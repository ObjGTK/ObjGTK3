/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTextBuffer.h"

#import "OGTKTextTagTable.h"
#import "OGTKTextTag.h"
#import <OGGdkPixbuf/OGGdkPixbuf.h>
#import "OGTKTextMark.h"
#import "OGTKTextChildAnchor.h"
#import "OGTKClipboard.h"

@implementation OGTKTextBuffer

- (instancetype)init:(OGTKTextTagTable*)table
{
	self = [super initWithGObject:(GObject*)gtk_text_buffer_new([table TEXTTAGTABLE])];

	return self;
}

- (GtkTextBuffer*)TEXTBUFFER
{
	return GTK_TEXT_BUFFER([self GOBJECT]);
}

- (void)addMarkWithMark:(OGTKTextMark*)mark where:(const GtkTextIter*)where
{
	gtk_text_buffer_add_mark([self TEXTBUFFER], [mark TEXTMARK], where);
}

- (void)addSelectionClipboard:(OGTKClipboard*)clipboard
{
	gtk_text_buffer_add_selection_clipboard([self TEXTBUFFER], [clipboard CLIPBOARD]);
}

- (void)applyTagWithTag:(OGTKTextTag*)tag start:(const GtkTextIter*)start end:(const GtkTextIter*)end
{
	gtk_text_buffer_apply_tag([self TEXTBUFFER], [tag TEXTTAG], start, end);
}

- (void)applyTagByNameWithName:(OFString*)name start:(const GtkTextIter*)start end:(const GtkTextIter*)end
{
	gtk_text_buffer_apply_tag_by_name([self TEXTBUFFER], [name UTF8String], start, end);
}

- (bool)backspaceWithIter:(GtkTextIter*)iter interactive:(bool)interactive defaultEditable:(bool)defaultEditable
{
	return gtk_text_buffer_backspace([self TEXTBUFFER], iter, interactive, defaultEditable);
}

- (void)beginUserAction
{
	gtk_text_buffer_begin_user_action([self TEXTBUFFER]);
}

- (void)copyClipboard:(OGTKClipboard*)clipboard
{
	gtk_text_buffer_copy_clipboard([self TEXTBUFFER], [clipboard CLIPBOARD]);
}

- (OGTKTextChildAnchor*)createChildAnchor:(GtkTextIter*)iter
{
	return [[[OGTKTextChildAnchor alloc] initWithGObject:(GObject*)gtk_text_buffer_create_child_anchor([self TEXTBUFFER], iter)] autorelease];
}

- (OGTKTextMark*)createMarkWithMarkName:(OFString*)markName where:(const GtkTextIter*)where leftGravity:(bool)leftGravity
{
	return [[[OGTKTextMark alloc] initWithGObject:(GObject*)gtk_text_buffer_create_mark([self TEXTBUFFER], [markName UTF8String], where, leftGravity)] autorelease];
}

- (void)cutClipboardWithClipboard:(OGTKClipboard*)clipboard defaultEditable:(bool)defaultEditable
{
	gtk_text_buffer_cut_clipboard([self TEXTBUFFER], [clipboard CLIPBOARD], defaultEditable);
}

- (void)deleteWithStart:(GtkTextIter*)start end:(GtkTextIter*)end
{
	gtk_text_buffer_delete([self TEXTBUFFER], start, end);
}

- (bool)deleteInteractiveWithStartIter:(GtkTextIter*)startIter endIter:(GtkTextIter*)endIter defaultEditable:(bool)defaultEditable
{
	return gtk_text_buffer_delete_interactive([self TEXTBUFFER], startIter, endIter, defaultEditable);
}

- (void)deleteMark:(OGTKTextMark*)mark
{
	gtk_text_buffer_delete_mark([self TEXTBUFFER], [mark TEXTMARK]);
}

- (void)deleteMarkByName:(OFString*)name
{
	gtk_text_buffer_delete_mark_by_name([self TEXTBUFFER], [name UTF8String]);
}

- (bool)deleteSelectionWithInteractive:(bool)interactive defaultEditable:(bool)defaultEditable
{
	return gtk_text_buffer_delete_selection([self TEXTBUFFER], interactive, defaultEditable);
}

- (bool)deserializeWithContentBuffer:(OGTKTextBuffer*)contentBuffer format:(GdkAtom)format iter:(GtkTextIter*)iter data:(const guint8*)data length:(gsize)length err:(GError**)err
{
	return gtk_text_buffer_deserialize([self TEXTBUFFER], [contentBuffer TEXTBUFFER], format, iter, data, length, err);
}

- (bool)deserializeGetCanCreateTags:(GdkAtom)format
{
	return gtk_text_buffer_deserialize_get_can_create_tags([self TEXTBUFFER], format);
}

- (void)deserializeSetCanCreateTagsWithFormat:(GdkAtom)format canCreateTags:(bool)canCreateTags
{
	gtk_text_buffer_deserialize_set_can_create_tags([self TEXTBUFFER], format, canCreateTags);
}

- (void)endUserAction
{
	gtk_text_buffer_end_user_action([self TEXTBUFFER]);
}

- (void)boundsWithStart:(GtkTextIter*)start end:(GtkTextIter*)end
{
	gtk_text_buffer_get_bounds([self TEXTBUFFER], start, end);
}

- (gint)charCount
{
	return gtk_text_buffer_get_char_count([self TEXTBUFFER]);
}

- (GtkTargetList*)copyTargetList
{
	return gtk_text_buffer_get_copy_target_list([self TEXTBUFFER]);
}

- (GdkAtom*)deserializeFormats:(gint*)nformats
{
	return gtk_text_buffer_get_deserialize_formats([self TEXTBUFFER], nformats);
}

- (void)endIter:(GtkTextIter*)iter
{
	gtk_text_buffer_get_end_iter([self TEXTBUFFER], iter);
}

- (bool)hasSelection
{
	return gtk_text_buffer_get_has_selection([self TEXTBUFFER]);
}

- (OGTKTextMark*)insert
{
	return [[[OGTKTextMark alloc] initWithGObject:(GObject*)gtk_text_buffer_get_insert([self TEXTBUFFER])] autorelease];
}

- (void)iterAtChildAnchorWithIter:(GtkTextIter*)iter anchor:(OGTKTextChildAnchor*)anchor
{
	gtk_text_buffer_get_iter_at_child_anchor([self TEXTBUFFER], iter, [anchor TEXTCHILDANCHOR]);
}

- (void)iterAtLineWithIter:(GtkTextIter*)iter lineNumber:(gint)lineNumber
{
	gtk_text_buffer_get_iter_at_line([self TEXTBUFFER], iter, lineNumber);
}

- (void)iterAtLineIndexWithIter:(GtkTextIter*)iter lineNumber:(gint)lineNumber byteIndex:(gint)byteIndex
{
	gtk_text_buffer_get_iter_at_line_index([self TEXTBUFFER], iter, lineNumber, byteIndex);
}

- (void)iterAtLineOffsetWithIter:(GtkTextIter*)iter lineNumber:(gint)lineNumber charOffset:(gint)charOffset
{
	gtk_text_buffer_get_iter_at_line_offset([self TEXTBUFFER], iter, lineNumber, charOffset);
}

- (void)iterAtMarkWithIter:(GtkTextIter*)iter mark:(OGTKTextMark*)mark
{
	gtk_text_buffer_get_iter_at_mark([self TEXTBUFFER], iter, [mark TEXTMARK]);
}

- (void)iterAtOffsetWithIter:(GtkTextIter*)iter charOffset:(gint)charOffset
{
	gtk_text_buffer_get_iter_at_offset([self TEXTBUFFER], iter, charOffset);
}

- (gint)lineCount
{
	return gtk_text_buffer_get_line_count([self TEXTBUFFER]);
}

- (OGTKTextMark*)mark:(OFString*)name
{
	return [[[OGTKTextMark alloc] initWithGObject:(GObject*)gtk_text_buffer_get_mark([self TEXTBUFFER], [name UTF8String])] autorelease];
}

- (bool)modified
{
	return gtk_text_buffer_get_modified([self TEXTBUFFER]);
}

- (GtkTargetList*)pasteTargetList
{
	return gtk_text_buffer_get_paste_target_list([self TEXTBUFFER]);
}

- (OGTKTextMark*)selectionBound
{
	return [[[OGTKTextMark alloc] initWithGObject:(GObject*)gtk_text_buffer_get_selection_bound([self TEXTBUFFER])] autorelease];
}

- (bool)selectionBoundsWithStart:(GtkTextIter*)start end:(GtkTextIter*)end
{
	return gtk_text_buffer_get_selection_bounds([self TEXTBUFFER], start, end);
}

- (GdkAtom*)serializeFormats:(gint*)nformats
{
	return gtk_text_buffer_get_serialize_formats([self TEXTBUFFER], nformats);
}

- (OFString*)sliceWithStart:(const GtkTextIter*)start end:(const GtkTextIter*)end includeHiddenChars:(bool)includeHiddenChars
{
	return [OFString stringWithUTF8String:gtk_text_buffer_get_slice([self TEXTBUFFER], start, end, includeHiddenChars)];
}

- (void)startIter:(GtkTextIter*)iter
{
	gtk_text_buffer_get_start_iter([self TEXTBUFFER], iter);
}

- (OGTKTextTagTable*)tagTable
{
	return [[[OGTKTextTagTable alloc] initWithGObject:(GObject*)gtk_text_buffer_get_tag_table([self TEXTBUFFER])] autorelease];
}

- (OFString*)textWithStart:(const GtkTextIter*)start end:(const GtkTextIter*)end includeHiddenChars:(bool)includeHiddenChars
{
	return [OFString stringWithUTF8String:gtk_text_buffer_get_text([self TEXTBUFFER], start, end, includeHiddenChars)];
}

- (void)insertWithIter:(GtkTextIter*)iter text:(OFString*)text len:(gint)len
{
	gtk_text_buffer_insert([self TEXTBUFFER], iter, [text UTF8String], len);
}

- (void)insertAtCursorWithText:(OFString*)text len:(gint)len
{
	gtk_text_buffer_insert_at_cursor([self TEXTBUFFER], [text UTF8String], len);
}

- (void)insertChildAnchorWithIter:(GtkTextIter*)iter anchor:(OGTKTextChildAnchor*)anchor
{
	gtk_text_buffer_insert_child_anchor([self TEXTBUFFER], iter, [anchor TEXTCHILDANCHOR]);
}

- (bool)insertInteractiveWithIter:(GtkTextIter*)iter text:(OFString*)text len:(gint)len defaultEditable:(bool)defaultEditable
{
	return gtk_text_buffer_insert_interactive([self TEXTBUFFER], iter, [text UTF8String], len, defaultEditable);
}

- (bool)insertInteractiveAtCursorWithText:(OFString*)text len:(gint)len defaultEditable:(bool)defaultEditable
{
	return gtk_text_buffer_insert_interactive_at_cursor([self TEXTBUFFER], [text UTF8String], len, defaultEditable);
}

- (void)insertMarkupWithIter:(GtkTextIter*)iter markup:(OFString*)markup len:(gint)len
{
	gtk_text_buffer_insert_markup([self TEXTBUFFER], iter, [markup UTF8String], len);
}

- (void)insertPixbufWithIter:(GtkTextIter*)iter pixbuf:(OGGdkPixbuf*)pixbuf
{
	gtk_text_buffer_insert_pixbuf([self TEXTBUFFER], iter, [pixbuf PIXBUF]);
}

- (void)insertRangeWithIter:(GtkTextIter*)iter start:(const GtkTextIter*)start end:(const GtkTextIter*)end
{
	gtk_text_buffer_insert_range([self TEXTBUFFER], iter, start, end);
}

- (bool)insertRangeInteractiveWithIter:(GtkTextIter*)iter start:(const GtkTextIter*)start end:(const GtkTextIter*)end defaultEditable:(bool)defaultEditable
{
	return gtk_text_buffer_insert_range_interactive([self TEXTBUFFER], iter, start, end, defaultEditable);
}

- (void)moveMarkWithMark:(OGTKTextMark*)mark where:(const GtkTextIter*)where
{
	gtk_text_buffer_move_mark([self TEXTBUFFER], [mark TEXTMARK], where);
}

- (void)moveMarkByNameWithName:(OFString*)name where:(const GtkTextIter*)where
{
	gtk_text_buffer_move_mark_by_name([self TEXTBUFFER], [name UTF8String], where);
}

- (void)pasteClipboardWithClipboard:(OGTKClipboard*)clipboard overrideLocation:(GtkTextIter*)overrideLocation defaultEditable:(bool)defaultEditable
{
	gtk_text_buffer_paste_clipboard([self TEXTBUFFER], [clipboard CLIPBOARD], overrideLocation, defaultEditable);
}

- (void)placeCursor:(const GtkTextIter*)where
{
	gtk_text_buffer_place_cursor([self TEXTBUFFER], where);
}

- (GdkAtom)registerDeserializeFormatWithMimeType:(OFString*)mimeType function:(GtkTextBufferDeserializeFunc)function userData:(gpointer)userData userDataDestroy:(GDestroyNotify)userDataDestroy
{
	return gtk_text_buffer_register_deserialize_format([self TEXTBUFFER], [mimeType UTF8String], function, userData, userDataDestroy);
}

- (GdkAtom)registerDeserializeTagset:(OFString*)tagsetName
{
	return gtk_text_buffer_register_deserialize_tagset([self TEXTBUFFER], [tagsetName UTF8String]);
}

- (GdkAtom)registerSerializeFormatWithMimeType:(OFString*)mimeType function:(GtkTextBufferSerializeFunc)function userData:(gpointer)userData userDataDestroy:(GDestroyNotify)userDataDestroy
{
	return gtk_text_buffer_register_serialize_format([self TEXTBUFFER], [mimeType UTF8String], function, userData, userDataDestroy);
}

- (GdkAtom)registerSerializeTagset:(OFString*)tagsetName
{
	return gtk_text_buffer_register_serialize_tagset([self TEXTBUFFER], [tagsetName UTF8String]);
}

- (void)removeAllTagsWithStart:(const GtkTextIter*)start end:(const GtkTextIter*)end
{
	gtk_text_buffer_remove_all_tags([self TEXTBUFFER], start, end);
}

- (void)removeSelectionClipboard:(OGTKClipboard*)clipboard
{
	gtk_text_buffer_remove_selection_clipboard([self TEXTBUFFER], [clipboard CLIPBOARD]);
}

- (void)removeTagWithTag:(OGTKTextTag*)tag start:(const GtkTextIter*)start end:(const GtkTextIter*)end
{
	gtk_text_buffer_remove_tag([self TEXTBUFFER], [tag TEXTTAG], start, end);
}

- (void)removeTagByNameWithName:(OFString*)name start:(const GtkTextIter*)start end:(const GtkTextIter*)end
{
	gtk_text_buffer_remove_tag_by_name([self TEXTBUFFER], [name UTF8String], start, end);
}

- (void)selectRangeWithIns:(const GtkTextIter*)ins bound:(const GtkTextIter*)bound
{
	gtk_text_buffer_select_range([self TEXTBUFFER], ins, bound);
}

- (guint8*)serializeWithContentBuffer:(OGTKTextBuffer*)contentBuffer format:(GdkAtom)format start:(const GtkTextIter*)start end:(const GtkTextIter*)end length:(gsize*)length
{
	return gtk_text_buffer_serialize([self TEXTBUFFER], [contentBuffer TEXTBUFFER], format, start, end, length);
}

- (void)setModified:(bool)setting
{
	gtk_text_buffer_set_modified([self TEXTBUFFER], setting);
}

- (void)setTextWithText:(OFString*)text len:(gint)len
{
	gtk_text_buffer_set_text([self TEXTBUFFER], [text UTF8String], len);
}

- (void)unregisterDeserializeFormat:(GdkAtom)format
{
	gtk_text_buffer_unregister_deserialize_format([self TEXTBUFFER], format);
}

- (void)unregisterSerializeFormat:(GdkAtom)format
{
	gtk_text_buffer_unregister_serialize_format([self TEXTBUFFER], format);
}


@end