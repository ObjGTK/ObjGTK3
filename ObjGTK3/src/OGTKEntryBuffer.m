/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEntryBuffer.h"

@implementation OGTKEntryBuffer

- (instancetype)initWithInitialChars:(OFString*)initialChars ninitialChars:(gint)ninitialChars
{
	self = [super initWithGObject:(GObject*)gtk_entry_buffer_new([initialChars UTF8String], ninitialChars)];

	return self;
}

- (GtkEntryBuffer*)ENTRYBUFFER
{
	return GTK_ENTRY_BUFFER([self GOBJECT]);
}

- (guint)deleteTextWithPosition:(guint)position nchars:(gint)nchars
{
	return gtk_entry_buffer_delete_text([self ENTRYBUFFER], position, nchars);
}

- (void)emitDeletedTextWithPosition:(guint)position nchars:(guint)nchars
{
	gtk_entry_buffer_emit_deleted_text([self ENTRYBUFFER], position, nchars);
}

- (void)emitInsertedTextWithPosition:(guint)position chars:(OFString*)chars nchars:(guint)nchars
{
	gtk_entry_buffer_emit_inserted_text([self ENTRYBUFFER], position, [chars UTF8String], nchars);
}

- (gsize)bytes
{
	return gtk_entry_buffer_get_bytes([self ENTRYBUFFER]);
}

- (guint)length
{
	return gtk_entry_buffer_get_length([self ENTRYBUFFER]);
}

- (gint)maxLength
{
	return gtk_entry_buffer_get_max_length([self ENTRYBUFFER]);
}

- (OFString*)text
{
	return [OFString stringWithUTF8String:gtk_entry_buffer_get_text([self ENTRYBUFFER])];
}

- (guint)insertTextWithPosition:(guint)position chars:(OFString*)chars nchars:(gint)nchars
{
	return gtk_entry_buffer_insert_text([self ENTRYBUFFER], position, [chars UTF8String], nchars);
}

- (void)setMaxLength:(gint)maxLength
{
	gtk_entry_buffer_set_max_length([self ENTRYBUFFER], maxLength);
}

- (void)setTextWithChars:(OFString*)chars nchars:(gint)nchars
{
	gtk_entry_buffer_set_text([self ENTRYBUFFER], [chars UTF8String], nchars);
}


@end