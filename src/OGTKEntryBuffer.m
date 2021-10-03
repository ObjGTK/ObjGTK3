/*
 * OGTKEntryBuffer.m
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
#import "OGTKEntryBuffer.h"

@implementation OGTKEntryBuffer

- (id)initWithInitialChars:(OFString*)initialChars andNinitialChars:(gint)ninitialChars
{
	self = [super initWithGObject:(GObject*)gtk_entry_buffer_new([initialChars UTF8String], ninitialChars)];

	return self;
}

- (GtkEntryBuffer*)ENTRYBUFFER
{
	return GTK_ENTRY_BUFFER([self GOBJECT]);
}

- (guint)deleteTextWithPosition:(guint)position andNchars:(gint)nchars
{
	return gtk_entry_buffer_delete_text(GTK_ENTRY_BUFFER([self GOBJECT]), position, nchars);
}

- (void)emitDeletedTextWithPosition:(guint)position andNchars:(guint)nchars
{
	gtk_entry_buffer_emit_deleted_text(GTK_ENTRY_BUFFER([self GOBJECT]), position, nchars);
}

- (void)emitInsertedTextWithPosition:(guint)position andChars:(OFString*)chars andNchars:(guint)nchars
{
	gtk_entry_buffer_emit_inserted_text(GTK_ENTRY_BUFFER([self GOBJECT]), position, [chars UTF8String], nchars);
}

- (gsize)getBytes
{
	return gtk_entry_buffer_get_bytes(GTK_ENTRY_BUFFER([self GOBJECT]));
}

- (guint)getLength
{
	return gtk_entry_buffer_get_length(GTK_ENTRY_BUFFER([self GOBJECT]));
}

- (gint)getMaxLength
{
	return gtk_entry_buffer_get_max_length(GTK_ENTRY_BUFFER([self GOBJECT]));
}

- (OFString*)getText
{
	return [OFString stringWithUTF8String:gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER([self GOBJECT]))];
}

- (guint)insertTextWithPosition:(guint)position andChars:(OFString*)chars andNchars:(gint)nchars
{
	return gtk_entry_buffer_insert_text(GTK_ENTRY_BUFFER([self GOBJECT]), position, [chars UTF8String], nchars);
}

- (void)setMaxLength:(gint)maxLength
{
	gtk_entry_buffer_set_max_length(GTK_ENTRY_BUFFER([self GOBJECT]), maxLength);
}

- (void)setTextWithChars:(OFString*)chars andNchars:(gint)nchars
{
	gtk_entry_buffer_set_text(GTK_ENTRY_BUFFER([self GOBJECT]), [chars UTF8String], nchars);
}


@end