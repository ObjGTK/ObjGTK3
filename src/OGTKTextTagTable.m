/*
 * OGTKTextTagTable.m
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
#import "OGTKTextTagTable.h"

@implementation OGTKTextTagTable

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_text_tag_table_new()];

	return self;
}

- (GtkTextTagTable*)TEXTTAGTABLE
{
	return GTK_TEXT_TAG_TABLE([self GOBJECT]);
}

- (bool)add:(GtkTextTag*)tag
{
	return gtk_text_tag_table_add(GTK_TEXT_TAG_TABLE([self GOBJECT]), tag);
}

- (void)foreachWithFunc:(GtkTextTagTableForeach)func andData:(gpointer)data
{
	gtk_text_tag_table_foreach(GTK_TEXT_TAG_TABLE([self GOBJECT]), func, data);
}

- (gint)getSize
{
	return gtk_text_tag_table_get_size(GTK_TEXT_TAG_TABLE([self GOBJECT]));
}

- (GtkTextTag*)lookup:(OFString*)name
{
	return gtk_text_tag_table_lookup(GTK_TEXT_TAG_TABLE([self GOBJECT]), [name UTF8String]);
}

- (void)remove:(GtkTextTag*)tag
{
	gtk_text_tag_table_remove(GTK_TEXT_TAG_TABLE([self GOBJECT]), tag);
}


@end