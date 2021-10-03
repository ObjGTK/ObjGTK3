/*
 * OGTKCssProvider.m
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
#import "OGTKCssProvider.h"

@implementation OGTKCssProvider

+ (GtkCssProvider*)getDefault
{
	return gtk_css_provider_get_default();
}

+ (GtkCssProvider*)getNamedWithName:(OFString*)name andVariant:(OFString*)variant
{
	return gtk_css_provider_get_named([name UTF8String], [variant UTF8String]);
}

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_css_provider_new()];

	return self;
}

- (GtkCssProvider*)CSSPROVIDER
{
	return GTK_CSS_PROVIDER([self GOBJECT]);
}

- (bool)loadFromDataWithData:(OFString*)data andLength:(gssize)length
{
	return gtk_css_provider_load_from_data(GTK_CSS_PROVIDER([self GOBJECT]), [data UTF8String], length);
}

- (bool)loadFromFile:(GFile*)file
{
	return gtk_css_provider_load_from_file(GTK_CSS_PROVIDER([self GOBJECT]), file);
}

- (bool)loadFromPath:(OFString*)path
{
	return gtk_css_provider_load_from_path(GTK_CSS_PROVIDER([self GOBJECT]), [path UTF8String]);
}

- (void)loadFromResource:(OFString*)resourcePath
{
	gtk_css_provider_load_from_resource(GTK_CSS_PROVIDER([self GOBJECT]), [resourcePath UTF8String]);
}

- (char*)toString
{
	return gtk_css_provider_to_string(GTK_CSS_PROVIDER([self GOBJECT]));
}


@end