/*
 * OGTKStyleProperties.m
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
#import "OGTKStyleProperties.h"

@implementation OGTKStyleProperties

+ (bool)lookupPropertyWithPropertyName:(OFString*)propertyName andParseFunc:(GtkStylePropertyParser*)parseFunc andPspec:(GParamSpec**)pspec
{
	return gtk_style_properties_lookup_property([propertyName UTF8String], parseFunc, pspec);
}

+ (void)registerPropertyWithParseFunc:(GtkStylePropertyParser)parseFunc andPspec:(GParamSpec*)pspec
{
	gtk_style_properties_register_property(parseFunc, pspec);
}

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_style_properties_new()];

	return self;
}

- (GtkStyleProperties*)STYLEPROPERTIES
{
	return GTK_STYLE_PROPERTIES([self GOBJECT]);
}

- (void)clear
{
	gtk_style_properties_clear(GTK_STYLE_PROPERTIES([self GOBJECT]));
}

- (bool)getPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state andValue:(GValue*)value
{
	return gtk_style_properties_get_property(GTK_STYLE_PROPERTIES([self GOBJECT]), [property UTF8String], state, value);
}

- (void)getValistWithState:(GtkStateFlags)state andArgs:(va_list)args
{
	gtk_style_properties_get_valist(GTK_STYLE_PROPERTIES([self GOBJECT]), state, args);
}

- (GtkSymbolicColor*)lookupColor:(OFString*)name
{
	return gtk_style_properties_lookup_color(GTK_STYLE_PROPERTIES([self GOBJECT]), [name UTF8String]);
}

- (void)mapColorWithName:(OFString*)name andColor:(GtkSymbolicColor*)color
{
	gtk_style_properties_map_color(GTK_STYLE_PROPERTIES([self GOBJECT]), [name UTF8String], color);
}

- (void)mergeWithPropsToMerge:(const GtkStyleProperties*)propsToMerge andReplace:(bool)replace
{
	gtk_style_properties_merge(GTK_STYLE_PROPERTIES([self GOBJECT]), propsToMerge, replace);
}

- (void)setPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state andValue:(const GValue*)value
{
	gtk_style_properties_set_property(GTK_STYLE_PROPERTIES([self GOBJECT]), [property UTF8String], state, value);
}

- (void)setValistWithState:(GtkStateFlags)state andArgs:(va_list)args
{
	gtk_style_properties_set_valist(GTK_STYLE_PROPERTIES([self GOBJECT]), state, args);
}

- (void)unsetPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state
{
	gtk_style_properties_unset_property(GTK_STYLE_PROPERTIES([self GOBJECT]), [property UTF8String], state);
}


@end