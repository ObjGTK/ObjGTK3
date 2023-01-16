/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSettings.h"

#import <OGdk3/OGGdkScreen.h>

@implementation OGTKSettings

+ (OGTKSettings*)default
{
	return [[[OGTKSettings alloc] initWithGObject:(GObject*)gtk_settings_get_default()] autorelease];
}

+ (OGTKSettings*)forScreen:(OGGdkScreen*)screen
{
	return [[[OGTKSettings alloc] initWithGObject:(GObject*)gtk_settings_get_for_screen([screen SCREEN])] autorelease];
}

+ (void)installProperty:(GParamSpec*)pspec
{
	gtk_settings_install_property(pspec);
}

+ (void)installPropertyParserWithPspec:(GParamSpec*)pspec parser:(GtkRcPropertyParser)parser
{
	gtk_settings_install_property_parser(pspec, parser);
}

- (GtkSettings*)SETTINGS
{
	return GTK_SETTINGS([self GOBJECT]);
}

- (void)resetProperty:(OFString*)name
{
	gtk_settings_reset_property([self SETTINGS], [name UTF8String]);
}

- (void)setDoublePropertyWithName:(OFString*)name vdouble:(gdouble)vdouble origin:(OFString*)origin
{
	gtk_settings_set_double_property([self SETTINGS], [name UTF8String], vdouble, [origin UTF8String]);
}

- (void)setLongPropertyWithName:(OFString*)name vlong:(glong)vlong origin:(OFString*)origin
{
	gtk_settings_set_long_property([self SETTINGS], [name UTF8String], vlong, [origin UTF8String]);
}

- (void)setPropertyValueWithName:(OFString*)name svalue:(const GtkSettingsValue*)svalue
{
	gtk_settings_set_property_value([self SETTINGS], [name UTF8String], svalue);
}

- (void)setStringPropertyWithName:(OFString*)name vstring:(OFString*)vstring origin:(OFString*)origin
{
	gtk_settings_set_string_property([self SETTINGS], [name UTF8String], [vstring UTF8String], [origin UTF8String]);
}


@end