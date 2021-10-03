/*
 * OGTKEntryCompletion.m
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
#import "OGTKEntryCompletion.h"

@implementation OGTKEntryCompletion

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_entry_completion_new()];

	return self;
}

- (id)initWithArea:(GtkCellArea*)area
{
	self = [super initWithGObject:(GObject*)gtk_entry_completion_new_with_area(area)];

	return self;
}

- (GtkEntryCompletion*)ENTRYCOMPLETION
{
	return GTK_ENTRY_COMPLETION([self GOBJECT]);
}

- (void)complete
{
	gtk_entry_completion_complete(GTK_ENTRY_COMPLETION([self GOBJECT]));
}

- (OFString*)computePrefix:(const char*)key
{
	return [OFString stringWithUTF8String:gtk_entry_completion_compute_prefix(GTK_ENTRY_COMPLETION([self GOBJECT]), key)];
}

- (void)deleteAction:(gint)index
{
	gtk_entry_completion_delete_action(GTK_ENTRY_COMPLETION([self GOBJECT]), index);
}

- (OFString*)getCompletionPrefix
{
	return [OFString stringWithUTF8String:gtk_entry_completion_get_completion_prefix(GTK_ENTRY_COMPLETION([self GOBJECT]))];
}

- (OGTKWidget*)getEntry
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_entry_completion_get_entry(GTK_ENTRY_COMPLETION([self GOBJECT]))];
}

- (bool)getInlineCompletion
{
	return gtk_entry_completion_get_inline_completion(GTK_ENTRY_COMPLETION([self GOBJECT]));
}

- (bool)getInlineSelection
{
	return gtk_entry_completion_get_inline_selection(GTK_ENTRY_COMPLETION([self GOBJECT]));
}

- (gint)getMinimumKeyLength
{
	return gtk_entry_completion_get_minimum_key_length(GTK_ENTRY_COMPLETION([self GOBJECT]));
}

- (GtkTreeModel*)getModel
{
	return gtk_entry_completion_get_model(GTK_ENTRY_COMPLETION([self GOBJECT]));
}

- (bool)getPopupCompletion
{
	return gtk_entry_completion_get_popup_completion(GTK_ENTRY_COMPLETION([self GOBJECT]));
}

- (bool)getPopupSetWidth
{
	return gtk_entry_completion_get_popup_set_width(GTK_ENTRY_COMPLETION([self GOBJECT]));
}

- (bool)getPopupSingleMatch
{
	return gtk_entry_completion_get_popup_single_match(GTK_ENTRY_COMPLETION([self GOBJECT]));
}

- (gint)getTextColumn
{
	return gtk_entry_completion_get_text_column(GTK_ENTRY_COMPLETION([self GOBJECT]));
}

- (void)insertActionMarkupWithIndex:(gint)index andMarkup:(OFString*)markup
{
	gtk_entry_completion_insert_action_markup(GTK_ENTRY_COMPLETION([self GOBJECT]), index, [markup UTF8String]);
}

- (void)insertActionTextWithIndex:(gint)index andText:(OFString*)text
{
	gtk_entry_completion_insert_action_text(GTK_ENTRY_COMPLETION([self GOBJECT]), index, [text UTF8String]);
}

- (void)insertPrefix
{
	gtk_entry_completion_insert_prefix(GTK_ENTRY_COMPLETION([self GOBJECT]));
}

- (void)setInlineCompletion:(bool)inlineCompletion
{
	gtk_entry_completion_set_inline_completion(GTK_ENTRY_COMPLETION([self GOBJECT]), inlineCompletion);
}

- (void)setInlineSelection:(bool)inlineSelection
{
	gtk_entry_completion_set_inline_selection(GTK_ENTRY_COMPLETION([self GOBJECT]), inlineSelection);
}

- (void)setMatchFuncWithFunc:(GtkEntryCompletionMatchFunc)func andFuncData:(gpointer)funcData andFuncNotify:(GDestroyNotify)funcNotify
{
	gtk_entry_completion_set_match_func(GTK_ENTRY_COMPLETION([self GOBJECT]), func, funcData, funcNotify);
}

- (void)setMinimumKeyLength:(gint)length
{
	gtk_entry_completion_set_minimum_key_length(GTK_ENTRY_COMPLETION([self GOBJECT]), length);
}

- (void)setModel:(GtkTreeModel*)model
{
	gtk_entry_completion_set_model(GTK_ENTRY_COMPLETION([self GOBJECT]), model);
}

- (void)setPopupCompletion:(bool)popupCompletion
{
	gtk_entry_completion_set_popup_completion(GTK_ENTRY_COMPLETION([self GOBJECT]), popupCompletion);
}

- (void)setPopupSetWidth:(bool)popupSetWidth
{
	gtk_entry_completion_set_popup_set_width(GTK_ENTRY_COMPLETION([self GOBJECT]), popupSetWidth);
}

- (void)setPopupSingleMatch:(bool)popupSingleMatch
{
	gtk_entry_completion_set_popup_single_match(GTK_ENTRY_COMPLETION([self GOBJECT]), popupSingleMatch);
}

- (void)setTextColumn:(gint)column
{
	gtk_entry_completion_set_text_column(GTK_ENTRY_COMPLETION([self GOBJECT]), column);
}


@end