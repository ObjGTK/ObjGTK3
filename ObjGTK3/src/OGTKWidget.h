/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

@class OGTKRcStyle;
@class OGGdkPixbuf;
@class OGTKStyle;
@class OGGdkFrameClock;
@class OGTKClipboard;
@class OGTKStyleContext;
@class OGAtkObject;
@class OGPangoLayout;
@class OGGdkScreen;
@class OGPangoFontMap;
@class OGPangoContext;
@class OGTKAccelGroup;
@class OGTKSettings;
@class OGGdkDevice;
@class OGTKWindow;
@class OGGdkWindow;
@class OGGdkVisual;
@class OGGdkDisplay;
@class OGGdkDragContext;

/**
 * GtkWidget is the base class all widgets in GTK+ derive from. It manages the
 * widget lifecycle, states and style.
 * 
 * # Height-for-width Geometry Management # {#geometry-management}
 * 
 * GTK+ uses a height-for-width (and width-for-height) geometry management
 * system. Height-for-width means that a widget can change how much
 * vertical space it needs, depending on the amount of horizontal space
 * that it is given (and similar for width-for-height). The most common
 * example is a label that reflows to fill up the available width, wraps
 * to fewer lines, and therefore needs less height.
 * 
 * Height-for-width geometry management is implemented in GTK+ by way
 * of five virtual methods:
 * 
 * - #GtkWidgetClass.get_request_mode()
 * - #GtkWidgetClass.get_preferred_width()
 * - #GtkWidgetClass.get_preferred_height()
 * - #GtkWidgetClass.get_preferred_height_for_width()
 * - #GtkWidgetClass.get_preferred_width_for_height()
 * - #GtkWidgetClass.get_preferred_height_and_baseline_for_width()
 * 
 * There are some important things to keep in mind when implementing
 * height-for-width and when using it in container implementations.
 * 
 * The geometry management system will query a widget hierarchy in
 * only one orientation at a time. When widgets are initially queried
 * for their minimum sizes it is generally done in two initial passes
 * in the #GtkSizeRequestMode chosen by the toplevel.
 * 
 * For example, when queried in the normal
 * %GTK_SIZE_REQUEST_HEIGHT_FOR_WIDTH mode:
 * First, the default minimum and natural width for each widget
 * in the interface will be computed using gtk_widget_get_preferred_width().
 * Because the preferred widths for each container depend on the preferred
 * widths of their children, this information propagates up the hierarchy,
 * and finally a minimum and natural width is determined for the entire
 * toplevel. Next, the toplevel will use the minimum width to query for the
 * minimum height contextual to that width using
 * gtk_widget_get_preferred_height_for_width(), which will also be a highly
 * recursive operation. The minimum height for the minimum width is normally
 * used to set the minimum size constraint on the toplevel
 * (unless gtk_window_set_geometry_hints() is explicitly used instead).
 * 
 * After the toplevel window has initially requested its size in both
 * dimensions it can go on to allocate itself a reasonable size (or a size
 * previously specified with gtk_window_set_default_size()). During the
 * recursive allocation process it’s important to note that request cycles
 * will be recursively executed while container widgets allocate their children.
 * Each container widget, once allocated a size, will go on to first share the
 * space in one orientation among its children and then request each child's
 * height for its target allocated width or its width for allocated height,
 * depending. In this way a #GtkWidget will typically be requested its size
 * a number of times before actually being allocated a size. The size a
 * widget is finally allocated can of course differ from the size it has
 * requested. For this reason, #GtkWidget caches a  small number of results
 * to avoid re-querying for the same sizes in one allocation cycle.
 * 
 * See
 * [GtkContainer’s geometry management section][container-geometry-management]
 * to learn more about how height-for-width allocations are performed
 * by container widgets.
 * 
 * If a widget does move content around to intelligently use up the
 * allocated size then it must support the request in both
 * #GtkSizeRequestModes even if the widget in question only
 * trades sizes in a single orientation.
 * 
 * For instance, a #GtkLabel that does height-for-width word wrapping
 * will not expect to have #GtkWidgetClass.get_preferred_height() called
 * because that call is specific to a width-for-height request. In this
 * case the label must return the height required for its own minimum
 * possible width. By following this rule any widget that handles
 * height-for-width or width-for-height requests will always be allocated
 * at least enough space to fit its own content.
 * 
 * Here are some examples of how a %GTK_SIZE_REQUEST_HEIGHT_FOR_WIDTH widget
 * generally deals with width-for-height requests, for #GtkWidgetClass.get_preferred_height()
 * it will do:
 * 
 * |[<!-- language="C" -->
 * static void
 * foo_widget_get_preferred_height (GtkWidget *widget,
 *                                  gint *min_height,
 *                                  gint *nat_height)
 * {
 *    if (i_am_in_height_for_width_mode)
 *      {
 *        gint min_width, nat_width;
 * 
 *        GTK_WIDGET_GET_CLASS (widget)->get_preferred_width (widget,
 *                                                            &min_width,
 *                                                            &nat_width);
 *        GTK_WIDGET_GET_CLASS (widget)->get_preferred_height_for_width
 *                                                           (widget,
 *                                                            min_width,
 *                                                            min_height,
 *                                                            nat_height);
 *      }
 *    else
 *      {
 *         ... some widgets do both. For instance, if a GtkLabel is
 *         rotated to 90 degrees it will return the minimum and
 *         natural height for the rotated label here.
 *      }
 * }
 * ]|
 * 
 * And in #GtkWidgetClass.get_preferred_width_for_height() it will simply return
 * the minimum and natural width:
 * |[<!-- language="C" -->
 * static void
 * foo_widget_get_preferred_width_for_height (GtkWidget *widget,
 *                                            gint for_height,
 *                                            gint *min_width,
 *                                            gint *nat_width)
 * {
 *    if (i_am_in_height_for_width_mode)
 *      {
 *        GTK_WIDGET_GET_CLASS (widget)->get_preferred_width (widget,
 *                                                            min_width,
 *                                                            nat_width);
 *      }
 *    else
 *      {
 *         ... again if a widget is sometimes operating in
 *         width-for-height mode (like a rotated GtkLabel) it can go
 *         ahead and do its real width for height calculation here.
 *      }
 * }
 * ]|
 * 
 * Often a widget needs to get its own request during size request or
 * allocation. For example, when computing height it may need to also
 * compute width. Or when deciding how to use an allocation, the widget
 * may need to know its natural size. In these cases, the widget should
 * be careful to call its virtual methods directly, like this:
 * 
 * |[<!-- language="C" -->
 * GTK_WIDGET_GET_CLASS(widget)->get_preferred_width (widget,
 *                                                    &min,
 *                                                    &natural);
 * ]|
 * 
 * It will not work to use the wrapper functions, such as
 * gtk_widget_get_preferred_width() inside your own size request
 * implementation. These return a request adjusted by #GtkSizeGroup
 * and by the #GtkWidgetClass.adjust_size_request() virtual method. If a
 * widget used the wrappers inside its virtual method implementations,
 * then the adjustments (such as widget margins) would be applied
 * twice. GTK+ therefore does not allow this and will warn if you try
 * to do it.
 * 
 * Of course if you are getting the size request for
 * another widget, such as a child of a
 * container, you must use the wrapper APIs.
 * Otherwise, you would not properly consider widget margins,
 * #GtkSizeGroup, and so forth.
 * 
 * Since 3.10 GTK+ also supports baseline vertical alignment of widgets. This
 * means that widgets are positioned such that the typographical baseline of
 * widgets in the same row are aligned. This happens if a widget supports baselines,
 * has a vertical alignment of %GTK_ALIGN_BASELINE, and is inside a container
 * that supports baselines and has a natural “row” that it aligns to the baseline,
 * or a baseline assigned to it by the grandparent.
 * 
 * Baseline alignment support for a widget is done by the #GtkWidgetClass.get_preferred_height_and_baseline_for_width()
 * virtual function. It allows you to report a baseline in combination with the
 * minimum and natural height. If there is no baseline you can return -1 to indicate
 * this. The default implementation of this virtual function calls into the
 * #GtkWidgetClass.get_preferred_height() and #GtkWidgetClass.get_preferred_height_for_width(),
 * so if baselines are not supported it doesn’t need to be implemented.
 * 
 * If a widget ends up baseline aligned it will be allocated all the space in the parent
 * as if it was %GTK_ALIGN_FILL, but the selected baseline can be found via gtk_widget_get_allocated_baseline().
 * If this has a value other than -1 you need to align the widget such that the baseline
 * appears at the position.
 * 
 * # Style Properties
 * 
 * #GtkWidget introduces “style
 * properties” - these are basically object properties that are stored
 * not on the object, but in the style object associated to the widget. Style
 * properties are set in [resource files][gtk3-Resource-Files].
 * This mechanism is used for configuring such things as the location of the
 * scrollbar arrows through the theme, giving theme authors more control over the
 * look of applications without the need to write a theme engine in C.
 * 
 * Use gtk_widget_class_install_style_property() to install style properties for
 * a widget class, gtk_widget_class_find_style_property() or
 * gtk_widget_class_list_style_properties() to get information about existing
 * style properties and gtk_widget_style_get_property(), gtk_widget_style_get() or
 * gtk_widget_style_get_valist() to obtain the value of a style property.
 * 
 * # GtkWidget as GtkBuildable
 * 
 * The GtkWidget implementation of the GtkBuildable interface supports a
 * custom `<accelerator>` element, which has attributes named ”key”, ”modifiers”
 * and ”signal” and allows to specify accelerators.
 * 
 * An example of a UI definition fragment specifying an accelerator:
 * 
 * |[<!-- language="xml" -->
 * <object class="GtkButton">
 *   <accelerator key="q" modifiers="GDK_CONTROL_MASK" signal="clicked"/>
 * </object>
 * ]|
 * 
 * In addition to accelerators, GtkWidget also support a custom `<accessible>`
 * element, which supports actions and relations. Properties on the accessible
 * implementation of an object can be set by accessing the internal child
 * “accessible” of a #GtkWidget.
 * 
 * An example of a UI definition fragment specifying an accessible:
 * 
 * |[<!-- language="xml" -->
 * <object class="GtkLabel" id="label1"/>
 *   <property name="label">I am a Label for a Button</property>
 * </object>
 * <object class="GtkButton" id="button1">
 *   <accessibility>
 *     <action action_name="click" translatable="yes">Click the button.</action>
 *     <relation target="label1" type="labelled-by"/>
 *   </accessibility>
 *   <child internal-child="accessible">
 *     <object class="AtkObject" id="a11y-button1">
 *       <property name="accessible-name">Clickable Button</property>
 *     </object>
 *   </child>
 * </object>
 * ]|
 * 
 * Finally, GtkWidget allows style information such as style classes to
 * be associated with widgets, using the custom `<style>` element:
 * 
 * |[<!-- language="xml" -->
 * <object class="GtkButton" id="button1">
 *   <style>
 *     <class name="my-special-button-class"/>
 *     <class name="dark-button"/>
 *   </style>
 * </object>
 * ]|
 * 
 * # Building composite widgets from template XML ## {#composite-templates}
 * 
 * GtkWidget exposes some facilities to automate the procedure
 * of creating composite widgets using #GtkBuilder interface description
 * language.
 * 
 * To create composite widgets with #GtkBuilder XML, one must associate
 * the interface description with the widget class at class initialization
 * time using gtk_widget_class_set_template().
 * 
 * The interface description semantics expected in composite template descriptions
 * is slightly different from regular #GtkBuilder XML.
 * 
 * Unlike regular interface descriptions, gtk_widget_class_set_template() will
 * expect a `<template>` tag as a direct child of the toplevel `<interface>`
 * tag. The `<template>` tag must specify the “class” attribute which must be
 * the type name of the widget. Optionally, the “parent” attribute may be
 * specified to specify the direct parent type of the widget type, this is
 * ignored by the GtkBuilder but required for Glade to introspect what kind
 * of properties and internal children exist for a given type when the actual
 * type does not exist.
 * 
 * The XML which is contained inside the `<template>` tag behaves as if it were
 * added to the `<object>` tag defining "widget" itself. You may set properties
 * on @widget by inserting `<property>` tags into the `<template>` tag, and also
 * add `<child>` tags to add children and extend "widget" in the normal way you
 * would with `<object>` tags.
 * 
 * Additionally, `<object>` tags can also be added before and after the initial
 * `<template>` tag in the normal way, allowing one to define auxiliary objects
 * which might be referenced by other widgets declared as children of the
 * `<template>` tag.
 * 
 * An example of a GtkBuilder Template Definition:
 * 
 * |[<!-- language="xml" -->
 * <interface>
 *   <template class="FooWidget" parent="GtkBox">
 *     <property name="orientation">GTK_ORIENTATION_HORIZONTAL</property>
 *     <property name="spacing">4</property>
 *     <child>
 *       <object class="GtkButton" id="hello_button">
 *         <property name="label">Hello World</property>
 *         <signal name="clicked" handler="hello_button_clicked" object="FooWidget" swapped="yes"/>
 *       </object>
 *     </child>
 *     <child>
 *       <object class="GtkButton" id="goodbye_button">
 *         <property name="label">Goodbye World</property>
 *       </object>
 *     </child>
 *   </template>
 * </interface>
 * ]|
 * 
 * Typically, you'll place the template fragment into a file that is
 * bundled with your project, using #GResource. In order to load the
 * template, you need to call gtk_widget_class_set_template_from_resource()
 * from the class initialization of your #GtkWidget type:
 * 
 * |[<!-- language="C" -->
 * static void
 * foo_widget_class_init (FooWidgetClass *klass)
 * {
 *   // ...
 * 
 *   gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (klass),
 *                                                "/com/example/ui/foowidget.ui");
 * }
 * ]|
 * 
 * You will also need to call gtk_widget_init_template() from the instance
 * initialization function:
 * 
 * |[<!-- language="C" -->
 * static void
 * foo_widget_init (FooWidget *self)
 * {
 *   // ...
 *   gtk_widget_init_template (GTK_WIDGET (self));
 * }
 * ]|
 * 
 * You can access widgets defined in the template using the
 * gtk_widget_get_template_child() function, but you will typically declare
 * a pointer in the instance private data structure of your type using the same
 * name as the widget in the template definition, and call
 * gtk_widget_class_bind_template_child_private() with that name, e.g.
 * 
 * |[<!-- language="C" -->
 * typedef struct {
 *   GtkWidget *hello_button;
 *   GtkWidget *goodbye_button;
 * } FooWidgetPrivate;
 * 
 * G_DEFINE_TYPE_WITH_PRIVATE (FooWidget, foo_widget, GTK_TYPE_BOX)
 * 
 * static void
 * foo_widget_class_init (FooWidgetClass *klass)
 * {
 *   // ...
 *   gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (klass),
 *                                                "/com/example/ui/foowidget.ui");
 *   gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (klass),
 *                                                 FooWidget, hello_button);
 *   gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (klass),
 *                                                 FooWidget, goodbye_button);
 * }
 * 
 * static void
 * foo_widget_init (FooWidget *widget)
 * {
 * 
 * }
 * ]|
 * 
 * You can also use gtk_widget_class_bind_template_callback() to connect a signal
 * callback defined in the template with a function visible in the scope of the
 * class, e.g.
 * 
 * |[<!-- language="C" -->
 * // the signal handler has the instance and user data swapped
 * // because of the swapped="yes" attribute in the template XML
 * static void
 * hello_button_clicked (FooWidget *self,
 *                       GtkButton *button)
 * {
 *   g_print ("Hello, world!\n");
 * }
 * 
 * static void
 * foo_widget_class_init (FooWidgetClass *klass)
 * {
 *   // ...
 *   gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (klass),
 *                                                "/com/example/ui/foowidget.ui");
 *   gtk_widget_class_bind_template_callback (GTK_WIDGET_CLASS (klass), hello_button_clicked);
 * }
 * ]|
 *
 */
@interface OGTKWidget : OGObject
{

}

/**
 * Functions
 */
+ (GtkTextDirection)defaultDirection;
+ (OGTKStyle*)defaultStyle;
+ (void)popCompositeChild;
+ (void)pushCompositeChild;
+ (void)setDefaultDirection:(GtkTextDirection)dir;

/**
 * Methods
 */

- (GtkWidget*)WIDGET;

/**
 * For widgets that can be “activated” (buttons, menu items, etc.)
 * this function activates them. Activation is what happens when you
 * press Enter on a widget during key navigation. If @widget isn't
 * activatable, the function returns %FALSE.
 *
 * @return %TRUE if the widget was activatable
 */
- (bool)activate;

/**
 * Installs an accelerator for this @widget in @accel_group that causes
 * @accel_signal to be emitted if the accelerator is activated.
 * The @accel_group needs to be added to the widget’s toplevel via
 * gtk_window_add_accel_group(), and the signal must be of type %G_SIGNAL_ACTION.
 * Accelerators added through this function are not user changeable during
 * runtime. If you want to support accelerators that can be changed by the
 * user, use gtk_accel_map_add_entry() and gtk_widget_set_accel_path() or
 * gtk_menu_item_set_accel_path() instead.
 *
 * @param accelSignal widget signal to emit on accelerator activation
 * @param accelGroup accel group for this widget, added to its toplevel
 * @param accelKey GDK keyval of the accelerator
 * @param accelMods modifier key combination of the accelerator
 * @param accelFlags flag accelerators, e.g. %GTK_ACCEL_VISIBLE
 */
- (void)addAcceleratorWithAccelSignal:(OFString*)accelSignal accelGroup:(OGTKAccelGroup*)accelGroup accelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods accelFlags:(GtkAccelFlags)accelFlags;

/**
 * Adds the device events in the bitfield @events to the event mask for
 * @widget. See gtk_widget_set_device_events() for details.
 *
 * @param device a #GdkDevice
 * @param events an event mask, see #GdkEventMask
 */
- (void)addDeviceEventsWithDevice:(OGGdkDevice*)device events:(GdkEventMask)events;

/**
 * Adds the events in the bitfield @events to the event mask for
 * @widget. See gtk_widget_set_events() and the
 * [input handling overview][event-masks] for details.
 *
 * @param events an event mask, see #GdkEventMask
 */
- (void)addEvents:(gint)events;

/**
 * Adds a widget to the list of mnemonic labels for
 * this widget. (See gtk_widget_list_mnemonic_labels()). Note the
 * list of mnemonic labels for the widget is cleared when the
 * widget is destroyed, so the caller must make sure to update
 * its internal state at this point as well, by using a connection
 * to the #GtkWidget::destroy signal or a weak notifier.
 *
 * @param label a #GtkWidget that acts as a mnemonic label for @widget
 */
- (void)addMnemonicLabel:(OGTKWidget*)label;

/**
 * Queues an animation frame update and adds a callback to be called
 * before each frame. Until the tick callback is removed, it will be
 * called frequently (usually at the frame rate of the output device
 * or as quickly as the application can be repainted, whichever is
 * slower). For this reason, is most suitable for handling graphics
 * that change every frame or every few frames. The tick callback does
 * not automatically imply a relayout or repaint. If you want a
 * repaint or relayout, and aren’t changing widget properties that
 * would trigger that (for example, changing the text of a #GtkLabel),
 * then you will have to call gtk_widget_queue_resize() or
 * gtk_widget_queue_draw_area() yourself.
 * 
 * gdk_frame_clock_get_frame_time() should generally be used for timing
 * continuous animations and
 * gdk_frame_timings_get_predicted_presentation_time() if you are
 * trying to display isolated frames at particular times.
 * 
 * This is a more convenient alternative to connecting directly to the
 * #GdkFrameClock::update signal of #GdkFrameClock, since you don't
 * have to worry about when a #GdkFrameClock is assigned to a widget.
 *
 * @param callback function to call for updating animations
 * @param userData data to pass to @callback
 * @param notify function to call to free @user_data when the callback is removed.
 * @return an id for the connection of this callback. Remove the callback
 *     by passing it to gtk_widget_remove_tick_callback()
 */
- (guint)addTickCallbackWithCallback:(GtkTickCallback)callback userData:(gpointer)userData notify:(GDestroyNotify)notify;

/**
 * Determines whether an accelerator that activates the signal
 * identified by @signal_id can currently be activated.
 * This is done by emitting the #GtkWidget::can-activate-accel
 * signal on @widget; if the signal isn’t overridden by a
 * handler or in a derived widget, then the default check is
 * that the widget must be sensitive, and the widget and all
 * its ancestors mapped.
 *
 * @param signalId the ID of a signal installed on @widget
 * @return %TRUE if the accelerator can be activated.
 */
- (bool)canActivateAccel:(guint)signalId;

/**
 * This function is used by custom widget implementations; if you're
 * writing an app, you’d use gtk_widget_grab_focus() to move the focus
 * to a particular widget, and gtk_container_set_focus_chain() to
 * change the focus tab order. So you may want to investigate those
 * functions instead.
 * 
 * gtk_widget_child_focus() is called by containers as the user moves
 * around the window using keyboard shortcuts. @direction indicates
 * what kind of motion is taking place (up, down, left, right, tab
 * forward, tab backward). gtk_widget_child_focus() emits the
 * #GtkWidget::focus signal; widgets override the default handler
 * for this signal in order to implement appropriate focus behavior.
 * 
 * The default ::focus handler for a widget should return %TRUE if
 * moving in @direction left the focus on a focusable location inside
 * that widget, and %FALSE if moving in @direction moved the focus
 * outside the widget. If returning %TRUE, widgets normally
 * call gtk_widget_grab_focus() to place the focus accordingly;
 * if returning %FALSE, they don’t modify the current focus location.
 *
 * @param direction direction of focus movement
 * @return %TRUE if focus ended up inside @widget
 */
- (bool)childFocus:(GtkDirectionType)direction;

/**
 * Emits a #GtkWidget::child-notify signal for the
 * [child property][child-properties] @child_property
 * on @widget.
 * 
 * This is the analogue of g_object_notify() for child properties.
 * 
 * Also see gtk_container_child_notify().
 *
 * @param childProperty the name of a child property installed on the
 *                  class of @widget’s parent
 */
- (void)childNotify:(OFString*)childProperty;

/**
 * Same as gtk_widget_path(), but always uses the name of a widget’s type,
 * never uses a custom name set with gtk_widget_set_name().
 *
 * @param pathLength location to store the length of the
 *     class path, or %NULL
 * @param path location to store the class path as an
 *     allocated string, or %NULL
 * @param pathReversed location to store the reverse
 *     class path as an allocated string, or %NULL
 */
- (void)classPathWithPathLength:(guint*)pathLength path:(gchar**)path pathReversed:(gchar**)pathReversed;

/**
 * Computes whether a container should give this widget extra space
 * when possible. Containers should check this, rather than
 * looking at gtk_widget_get_hexpand() or gtk_widget_get_vexpand().
 * 
 * This function already checks whether the widget is visible, so
 * visibility does not need to be checked separately. Non-visible
 * widgets are not expanded.
 * 
 * The computed expand value uses either the expand setting explicitly
 * set on the widget itself, or, if none has been explicitly set,
 * the widget may expand if some of its children do.
 *
 * @param orientation expand direction
 * @return whether widget tree rooted here should be expanded
 */
- (bool)computeExpand:(GtkOrientation)orientation;

/**
 * Creates a new #PangoContext with the appropriate font map,
 * font options, font description, and base direction for drawing
 * text for this widget. See also gtk_widget_get_pango_context().
 *
 * @return the new #PangoContext
 */
- (OGPangoContext*)createPangoContext;

/**
 * Creates a new #PangoLayout with the appropriate font map,
 * font description, and base direction for drawing text for
 * this widget.
 * 
 * If you keep a #PangoLayout created in this way around, you need
 * to re-create it when the widget #PangoContext is replaced.
 * This can be tracked by using the #GtkWidget::screen-changed signal
 * on the widget.
 *
 * @param text text to set on the layout (can be %NULL)
 * @return the new #PangoLayout
 */
- (OGPangoLayout*)createPangoLayout:(OFString*)text;

/**
 * Destroys a widget.
 * 
 * When a widget is destroyed all references it holds on other objects
 * will be released:
 * 
 *  - if the widget is inside a container, it will be removed from its
 *  parent
 *  - if the widget is a container, all its children will be destroyed,
 *  recursively
 *  - if the widget is a top level, it will be removed from the list
 *  of top level widgets that GTK+ maintains internally
 * 
 * It's expected that all references held on the widget will also
 * be released; you should connect to the #GtkWidget::destroy signal
 * if you hold a reference to @widget and you wish to remove it when
 * this function is called. It is not necessary to do so if you are
 * implementing a #GtkContainer, as you'll be able to use the
 * #GtkContainerClass.remove() virtual function for that.
 * 
 * It's important to notice that gtk_widget_destroy() will only cause
 * the @widget to be finalized if no additional references, acquired
 * using g_object_ref(), are held on it. In case additional references
 * are in place, the @widget will be in an "inert" state after calling
 * this function; @widget will still point to valid memory, allowing you
 * to release the references you hold, but you may not query the widget's
 * own state.
 * 
 * You should typically call this function on top level widgets, and
 * rarely on child widgets.
 * 
 * See also: gtk_container_remove()
 *
 */
- (void)destroy;

/**
 * This function sets *@widget_pointer to %NULL if @widget_pointer !=
 * %NULL.  It’s intended to be used as a callback connected to the
 * “destroy” signal of a widget. You connect gtk_widget_destroyed()
 * as a signal handler, and pass the address of your widget variable
 * as user data. Then when the widget is destroyed, the variable will
 * be set to %NULL. Useful for example to avoid multiple copies
 * of the same dialog.
 *
 * @param widgetPointer address of a variable that contains @widget
 */
- (void)destroyed:(GtkWidget**)widgetPointer;

/**
 * Returns %TRUE if @device has been shadowed by a GTK+
 * device grab on another widget, so it would stop sending
 * events to @widget. This may be used in the
 * #GtkWidget::grab-notify signal to check for specific
 * devices. See gtk_device_grab_add().
 *
 * @param device a #GdkDevice
 * @return %TRUE if there is an ongoing grab on @device
 *          by another #GtkWidget than @widget.
 */
- (bool)deviceIsShadowed:(OGGdkDevice*)device;

/**
 * This function is equivalent to gtk_drag_begin_with_coordinates(),
 * passing -1, -1 as coordinates.
 *
 * @param targets The targets (data formats) in which the
 *    source can provide the data
 * @param actions A bitmask of the allowed drag actions for this drag
 * @param button The button the user clicked to start the drag
 * @param event The event that triggered the start of the drag,
 *    or %NULL if none can be obtained.
 * @return the context for this drag
 */
- (OGGdkDragContext*)dragBeginWithTargets:(GtkTargetList*)targets actions:(GdkDragAction)actions button:(gint)button event:(GdkEvent*)event;

/**
 * Initiates a drag on the source side. The function only needs to be used
 * when the application is starting drags itself, and is not needed when
 * gtk_drag_source_set() is used.
 * 
 * The @event is used to retrieve the timestamp that will be used internally to
 * grab the pointer.  If @event is %NULL, then %GDK_CURRENT_TIME will be used.
 * However, you should try to pass a real event in all cases, since that can be
 * used to get information about the drag.
 * 
 * Generally there are three cases when you want to start a drag by hand by
 * calling this function:
 * 
 * 1. During a #GtkWidget::button-press-event handler, if you want to start a drag
 * immediately when the user presses the mouse button.  Pass the @event
 * that you have in your #GtkWidget::button-press-event handler.
 * 
 * 2. During a #GtkWidget::motion-notify-event handler, if you want to start a drag
 * when the mouse moves past a certain threshold distance after a button-press.
 * Pass the @event that you have in your #GtkWidget::motion-notify-event handler.
 * 
 * 3. During a timeout handler, if you want to start a drag after the mouse
 * button is held down for some time.  Try to save the last event that you got
 * from the mouse, using gdk_event_copy(), and pass it to this function
 * (remember to free the event with gdk_event_free() when you are done).
 * If you really cannot pass a real event, pass %NULL instead.
 *
 * @param targets The targets (data formats) in which the
 *    source can provide the data
 * @param actions A bitmask of the allowed drag actions for this drag
 * @param button The button the user clicked to start the drag
 * @param event The event that triggered the start of the drag,
 *    or %NULL if none can be obtained.
 * @param x The initial x coordinate to start dragging from, in the coordinate space
 *    of @widget. If -1 is passed, the coordinates are retrieved from @event or
 *    the current pointer position
 * @param y The initial y coordinate to start dragging from, in the coordinate space
 *    of @widget. If -1 is passed, the coordinates are retrieved from @event or
 *    the current pointer position
 * @return the context for this drag
 */
- (OGGdkDragContext*)dragBeginWithCoordinatesWithTargets:(GtkTargetList*)targets actions:(GdkDragAction)actions button:(gint)button event:(GdkEvent*)event x:(gint)x y:(gint)y;

/**
 * Checks to see if a mouse drag starting at (@start_x, @start_y) and ending
 * at (@current_x, @current_y) has passed the GTK+ drag threshold, and thus
 * should trigger the beginning of a drag-and-drop operation.
 *
 * @param startX X coordinate of start of drag
 * @param startY Y coordinate of start of drag
 * @param currentX current X coordinate
 * @param currentY current Y coordinate
 * @return %TRUE if the drag threshold has been passed.
 */
- (bool)dragCheckThresholdWithStartX:(gint)startX startY:(gint)startY currentX:(gint)currentX currentY:(gint)currentY;

/**
 * Add the image targets supported by #GtkSelectionData to
 * the target list of the drag destination. The targets
 * are added with @info = 0. If you need another value,
 * use gtk_target_list_add_image_targets() and
 * gtk_drag_dest_set_target_list().
 *
 */
- (void)dragDestAddImageTargets;

/**
 * Add the text targets supported by #GtkSelectionData to
 * the target list of the drag destination. The targets
 * are added with @info = 0. If you need another value,
 * use gtk_target_list_add_text_targets() and
 * gtk_drag_dest_set_target_list().
 *
 */
- (void)dragDestAddTextTargets;

/**
 * Add the URI targets supported by #GtkSelectionData to
 * the target list of the drag destination. The targets
 * are added with @info = 0. If you need another value,
 * use gtk_target_list_add_uri_targets() and
 * gtk_drag_dest_set_target_list().
 *
 */
- (void)dragDestAddUriTargets;

/**
 * Looks for a match between the supported targets of @context and the
 * @dest_target_list, returning the first matching target, otherwise
 * returning %GDK_NONE. @dest_target_list should usually be the return
 * value from gtk_drag_dest_get_target_list(), but some widgets may
 * have different valid targets for different parts of the widget; in
 * that case, they will have to implement a drag_motion handler that
 * passes the correct target list to this function.
 *
 * @param context drag context
 * @param targetList list of droppable targets, or %NULL to use
 *    gtk_drag_dest_get_target_list (@widget).
 * @return first target that the source offers
 *     and the dest can accept, or %GDK_NONE
 */
- (GdkAtom)dragDestFindTargetWithContext:(OGGdkDragContext*)context targetList:(GtkTargetList*)targetList;

/**
 * Returns the list of targets this widget can accept from
 * drag-and-drop.
 *
 * @return the #GtkTargetList, or %NULL if none
 */
- (GtkTargetList*)dragDestGetTargetList;

/**
 * Returns whether the widget has been configured to always
 * emit #GtkWidget::drag-motion signals.
 *
 * @return %TRUE if the widget always emits
 *   #GtkWidget::drag-motion events
 */
- (bool)dragDestGetTrackMotion;

/**
 * Sets a widget as a potential drop destination, and adds default behaviors.
 * 
 * The default behaviors listed in @flags have an effect similar
 * to installing default handlers for the widget’s drag-and-drop signals
 * (#GtkWidget::drag-motion, #GtkWidget::drag-drop, ...). They all exist
 * for convenience. When passing #GTK_DEST_DEFAULT_ALL for instance it is
 * sufficient to connect to the widget’s #GtkWidget::drag-data-received
 * signal to get primitive, but consistent drag-and-drop support.
 * 
 * Things become more complicated when you try to preview the dragged data,
 * as described in the documentation for #GtkWidget::drag-motion. The default
 * behaviors described by @flags make some assumptions, that can conflict
 * with your own signal handlers. For instance #GTK_DEST_DEFAULT_DROP causes
 * invokations of gdk_drag_status() in the context of #GtkWidget::drag-motion,
 * and invokations of gtk_drag_finish() in #GtkWidget::drag-data-received.
 * Especially the later is dramatic, when your own #GtkWidget::drag-motion
 * handler calls gtk_drag_get_data() to inspect the dragged data.
 * 
 * There’s no way to set a default action here, you can use the
 * #GtkWidget::drag-motion callback for that. Here’s an example which selects
 * the action to use depending on whether the control key is pressed or not:
 * |[<!-- language="C" -->
 * static void
 * drag_motion (GtkWidget *widget,
 *              GdkDragContext *context,
 *              gint x,
 *              gint y,
 *              guint time)
 * {
 *   GdkModifierType mask;
 * 
 *   gdk_window_get_pointer (gtk_widget_get_window (widget),
 *                           NULL, NULL, &mask);
 *   if (mask & GDK_CONTROL_MASK)
 *     gdk_drag_status (context, GDK_ACTION_COPY, time);
 *   else
 *     gdk_drag_status (context, GDK_ACTION_MOVE, time);
 * }
 * ]|
 *
 * @param flags which types of default drag behavior to use
 * @param targets a pointer to an array of
 *     #GtkTargetEntrys indicating the drop types that this @widget will
 *     accept, or %NULL. Later you can access the list with
 *     gtk_drag_dest_get_target_list() and gtk_drag_dest_find_target().
 * @param ntargets the number of entries in @targets
 * @param actions a bitmask of possible actions for a drop onto this @widget.
 */
- (void)dragDestSetWithFlags:(GtkDestDefaults)flags targets:(const GtkTargetEntry*)targets ntargets:(gint)ntargets actions:(GdkDragAction)actions;

/**
 * Sets this widget as a proxy for drops to another window.
 *
 * @param proxyWindow the window to which to forward drag events
 * @param protocol the drag protocol which the @proxy_window accepts
 *   (You can use gdk_drag_get_protocol() to determine this)
 * @param useCoordinates If %TRUE, send the same coordinates to the
 *   destination, because it is an embedded
 *   subwindow.
 */
- (void)dragDestSetProxyWithProxyWindow:(OGGdkWindow*)proxyWindow protocol:(GdkDragProtocol)protocol useCoordinates:(bool)useCoordinates;

/**
 * Sets the target types that this widget can accept from drag-and-drop.
 * The widget must first be made into a drag destination with
 * gtk_drag_dest_set().
 *
 * @param targetList list of droppable targets, or %NULL for none
 */
- (void)dragDestSetTargetList:(GtkTargetList*)targetList;

/**
 * Tells the widget to emit #GtkWidget::drag-motion and
 * #GtkWidget::drag-leave events regardless of the targets and the
 * %GTK_DEST_DEFAULT_MOTION flag.
 * 
 * This may be used when a widget wants to do generic
 * actions regardless of the targets that the source offers.
 *
 * @param trackMotion whether to accept all targets
 */
- (void)dragDestSetTrackMotion:(bool)trackMotion;

/**
 * Clears information about a drop destination set with
 * gtk_drag_dest_set(). The widget will no longer receive
 * notification of drags.
 *
 */
- (void)dragDestUnset;

/**
 * Gets the data associated with a drag. When the data
 * is received or the retrieval fails, GTK+ will emit a
 * #GtkWidget::drag-data-received signal. Failure of the retrieval
 * is indicated by the length field of the @selection_data
 * signal parameter being negative. However, when gtk_drag_get_data()
 * is called implicitely because the %GTK_DEST_DEFAULT_DROP was set,
 * then the widget will not receive notification of failed
 * drops.
 *
 * @param context the drag context
 * @param target the target (form of the data) to retrieve
 * @param time a timestamp for retrieving the data. This will
 *   generally be the time received in a #GtkWidget::drag-motion
 *   or #GtkWidget::drag-drop signal
 */
- (void)dragGetDataWithContext:(OGGdkDragContext*)context target:(GdkAtom)target time:(guint32)time;

/**
 * Highlights a widget as a currently hovered drop target.
 * To end the highlight, call gtk_drag_unhighlight().
 * GTK+ calls this automatically if %GTK_DEST_DEFAULT_HIGHLIGHT is set.
 *
 */
- (void)dragHighlight;

/**
 * Add the writable image targets supported by #GtkSelectionData to
 * the target list of the drag source. The targets
 * are added with @info = 0. If you need another value,
 * use gtk_target_list_add_image_targets() and
 * gtk_drag_source_set_target_list().
 *
 */
- (void)dragSourceAddImageTargets;

/**
 * Add the text targets supported by #GtkSelectionData to
 * the target list of the drag source.  The targets
 * are added with @info = 0. If you need another value,
 * use gtk_target_list_add_text_targets() and
 * gtk_drag_source_set_target_list().
 *
 */
- (void)dragSourceAddTextTargets;

/**
 * Add the URI targets supported by #GtkSelectionData to
 * the target list of the drag source.  The targets
 * are added with @info = 0. If you need another value,
 * use gtk_target_list_add_uri_targets() and
 * gtk_drag_source_set_target_list().
 *
 */
- (void)dragSourceAddUriTargets;

/**
 * Gets the list of targets this widget can provide for
 * drag-and-drop.
 *
 * @return the #GtkTargetList, or %NULL if none
 */
- (GtkTargetList*)dragSourceGetTargetList;

/**
 * Sets up a widget so that GTK+ will start a drag operation when the user
 * clicks and drags on the widget. The widget must have a window.
 *
 * @param startButtonMask the bitmask of buttons that can start the drag
 * @param targets the table of targets
 *     that the drag will support, may be %NULL
 * @param ntargets the number of items in @targets
 * @param actions the bitmask of possible actions for a drag from this widget
 */
- (void)dragSourceSetWithStartButtonMask:(GdkModifierType)startButtonMask targets:(const GtkTargetEntry*)targets ntargets:(gint)ntargets actions:(GdkDragAction)actions;

/**
 * Sets the icon that will be used for drags from a particular source
 * to @icon. See the docs for #GtkIconTheme for more details.
 *
 * @param icon A #GIcon
 */
- (void)dragSourceSetIconGicon:(GIcon*)icon;

/**
 * Sets the icon that will be used for drags from a particular source
 * to a themed icon. See the docs for #GtkIconTheme for more details.
 *
 * @param iconName name of icon to use
 */
- (void)dragSourceSetIconName:(OFString*)iconName;

/**
 * Sets the icon that will be used for drags from a particular widget
 * from a #GdkPixbuf. GTK+ retains a reference for @pixbuf and will
 * release it when it is no longer needed.
 *
 * @param pixbuf the #GdkPixbuf for the drag icon
 */
- (void)dragSourceSetIconPixbuf:(OGGdkPixbuf*)pixbuf;

/**
 * Sets the icon that will be used for drags from a particular source
 * to a stock icon.
 *
 * @param stockId the ID of the stock icon to use
 */
- (void)dragSourceSetIconStock:(OFString*)stockId;

/**
 * Changes the target types that this widget offers for drag-and-drop.
 * The widget must first be made into a drag source with
 * gtk_drag_source_set().
 *
 * @param targetList list of draggable targets, or %NULL for none
 */
- (void)dragSourceSetTargetList:(GtkTargetList*)targetList;

/**
 * Undoes the effects of gtk_drag_source_set().
 *
 */
- (void)dragSourceUnset;

/**
 * Removes a highlight set by gtk_drag_highlight() from
 * a widget.
 *
 */
- (void)dragUnhighlight;

/**
 * Draws @widget to @cr. The top left corner of the widget will be
 * drawn to the currently set origin point of @cr.
 * 
 * You should pass a cairo context as @cr argument that is in an
 * original state. Otherwise the resulting drawing is undefined. For
 * example changing the operator using cairo_set_operator() or the
 * line width using cairo_set_line_width() might have unwanted side
 * effects.
 * You may however change the context’s transform matrix - like with
 * cairo_scale(), cairo_translate() or cairo_set_matrix() and clip
 * region with cairo_clip() prior to calling this function. Also, it
 * is fine to modify the context with cairo_save() and
 * cairo_push_group() prior to calling this function.
 * 
 * Note that special-purpose widgets may contain special code for
 * rendering to the screen and might appear differently on screen
 * and when rendered using gtk_widget_draw().
 *
 * @param cr a cairo context to draw to
 */
- (void)draw:(cairo_t*)cr;

/**
 * Ensures that @widget has a style (@widget->style).
 * 
 * Not a very useful function; most of the time, if you
 * want the style, the widget is realized, and realized
 * widgets are guaranteed to have a style already.
 *
 */
- (void)ensureStyle;

/**
 * Notifies the user about an input-related error on this widget.
 * If the #GtkSettings:gtk-error-bell setting is %TRUE, it calls
 * gdk_window_beep(), otherwise it does nothing.
 * 
 * Note that the effect of gdk_window_beep() can be configured in many
 * ways, depending on the windowing backend and the desktop environment
 * or window manager that is used.
 *
 */
- (void)errorBell;

/**
 * Rarely-used function. This function is used to emit
 * the event signals on a widget (those signals should never
 * be emitted without using this function to do so).
 * If you want to synthesize an event though, don’t use this function;
 * instead, use gtk_main_do_event() so the event will behave as if
 * it were in the event queue. Don’t synthesize expose events; instead,
 * use gdk_window_invalidate_rect() to invalidate a region of the
 * window.
 *
 * @param event a #GdkEvent
 * @return return from the event signal emission (%TRUE if
 *               the event was handled)
 */
- (bool)event:(GdkEvent*)event;

/**
 * Stops emission of #GtkWidget::child-notify signals on @widget. The
 * signals are queued until gtk_widget_thaw_child_notify() is called
 * on @widget.
 * 
 * This is the analogue of g_object_freeze_notify() for child properties.
 *
 */
- (void)freezeChildNotify;

/**
 * Returns the accessible object that describes the widget to an
 * assistive technology.
 * 
 * If accessibility support is not available, this #AtkObject
 * instance may be a no-op. Likewise, if no class-specific #AtkObject
 * implementation is available for the widget instance in question,
 * it will inherit an #AtkObject implementation from the first ancestor
 * class for which such an implementation is defined.
 * 
 * The documentation of the
 * [ATK](http://developer.gnome.org/atk/stable/)
 * library contains more information about accessible objects and their uses.
 *
 * @return the #AtkObject associated with @widget
 */
- (OGAtkObject*)accessible;

/**
 * Retrieves the #GActionGroup that was registered using @prefix. The resulting
 * #GActionGroup may have been registered to @widget or any #GtkWidget in its
 * ancestry.
 * 
 * If no action group was found matching @prefix, then %NULL is returned.
 *
 * @param prefix The “prefix” of the action group.
 * @return A #GActionGroup or %NULL.
 */
- (GActionGroup*)actionGroup:(OFString*)prefix;

/**
 * Returns the baseline that has currently been allocated to @widget.
 * This function is intended to be used when implementing handlers
 * for the #GtkWidget::draw function, and when allocating child
 * widgets in #GtkWidget::size_allocate.
 *
 * @return the baseline of the @widget, or -1 if none
 */
- (int)allocatedBaseline;

/**
 * Returns the height that has currently been allocated to @widget.
 * This function is intended to be used when implementing handlers
 * for the #GtkWidget::draw function.
 *
 * @return the height of the @widget
 */
- (int)allocatedHeight;

/**
 * Retrieves the widget’s allocated size.
 * 
 * This function returns the last values passed to
 * gtk_widget_size_allocate_with_baseline(). The value differs from
 * the size returned in gtk_widget_get_allocation() in that functions
 * like gtk_widget_set_halign() can adjust the allocation, but not
 * the value returned by this function.
 * 
 * If a widget is not visible, its allocated size is 0.
 *
 * @param allocation a pointer to a #GtkAllocation to copy to
 * @param baseline a pointer to an integer to copy to
 */
- (void)allocatedSizeWithAllocation:(GtkAllocation*)allocation baseline:(int*)baseline;

/**
 * Returns the width that has currently been allocated to @widget.
 * This function is intended to be used when implementing handlers
 * for the #GtkWidget::draw function.
 *
 * @return the width of the @widget
 */
- (int)allocatedWidth;

/**
 * Retrieves the widget’s allocation.
 * 
 * Note, when implementing a #GtkContainer: a widget’s allocation will
 * be its “adjusted” allocation, that is, the widget’s parent
 * container typically calls gtk_widget_size_allocate() with an
 * allocation, and that allocation is then adjusted (to handle margin
 * and alignment for example) before assignment to the widget.
 * gtk_widget_get_allocation() returns the adjusted allocation that
 * was actually assigned to the widget. The adjusted allocation is
 * guaranteed to be completely contained within the
 * gtk_widget_size_allocate() allocation, however. So a #GtkContainer
 * is guaranteed that its children stay inside the assigned bounds,
 * but not that they have exactly the bounds the container assigned.
 * There is no way to get the original allocation assigned by
 * gtk_widget_size_allocate(), since it isn’t stored; if a container
 * implementation needs that information it will have to track it itself.
 *
 * @param allocation a pointer to a #GtkAllocation to copy to
 */
- (void)allocation:(GtkAllocation*)allocation;

/**
 * Gets the first ancestor of @widget with type @widget_type. For example,
 * `gtk_widget_get_ancestor (widget, GTK_TYPE_BOX)` gets
 * the first #GtkBox that’s an ancestor of @widget. No reference will be
 * added to the returned widget; it should not be unreferenced. See note
 * about checking for a toplevel #GtkWindow in the docs for
 * gtk_widget_get_toplevel().
 * 
 * Note that unlike gtk_widget_is_ancestor(), gtk_widget_get_ancestor()
 * considers @widget to be an ancestor of itself.
 *
 * @param widgetType ancestor type
 * @return the ancestor widget, or %NULL if not found
 */
- (OGTKWidget*)ancestor:(GType)widgetType;

/**
 * Determines whether the application intends to draw on the widget in
 * an #GtkWidget::draw handler.
 * 
 * See gtk_widget_set_app_paintable()
 *
 * @return %TRUE if the widget is app paintable
 */
- (bool)appPaintable;

/**
 * Determines whether @widget can be a default widget. See
 * gtk_widget_set_can_default().
 *
 * @return %TRUE if @widget can be a default widget, %FALSE otherwise
 */
- (bool)canDefault;

/**
 * Determines whether @widget can own the input focus. See
 * gtk_widget_set_can_focus().
 *
 * @return %TRUE if @widget can own the input focus, %FALSE otherwise
 */
- (bool)canFocus;

/**
 * This function is only for use in widget implementations. Obtains
 * @widget->requisition, unless someone has forced a particular
 * geometry on the widget (e.g. with gtk_widget_set_size_request()),
 * in which case it returns that geometry instead of the widget's
 * requisition.
 * 
 * This function differs from gtk_widget_size_request() in that
 * it retrieves the last size request value from @widget->requisition,
 * while gtk_widget_size_request() actually calls the "size_request" method
 * on @widget to compute the size request and fill in @widget->requisition,
 * and only then returns @widget->requisition.
 * 
 * Because this function does not call the “size_request” method, it
 * can only be used when you know that @widget->requisition is
 * up-to-date, that is, gtk_widget_size_request() has been called
 * since the last time a resize was queued. In general, only container
 * implementations have this information; applications should use
 * gtk_widget_size_request().
 *
 * @param requisition a #GtkRequisition to be filled in
 */
- (void)childRequisition:(GtkRequisition*)requisition;

/**
 * Gets the value set with gtk_widget_set_child_visible().
 * If you feel a need to use this function, your code probably
 * needs reorganization.
 * 
 * This function is only useful for container implementations and
 * never should be called by an application.
 *
 * @return %TRUE if the widget is mapped with the parent.
 */
- (bool)childVisible;

/**
 * Retrieves the widget’s clip area.
 * 
 * The clip area is the area in which all of @widget's drawing will
 * happen. Other toolkits call it the bounding box.
 * 
 * Historically, in GTK+ the clip area has been equal to the allocation
 * retrieved via gtk_widget_get_allocation().
 *
 * @param clip a pointer to a #GtkAllocation to copy to
 */
- (void)clip:(GtkAllocation*)clip;

/**
 * Returns the clipboard object for the given selection to
 * be used with @widget. @widget must have a #GdkDisplay
 * associated with it, so must be attached to a toplevel
 * window.
 *
 * @param selection a #GdkAtom which identifies the clipboard
 *             to use. %GDK_SELECTION_CLIPBOARD gives the
 *             default clipboard. Another common value
 *             is %GDK_SELECTION_PRIMARY, which gives
 *             the primary X selection.
 * @return the appropriate clipboard object. If no
 *             clipboard already exists, a new one will
 *             be created. Once a clipboard object has
 *             been created, it is persistent for all time.
 */
- (OGTKClipboard*)clipboard:(GdkAtom)selection;

/**
 * Obtains the composite name of a widget.
 *
 * @return the composite name of @widget, or %NULL if @widget is not
 *   a composite child. The string should be freed when it is no
 *   longer needed.
 */
- (OFString*)compositeName;

/**
 * Returns whether @device can interact with @widget and its
 * children. See gtk_widget_set_device_enabled().
 *
 * @param device a #GdkDevice
 * @return %TRUE is @device is enabled for @widget
 */
- (bool)deviceEnabled:(OGGdkDevice*)device;

/**
 * Returns the events mask for the widget corresponding to an specific device. These
 * are the events that the widget will receive when @device operates on it.
 *
 * @param device a #GdkDevice
 * @return device event mask for @widget
 */
- (GdkEventMask)deviceEvents:(OGGdkDevice*)device;

/**
 * Gets the reading direction for a particular widget. See
 * gtk_widget_set_direction().
 *
 * @return the reading direction for the widget.
 */
- (GtkTextDirection)direction;

/**
 * Get the #GdkDisplay for the toplevel window associated with
 * this widget. This function can only be called after the widget
 * has been added to a widget hierarchy with a #GtkWindow at the top.
 * 
 * In general, you should only create display specific
 * resources when a widget has been realized, and you should
 * free those resources when the widget is unrealized.
 *
 * @return the #GdkDisplay for the toplevel for this widget.
 */
- (OGGdkDisplay*)display;

/**
 * Determines whether the widget is double buffered.
 * 
 * See gtk_widget_set_double_buffered()
 *
 * @return %TRUE if the widget is double buffered
 */
- (bool)doubleBuffered;

/**
 * Returns the event mask (see #GdkEventMask) for the widget. These are the
 * events that the widget will receive.
 * 
 * Note: Internally, the widget event mask will be the logical OR of the event
 * mask set through gtk_widget_set_events() or gtk_widget_add_events(), and the
 * event mask necessary to cater for every #GtkEventController created for the
 * widget.
 *
 * @return event mask for @widget
 */
- (gint)events;

/**
 * Returns whether the widget should grab focus when it is clicked with the mouse.
 * See gtk_widget_set_focus_on_click().
 *
 * @return %TRUE if the widget should grab focus when it is clicked with
 *               the mouse.
 */
- (bool)focusOnClick;

/**
 * Gets the font map that has been set with gtk_widget_set_font_map().
 *
 * @return A #PangoFontMap, or %NULL
 */
- (OGPangoFontMap*)fontMap;

/**
 * Returns the #cairo_font_options_t used for Pango rendering. When not set,
 * the defaults font options for the #GdkScreen will be used.
 *
 * @return the #cairo_font_options_t or %NULL if not set
 */
- (const cairo_font_options_t*)fontOptions;

/**
 * Obtains the frame clock for a widget. The frame clock is a global
 * “ticker” that can be used to drive animations and repaints.  The
 * most common reason to get the frame clock is to call
 * gdk_frame_clock_get_frame_time(), in order to get a time to use for
 * animating. For example you might record the start of the animation
 * with an initial value from gdk_frame_clock_get_frame_time(), and
 * then update the animation by calling
 * gdk_frame_clock_get_frame_time() again during each repaint.
 * 
 * gdk_frame_clock_request_phase() will result in a new frame on the
 * clock, but won’t necessarily repaint any widgets. To repaint a
 * widget, you have to use gtk_widget_queue_draw() which invalidates
 * the widget (thus scheduling it to receive a draw on the next
 * frame). gtk_widget_queue_draw() will also end up requesting a frame
 * on the appropriate frame clock.
 * 
 * A widget’s frame clock will not change while the widget is
 * mapped. Reparenting a widget (which implies a temporary unmap) can
 * change the widget’s frame clock.
 * 
 * Unrealized widgets do not have a frame clock.
 *
 * @return a #GdkFrameClock,
 * or %NULL if widget is unrealized
 */
- (OGGdkFrameClock*)frameClock;

/**
 * Gets the value of the #GtkWidget:halign property.
 * 
 * For backwards compatibility reasons this method will never return
 * %GTK_ALIGN_BASELINE, but instead it will convert it to
 * %GTK_ALIGN_FILL. Baselines are not supported for horizontal
 * alignment.
 *
 * @return the horizontal alignment of @widget
 */
- (GtkAlign)halign;

/**
 * Returns the current value of the has-tooltip property.  See
 * #GtkWidget:has-tooltip for more information.
 *
 * @return current value of has-tooltip on @widget.
 */
- (bool)hasTooltip;

/**
 * Determines whether @widget has a #GdkWindow of its own. See
 * gtk_widget_set_has_window().
 *
 * @return %TRUE if @widget has a window, %FALSE otherwise
 */
- (bool)hasWindow;

/**
 * Gets whether the widget would like any available extra horizontal
 * space. When a user resizes a #GtkWindow, widgets with expand=TRUE
 * generally receive the extra space. For example, a list or
 * scrollable area or document in your window would often be set to
 * expand.
 * 
 * Containers should use gtk_widget_compute_expand() rather than
 * this function, to see whether a widget, or any of its children,
 * has the expand flag set. If any child of a widget wants to
 * expand, the parent may ask to expand also.
 * 
 * This function only looks at the widget’s own hexpand flag, rather
 * than computing whether the entire widget tree rooted at this widget
 * wants to expand.
 *
 * @return whether hexpand flag is set
 */
- (bool)hexpand;

/**
 * Gets whether gtk_widget_set_hexpand() has been used to
 * explicitly set the expand flag on this widget.
 * 
 * If hexpand is set, then it overrides any computed
 * expand value based on child widgets. If hexpand is not
 * set, then the expand value depends on whether any
 * children of the widget would like to expand.
 * 
 * There are few reasons to use this function, but it’s here
 * for completeness and consistency.
 *
 * @return whether hexpand has been explicitly set
 */
- (bool)hexpandSet;

/**
 * Whether the widget is mapped.
 *
 * @return %TRUE if the widget is mapped, %FALSE otherwise.
 */
- (bool)mapped;

/**
 * Gets the value of the #GtkWidget:margin-bottom property.
 *
 * @return The bottom margin of @widget
 */
- (gint)marginBottom;

/**
 * Gets the value of the #GtkWidget:margin-end property.
 *
 * @return The end margin of @widget
 */
- (gint)marginEnd;

/**
 * Gets the value of the #GtkWidget:margin-left property.
 *
 * @return The left margin of @widget
 */
- (gint)marginLeft;

/**
 * Gets the value of the #GtkWidget:margin-right property.
 *
 * @return The right margin of @widget
 */
- (gint)marginRight;

/**
 * Gets the value of the #GtkWidget:margin-start property.
 *
 * @return The start margin of @widget
 */
- (gint)marginStart;

/**
 * Gets the value of the #GtkWidget:margin-top property.
 *
 * @return The top margin of @widget
 */
- (gint)marginTop;

/**
 * Returns the modifier mask the @widget’s windowing system backend
 * uses for a particular purpose.
 * 
 * See gdk_keymap_get_modifier_mask().
 *
 * @param intent the use case for the modifier mask
 * @return the modifier mask used for @intent.
 */
- (GdkModifierType)modifierMask:(GdkModifierIntent)intent;

/**
 * Returns the current modifier style for the widget. (As set by
 * gtk_widget_modify_style().) If no style has previously set, a new
 * #GtkRcStyle will be created with all values unset, and set as the
 * modifier style for the widget. If you make changes to this rc
 * style, you must call gtk_widget_modify_style(), passing in the
 * returned rc style, to make sure that your changes take effect.
 * 
 * Caution: passing the style back to gtk_widget_modify_style() will
 * normally end up destroying it, because gtk_widget_modify_style() copies
 * the passed-in style and sets the copy as the new modifier style,
 * thus dropping any reference to the old modifier style. Add a reference
 * to the modifier style if you want to keep it alive.
 *
 * @return the modifier style for the widget.
 *     This rc style is owned by the widget. If you want to keep a
 *     pointer to value this around, you must add a refcount using
 *     g_object_ref().
 */
- (OGTKRcStyle*)modifierStyle;

/**
 * Retrieves the name of a widget. See gtk_widget_set_name() for the
 * significance of widget names.
 *
 * @return name of the widget. This string is owned by GTK+ and
 * should not be modified or freed
 */
- (OFString*)name;

/**
 * Returns the current value of the #GtkWidget:no-show-all property,
 * which determines whether calls to gtk_widget_show_all()
 * will affect this widget.
 *
 * @return the current value of the “no-show-all” property.
 */
- (bool)noShowAll;

/**
 * Fetches the requested opacity for this widget.
 * See gtk_widget_set_opacity().
 *
 * @return the requested opacity for this widget.
 */
- (double)opacity;

/**
 * Gets a #PangoContext with the appropriate font map, font description,
 * and base direction for this widget. Unlike the context returned
 * by gtk_widget_create_pango_context(), this context is owned by
 * the widget (it can be used until the screen for the widget changes
 * or the widget is removed from its toplevel), and will be updated to
 * match any changes to the widget’s attributes. This can be tracked
 * by using the #GtkWidget::screen-changed signal on the widget.
 *
 * @return the #PangoContext for the widget.
 */
- (OGPangoContext*)pangoContext;

/**
 * Returns the parent container of @widget.
 *
 * @return the parent container of @widget, or %NULL
 */
- (OGTKWidget*)parent;

/**
 * Gets @widget’s parent window, or %NULL if it does not have one.
 *
 * @return the parent window of @widget, or %NULL
 * if it does not have a parent window.
 */
- (OGGdkWindow*)parentWindow;

/**
 * Returns the #GtkWidgetPath representing @widget, if the widget
 * is not connected to a toplevel widget, a partial path will be
 * created.
 *
 * @return The #GtkWidgetPath representing @widget
 */
- (GtkWidgetPath*)path;

/**
 * Obtains the location of the mouse pointer in widget coordinates.
 * Widget coordinates are a bit odd; for historical reasons, they are
 * defined as @widget->window coordinates for widgets that return %TRUE for
 * gtk_widget_get_has_window(); and are relative to @widget->allocation.x,
 * @widget->allocation.y otherwise.
 *
 * @param x return location for the X coordinate, or %NULL
 * @param y return location for the Y coordinate, or %NULL
 */
- (void)pointerWithX:(gint*)x y:(gint*)y;

/**
 * Retrieves a widget’s initial minimum and natural height.
 * 
 * This call is specific to width-for-height requests.
 * 
 * The returned request will be modified by the
 * GtkWidgetClass::adjust_size_request virtual method and by any
 * #GtkSizeGroups that have been applied. That is, the returned request
 * is the one that should be used for layout, not necessarily the one
 * returned by the widget itself.
 *
 * @param minimumHeight location to store the minimum height, or %NULL
 * @param naturalHeight location to store the natural height, or %NULL
 */
- (void)preferredHeightWithMinimumHeight:(gint*)minimumHeight naturalHeight:(gint*)naturalHeight;

/**
 * Retrieves a widget’s minimum and natural height and the corresponding baselines if it would be given
 * the specified @width, or the default height if @width is -1. The baselines may be -1 which means
 * that no baseline is requested for this widget.
 * 
 * The returned request will be modified by the
 * GtkWidgetClass::adjust_size_request and GtkWidgetClass::adjust_baseline_request virtual methods
 * and by any #GtkSizeGroups that have been applied. That is, the returned request
 * is the one that should be used for layout, not necessarily the one
 * returned by the widget itself.
 *
 * @param width the width which is available for allocation, or -1 if none
 * @param minimumHeight location for storing the minimum height, or %NULL
 * @param naturalHeight location for storing the natural height, or %NULL
 * @param minimumBaseline location for storing the baseline for the minimum height, or %NULL
 * @param naturalBaseline location for storing the baseline for the natural height, or %NULL
 */
- (void)preferredHeightAndBaselineForWidthWithWidth:(gint)width minimumHeight:(gint*)minimumHeight naturalHeight:(gint*)naturalHeight minimumBaseline:(gint*)minimumBaseline naturalBaseline:(gint*)naturalBaseline;

/**
 * Retrieves a widget’s minimum and natural height if it would be given
 * the specified @width.
 * 
 * The returned request will be modified by the
 * GtkWidgetClass::adjust_size_request virtual method and by any
 * #GtkSizeGroups that have been applied. That is, the returned request
 * is the one that should be used for layout, not necessarily the one
 * returned by the widget itself.
 *
 * @param width the width which is available for allocation
 * @param minimumHeight location for storing the minimum height, or %NULL
 * @param naturalHeight location for storing the natural height, or %NULL
 */
- (void)preferredHeightForWidthWithWidth:(gint)width minimumHeight:(gint*)minimumHeight naturalHeight:(gint*)naturalHeight;

/**
 * Retrieves the minimum and natural size of a widget, taking
 * into account the widget’s preference for height-for-width management.
 * 
 * This is used to retrieve a suitable size by container widgets which do
 * not impose any restrictions on the child placement. It can be used
 * to deduce toplevel window and menu sizes as well as child widgets in
 * free-form containers such as GtkLayout.
 * 
 * Handle with care. Note that the natural height of a height-for-width
 * widget will generally be a smaller size than the minimum height, since the required
 * height for the natural width is generally smaller than the required height for
 * the minimum width.
 * 
 * Use gtk_widget_get_preferred_height_and_baseline_for_width() if you want to support
 * baseline alignment.
 *
 * @param minimumSize location for storing the minimum size, or %NULL
 * @param naturalSize location for storing the natural size, or %NULL
 */
- (void)preferredSizeWithMinimumSize:(GtkRequisition*)minimumSize naturalSize:(GtkRequisition*)naturalSize;

/**
 * Retrieves a widget’s initial minimum and natural width.
 * 
 * This call is specific to height-for-width requests.
 * 
 * The returned request will be modified by the
 * GtkWidgetClass::adjust_size_request virtual method and by any
 * #GtkSizeGroups that have been applied. That is, the returned request
 * is the one that should be used for layout, not necessarily the one
 * returned by the widget itself.
 *
 * @param minimumWidth location to store the minimum width, or %NULL
 * @param naturalWidth location to store the natural width, or %NULL
 */
- (void)preferredWidthWithMinimumWidth:(gint*)minimumWidth naturalWidth:(gint*)naturalWidth;

/**
 * Retrieves a widget’s minimum and natural width if it would be given
 * the specified @height.
 * 
 * The returned request will be modified by the
 * GtkWidgetClass::adjust_size_request virtual method and by any
 * #GtkSizeGroups that have been applied. That is, the returned request
 * is the one that should be used for layout, not necessarily the one
 * returned by the widget itself.
 *
 * @param height the height which is available for allocation
 * @param minimumWidth location for storing the minimum width, or %NULL
 * @param naturalWidth location for storing the natural width, or %NULL
 */
- (void)preferredWidthForHeightWithHeight:(gint)height minimumWidth:(gint*)minimumWidth naturalWidth:(gint*)naturalWidth;

/**
 * Determines whether @widget is realized.
 *
 * @return %TRUE if @widget is realized, %FALSE otherwise
 */
- (bool)realized;

/**
 * Determines whether @widget is always treated as the default widget
 * within its toplevel when it has the focus, even if another widget
 * is the default.
 * 
 * See gtk_widget_set_receives_default().
 *
 * @return %TRUE if @widget acts as the default widget when focused,
 *               %FALSE otherwise
 */
- (bool)receivesDefault;

/**
 * Gets whether the widget prefers a height-for-width layout
 * or a width-for-height layout.
 * 
 * #GtkBin widgets generally propagate the preference of
 * their child, container widgets need to request something either in
 * context of their children or in context of their allocation
 * capabilities.
 *
 * @return The #GtkSizeRequestMode preferred by @widget.
 */
- (GtkSizeRequestMode)requestMode;

/**
 * Retrieves the widget’s requisition.
 * 
 * This function should only be used by widget implementations in
 * order to figure whether the widget’s requisition has actually
 * changed after some internal state change (so that they can call
 * gtk_widget_queue_resize() instead of gtk_widget_queue_draw()).
 * 
 * Normally, gtk_widget_size_request() should be used.
 *
 * @param requisition a pointer to a #GtkRequisition to copy to
 */
- (void)requisition:(GtkRequisition*)requisition;

/**
 * Get the root window where this widget is located. This function can
 * only be called after the widget has been added to a widget
 * hierarchy with #GtkWindow at the top.
 * 
 * The root window is useful for such purposes as creating a popup
 * #GdkWindow associated with the window. In general, you should only
 * create display specific resources when a widget has been realized,
 * and you should free those resources when the widget is unrealized.
 *
 * @return the #GdkWindow root window for the toplevel for this widget.
 */
- (OGGdkWindow*)rootWindow;

/**
 * Retrieves the internal scale factor that maps from window coordinates
 * to the actual device pixels. On traditional systems this is 1, on
 * high density outputs, it can be a higher value (typically 2).
 * 
 * See gdk_window_get_scale_factor().
 *
 * @return the scale factor for @widget
 */
- (gint)scaleFactor;

/**
 * Get the #GdkScreen from the toplevel window associated with
 * this widget. This function can only be called after the widget
 * has been added to a widget hierarchy with a #GtkWindow
 * at the top.
 * 
 * In general, you should only create screen specific
 * resources when a widget has been realized, and you should
 * free those resources when the widget is unrealized.
 *
 * @return the #GdkScreen for the toplevel for this widget.
 */
- (OGGdkScreen*)screen;

/**
 * Returns the widget’s sensitivity (in the sense of returning
 * the value that has been set using gtk_widget_set_sensitive()).
 * 
 * The effective sensitivity of a widget is however determined by both its
 * own and its parent widget’s sensitivity. See gtk_widget_is_sensitive().
 *
 * @return %TRUE if the widget is sensitive
 */
- (bool)sensitive;

/**
 * Gets the settings object holding the settings used for this widget.
 * 
 * Note that this function can only be called when the #GtkWidget
 * is attached to a toplevel, since the settings object is specific
 * to a particular #GdkScreen.
 *
 * @return the relevant #GtkSettings object
 */
- (OGTKSettings*)settings;

/**
 * Gets the size request that was explicitly set for the widget using
 * gtk_widget_set_size_request(). A value of -1 stored in @width or
 * @height indicates that that dimension has not been set explicitly
 * and the natural requisition of the widget will be used instead. See
 * gtk_widget_set_size_request(). To get the size a widget will
 * actually request, call gtk_widget_get_preferred_size() instead of
 * this function.
 *
 * @param width return location for width, or %NULL
 * @param height return location for height, or %NULL
 */
- (void)sizeRequestWithWidth:(gint*)width height:(gint*)height;

/**
 * Returns the widget’s state. See gtk_widget_set_state().
 *
 * @return the state of @widget.
 */
- (GtkStateType)state;

/**
 * Returns the widget state as a flag set. It is worth mentioning
 * that the effective %GTK_STATE_FLAG_INSENSITIVE state will be
 * returned, that is, also based on parent insensitivity, even if
 * @widget itself is sensitive.
 * 
 * Also note that if you are looking for a way to obtain the
 * #GtkStateFlags to pass to a #GtkStyleContext method, you
 * should look at gtk_style_context_get_state().
 *
 * @return The state flags for widget
 */
- (GtkStateFlags)stateFlags;

/**
 * Simply an accessor function that returns @widget->style.
 *
 * @return the widget’s #GtkStyle
 */
- (OGTKStyle*)style;

/**
 * Returns the style context associated to @widget. The returned object is
 * guaranteed to be the same for the lifetime of @widget.
 *
 * @return a #GtkStyleContext. This memory is owned by @widget and
 *          must not be freed.
 */
- (OGTKStyleContext*)styleContext;

/**
 * Returns %TRUE if @widget is multiple pointer aware. See
 * gtk_widget_set_support_multidevice() for more information.
 *
 * @return %TRUE if @widget is multidevice aware.
 */
- (bool)supportMultidevice;

/**
 * Fetch an object build from the template XML for @widget_type in this @widget instance.
 * 
 * This will only report children which were previously declared with
 * gtk_widget_class_bind_template_child_full() or one of its
 * variants.
 * 
 * This function is only meant to be called for code which is private to the @widget_type which
 * declared the child and is meant for language bindings which cannot easily make use
 * of the GObject structure offsets.
 *
 * @param widgetType The #GType to get a template child for
 * @param name The “id” of the child defined in the template XML
 * @return The object built in the template XML with the id @name
 */
- (GObject*)templateChildWithWidgetType:(GType)widgetType name:(OFString*)name;

/**
 * Gets the contents of the tooltip for @widget.
 *
 * @return the tooltip text, or %NULL. You should free the
 *   returned string with g_free() when done.
 */
- (OFString*)tooltipMarkup;

/**
 * Gets the contents of the tooltip for @widget.
 *
 * @return the tooltip text, or %NULL. You should free the
 *   returned string with g_free() when done.
 */
- (OFString*)tooltipText;

/**
 * Returns the #GtkWindow of the current tooltip. This can be the
 * GtkWindow created by default, or the custom tooltip window set
 * using gtk_widget_set_tooltip_window().
 *
 * @return The #GtkWindow of the current tooltip.
 */
- (OGTKWindow*)tooltipWindow;

/**
 * This function returns the topmost widget in the container hierarchy
 * @widget is a part of. If @widget has no parent widgets, it will be
 * returned as the topmost widget. No reference will be added to the
 * returned widget; it should not be unreferenced.
 * 
 * Note the difference in behavior vs. gtk_widget_get_ancestor();
 * `gtk_widget_get_ancestor (widget, GTK_TYPE_WINDOW)`
 * would return
 * %NULL if @widget wasn’t inside a toplevel window, and if the
 * window was inside a #GtkWindow-derived widget which was in turn
 * inside the toplevel #GtkWindow. While the second case may
 * seem unlikely, it actually happens when a #GtkPlug is embedded
 * inside a #GtkSocket within the same application.
 * 
 * To reliably find the toplevel #GtkWindow, use
 * gtk_widget_get_toplevel() and call GTK_IS_WINDOW()
 * on the result. For instance, to get the title of a widget's toplevel
 * window, one might use:
 * |[<!-- language="C" -->
 * static const char *
 * get_widget_toplevel_title (GtkWidget *widget)
 * {
 *   GtkWidget *toplevel = gtk_widget_get_toplevel (widget);
 *   if (GTK_IS_WINDOW (toplevel))
 *     {
 *       return gtk_window_get_title (GTK_WINDOW (toplevel));
 *     }
 * 
 *   return NULL;
 * }
 * ]|
 *
 * @return the topmost ancestor of @widget, or @widget itself
 *    if there’s no ancestor.
 */
- (OGTKWidget*)toplevel;

/**
 * Gets the value of the #GtkWidget:valign property.
 * 
 * For backwards compatibility reasons this method will never return
 * %GTK_ALIGN_BASELINE, but instead it will convert it to
 * %GTK_ALIGN_FILL. If your widget want to support baseline aligned
 * children it must use gtk_widget_get_valign_with_baseline(), or
 * `g_object_get (widget, "valign", &value, NULL)`, which will
 * also report the true value.
 *
 * @return the vertical alignment of @widget, ignoring baseline alignment
 */
- (GtkAlign)valign;

/**
 * Gets the value of the #GtkWidget:valign property, including
 * %GTK_ALIGN_BASELINE.
 *
 * @return the vertical alignment of @widget
 */
- (GtkAlign)valignWithBaseline;

/**
 * Gets whether the widget would like any available extra vertical
 * space.
 * 
 * See gtk_widget_get_hexpand() for more detail.
 *
 * @return whether vexpand flag is set
 */
- (bool)vexpand;

/**
 * Gets whether gtk_widget_set_vexpand() has been used to
 * explicitly set the expand flag on this widget.
 * 
 * See gtk_widget_get_hexpand_set() for more detail.
 *
 * @return whether vexpand has been explicitly set
 */
- (bool)vexpandSet;

/**
 * Determines whether the widget is visible. If you want to
 * take into account whether the widget’s parent is also marked as
 * visible, use gtk_widget_is_visible() instead.
 * 
 * This function does not check if the widget is obscured in any way.
 * 
 * See gtk_widget_set_visible().
 *
 * @return %TRUE if the widget is visible
 */
- (bool)visible;

/**
 * Gets the visual that will be used to render @widget.
 *
 * @return the visual for @widget
 */
- (OGGdkVisual*)visual;

/**
 * Returns the widget’s window if it is realized, %NULL otherwise
 *
 * @return @widget’s window.
 */
- (OGGdkWindow*)window;

/**
 * Makes @widget the current grabbed widget.
 * 
 * This means that interaction with other widgets in the same
 * application is blocked and mouse as well as keyboard events
 * are delivered to this widget.
 * 
 * If @widget is not sensitive, it is not set as the current
 * grabbed widget and this function does nothing.
 *
 */
- (void)grabAdd;

/**
 * Causes @widget to become the default widget. @widget must be able to be
 * a default widget; typically you would ensure this yourself
 * by calling gtk_widget_set_can_default() with a %TRUE value.
 * The default widget is activated when
 * the user presses Enter in a window. Default widgets must be
 * activatable, that is, gtk_widget_activate() should affect them. Note
 * that #GtkEntry widgets require the “activates-default” property
 * set to %TRUE before they activate the default widget when Enter
 * is pressed and the #GtkEntry is focused.
 *
 */
- (void)grabDefault;

/**
 * Causes @widget to have the keyboard focus for the #GtkWindow it's
 * inside. @widget must be a focusable widget, such as a #GtkEntry;
 * something like #GtkFrame won’t work.
 * 
 * More precisely, it must have the %GTK_CAN_FOCUS flag set. Use
 * gtk_widget_set_can_focus() to modify that flag.
 * 
 * The widget also needs to be realized and mapped. This is indicated by the
 * related signals. Grabbing the focus immediately after creating the widget
 * will likely fail and cause critical warnings.
 *
 */
- (void)grabFocus;

/**
 * Removes the grab from the given widget.
 * 
 * You have to pair calls to gtk_grab_add() and gtk_grab_remove().
 * 
 * If @widget does not have the grab, this function does nothing.
 *
 */
- (void)grabRemove;

/**
 * Determines whether @widget is the current default widget within its
 * toplevel. See gtk_widget_set_can_default().
 *
 * @return %TRUE if @widget is the current default widget within
 *     its toplevel, %FALSE otherwise
 */
- (bool)hasDefault;

/**
 * Determines if the widget has the global input focus. See
 * gtk_widget_is_focus() for the difference between having the global
 * input focus, and only having the focus within a toplevel.
 *
 * @return %TRUE if the widget has the global input focus.
 */
- (bool)hasFocus;

/**
 * Determines whether the widget is currently grabbing events, so it
 * is the only widget receiving input events (keyboard and mouse).
 * 
 * See also gtk_grab_add().
 *
 * @return %TRUE if the widget is in the grab_widgets stack
 */
- (bool)hasGrab;

/**
 * Determines if the widget style has been looked up through the rc mechanism.
 *
 * @return %TRUE if the widget has been looked up through the rc
 *   mechanism, %FALSE otherwise.
 */
- (bool)hasRcStyle;

/**
 * Checks whether there is a #GdkScreen is associated with
 * this widget. All toplevel widgets have an associated
 * screen, and all widgets added into a hierarchy with a toplevel
 * window at the top.
 *
 * @return %TRUE if there is a #GdkScreen associated
 *   with the widget.
 */
- (bool)hasScreen;

/**
 * Determines if the widget should show a visible indication that
 * it has the global input focus. This is a convenience function for
 * use in ::draw handlers that takes into account whether focus
 * indication should currently be shown in the toplevel window of
 * @widget. See gtk_window_get_focus_visible() for more information
 * about focus indication.
 * 
 * To find out if the widget has the global input focus, use
 * gtk_widget_has_focus().
 *
 * @return %TRUE if the widget should display a “focus rectangle”
 */
- (bool)hasVisibleFocus;

/**
 * Reverses the effects of gtk_widget_show(), causing the widget to be
 * hidden (invisible to the user).
 *
 */
- (void)hide;

/**
 * Utility function; intended to be connected to the #GtkWidget::delete-event
 * signal on a #GtkWindow. The function calls gtk_widget_hide() on its
 * argument, then returns %TRUE. If connected to ::delete-event, the
 * result is that clicking the close button for a window (on the
 * window frame, top right corner usually) will hide but not destroy
 * the window. By default, GTK+ destroys windows when ::delete-event
 * is received.
 *
 * @return %TRUE
 */
- (bool)hideOnDelete;

/**
 * Returns whether the widget is currently being destroyed.
 * This information can sometimes be used to avoid doing
 * unnecessary work.
 *
 * @return %TRUE if @widget is being destroyed
 */
- (bool)inDestruction;

/**
 * Creates and initializes child widgets defined in templates. This
 * function must be called in the instance initializer for any
 * class which assigned itself a template using gtk_widget_class_set_template()
 * 
 * It is important to call this function in the instance initializer
 * of a #GtkWidget subclass and not in #GObject.constructed() or
 * #GObject.constructor() for two reasons.
 * 
 * One reason is that generally derived widgets will assume that parent
 * class composite widgets have been created in their instance
 * initializers.
 * 
 * Another reason is that when calling g_object_new() on a widget with
 * composite templates, it’s important to build the composite widgets
 * before the construct properties are set. Properties passed to g_object_new()
 * should take precedence over properties set in the private template XML.
 *
 */
- (void)initTemplate;

/**
 * Sets an input shape for this widget’s GDK window. This allows for
 * windows which react to mouse click in a nonrectangular region, see
 * gdk_window_input_shape_combine_region() for more information.
 *
 * @param region shape to be added, or %NULL to remove an existing shape
 */
- (void)inputShapeCombineRegion:(cairo_region_t*)region;

/**
 * Inserts @group into @widget. Children of @widget that implement
 * #GtkActionable can then be associated with actions in @group by
 * setting their “action-name” to
 * @prefix.`action-name`.
 * 
 * If @group is %NULL, a previously inserted group for @name is removed
 * from @widget.
 *
 * @param name the prefix for actions in @group
 * @param group a #GActionGroup, or %NULL
 */
- (void)insertActionGroupWithName:(OFString*)name group:(GActionGroup*)group;

/**
 * Computes the intersection of a @widget’s area and @area, storing
 * the intersection in @intersection, and returns %TRUE if there was
 * an intersection.  @intersection may be %NULL if you’re only
 * interested in whether there was an intersection.
 *
 * @param area a rectangle
 * @param intersection rectangle to store
 *   intersection of @widget and @area
 * @return %TRUE if there was an intersection
 */
- (bool)intersectWithArea:(const GdkRectangle*)area intersection:(GdkRectangle*)intersection;

/**
 * Determines whether @widget is somewhere inside @ancestor, possibly with
 * intermediate containers.
 *
 * @param ancestor another #GtkWidget
 * @return %TRUE if @ancestor contains @widget as a child,
 *    grandchild, great grandchild, etc.
 */
- (bool)isAncestor:(OGTKWidget*)ancestor;

/**
 * Whether @widget can rely on having its alpha channel
 * drawn correctly. On X11 this function returns whether a
 * compositing manager is running for @widget’s screen.
 * 
 * Please note that the semantics of this call will change
 * in the future if used on a widget that has a composited
 * window in its hierarchy (as set by gdk_window_set_composited()).
 *
 * @return %TRUE if the widget can rely on its alpha
 * channel being drawn correctly.
 */
- (bool)isComposited;

/**
 * Determines whether @widget can be drawn to. A widget can be drawn
 * to if it is mapped and visible.
 *
 * @return %TRUE if @widget is drawable, %FALSE otherwise
 */
- (bool)isDrawable;

/**
 * Determines if the widget is the focus widget within its
 * toplevel. (This does not mean that the #GtkWidget:has-focus property is
 * necessarily set; #GtkWidget:has-focus will only be set if the
 * toplevel widget additionally has the global input focus.)
 *
 * @return %TRUE if the widget is the focus widget.
 */
- (bool)isFocus;

/**
 * Returns the widget’s effective sensitivity, which means
 * it is sensitive itself and also its parent widget is sensitive
 *
 * @return %TRUE if the widget is effectively sensitive
 */
- (bool)isSensitive;

/**
 * Determines whether @widget is a toplevel widget.
 * 
 * Currently only #GtkWindow and #GtkInvisible (and out-of-process
 * #GtkPlugs) are toplevel widgets. Toplevel widgets have no parent
 * widget.
 *
 * @return %TRUE if @widget is a toplevel, %FALSE otherwise
 */
- (bool)isToplevel;

/**
 * Determines whether the widget and all its parents are marked as
 * visible.
 * 
 * This function does not check if the widget is obscured in any way.
 * 
 * See also gtk_widget_get_visible() and gtk_widget_set_visible()
 *
 * @return %TRUE if the widget and all its parents are visible
 */
- (bool)isVisible;

/**
 * This function should be called whenever keyboard navigation within
 * a single widget hits a boundary. The function emits the
 * #GtkWidget::keynav-failed signal on the widget and its return
 * value should be interpreted in a way similar to the return value of
 * gtk_widget_child_focus():
 * 
 * When %TRUE is returned, stay in the widget, the failed keyboard
 * navigation is OK and/or there is nowhere we can/should move the
 * focus to.
 * 
 * When %FALSE is returned, the caller should continue with keyboard
 * navigation outside the widget, e.g. by calling
 * gtk_widget_child_focus() on the widget’s toplevel.
 * 
 * The default ::keynav-failed handler returns %FALSE for
 * %GTK_DIR_TAB_FORWARD and %GTK_DIR_TAB_BACKWARD. For the other
 * values of #GtkDirectionType it returns %TRUE.
 * 
 * Whenever the default handler returns %TRUE, it also calls
 * gtk_widget_error_bell() to notify the user of the failed keyboard
 * navigation.
 * 
 * A use case for providing an own implementation of ::keynav-failed
 * (either by connecting to it or by overriding it) would be a row of
 * #GtkEntry widgets where the user should be able to navigate the
 * entire row with the cursor keys, as e.g. known from user interfaces
 * that require entering license keys.
 *
 * @param direction direction of focus movement
 * @return %TRUE if stopping keyboard navigation is fine, %FALSE
 *               if the emitting widget should try to handle the keyboard
 *               navigation attempt in its parent container(s).
 */
- (bool)keynavFailed:(GtkDirectionType)direction;

/**
 * Lists the closures used by @widget for accelerator group connections
 * with gtk_accel_group_connect_by_path() or gtk_accel_group_connect().
 * The closures can be used to monitor accelerator changes on @widget,
 * by connecting to the @GtkAccelGroup::accel-changed signal of the
 * #GtkAccelGroup of a closure which can be found out with
 * gtk_accel_group_from_accel_closure().
 *
 * @return a newly allocated #GList of closures
 */
- (GList*)listAccelClosures;

/**
 * Retrieves a %NULL-terminated array of strings containing the prefixes of
 * #GActionGroup's available to @widget.
 *
 * @return a %NULL-terminated array of strings.
 */
- (const gchar**)listActionPrefixes;

/**
 * Returns a newly allocated list of the widgets, normally labels, for
 * which this widget is the target of a mnemonic (see for example,
 * gtk_label_set_mnemonic_widget()).
 * 
 * The widgets in the list are not individually referenced. If you
 * want to iterate through the list and perform actions involving
 * callbacks that might destroy the widgets, you
 * must call `g_list_foreach (result,
 * (GFunc)g_object_ref, NULL)` first, and then unref all the
 * widgets afterwards.
 *
 * @return the list of
 *  mnemonic labels; free this list
 *  with g_list_free() when you are done with it.
 */
- (GList*)listMnemonicLabels;

/**
 * This function is only for use in widget implementations. Causes
 * a widget to be mapped if it isn’t already.
 *
 */
- (void)map;

/**
 * Emits the #GtkWidget::mnemonic-activate signal.
 *
 * @param groupCycling %TRUE if there are other widgets with the same mnemonic
 * @return %TRUE if the signal has been handled
 */
- (bool)mnemonicActivate:(bool)groupCycling;

/**
 * Sets the base color for a widget in a particular state.
 * All other style values are left untouched. The base color
 * is the background color used along with the text color
 * (see gtk_widget_modify_text()) for widgets such as #GtkEntry
 * and #GtkTextView. See also gtk_widget_modify_style().
 * 
 * > Note that “no window” widgets (which have the %GTK_NO_WINDOW
 * > flag set) draw on their parent container’s window and thus may
 * > not draw any background themselves. This is the case for e.g.
 * > #GtkLabel.
 * >
 * > To modify the background of such widgets, you have to set the
 * > base color on their parent; if you want to set the background
 * > of a rectangular area around a label, try placing the label in
 * > a #GtkEventBox widget and setting the base color on that.
 *
 * @param state the state for which to set the base color
 * @param color the color to assign (does not need to
 *     be allocated), or %NULL to undo the effect of previous
 *     calls to of gtk_widget_modify_base().
 */
- (void)modifyBaseWithState:(GtkStateType)state color:(const GdkColor*)color;

/**
 * Sets the background color for a widget in a particular state.
 * 
 * All other style values are left untouched.
 * See also gtk_widget_modify_style().
 * 
 * > Note that “no window” widgets (which have the %GTK_NO_WINDOW
 * > flag set) draw on their parent container’s window and thus may
 * > not draw any background themselves. This is the case for e.g.
 * > #GtkLabel.
 * >
 * > To modify the background of such widgets, you have to set the
 * > background color on their parent; if you want to set the background
 * > of a rectangular area around a label, try placing the label in
 * > a #GtkEventBox widget and setting the background color on that.
 *
 * @param state the state for which to set the background color
 * @param color the color to assign (does not need
 *     to be allocated), or %NULL to undo the effect of previous
 *     calls to of gtk_widget_modify_bg().
 */
- (void)modifyBgWithState:(GtkStateType)state color:(const GdkColor*)color;

/**
 * Sets the cursor color to use in a widget, overriding the #GtkWidget
 * cursor-color and secondary-cursor-color
 * style properties.
 * 
 * All other style values are left untouched.
 * See also gtk_widget_modify_style().
 *
 * @param primary the color to use for primary cursor (does not
 *     need to be allocated), or %NULL to undo the effect of previous
 *     calls to of gtk_widget_modify_cursor().
 * @param secondary the color to use for secondary cursor (does
 *     not need to be allocated), or %NULL to undo the effect of
 *     previous calls to of gtk_widget_modify_cursor().
 */
- (void)modifyCursorWithPrimary:(const GdkColor*)primary secondary:(const GdkColor*)secondary;

/**
 * Sets the foreground color for a widget in a particular state.
 * 
 * All other style values are left untouched.
 * See also gtk_widget_modify_style().
 *
 * @param state the state for which to set the foreground color
 * @param color the color to assign (does not need to be allocated),
 *     or %NULL to undo the effect of previous calls to
 *     of gtk_widget_modify_fg().
 */
- (void)modifyFgWithState:(GtkStateType)state color:(const GdkColor*)color;

/**
 * Sets the font to use for a widget.
 * 
 * All other style values are left untouched.
 * See also gtk_widget_modify_style().
 *
 * @param fontDesc the font description to use, or %NULL
 *     to undo the effect of previous calls to gtk_widget_modify_font()
 */
- (void)modifyFont:(PangoFontDescription*)fontDesc;

/**
 * Modifies style values on the widget.
 * 
 * Modifications made using this technique take precedence over
 * style values set via an RC file, however, they will be overridden
 * if a style is explicitly set on the widget using gtk_widget_set_style().
 * The #GtkRcStyle-struct is designed so each field can either be
 * set or unset, so it is possible, using this function, to modify some
 * style values and leave the others unchanged.
 * 
 * Note that modifications made with this function are not cumulative
 * with previous calls to gtk_widget_modify_style() or with such
 * functions as gtk_widget_modify_fg(). If you wish to retain
 * previous values, you must first call gtk_widget_get_modifier_style(),
 * make your modifications to the returned style, then call
 * gtk_widget_modify_style() with that style. On the other hand,
 * if you first call gtk_widget_modify_style(), subsequent calls
 * to such functions gtk_widget_modify_fg() will have a cumulative
 * effect with the initial modifications.
 *
 * @param style the #GtkRcStyle-struct holding the style modifications
 */
- (void)modifyStyle:(OGTKRcStyle*)style;

/**
 * Sets the text color for a widget in a particular state.
 * 
 * All other style values are left untouched.
 * The text color is the foreground color used along with the
 * base color (see gtk_widget_modify_base()) for widgets such
 * as #GtkEntry and #GtkTextView.
 * See also gtk_widget_modify_style().
 *
 * @param state the state for which to set the text color
 * @param color the color to assign (does not need to
 *     be allocated), or %NULL to undo the effect of previous
 *     calls to of gtk_widget_modify_text().
 */
- (void)modifyTextWithState:(GtkStateType)state color:(const GdkColor*)color;

/**
 * Sets the background color to use for a widget.
 * 
 * All other style values are left untouched.
 * See gtk_widget_override_color().
 *
 * @param state the state for which to set the background color
 * @param color the color to assign, or %NULL to undo the effect
 *     of previous calls to gtk_widget_override_background_color()
 */
- (void)overrideBackgroundColorWithState:(GtkStateFlags)state color:(const GdkRGBA*)color;

/**
 * Sets the color to use for a widget.
 * 
 * All other style values are left untouched.
 * 
 * This function does not act recursively. Setting the color of a
 * container does not affect its children. Note that some widgets that
 * you may not think of as containers, for instance #GtkButtons,
 * are actually containers.
 * 
 * This API is mostly meant as a quick way for applications to
 * change a widget appearance. If you are developing a widgets
 * library and intend this change to be themeable, it is better
 * done by setting meaningful CSS classes in your
 * widget/container implementation through gtk_style_context_add_class().
 * 
 * This way, your widget library can install a #GtkCssProvider
 * with the %GTK_STYLE_PROVIDER_PRIORITY_FALLBACK priority in order
 * to provide a default styling for those widgets that need so, and
 * this theming may fully overridden by the user’s theme.
 * 
 * Note that for complex widgets this may bring in undesired
 * results (such as uniform background color everywhere), in
 * these cases it is better to fully style such widgets through a
 * #GtkCssProvider with the %GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
 * priority.
 *
 * @param state the state for which to set the color
 * @param color the color to assign, or %NULL to undo the effect
 *     of previous calls to gtk_widget_override_color()
 */
- (void)overrideColorWithState:(GtkStateFlags)state color:(const GdkRGBA*)color;

/**
 * Sets the cursor color to use in a widget, overriding the
 * cursor-color and secondary-cursor-color
 * style properties. All other style values are left untouched.
 * See also gtk_widget_modify_style().
 * 
 * Note that the underlying properties have the #GdkColor type,
 * so the alpha value in @primary and @secondary will be ignored.
 *
 * @param cursor the color to use for primary cursor (does not need to be
 *     allocated), or %NULL to undo the effect of previous calls to
 *     of gtk_widget_override_cursor().
 * @param secondaryCursor the color to use for secondary cursor (does not
 *     need to be allocated), or %NULL to undo the effect of previous
 *     calls to of gtk_widget_override_cursor().
 */
- (void)overrideCursorWithCursor:(const GdkRGBA*)cursor secondaryCursor:(const GdkRGBA*)secondaryCursor;

/**
 * Sets the font to use for a widget. All other style values are
 * left untouched. See gtk_widget_override_color().
 *
 * @param fontDesc the font description to use, or %NULL to undo
 *     the effect of previous calls to gtk_widget_override_font()
 */
- (void)overrideFont:(const PangoFontDescription*)fontDesc;

/**
 * Sets a symbolic color for a widget.
 * 
 * All other style values are left untouched.
 * See gtk_widget_override_color() for overriding the foreground
 * or background color.
 *
 * @param name the name of the symbolic color to modify
 * @param color the color to assign (does not need
 *     to be allocated), or %NULL to undo the effect of previous
 *     calls to gtk_widget_override_symbolic_color()
 */
- (void)overrideSymbolicColorWithName:(OFString*)name color:(const GdkRGBA*)color;

/**
 * Obtains the full path to @widget. The path is simply the name of a
 * widget and all its parents in the container hierarchy, separated by
 * periods. The name of a widget comes from
 * gtk_widget_get_name(). Paths are used to apply styles to a widget
 * in gtkrc configuration files. Widget names are the type of the
 * widget by default (e.g. “GtkButton”) or can be set to an
 * application-specific value with gtk_widget_set_name(). By setting
 * the name of a widget, you allow users or theme authors to apply
 * styles to that specific widget in their gtkrc
 * file. @path_reversed_p fills in the path in reverse order,
 * i.e. starting with @widget’s name instead of starting with the name
 * of @widget’s outermost ancestor.
 *
 * @param pathLength location to store length of the path,
 *     or %NULL
 * @param path location to store allocated path string,
 *     or %NULL
 * @param pathReversed location to store allocated reverse
 *     path string, or %NULL
 */
- (void)pathWithPathLength:(guint*)pathLength path:(gchar**)path pathReversed:(gchar**)pathReversed;

/**
 * This function is only for use in widget implementations.
 * 
 * Flags the widget for a rerun of the GtkWidgetClass::size_allocate
 * function. Use this function instead of gtk_widget_queue_resize()
 * when the @widget's size request didn't change but it wants to
 * reposition its contents.
 * 
 * An example user of this function is gtk_widget_set_halign().
 *
 */
- (void)queueAllocate;

/**
 * Mark @widget as needing to recompute its expand flags. Call
 * this function when setting legacy expand child properties
 * on the child of a container.
 * 
 * See gtk_widget_compute_expand().
 *
 */
- (void)queueComputeExpand;

/**
 * Equivalent to calling gtk_widget_queue_draw_area() for the
 * entire area of a widget.
 *
 */
- (void)queueDraw;

/**
 * Convenience function that calls gtk_widget_queue_draw_region() on
 * the region created from the given coordinates.
 * 
 * The region here is specified in widget coordinates.
 * Widget coordinates are a bit odd; for historical reasons, they are
 * defined as @widget->window coordinates for widgets that return %TRUE for
 * gtk_widget_get_has_window(), and are relative to @widget->allocation.x,
 * @widget->allocation.y otherwise.
 * 
 * @width or @height may be 0, in this case this function does
 * nothing. Negative values for @width and @height are not allowed.
 *
 * @param x x coordinate of upper-left corner of rectangle to redraw
 * @param y y coordinate of upper-left corner of rectangle to redraw
 * @param width width of region to draw
 * @param height height of region to draw
 */
- (void)queueDrawAreaWithX:(gint)x y:(gint)y width:(gint)width height:(gint)height;

/**
 * Invalidates the area of @widget defined by @region by calling
 * gdk_window_invalidate_region() on the widget’s window and all its
 * child windows. Once the main loop becomes idle (after the current
 * batch of events has been processed, roughly), the window will
 * receive expose events for the union of all regions that have been
 * invalidated.
 * 
 * Normally you would only use this function in widget
 * implementations. You might also use it to schedule a redraw of a
 * #GtkDrawingArea or some portion thereof.
 *
 * @param region region to draw
 */
- (void)queueDrawRegion:(const cairo_region_t*)region;

/**
 * This function is only for use in widget implementations.
 * Flags a widget to have its size renegotiated; should
 * be called when a widget for some reason has a new size request.
 * For example, when you change the text in a #GtkLabel, #GtkLabel
 * queues a resize to ensure there’s enough space for the new text.
 * 
 * Note that you cannot call gtk_widget_queue_resize() on a widget
 * from inside its implementation of the GtkWidgetClass::size_allocate
 * virtual method. Calls to gtk_widget_queue_resize() from inside
 * GtkWidgetClass::size_allocate will be silently ignored.
 *
 */
- (void)queueResize;

/**
 * This function works like gtk_widget_queue_resize(),
 * except that the widget is not invalidated.
 *
 */
- (void)queueResizeNoRedraw;

/**
 * Creates the GDK (windowing system) resources associated with a
 * widget.  For example, @widget->window will be created when a widget
 * is realized.  Normally realization happens implicitly; if you show
 * a widget and all its parent containers, then the widget will be
 * realized and mapped automatically.
 * 
 * Realizing a widget requires all
 * the widget’s parent widgets to be realized; calling
 * gtk_widget_realize() realizes the widget’s parents in addition to
 * @widget itself. If a widget is not yet inside a toplevel window
 * when you realize it, bad things will happen.
 * 
 * This function is primarily used in widget implementations, and
 * isn’t very useful otherwise. Many times when you think you might
 * need it, a better approach is to connect to a signal that will be
 * called after the widget is realized automatically, such as
 * #GtkWidget::draw. Or simply g_signal_connect () to the
 * #GtkWidget::realize signal.
 *
 */
- (void)realize;

/**
 * Computes the intersection of a @widget’s area and @region, returning
 * the intersection. The result may be empty, use cairo_region_is_empty() to
 * check.
 *
 * @param region a #cairo_region_t, in the same coordinate system as
 *          @widget->allocation. That is, relative to @widget->window
 *          for widgets which return %FALSE from gtk_widget_get_has_window();
 *          relative to the parent window of @widget->window otherwise.
 * @return A newly allocated region holding the intersection of @widget
 *     and @region.
 */
- (cairo_region_t*)regionIntersect:(const cairo_region_t*)region;

/**
 * Registers a #GdkWindow with the widget and sets it up so that
 * the widget receives events for it. Call gtk_widget_unregister_window()
 * when destroying the window.
 * 
 * Before 3.8 you needed to call gdk_window_set_user_data() directly to set
 * this up. This is now deprecated and you should use gtk_widget_register_window()
 * instead. Old code will keep working as is, although some new features like
 * transparency might not work perfectly.
 *
 * @param window a #GdkWindow
 */
- (void)registerWindow:(OGGdkWindow*)window;

/**
 * Removes an accelerator from @widget, previously installed with
 * gtk_widget_add_accelerator().
 *
 * @param accelGroup accel group for this widget
 * @param accelKey GDK keyval of the accelerator
 * @param accelMods modifier key combination of the accelerator
 * @return whether an accelerator was installed and could be removed
 */
- (bool)removeAcceleratorWithAccelGroup:(OGTKAccelGroup*)accelGroup accelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods;

/**
 * Removes a widget from the list of mnemonic labels for
 * this widget. (See gtk_widget_list_mnemonic_labels()). The widget
 * must have previously been added to the list with
 * gtk_widget_add_mnemonic_label().
 *
 * @param label a #GtkWidget that was previously set as a mnemonic label for
 *         @widget with gtk_widget_add_mnemonic_label().
 */
- (void)removeMnemonicLabel:(OGTKWidget*)label;

/**
 * Removes a tick callback previously registered with
 * gtk_widget_add_tick_callback().
 *
 * @param id an id returned by gtk_widget_add_tick_callback()
 */
- (void)removeTickCallback:(guint)id;

/**
 * A convenience function that uses the theme settings for @widget
 * to look up @stock_id and render it to a pixbuf. @stock_id should
 * be a stock icon ID such as #GTK_STOCK_OPEN or #GTK_STOCK_OK. @size
 * should be a size such as #GTK_ICON_SIZE_MENU. @detail should be a
 * string that identifies the widget or code doing the rendering, so
 * that theme engines can special-case rendering for that widget or
 * code.
 * 
 * The pixels in the returned #GdkPixbuf are shared with the rest of
 * the application and should not be modified. The pixbuf should be
 * freed after use with g_object_unref().
 *
 * @param stockId a stock ID
 * @param size a stock size (#GtkIconSize). A size of `(GtkIconSize)-1`
 *     means render at the size of the source and don’t scale (if there are
 *     multiple source sizes, GTK+ picks one of the available sizes).
 * @param detail render detail to pass to theme engine
 * @return a new pixbuf, or %NULL if the
 *     stock ID wasn’t known
 */
- (OGGdkPixbuf*)renderIconWithStockId:(OFString*)stockId size:(GtkIconSize)size detail:(OFString*)detail;

/**
 * A convenience function that uses the theme engine and style
 * settings for @widget to look up @stock_id and render it to
 * a pixbuf. @stock_id should be a stock icon ID such as
 * #GTK_STOCK_OPEN or #GTK_STOCK_OK. @size should be a size
 * such as #GTK_ICON_SIZE_MENU.
 * 
 * The pixels in the returned #GdkPixbuf are shared with the rest of
 * the application and should not be modified. The pixbuf should be freed
 * after use with g_object_unref().
 *
 * @param stockId a stock ID
 * @param size a stock size (#GtkIconSize). A size of `(GtkIconSize)-1`
 *     means render at the size of the source and don’t scale (if there are
 *     multiple source sizes, GTK+ picks one of the available sizes).
 * @return a new pixbuf, or %NULL if the
 *     stock ID wasn’t known
 */
- (OGGdkPixbuf*)renderIconPixbufWithStockId:(OFString*)stockId size:(GtkIconSize)size;

/**
 * Moves a widget from one #GtkContainer to another, handling reference
 * count issues to avoid destroying the widget.
 *
 * @param newParent a #GtkContainer to move the widget into
 */
- (void)reparent:(OGTKWidget*)newParent;

/**
 * Reset the styles of @widget and all descendents, so when
 * they are looked up again, they get the correct values
 * for the currently loaded RC file settings.
 * 
 * This function is not useful for applications.
 *
 */
- (void)resetRcStyles;

/**
 * Updates the style context of @widget and all descendants
 * by updating its widget path. #GtkContainers may want
 * to use this on a child when reordering it in a way that a different
 * style might apply to it. See also gtk_container_get_path_for_child().
 *
 */
- (void)resetStyle;

/**
 * Very rarely-used function. This function is used to emit
 * an expose event on a widget. This function is not normally used
 * directly. The only time it is used is when propagating an expose
 * event to a windowless child widget (gtk_widget_get_has_window() is %FALSE),
 * and that is normally done using gtk_container_propagate_draw().
 * 
 * If you want to force an area of a window to be redrawn,
 * use gdk_window_invalidate_rect() or gdk_window_invalidate_region().
 * To cause the redraw to be done immediately, follow that call
 * with a call to gdk_window_process_updates().
 *
 * @param event a expose #GdkEvent
 * @return return from the event signal emission (%TRUE if
 *   the event was handled)
 */
- (gint)sendExpose:(GdkEvent*)event;

/**
 * Sends the focus change @event to @widget
 * 
 * This function is not meant to be used by applications. The only time it
 * should be used is when it is necessary for a #GtkWidget to assign focus
 * to a widget that is semantically owned by the first widget even though
 * it’s not a direct child - for instance, a search entry in a floating
 * window similar to the quick search in #GtkTreeView.
 * 
 * An example of its usage is:
 * 
 * |[<!-- language="C" -->
 *   GdkEvent *fevent = gdk_event_new (GDK_FOCUS_CHANGE);
 * 
 *   fevent->focus_change.type = GDK_FOCUS_CHANGE;
 *   fevent->focus_change.in = TRUE;
 *   fevent->focus_change.window = _gtk_widget_get_window (widget);
 *   if (fevent->focus_change.window != NULL)
 *     g_object_ref (fevent->focus_change.window);
 * 
 *   gtk_widget_send_focus_change (widget, fevent);
 * 
 *   gdk_event_free (event);
 * ]|
 *
 * @param event a #GdkEvent of type GDK_FOCUS_CHANGE
 * @return the return value from the event signal emission: %TRUE
 *   if the event was handled, and %FALSE otherwise
 */
- (bool)sendFocusChange:(GdkEvent*)event;

/**
 * Given an accelerator group, @accel_group, and an accelerator path,
 * @accel_path, sets up an accelerator in @accel_group so whenever the
 * key binding that is defined for @accel_path is pressed, @widget
 * will be activated.  This removes any accelerators (for any
 * accelerator group) installed by previous calls to
 * gtk_widget_set_accel_path(). Associating accelerators with
 * paths allows them to be modified by the user and the modifications
 * to be saved for future use. (See gtk_accel_map_save().)
 * 
 * This function is a low level function that would most likely
 * be used by a menu creation system like #GtkUIManager. If you
 * use #GtkUIManager, setting up accelerator paths will be done
 * automatically.
 * 
 * Even when you you aren’t using #GtkUIManager, if you only want to
 * set up accelerators on menu items gtk_menu_item_set_accel_path()
 * provides a somewhat more convenient interface.
 * 
 * Note that @accel_path string will be stored in a #GQuark. Therefore, if you
 * pass a static string, you can save some memory by interning it first with
 * g_intern_static_string().
 *
 * @param accelPath path used to look up the accelerator
 * @param accelGroup a #GtkAccelGroup.
 */
- (void)setAccelPathWithAccelPath:(OFString*)accelPath accelGroup:(OGTKAccelGroup*)accelGroup;

/**
 * Sets the widget’s allocation.  This should not be used
 * directly, but from within a widget’s size_allocate method.
 * 
 * The allocation set should be the “adjusted” or actual
 * allocation. If you’re implementing a #GtkContainer, you want to use
 * gtk_widget_size_allocate() instead of gtk_widget_set_allocation().
 * The GtkWidgetClass::adjust_size_allocation virtual method adjusts the
 * allocation inside gtk_widget_size_allocate() to create an adjusted
 * allocation.
 *
 * @param allocation a pointer to a #GtkAllocation to copy from
 */
- (void)setAllocation:(const GtkAllocation*)allocation;

/**
 * Sets whether the application intends to draw on the widget in
 * an #GtkWidget::draw handler.
 * 
 * This is a hint to the widget and does not affect the behavior of
 * the GTK+ core; many widgets ignore this flag entirely. For widgets
 * that do pay attention to the flag, such as #GtkEventBox and #GtkWindow,
 * the effect is to suppress default themed drawing of the widget's
 * background. (Children of the widget will still be drawn.) The application
 * is then entirely responsible for drawing the widget background.
 * 
 * Note that the background is still drawn when the widget is mapped.
 *
 * @param appPaintable %TRUE if the application will paint on the widget
 */
- (void)setAppPaintable:(bool)appPaintable;

/**
 * Specifies whether @widget can be a default widget. See
 * gtk_widget_grab_default() for details about the meaning of
 * “default”.
 *
 * @param canDefault whether or not @widget can be a default widget.
 */
- (void)setCanDefault:(bool)canDefault;

/**
 * Specifies whether @widget can own the input focus. See
 * gtk_widget_grab_focus() for actually setting the input focus on a
 * widget.
 *
 * @param canFocus whether or not @widget can own the input focus.
 */
- (void)setCanFocus:(bool)canFocus;

/**
 * Sets whether @widget should be mapped along with its when its parent
 * is mapped and @widget has been shown with gtk_widget_show().
 * 
 * The child visibility can be set for widget before it is added to
 * a container with gtk_widget_set_parent(), to avoid mapping
 * children unnecessary before immediately unmapping them. However
 * it will be reset to its default state of %TRUE when the widget
 * is removed from a container.
 * 
 * Note that changing the child visibility of a widget does not
 * queue a resize on the widget. Most of the time, the size of
 * a widget is computed from all visible children, whether or
 * not they are mapped. If this is not the case, the container
 * can queue a resize itself.
 * 
 * This function is only useful for container implementations and
 * never should be called by an application.
 *
 * @param isVisible if %TRUE, @widget should be mapped along with its parent.
 */
- (void)setChildVisible:(bool)isVisible;

/**
 * Sets the widget’s clip.  This must not be used directly,
 * but from within a widget’s size_allocate method.
 * It must be called after gtk_widget_set_allocation() (or after chaining up
 * to the parent class), because that function resets the clip.
 * 
 * The clip set should be the area that @widget draws on. If @widget is a
 * #GtkContainer, the area must contain all children's clips.
 * 
 * If this function is not called by @widget during a ::size-allocate handler,
 * the clip will be set to @widget's allocation.
 *
 * @param clip a pointer to a #GtkAllocation to copy from
 */
- (void)setClip:(const GtkAllocation*)clip;

/**
 * Sets a widgets composite name. The widget must be
 * a composite child of its parent; see gtk_widget_push_composite_child().
 *
 * @param name the name to set
 */
- (void)setCompositeName:(OFString*)name;

/**
 * Enables or disables a #GdkDevice to interact with @widget
 * and all its children.
 * 
 * It does so by descending through the #GdkWindow hierarchy
 * and enabling the same mask that is has for core events
 * (i.e. the one that gdk_window_get_events() returns).
 *
 * @param device a #GdkDevice
 * @param enabled whether to enable the device
 */
- (void)setDeviceEnabledWithDevice:(OGGdkDevice*)device enabled:(bool)enabled;

/**
 * Sets the device event mask (see #GdkEventMask) for a widget. The event
 * mask determines which events a widget will receive from @device. Keep
 * in mind that different widgets have different default event masks, and by
 * changing the event mask you may disrupt a widget’s functionality,
 * so be careful. This function must be called while a widget is
 * unrealized. Consider gtk_widget_add_device_events() for widgets that are
 * already realized, or if you want to preserve the existing event
 * mask. This function can’t be used with windowless widgets (which return
 * %FALSE from gtk_widget_get_has_window());
 * to get events on those widgets, place them inside a #GtkEventBox
 * and receive events on the event box.
 *
 * @param device a #GdkDevice
 * @param events event mask
 */
- (void)setDeviceEventsWithDevice:(OGGdkDevice*)device events:(GdkEventMask)events;

/**
 * Sets the reading direction on a particular widget. This direction
 * controls the primary direction for widgets containing text,
 * and also the direction in which the children of a container are
 * packed. The ability to set the direction is present in order
 * so that correct localization into languages with right-to-left
 * reading directions can be done. Generally, applications will
 * let the default reading direction present, except for containers
 * where the containers are arranged in an order that is explicitly
 * visual rather than logical (such as buttons for text justification).
 * 
 * If the direction is set to %GTK_TEXT_DIR_NONE, then the value
 * set by gtk_widget_set_default_direction() will be used.
 *
 * @param dir the new direction
 */
- (void)setDirection:(GtkTextDirection)dir;

/**
 * Widgets are double buffered by default; you can use this function
 * to turn off the buffering. “Double buffered” simply means that
 * gdk_window_begin_draw_frame() and gdk_window_end_draw_frame() are called
 * automatically around expose events sent to the
 * widget. gdk_window_begin_draw_frame() diverts all drawing to a widget's
 * window to an offscreen buffer, and gdk_window_end_draw_frame() draws the
 * buffer to the screen. The result is that users see the window
 * update in one smooth step, and don’t see individual graphics
 * primitives being rendered.
 * 
 * In very simple terms, double buffered widgets don’t flicker,
 * so you would only use this function to turn off double buffering
 * if you had special needs and really knew what you were doing.
 * 
 * Note: if you turn off double-buffering, you have to handle
 * expose events, since even the clearing to the background color or
 * pixmap will not happen automatically (as it is done in
 * gdk_window_begin_draw_frame()).
 * 
 * In 3.10 GTK and GDK have been restructured for translucent drawing. Since
 * then expose events for double-buffered widgets are culled into a single
 * event to the toplevel GDK window. If you now unset double buffering, you
 * will cause a separate rendering pass for every widget. This will likely
 * cause rendering problems - in particular related to stacking - and usually
 * increases rendering times significantly.
 *
 * @param doubleBuffered %TRUE to double-buffer a widget
 */
- (void)setDoubleBuffered:(bool)doubleBuffered;

/**
 * Sets the event mask (see #GdkEventMask) for a widget. The event
 * mask determines which events a widget will receive. Keep in mind
 * that different widgets have different default event masks, and by
 * changing the event mask you may disrupt a widget’s functionality,
 * so be careful. This function must be called while a widget is
 * unrealized. Consider gtk_widget_add_events() for widgets that are
 * already realized, or if you want to preserve the existing event
 * mask. This function can’t be used with widgets that have no window.
 * (See gtk_widget_get_has_window()).  To get events on those widgets,
 * place them inside a #GtkEventBox and receive events on the event
 * box.
 *
 * @param events event mask
 */
- (void)setEvents:(gint)events;

/**
 * Sets whether the widget should grab focus when it is clicked with the mouse.
 * Making mouse clicks not grab focus is useful in places like toolbars where
 * you don’t want the keyboard focus removed from the main area of the
 * application.
 *
 * @param focusOnClick whether the widget should grab focus when clicked with the mouse
 */
- (void)setFocusOnClick:(bool)focusOnClick;

/**
 * Sets the font map to use for Pango rendering. When not set, the widget
 * will inherit the font map from its parent.
 *
 * @param fontMap a #PangoFontMap, or %NULL to unset any previously
 *     set font map
 */
- (void)setFontMap:(OGPangoFontMap*)fontMap;

/**
 * Sets the #cairo_font_options_t used for Pango rendering in this widget.
 * When not set, the default font options for the #GdkScreen will be used.
 *
 * @param options a #cairo_font_options_t, or %NULL to unset any
 *   previously set default font options.
 */
- (void)setFontOptions:(const cairo_font_options_t*)options;

/**
 * Sets the horizontal alignment of @widget.
 * See the #GtkWidget:halign property.
 *
 * @param align the horizontal alignment
 */
- (void)setHalign:(GtkAlign)align;

/**
 * Sets the has-tooltip property on @widget to @has_tooltip.  See
 * #GtkWidget:has-tooltip for more information.
 *
 * @param hasTooltip whether or not @widget has a tooltip.
 */
- (void)setHasTooltip:(bool)hasTooltip;

/**
 * Specifies whether @widget has a #GdkWindow of its own. Note that
 * all realized widgets have a non-%NULL “window” pointer
 * (gtk_widget_get_window() never returns a %NULL window when a widget
 * is realized), but for many of them it’s actually the #GdkWindow of
 * one of its parent widgets. Widgets that do not create a %window for
 * themselves in #GtkWidget::realize must announce this by
 * calling this function with @has_window = %FALSE.
 * 
 * This function should only be called by widget implementations,
 * and they should call it in their init() function.
 *
 * @param hasWindow whether or not @widget has a window.
 */
- (void)setHasWindow:(bool)hasWindow;

/**
 * Sets whether the widget would like any available extra horizontal
 * space. When a user resizes a #GtkWindow, widgets with expand=TRUE
 * generally receive the extra space. For example, a list or
 * scrollable area or document in your window would often be set to
 * expand.
 * 
 * Call this function to set the expand flag if you would like your
 * widget to become larger horizontally when the window has extra
 * room.
 * 
 * By default, widgets automatically expand if any of their children
 * want to expand. (To see if a widget will automatically expand given
 * its current children and state, call gtk_widget_compute_expand(). A
 * container can decide how the expandability of children affects the
 * expansion of the container by overriding the compute_expand virtual
 * method on #GtkWidget.).
 * 
 * Setting hexpand explicitly with this function will override the
 * automatic expand behavior.
 * 
 * This function forces the widget to expand or not to expand,
 * regardless of children.  The override occurs because
 * gtk_widget_set_hexpand() sets the hexpand-set property (see
 * gtk_widget_set_hexpand_set()) which causes the widget’s hexpand
 * value to be used, rather than looking at children and widget state.
 *
 * @param expand whether to expand
 */
- (void)setHexpand:(bool)expand;

/**
 * Sets whether the hexpand flag (see gtk_widget_get_hexpand()) will
 * be used.
 * 
 * The hexpand-set property will be set automatically when you call
 * gtk_widget_set_hexpand() to set hexpand, so the most likely
 * reason to use this function would be to unset an explicit expand
 * flag.
 * 
 * If hexpand is set, then it overrides any computed
 * expand value based on child widgets. If hexpand is not
 * set, then the expand value depends on whether any
 * children of the widget would like to expand.
 * 
 * There are few reasons to use this function, but it’s here
 * for completeness and consistency.
 *
 * @param set value for hexpand-set property
 */
- (void)setHexpandSet:(bool)set;

/**
 * Marks the widget as being mapped.
 * 
 * This function should only ever be called in a derived widget's
 * “map” or “unmap” implementation.
 *
 * @param mapped %TRUE to mark the widget as mapped
 */
- (void)setMapped:(bool)mapped;

/**
 * Sets the bottom margin of @widget.
 * See the #GtkWidget:margin-bottom property.
 *
 * @param margin the bottom margin
 */
- (void)setMarginBottom:(gint)margin;

/**
 * Sets the end margin of @widget.
 * See the #GtkWidget:margin-end property.
 *
 * @param margin the end margin
 */
- (void)setMarginEnd:(gint)margin;

/**
 * Sets the left margin of @widget.
 * See the #GtkWidget:margin-left property.
 *
 * @param margin the left margin
 */
- (void)setMarginLeft:(gint)margin;

/**
 * Sets the right margin of @widget.
 * See the #GtkWidget:margin-right property.
 *
 * @param margin the right margin
 */
- (void)setMarginRight:(gint)margin;

/**
 * Sets the start margin of @widget.
 * See the #GtkWidget:margin-start property.
 *
 * @param margin the start margin
 */
- (void)setMarginStart:(gint)margin;

/**
 * Sets the top margin of @widget.
 * See the #GtkWidget:margin-top property.
 *
 * @param margin the top margin
 */
- (void)setMarginTop:(gint)margin;

/**
 * Widgets can be named, which allows you to refer to them from a
 * CSS file. You can apply a style to widgets with a particular name
 * in the CSS file. See the documentation for the CSS syntax (on the
 * same page as the docs for #GtkStyleContext).
 * 
 * Note that the CSS syntax has certain special characters to delimit
 * and represent elements in a selector (period, #, >, *...), so using
 * these will make your widget impossible to match by name. Any combination
 * of alphanumeric symbols, dashes and underscores will suffice.
 *
 * @param name name for the widget
 */
- (void)setName:(OFString*)name;

/**
 * Sets the #GtkWidget:no-show-all property, which determines whether
 * calls to gtk_widget_show_all() will affect this widget.
 * 
 * This is mostly for use in constructing widget hierarchies with externally
 * controlled visibility, see #GtkUIManager.
 *
 * @param noShowAll the new value for the “no-show-all” property
 */
- (void)setNoShowAll:(bool)noShowAll;

/**
 * Request the @widget to be rendered partially transparent,
 * with opacity 0 being fully transparent and 1 fully opaque. (Opacity values
 * are clamped to the [0,1] range.).
 * This works on both toplevel widget, and child widgets, although there
 * are some limitations:
 * 
 * For toplevel widgets this depends on the capabilities of the windowing
 * system. On X11 this has any effect only on X screens with a compositing manager
 * running. See gtk_widget_is_composited(). On Windows it should work
 * always, although setting a window’s opacity after the window has been
 * shown causes it to flicker once on Windows.
 * 
 * For child widgets it doesn’t work if any affected widget has a native window, or
 * disables double buffering.
 *
 * @param opacity desired opacity, between 0 and 1
 */
- (void)setOpacity:(double)opacity;

/**
 * This function is useful only when implementing subclasses of
 * #GtkContainer.
 * Sets the container as the parent of @widget, and takes care of
 * some details such as updating the state and style of the child
 * to reflect its new location. The opposite function is
 * gtk_widget_unparent().
 *
 * @param parent parent container
 */
- (void)setParent:(OGTKWidget*)parent;

/**
 * Sets a non default parent window for @widget.
 * 
 * For #GtkWindow classes, setting a @parent_window effects whether
 * the window is a toplevel window or can be embedded into other
 * widgets.
 * 
 * For #GtkWindow classes, this needs to be called before the
 * window is realized.
 *
 * @param parentWindow the new parent window.
 */
- (void)setParentWindow:(OGGdkWindow*)parentWindow;

/**
 * Marks the widget as being realized. This function must only be
 * called after all #GdkWindows for the @widget have been created
 * and registered.
 * 
 * This function should only ever be called in a derived widget's
 * “realize” or “unrealize” implementation.
 *
 * @param realized %TRUE to mark the widget as realized
 */
- (void)setRealized:(bool)realized;

/**
 * Specifies whether @widget will be treated as the default widget
 * within its toplevel when it has the focus, even if another widget
 * is the default.
 * 
 * See gtk_widget_grab_default() for details about the meaning of
 * “default”.
 *
 * @param receivesDefault whether or not @widget can be a default widget.
 */
- (void)setReceivesDefault:(bool)receivesDefault;

/**
 * Sets whether the entire widget is queued for drawing when its size
 * allocation changes. By default, this setting is %TRUE and
 * the entire widget is redrawn on every size change. If your widget
 * leaves the upper left unchanged when made bigger, turning this
 * setting off will improve performance.
 * 
 * Note that for widgets where gtk_widget_get_has_window() is %FALSE
 * setting this flag to %FALSE turns off all allocation on resizing:
 * the widget will not even redraw if its position changes; this is to
 * allow containers that don’t draw anything to avoid excess
 * invalidations. If you set this flag on a widget with no window that
 * does draw on @widget->window, you are
 * responsible for invalidating both the old and new allocation of the
 * widget when the widget is moved and responsible for invalidating
 * regions newly when the widget increases size.
 *
 * @param redrawOnAllocate if %TRUE, the entire widget will be redrawn
 *   when it is allocated to a new size. Otherwise, only the
 *   new portion of the widget will be redrawn.
 */
- (void)setRedrawOnAllocate:(bool)redrawOnAllocate;

/**
 * Sets the sensitivity of a widget. A widget is sensitive if the user
 * can interact with it. Insensitive widgets are “grayed out” and the
 * user can’t interact with them. Insensitive widgets are known as
 * “inactive”, “disabled”, or “ghosted” in some other toolkits.
 *
 * @param sensitive %TRUE to make the widget sensitive
 */
- (void)setSensitive:(bool)sensitive;

/**
 * Sets the minimum size of a widget; that is, the widget’s size
 * request will be at least @width by @height. You can use this
 * function to force a widget to be larger than it normally would be.
 * 
 * In most cases, gtk_window_set_default_size() is a better choice for
 * toplevel windows than this function; setting the default size will
 * still allow users to shrink the window. Setting the size request
 * will force them to leave the window at least as large as the size
 * request. When dealing with window sizes,
 * gtk_window_set_geometry_hints() can be a useful function as well.
 * 
 * Note the inherent danger of setting any fixed size - themes,
 * translations into other languages, different fonts, and user action
 * can all change the appropriate size for a given widget. So, it's
 * basically impossible to hardcode a size that will always be
 * correct.
 * 
 * The size request of a widget is the smallest size a widget can
 * accept while still functioning well and drawing itself correctly.
 * However in some strange cases a widget may be allocated less than
 * its requested size, and in many cases a widget may be allocated more
 * space than it requested.
 * 
 * If the size request in a given direction is -1 (unset), then
 * the “natural” size request of the widget will be used instead.
 * 
 * The size request set here does not include any margin from the
 * #GtkWidget properties margin-left, margin-right, margin-top, and
 * margin-bottom, but it does include pretty much all other padding
 * or border properties set by any subclass of #GtkWidget.
 *
 * @param width width @widget should request, or -1 to unset
 * @param height height @widget should request, or -1 to unset
 */
- (void)setSizeRequestWithWidth:(gint)width height:(gint)height;

/**
 * This function is for use in widget implementations. Sets the state
 * of a widget (insensitive, prelighted, etc.) Usually you should set
 * the state using wrapper functions such as gtk_widget_set_sensitive().
 *
 * @param state new state for @widget
 */
- (void)setState:(GtkStateType)state;

/**
 * This function is for use in widget implementations. Turns on flag
 * values in the current widget state (insensitive, prelighted, etc.).
 * 
 * This function accepts the values %GTK_STATE_FLAG_DIR_LTR and
 * %GTK_STATE_FLAG_DIR_RTL but ignores them. If you want to set the widget's
 * direction, use gtk_widget_set_direction().
 * 
 * It is worth mentioning that any other state than %GTK_STATE_FLAG_INSENSITIVE,
 * will be propagated down to all non-internal children if @widget is a
 * #GtkContainer, while %GTK_STATE_FLAG_INSENSITIVE itself will be propagated
 * down to all #GtkContainer children by different means than turning on the
 * state flag down the hierarchy, both gtk_widget_get_state_flags() and
 * gtk_widget_is_sensitive() will make use of these.
 *
 * @param flags State flags to turn on
 * @param clear Whether to clear state before turning on @flags
 */
- (void)setStateFlagsWithFlags:(GtkStateFlags)flags clear:(bool)clear;

/**
 * Used to set the #GtkStyle for a widget (@widget->style). Since
 * GTK 3, this function does nothing, the passed in style is ignored.
 *
 * @param style a #GtkStyle, or %NULL to remove the effect
 *     of a previous call to gtk_widget_set_style() and go back to
 *     the default style
 */
- (void)setStyle:(OGTKStyle*)style;

/**
 * Enables or disables multiple pointer awareness. If this setting is %TRUE,
 * @widget will start receiving multiple, per device enter/leave events. Note
 * that if custom #GdkWindows are created in #GtkWidget::realize,
 * gdk_window_set_support_multidevice() will have to be called manually on them.
 *
 * @param supportMultidevice %TRUE to support input from multiple devices.
 */
- (void)setSupportMultidevice:(bool)supportMultidevice;

/**
 * Sets @markup as the contents of the tooltip, which is marked up with
 *  the [Pango text markup language][PangoMarkupFormat].
 * 
 * This function will take care of setting #GtkWidget:has-tooltip to %TRUE
 * and of the default handler for the #GtkWidget::query-tooltip signal.
 * 
 * See also the #GtkWidget:tooltip-markup property and
 * gtk_tooltip_set_markup().
 *
 * @param markup the contents of the tooltip for @widget, or %NULL
 */
- (void)setTooltipMarkup:(OFString*)markup;

/**
 * Sets @text as the contents of the tooltip. This function will take
 * care of setting #GtkWidget:has-tooltip to %TRUE and of the default
 * handler for the #GtkWidget::query-tooltip signal.
 * 
 * See also the #GtkWidget:tooltip-text property and gtk_tooltip_set_text().
 *
 * @param text the contents of the tooltip for @widget
 */
- (void)setTooltipText:(OFString*)text;

/**
 * Replaces the default window used for displaying
 * tooltips with @custom_window. GTK+ will take care of showing and
 * hiding @custom_window at the right moment, to behave likewise as
 * the default tooltip window. If @custom_window is %NULL, the default
 * tooltip window will be used.
 *
 * @param customWindow a #GtkWindow, or %NULL
 */
- (void)setTooltipWindow:(OGTKWindow*)customWindow;

/**
 * Sets the vertical alignment of @widget.
 * See the #GtkWidget:valign property.
 *
 * @param align the vertical alignment
 */
- (void)setValign:(GtkAlign)align;

/**
 * Sets whether the widget would like any available extra vertical
 * space.
 * 
 * See gtk_widget_set_hexpand() for more detail.
 *
 * @param expand whether to expand
 */
- (void)setVexpand:(bool)expand;

/**
 * Sets whether the vexpand flag (see gtk_widget_get_vexpand()) will
 * be used.
 * 
 * See gtk_widget_set_hexpand_set() for more detail.
 *
 * @param set value for vexpand-set property
 */
- (void)setVexpandSet:(bool)set;

/**
 * Sets the visibility state of @widget. Note that setting this to
 * %TRUE doesn’t mean the widget is actually viewable, see
 * gtk_widget_get_visible().
 * 
 * This function simply calls gtk_widget_show() or gtk_widget_hide()
 * but is nicer to use when the visibility of the widget depends on
 * some condition.
 *
 * @param visible whether the widget should be shown or not
 */
- (void)setVisible:(bool)visible;

/**
 * Sets the visual that should be used for by widget and its children for
 * creating #GdkWindows. The visual must be on the same #GdkScreen as
 * returned by gtk_widget_get_screen(), so handling the
 * #GtkWidget::screen-changed signal is necessary.
 * 
 * Setting a new @visual will not cause @widget to recreate its windows,
 * so you should call this function before @widget is realized.
 *
 * @param visual visual to be used or %NULL to unset a previous one
 */
- (void)setVisual:(OGGdkVisual*)visual;

/**
 * Sets a widget’s window. This function should only be used in a
 * widget’s #GtkWidget::realize implementation. The %window passed is
 * usually either new window created with gdk_window_new(), or the
 * window of its parent widget as returned by
 * gtk_widget_get_parent_window().
 * 
 * Widgets must indicate whether they will create their own #GdkWindow
 * by calling gtk_widget_set_has_window(). This is usually done in the
 * widget’s init() function.
 * 
 * Note that this function does not add any reference to @window.
 *
 * @param window a #GdkWindow
 */
- (void)setWindow:(OGGdkWindow*)window;

/**
 * Sets a shape for this widget’s GDK window. This allows for
 * transparent windows etc., see gdk_window_shape_combine_region()
 * for more information.
 *
 * @param region shape to be added, or %NULL to remove an existing shape
 */
- (void)shapeCombineRegion:(cairo_region_t*)region;

/**
 * Flags a widget to be displayed. Any widget that isn’t shown will
 * not appear on the screen. If you want to show all the widgets in a
 * container, it’s easier to call gtk_widget_show_all() on the
 * container, instead of individually showing the widgets.
 * 
 * Remember that you have to show the containers containing a widget,
 * in addition to the widget itself, before it will appear onscreen.
 * 
 * When a toplevel container is shown, it is immediately realized and
 * mapped; other shown widgets are realized and mapped when their
 * toplevel container is realized and mapped.
 *
 */
- (void)show;

/**
 * Recursively shows a widget, and any child widgets (if the widget is
 * a container).
 *
 */
- (void)showAll;

/**
 * Shows a widget. If the widget is an unmapped toplevel widget
 * (i.e. a #GtkWindow that has not yet been shown), enter the main
 * loop and wait for the window to actually be mapped. Be careful;
 * because the main loop is running, anything can happen during
 * this function.
 *
 */
- (void)showNow;

/**
 * This function is only used by #GtkContainer subclasses, to assign a size
 * and position to their child widgets.
 * 
 * In this function, the allocation may be adjusted. It will be forced
 * to a 1x1 minimum size, and the adjust_size_allocation virtual
 * method on the child will be used to adjust the allocation. Standard
 * adjustments include removing the widget’s margins, and applying the
 * widget’s #GtkWidget:halign and #GtkWidget:valign properties.
 * 
 * For baseline support in containers you need to use gtk_widget_size_allocate_with_baseline()
 * instead.
 *
 * @param allocation position and size to be allocated to @widget
 */
- (void)sizeAllocate:(GtkAllocation*)allocation;

/**
 * This function is only used by #GtkContainer subclasses, to assign a size,
 * position and (optionally) baseline to their child widgets.
 * 
 * In this function, the allocation and baseline may be adjusted. It
 * will be forced to a 1x1 minimum size, and the
 * adjust_size_allocation virtual and adjust_baseline_allocation
 * methods on the child will be used to adjust the allocation and
 * baseline. Standard adjustments include removing the widget's
 * margins, and applying the widget’s #GtkWidget:halign and
 * #GtkWidget:valign properties.
 * 
 * If the child widget does not have a valign of %GTK_ALIGN_BASELINE the
 * baseline argument is ignored and -1 is used instead.
 *
 * @param allocation position and size to be allocated to @widget
 * @param baseline The baseline of the child, or -1
 */
- (void)sizeAllocateWithBaselineWithAllocation:(GtkAllocation*)allocation baseline:(gint)baseline;

/**
 * This function is typically used when implementing a #GtkContainer
 * subclass.  Obtains the preferred size of a widget. The container
 * uses this information to arrange its child widgets and decide what
 * size allocations to give them with gtk_widget_size_allocate().
 * 
 * You can also call this function from an application, with some
 * caveats. Most notably, getting a size request requires the widget
 * to be associated with a screen, because font information may be
 * needed. Multihead-aware applications should keep this in mind.
 * 
 * Also remember that the size request is not necessarily the size
 * a widget will actually be allocated.
 *
 * @param requisition a #GtkRequisition to be filled in
 */
- (void)sizeRequest:(GtkRequisition*)requisition;

/**
 * This function attaches the widget’s #GtkStyle to the widget's
 * #GdkWindow. It is a replacement for
 * 
 * |[
 * widget->style = gtk_style_attach (widget->style, widget->window);
 * ]|
 * 
 * and should only ever be called in a derived widget’s “realize”
 * implementation which does not chain up to its parent class'
 * “realize” implementation, because one of the parent classes
 * (finally #GtkWidget) would attach the style itself.
 *
 */
- (void)styleAttach;

/**
 * Gets the value of a style property of @widget.
 *
 * @param propertyName the name of a style property
 * @param value location to return the property value
 */
- (void)styleGetPropertyWithPropertyName:(OFString*)propertyName value:(GValue*)value;

/**
 * Non-vararg variant of gtk_widget_style_get(). Used primarily by language
 * bindings.
 *
 * @param firstPropertyName the name of the first property to get
 * @param varArgs a va_list of pairs of property names and
 *     locations to return the property values, starting with the location
 *     for @first_property_name.
 */
- (void)styleGetValistWithFirstPropertyName:(OFString*)firstPropertyName varArgs:(va_list)varArgs;

/**
 * Reverts the effect of a previous call to gtk_widget_freeze_child_notify().
 * This causes all queued #GtkWidget::child-notify signals on @widget to be
 * emitted.
 *
 */
- (void)thawChildNotify;

/**
 * Translate coordinates relative to @src_widget’s allocation to coordinates
 * relative to @dest_widget’s allocations. In order to perform this
 * operation, both widgets must be realized, and must share a common
 * toplevel.
 *
 * @param destWidget a #GtkWidget
 * @param srcX X position relative to @src_widget
 * @param srcY Y position relative to @src_widget
 * @param destX location to store X position relative to @dest_widget
 * @param destY location to store Y position relative to @dest_widget
 * @return %FALSE if either widget was not realized, or there
 *   was no common ancestor. In this case, nothing is stored in
 *   *@dest_x and *@dest_y. Otherwise %TRUE.
 */
- (bool)translateCoordinatesWithDestWidget:(OGTKWidget*)destWidget srcX:(gint)srcX srcY:(gint)srcY destX:(gint*)destX destY:(gint*)destY;

/**
 * Triggers a tooltip query on the display where the toplevel of @widget
 * is located. See gtk_tooltip_trigger_tooltip_query() for more
 * information.
 *
 */
- (void)triggerTooltipQuery;

/**
 * This function is only for use in widget implementations. Causes
 * a widget to be unmapped if it’s currently mapped.
 *
 */
- (void)unmap;

/**
 * This function is only for use in widget implementations.
 * Should be called by implementations of the remove method
 * on #GtkContainer, to dissociate a child from the container.
 *
 */
- (void)unparent;

/**
 * This function is only useful in widget implementations.
 * Causes a widget to be unrealized (frees all GDK resources
 * associated with the widget, such as @widget->window).
 *
 */
- (void)unrealize;

/**
 * Unregisters a #GdkWindow from the widget that was previously set up with
 * gtk_widget_register_window(). You need to call this when the window is
 * no longer used by the widget, such as when you destroy it.
 *
 * @param window a #GdkWindow
 */
- (void)unregisterWindow:(OGGdkWindow*)window;

/**
 * This function is for use in widget implementations. Turns off flag
 * values for the current widget state (insensitive, prelighted, etc.).
 * See gtk_widget_set_state_flags().
 *
 * @param flags State flags to turn off
 */
- (void)unsetStateFlags:(GtkStateFlags)flags;

@end