/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>
#include <gtk/gtk.h>

#import <OGObject/OGObject.h>

@class OGGdkScreen;
@class OGGdkWindow;
@class OGGdkFrameClock;

/**
 * #GtkStyleContext is an object that stores styling information affecting
 * a widget defined by #GtkWidgetPath.
 * 
 * In order to construct the final style information, #GtkStyleContext
 * queries information from all attached #GtkStyleProviders. Style providers
 * can be either attached explicitly to the context through
 * gtk_style_context_add_provider(), or to the screen through
 * gtk_style_context_add_provider_for_screen(). The resulting style is a
 * combination of all providers’ information in priority order.
 * 
 * For GTK+ widgets, any #GtkStyleContext returned by
 * gtk_widget_get_style_context() will already have a #GtkWidgetPath, a
 * #GdkScreen and RTL/LTR information set. The style context will also be
 * updated automatically if any of these settings change on the widget.
 * 
 * If you are using the theming layer standalone, you will need to set a
 * widget path and a screen yourself to the created style context through
 * gtk_style_context_set_path() and possibly gtk_style_context_set_screen(). See
 * the “Foreign drawing“ example in gtk3-demo.
 * 
 * # Style Classes # {#gtkstylecontext-classes}
 * 
 * Widgets can add style classes to their context, which can be used to associate
 * different styles by class. The documentation for individual widgets lists
 * which style classes it uses itself, and which style classes may be added by
 * applications to affect their appearance.
 * 
 * GTK+ defines macros for a number of style classes.
 * 
 * # Style Regions
 * 
 * Widgets can also add regions with flags to their context. This feature is
 * deprecated and will be removed in a future GTK+ update. Please use style
 * classes instead.
 * 
 * GTK+ defines macros for a number of style regions.
 * 
 * # Custom styling in UI libraries and applications
 * 
 * If you are developing a library with custom #GtkWidgets that
 * render differently than standard components, you may need to add a
 * #GtkStyleProvider yourself with the %GTK_STYLE_PROVIDER_PRIORITY_FALLBACK
 * priority, either a #GtkCssProvider or a custom object implementing the
 * #GtkStyleProvider interface. This way themes may still attempt
 * to style your UI elements in a different way if needed so.
 * 
 * If you are using custom styling on an applications, you probably want then
 * to make your style information prevail to the theme’s, so you must use
 * a #GtkStyleProvider with the %GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
 * priority, keep in mind that the user settings in
 * `XDG_CONFIG_HOME/gtk-3.0/gtk.css` will
 * still take precedence over your changes, as it uses the
 * %GTK_STYLE_PROVIDER_PRIORITY_USER priority.
 *
 */
@interface OGTKStyleContext : OGObject
{

}

/**
 * Functions
 */

/**
 * Adds a global style provider to @screen, which will be used
 * in style construction for all #GtkStyleContexts under @screen.
 * 
 * GTK+ uses this to make styling information from #GtkSettings
 * available.
 * 
 * Note: If both priorities are the same, A #GtkStyleProvider
 * added through gtk_style_context_add_provider() takes precedence
 * over another added through this function.
 *
 * @param screen a #GdkScreen
 * @param provider a #GtkStyleProvider
 * @param priority the priority of the style provider. The lower
 *            it is, the earlier it will be used in the style
 *            construction. Typically this will be in the range
 *            between %GTK_STYLE_PROVIDER_PRIORITY_FALLBACK and
 *            %GTK_STYLE_PROVIDER_PRIORITY_USER
 */
+ (void)addProviderForScreenWithScreen:(OGGdkScreen*)screen provider:(GtkStyleProvider*)provider priority:(guint)priority;

/**
 * Removes @provider from the global style providers list in @screen.
 *
 * @param screen a #GdkScreen
 * @param provider a #GtkStyleProvider
 */
+ (void)removeProviderForScreenWithScreen:(OGGdkScreen*)screen provider:(GtkStyleProvider*)provider;

/**
 * This function recomputes the styles for all widgets under a particular
 * #GdkScreen. This is useful when some global parameter has changed that
 * affects the appearance of all widgets, because when a widget gets a new
 * style, it will both redraw and recompute any cached information about
 * its appearance. As an example, it is used when the color scheme changes
 * in the related #GtkSettings object.
 *
 * @param screen a #GdkScreen
 */
+ (void)resetWidgets:(OGGdkScreen*)screen;

/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkStyleContext*)STYLECONTEXT;

/**
 * Adds a style class to @context, so posterior calls to
 * gtk_style_context_get() or any of the gtk_render_*()
 * functions will make use of this new class for styling.
 * 
 * In the CSS file format, a #GtkEntry defining a “search”
 * class, would be matched by:
 * 
 * |[ <!-- language="CSS" -->
 * entry.search { ... }
 * ]|
 * 
 * While any widget defining a “search” class would be
 * matched by:
 * |[ <!-- language="CSS" -->
 * .search { ... }
 * ]|
 *
 * @param className class name to use in styling
 */
- (void)addClass:(OFString*)className;

/**
 * Adds a style provider to @context, to be used in style construction.
 * Note that a style provider added by this function only affects
 * the style of the widget to which @context belongs. If you want
 * to affect the style of all widgets, use
 * gtk_style_context_add_provider_for_screen().
 * 
 * Note: If both priorities are the same, a #GtkStyleProvider
 * added through this function takes precedence over another added
 * through gtk_style_context_add_provider_for_screen().
 *
 * @param provider a #GtkStyleProvider
 * @param priority the priority of the style provider. The lower
 *            it is, the earlier it will be used in the style
 *            construction. Typically this will be in the range
 *            between %GTK_STYLE_PROVIDER_PRIORITY_FALLBACK and
 *            %GTK_STYLE_PROVIDER_PRIORITY_USER
 */
- (void)addProviderWithProvider:(GtkStyleProvider*)provider priority:(guint)priority;

/**
 * Adds a region to @context, so posterior calls to
 * gtk_style_context_get() or any of the gtk_render_*()
 * functions will make use of this new region for styling.
 * 
 * In the CSS file format, a #GtkTreeView defining a “row”
 * region, would be matched by:
 * 
 * |[ <!-- language="CSS" -->
 * treeview row { ... }
 * ]|
 * 
 * Pseudo-classes are used for matching @flags, so the two
 * following rules:
 * |[ <!-- language="CSS" -->
 * treeview row:nth-child(even) { ... }
 * treeview row:nth-child(odd) { ... }
 * ]|
 * 
 * would apply to even and odd rows, respectively.
 * 
 * Region names must only contain lowercase letters
 * and “-”, starting always with a lowercase letter.
 *
 * @param regionName region name to use in styling
 * @param flags flags that apply to the region
 */
- (void)addRegionWithRegionName:(OFString*)regionName flags:(GtkRegionFlags)flags;

/**
 * Stops all running animations for @region_id and all animatable
 * regions underneath.
 * 
 * A %NULL @region_id will stop all ongoing animations in @context,
 * when dealing with a #GtkStyleContext obtained through
 * gtk_widget_get_style_context(), this is normally done for you
 * in all circumstances you would expect all widget to be stopped,
 * so this should be only used in complex widgets with different
 * animatable regions.
 *
 * @param regionId animatable region to stop, or %NULL.
 *     See gtk_style_context_push_animatable_region()
 */
- (void)cancelAnimations:(gpointer)regionId;

/**
 * Gets the background color for a given state.
 * 
 * This function is far less useful than it seems, and it should not be used in
 * newly written code. CSS has no concept of "background color", as a background
 * can be an image, or a gradient, or any other pattern including solid colors.
 * 
 * The only reason why you would call gtk_style_context_get_background_color() is
 * to use the returned value to draw the background with it; the correct way to
 * achieve this result is to use gtk_render_background() instead, along with CSS
 * style classes to modify the color to be rendered.
 *
 * @param state state to retrieve the color for
 * @param color return value for the background color
 */
- (void)backgroundColorWithState:(GtkStateFlags)state color:(GdkRGBA*)color;

/**
 * Gets the border for a given state as a #GtkBorder.
 * 
 * See gtk_style_context_get_property() and
 * #GTK_STYLE_PROPERTY_BORDER_WIDTH for details.
 *
 * @param state state to retrieve the border for
 * @param border return value for the border settings
 */
- (void)borderWithState:(GtkStateFlags)state border:(GtkBorder*)border;

/**
 * Gets the border color for a given state.
 *
 * @param state state to retrieve the color for
 * @param color return value for the border color
 */
- (void)borderColorWithState:(GtkStateFlags)state color:(GdkRGBA*)color;

/**
 * Gets the foreground color for a given state.
 * 
 * See gtk_style_context_get_property() and
 * #GTK_STYLE_PROPERTY_COLOR for details.
 *
 * @param state state to retrieve the color for
 * @param color return value for the foreground color
 */
- (void)colorWithState:(GtkStateFlags)state color:(GdkRGBA*)color;

/**
 * Returns the widget direction used for rendering.
 *
 * @return the widget direction
 */
- (GtkTextDirection)direction;

/**
 * Returns the font description for a given state. The returned
 * object is const and will remain valid until the
 * #GtkStyleContext::changed signal happens.
 *
 * @param state state to retrieve the font for
 * @return the #PangoFontDescription for the given
 *          state.  This object is owned by GTK+ and should not be
 *          freed.
 */
- (const PangoFontDescription*)font:(GtkStateFlags)state;

/**
 * Returns the #GdkFrameClock to which @context is attached.
 *
 * @return a #GdkFrameClock, or %NULL
 *  if @context does not have an attached frame clock.
 */
- (OGGdkFrameClock*)frameClock;

/**
 * Returns the sides where rendered elements connect visually with others.
 *
 * @return the junction sides
 */
- (GtkJunctionSides)junctionSides;

/**
 * Gets the margin for a given state as a #GtkBorder.
 * See gtk_style_property_get() and #GTK_STYLE_PROPERTY_MARGIN
 * for details.
 *
 * @param state state to retrieve the border for
 * @param margin return value for the margin settings
 */
- (void)marginWithState:(GtkStateFlags)state margin:(GtkBorder*)margin;

/**
 * Gets the padding for a given state as a #GtkBorder.
 * See gtk_style_context_get() and #GTK_STYLE_PROPERTY_PADDING
 * for details.
 *
 * @param state state to retrieve the padding for
 * @param padding return value for the padding settings
 */
- (void)paddingWithState:(GtkStateFlags)state padding:(GtkBorder*)padding;

/**
 * Gets the parent context set via gtk_style_context_set_parent().
 * See that function for details.
 *
 * @return the parent context or %NULL
 */
- (OGTKStyleContext*)parent;

/**
 * Returns the widget path used for style matching.
 *
 * @return A #GtkWidgetPath
 */
- (const GtkWidgetPath*)path;

/**
 * Gets a style property from @context for the given state.
 * 
 * Note that not all CSS properties that are supported by GTK+ can be
 * retrieved in this way, since they may not be representable as #GValue.
 * GTK+ defines macros for a number of properties that can be used
 * with this function.
 * 
 * Note that passing a state other than the current state of @context
 * is not recommended unless the style context has been saved with
 * gtk_style_context_save().
 * 
 * When @value is no longer needed, g_value_unset() must be called
 * to free any allocated memory.
 *
 * @param property style property name
 * @param state state to retrieve the property value for
 * @param value return location for the style property value
 */
- (void)propertyWithProperty:(OFString*)property state:(GtkStateFlags)state value:(GValue*)value;

/**
 * Returns the scale used for assets.
 *
 * @return the scale
 */
- (gint)scale;

/**
 * Returns the #GdkScreen to which @context is attached.
 *
 * @return a #GdkScreen.
 */
- (OGGdkScreen*)screen;

/**
 * Queries the location in the CSS where @property was defined for the
 * current @context. Note that the state to be queried is taken from
 * gtk_style_context_get_state().
 * 
 * If the location is not available, %NULL will be returned. The
 * location might not be available for various reasons, such as the
 * property being overridden, @property not naming a supported CSS
 * property or tracking of definitions being disabled for performance
 * reasons.
 * 
 * Shorthand CSS properties cannot be queried for a location and will
 * always return %NULL.
 *
 * @param property style property name
 * @return %NULL or the section where a value
 * for @property was defined
 */
- (GtkCssSection*)section:(OFString*)property;

/**
 * Returns the state used for style matching.
 * 
 * This method should only be used to retrieve the #GtkStateFlags
 * to pass to #GtkStyleContext methods, like gtk_style_context_get_padding().
 * If you need to retrieve the current state of a #GtkWidget, use
 * gtk_widget_get_state_flags().
 *
 * @return the state flags
 */
- (GtkStateFlags)state;

/**
 * Gets the value for a widget style property.
 * 
 * When @value is no longer needed, g_value_unset() must be called
 * to free any allocated memory.
 *
 * @param propertyName the name of the widget style property
 * @param value Return location for the property value
 */
- (void)stylePropertyWithPropertyName:(OFString*)propertyName value:(GValue*)value;

/**
 * Retrieves several widget style properties from @context according to the
 * current style.
 *
 * @param args va_list of property name/return location pairs, followed by %NULL
 */
- (void)styleValist:(va_list)args;

/**
 * Retrieves several style property values from @context for a given state.
 * 
 * See gtk_style_context_get_property() for details.
 *
 * @param state state to retrieve the property values for
 * @param args va_list of property name/return location pairs, followed by %NULL
 */
- (void)valistWithState:(GtkStateFlags)state args:(va_list)args;

/**
 * Returns %TRUE if @context currently has defined the
 * given class name.
 *
 * @param className a class name
 * @return %TRUE if @context has @class_name defined
 */
- (bool)hasClass:(OFString*)className;

/**
 * Returns %TRUE if @context has the region defined.
 * If @flags_return is not %NULL, it is set to the flags
 * affecting the region.
 *
 * @param regionName a region name
 * @param flagsReturn return location for region flags
 * @return %TRUE if region is defined
 */
- (bool)hasRegionWithRegionName:(OFString*)regionName flagsReturn:(GtkRegionFlags*)flagsReturn;

/**
 * Invalidates @context style information, so it will be reconstructed
 * again. It is useful if you modify the @context and need the new
 * information immediately.
 *
 */
- (void)invalidate;

/**
 * Returns the list of classes currently defined in @context.
 *
 * @return a #GList of
 *          strings with the currently defined classes. The contents
 *          of the list are owned by GTK+, but you must free the list
 *          itself with g_list_free() when you are done with it.
 */
- (GList*)listClasses;

/**
 * Returns the list of regions currently defined in @context.
 *
 * @return a #GList of
 *          strings with the currently defined regions. The contents
 *          of the list are owned by GTK+, but you must free the list
 *          itself with g_list_free() when you are done with it.
 */
- (GList*)listRegions;

/**
 * Looks up and resolves a color name in the @context color map.
 *
 * @param colorName color name to lookup
 * @param color Return location for the looked up color
 * @return %TRUE if @color_name was found and resolved, %FALSE otherwise
 */
- (bool)lookupColorWithColorName:(OFString*)colorName color:(GdkRGBA*)color;

/**
 * Looks up @stock_id in the icon factories associated to @context and
 * the default icon factory, returning an icon set if found, otherwise
 * %NULL.
 *
 * @param stockId an icon name
 * @return The looked up %GtkIconSet, or %NULL
 */
- (GtkIconSet*)lookupIconSet:(OFString*)stockId;

/**
 * Notifies a state change on @context, so if the current style makes use
 * of transition animations, one will be started so all rendered elements
 * under @region_id are animated for state @state being set to value
 * @state_value.
 * 
 * The @window parameter is used in order to invalidate the rendered area
 * as the animation runs, so make sure it is the same window that is being
 * rendered on by the gtk_render_*() functions.
 * 
 * If @region_id is %NULL, all rendered elements using @context will be
 * affected by this state transition.
 * 
 * As a practical example, a #GtkButton notifying a state transition on
 * the prelight state:
 * |[ <!-- language="C" -->
 * gtk_style_context_notify_state_change (context,
 *                                        gtk_widget_get_window (widget),
 *                                        NULL,
 *                                        GTK_STATE_PRELIGHT,
 *                                        button->in_button);
 * ]|
 * 
 * Can be handled in the CSS file like this:
 * |[ <!-- language="CSS" -->
 * button {
 *     background-color: #f00
 * }
 * 
 * button:hover {
 *     background-color: #fff;
 *     transition: 200ms linear
 * }
 * ]|
 * 
 * This combination will animate the button background from red to white
 * if a pointer enters the button, and back to red if the pointer leaves
 * the button.
 * 
 * Note that @state is used when finding the transition parameters, which
 * is why the style places the transition under the :hover pseudo-class.
 *
 * @param window a #GdkWindow
 * @param regionId animatable region to notify on, or %NULL.
 *     See gtk_style_context_push_animatable_region()
 * @param state state to trigger transition for
 * @param stateValue %TRUE if @state is the state we are changing to,
 *     %FALSE if we are changing away from it
 */
- (void)notifyStateChangeWithWindow:(OGGdkWindow*)window regionId:(gpointer)regionId state:(GtkStateType)state stateValue:(bool)stateValue;

/**
 * Pops an animatable region from @context.
 * See gtk_style_context_push_animatable_region().
 *
 */
- (void)popAnimatableRegion;

/**
 * Pushes an animatable region, so all further gtk_render_*() calls between
 * this call and the following gtk_style_context_pop_animatable_region()
 * will potentially show transition animations for this region if
 * gtk_style_context_notify_state_change() is called for a given state,
 * and the current theme/style defines transition animations for state
 * changes.
 * 
 * The @region_id used must be unique in @context so the themes
 * can uniquely identify rendered elements subject to a state transition.
 *
 * @param regionId unique identifier for the animatable region
 */
- (void)pushAnimatableRegion:(gpointer)regionId;

/**
 * Removes @class_name from @context.
 *
 * @param className class name to remove
 */
- (void)removeClass:(OFString*)className;

/**
 * Removes @provider from the style providers list in @context.
 *
 * @param provider a #GtkStyleProvider
 */
- (void)removeProvider:(GtkStyleProvider*)provider;

/**
 * Removes a region from @context.
 *
 * @param regionName region name to unset
 */
- (void)removeRegion:(OFString*)regionName;

/**
 * Restores @context state to a previous stage.
 * See gtk_style_context_save().
 *
 */
- (void)restore;

/**
 * Saves the @context state, so temporary modifications done through
 * gtk_style_context_add_class(), gtk_style_context_remove_class(),
 * gtk_style_context_set_state(), etc. can quickly be reverted
 * in one go through gtk_style_context_restore().
 * 
 * The matching call to gtk_style_context_restore() must be done
 * before GTK returns to the main loop.
 *
 */
- (void)save;

/**
 * This function is analogous to gdk_window_scroll(), and
 * should be called together with it so the invalidation
 * areas for any ongoing animation are scrolled together
 * with it.
 *
 * @param window a #GdkWindow used previously in
 *          gtk_style_context_notify_state_change()
 * @param dx Amount to scroll in the X axis
 * @param dy Amount to scroll in the Y axis
 */
- (void)scrollAnimationsWithWindow:(OGGdkWindow*)window dx:(gint)dx dy:(gint)dy;

/**
 * Sets the background of @window to the background pattern or
 * color specified in @context for its current state.
 *
 * @param window a #GdkWindow
 */
- (void)setBackground:(OGGdkWindow*)window;

/**
 * Sets the reading direction for rendering purposes.
 * 
 * If you are using a #GtkStyleContext returned from
 * gtk_widget_get_style_context(), you do not need to
 * call this yourself.
 *
 * @param direction the new direction.
 */
- (void)setDirection:(GtkTextDirection)direction;

/**
 * Attaches @context to the given frame clock.
 * 
 * The frame clock is used for the timing of animations.
 * 
 * If you are using a #GtkStyleContext returned from
 * gtk_widget_get_style_context(), you do not need to
 * call this yourself.
 *
 * @param frameClock a #GdkFrameClock
 */
- (void)setFrameClock:(OGGdkFrameClock*)frameClock;

/**
 * Sets the sides where rendered elements (mostly through
 * gtk_render_frame()) will visually connect with other visual elements.
 * 
 * This is merely a hint that may or may not be honored
 * by themes.
 * 
 * Container widgets are expected to set junction hints as appropriate
 * for their children, so it should not normally be necessary to call
 * this function manually.
 *
 * @param sides sides where rendered elements are visually connected to
 *     other elements
 */
- (void)setJunctionSides:(GtkJunctionSides)sides;

/**
 * Sets the parent style context for @context. The parent style
 * context is used to implement
 * [inheritance](http://www.w3.org/TR/css3-cascade/#inheritance)
 * of properties.
 * 
 * If you are using a #GtkStyleContext returned from
 * gtk_widget_get_style_context(), the parent will be set for you.
 *
 * @param parent the new parent or %NULL
 */
- (void)setParent:(OGTKStyleContext*)parent;

/**
 * Sets the #GtkWidgetPath used for style matching. As a
 * consequence, the style will be regenerated to match
 * the new given path.
 * 
 * If you are using a #GtkStyleContext returned from
 * gtk_widget_get_style_context(), you do not need to call
 * this yourself.
 *
 * @param path a #GtkWidgetPath
 */
- (void)setPath:(GtkWidgetPath*)path;

/**
 * Sets the scale to use when getting image assets for the style.
 *
 * @param scale scale
 */
- (void)setScale:(gint)scale;

/**
 * Attaches @context to the given screen.
 * 
 * The screen is used to add style information from “global” style
 * providers, such as the screen’s #GtkSettings instance.
 * 
 * If you are using a #GtkStyleContext returned from
 * gtk_widget_get_style_context(), you do not need to
 * call this yourself.
 *
 * @param screen a #GdkScreen
 */
- (void)setScreen:(OGGdkScreen*)screen;

/**
 * Sets the state to be used for style matching.
 *
 * @param flags state to represent
 */
- (void)setState:(GtkStateFlags)flags;

/**
 * Returns %TRUE if there is a transition animation running for the
 * current region (see gtk_style_context_push_animatable_region()).
 * 
 * If @progress is not %NULL, the animation progress will be returned
 * there, 0.0 means the state is closest to being unset, while 1.0 means
 * it’s closest to being set. This means transition animation will
 * run from 0 to 1 when @state is being set and from 1 to 0 when
 * it’s being unset.
 *
 * @param state a widget state
 * @param progress return location for the transition progress
 * @return %TRUE if there is a running transition animation for @state.
 */
- (bool)stateIsRunningWithState:(GtkStateType)state progress:(gdouble*)progress;

/**
 * Converts the style context into a string representation.
 * 
 * The string representation always includes information about
 * the name, state, id, visibility and style classes of the CSS
 * node that is backing @context. Depending on the flags, more
 * information may be included.
 * 
 * This function is intended for testing and debugging of the
 * CSS implementation in GTK+. There are no guarantees about
 * the format of the returned string, it may change.
 *
 * @param flags Flags that determine what to print
 * @return a newly allocated string representing @context
 */
- (char*)toString:(GtkStyleContextPrintFlags)flags;

@end