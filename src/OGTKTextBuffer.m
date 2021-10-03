/*
 * OGTKTextBuffer.m
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
#import "OGTKTextBuffer.h"

@implementation OGTKTextBuffer

- (id)init:(GtkTextTagTable*)table
{
	self = [super initWithGObject:(GObject*)gtk_text_buffer_new(table)];

	return self;
}

- (GtkTextBuffer*)TEXTBUFFER
{
	return GTK_TEXT_BUFFER([self GOBJECT]);
}

- (void)addMarkWithMark:(GtkTextMark*)mark andWhere:(const GtkTextIter*)where
{
	gtk_text_buffer_add_mark(GTK_TEXT_BUFFER([self GOBJECT]), mark, where);
}

- (void)addSelectionClipboard:(GtkClipboard*)clipboard
{
	gtk_text_buffer_add_selection_clipboard(GTK_TEXT_BUFFER([self GOBJECT]), clipboard);
}

- (void)applyTagWithTag:(GtkTextTag*)tag andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end
{
	gtk_text_buffer_apply_tag(GTK_TEXT_BUFFER([self GOBJECT]), tag, start, end);
}

- (void)applyTagByNameWithName:(OFString*)name andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end
{
	gtk_text_buffer_apply_tag_by_name(GTK_TEXT_BUFFER([self GOBJECT]), [name UTF8String], start, end);
}

- (bool)backspaceWithIter:(GtkTextIter*)iter andInteractive:(bool)interactive andDefaultEditable:(bool)defaultEditable
{
	return gtk_text_buffer_backspace(GTK_TEXT_BUFFER([self GOBJECT]), iter, interactive, defaultEditable);
}

- (void)beginUserAction
{
	gtk_text_buffer_begin_user_action(GTK_TEXT_BUFFER([self GOBJECT]));
}

- (void)copyClipboard:(GtkClipboard*)clipboard
{
	gtk_text_buffer_copy_clipboard(GTK_TEXT_BUFFER([self GOBJECT]), clipboard);
}

- (GtkTextChildAnchor*)createChildAnchor:(GtkTextIter*)iter
{
	return gtk_text_buffer_create_child_anchor(GTK_TEXT_BUFFER([self GOBJECT]), iter);
}

- (GtkTextMark*)createMarkWithMarkName:(OFString*)markName andWhere:(const GtkTextIter*)where andLeftGravity:(bool)leftGravity
{
	return gtk_text_buffer_create_mark(GTK_TEXT_BUFFER([self GOBJECT]), [markName UTF8String], where, leftGravity);
}

- (void)cutClipboardWithClipboard:(GtkClipboard*)clipboard andDefaultEditable:(bool)defaultEditable
{
	gtk_text_buffer_cut_clipboard(GTK_TEXT_BUFFER([self GOBJECT]), clipboard, defaultEditable);
}

- (void)deleteWithStart:(GtkTextIter*)start andEnd:(GtkTextIter*)end
{
	gtk_text_buffer_delete(GTK_TEXT_BUFFER([self GOBJECT]), start, end);
}

- (bool)deleteInteractiveWithStartIter:(GtkTextIter*)startIter andEndIter:(GtkTextIter*)endIter andDefaultEditable:(bool)defaultEditable
{
	return gtk_text_buffer_delete_interactive(GTK_TEXT_BUFFER([self GOBJECT]), startIter, endIter, defaultEditable);
}

- (void)deleteMark:(GtkTextMark*)mark
{
	gtk_text_buffer_delete_mark(GTK_TEXT_BUFFER([self GOBJECT]), mark);
}

- (void)deleteMarkByName:(OFString*)name
{
	gtk_text_buffer_delete_mark_by_name(GTK_TEXT_BUFFER([self GOBJECT]), [name UTF8String]);
}

- (bool)deleteSelectionWithInteractive:(bool)interactive andDefaultEditable:(bool)defaultEditable
{
	return gtk_text_buffer_delete_selection(GTK_TEXT_BUFFER([self GOBJECT]), interactive, defaultEditable);
}

- (bool)deserializeWithContentBuffer:(GtkTextBuffer*)contentBuffer andFormat:(GdkAtom)format andIter:(GtkTextIter*)iter andData:(const guint8*)data andLength:(gsize)length
{
	return gtk_text_buffer_deserialize(GTK_TEXT_BUFFER([self GOBJECT]), contentBuffer, format, iter, data, length);
}

- (bool)deserializeGetCanCreateTags:(GdkAtom)format
{
	return gtk_text_buffer_deserialize_get_can_create_tags(GTK_TEXT_BUFFER([self GOBJECT]), format);
}

- (void)deserializeSetCanCreateTagsWithFormat:(GdkAtom)format andCanCreateTags:(bool)canCreateTags
{
	gtk_text_buffer_deserialize_set_can_create_tags(GTK_TEXT_BUFFER([self GOBJECT]), format, canCreateTags);
}

- (void)endUserAction
{
	gtk_text_buffer_end_user_action(GTK_TEXT_BUFFER([self GOBJECT]));
}

- (void)getBoundsWithStart:(GtkTextIter*)start andEnd:(GtkTextIter*)end
{
	gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER([self GOBJECT]), start, end);
}

- (gint)getCharCount
{
	return gtk_text_buffer_get_char_count(GTK_TEXT_BUFFER([self GOBJECT]));
}

- (GtkTargetList*)getCopyTargetList
{
	return gtk_text_buffer_get_copy_target_list(GTK_TEXT_BUFFER([self GOBJECT]));
}

- (GdkAtom*)getDeserializeFormats:(gint*)nformats
{
	return gtk_text_buffer_get_deserialize_formats(GTK_TEXT_BUFFER([self GOBJECT]), nformats);
}

- (void)getEndIter:(GtkTextIter*)iter
{
	gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER([self GOBJECT]), iter);
}

- (bool)getHasSelection
{
	return gtk_text_buffer_get_has_selection(GTK_TEXT_BUFFER([self GOBJECT]));
}

- (GtkTextMark*)getInsert
{
	return gtk_text_buffer_get_insert(GTK_TEXT_BUFFER([self GOBJECT]));
}

- (void)getIterAtChildAnchorWithIter:(GtkTextIter*)iter andAnchor:(GtkTextChildAnchor*)anchor
{
	gtk_text_buffer_get_iter_at_child_anchor(GTK_TEXT_BUFFER([self GOBJECT]), iter, anchor);
}

- (void)getIterAtLineWithIter:(GtkTextIter*)iter andLineNumber:(gint)lineNumber
{
	gtk_text_buffer_get_iter_at_line(GTK_TEXT_BUFFER([self GOBJECT]), iter, lineNumber);
}

- (void)getIterAtLineIndexWithIter:(GtkTextIter*)iter andLineNumber:(gint)lineNumber andByteIndex:(gint)byteIndex
{
	gtk_text_buffer_get_iter_at_line_index(GTK_TEXT_BUFFER([self GOBJECT]), iter, lineNumber, byteIndex);
}

- (void)getIterAtLineOffsetWithIter:(GtkTextIter*)iter andLineNumber:(gint)lineNumber andCharOffset:(gint)charOffset
{
	gtk_text_buffer_get_iter_at_line_offset(GTK_TEXT_BUFFER([self GOBJECT]), iter, lineNumber, charOffset);
}

- (void)getIterAtMarkWithIter:(GtkTextIter*)iter andMark:(GtkTextMark*)mark
{
	gtk_text_buffer_get_iter_at_mark(GTK_TEXT_BUFFER([self GOBJECT]), iter, mark);
}

- (void)getIterAtOffsetWithIter:(GtkTextIter*)iter andCharOffset:(gint)charOffset
{
	gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER([self GOBJECT]), iter, charOffset);
}

- (gint)getLineCount
{
	return gtk_text_buffer_get_line_count(GTK_TEXT_BUFFER([self GOBJECT]));
}

- (GtkTextMark*)getMark:(OFString*)name
{
	return gtk_text_buffer_get_mark(GTK_TEXT_BUFFER([self GOBJECT]), [name UTF8String]);
}

- (bool)getModified
{
	return gtk_text_buffer_get_modified(GTK_TEXT_BUFFER([self GOBJECT]));
}

- (GtkTargetList*)getPasteTargetList
{
	return gtk_text_buffer_get_paste_target_list(GTK_TEXT_BUFFER([self GOBJECT]));
}

- (GtkTextMark*)getSelectionBound
{
	return gtk_text_buffer_get_selection_bound(GTK_TEXT_BUFFER([self GOBJECT]));
}

- (bool)getSelectionBoundsWithStart:(GtkTextIter*)start andEnd:(GtkTextIter*)end
{
	return gtk_text_buffer_get_selection_bounds(GTK_TEXT_BUFFER([self GOBJECT]), start, end);
}

- (GdkAtom*)getSerializeFormats:(gint*)nformats
{
	return gtk_text_buffer_get_serialize_formats(GTK_TEXT_BUFFER([self GOBJECT]), nformats);
}

- (OFString*)getSliceWithStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end andIncludeHiddenChars:(bool)includeHiddenChars
{
	return [OFString stringWithUTF8String:gtk_text_buffer_get_slice(GTK_TEXT_BUFFER([self GOBJECT]), start, end, includeHiddenChars)];
}

- (void)getStartIter:(GtkTextIter*)iter
{
	gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER([self GOBJECT]), iter);
}

- (GtkTextTagTable*)getTagTable
{
	return gtk_text_buffer_get_tag_table(GTK_TEXT_BUFFER([self GOBJECT]));
}

- (OFString*)getTextWithStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end andIncludeHiddenChars:(bool)includeHiddenChars
{
	return [OFString stringWithUTF8String:gtk_text_buffer_get_text(GTK_TEXT_BUFFER([self GOBJECT]), start, end, includeHiddenChars)];
}

- (void)insertWithIter:(GtkTextIter*)iter andText:(OFString*)text andLen:(gint)len
{
	gtk_text_buffer_insert(GTK_TEXT_BUFFER([self GOBJECT]), iter, [text UTF8String], len);
}

- (void)insertAtCursorWithText:(OFString*)text andLen:(gint)len
{
	gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER([self GOBJECT]), [text UTF8String], len);
}

- (void)insertChildAnchorWithIter:(GtkTextIter*)iter andAnchor:(GtkTextChildAnchor*)anchor
{
	gtk_text_buffer_insert_child_anchor(GTK_TEXT_BUFFER([self GOBJECT]), iter, anchor);
}

- (bool)insertInteractiveWithIter:(GtkTextIter*)iter andText:(OFString*)text andLen:(gint)len andDefaultEditable:(bool)defaultEditable
{
	return gtk_text_buffer_insert_interactive(GTK_TEXT_BUFFER([self GOBJECT]), iter, [text UTF8String], len, defaultEditable);
}

- (bool)insertInteractiveAtCursorWithText:(OFString*)text andLen:(gint)len andDefaultEditable:(bool)defaultEditable
{
	return gtk_text_buffer_insert_interactive_at_cursor(GTK_TEXT_BUFFER([self GOBJECT]), [text UTF8String], len, defaultEditable);
}

- (void)insertMarkupWithIter:(GtkTextIter*)iter andMarkup:(OFString*)markup andLen:(gint)len
{
	gtk_text_buffer_insert_markup(GTK_TEXT_BUFFER([self GOBJECT]), iter, [markup UTF8String], len);
}

- (void)insertPixbufWithIter:(GtkTextIter*)iter andPixbuf:(GdkPixbuf*)pixbuf
{
	gtk_text_buffer_insert_pixbuf(GTK_TEXT_BUFFER([self GOBJECT]), iter, pixbuf);
}

- (void)insertRangeWithIter:(GtkTextIter*)iter andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end
{
	gtk_text_buffer_insert_range(GTK_TEXT_BUFFER([self GOBJECT]), iter, start, end);
}

- (bool)insertRangeInteractiveWithIter:(GtkTextIter*)iter andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end andDefaultEditable:(bool)defaultEditable
{
	return gtk_text_buffer_insert_range_interactive(GTK_TEXT_BUFFER([self GOBJECT]), iter, start, end, defaultEditable);
}

- (void)moveMarkWithMark:(GtkTextMark*)mark andWhere:(const GtkTextIter*)where
{
	gtk_text_buffer_move_mark(GTK_TEXT_BUFFER([self GOBJECT]), mark, where);
}

- (void)moveMarkByNameWithName:(OFString*)name andWhere:(const GtkTextIter*)where
{
	gtk_text_buffer_move_mark_by_name(GTK_TEXT_BUFFER([self GOBJECT]), [name UTF8String], where);
}

- (void)pasteClipboardWithClipboard:(GtkClipboard*)clipboard andOverrideLocation:(GtkTextIter*)overrideLocation andDefaultEditable:(bool)defaultEditable
{
	gtk_text_buffer_paste_clipboard(GTK_TEXT_BUFFER([self GOBJECT]), clipboard, overrideLocation, defaultEditable);
}

- (void)placeCursor:(const GtkTextIter*)where
{
	gtk_text_buffer_place_cursor(GTK_TEXT_BUFFER([self GOBJECT]), where);
}

- (GdkAtom)registerDeserializeFormatWithMimeType:(OFString*)mimeType andFunction:(GtkTextBufferDeserializeFunc)function andUserData:(gpointer)userData andUserDataDestroy:(GDestroyNotify)userDataDestroy
{
	return gtk_text_buffer_register_deserialize_format(GTK_TEXT_BUFFER([self GOBJECT]), [mimeType UTF8String], function, userData, userDataDestroy);
}

- (GdkAtom)registerDeserializeTagset:(OFString*)tagsetName
{
	return gtk_text_buffer_register_deserialize_tagset(GTK_TEXT_BUFFER([self GOBJECT]), [tagsetName UTF8String]);
}

- (GdkAtom)registerSerializeFormatWithMimeType:(OFString*)mimeType andFunction:(GtkTextBufferSerializeFunc)function andUserData:(gpointer)userData andUserDataDestroy:(GDestroyNotify)userDataDestroy
{
	return gtk_text_buffer_register_serialize_format(GTK_TEXT_BUFFER([self GOBJECT]), [mimeType UTF8String], function, userData, userDataDestroy);
}

- (GdkAtom)registerSerializeTagset:(OFString*)tagsetName
{
	return gtk_text_buffer_register_serialize_tagset(GTK_TEXT_BUFFER([self GOBJECT]), [tagsetName UTF8String]);
}

- (void)removeAllTagsWithStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end
{
	gtk_text_buffer_remove_all_tags(GTK_TEXT_BUFFER([self GOBJECT]), start, end);
}

- (void)removeSelectionClipboard:(GtkClipboard*)clipboard
{
	gtk_text_buffer_remove_selection_clipboard(GTK_TEXT_BUFFER([self GOBJECT]), clipboard);
}

- (void)removeTagWithTag:(GtkTextTag*)tag andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end
{
	gtk_text_buffer_remove_tag(GTK_TEXT_BUFFER([self GOBJECT]), tag, start, end);
}

- (void)removeTagByNameWithName:(OFString*)name andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end
{
	gtk_text_buffer_remove_tag_by_name(GTK_TEXT_BUFFER([self GOBJECT]), [name UTF8String], start, end);
}

- (void)selectRangeWithIns:(const GtkTextIter*)ins andBound:(const GtkTextIter*)bound
{
	gtk_text_buffer_select_range(GTK_TEXT_BUFFER([self GOBJECT]), ins, bound);
}

- (guint8*)serializeWithContentBuffer:(GtkTextBuffer*)contentBuffer andFormat:(GdkAtom)format andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end andLength:(gsize*)length
{
	return gtk_text_buffer_serialize(GTK_TEXT_BUFFER([self GOBJECT]), contentBuffer, format, start, end, length);
}

- (void)setModified:(bool)setting
{
	gtk_text_buffer_set_modified(GTK_TEXT_BUFFER([self GOBJECT]), setting);
}

- (void)setTextWithText:(OFString*)text andLen:(gint)len
{
	gtk_text_buffer_set_text(GTK_TEXT_BUFFER([self GOBJECT]), [text UTF8String], len);
}

- (void)unregisterDeserializeFormat:(GdkAtom)format
{
	gtk_text_buffer_unregister_deserialize_format(GTK_TEXT_BUFFER([self GOBJECT]), format);
}

- (void)unregisterSerializeFormat:(GdkAtom)format
{
	gtk_text_buffer_unregister_serialize_format(GTK_TEXT_BUFFER([self GOBJECT]), format);
}


@end