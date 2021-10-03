/*
 * OGTKTextBuffer.h
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
#import "OGTKBase.h"

@interface OGTKTextBuffer : OGTKBase
{

}


/**
 * Constructors
 */
- (id)init:(GtkTextTagTable*)table;

/**
 * Methods
 */

- (GtkTextBuffer*)TEXTBUFFER;

/**
 * - (void*)addMarkWithMark:(GtkTextMark*)mark andWhere:(const GtkTextIter*)where;
 *
 * @param mark
 * @param where
 */
- (void)addMarkWithMark:(GtkTextMark*)mark andWhere:(const GtkTextIter*)where;

/**
 * - (void*)addSelectionClipboard:(GtkClipboard*)clipboard;
 *
 * @param clipboard
 */
- (void)addSelectionClipboard:(GtkClipboard*)clipboard;

/**
 * - (void*)applyTagWithTag:(GtkTextTag*)tag andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end;
 *
 * @param tag
 * @param start
 * @param end
 */
- (void)applyTagWithTag:(GtkTextTag*)tag andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end;

/**
 * - (void*)applyTagByNameWithName:(OFString*)name andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end;
 *
 * @param name
 * @param start
 * @param end
 */
- (void)applyTagByNameWithName:(OFString*)name andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end;

/**
 * - (bool*)backspaceWithIter:(GtkTextIter*)iter andInteractive:(bool)interactive andDefaultEditable:(bool)defaultEditable;
 *
 * @param iter
 * @param interactive
 * @param defaultEditable
 * @returns bool
 */
- (bool)backspaceWithIter:(GtkTextIter*)iter andInteractive:(bool)interactive andDefaultEditable:(bool)defaultEditable;

/**
 * - (void*)beginUserAction;
 *
 */
- (void)beginUserAction;

/**
 * - (void*)copyClipboard:(GtkClipboard*)clipboard;
 *
 * @param clipboard
 */
- (void)copyClipboard:(GtkClipboard*)clipboard;

/**
 * - (GtkTextChildAnchor**)createChildAnchor:(GtkTextIter*)iter;
 *
 * @param iter
 * @returns GtkTextChildAnchor*
 */
- (GtkTextChildAnchor*)createChildAnchor:(GtkTextIter*)iter;

/**
 * - (GtkTextMark**)createMarkWithMarkName:(OFString*)markName andWhere:(const GtkTextIter*)where andLeftGravity:(bool)leftGravity;
 *
 * @param markName
 * @param where
 * @param leftGravity
 * @returns GtkTextMark*
 */
- (GtkTextMark*)createMarkWithMarkName:(OFString*)markName andWhere:(const GtkTextIter*)where andLeftGravity:(bool)leftGravity;

/**
 * - (void*)cutClipboardWithClipboard:(GtkClipboard*)clipboard andDefaultEditable:(bool)defaultEditable;
 *
 * @param clipboard
 * @param defaultEditable
 */
- (void)cutClipboardWithClipboard:(GtkClipboard*)clipboard andDefaultEditable:(bool)defaultEditable;

/**
 * - (void*)deleteWithStart:(GtkTextIter*)start andEnd:(GtkTextIter*)end;
 *
 * @param start
 * @param end
 */
- (void)deleteWithStart:(GtkTextIter*)start andEnd:(GtkTextIter*)end;

/**
 * - (bool*)deleteInteractiveWithStartIter:(GtkTextIter*)startIter andEndIter:(GtkTextIter*)endIter andDefaultEditable:(bool)defaultEditable;
 *
 * @param startIter
 * @param endIter
 * @param defaultEditable
 * @returns bool
 */
- (bool)deleteInteractiveWithStartIter:(GtkTextIter*)startIter andEndIter:(GtkTextIter*)endIter andDefaultEditable:(bool)defaultEditable;

/**
 * - (void*)deleteMark:(GtkTextMark*)mark;
 *
 * @param mark
 */
- (void)deleteMark:(GtkTextMark*)mark;

/**
 * - (void*)deleteMarkByName:(OFString*)name;
 *
 * @param name
 */
- (void)deleteMarkByName:(OFString*)name;

/**
 * - (bool*)deleteSelectionWithInteractive:(bool)interactive andDefaultEditable:(bool)defaultEditable;
 *
 * @param interactive
 * @param defaultEditable
 * @returns bool
 */
- (bool)deleteSelectionWithInteractive:(bool)interactive andDefaultEditable:(bool)defaultEditable;

/**
 * - (bool*)deserializeWithContentBuffer:(GtkTextBuffer*)contentBuffer andFormat:(GdkAtom)format andIter:(GtkTextIter*)iter andData:(const guint8*)data andLength:(gsize)length;
 *
 * @param contentBuffer
 * @param format
 * @param iter
 * @param data
 * @param length
 * @returns bool
 */
- (bool)deserializeWithContentBuffer:(GtkTextBuffer*)contentBuffer andFormat:(GdkAtom)format andIter:(GtkTextIter*)iter andData:(const guint8*)data andLength:(gsize)length;

/**
 * - (bool*)deserializeGetCanCreateTags:(GdkAtom)format;
 *
 * @param format
 * @returns bool
 */
- (bool)deserializeGetCanCreateTags:(GdkAtom)format;

/**
 * - (void*)deserializeSetCanCreateTagsWithFormat:(GdkAtom)format andCanCreateTags:(bool)canCreateTags;
 *
 * @param format
 * @param canCreateTags
 */
- (void)deserializeSetCanCreateTagsWithFormat:(GdkAtom)format andCanCreateTags:(bool)canCreateTags;

/**
 * - (void*)endUserAction;
 *
 */
- (void)endUserAction;

/**
 * - (void*)getBoundsWithStart:(GtkTextIter*)start andEnd:(GtkTextIter*)end;
 *
 * @param start
 * @param end
 */
- (void)getBoundsWithStart:(GtkTextIter*)start andEnd:(GtkTextIter*)end;

/**
 * - (gint*)getCharCount;
 *
 * @returns gint
 */
- (gint)getCharCount;

/**
 * - (GtkTargetList**)getCopyTargetList;
 *
 * @returns GtkTargetList*
 */
- (GtkTargetList*)getCopyTargetList;

/**
 * - (GdkAtom**)getDeserializeFormats:(gint*)nformats;
 *
 * @param nformats
 * @returns GdkAtom*
 */
- (GdkAtom*)getDeserializeFormats:(gint*)nformats;

/**
 * - (void*)getEndIter:(GtkTextIter*)iter;
 *
 * @param iter
 */
- (void)getEndIter:(GtkTextIter*)iter;

/**
 * - (bool*)getHasSelection;
 *
 * @returns bool
 */
- (bool)getHasSelection;

/**
 * - (GtkTextMark**)getInsert;
 *
 * @returns GtkTextMark*
 */
- (GtkTextMark*)getInsert;

/**
 * - (void*)getIterAtChildAnchorWithIter:(GtkTextIter*)iter andAnchor:(GtkTextChildAnchor*)anchor;
 *
 * @param iter
 * @param anchor
 */
- (void)getIterAtChildAnchorWithIter:(GtkTextIter*)iter andAnchor:(GtkTextChildAnchor*)anchor;

/**
 * - (void*)getIterAtLineWithIter:(GtkTextIter*)iter andLineNumber:(gint)lineNumber;
 *
 * @param iter
 * @param lineNumber
 */
- (void)getIterAtLineWithIter:(GtkTextIter*)iter andLineNumber:(gint)lineNumber;

/**
 * - (void*)getIterAtLineIndexWithIter:(GtkTextIter*)iter andLineNumber:(gint)lineNumber andByteIndex:(gint)byteIndex;
 *
 * @param iter
 * @param lineNumber
 * @param byteIndex
 */
- (void)getIterAtLineIndexWithIter:(GtkTextIter*)iter andLineNumber:(gint)lineNumber andByteIndex:(gint)byteIndex;

/**
 * - (void*)getIterAtLineOffsetWithIter:(GtkTextIter*)iter andLineNumber:(gint)lineNumber andCharOffset:(gint)charOffset;
 *
 * @param iter
 * @param lineNumber
 * @param charOffset
 */
- (void)getIterAtLineOffsetWithIter:(GtkTextIter*)iter andLineNumber:(gint)lineNumber andCharOffset:(gint)charOffset;

/**
 * - (void*)getIterAtMarkWithIter:(GtkTextIter*)iter andMark:(GtkTextMark*)mark;
 *
 * @param iter
 * @param mark
 */
- (void)getIterAtMarkWithIter:(GtkTextIter*)iter andMark:(GtkTextMark*)mark;

/**
 * - (void*)getIterAtOffsetWithIter:(GtkTextIter*)iter andCharOffset:(gint)charOffset;
 *
 * @param iter
 * @param charOffset
 */
- (void)getIterAtOffsetWithIter:(GtkTextIter*)iter andCharOffset:(gint)charOffset;

/**
 * - (gint*)getLineCount;
 *
 * @returns gint
 */
- (gint)getLineCount;

/**
 * - (GtkTextMark**)getMark:(OFString*)name;
 *
 * @param name
 * @returns GtkTextMark*
 */
- (GtkTextMark*)getMark:(OFString*)name;

/**
 * - (bool*)getModified;
 *
 * @returns bool
 */
- (bool)getModified;

/**
 * - (GtkTargetList**)getPasteTargetList;
 *
 * @returns GtkTargetList*
 */
- (GtkTargetList*)getPasteTargetList;

/**
 * - (GtkTextMark**)getSelectionBound;
 *
 * @returns GtkTextMark*
 */
- (GtkTextMark*)getSelectionBound;

/**
 * - (bool*)getSelectionBoundsWithStart:(GtkTextIter*)start andEnd:(GtkTextIter*)end;
 *
 * @param start
 * @param end
 * @returns bool
 */
- (bool)getSelectionBoundsWithStart:(GtkTextIter*)start andEnd:(GtkTextIter*)end;

/**
 * - (GdkAtom**)getSerializeFormats:(gint*)nformats;
 *
 * @param nformats
 * @returns GdkAtom*
 */
- (GdkAtom*)getSerializeFormats:(gint*)nformats;

/**
 * - (OFString**)getSliceWithStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end andIncludeHiddenChars:(bool)includeHiddenChars;
 *
 * @param start
 * @param end
 * @param includeHiddenChars
 * @returns OFString*
 */
- (OFString*)getSliceWithStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end andIncludeHiddenChars:(bool)includeHiddenChars;

/**
 * - (void*)getStartIter:(GtkTextIter*)iter;
 *
 * @param iter
 */
- (void)getStartIter:(GtkTextIter*)iter;

/**
 * - (GtkTextTagTable**)getTagTable;
 *
 * @returns GtkTextTagTable*
 */
- (GtkTextTagTable*)getTagTable;

/**
 * - (OFString**)getTextWithStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end andIncludeHiddenChars:(bool)includeHiddenChars;
 *
 * @param start
 * @param end
 * @param includeHiddenChars
 * @returns OFString*
 */
- (OFString*)getTextWithStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end andIncludeHiddenChars:(bool)includeHiddenChars;

/**
 * - (void*)insertWithIter:(GtkTextIter*)iter andText:(OFString*)text andLen:(gint)len;
 *
 * @param iter
 * @param text
 * @param len
 */
- (void)insertWithIter:(GtkTextIter*)iter andText:(OFString*)text andLen:(gint)len;

/**
 * - (void*)insertAtCursorWithText:(OFString*)text andLen:(gint)len;
 *
 * @param text
 * @param len
 */
- (void)insertAtCursorWithText:(OFString*)text andLen:(gint)len;

/**
 * - (void*)insertChildAnchorWithIter:(GtkTextIter*)iter andAnchor:(GtkTextChildAnchor*)anchor;
 *
 * @param iter
 * @param anchor
 */
- (void)insertChildAnchorWithIter:(GtkTextIter*)iter andAnchor:(GtkTextChildAnchor*)anchor;

/**
 * - (bool*)insertInteractiveWithIter:(GtkTextIter*)iter andText:(OFString*)text andLen:(gint)len andDefaultEditable:(bool)defaultEditable;
 *
 * @param iter
 * @param text
 * @param len
 * @param defaultEditable
 * @returns bool
 */
- (bool)insertInteractiveWithIter:(GtkTextIter*)iter andText:(OFString*)text andLen:(gint)len andDefaultEditable:(bool)defaultEditable;

/**
 * - (bool*)insertInteractiveAtCursorWithText:(OFString*)text andLen:(gint)len andDefaultEditable:(bool)defaultEditable;
 *
 * @param text
 * @param len
 * @param defaultEditable
 * @returns bool
 */
- (bool)insertInteractiveAtCursorWithText:(OFString*)text andLen:(gint)len andDefaultEditable:(bool)defaultEditable;

/**
 * - (void*)insertMarkupWithIter:(GtkTextIter*)iter andMarkup:(OFString*)markup andLen:(gint)len;
 *
 * @param iter
 * @param markup
 * @param len
 */
- (void)insertMarkupWithIter:(GtkTextIter*)iter andMarkup:(OFString*)markup andLen:(gint)len;

/**
 * - (void*)insertPixbufWithIter:(GtkTextIter*)iter andPixbuf:(GdkPixbuf*)pixbuf;
 *
 * @param iter
 * @param pixbuf
 */
- (void)insertPixbufWithIter:(GtkTextIter*)iter andPixbuf:(GdkPixbuf*)pixbuf;

/**
 * - (void*)insertRangeWithIter:(GtkTextIter*)iter andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end;
 *
 * @param iter
 * @param start
 * @param end
 */
- (void)insertRangeWithIter:(GtkTextIter*)iter andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end;

/**
 * - (bool*)insertRangeInteractiveWithIter:(GtkTextIter*)iter andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end andDefaultEditable:(bool)defaultEditable;
 *
 * @param iter
 * @param start
 * @param end
 * @param defaultEditable
 * @returns bool
 */
- (bool)insertRangeInteractiveWithIter:(GtkTextIter*)iter andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end andDefaultEditable:(bool)defaultEditable;

/**
 * - (void*)moveMarkWithMark:(GtkTextMark*)mark andWhere:(const GtkTextIter*)where;
 *
 * @param mark
 * @param where
 */
- (void)moveMarkWithMark:(GtkTextMark*)mark andWhere:(const GtkTextIter*)where;

/**
 * - (void*)moveMarkByNameWithName:(OFString*)name andWhere:(const GtkTextIter*)where;
 *
 * @param name
 * @param where
 */
- (void)moveMarkByNameWithName:(OFString*)name andWhere:(const GtkTextIter*)where;

/**
 * - (void*)pasteClipboardWithClipboard:(GtkClipboard*)clipboard andOverrideLocation:(GtkTextIter*)overrideLocation andDefaultEditable:(bool)defaultEditable;
 *
 * @param clipboard
 * @param overrideLocation
 * @param defaultEditable
 */
- (void)pasteClipboardWithClipboard:(GtkClipboard*)clipboard andOverrideLocation:(GtkTextIter*)overrideLocation andDefaultEditable:(bool)defaultEditable;

/**
 * - (void*)placeCursor:(const GtkTextIter*)where;
 *
 * @param where
 */
- (void)placeCursor:(const GtkTextIter*)where;

/**
 * - (GdkAtom*)registerDeserializeFormatWithMimeType:(OFString*)mimeType andFunction:(GtkTextBufferDeserializeFunc)function andUserData:(gpointer)userData andUserDataDestroy:(GDestroyNotify)userDataDestroy;
 *
 * @param mimeType
 * @param function
 * @param userData
 * @param userDataDestroy
 * @returns GdkAtom
 */
- (GdkAtom)registerDeserializeFormatWithMimeType:(OFString*)mimeType andFunction:(GtkTextBufferDeserializeFunc)function andUserData:(gpointer)userData andUserDataDestroy:(GDestroyNotify)userDataDestroy;

/**
 * - (GdkAtom*)registerDeserializeTagset:(OFString*)tagsetName;
 *
 * @param tagsetName
 * @returns GdkAtom
 */
- (GdkAtom)registerDeserializeTagset:(OFString*)tagsetName;

/**
 * - (GdkAtom*)registerSerializeFormatWithMimeType:(OFString*)mimeType andFunction:(GtkTextBufferSerializeFunc)function andUserData:(gpointer)userData andUserDataDestroy:(GDestroyNotify)userDataDestroy;
 *
 * @param mimeType
 * @param function
 * @param userData
 * @param userDataDestroy
 * @returns GdkAtom
 */
- (GdkAtom)registerSerializeFormatWithMimeType:(OFString*)mimeType andFunction:(GtkTextBufferSerializeFunc)function andUserData:(gpointer)userData andUserDataDestroy:(GDestroyNotify)userDataDestroy;

/**
 * - (GdkAtom*)registerSerializeTagset:(OFString*)tagsetName;
 *
 * @param tagsetName
 * @returns GdkAtom
 */
- (GdkAtom)registerSerializeTagset:(OFString*)tagsetName;

/**
 * - (void*)removeAllTagsWithStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end;
 *
 * @param start
 * @param end
 */
- (void)removeAllTagsWithStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end;

/**
 * - (void*)removeSelectionClipboard:(GtkClipboard*)clipboard;
 *
 * @param clipboard
 */
- (void)removeSelectionClipboard:(GtkClipboard*)clipboard;

/**
 * - (void*)removeTagWithTag:(GtkTextTag*)tag andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end;
 *
 * @param tag
 * @param start
 * @param end
 */
- (void)removeTagWithTag:(GtkTextTag*)tag andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end;

/**
 * - (void*)removeTagByNameWithName:(OFString*)name andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end;
 *
 * @param name
 * @param start
 * @param end
 */
- (void)removeTagByNameWithName:(OFString*)name andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end;

/**
 * - (void*)selectRangeWithIns:(const GtkTextIter*)ins andBound:(const GtkTextIter*)bound;
 *
 * @param ins
 * @param bound
 */
- (void)selectRangeWithIns:(const GtkTextIter*)ins andBound:(const GtkTextIter*)bound;

/**
 * - (guint8**)serializeWithContentBuffer:(GtkTextBuffer*)contentBuffer andFormat:(GdkAtom)format andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end andLength:(gsize*)length;
 *
 * @param contentBuffer
 * @param format
 * @param start
 * @param end
 * @param length
 * @returns guint8*
 */
- (guint8*)serializeWithContentBuffer:(GtkTextBuffer*)contentBuffer andFormat:(GdkAtom)format andStart:(const GtkTextIter*)start andEnd:(const GtkTextIter*)end andLength:(gsize*)length;

/**
 * - (void*)setModified:(bool)setting;
 *
 * @param setting
 */
- (void)setModified:(bool)setting;

/**
 * - (void*)setTextWithText:(OFString*)text andLen:(gint)len;
 *
 * @param text
 * @param len
 */
- (void)setTextWithText:(OFString*)text andLen:(gint)len;

/**
 * - (void*)unregisterDeserializeFormat:(GdkAtom)format;
 *
 * @param format
 */
- (void)unregisterDeserializeFormat:(GdkAtom)format;

/**
 * - (void*)unregisterSerializeFormat:(GdkAtom)format;
 *
 * @param format
 */
- (void)unregisterSerializeFormat:(GdkAtom)format;

@end