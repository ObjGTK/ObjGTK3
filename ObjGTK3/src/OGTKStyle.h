/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

@class OGGdkWindow;
@class OGTKWidget;
@class OGGdkPixbuf;

/**
 * A #GtkStyle object encapsulates the information that provides the look and
 * feel for a widget.
 * 
 * > In GTK+ 3.0, GtkStyle has been deprecated and replaced by
 * > #GtkStyleContext.
 * 
 * Each #GtkWidget has an associated #GtkStyle object that is used when
 * rendering that widget. Also, a #GtkStyle holds information for the five
 * possible widget states though not every widget supports all five
 * states; see #GtkStateType.
 * 
 * Usually the #GtkStyle for a widget is the same as the default style that
 * is set by GTK+ and modified the theme engine.
 * 
 * Usually applications should not need to use or modify the #GtkStyle of
 * their widgets.
 *
 */
@interface OGTKStyle : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkStyle*)STYLE;

/**
 *
 * @param cr
 * @param window
 * @param stateType
 * @param x
 * @param y
 * @param width
 * @param height
 */
- (void)applyDefaultBackgroundWithCr:(cairo_t*)cr window:(OGGdkWindow*)window stateType:(GtkStateType)stateType x:(gint)x y:(gint)y width:(gint)width height:(gint)height;

/**
 * Attaches a style to a window; this process allocates the
 * colors and creates the GC’s for the style - it specializes
 * it to a particular visual. The process may involve the creation
 * of a new style if the style has already been attached to a
 * window with a different style and visual.
 * 
 * Since this function may return a new object, you have to use it
 * in the following way:
 * `style = gtk_style_attach (style, window)`
 *
 * @param window a #GdkWindow.
 * @return Either @style, or a newly-created #GtkStyle.
 *   If the style is newly created, the style parameter
 *   will be unref'ed, and the new style will have
 *   a reference count belonging to the caller.
 */
- (OGTKStyle*)attach:(OGGdkWindow*)window;

/**
 * Creates a copy of the passed in #GtkStyle object.
 *
 * @return a copy of @style
 */
- (OGTKStyle*)copy;

/**
 * Detaches a style from a window. If the style is not attached
 * to any windows anymore, it is unrealized. See gtk_style_attach().
 *
 */
- (void)detach;

/**
 * Queries the value of a style property corresponding to a
 * widget class is in the given style.
 *
 * @param widgetType the #GType of a descendant of #GtkWidget
 * @param propertyName the name of the style property to get
 * @param value a #GValue where the value of the property being
 *     queried will be stored
 */
- (void)stylePropertyWithWidgetType:(GType)widgetType propertyName:(OFString*)propertyName value:(GValue*)value;

/**
 * Non-vararg variant of gtk_style_get().
 * Used primarily by language bindings.
 *
 * @param widgetType the #GType of a descendant of #GtkWidget
 * @param firstPropertyName the name of the first style property to get
 * @param varArgs a va_list of pairs of property names and
 *     locations to return the property values, starting with the
 *     location for @first_property_name.
 */
- (void)valistWithWidgetType:(GType)widgetType firstPropertyName:(OFString*)firstPropertyName varArgs:(va_list)varArgs;

/**
 * Returns whether @style has an associated #GtkStyleContext.
 *
 * @return %TRUE if @style has a #GtkStyleContext
 */
- (bool)hasContext;

/**
 * Looks up @color_name in the style’s logical color mappings,
 * filling in @color and returning %TRUE if found, otherwise
 * returning %FALSE. Do not cache the found mapping, because
 * it depends on the #GtkStyle and might change when a theme
 * switch occurs.
 *
 * @param colorName the name of the logical color to look up
 * @param color the #GdkColor to fill in
 * @return %TRUE if the mapping was found.
 */
- (bool)lookupColorWithColorName:(OFString*)colorName color:(GdkColor*)color;

/**
 * Looks up @stock_id in the icon factories associated with @style
 * and the default icon factory, returning an icon set if found,
 * otherwise %NULL.
 *
 * @param stockId an icon name
 * @return icon set of @stock_id
 */
- (GtkIconSet*)lookupIconSet:(OFString*)stockId;

/**
 * Renders the icon specified by @source at the given @size
 * according to the given parameters and returns the result in a
 * pixbuf.
 *
 * @param source the #GtkIconSource specifying the icon to render
 * @param direction a text direction
 * @param state a state
 * @param size the size to render the icon at (#GtkIconSize). A size of
 *     `(GtkIconSize)-1` means render at the size of the source and
 *     don’t scale.
 * @param widget the widget
 * @param detail a style detail
 * @return a newly-created #GdkPixbuf
 *     containing the rendered icon
 */
- (OGGdkPixbuf*)renderIconWithSource:(const GtkIconSource*)source direction:(GtkTextDirection)direction state:(GtkStateType)state size:(GtkIconSize)size widget:(OGTKWidget*)widget detail:(OFString*)detail;

/**
 * Sets the background of @window to the background color or pixmap
 * specified by @style for the given state.
 *
 * @param window a #GdkWindow
 * @param stateType a state
 */
- (void)setBackgroundWithWindow:(OGGdkWindow*)window stateType:(GtkStateType)stateType;

@end