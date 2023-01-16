/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

@class OGTKTextBuffer;

/**
 * You may wish to begin by reading the
 * [text widget conceptual overview][TextWidget]
 * which gives an overview of all the objects and data
 * types related to the text widget and how they work together.
 * 
 * A #GtkTextMark is like a bookmark in a text buffer; it preserves a position in
 * the text. You can convert the mark to an iterator using
 * gtk_text_buffer_get_iter_at_mark(). Unlike iterators, marks remain valid across
 * buffer mutations, because their behavior is defined when text is inserted or
 * deleted. When text containing a mark is deleted, the mark remains in the
 * position originally occupied by the deleted text. When text is inserted at a
 * mark, a mark with “left gravity” will be moved to the
 * beginning of the newly-inserted text, and a mark with “right
 * gravity” will be moved to the end.
 * 
 * Note that “left” and “right” here refer to logical direction (left
 * is the toward the start of the buffer); in some languages such as
 * Hebrew the logically-leftmost text is not actually on the left when
 * displayed.
 * 
 * Marks are reference counted, but the reference count only controls the validity
 * of the memory; marks can be deleted from the buffer at any time with
 * gtk_text_buffer_delete_mark(). Once deleted from the buffer, a mark is
 * essentially useless.
 * 
 * Marks optionally have names; these can be convenient to avoid passing the
 * #GtkTextMark object around.
 * 
 * Marks are typically created using the gtk_text_buffer_create_mark() function.
 *
 */
@interface OGTKTextMark : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)initWithName:(OFString*)name leftGravity:(bool)leftGravity;

/**
 * Methods
 */

- (GtkTextMark*)TEXTMARK;

/**
 * Gets the buffer this mark is located inside,
 * or %NULL if the mark is deleted.
 *
 * @return the mark’s #GtkTextBuffer
 */
- (OGTKTextBuffer*)buffer;

/**
 * Returns %TRUE if the mark has been removed from its buffer
 * with gtk_text_buffer_delete_mark(). See gtk_text_buffer_add_mark()
 * for a way to add it to a buffer again.
 *
 * @return whether the mark is deleted
 */
- (bool)deleted;

/**
 * Determines whether the mark has left gravity.
 *
 * @return %TRUE if the mark has left gravity, %FALSE otherwise
 */
- (bool)leftGravity;

/**
 * Returns the mark name; returns NULL for anonymous marks.
 *
 * @return mark name
 */
- (OFString*)name;

/**
 * Returns %TRUE if the mark is visible (i.e. a cursor is displayed
 * for it).
 *
 * @return %TRUE if visible
 */
- (bool)visible;

/**
 * Sets the visibility of @mark; the insertion point is normally
 * visible, i.e. you can see it as a vertical bar. Also, the text
 * widget uses a visible mark to indicate where a drop will occur when
 * dragging-and-dropping text. Most other marks are not visible.
 * Marks are not visible by default.
 *
 * @param setting visibility of mark
 */
- (void)setVisible:(bool)setting;

@end