/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKComboBoxText.h"

#import "OGTKWidget.h"

@implementation OGTKComboBoxText

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_text_new()];

	return self;
}

- (instancetype)initWithEntry
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_text_new_with_entry()];

	return self;
}

- (GtkComboBoxText*)COMBOBOXTEXT
{
	return GTK_COMBO_BOX_TEXT([self GOBJECT]);
}

- (void)appendWithId:(OFString*)id text:(OFString*)text
{
	gtk_combo_box_text_append([self COMBOBOXTEXT], [id UTF8String], [text UTF8String]);
}

- (void)appendText:(OFString*)text
{
	gtk_combo_box_text_append_text([self COMBOBOXTEXT], [text UTF8String]);
}

- (OFString*)activeText
{
	return [OFString stringWithUTF8String:gtk_combo_box_text_get_active_text([self COMBOBOXTEXT])];
}

- (void)insertWithPosition:(gint)position id:(OFString*)id text:(OFString*)text
{
	gtk_combo_box_text_insert([self COMBOBOXTEXT], position, [id UTF8String], [text UTF8String]);
}

- (void)insertTextWithPosition:(gint)position text:(OFString*)text
{
	gtk_combo_box_text_insert_text([self COMBOBOXTEXT], position, [text UTF8String]);
}

- (void)prependWithId:(OFString*)id text:(OFString*)text
{
	gtk_combo_box_text_prepend([self COMBOBOXTEXT], [id UTF8String], [text UTF8String]);
}

- (void)prependText:(OFString*)text
{
	gtk_combo_box_text_prepend_text([self COMBOBOXTEXT], [text UTF8String]);
}

- (void)remove:(gint)position
{
	gtk_combo_box_text_remove([self COMBOBOXTEXT], position);
}

- (void)removeAll
{
	gtk_combo_box_text_remove_all([self COMBOBOXTEXT]);
}


@end