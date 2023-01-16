/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKTextChildAnchor;
@class OGGdkWindow;
@class OGTKAdjustment;
@class OGTKTextBuffer;
@class OGTKWidget;
@class OGTKTextMark;

/**
 * You may wish to begin by reading the
 * [text widget conceptual overview][TextWidget]
 * which gives an overview of all the objects and data
 * types related to the text widget and how they work together.
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * textview.view
 * ├── border.top
 * ├── border.left
 * ├── text
 * │   ╰── [selection]
 * ├── border.right
 * ├── border.bottom
 * ╰── [window.popup]
 * ]|
 * 
 * GtkTextView has a main css node with name textview and style class .view,
 * and subnodes for each of the border windows, and the main text area,
 * with names border and text, respectively. The border nodes each get
 * one of the style classes .left, .right, .top or .bottom.
 * 
 * A node representing the selection will appear below the text node.
 * 
 * If a context menu is opened, the window node will appear as a subnode
 * of the main node.
 *
 */
@interface OGTKTextView : OGTKContainer
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initWithBuffer:(OGTKTextBuffer*)buffer;

/**
 * Methods
 */

- (GtkTextView*)TEXTVIEW;

/**
 * Adds a child widget in the text buffer, at the given @anchor.
 *
 * @param child a #GtkWidget
 * @param anchor a #GtkTextChildAnchor in the #GtkTextBuffer for @text_view
 */
- (void)addChildAtAnchorWithChild:(OGTKWidget*)child anchor:(OGTKTextChildAnchor*)anchor;

/**
 * Adds a child at fixed coordinates in one of the text widget's
 * windows.
 * 
 * The window must have nonzero size (see
 * gtk_text_view_set_border_window_size()). Note that the child
 * coordinates are given relative to scrolling. When
 * placing a child in #GTK_TEXT_WINDOW_WIDGET, scrolling is
 * irrelevant, the child floats above all scrollable areas. But when
 * placing a child in one of the scrollable windows (border windows or
 * text window) it will move with the scrolling as needed.
 *
 * @param child a #GtkWidget
 * @param whichWindow which window the child should appear in
 * @param xpos X position of child in window coordinates
 * @param ypos Y position of child in window coordinates
 */
- (void)addChildInWindowWithChild:(OGTKWidget*)child whichWindow:(GtkTextWindowType)whichWindow xpos:(gint)xpos ypos:(gint)ypos;

/**
 * Moves the given @iter backward by one display (wrapped) line.
 * A display line is different from a paragraph. Paragraphs are
 * separated by newlines or other paragraph separator characters.
 * Display lines are created by line-wrapping a paragraph. If
 * wrapping is turned off, display lines and paragraphs will be the
 * same. Display lines are divided differently for each view, since
 * they depend on the view’s width; paragraphs are the same in all
 * views, since they depend on the contents of the #GtkTextBuffer.
 *
 * @param iter a #GtkTextIter
 * @return %TRUE if @iter was moved and is not on the end iterator
 */
- (bool)backwardDisplayLine:(GtkTextIter*)iter;

/**
 * Moves the given @iter backward to the next display line start.
 * A display line is different from a paragraph. Paragraphs are
 * separated by newlines or other paragraph separator characters.
 * Display lines are created by line-wrapping a paragraph. If
 * wrapping is turned off, display lines and paragraphs will be the
 * same. Display lines are divided differently for each view, since
 * they depend on the view’s width; paragraphs are the same in all
 * views, since they depend on the contents of the #GtkTextBuffer.
 *
 * @param iter a #GtkTextIter
 * @return %TRUE if @iter was moved and is not on the end iterator
 */
- (bool)backwardDisplayLineStart:(GtkTextIter*)iter;

/**
 * Converts coordinate (@buffer_x, @buffer_y) to coordinates for the window
 * @win, and stores the result in (@window_x, @window_y).
 * 
 * Note that you can’t convert coordinates for a nonexisting window (see
 * gtk_text_view_set_border_window_size()).
 *
 * @param win a #GtkTextWindowType, except %GTK_TEXT_WINDOW_PRIVATE
 * @param bufferX buffer x coordinate
 * @param bufferY buffer y coordinate
 * @param windowX window x coordinate return location or %NULL
 * @param windowY window y coordinate return location or %NULL
 */
- (void)bufferToWindowCoordsWithWin:(GtkTextWindowType)win bufferX:(gint)bufferX bufferY:(gint)bufferY windowX:(gint*)windowX windowY:(gint*)windowY;

/**
 * Moves the given @iter forward by one display (wrapped) line.
 * A display line is different from a paragraph. Paragraphs are
 * separated by newlines or other paragraph separator characters.
 * Display lines are created by line-wrapping a paragraph. If
 * wrapping is turned off, display lines and paragraphs will be the
 * same. Display lines are divided differently for each view, since
 * they depend on the view’s width; paragraphs are the same in all
 * views, since they depend on the contents of the #GtkTextBuffer.
 *
 * @param iter a #GtkTextIter
 * @return %TRUE if @iter was moved and is not on the end iterator
 */
- (bool)forwardDisplayLine:(GtkTextIter*)iter;

/**
 * Moves the given @iter forward to the next display line end.
 * A display line is different from a paragraph. Paragraphs are
 * separated by newlines or other paragraph separator characters.
 * Display lines are created by line-wrapping a paragraph. If
 * wrapping is turned off, display lines and paragraphs will be the
 * same. Display lines are divided differently for each view, since
 * they depend on the view’s width; paragraphs are the same in all
 * views, since they depend on the contents of the #GtkTextBuffer.
 *
 * @param iter a #GtkTextIter
 * @return %TRUE if @iter was moved and is not on the end iterator
 */
- (bool)forwardDisplayLineEnd:(GtkTextIter*)iter;

/**
 * Returns whether pressing the Tab key inserts a tab characters.
 * gtk_text_view_set_accepts_tab().
 *
 * @return %TRUE if pressing the Tab key inserts a tab character,
 *   %FALSE if pressing the Tab key moves the keyboard focus.
 */
- (bool)acceptsTab;

/**
 * Gets the width of the specified border window. See
 * gtk_text_view_set_border_window_size().
 *
 * @param type window to return size from
 * @return width of window
 */
- (gint)borderWindowSize:(GtkTextWindowType)type;

/**
 * Gets the bottom margin for text in the @text_view.
 *
 * @return bottom margin in pixels
 */
- (gint)bottomMargin;

/**
 * Returns the #GtkTextBuffer being displayed by this text view.
 * The reference count on the buffer is not incremented; the caller
 * of this function won’t own a new reference.
 *
 * @return a #GtkTextBuffer
 */
- (OGTKTextBuffer*)buffer;

/**
 * Given an @iter within a text layout, determine the positions of the
 * strong and weak cursors if the insertion point is at that
 * iterator. The position of each cursor is stored as a zero-width
 * rectangle. The strong cursor location is the location where
 * characters of the directionality equal to the base direction of the
 * paragraph are inserted.  The weak cursor location is the location
 * where characters of the directionality opposite to the base
 * direction of the paragraph are inserted.
 * 
 * If @iter is %NULL, the actual cursor position is used.
 * 
 * Note that if @iter happens to be the actual cursor position, and
 * there is currently an IM preedit sequence being entered, the
 * returned locations will be adjusted to account for the preedit
 * cursor’s offset within the preedit sequence.
 * 
 * The rectangle position is in buffer coordinates; use
 * gtk_text_view_buffer_to_window_coords() to convert these
 * coordinates to coordinates for one of the windows in the text view.
 *
 * @param iter a #GtkTextIter
 * @param strong location to store the strong
 *     cursor position (may be %NULL)
 * @param weak location to store the weak
 *     cursor position (may be %NULL)
 */
- (void)cursorLocationsWithIter:(const GtkTextIter*)iter strong:(GdkRectangle*)strong weak:(GdkRectangle*)weak;

/**
 * Find out whether the cursor should be displayed.
 *
 * @return whether the insertion mark is visible
 */
- (bool)cursorVisible;

/**
 * Obtains a copy of the default text attributes. These are the
 * attributes used for text unless a tag overrides them.
 * You’d typically pass the default attributes in to
 * gtk_text_iter_get_attributes() in order to get the
 * attributes in effect at a given text position.
 * 
 * The return value is a copy owned by the caller of this function,
 * and should be freed with gtk_text_attributes_unref().
 *
 * @return a new #GtkTextAttributes
 */
- (GtkTextAttributes*)defaultAttributes;

/**
 * Returns the default editability of the #GtkTextView. Tags in the
 * buffer may override this setting for some ranges of text.
 *
 * @return whether text is editable by default
 */
- (bool)editable;

/**
 * Gets the horizontal-scrolling #GtkAdjustment.
 *
 * @return pointer to the horizontal #GtkAdjustment
 */
- (OGTKAdjustment*)hadjustment;

/**
 * Gets the default indentation of paragraphs in @text_view.
 * Tags in the view’s buffer may override the default.
 * The indentation may be negative.
 *
 * @return number of pixels of indentation
 */
- (gint)indent;

/**
 * Gets the value of the #GtkTextView:input-hints property.
 *
 * @return
 */
- (GtkInputHints)inputHints;

/**
 * Gets the value of the #GtkTextView:input-purpose property.
 *
 * @return
 */
- (GtkInputPurpose)inputPurpose;

/**
 * Retrieves the iterator at buffer coordinates @x and @y. Buffer
 * coordinates are coordinates for the entire buffer, not just the
 * currently-displayed portion.  If you have coordinates from an
 * event, you have to convert those to buffer coordinates with
 * gtk_text_view_window_to_buffer_coords().
 *
 * @param iter a #GtkTextIter
 * @param x x position, in buffer coordinates
 * @param y y position, in buffer coordinates
 * @return %TRUE if the position is over text
 */
- (bool)iterAtLocationWithIter:(GtkTextIter*)iter x:(gint)x y:(gint)y;

/**
 * Retrieves the iterator pointing to the character at buffer
 * coordinates @x and @y. Buffer coordinates are coordinates for
 * the entire buffer, not just the currently-displayed portion.
 * If you have coordinates from an event, you have to convert
 * those to buffer coordinates with
 * gtk_text_view_window_to_buffer_coords().
 * 
 * Note that this is different from gtk_text_view_get_iter_at_location(),
 * which returns cursor locations, i.e. positions between
 * characters.
 *
 * @param iter a #GtkTextIter
 * @param trailing if non-%NULL, location to store an integer indicating where
 *    in the grapheme the user clicked. It will either be
 *    zero, or the number of characters in the grapheme.
 *    0 represents the trailing edge of the grapheme.
 * @param x x position, in buffer coordinates
 * @param y y position, in buffer coordinates
 * @return %TRUE if the position is over text
 */
- (bool)iterAtPositionWithIter:(GtkTextIter*)iter trailing:(gint*)trailing x:(gint)x y:(gint)y;

/**
 * Gets a rectangle which roughly contains the character at @iter.
 * The rectangle position is in buffer coordinates; use
 * gtk_text_view_buffer_to_window_coords() to convert these
 * coordinates to coordinates for one of the windows in the text view.
 *
 * @param iter a #GtkTextIter
 * @param location bounds of the character at @iter
 */
- (void)iterLocationWithIter:(const GtkTextIter*)iter location:(GdkRectangle*)location;

/**
 * Gets the default justification of paragraphs in @text_view.
 * Tags in the buffer may override the default.
 *
 * @return default justification
 */
- (GtkJustification)justification;

/**
 * Gets the default left margin size of paragraphs in the @text_view.
 * Tags in the buffer may override the default.
 *
 * @return left margin in pixels
 */
- (gint)leftMargin;

/**
 * Gets the #GtkTextIter at the start of the line containing
 * the coordinate @y. @y is in buffer coordinates, convert from
 * window coordinates with gtk_text_view_window_to_buffer_coords().
 * If non-%NULL, @line_top will be filled with the coordinate of the top
 * edge of the line.
 *
 * @param targetIter a #GtkTextIter
 * @param y a y coordinate
 * @param lineTop return location for top coordinate of the line
 */
- (void)lineAtYWithTargetIter:(GtkTextIter*)targetIter y:(gint)y lineTop:(gint*)lineTop;

/**
 * Gets the y coordinate of the top of the line containing @iter,
 * and the height of the line. The coordinate is a buffer coordinate;
 * convert to window coordinates with gtk_text_view_buffer_to_window_coords().
 *
 * @param iter a #GtkTextIter
 * @param y return location for a y coordinate
 * @param height return location for a height
 */
- (void)lineYrangeWithIter:(const GtkTextIter*)iter y:(gint*)y height:(gint*)height;

/**
 * Gets the value of the #GtkTextView:monospace property.
 *
 * @return %TRUE if monospace fonts are desired
 */
- (bool)monospace;

/**
 * Returns whether the #GtkTextView is in overwrite mode or not.
 *
 * @return whether @text_view is in overwrite mode or not.
 */
- (bool)overwrite;

/**
 * Gets the default number of pixels to put above paragraphs.
 * Adding this function with gtk_text_view_get_pixels_below_lines()
 * is equal to the line space between each paragraph.
 *
 * @return default number of pixels above paragraphs
 */
- (gint)pixelsAboveLines;

/**
 * Gets the value set by gtk_text_view_set_pixels_below_lines().
 * 
 * The line space is the sum of the value returned by this function and the
 * value returned by gtk_text_view_get_pixels_above_lines().
 *
 * @return default number of blank pixels below paragraphs
 */
- (gint)pixelsBelowLines;

/**
 * Gets the value set by gtk_text_view_set_pixels_inside_wrap().
 *
 * @return default number of pixels of blank space between wrapped lines
 */
- (gint)pixelsInsideWrap;

/**
 * Gets the default right margin for text in @text_view. Tags
 * in the buffer may override the default.
 *
 * @return right margin in pixels
 */
- (gint)rightMargin;

/**
 * Gets the default tabs for @text_view. Tags in the buffer may
 * override the defaults. The returned array will be %NULL if
 * “standard” (8-space) tabs are used. Free the return value
 * with pango_tab_array_free().
 *
 * @return copy of default tab array, or %NULL if
 *    “standard" tabs are used; must be freed with pango_tab_array_free().
 */
- (PangoTabArray*)tabs;

/**
 * Gets the top margin for text in the @text_view.
 *
 * @return top margin in pixels
 */
- (gint)topMargin;

/**
 * Gets the vertical-scrolling #GtkAdjustment.
 *
 * @return pointer to the vertical #GtkAdjustment
 */
- (OGTKAdjustment*)vadjustment;

/**
 * Fills @visible_rect with the currently-visible
 * region of the buffer, in buffer coordinates. Convert to window coordinates
 * with gtk_text_view_buffer_to_window_coords().
 *
 * @param visibleRect rectangle to fill
 */
- (void)visibleRect:(GdkRectangle*)visibleRect;

/**
 * Retrieves the #GdkWindow corresponding to an area of the text view;
 * possible windows include the overall widget window, child windows
 * on the left, right, top, bottom, and the window that displays the
 * text buffer. Windows are %NULL and nonexistent if their width or
 * height is 0, and are nonexistent before the widget has been
 * realized.
 *
 * @param win window to get
 * @return a #GdkWindow, or %NULL
 */
- (OGGdkWindow*)window:(GtkTextWindowType)win;

/**
 * Usually used to find out which window an event corresponds to.
 * 
 * If you connect to an event signal on @text_view, this function
 * should be called on `event->window` to see which window it was.
 *
 * @param window a window type
 * @return the window type.
 */
- (GtkTextWindowType)windowType:(OGGdkWindow*)window;

/**
 * Gets the line wrapping for the view.
 *
 * @return the line wrap setting
 */
- (GtkWrapMode)wrapMode;

/**
 * Allow the #GtkTextView input method to internally handle key press
 * and release events. If this function returns %TRUE, then no further
 * processing should be done for this key event. See
 * gtk_im_context_filter_keypress().
 * 
 * Note that you are expected to call this function from your handler
 * when overriding key event handling. This is needed in the case when
 * you need to insert your own key handling between the input method
 * and the default key event handling of the #GtkTextView.
 * 
 * |[<!-- language="C" -->
 * static gboolean
 * gtk_foo_bar_key_press_event (GtkWidget   *widget,
 *                              GdkEventKey *event)
 * {
 *   guint keyval;
 * 
 *   gdk_event_get_keyval ((GdkEvent*)event, &keyval);
 * 
 *   if (keyval == GDK_KEY_Return || keyval == GDK_KEY_KP_Enter)
 *     {
 *       if (gtk_text_view_im_context_filter_keypress (GTK_TEXT_VIEW (widget), event))
 *         return TRUE;
 *     }
 * 
 *   // Do some stuff
 * 
 *   return GTK_WIDGET_CLASS (gtk_foo_bar_parent_class)->key_press_event (widget, event);
 * }
 * ]|
 *
 * @param event the key event
 * @return %TRUE if the input method handled the key event.
 */
- (bool)imContextFilterKeypress:(GdkEventKey*)event;

/**
 * Updates the position of a child, as for gtk_text_view_add_child_in_window().
 *
 * @param child child widget already added to the text view
 * @param xpos new X position in window coordinates
 * @param ypos new Y position in window coordinates
 */
- (void)moveChildWithChild:(OGTKWidget*)child xpos:(gint)xpos ypos:(gint)ypos;

/**
 * Moves a mark within the buffer so that it's
 * located within the currently-visible text area.
 *
 * @param mark a #GtkTextMark
 * @return %TRUE if the mark moved (wasn’t already onscreen)
 */
- (bool)moveMarkOnscreen:(OGTKTextMark*)mark;

/**
 * Move the iterator a given number of characters visually, treating
 * it as the strong cursor position. If @count is positive, then the
 * new strong cursor position will be @count positions to the right of
 * the old cursor position. If @count is negative then the new strong
 * cursor position will be @count positions to the left of the old
 * cursor position.
 * 
 * In the presence of bi-directional text, the correspondence
 * between logical and visual order will depend on the direction
 * of the current run, and there may be jumps when the cursor
 * is moved off of the end of a run.
 *
 * @param iter a #GtkTextIter
 * @param count number of characters to move (negative moves left,
 *    positive moves right)
 * @return %TRUE if @iter moved and is not on the end iterator
 */
- (bool)moveVisuallyWithIter:(GtkTextIter*)iter count:(gint)count;

/**
 * Moves the cursor to the currently visible region of the
 * buffer, it it isn’t there already.
 *
 * @return %TRUE if the cursor had to be moved.
 */
- (bool)placeCursorOnscreen;

/**
 * Ensures that the cursor is shown (i.e. not in an 'off' blink
 * interval) and resets the time that it will stay blinking (or
 * visible, in case blinking is disabled).
 * 
 * This function should be called in response to user input
 * (e.g. from derived classes that override the textview's
 * #GtkWidget::key-press-event handler).
 *
 */
- (void)resetCursorBlink;

/**
 * Reset the input method context of the text view if needed.
 * 
 * This can be necessary in the case where modifying the buffer
 * would confuse on-going input method behavior.
 *
 */
- (void)resetImContext;

/**
 * Scrolls @text_view the minimum distance such that @mark is contained
 * within the visible area of the widget.
 *
 * @param mark a mark in the buffer for @text_view
 */
- (void)scrollMarkOnscreen:(OGTKTextMark*)mark;

/**
 * Scrolls @text_view so that @iter is on the screen in the position
 * indicated by @xalign and @yalign. An alignment of 0.0 indicates
 * left or top, 1.0 indicates right or bottom, 0.5 means center.
 * If @use_align is %FALSE, the text scrolls the minimal distance to
 * get the mark onscreen, possibly not scrolling at all. The effective
 * screen for purposes of this function is reduced by a margin of size
 * @within_margin.
 * 
 * Note that this function uses the currently-computed height of the
 * lines in the text buffer. Line heights are computed in an idle
 * handler; so this function may not have the desired effect if it’s
 * called before the height computations. To avoid oddness, consider
 * using gtk_text_view_scroll_to_mark() which saves a point to be
 * scrolled to after line validation.
 *
 * @param iter a #GtkTextIter
 * @param withinMargin margin as a [0.0,0.5) fraction of screen size
 * @param useAlign whether to use alignment arguments (if %FALSE,
 *    just get the mark onscreen)
 * @param xalign horizontal alignment of mark within visible area
 * @param yalign vertical alignment of mark within visible area
 * @return %TRUE if scrolling occurred
 */
- (bool)scrollToIterWithIter:(GtkTextIter*)iter withinMargin:(gdouble)withinMargin useAlign:(bool)useAlign xalign:(gdouble)xalign yalign:(gdouble)yalign;

/**
 * Scrolls @text_view so that @mark is on the screen in the position
 * indicated by @xalign and @yalign. An alignment of 0.0 indicates
 * left or top, 1.0 indicates right or bottom, 0.5 means center.
 * If @use_align is %FALSE, the text scrolls the minimal distance to
 * get the mark onscreen, possibly not scrolling at all. The effective
 * screen for purposes of this function is reduced by a margin of size
 * @within_margin.
 *
 * @param mark a #GtkTextMark
 * @param withinMargin margin as a [0.0,0.5) fraction of screen size
 * @param useAlign whether to use alignment arguments (if %FALSE, just
 *    get the mark onscreen)
 * @param xalign horizontal alignment of mark within visible area
 * @param yalign vertical alignment of mark within visible area
 */
- (void)scrollToMarkWithMark:(OGTKTextMark*)mark withinMargin:(gdouble)withinMargin useAlign:(bool)useAlign xalign:(gdouble)xalign yalign:(gdouble)yalign;

/**
 * Sets the behavior of the text widget when the Tab key is pressed.
 * If @accepts_tab is %TRUE, a tab character is inserted. If @accepts_tab
 * is %FALSE the keyboard focus is moved to the next widget in the focus
 * chain.
 *
 * @param acceptsTab %TRUE if pressing the Tab key should insert a tab
 *    character, %FALSE, if pressing the Tab key should move the
 *    keyboard focus.
 */
- (void)setAcceptsTab:(bool)acceptsTab;

/**
 * Sets the width of %GTK_TEXT_WINDOW_LEFT or %GTK_TEXT_WINDOW_RIGHT,
 * or the height of %GTK_TEXT_WINDOW_TOP or %GTK_TEXT_WINDOW_BOTTOM.
 * Automatically destroys the corresponding window if the size is set
 * to 0, and creates the window if the size is set to non-zero.  This
 * function can only be used for the “border windows”, and it won’t
 * work with %GTK_TEXT_WINDOW_WIDGET, %GTK_TEXT_WINDOW_TEXT, or
 * %GTK_TEXT_WINDOW_PRIVATE.
 *
 * @param type window to affect
 * @param size width or height of the window
 */
- (void)setBorderWindowSizeWithType:(GtkTextWindowType)type size:(gint)size;

/**
 * Sets the bottom margin for text in @text_view.
 * 
 * Note that this function is confusingly named.
 * In CSS terms, the value set here is padding.
 *
 * @param bottomMargin bottom margin in pixels
 */
- (void)setBottomMargin:(gint)bottomMargin;

/**
 * Sets @buffer as the buffer being displayed by @text_view. The previous
 * buffer displayed by the text view is unreferenced, and a reference is
 * added to @buffer. If you owned a reference to @buffer before passing it
 * to this function, you must remove that reference yourself; #GtkTextView
 * will not “adopt” it.
 *
 * @param buffer a #GtkTextBuffer
 */
- (void)setBuffer:(OGTKTextBuffer*)buffer;

/**
 * Toggles whether the insertion point should be displayed. A buffer with
 * no editable text probably shouldn’t have a visible cursor, so you may
 * want to turn the cursor off.
 * 
 * Note that this property may be overridden by the
 * #GtkSettings:gtk-keynave-use-caret settings.
 *
 * @param setting whether to show the insertion cursor
 */
- (void)setCursorVisible:(bool)setting;

/**
 * Sets the default editability of the #GtkTextView. You can override
 * this default setting with tags in the buffer, using the “editable”
 * attribute of tags.
 *
 * @param setting whether it’s editable
 */
- (void)setEditable:(bool)setting;

/**
 * Sets the default indentation for paragraphs in @text_view.
 * Tags in the buffer may override the default.
 *
 * @param indent indentation in pixels
 */
- (void)setIndent:(gint)indent;

/**
 * Sets the #GtkTextView:input-hints property, which
 * allows input methods to fine-tune their behaviour.
 *
 * @param hints the hints
 */
- (void)setInputHints:(GtkInputHints)hints;

/**
 * Sets the #GtkTextView:input-purpose property which
 * can be used by on-screen keyboards and other input
 * methods to adjust their behaviour.
 *
 * @param purpose the purpose
 */
- (void)setInputPurpose:(GtkInputPurpose)purpose;

/**
 * Sets the default justification of text in @text_view.
 * Tags in the view’s buffer may override the default.
 *
 * @param justification justification
 */
- (void)setJustification:(GtkJustification)justification;

/**
 * Sets the default left margin for text in @text_view.
 * Tags in the buffer may override the default.
 * 
 * Note that this function is confusingly named.
 * In CSS terms, the value set here is padding.
 *
 * @param leftMargin left margin in pixels
 */
- (void)setLeftMargin:(gint)leftMargin;

/**
 * Sets the #GtkTextView:monospace property, which
 * indicates that the text view should use monospace
 * fonts.
 *
 * @param monospace %TRUE to request monospace styling
 */
- (void)setMonospace:(bool)monospace;

/**
 * Changes the #GtkTextView overwrite mode.
 *
 * @param overwrite %TRUE to turn on overwrite mode, %FALSE to turn it off
 */
- (void)setOverwrite:(bool)overwrite;

/**
 * Sets the default number of blank pixels above paragraphs in @text_view.
 * Tags in the buffer for @text_view may override the defaults.
 *
 * @param pixelsAboveLines pixels above paragraphs
 */
- (void)setPixelsAboveLines:(gint)pixelsAboveLines;

/**
 * Sets the default number of pixels of blank space
 * to put below paragraphs in @text_view. May be overridden
 * by tags applied to @text_view’s buffer.
 *
 * @param pixelsBelowLines pixels below paragraphs
 */
- (void)setPixelsBelowLines:(gint)pixelsBelowLines;

/**
 * Sets the default number of pixels of blank space to leave between
 * display/wrapped lines within a paragraph. May be overridden by
 * tags in @text_view’s buffer.
 *
 * @param pixelsInsideWrap default number of pixels between wrapped lines
 */
- (void)setPixelsInsideWrap:(gint)pixelsInsideWrap;

/**
 * Sets the default right margin for text in the text view.
 * Tags in the buffer may override the default.
 * 
 * Note that this function is confusingly named.
 * In CSS terms, the value set here is padding.
 *
 * @param rightMargin right margin in pixels
 */
- (void)setRightMargin:(gint)rightMargin;

/**
 * Sets the default tab stops for paragraphs in @text_view.
 * Tags in the buffer may override the default.
 *
 * @param tabs tabs as a #PangoTabArray
 */
- (void)setTabs:(PangoTabArray*)tabs;

/**
 * Sets the top margin for text in @text_view.
 * 
 * Note that this function is confusingly named.
 * In CSS terms, the value set here is padding.
 *
 * @param topMargin top margin in pixels
 */
- (void)setTopMargin:(gint)topMargin;

/**
 * Sets the line wrapping for the view.
 *
 * @param wrapMode a #GtkWrapMode
 */
- (void)setWrapMode:(GtkWrapMode)wrapMode;

/**
 * Determines whether @iter is at the start of a display line.
 * See gtk_text_view_forward_display_line() for an explanation of
 * display lines vs. paragraphs.
 *
 * @param iter a #GtkTextIter
 * @return %TRUE if @iter begins a wrapped line
 */
- (bool)startsDisplayLine:(const GtkTextIter*)iter;

/**
 * Converts coordinates on the window identified by @win to buffer
 * coordinates, storing the result in (@buffer_x,@buffer_y).
 * 
 * Note that you can’t convert coordinates for a nonexisting window (see
 * gtk_text_view_set_border_window_size()).
 *
 * @param win a #GtkTextWindowType except %GTK_TEXT_WINDOW_PRIVATE
 * @param windowX window x coordinate
 * @param windowY window y coordinate
 * @param bufferX buffer x coordinate return location or %NULL
 * @param bufferY buffer y coordinate return location or %NULL
 */
- (void)windowToBufferCoordsWithWin:(GtkTextWindowType)win windowX:(gint)windowX windowY:(gint)windowY bufferX:(gint*)bufferX bufferY:(gint*)bufferY;

@end