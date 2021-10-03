/*
 * OGTKThemingEngine.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKThemingEngine.h"

@implementation OGTKThemingEngine

+ (GtkThemingEngine*)load:(OFString*)name
{
	return gtk_theming_engine_load([name UTF8String]);
}

+ (void)registerPropertyWithNameSpace:(OFString*)nameSpace andParseFunc:(GtkStylePropertyParser)parseFunc andPspec:(GParamSpec*)pspec
{
	gtk_theming_engine_register_property([nameSpace UTF8String], parseFunc, pspec);
}

- (GtkThemingEngine*)THEMINGENGINE
{
	return GTK_THEMING_ENGINE([self GOBJECT]);
}

- (void)getBackgroundColorWithState:(GtkStateFlags)state andColor:(GdkRGBA*)color
{
	gtk_theming_engine_get_background_color(GTK_THEMING_ENGINE([self GOBJECT]), state, color);
}

- (void)getBorderWithState:(GtkStateFlags)state andBorder:(GtkBorder*)border
{
	gtk_theming_engine_get_border(GTK_THEMING_ENGINE([self GOBJECT]), state, border);
}

- (void)getBorderColorWithState:(GtkStateFlags)state andColor:(GdkRGBA*)color
{
	gtk_theming_engine_get_border_color(GTK_THEMING_ENGINE([self GOBJECT]), state, color);
}

- (void)getColorWithState:(GtkStateFlags)state andColor:(GdkRGBA*)color
{
	gtk_theming_engine_get_color(GTK_THEMING_ENGINE([self GOBJECT]), state, color);
}

- (GtkTextDirection)getDirection
{
	return gtk_theming_engine_get_direction(GTK_THEMING_ENGINE([self GOBJECT]));
}

- (const PangoFontDescription*)getFont:(GtkStateFlags)state
{
	return gtk_theming_engine_get_font(GTK_THEMING_ENGINE([self GOBJECT]), state);
}

- (GtkJunctionSides)getJunctionSides
{
	return gtk_theming_engine_get_junction_sides(GTK_THEMING_ENGINE([self GOBJECT]));
}

- (void)getMarginWithState:(GtkStateFlags)state andMargin:(GtkBorder*)margin
{
	gtk_theming_engine_get_margin(GTK_THEMING_ENGINE([self GOBJECT]), state, margin);
}

- (void)getPaddingWithState:(GtkStateFlags)state andPadding:(GtkBorder*)padding
{
	gtk_theming_engine_get_padding(GTK_THEMING_ENGINE([self GOBJECT]), state, padding);
}

- (const GtkWidgetPath*)getPath
{
	return gtk_theming_engine_get_path(GTK_THEMING_ENGINE([self GOBJECT]));
}

- (void)getPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state andValue:(GValue*)value
{
	gtk_theming_engine_get_property(GTK_THEMING_ENGINE([self GOBJECT]), [property UTF8String], state, value);
}

- (GdkScreen*)getScreen
{
	return gtk_theming_engine_get_screen(GTK_THEMING_ENGINE([self GOBJECT]));
}

- (GtkStateFlags)getState
{
	return gtk_theming_engine_get_state(GTK_THEMING_ENGINE([self GOBJECT]));
}

- (void)getStylePropertyWithPropertyName:(OFString*)propertyName andValue:(GValue*)value
{
	gtk_theming_engine_get_style_property(GTK_THEMING_ENGINE([self GOBJECT]), [propertyName UTF8String], value);
}

- (void)getStyleValist:(va_list)args
{
	gtk_theming_engine_get_style_valist(GTK_THEMING_ENGINE([self GOBJECT]), args);
}

- (void)getValistWithState:(GtkStateFlags)state andArgs:(va_list)args
{
	gtk_theming_engine_get_valist(GTK_THEMING_ENGINE([self GOBJECT]), state, args);
}

- (bool)hasClass:(OFString*)styleClass
{
	return gtk_theming_engine_has_class(GTK_THEMING_ENGINE([self GOBJECT]), [styleClass UTF8String]);
}

- (bool)hasRegionWithStyleRegion:(OFString*)styleRegion andFlags:(GtkRegionFlags*)flags
{
	return gtk_theming_engine_has_region(GTK_THEMING_ENGINE([self GOBJECT]), [styleRegion UTF8String], flags);
}

- (bool)lookupColorWithColorName:(OFString*)colorName andColor:(GdkRGBA*)color
{
	return gtk_theming_engine_lookup_color(GTK_THEMING_ENGINE([self GOBJECT]), [colorName UTF8String], color);
}

- (bool)stateIsRunningWithState:(GtkStateType)state andProgress:(gdouble*)progress
{
	return gtk_theming_engine_state_is_running(GTK_THEMING_ENGINE([self GOBJECT]), state, progress);
}


@end