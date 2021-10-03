/*
 * OGTKSettings.m
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
#import "OGTKSettings.h"

@implementation OGTKSettings

+ (GtkSettings*)getDefault
{
	return gtk_settings_get_default();
}

+ (GtkSettings*)getForScreen:(GdkScreen*)screen
{
	return gtk_settings_get_for_screen(screen);
}

+ (void)installProperty:(GParamSpec*)pspec
{
	gtk_settings_install_property(pspec);
}

+ (void)installPropertyParserWithPspec:(GParamSpec*)pspec andParser:(GtkRcPropertyParser)parser
{
	gtk_settings_install_property_parser(pspec, parser);
}

- (GtkSettings*)SETTINGS
{
	return GTK_SETTINGS([self GOBJECT]);
}

- (void)resetProperty:(OFString*)name
{
	gtk_settings_reset_property(GTK_SETTINGS([self GOBJECT]), [name UTF8String]);
}

- (void)setDoublePropertyWithName:(OFString*)name andVdouble:(gdouble)vdouble andOrigin:(OFString*)origin
{
	gtk_settings_set_double_property(GTK_SETTINGS([self GOBJECT]), [name UTF8String], vdouble, [origin UTF8String]);
}

- (void)setLongPropertyWithName:(OFString*)name andVlong:(glong)vlong andOrigin:(OFString*)origin
{
	gtk_settings_set_long_property(GTK_SETTINGS([self GOBJECT]), [name UTF8String], vlong, [origin UTF8String]);
}

- (void)setPropertyValueWithName:(OFString*)name andSvalue:(const GtkSettingsValue*)svalue
{
	gtk_settings_set_property_value(GTK_SETTINGS([self GOBJECT]), [name UTF8String], svalue);
}

- (void)setStringPropertyWithName:(OFString*)name andVstring:(OFString*)vstring andOrigin:(OFString*)origin
{
	gtk_settings_set_string_property(GTK_SETTINGS([self GOBJECT]), [name UTF8String], [vstring UTF8String], [origin UTF8String]);
}


@end