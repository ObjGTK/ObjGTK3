/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEntryCompletion.h"

#import "OGTKCellArea.h"
#import "OGTKWidget.h"

@implementation OGTKEntryCompletion

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_entry_completion_new()];

	return self;
}

- (instancetype)initWithArea:(OGTKCellArea*)area
{
	self = [super initWithGObject:(GObject*)gtk_entry_completion_new_with_area([area CELLAREA])];

	return self;
}

- (GtkEntryCompletion*)ENTRYCOMPLETION
{
	return GTK_ENTRY_COMPLETION([self GOBJECT]);
}

- (void)complete
{
	gtk_entry_completion_complete([self ENTRYCOMPLETION]);
}

- (OFString*)computePrefix:(OFString*)key
{
	return [OFString stringWithUTF8String:gtk_entry_completion_compute_prefix([self ENTRYCOMPLETION], [key UTF8String])];
}

- (void)deleteAction:(gint)index
{
	gtk_entry_completion_delete_action([self ENTRYCOMPLETION], index);
}

- (OFString*)completionPrefix
{
	return [OFString stringWithUTF8String:gtk_entry_completion_get_completion_prefix([self ENTRYCOMPLETION])];
}

- (OGTKWidget*)entry
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_entry_completion_get_entry([self ENTRYCOMPLETION])] autorelease];
}

- (bool)inlineCompletion
{
	return gtk_entry_completion_get_inline_completion([self ENTRYCOMPLETION]);
}

- (bool)inlineSelection
{
	return gtk_entry_completion_get_inline_selection([self ENTRYCOMPLETION]);
}

- (gint)minimumKeyLength
{
	return gtk_entry_completion_get_minimum_key_length([self ENTRYCOMPLETION]);
}

- (GtkTreeModel*)model
{
	return gtk_entry_completion_get_model([self ENTRYCOMPLETION]);
}

- (bool)popupCompletion
{
	return gtk_entry_completion_get_popup_completion([self ENTRYCOMPLETION]);
}

- (bool)popupSetWidth
{
	return gtk_entry_completion_get_popup_set_width([self ENTRYCOMPLETION]);
}

- (bool)popupSingleMatch
{
	return gtk_entry_completion_get_popup_single_match([self ENTRYCOMPLETION]);
}

- (gint)textColumn
{
	return gtk_entry_completion_get_text_column([self ENTRYCOMPLETION]);
}

- (void)insertActionMarkupWithIndex:(gint)index markup:(OFString*)markup
{
	gtk_entry_completion_insert_action_markup([self ENTRYCOMPLETION], index, [markup UTF8String]);
}

- (void)insertActionTextWithIndex:(gint)index text:(OFString*)text
{
	gtk_entry_completion_insert_action_text([self ENTRYCOMPLETION], index, [text UTF8String]);
}

- (void)insertPrefix
{
	gtk_entry_completion_insert_prefix([self ENTRYCOMPLETION]);
}

- (void)setInlineCompletion:(bool)inlineCompletion
{
	gtk_entry_completion_set_inline_completion([self ENTRYCOMPLETION], inlineCompletion);
}

- (void)setInlineSelection:(bool)inlineSelection
{
	gtk_entry_completion_set_inline_selection([self ENTRYCOMPLETION], inlineSelection);
}

- (void)setMatchFuncWithFunc:(GtkEntryCompletionMatchFunc)func funcData:(gpointer)funcData funcNotify:(GDestroyNotify)funcNotify
{
	gtk_entry_completion_set_match_func([self ENTRYCOMPLETION], func, funcData, funcNotify);
}

- (void)setMinimumKeyLength:(gint)length
{
	gtk_entry_completion_set_minimum_key_length([self ENTRYCOMPLETION], length);
}

- (void)setModel:(GtkTreeModel*)model
{
	gtk_entry_completion_set_model([self ENTRYCOMPLETION], model);
}

- (void)setPopupCompletion:(bool)popupCompletion
{
	gtk_entry_completion_set_popup_completion([self ENTRYCOMPLETION], popupCompletion);
}

- (void)setPopupSetWidth:(bool)popupSetWidth
{
	gtk_entry_completion_set_popup_set_width([self ENTRYCOMPLETION], popupSetWidth);
}

- (void)setPopupSingleMatch:(bool)popupSingleMatch
{
	gtk_entry_completion_set_popup_single_match([self ENTRYCOMPLETION], popupSingleMatch);
}

- (void)setTextColumn:(gint)column
{
	gtk_entry_completion_set_text_column([self ENTRYCOMPLETION], column);
}


@end