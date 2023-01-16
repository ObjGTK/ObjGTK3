/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKThemingEngine.h"

#import <OGdk3/OGGdkScreen.h>

@implementation OGTKThemingEngine

+ (OGTKThemingEngine*)load:(OFString*)name
{
	return [[[OGTKThemingEngine alloc] initWithGObject:(GObject*)gtk_theming_engine_load([name UTF8String])] autorelease];
}

+ (void)registerPropertyWithNameSpace:(OFString*)nameSpace parseFunc:(GtkStylePropertyParser)parseFunc pspec:(GParamSpec*)pspec
{
	gtk_theming_engine_register_property([nameSpace UTF8String], parseFunc, pspec);
}

- (GtkThemingEngine*)THEMINGENGINE
{
	return GTK_THEMING_ENGINE([self GOBJECT]);
}

- (void)backgroundColorWithState:(GtkStateFlags)state color:(GdkRGBA*)color
{
	gtk_theming_engine_get_background_color([self THEMINGENGINE], state, color);
}

- (void)borderWithState:(GtkStateFlags)state border:(GtkBorder*)border
{
	gtk_theming_engine_get_border([self THEMINGENGINE], state, border);
}

- (void)borderColorWithState:(GtkStateFlags)state color:(GdkRGBA*)color
{
	gtk_theming_engine_get_border_color([self THEMINGENGINE], state, color);
}

- (void)colorWithState:(GtkStateFlags)state color:(GdkRGBA*)color
{
	gtk_theming_engine_get_color([self THEMINGENGINE], state, color);
}

- (GtkTextDirection)direction
{
	return gtk_theming_engine_get_direction([self THEMINGENGINE]);
}

- (const PangoFontDescription*)font:(GtkStateFlags)state
{
	return gtk_theming_engine_get_font([self THEMINGENGINE], state);
}

- (GtkJunctionSides)junctionSides
{
	return gtk_theming_engine_get_junction_sides([self THEMINGENGINE]);
}

- (void)marginWithState:(GtkStateFlags)state margin:(GtkBorder*)margin
{
	gtk_theming_engine_get_margin([self THEMINGENGINE], state, margin);
}

- (void)paddingWithState:(GtkStateFlags)state padding:(GtkBorder*)padding
{
	gtk_theming_engine_get_padding([self THEMINGENGINE], state, padding);
}

- (const GtkWidgetPath*)path
{
	return gtk_theming_engine_get_path([self THEMINGENGINE]);
}

- (void)propertyWithProperty:(OFString*)property state:(GtkStateFlags)state value:(GValue*)value
{
	gtk_theming_engine_get_property([self THEMINGENGINE], [property UTF8String], state, value);
}

- (OGGdkScreen*)screen
{
	return [[[OGGdkScreen alloc] initWithGObject:(GObject*)gtk_theming_engine_get_screen([self THEMINGENGINE])] autorelease];
}

- (GtkStateFlags)state
{
	return gtk_theming_engine_get_state([self THEMINGENGINE]);
}

- (void)stylePropertyWithPropertyName:(OFString*)propertyName value:(GValue*)value
{
	gtk_theming_engine_get_style_property([self THEMINGENGINE], [propertyName UTF8String], value);
}

- (void)styleValist:(va_list)args
{
	gtk_theming_engine_get_style_valist([self THEMINGENGINE], args);
}

- (void)valistWithState:(GtkStateFlags)state args:(va_list)args
{
	gtk_theming_engine_get_valist([self THEMINGENGINE], state, args);
}

- (bool)hasClass:(OFString*)styleClass
{
	return gtk_theming_engine_has_class([self THEMINGENGINE], [styleClass UTF8String]);
}

- (bool)hasRegionWithStyleRegion:(OFString*)styleRegion flags:(GtkRegionFlags*)flags
{
	return gtk_theming_engine_has_region([self THEMINGENGINE], [styleRegion UTF8String], flags);
}

- (bool)lookupColorWithColorName:(OFString*)colorName color:(GdkRGBA*)color
{
	return gtk_theming_engine_lookup_color([self THEMINGENGINE], [colorName UTF8String], color);
}

- (bool)stateIsRunningWithState:(GtkStateType)state progress:(gdouble*)progress
{
	return gtk_theming_engine_state_is_running([self THEMINGENGINE], state, progress);
}


@end