/*
 * OGTKComboBoxText.m
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
#import "OGTKComboBoxText.h"

@implementation OGTKComboBoxText

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_text_new()];

	return self;
}

- (id)initWithEntry
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_text_new_with_entry()];

	return self;
}

- (GtkComboBoxText*)COMBOBOXTEXT
{
	return GTK_COMBO_BOX_TEXT([self GOBJECT]);
}

- (void)appendWithId:(OFString*)id andText:(OFString*)text
{
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT([self GOBJECT]), [id UTF8String], [text UTF8String]);
}

- (void)appendText:(OFString*)text
{
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT([self GOBJECT]), [text UTF8String]);
}

- (OFString*)getActiveText
{
	return [OFString stringWithUTF8String:gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT([self GOBJECT]))];
}

- (void)insertWithPosition:(gint)position andId:(OFString*)id andText:(OFString*)text
{
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT([self GOBJECT]), position, [id UTF8String], [text UTF8String]);
}

- (void)insertTextWithPosition:(gint)position andText:(OFString*)text
{
	gtk_combo_box_text_insert_text(GTK_COMBO_BOX_TEXT([self GOBJECT]), position, [text UTF8String]);
}

- (void)prependWithId:(OFString*)id andText:(OFString*)text
{
	gtk_combo_box_text_prepend(GTK_COMBO_BOX_TEXT([self GOBJECT]), [id UTF8String], [text UTF8String]);
}

- (void)prependText:(OFString*)text
{
	gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT([self GOBJECT]), [text UTF8String]);
}

- (void)remove:(gint)position
{
	gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT([self GOBJECT]), position);
}

- (void)removeAll
{
	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT([self GOBJECT]));
}


@end