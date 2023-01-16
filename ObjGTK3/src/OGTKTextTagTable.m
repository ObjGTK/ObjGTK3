/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTextTagTable.h"

#import "OGTKTextTag.h"

@implementation OGTKTextTagTable

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_text_tag_table_new()];

	return self;
}

- (GtkTextTagTable*)TEXTTAGTABLE
{
	return GTK_TEXT_TAG_TABLE([self GOBJECT]);
}

- (bool)add:(OGTKTextTag*)tag
{
	return gtk_text_tag_table_add([self TEXTTAGTABLE], [tag TEXTTAG]);
}

- (void)foreachWithFunc:(GtkTextTagTableForeach)func data:(gpointer)data
{
	gtk_text_tag_table_foreach([self TEXTTAGTABLE], func, data);
}

- (gint)size
{
	return gtk_text_tag_table_get_size([self TEXTTAGTABLE]);
}

- (OGTKTextTag*)lookup:(OFString*)name
{
	return [[[OGTKTextTag alloc] initWithGObject:(GObject*)gtk_text_tag_table_lookup([self TEXTTAGTABLE], [name UTF8String])] autorelease];
}

- (void)remove:(OGTKTextTag*)tag
{
	gtk_text_tag_table_remove([self TEXTTAGTABLE], [tag TEXTTAG]);
}


@end