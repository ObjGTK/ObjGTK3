/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

@class OGGdkScreen;

/**
 * #GtkThemingEngine was the object used for rendering themed content
 * in GTK+ widgets. It used to allow overriding GTK+'s default
 * implementation of rendering functions by allowing engines to be
 * loaded as modules.
 * 
 * #GtkThemingEngine has been deprecated in GTK+ 3.14 and will be
 * ignored for rendering. The advancements in CSS theming are good
 * enough to allow themers to achieve their goals without the need
 * to modify source code.
 *
 */
@interface OGTKThemingEngine : OGObject
{

}

/**
 * Functions
 */
+ (OGTKThemingEngine*)load:(OFString*)name;
+ (void)registerPropertyWithNameSpace:(OFString*)nameSpace parseFunc:(GtkStylePropertyParser)parseFunc pspec:(GParamSpec*)pspec;

/**
 * Methods
 */

- (GtkThemingEngine*)THEMINGENGINE;

/**
 * Gets the background color for a given state.
 *
 * @param state state to retrieve the color for
 * @param color return value for the background color
 */
- (void)backgroundColorWithState:(GtkStateFlags)state color:(GdkRGBA*)color;

/**
 * Gets the border for a given state as a #GtkBorder.
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
 * Returns the font description for a given state.
 *
 * @param state state to retrieve the font for
 * @return the #PangoFontDescription for the given
 *          state. This object is owned by GTK+ and should not be
 *          freed.
 */
- (const PangoFontDescription*)font:(GtkStateFlags)state;

/**
 * Returns the widget direction used for rendering.
 *
 * @return the widget direction
 */
- (GtkJunctionSides)junctionSides;

/**
 * Gets the margin for a given state as a #GtkBorder.
 *
 * @param state state to retrieve the border for
 * @param margin return value for the margin settings
 */
- (void)marginWithState:(GtkStateFlags)state margin:(GtkBorder*)margin;

/**
 * Gets the padding for a given state as a #GtkBorder.
 *
 * @param state state to retrieve the padding for
 * @param padding return value for the padding settings
 */
- (void)paddingWithState:(GtkStateFlags)state padding:(GtkBorder*)padding;

/**
 * Returns the widget path used for style matching.
 *
 * @return A #GtkWidgetPath
 */
- (const GtkWidgetPath*)path;

/**
 * Gets a property value as retrieved from the style settings that apply
 * to the currently rendered element.
 *
 * @param property the property name
 * @param state state to retrieve the value for
 * @param value return location for the property value,
 *         you must free this memory using g_value_unset() once you are
 *         done with it.
 */
- (void)propertyWithProperty:(OFString*)property state:(GtkStateFlags)state value:(GValue*)value;

/**
 * Returns the #GdkScreen to which @engine currently rendering to.
 *
 * @return a #GdkScreen, or %NULL.
 */
- (OGGdkScreen*)screen;

/**
 * returns the state used when rendering.
 *
 * @return the state flags
 */
- (GtkStateFlags)state;

/**
 * Gets the value for a widget style property.
 *
 * @param propertyName the name of the widget style property
 * @param value Return location for the property value, free with
 *         g_value_unset() after use.
 */
- (void)stylePropertyWithPropertyName:(OFString*)propertyName value:(GValue*)value;

/**
 * Retrieves several widget style properties from @engine according to the
 * currently rendered content’s style.
 *
 * @param args va_list of property name/return location pairs, followed by %NULL
 */
- (void)styleValist:(va_list)args;

/**
 * Retrieves several style property values that apply to the currently
 * rendered element.
 *
 * @param state state to retrieve values for
 * @param args va_list of property name/return location pairs, followed by %NULL
 */
- (void)valistWithState:(GtkStateFlags)state args:(va_list)args;

/**
 * Returns %TRUE if the currently rendered contents have
 * defined the given class name.
 *
 * @param styleClass class name to look up
 * @return %TRUE if @engine has @class_name defined
 */
- (bool)hasClass:(OFString*)styleClass;

/**
 * Returns %TRUE if the currently rendered contents have the
 * region defined. If @flags_return is not %NULL, it is set
 * to the flags affecting the region.
 *
 * @param styleRegion a region name
 * @param flags return location for region flags
 * @return %TRUE if region is defined
 */
- (bool)hasRegionWithStyleRegion:(OFString*)styleRegion flags:(GtkRegionFlags*)flags;

/**
 * Looks up and resolves a color name in the current style’s color map.
 *
 * @param colorName color name to lookup
 * @param color Return location for the looked up color
 * @return %TRUE if @color_name was found and resolved, %FALSE otherwise
 */
- (bool)lookupColorWithColorName:(OFString*)colorName color:(GdkRGBA*)color;

/**
 * Returns %TRUE if there is a transition animation running for the
 * current region (see gtk_style_context_push_animatable_region()).
 * 
 * If @progress is not %NULL, the animation progress will be returned
 * there, 0.0 means the state is closest to being %FALSE, while 1.0 means
 * it’s closest to being %TRUE. This means transition animations will
 * run from 0 to 1 when @state is being set to %TRUE and from 1 to 0 when
 * it’s being set to %FALSE.
 *
 * @param state a widget state
 * @param progress return location for the transition progress
 * @return %TRUE if there is a running transition animation for @state.
 */
- (bool)stateIsRunningWithState:(GtkStateType)state progress:(gdouble*)progress;

@end