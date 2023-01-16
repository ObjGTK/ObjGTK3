/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWidget.h"

@class OGTKAdjustment;
@class OGPangoLayout;
@class OGTKEntryCompletion;
@class OGGdkPixbuf;
@class OGTKEntryBuffer;

/**
 * The #GtkEntry widget is a single line text entry
 * widget. A fairly large set of key bindings are supported
 * by default. If the entered text is longer than the allocation
 * of the widget, the widget will scroll so that the cursor
 * position is visible.
 * 
 * When using an entry for passwords and other sensitive information,
 * it can be put into “password mode” using gtk_entry_set_visibility().
 * In this mode, entered text is displayed using a “invisible” character.
 * By default, GTK+ picks the best invisible character that is available
 * in the current font, but it can be changed with
 * gtk_entry_set_invisible_char(). Since 2.16, GTK+ displays a warning
 * when Caps Lock or input methods might interfere with entering text in
 * a password entry. The warning can be turned off with the
 * #GtkEntry:caps-lock-warning property.
 * 
 * Since 2.16, GtkEntry has the ability to display progress or activity
 * information behind the text. To make an entry display such information,
 * use gtk_entry_set_progress_fraction() or gtk_entry_set_progress_pulse_step().
 * 
 * Additionally, GtkEntry can show icons at either side of the entry. These
 * icons can be activatable by clicking, can be set up as drag source and
 * can have tooltips. To add an icon, use gtk_entry_set_icon_from_gicon() or
 * one of the various other functions that set an icon from a stock id, an
 * icon name or a pixbuf. To trigger an action when the user clicks an icon,
 * connect to the #GtkEntry::icon-press signal. To allow DND operations
 * from an icon, use gtk_entry_set_icon_drag_source(). To set a tooltip on
 * an icon, use gtk_entry_set_icon_tooltip_text() or the corresponding function
 * for markup.
 * 
 * Note that functionality or information that is only available by clicking
 * on an icon in an entry may not be accessible at all to users which are not
 * able to use a mouse or other pointing device. It is therefore recommended
 * that any such functionality should also be available by other means, e.g.
 * via the context menu of the entry.
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * entry[.read-only][.flat][.warning][.error]
 * ├── image.left
 * ├── image.right
 * ├── undershoot.left
 * ├── undershoot.right
 * ├── [selection]
 * ├── [progress[.pulse]]
 * ╰── [window.popup]
 * ]|
 * 
 * GtkEntry has a main node with the name entry. Depending on the properties
 * of the entry, the style classes .read-only and .flat may appear. The style
 * classes .warning and .error may also be used with entries.
 * 
 * When the entry shows icons, it adds subnodes with the name image and the
 * style class .left or .right, depending on where the icon appears.
 * 
 * When the entry has a selection, it adds a subnode with the name selection.
 * 
 * When the entry shows progress, it adds a subnode with the name progress.
 * The node has the style class .pulse when the shown progress is pulsing.
 * 
 * The CSS node for a context menu is added as a subnode below entry as well.
 * 
 * The undershoot nodes are used to draw the underflow indication when content
 * is scrolled out of view. These nodes get the .left and .right style classes
 * added depending on where the indication is drawn.
 * 
 * When touch is used and touch selection handles are shown, they are using
 * CSS nodes with name cursor-handle. They get the .top or .bottom style class
 * depending on where they are shown in relation to the selection. If there is
 * just a single handle for the text cursor, it gets the style class
 * .insertion-cursor.
 *
 */
@interface OGTKEntry : OGTKWidget
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initWithBuffer:(OGTKEntryBuffer*)buffer;

/**
 * Methods
 */

- (GtkEntry*)ENTRY;

/**
 * Retrieves the value set by gtk_entry_set_activates_default().
 *
 * @return %TRUE if the entry will activate the default widget
 */
- (bool)activatesDefault;

/**
 * Gets the value set by gtk_entry_set_alignment().
 *
 * @return the alignment
 */
- (gfloat)alignment;

/**
 * Gets the attribute list that was set on the entry using
 * gtk_entry_set_attributes(), if any.
 *
 * @return the attribute list, or %NULL
 *     if none was set.
 */
- (PangoAttrList*)attributes;

/**
 * Get the #GtkEntryBuffer object which holds the text for
 * this widget.
 *
 * @return A #GtkEntryBuffer object.
 */
- (OGTKEntryBuffer*)buffer;

/**
 * Returns the auxiliary completion object currently in use by @entry.
 *
 * @return The auxiliary completion object currently
 *     in use by @entry.
 */
- (OGTKEntryCompletion*)completion;

/**
 * Returns the index of the icon which is the source of the current
 * DND operation, or -1.
 * 
 * This function is meant to be used in a #GtkWidget::drag-data-get
 * callback.
 *
 * @return index of the icon which is the source of the current
 *          DND operation, or -1.
 */
- (gint)currentIconDragSource;

/**
 * Retrieves the horizontal cursor adjustment for the entry.
 * See gtk_entry_set_cursor_hadjustment().
 *
 * @return the horizontal cursor adjustment, or %NULL
 *   if none has been set.
 */
- (OGTKAdjustment*)cursorHadjustment;

/**
 * Gets the value set by gtk_entry_set_has_frame().
 *
 * @return whether the entry has a beveled frame
 */
- (bool)hasFrame;

/**
 * Returns whether the icon is activatable.
 *
 * @param iconPos Icon position
 * @return %TRUE if the icon is activatable.
 */
- (bool)iconActivatable:(GtkEntryIconPosition)iconPos;

/**
 * Gets the area where entry’s icon at @icon_pos is drawn.
 * This function is useful when drawing something to the
 * entry in a draw callback.
 * 
 * If the entry is not realized or has no icon at the given position,
 * @icon_area is filled with zeros. Otherwise, @icon_area will be filled
 * with the icon’s allocation, relative to @entry’s allocation.
 * 
 * See also gtk_entry_get_text_area()
 *
 * @param iconPos Icon position
 * @param iconArea Return location for the icon’s area
 */
- (void)iconAreaWithIconPos:(GtkEntryIconPosition)iconPos iconArea:(GdkRectangle*)iconArea;

/**
 * Finds the icon at the given position and return its index. The
 * position’s coordinates are relative to the @entry’s top left corner.
 * If @x, @y doesn’t lie inside an icon, -1 is returned.
 * This function is intended for use in a #GtkWidget::query-tooltip
 * signal handler.
 *
 * @param x the x coordinate of the position to find
 * @param y the y coordinate of the position to find
 * @return the index of the icon at the given position, or -1
 */
- (gint)iconAtPosWithX:(gint)x y:(gint)y;

/**
 * Retrieves the #GIcon used for the icon, or %NULL if there is
 * no icon or if the icon was set by some other method (e.g., by
 * stock, pixbuf, or icon name).
 *
 * @param iconPos Icon position
 * @return A #GIcon, or %NULL if no icon is set
 *     or if the icon is not a #GIcon
 */
- (GIcon*)iconGicon:(GtkEntryIconPosition)iconPos;

/**
 * Retrieves the icon name used for the icon, or %NULL if there is
 * no icon or if the icon was set by some other method (e.g., by
 * pixbuf, stock or gicon).
 *
 * @param iconPos Icon position
 * @return An icon name, or %NULL if no icon is set or if the icon
 *          wasn’t set from an icon name
 */
- (OFString*)iconName:(GtkEntryIconPosition)iconPos;

/**
 * Retrieves the image used for the icon.
 * 
 * Unlike the other methods of setting and getting icon data, this
 * method will work regardless of whether the icon was set using a
 * #GdkPixbuf, a #GIcon, a stock item, or an icon name.
 *
 * @param iconPos Icon position
 * @return A #GdkPixbuf, or %NULL if no icon is
 *     set for this position.
 */
- (OGGdkPixbuf*)iconPixbuf:(GtkEntryIconPosition)iconPos;

/**
 * Returns whether the icon appears sensitive or insensitive.
 *
 * @param iconPos Icon position
 * @return %TRUE if the icon is sensitive.
 */
- (bool)iconSensitive:(GtkEntryIconPosition)iconPos;

/**
 * Retrieves the stock id used for the icon, or %NULL if there is
 * no icon or if the icon was set by some other method (e.g., by
 * pixbuf, icon name or gicon).
 *
 * @param iconPos Icon position
 * @return A stock id, or %NULL if no icon is set or if the icon
 *          wasn’t set from a stock id
 */
- (OFString*)iconStock:(GtkEntryIconPosition)iconPos;

/**
 * Gets the type of representation being used by the icon
 * to store image data. If the icon has no image data,
 * the return value will be %GTK_IMAGE_EMPTY.
 *
 * @param iconPos Icon position
 * @return image representation being used
 */
- (GtkImageType)iconStorageType:(GtkEntryIconPosition)iconPos;

/**
 * Gets the contents of the tooltip on the icon at the specified
 * position in @entry.
 *
 * @param iconPos the icon position
 * @return the tooltip text, or %NULL. Free the returned
 *     string with g_free() when done.
 */
- (OFString*)iconTooltipMarkup:(GtkEntryIconPosition)iconPos;

/**
 * Gets the contents of the tooltip on the icon at the specified
 * position in @entry.
 *
 * @param iconPos the icon position
 * @return the tooltip text, or %NULL. Free the returned
 *     string with g_free() when done.
 */
- (OFString*)iconTooltipText:(GtkEntryIconPosition)iconPos;

/**
 * This function returns the entry’s #GtkEntry:inner-border property. See
 * gtk_entry_set_inner_border() for more information.
 *
 * @return the entry’s #GtkBorder, or
 *   %NULL if none was set.
 */
- (const GtkBorder*)innerBorder;

/**
 * Gets the value of the #GtkEntry:input-hints property.
 *
 * @return
 */
- (GtkInputHints)inputHints;

/**
 * Gets the value of the #GtkEntry:input-purpose property.
 *
 * @return
 */
- (GtkInputPurpose)inputPurpose;

/**
 * Retrieves the character displayed in place of the real characters
 * for entries with visibility set to false. See gtk_entry_set_invisible_char().
 *
 * @return the current invisible char, or 0, if the entry does not
 *               show invisible text at all.
 */
- (gunichar)invisibleChar;

/**
 * Gets the #PangoLayout used to display the entry.
 * The layout is useful to e.g. convert text positions to
 * pixel positions, in combination with gtk_entry_get_layout_offsets().
 * The returned layout is owned by the entry and must not be
 * modified or freed by the caller.
 * 
 * Keep in mind that the layout text may contain a preedit string, so
 * gtk_entry_layout_index_to_text_index() and
 * gtk_entry_text_index_to_layout_index() are needed to convert byte
 * indices in the layout to byte indices in the entry contents.
 *
 * @return the #PangoLayout for this entry
 */
- (OGPangoLayout*)layout;

/**
 * Obtains the position of the #PangoLayout used to render text
 * in the entry, in widget coordinates. Useful if you want to line
 * up the text in an entry with some other text, e.g. when using the
 * entry to implement editable cells in a sheet widget.
 * 
 * Also useful to convert mouse events into coordinates inside the
 * #PangoLayout, e.g. to take some action if some part of the entry text
 * is clicked.
 * 
 * Note that as the user scrolls around in the entry the offsets will
 * change; you’ll need to connect to the “notify::scroll-offset”
 * signal to track this. Remember when using the #PangoLayout
 * functions you need to convert to and from pixels using
 * PANGO_PIXELS() or #PANGO_SCALE.
 * 
 * Keep in mind that the layout text may contain a preedit string, so
 * gtk_entry_layout_index_to_text_index() and
 * gtk_entry_text_index_to_layout_index() are needed to convert byte
 * indices in the layout to byte indices in the entry contents.
 *
 * @param x location to store X offset of layout, or %NULL
 * @param y location to store Y offset of layout, or %NULL
 */
- (void)layoutOffsetsWithX:(gint*)x y:(gint*)y;

/**
 * Retrieves the maximum allowed length of the text in
 * @entry. See gtk_entry_set_max_length().
 * 
 * This is equivalent to getting @entry's #GtkEntryBuffer and
 * calling gtk_entry_buffer_get_max_length() on it.
 *
 * @return the maximum allowed number of characters
 *               in #GtkEntry, or 0 if there is no maximum.
 */
- (gint)maxLength;

/**
 * Retrieves the desired maximum width of @entry, in characters.
 * See gtk_entry_set_max_width_chars().
 *
 * @return the maximum width of the entry, in characters
 */
- (gint)maxWidthChars;

/**
 * Gets the value set by gtk_entry_set_overwrite_mode().
 *
 * @return whether the text is overwritten when typing.
 */
- (bool)overwriteMode;

/**
 * Retrieves the text that will be displayed when @entry is empty and unfocused
 *
 * @return a pointer to the placeholder text as a string. This string points to internally allocated
 * storage in the widget and must not be freed, modified or stored.
 */
- (OFString*)placeholderText;

/**
 * Returns the current fraction of the task that’s been completed.
 * See gtk_entry_set_progress_fraction().
 *
 * @return a fraction from 0.0 to 1.0
 */
- (gdouble)progressFraction;

/**
 * Retrieves the pulse step set with gtk_entry_set_progress_pulse_step().
 *
 * @return a fraction from 0.0 to 1.0
 */
- (gdouble)progressPulseStep;

/**
 * Gets the tabstops that were set on the entry using gtk_entry_set_tabs(), if
 * any.
 *
 * @return the tabstops, or %NULL if none was set.
 */
- (PangoTabArray*)tabs;

/**
 * Retrieves the contents of the entry widget.
 * See also gtk_editable_get_chars().
 * 
 * This is equivalent to getting @entry's #GtkEntryBuffer and calling
 * gtk_entry_buffer_get_text() on it.
 *
 * @return a pointer to the contents of the widget as a
 *      string. This string points to internally allocated
 *      storage in the widget and must not be freed, modified or
 *      stored.
 */
- (OFString*)text;

/**
 * Gets the area where the entry’s text is drawn. This function is
 * useful when drawing something to the entry in a draw callback.
 * 
 * If the entry is not realized, @text_area is filled with zeros.
 * 
 * See also gtk_entry_get_icon_area().
 *
 * @param textArea Return location for the text area.
 */
- (void)textArea:(GdkRectangle*)textArea;

/**
 * Retrieves the current length of the text in
 * @entry.
 * 
 * This is equivalent to getting @entry's #GtkEntryBuffer and
 * calling gtk_entry_buffer_get_length() on it.
 *
 * @return the current number of characters
 *               in #GtkEntry, or 0 if there are none.
 */
- (guint16)textLength;

/**
 * Retrieves whether the text in @entry is visible. See
 * gtk_entry_set_visibility().
 *
 * @return %TRUE if the text is currently visible
 */
- (bool)visibility;

/**
 * Gets the value set by gtk_entry_set_width_chars().
 *
 * @return number of chars to request space for, or negative if unset
 */
- (gint)widthChars;

/**
 * Causes @entry to have keyboard focus.
 * 
 * It behaves like gtk_widget_grab_focus(),
 * except that it doesn't select the contents of the entry.
 * You only want to call this on some special entries
 * which the user usually doesn't want to replace all text in,
 * such as search-as-you-type entries.
 *
 */
- (void)grabFocusWithoutSelecting;

/**
 * Allow the #GtkEntry input method to internally handle key press
 * and release events. If this function returns %TRUE, then no further
 * processing should be done for this key event. See
 * gtk_im_context_filter_keypress().
 * 
 * Note that you are expected to call this function from your handler
 * when overriding key event handling. This is needed in the case when
 * you need to insert your own key handling between the input method
 * and the default key event handling of the #GtkEntry.
 * See gtk_text_view_reset_im_context() for an example of use.
 *
 * @param event the key event
 * @return %TRUE if the input method handled the key event.
 */
- (bool)imContextFilterKeypress:(GdkEventKey*)event;

/**
 * Converts from a position in the entry’s #PangoLayout (returned by
 * gtk_entry_get_layout()) to a position in the entry contents
 * (returned by gtk_entry_get_text()).
 *
 * @param layoutIndex byte index into the entry layout text
 * @return byte index into the entry contents
 */
- (gint)layoutIndexToTextIndex:(gint)layoutIndex;

/**
 * Indicates that some progress is made, but you don’t know how much.
 * Causes the entry’s progress indicator to enter “activity mode,”
 * where a block bounces back and forth. Each call to
 * gtk_entry_progress_pulse() causes the block to move by a little bit
 * (the amount of movement per pulse is determined by
 * gtk_entry_set_progress_pulse_step()).
 *
 */
- (void)progressPulse;

/**
 * Reset the input method context of the entry if needed.
 * 
 * This can be necessary in the case where modifying the buffer
 * would confuse on-going input method behavior.
 *
 */
- (void)resetImContext;

/**
 * If @setting is %TRUE, pressing Enter in the @entry will activate the default
 * widget for the window containing the entry. This usually means that
 * the dialog box containing the entry will be closed, since the default
 * widget is usually one of the dialog buttons.
 * 
 * (For experts: if @setting is %TRUE, the entry calls
 * gtk_window_activate_default() on the window containing the entry, in
 * the default handler for the #GtkEntry::activate signal.)
 *
 * @param setting %TRUE to activate window’s default widget on Enter keypress
 */
- (void)setActivatesDefault:(bool)setting;

/**
 * Sets the alignment for the contents of the entry. This controls
 * the horizontal positioning of the contents when the displayed
 * text is shorter than the width of the entry.
 *
 * @param xalign The horizontal alignment, from 0 (left) to 1 (right).
 *          Reversed for RTL layouts
 */
- (void)setAlignment:(gfloat)xalign;

/**
 * Sets a #PangoAttrList; the attributes in the list are applied to the
 * entry text.
 *
 * @param attrs a #PangoAttrList
 */
- (void)setAttributes:(PangoAttrList*)attrs;

/**
 * Set the #GtkEntryBuffer object which holds the text for
 * this widget.
 *
 * @param buffer a #GtkEntryBuffer
 */
- (void)setBuffer:(OGTKEntryBuffer*)buffer;

/**
 * Sets @completion to be the auxiliary completion object to use with @entry.
 * All further configuration of the completion mechanism is done on
 * @completion using the #GtkEntryCompletion API. Completion is disabled if
 * @completion is set to %NULL.
 *
 * @param completion The #GtkEntryCompletion or %NULL
 */
- (void)setCompletion:(OGTKEntryCompletion*)completion;

/**
 * Hooks up an adjustment to the cursor position in an entry, so that when
 * the cursor is moved, the adjustment is scrolled to show that position.
 * See gtk_scrolled_window_get_hadjustment() for a typical way of obtaining
 * the adjustment.
 * 
 * The adjustment has to be in pixel units and in the same coordinate system
 * as the entry.
 *
 * @param adjustment an adjustment which should be adjusted when the cursor
 *              is moved, or %NULL
 */
- (void)setCursorHadjustment:(OGTKAdjustment*)adjustment;

/**
 * Sets whether the entry has a beveled frame around it.
 *
 * @param setting new value
 */
- (void)setHasFrame:(bool)setting;

/**
 * Sets whether the icon is activatable.
 *
 * @param iconPos Icon position
 * @param activatable %TRUE if the icon should be activatable
 */
- (void)setIconActivatableWithIconPos:(GtkEntryIconPosition)iconPos activatable:(bool)activatable;

/**
 * Sets up the icon at the given position so that GTK+ will start a drag
 * operation when the user clicks and drags the icon.
 * 
 * To handle the drag operation, you need to connect to the usual
 * #GtkWidget::drag-data-get (or possibly #GtkWidget::drag-data-delete)
 * signal, and use gtk_entry_get_current_icon_drag_source() in
 * your signal handler to find out if the drag was started from
 * an icon.
 * 
 * By default, GTK+ uses the icon as the drag icon. You can use the
 * #GtkWidget::drag-begin signal to set a different icon. Note that you
 * have to use g_signal_connect_after() to ensure that your signal handler
 * gets executed after the default handler.
 *
 * @param iconPos icon position
 * @param targetList the targets (data formats) in which the data can be provided
 * @param actions a bitmask of the allowed drag actions
 */
- (void)setIconDragSourceWithIconPos:(GtkEntryIconPosition)iconPos targetList:(GtkTargetList*)targetList actions:(GdkDragAction)actions;

/**
 * Sets the icon shown in the entry at the specified position
 * from the current icon theme.
 * If the icon isn’t known, a “broken image” icon will be displayed
 * instead.
 * 
 * If @icon is %NULL, no icon will be shown in the specified position.
 *
 * @param iconPos The position at which to set the icon
 * @param icon The icon to set, or %NULL
 */
- (void)setIconFromGiconWithIconPos:(GtkEntryIconPosition)iconPos icon:(GIcon*)icon;

/**
 * Sets the icon shown in the entry at the specified position
 * from the current icon theme.
 * 
 * If the icon name isn’t known, a “broken image” icon will be displayed
 * instead.
 * 
 * If @icon_name is %NULL, no icon will be shown in the specified position.
 *
 * @param iconPos The position at which to set the icon
 * @param iconName An icon name, or %NULL
 */
- (void)setIconFromIconNameWithIconPos:(GtkEntryIconPosition)iconPos iconName:(OFString*)iconName;

/**
 * Sets the icon shown in the specified position using a pixbuf.
 * 
 * If @pixbuf is %NULL, no icon will be shown in the specified position.
 *
 * @param iconPos Icon position
 * @param pixbuf A #GdkPixbuf, or %NULL
 */
- (void)setIconFromPixbufWithIconPos:(GtkEntryIconPosition)iconPos pixbuf:(OGGdkPixbuf*)pixbuf;

/**
 * Sets the icon shown in the entry at the specified position from
 * a stock image.
 * 
 * If @stock_id is %NULL, no icon will be shown in the specified position.
 *
 * @param iconPos Icon position
 * @param stockId The name of the stock item, or %NULL
 */
- (void)setIconFromStockWithIconPos:(GtkEntryIconPosition)iconPos stockId:(OFString*)stockId;

/**
 * Sets the sensitivity for the specified icon.
 *
 * @param iconPos Icon position
 * @param sensitive Specifies whether the icon should appear
 *             sensitive or insensitive
 */
- (void)setIconSensitiveWithIconPos:(GtkEntryIconPosition)iconPos sensitive:(bool)sensitive;

/**
 * Sets @tooltip as the contents of the tooltip for the icon at
 * the specified position. @tooltip is assumed to be marked up with
 * the [Pango text markup language][PangoMarkupFormat].
 * 
 * Use %NULL for @tooltip to remove an existing tooltip.
 * 
 * See also gtk_widget_set_tooltip_markup() and
 * gtk_entry_set_icon_tooltip_text().
 *
 * @param iconPos the icon position
 * @param tooltip the contents of the tooltip for the icon, or %NULL
 */
- (void)setIconTooltipMarkupWithIconPos:(GtkEntryIconPosition)iconPos tooltip:(OFString*)tooltip;

/**
 * Sets @tooltip as the contents of the tooltip for the icon
 * at the specified position.
 * 
 * Use %NULL for @tooltip to remove an existing tooltip.
 * 
 * See also gtk_widget_set_tooltip_text() and
 * gtk_entry_set_icon_tooltip_markup().
 * 
 * If you unset the widget tooltip via gtk_widget_set_tooltip_text() or
 * gtk_widget_set_tooltip_markup(), this sets GtkWidget:has-tooltip to %FALSE,
 * which suppresses icon tooltips too. You can resolve this by then calling
 * gtk_widget_set_has_tooltip() to set GtkWidget:has-tooltip back to %TRUE, or
 * setting at least one non-empty tooltip on any icon achieves the same result.
 *
 * @param iconPos the icon position
 * @param tooltip the contents of the tooltip for the icon, or %NULL
 */
- (void)setIconTooltipTextWithIconPos:(GtkEntryIconPosition)iconPos tooltip:(OFString*)tooltip;

/**
 * Sets %entry’s inner-border property to @border, or clears it if %NULL
 * is passed. The inner-border is the area around the entry’s text, but
 * inside its frame.
 * 
 * If set, this property overrides the inner-border style property.
 * Overriding the style-provided border is useful when you want to do
 * in-place editing of some text in a canvas or list widget, where
 * pixel-exact positioning of the entry is important.
 *
 * @param border a #GtkBorder, or %NULL
 */
- (void)setInnerBorder:(const GtkBorder*)border;

/**
 * Sets the #GtkEntry:input-hints property, which
 * allows input methods to fine-tune their behaviour.
 *
 * @param hints the hints
 */
- (void)setInputHints:(GtkInputHints)hints;

/**
 * Sets the #GtkEntry:input-purpose property which
 * can be used by on-screen keyboards and other input
 * methods to adjust their behaviour.
 *
 * @param purpose the purpose
 */
- (void)setInputPurpose:(GtkInputPurpose)purpose;

/**
 * Sets the character to use in place of the actual text when
 * gtk_entry_set_visibility() has been called to set text visibility
 * to %FALSE. i.e. this is the character used in “password mode” to
 * show the user how many characters have been typed. By default, GTK+
 * picks the best invisible char available in the current font. If you
 * set the invisible char to 0, then the user will get no feedback
 * at all; there will be no text on the screen as they type.
 *
 * @param ch a Unicode character
 */
- (void)setInvisibleChar:(gunichar)ch;

/**
 * Sets the maximum allowed length of the contents of the widget. If
 * the current contents are longer than the given length, then they
 * will be truncated to fit.
 * 
 * This is equivalent to getting @entry's #GtkEntryBuffer and
 * calling gtk_entry_buffer_set_max_length() on it.
 * ]|
 *
 * @param max the maximum length of the entry, or 0 for no maximum.
 *   (other than the maximum length of entries.) The value passed in will
 *   be clamped to the range 0-65536.
 */
- (void)setMaxLength:(gint)max;

/**
 * Sets the desired maximum width in characters of @entry.
 *
 * @param nchars the new desired maximum width, in characters
 */
- (void)setMaxWidthChars:(gint)nchars;

/**
 * Sets whether the text is overwritten when typing in the #GtkEntry.
 *
 * @param overwrite new value
 */
- (void)setOverwriteMode:(bool)overwrite;

/**
 * Sets text to be displayed in @entry when it is empty and unfocused.
 * This can be used to give a visual hint of the expected contents of
 * the #GtkEntry.
 * 
 * Note that since the placeholder text gets removed when the entry
 * received focus, using this feature is a bit problematic if the entry
 * is given the initial focus in a window. Sometimes this can be
 * worked around by delaying the initial focus setting until the
 * first key event arrives.
 *
 * @param text a string to be displayed when @entry is empty and unfocused, or %NULL
 */
- (void)setPlaceholderText:(OFString*)text;

/**
 * Causes the entry’s progress indicator to “fill in” the given
 * fraction of the bar. The fraction should be between 0.0 and 1.0,
 * inclusive.
 *
 * @param fraction fraction of the task that’s been completed
 */
- (void)setProgressFraction:(gdouble)fraction;

/**
 * Sets the fraction of total entry width to move the progress
 * bouncing block for each call to gtk_entry_progress_pulse().
 *
 * @param fraction fraction between 0.0 and 1.0
 */
- (void)setProgressPulseStep:(gdouble)fraction;

/**
 * Sets a #PangoTabArray; the tabstops in the array are applied to the entry
 * text.
 *
 * @param tabs a #PangoTabArray
 */
- (void)setTabs:(PangoTabArray*)tabs;

/**
 * Sets the text in the widget to the given
 * value, replacing the current contents.
 * 
 * See gtk_entry_buffer_set_text().
 *
 * @param text the new text
 */
- (void)setText:(OFString*)text;

/**
 * Sets whether the contents of the entry are visible or not.
 * When visibility is set to %FALSE, characters are displayed
 * as the invisible char, and will also appear that way when
 * the text in the entry widget is copied elsewhere.
 * 
 * By default, GTK+ picks the best invisible character available
 * in the current font, but it can be changed with
 * gtk_entry_set_invisible_char().
 * 
 * Note that you probably want to set #GtkEntry:input-purpose
 * to %GTK_INPUT_PURPOSE_PASSWORD or %GTK_INPUT_PURPOSE_PIN to
 * inform input methods about the purpose of this entry,
 * in addition to setting visibility to %FALSE.
 *
 * @param visible %TRUE if the contents of the entry are displayed
 *           as plaintext
 */
- (void)setVisibility:(bool)visible;

/**
 * Changes the size request of the entry to be about the right size
 * for @n_chars characters. Note that it changes the size
 * request, the size can still be affected by
 * how you pack the widget into containers. If @n_chars is -1, the
 * size reverts to the default entry size.
 *
 * @param nchars width in chars
 */
- (void)setWidthChars:(gint)nchars;

/**
 * Converts from a position in the entry contents (returned
 * by gtk_entry_get_text()) to a position in the
 * entry’s #PangoLayout (returned by gtk_entry_get_layout(),
 * with text retrieved via pango_layout_get_text()).
 *
 * @param textIndex byte index into the entry contents
 * @return byte index into the entry layout text
 */
- (gint)textIndexToLayoutIndex:(gint)textIndex;

/**
 * Unsets the invisible char previously set with
 * gtk_entry_set_invisible_char(). So that the
 * default invisible char is used again.
 *
 */
- (void)unsetInvisibleChar;

@end