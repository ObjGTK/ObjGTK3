/*
 * OGTKFileFilter.m
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
#import "OGTKFileFilter.h"

@implementation OGTKFileFilter

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_file_filter_new()];

	return self;
}

- (id)initFromGvariant:(GVariant*)variant
{
	self = [super initWithGObject:(GObject*)gtk_file_filter_new_from_gvariant(variant)];

	return self;
}

- (GtkFileFilter*)FILEFILTER
{
	return GTK_FILE_FILTER([self GOBJECT]);
}

- (void)addCustomWithNeeded:(GtkFileFilterFlags)needed andFunc:(GtkFileFilterFunc)func andData:(gpointer)data andNotify:(GDestroyNotify)notify
{
	gtk_file_filter_add_custom(GTK_FILE_FILTER([self GOBJECT]), needed, func, data, notify);
}

- (void)addMimeType:(OFString*)mimeType
{
	gtk_file_filter_add_mime_type(GTK_FILE_FILTER([self GOBJECT]), [mimeType UTF8String]);
}

- (void)addPattern:(OFString*)pattern
{
	gtk_file_filter_add_pattern(GTK_FILE_FILTER([self GOBJECT]), [pattern UTF8String]);
}

- (void)addPixbufFormats
{
	gtk_file_filter_add_pixbuf_formats(GTK_FILE_FILTER([self GOBJECT]));
}

- (bool)filter:(const GtkFileFilterInfo*)filterInfo
{
	return gtk_file_filter_filter(GTK_FILE_FILTER([self GOBJECT]), filterInfo);
}

- (OFString*)getName
{
	return [OFString stringWithUTF8String:gtk_file_filter_get_name(GTK_FILE_FILTER([self GOBJECT]))];
}

- (GtkFileFilterFlags)getNeeded
{
	return gtk_file_filter_get_needed(GTK_FILE_FILTER([self GOBJECT]));
}

- (void)setName:(OFString*)name
{
	gtk_file_filter_set_name(GTK_FILE_FILTER([self GOBJECT]), [name UTF8String]);
}

- (GVariant*)toGvariant
{
	return gtk_file_filter_to_gvariant(GTK_FILE_FILTER([self GOBJECT]));
}


@end