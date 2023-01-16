/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKStyleProperties.h"

@implementation OGTKStyleProperties

+ (bool)lookupPropertyWithPropertyName:(OFString*)propertyName parseFunc:(GtkStylePropertyParser*)parseFunc pspec:(GParamSpec**)pspec
{
	return gtk_style_properties_lookup_property([propertyName UTF8String], parseFunc, pspec);
}

+ (void)registerPropertyWithParseFunc:(GtkStylePropertyParser)parseFunc pspec:(GParamSpec*)pspec
{
	gtk_style_properties_register_property(parseFunc, pspec);
}

- (instancetype)init
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
	gtk_style_properties_clear([self STYLEPROPERTIES]);
}

- (bool)propertyWithProperty:(OFString*)property state:(GtkStateFlags)state value:(GValue*)value
{
	return gtk_style_properties_get_property([self STYLEPROPERTIES], [property UTF8String], state, value);
}

- (void)valistWithState:(GtkStateFlags)state args:(va_list)args
{
	gtk_style_properties_get_valist([self STYLEPROPERTIES], state, args);
}

- (GtkSymbolicColor*)lookupColor:(OFString*)name
{
	return gtk_style_properties_lookup_color([self STYLEPROPERTIES], [name UTF8String]);
}

- (void)mapColorWithName:(OFString*)name color:(GtkSymbolicColor*)color
{
	gtk_style_properties_map_color([self STYLEPROPERTIES], [name UTF8String], color);
}

- (void)mergeWithPropsToMerge:(const GtkStyleProperties*)propsToMerge replace:(bool)replace
{
	gtk_style_properties_merge([self STYLEPROPERTIES], propsToMerge, replace);
}

- (void)setPropertyWithProperty:(OFString*)property state:(GtkStateFlags)state value:(const GValue*)value
{
	gtk_style_properties_set_property([self STYLEPROPERTIES], [property UTF8String], state, value);
}

- (void)setValistWithState:(GtkStateFlags)state args:(va_list)args
{
	gtk_style_properties_set_valist([self STYLEPROPERTIES], state, args);
}

- (void)unsetPropertyWithProperty:(OFString*)property state:(GtkStateFlags)state
{
	gtk_style_properties_unset_property([self STYLEPROPERTIES], [property UTF8String], state);
}


@end