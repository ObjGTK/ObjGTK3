/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>
#include <gtk/gtk.h>

#import <OGObject/OGObject.h>

/**
 * GtkStyleProperties provides the storage for style information
 * that is used by #GtkStyleContext and other #GtkStyleProvider
 * implementations.
 * 
 * Before style properties can be stored in GtkStyleProperties, they
 * must be registered with gtk_style_properties_register_property().
 * 
 * Unless you are writing a #GtkStyleProvider implementation, you
 * are unlikely to use this API directly, as gtk_style_context_get()
 * and its variants are the preferred way to access styling information
 * from widget implementations and theming engine implementations
 * should use the APIs provided by #GtkThemingEngine instead.
 * 
 * #GtkStyleProperties has been deprecated in GTK 3.16. The CSS
 * machinery does not use it anymore and all users of this object
 * have been deprecated.
 *
 */
@interface OGTKStyleProperties : OGObject
{

}

/**
 * Functions
 */

/**
 * Returns %TRUE if a property has been registered, if @pspec or
 * @parse_func are not %NULL, the #GParamSpec and parsing function
 * will be respectively returned.
 *
 * @param propertyName property name to look up
 * @param parseFunc return location for the parse function
 * @param pspec return location for the #GParamSpec
 * @return %TRUE if the property is registered, %FALSE otherwise
 */
+ (bool)lookupPropertyWithPropertyName:(OFString*)propertyName parseFunc:(GtkStylePropertyParser*)parseFunc pspec:(GParamSpec**)pspec;

/**
 * Registers a property so it can be used in the CSS file format.
 * This function is the low-level equivalent of
 * gtk_theming_engine_register_property(), if you are implementing
 * a theming engine, you want to use that function instead.
 *
 * @param parseFunc parsing function to use, or %NULL
 * @param pspec the #GParamSpec for the new property
 */
+ (void)registerPropertyWithParseFunc:(GtkStylePropertyParser)parseFunc pspec:(GParamSpec*)pspec;

/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkStyleProperties*)STYLEPROPERTIES;

/**
 * Clears all style information from @props.
 *
 */
- (void)clear;

/**
 * Gets a style property from @props for the given state. When done with @value,
 * g_value_unset() needs to be called to free any allocated memory.
 *
 * @param property style property name
 * @param state state to retrieve the property value for
 * @param value return location for the style property value.
 * @return %TRUE if the property exists in @props, %FALSE otherwise
 */
- (bool)propertyWithProperty:(OFString*)property state:(GtkStateFlags)state value:(GValue*)value;

/**
 * Retrieves several style property values from @props for a given state.
 *
 * @param state state to retrieve the property values for
 * @param args va_list of property name/return location pairs, followed by %NULL
 */
- (void)valistWithState:(GtkStateFlags)state args:(va_list)args;

/**
 * Returns the symbolic color that is mapped
 * to @name.
 *
 * @param name color name to lookup
 * @return The mapped color
 */
- (GtkSymbolicColor*)lookupColor:(OFString*)name;

/**
 * Maps @color so it can be referenced by @name. See
 * gtk_style_properties_lookup_color()
 *
 * @param name color name
 * @param color #GtkSymbolicColor to map @name to
 */
- (void)mapColorWithName:(OFString*)name color:(GtkSymbolicColor*)color;

/**
 * Merges into @props all the style information contained
 * in @props_to_merge. If @replace is %TRUE, the values
 * will be overwritten, if it is %FALSE, the older values
 * will prevail.
 *
 * @param propsToMerge a second #GtkStyleProperties
 * @param replace whether to replace values or not
 */
- (void)mergeWithPropsToMerge:(const GtkStyleProperties*)propsToMerge replace:(bool)replace;

/**
 * Sets a styling property in @props.
 *
 * @param property styling property to set
 * @param state state to set the value for
 * @param value new value for the property
 */
- (void)setPropertyWithProperty:(OFString*)property state:(GtkStateFlags)state value:(const GValue*)value;

/**
 * Sets several style properties on @props.
 *
 * @param state state to set the values for
 * @param args va_list of property name/value pairs, followed by %NULL
 */
- (void)setValistWithState:(GtkStateFlags)state args:(va_list)args;

/**
 * Unsets a style property in @props.
 *
 * @param property property to unset
 * @param state state to unset
 */
- (void)unsetPropertyWithProperty:(OFString*)property state:(GtkStateFlags)state;

@end