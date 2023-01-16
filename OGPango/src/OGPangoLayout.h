/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <pango/pango.h>

#import <OGObject/OGObject.h>

@class OGPangoContext;

/**
 * The #PangoLayout structure represents an entire paragraph
 * of text. It is initialized with a #PangoContext, UTF-8 string
 * and set of attributes for that string. Once that is done, the
 * set of formatted lines can be extracted from the object,
 * the layout can be rendered, and conversion between logical
 * character positions within the layout's text, and the physical
 * position of the resulting glyphs can be made.
 * 
 * There are also a number of parameters to adjust the formatting
 * of a #PangoLayout, which are illustrated in <xref linkend="parameters"/>.
 * It is possible, as well, to ignore the 2-D setup, and simply
 * treat the results of a #PangoLayout as a list of lines.
 * 
 * <figure id="parameters">
 * <title>Adjustable parameters (on the left) and font metrics (on the right) for a PangoLayout</title>
 * <graphic fileref="layout.png" format="PNG"></graphic>
 * </figure>
 * 
 * The #PangoLayout structure is opaque, and has no user-visible
 * fields.
 *
 */
@interface OGPangoLayout : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGPangoContext*)context;

/**
 * Methods
 */

- (PangoLayout*)LAYOUT;

/**
 * Forces recomputation of any state in the #PangoLayout that
 * might depend on the layout's context. This function should
 * be called if you make changes to the context subsequent
 * to creating the layout.
 *
 */
- (void)contextChanged;

/**
 * Does a deep copy-by-value of the @src layout. The attribute list,
 * tab array, and text from the original layout are all copied by
 * value.
 *
 * @return the newly allocated #PangoLayout,
 *               with a reference count of one, which should be freed
 *               with g_object_unref().
 */
- (OGPangoLayout*)copy;

/**
 * Gets the alignment for the layout: how partial lines are
 * positioned within the horizontal space available.
 *
 * @return the alignment.
 */
- (PangoAlignment)alignment;

/**
 * Gets the attribute list for the layout, if any.
 *
 * @return a #PangoAttrList or %NULL
 *   if none was set.
 */
- (PangoAttrList*)attributes;

/**
 * Gets whether to calculate the bidirectional base direction
 * for the layout according to the contents of the layout.
 * See pango_layout_set_auto_dir().
 *
 * @return %TRUE if the bidirectional base direction
 *   is computed from the layout's contents, %FALSE otherwise.
 */
- (bool)autoDir;

/**
 * Gets the Y position of baseline of the first line in @layout.
 *
 * @return baseline of first line, from top of @layout.
 */
- (int)baseline;

/**
 * Returns the number of Unicode characters in the
 * the text of @layout.
 *
 * @return the number of Unicode characters
 *     in the text of @layout
 */
- (gint)characterCount;

/**
 * Retrieves the #PangoContext used for this layout.
 *
 * @return the #PangoContext for the layout.
 * This does not have an additional refcount added, so if you want to
 * keep a copy of this around, you must reference it yourself.
 */
- (OGPangoContext*)context;

/**
 * Given an index within a layout, determines the positions that of the
 * strong and weak cursors if the insertion point is at that
 * index. The position of each cursor is stored as a zero-width
 * rectangle. The strong cursor location is the location where
 * characters of the directionality equal to the base direction of the
 * layout are inserted.  The weak cursor location is the location
 * where characters of the directionality opposite to the base
 * direction of the layout are inserted.
 *
 * @param index the byte index of the cursor
 * @param strongPos location to store the strong cursor position
 *                     (may be %NULL)
 * @param weakPos location to store the weak cursor position (may be %NULL)
 */
- (void)cursorPosWithIndex:(int)index strongPos:(PangoRectangle*)strongPos weakPos:(PangoRectangle*)weakPos;

/**
 * Gets the text direction at the given character
 * position in @layout.
 *
 * @param index the byte index of the char
 * @return the text direction at @index
 */
- (PangoDirection)direction:(int)index;

/**
 * Gets the type of ellipsization being performed for @layout.
 * See pango_layout_set_ellipsize()
 *
 * @return the current ellipsization mode for @layout.
 * 
 * Use pango_layout_is_ellipsized() to query whether any paragraphs
 * were actually ellipsized.
 */
- (PangoEllipsizeMode)ellipsize;

/**
 * Computes the logical and ink extents of @layout. Logical extents
 * are usually what you want for positioning things.  Note that both extents
 * may have non-zero x and y.  You may want to use those to offset where you
 * render the layout.  Not doing that is a very typical bug that shows up as
 * right-to-left layouts not being correctly positioned in a layout with
 * a set width.
 * 
 * The extents are given in layout coordinates and in Pango units; layout
 * coordinates begin at the top left corner of the layout.
 *
 * @param inkRect rectangle used to store the extents of the
 *                   layout as drawn or %NULL to indicate that the result is
 *                   not needed.
 * @param logicalRect rectangle used to store the logical
 *                      extents of the layout or %NULL to indicate that the
 *                      result is not needed.
 */
- (void)extentsWithInkRect:(PangoRectangle*)inkRect logicalRect:(PangoRectangle*)logicalRect;

/**
 * Gets the font description for the layout, if any.
 *
 * @return a pointer to the layout's font
 *  description, or %NULL if the font description from the layout's
 *  context is inherited. This value is owned by the layout and must
 *  not be modified or freed.
 */
- (const PangoFontDescription*)fontDescription;

/**
 * Gets the height of layout used for ellipsization.  See
 * pango_layout_set_height() for details.
 *
 * @return the height, in Pango units if positive, or
 * number of lines if negative.
 */
- (int)height;

/**
 * Gets the paragraph indent width in Pango units. A negative value
 * indicates a hanging indentation.
 *
 * @return the indent in Pango units.
 */
- (int)indent;

/**
 * Returns an iterator to iterate over the visual extents of the layout.
 *
 * @return the new #PangoLayoutIter that should be freed using
 *               pango_layout_iter_free().
 */
- (PangoLayoutIter*)iter;

/**
 * Gets whether each complete line should be stretched to fill the entire
 * width of the layout.
 *
 * @return the justify.
 */
- (bool)justify;

/**
 * Retrieves a particular line from a #PangoLayout.
 * 
 * Use the faster pango_layout_get_line_readonly() if you do not plan
 * to modify the contents of the line (glyphs, glyph widths, etc.).
 *
 * @param line the index of a line, which must be between 0 and
 *        <literal>pango_layout_get_line_count(layout) - 1</literal>, inclusive.
 * @return the requested
 *               #PangoLayoutLine, or %NULL if the index is out of
 *               range. This layout line can be ref'ed and retained,
 *               but will become invalid if changes are made to the
 *               #PangoLayout.
 */
- (PangoLayoutLine*)line:(int)line;

/**
 * Retrieves the count of lines for the @layout.
 *
 * @return the line count.
 */
- (int)lineCount;

/**
 * Retrieves a particular line from a #PangoLayout.
 * 
 * This is a faster alternative to pango_layout_get_line(),
 * but the user is not expected
 * to modify the contents of the line (glyphs, glyph widths, etc.).
 *
 * @param line the index of a line, which must be between 0 and
 *        <literal>pango_layout_get_line_count(layout) - 1</literal>, inclusive.
 * @return the requested
 *               #PangoLayoutLine, or %NULL if the index is out of
 *               range. This layout line can be ref'ed and retained,
 *               but will become invalid if changes are made to the
 *               #PangoLayout.  No changes should be made to the line.
 */
- (PangoLayoutLine*)lineReadonly:(int)line;

/**
 * Gets the value that has been
 * set with pango_layout_set_line_spacing().
 *
 * @return
 */
- (float)lineSpacing;

/**
 * Returns the lines of the @layout as a list.
 * 
 * Use the faster pango_layout_get_lines_readonly() if you do not plan
 * to modify the contents of the lines (glyphs, glyph widths, etc.).
 *
 * @return a #GSList containing
 * the lines in the layout. This points to internal data of the #PangoLayout
 * and must be used with care. It will become invalid on any change to the layout's
 * text or properties.
 */
- (GSList*)lines;

/**
 * Returns the lines of the @layout as a list.
 * 
 * This is a faster alternative to pango_layout_get_lines(),
 * but the user is not expected
 * to modify the contents of the lines (glyphs, glyph widths, etc.).
 *
 * @return a #GSList containing
 * the lines in the layout. This points to internal data of the #PangoLayout and
 * must be used with care. It will become invalid on any change to the layout's
 * text or properties.  No changes should be made to the lines.
 */
- (GSList*)linesReadonly;

/**
 * Retrieves an array of logical attributes for each character in
 * the @layout.
 *
 * @param attrs location to store a pointer to an array of logical attributes
 *         This value must be freed with g_free().
 * @param nattrs location to store the number of the attributes in the
 *           array. (The stored value will be one more than the total number
 *           of characters in the layout, since there need to be attributes
 *           corresponding to both the position before the first character
 *           and the position after the last character.)
 */
- (void)logAttrsWithAttrs:(PangoLogAttr**)attrs nattrs:(gint*)nattrs;

/**
 * Retrieves an array of logical attributes for each character in
 * the @layout.
 * 
 * This is a faster alternative to pango_layout_get_log_attrs().
 * The returned array is part of @layout and must not be modified.
 * Modifying the layout will invalidate the returned array.
 * 
 * The number of attributes returned in @n_attrs will be one more
 * than the total number of characters in the layout, since there
 * need to be attributes corresponding to both the position before
 * the first character and the position after the last character.
 *
 * @param nattrs location to store the number of the attributes in
 *   the array
 * @return an array of logical attributes
 */
- (const PangoLogAttr*)logAttrsReadonly:(gint*)nattrs;

/**
 * Computes the logical and ink extents of @layout in device units.
 * This function just calls pango_layout_get_extents() followed by
 * two pango_extents_to_pixels() calls, rounding @ink_rect and @logical_rect
 * such that the rounded rectangles fully contain the unrounded one (that is,
 * passes them as first argument to pango_extents_to_pixels()).
 *
 * @param inkRect rectangle used to store the extents of the
 *                   layout as drawn or %NULL to indicate that the result is
 *                   not needed.
 * @param logicalRect rectangle used to store the logical
 *                       extents of the layout or %NULL to indicate that the
 *                       result is not needed.
 */
- (void)pixelExtentsWithInkRect:(PangoRectangle*)inkRect logicalRect:(PangoRectangle*)logicalRect;

/**
 * Determines the logical width and height of a #PangoLayout
 * in device units. (pango_layout_get_size() returns the width
 * and height scaled by %PANGO_SCALE.) This
 * is simply a convenience function around
 * pango_layout_get_pixel_extents().
 *
 * @param width location to store the logical width, or %NULL
 * @param height location to store the logical height, or %NULL
 */
- (void)pixelSizeWithWidth:(int*)width height:(int*)height;

/**
 * Returns the current serial number of @layout.  The serial number is
 * initialized to an small number  larger than zero when a new layout
 * is created and is increased whenever the layout is changed using any
 * of the setter functions, or the #PangoContext it uses has changed.
 * The serial may wrap, but will never have the value 0. Since it
 * can wrap, never compare it with "less than", always use "not equals".
 * 
 * This can be used to automatically detect changes to a #PangoLayout, and
 * is useful for example to decide whether a layout needs redrawing.
 * To force the serial to be increased, use pango_layout_context_changed().
 *
 * @return The current serial number of @layout.
 */
- (guint)serial;

/**
 * Obtains the value set by pango_layout_set_single_paragraph_mode().
 *
 * @return %TRUE if the layout does not break paragraphs at
 * paragraph separator characters, %FALSE otherwise.
 */
- (bool)singleParagraphMode;

/**
 * Determines the logical width and height of a #PangoLayout
 * in Pango units (device units scaled by %PANGO_SCALE). This
 * is simply a convenience function around pango_layout_get_extents().
 *
 * @param width location to store the logical width, or %NULL
 * @param height location to store the logical height, or %NULL
 */
- (void)sizeWithWidth:(int*)width height:(int*)height;

/**
 * Gets the amount of spacing between the lines of the layout.
 *
 * @return the spacing in Pango units.
 */
- (int)spacing;

/**
 * Gets the current #PangoTabArray used by this layout. If no
 * #PangoTabArray has been set, then the default tabs are in use
 * and %NULL is returned. Default tabs are every 8 spaces.
 * The return value should be freed with pango_tab_array_free().
 *
 * @return a copy of the tabs for this layout, or
 * %NULL.
 */
- (PangoTabArray*)tabs;

/**
 * Gets the text in the layout. The returned text should not
 * be freed or modified.
 *
 * @return the text in the @layout.
 */
- (OFString*)text;

/**
 * Counts the number unknown glyphs in @layout.  That is, zero if
 * glyphs for all characters in the layout text were found, or more
 * than zero otherwise.
 * 
 * This function can be used to determine if there are any fonts
 * available to render all characters in a certain string, or when
 * used in combination with %PANGO_ATTR_FALLBACK, to check if a
 * certain font supports all the characters in the string.
 *
 * @return The number of unknown glyphs in @layout.
 */
- (int)unknownGlyphsCount;

/**
 * Gets the width to which the lines of the #PangoLayout should wrap.
 *
 * @return the width in Pango units, or -1 if no width set.
 */
- (int)width;

/**
 * Gets the wrap mode for the layout.
 * 
 * Use pango_layout_is_wrapped() to query whether any paragraphs
 * were actually wrapped.
 *
 * @return active wrap mode.
 */
- (PangoWrapMode)wrap;

/**
 * Converts from byte @index_ within the @layout to line and X position.
 * (X position is measured from the left edge of the line)
 *
 * @param index the byte index of a grapheme within the layout.
 * @param trailing an integer indicating the edge of the grapheme to retrieve the
 *             position of. If > 0, the trailing edge of the grapheme, if 0,
 *             the leading of the grapheme.
 * @param line location to store resulting line index. (which will
 *               between 0 and pango_layout_get_line_count(layout) - 1), or %NULL
 * @param xpos location to store resulting position within line
 *              (%PANGO_SCALE units per device unit), or %NULL
 */
- (void)indexToLineXWithIndex:(int)index trailing:(bool)trailing line:(int*)line xpos:(int*)xpos;

/**
 * Converts from an index within a #PangoLayout to the onscreen position
 * corresponding to the grapheme at that index, which is represented
 * as rectangle.  Note that <literal>pos->x</literal> is always the leading
 * edge of the grapheme and <literal>pos->x + pos->width</literal> the trailing
 * edge of the grapheme. If the directionality of the grapheme is right-to-left,
 * then <literal>pos->width</literal> will be negative.
 *
 * @param index byte index within @layout
 * @param pos rectangle in which to store the position of the grapheme
 */
- (void)indexToPosWithIndex:(int)index pos:(PangoRectangle*)pos;

/**
 * Queries whether the layout had to ellipsize any paragraphs.
 * 
 * This returns %TRUE if the ellipsization mode for @layout
 * is not %PANGO_ELLIPSIZE_NONE, a positive width is set on @layout,
 * and there are paragraphs exceeding that width that have to be
 * ellipsized.
 *
 * @return %TRUE if any paragraphs had to be ellipsized, %FALSE
 * otherwise.
 */
- (bool)isEllipsized;

/**
 * Queries whether the layout had to wrap any paragraphs.
 * 
 * This returns %TRUE if a positive width is set on @layout,
 * ellipsization mode of @layout is set to %PANGO_ELLIPSIZE_NONE,
 * and there are paragraphs exceeding the layout width that have
 * to be wrapped.
 *
 * @return %TRUE if any paragraphs had to be wrapped, %FALSE
 * otherwise.
 */
- (bool)isWrapped;

/**
 * Computes a new cursor position from an old position and
 * a count of positions to move visually. If @direction is positive,
 * then the new strong cursor position will be one position
 * to the right of the old cursor position. If @direction is negative,
 * then the new strong cursor position will be one position
 * to the left of the old cursor position.
 * 
 * In the presence of bidirectional text, the correspondence
 * between logical and visual order will depend on the direction
 * of the current run, and there may be jumps when the cursor
 * is moved off of the end of a run.
 * 
 * Motion here is in cursor positions, not in characters, so a
 * single call to pango_layout_move_cursor_visually() may move the
 * cursor over multiple characters when multiple characters combine
 * to form a single grapheme.
 *
 * @param strong whether the moving cursor is the strong cursor or the
 *                weak cursor. The strong cursor is the cursor corresponding
 *                to text insertion in the base direction for the layout.
 * @param oldIndex the byte index of the grapheme for the old index
 * @param oldTrailing if 0, the cursor was at the leading edge of the
 *                grapheme indicated by @old_index, if > 0, the cursor
 *                was at the trailing edge.
 * @param direction direction to move cursor. A negative
 *                value indicates motion to the left.
 * @param newIndex location to store the new cursor byte index. A value of -1
 *                indicates that the cursor has been moved off the beginning
 *                of the layout. A value of %G_MAXINT indicates that
 *                the cursor has been moved off the end of the layout.
 * @param newTrailing number of characters to move forward from the
 *                location returned for @new_index to get the position
 *                where the cursor should be displayed. This allows
 *                distinguishing the position at the beginning of one
 *                line from the position at the end of the preceding
 *                line. @new_index is always on the line where the
 *                cursor should be displayed.
 */
- (void)moveCursorVisuallyWithStrong:(bool)strong oldIndex:(int)oldIndex oldTrailing:(int)oldTrailing direction:(int)direction newIndex:(int*)newIndex newTrailing:(int*)newTrailing;

/**
 * Sets the alignment for the layout: how partial lines are
 * positioned within the horizontal space available.
 *
 * @param alignment the alignment
 */
- (void)setAlignment:(PangoAlignment)alignment;

/**
 * Sets the text attributes for a layout object.
 * References @attrs, so the caller can unref its reference.
 *
 * @param attrs a #PangoAttrList, can be %NULL
 */
- (void)setAttributes:(PangoAttrList*)attrs;

/**
 * Sets whether to calculate the bidirectional base direction
 * for the layout according to the contents of the layout;
 * when this flag is on (the default), then paragraphs in
 *    @layout that begin with strong right-to-left characters
 * (Arabic and Hebrew principally), will have right-to-left
 * layout, paragraphs with letters from other scripts will
 * have left-to-right layout. Paragraphs with only neutral
 * characters get their direction from the surrounding paragraphs.
 * 
 * When %FALSE, the choice between left-to-right and
 * right-to-left layout is done according to the base direction
 * of the layout's #PangoContext. (See pango_context_set_base_dir()).
 * 
 * When the auto-computed direction of a paragraph differs from the
 * base direction of the context, the interpretation of
 * %PANGO_ALIGN_LEFT and %PANGO_ALIGN_RIGHT are swapped.
 *
 * @param autoDir if %TRUE, compute the bidirectional base direction
 *   from the layout's contents.
 */
- (void)setAutoDir:(bool)autoDir;

/**
 * Sets the type of ellipsization being performed for @layout.
 * Depending on the ellipsization mode @ellipsize text is
 * removed from the start, middle, or end of text so they
 * fit within the width and height of layout set with
 * pango_layout_set_width() and pango_layout_set_height().
 * 
 * If the layout contains characters such as newlines that
 * force it to be layed out in multiple paragraphs, then whether
 * each paragraph is ellipsized separately or the entire layout
 * is ellipsized as a whole depends on the set height of the layout.
 * See pango_layout_set_height() for details.
 *
 * @param ellipsize the new ellipsization mode for @layout
 */
- (void)setEllipsize:(PangoEllipsizeMode)ellipsize;

/**
 * Sets the default font description for the layout. If no font
 * description is set on the layout, the font description from
 * the layout's context is used.
 *
 * @param desc the new #PangoFontDescription, or %NULL to unset the
 *        current font description
 */
- (void)setFontDescription:(const PangoFontDescription*)desc;

/**
 * Sets the height to which the #PangoLayout should be ellipsized at.  There
 * are two different behaviors, based on whether @height is positive or
 * negative.
 * 
 * If @height is positive, it will be the maximum height of the layout.  Only
 * lines would be shown that would fit, and if there is any text omitted,
 * an ellipsis added.  At least one line is included in each paragraph regardless
 * of how small the height value is.  A value of zero will render exactly one
 * line for the entire layout.
 * 
 * If @height is negative, it will be the (negative of) maximum number of lines per
 * paragraph.  That is, the total number of lines shown may well be more than
 * this value if the layout contains multiple paragraphs of text.
 * The default value of -1 means that first line of each paragraph is ellipsized.
 * This behvaior may be changed in the future to act per layout instead of per
 * paragraph.  File a bug against pango at <ulink
 * url="http://bugzilla.gnome.org/">http://bugzilla.gnome.org/</ulink> if your
 * code relies on this behavior.
 * 
 * Height setting only has effect if a positive width is set on
 * @layout and ellipsization mode of @layout is not %PANGO_ELLIPSIZE_NONE.
 * The behavior is undefined if a height other than -1 is set and
 * ellipsization mode is set to %PANGO_ELLIPSIZE_NONE, and may change in the
 * future.
 *
 * @param height the desired height of the layout in Pango units if positive,
 *          or desired number of lines if negative.
 */
- (void)setHeight:(int)height;

/**
 * Sets the width in Pango units to indent each paragraph. A negative value
 * of @indent will produce a hanging indentation. That is, the first line will
 * have the full width, and subsequent lines will be indented by the
 * absolute value of @indent.
 * 
 * The indent setting is ignored if layout alignment is set to
 * %PANGO_ALIGN_CENTER.
 *
 * @param indent the amount by which to indent.
 */
- (void)setIndent:(int)indent;

/**
 * Sets whether each complete line should be stretched to
 * fill the entire width of the layout. This stretching is typically
 * done by adding whitespace, but for some scripts (such as Arabic),
 * the justification may be done in more complex ways, like extending
 * the characters.
 * 
 * Note that this setting is not implemented and so is ignored in Pango
 * older than 1.18.
 *
 * @param justify whether the lines in the layout should be justified.
 */
- (void)setJustify:(bool)justify;

/**
 * Sets a factor for line spacing.
 * Typical values are: 0, 1, 1.5, 2.
 * The default values is 0.
 * 
 * If @factor is non-zero, lines are placed
 * so that
 * 
 * baseline2 = baseline1 + factor * height2
 * 
 * where height2 is the line height of the
 * second line (as determined by the font(s)).
 * In this case, the spacing set with
 * pango_layout_set_spacing() is ignored.
 * 
 * If @factor is zero, spacing is applied as
 * before.
 *
 * @param factor the new line spacing factor
 */
- (void)setLineSpacing:(float)factor;

/**
 * Same as pango_layout_set_markup_with_accel(), but
 * the markup text isn't scanned for accelerators.
 *
 * @param markup marked-up text
 * @param length length of marked-up text in bytes, or -1 if @markup is
 *          null-terminated
 */
- (void)setMarkupWithMarkup:(OFString*)markup length:(int)length;

/**
 * Sets the layout text and attribute list from marked-up text (see
 * <link linkend="PangoMarkupFormat">markup format</link>). Replaces
 * the current text and attribute list.
 * 
 * If @accel_marker is nonzero, the given character will mark the
 * character following it as an accelerator. For example, @accel_marker
 * might be an ampersand or underscore. All characters marked
 * as an accelerator will receive a %PANGO_UNDERLINE_LOW attribute,
 * and the first character so marked will be returned in @accel_char.
 * Two @accel_marker characters following each other produce a single
 * literal @accel_marker character.
 *
 * @param markup marked-up text
 * (see <link linkend="PangoMarkupFormat">markup format</link>)
 * @param length length of marked-up text in bytes, or -1 if @markup is
 *          null-terminated
 * @param accelMarker marker for accelerators in the text
 * @param accelChar return location
 *                    for first located accelerator, or %NULL
 */
- (void)setMarkupWithAccelWithMarkup:(OFString*)markup length:(int)length accelMarker:(gunichar)accelMarker accelChar:(gunichar*)accelChar;

/**
 * If @setting is %TRUE, do not treat newlines and similar characters
 * as paragraph separators; instead, keep all text in a single paragraph,
 * and display a glyph for paragraph separator characters. Used when
 * you want to allow editing of newlines on a single text line.
 *
 * @param setting new setting
 */
- (void)setSingleParagraphMode:(bool)setting;

/**
 * Sets the amount of spacing in Pango unit between
 * the lines of the layout. When placing lines with
 * spacing, Pango arranges things so that
 * 
 * line2.top = line1.bottom + spacing
 * 
 * Note: Since 1.44, Pango defaults to using the
 * line height (as determined by the font) for placing
 * lines. The @spacing set with this function is only
 * taken into account when the line-height factor is
 * set to zero with pango_layout_set_line_spacing().
 *
 * @param spacing the amount of spacing
 */
- (void)setSpacing:(int)spacing;

/**
 * Sets the tabs to use for @layout, overriding the default tabs
 * (by default, tabs are every 8 spaces). If @tabs is %NULL, the default
 * tabs are reinstated. @tabs is copied into the layout; you must
 * free your copy of @tabs yourself.
 *
 * @param tabs a #PangoTabArray, or %NULL
 */
- (void)setTabs:(PangoTabArray*)tabs;

/**
 * Sets the text of the layout.
 * 
 * This function validates @text and renders invalid UTF-8
 * with a placeholder glyph.
 * 
 * Note that if you have used pango_layout_set_markup() or
 * pango_layout_set_markup_with_accel() on @layout before, you may
 * want to call pango_layout_set_attributes() to clear the attributes
 * set on the layout from the markup as this function does not clear
 * attributes.
 *
 * @param text the text
 * @param length maximum length of @text, in bytes. -1 indicates that
 *          the string is nul-terminated and the length should be
 *          calculated.  The text will also be truncated on
 *          encountering a nul-termination even when @length is
 *          positive.
 */
- (void)setTextWithText:(OFString*)text length:(int)length;

/**
 * Sets the width to which the lines of the #PangoLayout should wrap or
 * ellipsized.  The default value is -1: no width set.
 *
 * @param width the desired width in Pango units, or -1 to indicate that no
 *         wrapping or ellipsization should be performed.
 */
- (void)setWidth:(int)width;

/**
 * Sets the wrap mode; the wrap mode only has effect if a width
 * is set on the layout with pango_layout_set_width().
 * To turn off wrapping, set the width to -1.
 *
 * @param wrap the wrap mode
 */
- (void)setWrap:(PangoWrapMode)wrap;

/**
 * Converts from X and Y position within a layout to the byte
 * index to the character at that logical position. If the
 * Y position is not inside the layout, the closest position is chosen
 * (the position will be clamped inside the layout). If the
 * X position is not within the layout, then the start or the
 * end of the line is chosen as described for pango_layout_line_x_to_index().
 * If either the X or Y positions were not inside the layout, then the
 * function returns %FALSE; on an exact hit, it returns %TRUE.
 *
 * @param x the X offset (in Pango units)
 *             from the left edge of the layout.
 * @param y the Y offset (in Pango units)
 *             from the top edge of the layout
 * @param index location to store calculated byte index
 * @param trailing location to store a integer indicating where
 *             in the grapheme the user clicked. It will either
 *             be zero, or the number of characters in the
 *             grapheme. 0 represents the leading edge of the grapheme.
 * @return %TRUE if the coordinates were inside text, %FALSE otherwise.
 */
- (bool)xyToIndexWithX:(int)x y:(int)y index:(int*)index trailing:(int*)trailing;

@end