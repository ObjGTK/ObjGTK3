/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>
#include <gtk/gtk.h>

#import <OGAtk/OGAtkMisc.h>

@class OGTKWidget;
@class OGPangoLayout;

/**
 * The #GtkLabel widget displays a small amount of text. As the name
 * implies, most labels are used to label another widget such as a
 * #GtkButton, a #GtkMenuItem, or a #GtkComboBox.
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * label
 * ├── [selection]
 * ├── [link]
 * ┊
 * ╰── [link]
 * ]|
 * 
 * GtkLabel has a single CSS node with the name label. A wide variety
 * of style classes may be applied to labels, such as .title, .subtitle,
 * .dim-label, etc. In the #GtkShortcutsWindow, labels are used wth the
 * .keycap style class.
 * 
 * If the label has a selection, it gets a subnode with name selection.
 * 
 * If the label has links, there is one subnode per link. These subnodes
 * carry the link or visited state depending on whether they have been
 * visited.
 * 
 * # GtkLabel as GtkBuildable
 * 
 * The GtkLabel implementation of the GtkBuildable interface supports a
 * custom <attributes> element, which supports any number of <attribute>
 * elements. The <attribute> element has attributes named “name“, “value“,
 * “start“ and “end“ and allows you to specify #PangoAttribute values for
 * this label.
 * 
 * An example of a UI definition fragment specifying Pango attributes:
 * |[
 * <object class="GtkLabel">
 *   <attributes>
 *     <attribute name="weight" value="PANGO_WEIGHT_BOLD"/>
 *     <attribute name="background" value="red" start="5" end="10"/>
 *   </attributes>
 * </object>
 * ]|
 * 
 * The start and end attributes specify the range of characters to which the
 * Pango attribute applies. If start and end are not specified, the attribute is
 * applied to the whole text. Note that specifying ranges does not make much
 * sense with translatable attributes. Use markup embedded in the translatable
 * content instead.
 * 
 * # Mnemonics
 * 
 * Labels may contain “mnemonics”. Mnemonics are
 * underlined characters in the label, used for keyboard navigation.
 * Mnemonics are created by providing a string with an underscore before
 * the mnemonic character, such as `"_File"`, to the
 * functions gtk_label_new_with_mnemonic() or
 * gtk_label_set_text_with_mnemonic().
 * 
 * Mnemonics automatically activate any activatable widget the label is
 * inside, such as a #GtkButton; if the label is not inside the
 * mnemonic’s target widget, you have to tell the label about the target
 * using gtk_label_set_mnemonic_widget(). Here’s a simple example where
 * the label is inside a button:
 * 
 * |[<!-- language="C" -->
 *   // Pressing Alt+H will activate this button
 *   GtkWidget *button = gtk_button_new ();
 *   GtkWidget *label = gtk_label_new_with_mnemonic ("_Hello");
 *   gtk_container_add (GTK_CONTAINER (button), label);
 * ]|
 * 
 * There’s a convenience function to create buttons with a mnemonic label
 * already inside:
 * 
 * |[<!-- language="C" -->
 *   // Pressing Alt+H will activate this button
 *   GtkWidget *button = gtk_button_new_with_mnemonic ("_Hello");
 * ]|
 * 
 * To create a mnemonic for a widget alongside the label, such as a
 * #GtkEntry, you have to point the label at the entry with
 * gtk_label_set_mnemonic_widget():
 * 
 * |[<!-- language="C" -->
 *   // Pressing Alt+H will focus the entry
 *   GtkWidget *entry = gtk_entry_new ();
 *   GtkWidget *label = gtk_label_new_with_mnemonic ("_Hello");
 *   gtk_label_set_mnemonic_widget (GTK_LABEL (label), entry);
 * ]|
 * 
 * # Markup (styled text)
 * 
 * To make it easy to format text in a label (changing colors,
 * fonts, etc.), label text can be provided in a simple
 * [markup format][PangoMarkupFormat].
 * 
 * Here’s how to create a label with a small font:
 * |[<!-- language="C" -->
 *   GtkWidget *label = gtk_label_new (NULL);
 *   gtk_label_set_markup (GTK_LABEL (label), "<small>Small text</small>");
 * ]|
 * 
 * (See [complete documentation][PangoMarkupFormat] of available
 * tags in the Pango manual.)
 * 
 * The markup passed to gtk_label_set_markup() must be valid; for example,
 * literal <, > and & characters must be escaped as &lt;, &gt;, and &amp;.
 * If you pass text obtained from the user, file, or a network to
 * gtk_label_set_markup(), you’ll want to escape it with
 * g_markup_escape_text() or g_markup_printf_escaped().
 * 
 * Markup strings are just a convenient way to set the #PangoAttrList on
 * a label; gtk_label_set_attributes() may be a simpler way to set
 * attributes in some cases. Be careful though; #PangoAttrList tends to
 * cause internationalization problems, unless you’re applying attributes
 * to the entire string (i.e. unless you set the range of each attribute
 * to [0, %G_MAXINT)). The reason is that specifying the start_index and
 * end_index for a #PangoAttribute requires knowledge of the exact string
 * being displayed, so translations will cause problems.
 * 
 * # Selectable labels
 * 
 * Labels can be made selectable with gtk_label_set_selectable().
 * Selectable labels allow the user to copy the label contents to
 * the clipboard. Only labels that contain useful-to-copy information
 * — such as error messages — should be made selectable.
 * 
 * # Text layout # {#label-text-layout}
 * 
 * A label can contain any number of paragraphs, but will have
 * performance problems if it contains more than a small number.
 * Paragraphs are separated by newlines or other paragraph separators
 * understood by Pango.
 * 
 * Labels can automatically wrap text if you call
 * gtk_label_set_line_wrap().
 * 
 * gtk_label_set_justify() sets how the lines in a label align
 * with one another. If you want to set how the label as a whole
 * aligns in its available space, see the #GtkWidget:halign and
 * #GtkWidget:valign properties.
 * 
 * The #GtkLabel:width-chars and #GtkLabel:max-width-chars properties
 * can be used to control the size allocation of ellipsized or wrapped
 * labels. For ellipsizing labels, if either is specified (and less
 * than the actual text size), it is used as the minimum width, and the actual
 * text size is used as the natural width of the label. For wrapping labels,
 * width-chars is used as the minimum width, if specified, and max-width-chars
 * is used as the natural width. Even if max-width-chars specified, wrapping
 * labels will be rewrapped to use all of the available width.
 * 
 * Note that the interpretation of #GtkLabel:width-chars and
 * #GtkLabel:max-width-chars has changed a bit with the introduction of
 * [width-for-height geometry management.][geometry-management]
 * 
 * # Links
 * 
 * Since 2.18, GTK+ supports markup for clickable hyperlinks in addition
 * to regular Pango markup. The markup for links is borrowed from HTML,
 * using the `<a>` with “href“ and “title“ attributes. GTK+ renders links
 * similar to the way they appear in web browsers, with colored, underlined
 * text. The “title“ attribute is displayed as a tooltip on the link.
 * 
 * An example looks like this:
 * 
 * |[<!-- language="C" -->
 * const gchar *text =
 * "Go to the"
 * "<a href=\"http://www.gtk.org title=\"&lt;i&gt;Our&lt;/i&gt; website\">"
 * "GTK+ website</a> for more...";
 * GtkWidget *label = gtk_label_new (NULL);
 * gtk_label_set_markup (GTK_LABEL (label), text);
 * ]|
 * 
 * It is possible to implement custom handling for links and their tooltips with
 * the #GtkLabel::activate-link signal and the gtk_label_get_current_uri() function.
 *
 */
@interface OGTKLabel : OGAtkMisc
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)str;
- (instancetype)initWithMnemonic:(OFString*)str;

/**
 * Methods
 */

- (GtkLabel*)LABEL;

/**
 * Gets the angle of rotation for the label. See
 * gtk_label_set_angle().
 *
 * @return the angle of rotation for the label
 */
- (gdouble)angle;

/**
 * Gets the attribute list that was set on the label using
 * gtk_label_set_attributes(), if any. This function does
 * not reflect attributes that come from the labels markup
 * (see gtk_label_set_markup()). If you want to get the
 * effective attributes for the label, use
 * pango_layout_get_attribute (gtk_label_get_layout (label)).
 *
 * @return the attribute list, or %NULL
 *     if none was set.
 */
- (PangoAttrList*)attributes;

/**
 * Returns the URI for the currently active link in the label.
 * The active link is the one under the mouse pointer or, in a
 * selectable label, the link in which the text cursor is currently
 * positioned.
 * 
 * This function is intended for use in a #GtkLabel::activate-link handler
 * or for use in a #GtkWidget::query-tooltip handler.
 *
 * @return the currently active URI. The string is owned by GTK+ and must
 *   not be freed or modified.
 */
- (OFString*)currentUri;

/**
 * Returns the ellipsizing position of the label. See gtk_label_set_ellipsize().
 *
 * @return #PangoEllipsizeMode
 */
- (PangoEllipsizeMode)ellipsize;

/**
 * Returns the justification of the label. See gtk_label_set_justify().
 *
 * @return #GtkJustification
 */
- (GtkJustification)justify;

/**
 * Fetches the text from a label widget including any embedded
 * underlines indicating mnemonics and Pango markup. (See
 * gtk_label_get_text()).
 *
 * @return the text of the label widget. This string is
 *   owned by the widget and must not be modified or freed.
 */
- (OFString*)label;

/**
 * Gets the #PangoLayout used to display the label.
 * The layout is useful to e.g. convert text positions to
 * pixel positions, in combination with gtk_label_get_layout_offsets().
 * The returned layout is owned by the @label so need not be
 * freed by the caller. The @label is free to recreate its layout at
 * any time, so it should be considered read-only.
 *
 * @return the #PangoLayout for this label
 */
- (OGPangoLayout*)layout;

/**
 * Obtains the coordinates where the label will draw the #PangoLayout
 * representing the text in the label; useful to convert mouse events
 * into coordinates inside the #PangoLayout, e.g. to take some action
 * if some part of the label is clicked. Of course you will need to
 * create a #GtkEventBox to receive the events, and pack the label
 * inside it, since labels are windowless (they return %FALSE from
 * gtk_widget_get_has_window()). Remember
 * when using the #PangoLayout functions you need to convert to
 * and from pixels using PANGO_PIXELS() or #PANGO_SCALE.
 *
 * @param x location to store X offset of layout, or %NULL
 * @param y location to store Y offset of layout, or %NULL
 */
- (void)layoutOffsetsWithX:(gint*)x y:(gint*)y;

/**
 * Returns whether lines in the label are automatically wrapped.
 * See gtk_label_set_line_wrap().
 *
 * @return %TRUE if the lines of the label are automatically wrapped.
 */
- (bool)lineWrap;

/**
 * Returns line wrap mode used by the label. See gtk_label_set_line_wrap_mode().
 *
 * @return %TRUE if the lines of the label are automatically wrapped.
 */
- (PangoWrapMode)lineWrapMode;

/**
 * Gets the number of lines to which an ellipsized, wrapping
 * label should be limited. See gtk_label_set_lines().
 *
 * @return The number of lines
 */
- (gint)lines;

/**
 * Retrieves the desired maximum width of @label, in characters. See
 * gtk_label_set_width_chars().
 *
 * @return the maximum width of the label in characters.
 */
- (gint)maxWidthChars;

/**
 * If the label has been set so that it has an mnemonic key this function
 * returns the keyval used for the mnemonic accelerator. If there is no
 * mnemonic set up it returns #GDK_KEY_VoidSymbol.
 *
 * @return GDK keyval usable for accelerators, or #GDK_KEY_VoidSymbol
 */
- (guint)mnemonicKeyval;

/**
 * Retrieves the target of the mnemonic (keyboard shortcut) of this
 * label. See gtk_label_set_mnemonic_widget().
 *
 * @return the target of the label’s mnemonic,
 *     or %NULL if none has been set and the default algorithm will be used.
 */
- (OGTKWidget*)mnemonicWidget;

/**
 * Gets the value set by gtk_label_set_selectable().
 *
 * @return %TRUE if the user can copy text from the label
 */
- (bool)selectable;

/**
 * Gets the selected range of characters in the label, returning %TRUE
 * if there’s a selection.
 *
 * @param start return location for start of selection, as a character offset
 * @param end return location for end of selection, as a character offset
 * @return %TRUE if selection is non-empty
 */
- (bool)selectionBoundsWithStart:(gint*)start end:(gint*)end;

/**
 * Returns whether the label is in single line mode.
 *
 * @return %TRUE when the label is in single line mode.
 */
- (bool)singleLineMode;

/**
 * Fetches the text from a label widget, as displayed on the
 * screen. This does not include any embedded underlines
 * indicating mnemonics or Pango markup. (See gtk_label_get_label())
 *
 * @return the text in the label widget. This is the internal
 *   string used by the label, and must not be modified.
 */
- (OFString*)text;

/**
 * Returns whether the label is currently keeping track
 * of clicked links.
 *
 * @return %TRUE if clicked links are remembered
 */
- (bool)trackVisitedLinks;

/**
 * Returns whether the label’s text is interpreted as marked up with
 * the [Pango text markup language][PangoMarkupFormat].
 * See gtk_label_set_use_markup ().
 *
 * @return %TRUE if the label’s text will be parsed for markup.
 */
- (bool)useMarkup;

/**
 * Returns whether an embedded underline in the label indicates a
 * mnemonic. See gtk_label_set_use_underline().
 *
 * @return %TRUE whether an embedded underline in the label indicates
 *               the mnemonic accelerator keys.
 */
- (bool)useUnderline;

/**
 * Retrieves the desired width of @label, in characters. See
 * gtk_label_set_width_chars().
 *
 * @return the width of the label in characters.
 */
- (gint)widthChars;

/**
 * Gets the #GtkLabel:xalign property for @label.
 *
 * @return the xalign property
 */
- (gfloat)xalign;

/**
 * Gets the #GtkLabel:yalign property for @label.
 *
 * @return the yalign property
 */
- (gfloat)yalign;

/**
 * Selects a range of characters in the label, if the label is selectable.
 * See gtk_label_set_selectable(). If the label is not selectable,
 * this function has no effect. If @start_offset or
 * @end_offset are -1, then the end of the label will be substituted.
 *
 * @param startOffset start offset (in characters not bytes)
 * @param endOffset end offset (in characters not bytes)
 */
- (void)selectRegionWithStartOffset:(gint)startOffset endOffset:(gint)endOffset;

/**
 * Sets the angle of rotation for the label. An angle of 90 reads from
 * from bottom to top, an angle of 270, from top to bottom. The angle
 * setting for the label is ignored if the label is selectable,
 * wrapped, or ellipsized.
 *
 * @param angle the angle that the baseline of the label makes with
 *   the horizontal, in degrees, measured counterclockwise
 */
- (void)setAngle:(gdouble)angle;

/**
 * Sets a #PangoAttrList; the attributes in the list are applied to the
 * label text.
 * 
 * The attributes set with this function will be applied
 * and merged with any other attributes previously effected by way
 * of the #GtkLabel:use-underline or #GtkLabel:use-markup properties.
 * While it is not recommended to mix markup strings with manually set
 * attributes, if you must; know that the attributes will be applied
 * to the label after the markup string is parsed.
 *
 * @param attrs a #PangoAttrList, or %NULL
 */
- (void)setAttributes:(PangoAttrList*)attrs;

/**
 * Sets the mode used to ellipsize (add an ellipsis: "...") to the text
 * if there is not enough space to render the entire string.
 *
 * @param mode a #PangoEllipsizeMode
 */
- (void)setEllipsize:(PangoEllipsizeMode)mode;

/**
 * Sets the alignment of the lines in the text of the label relative to
 * each other. %GTK_JUSTIFY_LEFT is the default value when the widget is
 * first created with gtk_label_new(). If you instead want to set the
 * alignment of the label as a whole, use gtk_widget_set_halign() instead.
 * gtk_label_set_justify() has no effect on labels containing only a
 * single line.
 *
 * @param jtype a #GtkJustification
 */
- (void)setJustify:(GtkJustification)jtype;

/**
 * Sets the text of the label. The label is interpreted as
 * including embedded underlines and/or Pango markup depending
 * on the values of the #GtkLabel:use-underline and
 * #GtkLabel:use-markup properties.
 *
 * @param str the new text to set for the label
 */
- (void)setLabel:(OFString*)str;

/**
 * Toggles line wrapping within the #GtkLabel widget. %TRUE makes it break
 * lines if text exceeds the widget’s size. %FALSE lets the text get cut off
 * by the edge of the widget if it exceeds the widget size.
 * 
 * Note that setting line wrapping to %TRUE does not make the label
 * wrap at its parent container’s width, because GTK+ widgets
 * conceptually can’t make their requisition depend on the parent
 * container’s size. For a label that wraps at a specific position,
 * set the label’s width using gtk_widget_set_size_request().
 *
 * @param wrap the setting
 */
- (void)setLineWrap:(bool)wrap;

/**
 * If line wrapping is on (see gtk_label_set_line_wrap()) this controls how
 * the line wrapping is done. The default is %PANGO_WRAP_WORD which means
 * wrap on word boundaries.
 *
 * @param wrapMode the line wrapping mode
 */
- (void)setLineWrapMode:(PangoWrapMode)wrapMode;

/**
 * Sets the number of lines to which an ellipsized, wrapping label
 * should be limited. This has no effect if the label is not wrapping
 * or ellipsized. Set this to -1 if you don’t want to limit the
 * number of lines.
 *
 * @param lines the desired number of lines, or -1
 */
- (void)setLines:(gint)lines;

/**
 * Parses @str which is marked up with the
 * [Pango text markup language][PangoMarkupFormat], setting the
 * label’s text and attribute list based on the parse results.
 * 
 * If the @str is external data, you may need to escape it with
 * g_markup_escape_text() or g_markup_printf_escaped():
 * 
 * |[<!-- language="C" -->
 * GtkWidget *label = gtk_label_new (NULL);
 * const char *str = "some text";
 * const char *format = "<span style=\"italic\">\%s</span>";
 * char *markup;
 * 
 * markup = g_markup_printf_escaped (format, str);
 * gtk_label_set_markup (GTK_LABEL (label), markup);
 * g_free (markup);
 * ]|
 * 
 * This function will set the #GtkLabel:use-markup property to %TRUE as
 * a side effect.
 * 
 * If you set the label contents using the #GtkLabel:label property you
 * should also ensure that you set the #GtkLabel:use-markup property
 * accordingly.
 * 
 * See also: gtk_label_set_text()
 *
 * @param str a markup string (see [Pango markup format][PangoMarkupFormat])
 */
- (void)setMarkup:(OFString*)str;

/**
 * Parses @str which is marked up with the
 * [Pango text markup language][PangoMarkupFormat],
 * setting the label’s text and attribute list based on the parse results.
 * If characters in @str are preceded by an underscore, they are underlined
 * indicating that they represent a keyboard accelerator called a mnemonic.
 * 
 * The mnemonic key can be used to activate another widget, chosen
 * automatically, or explicitly using gtk_label_set_mnemonic_widget().
 *
 * @param str a markup string (see
 *     [Pango markup format][PangoMarkupFormat])
 */
- (void)setMarkupWithMnemonic:(OFString*)str;

/**
 * Sets the desired maximum width in characters of @label to @n_chars.
 *
 * @param nchars the new desired maximum width, in characters.
 */
- (void)setMaxWidthChars:(gint)nchars;

/**
 * If the label has been set so that it has an mnemonic key (using
 * i.e. gtk_label_set_markup_with_mnemonic(),
 * gtk_label_set_text_with_mnemonic(), gtk_label_new_with_mnemonic()
 * or the “use_underline” property) the label can be associated with a
 * widget that is the target of the mnemonic. When the label is inside
 * a widget (like a #GtkButton or a #GtkNotebook tab) it is
 * automatically associated with the correct widget, but sometimes
 * (i.e. when the target is a #GtkEntry next to the label) you need to
 * set it explicitly using this function.
 * 
 * The target widget will be accelerated by emitting the
 * GtkWidget::mnemonic-activate signal on it. The default handler for
 * this signal will activate the widget if there are no mnemonic collisions
 * and toggle focus between the colliding widgets otherwise.
 *
 * @param widget the target #GtkWidget, or %NULL to unset
 */
- (void)setMnemonicWidget:(OGTKWidget*)widget;

/**
 * The pattern of underlines you want under the existing text within the
 * #GtkLabel widget.  For example if the current text of the label says
 * “FooBarBaz” passing a pattern of “___   ___” will underline
 * “Foo” and “Baz” but not “Bar”.
 *
 * @param pattern The pattern as described above.
 */
- (void)setPattern:(OFString*)pattern;

/**
 * Selectable labels allow the user to select text from the label, for
 * copy-and-paste.
 *
 * @param setting %TRUE to allow selecting text in the label
 */
- (void)setSelectable:(bool)setting;

/**
 * Sets whether the label is in single line mode.
 *
 * @param singleLineMode %TRUE if the label should be in single line mode
 */
- (void)setSingleLineMode:(bool)singleLineMode;

/**
 * Sets the text within the #GtkLabel widget. It overwrites any text that
 * was there before.
 * 
 * This function will clear any previously set mnemonic accelerators, and
 * set the #GtkLabel:use-underline property to %FALSE as a side effect.
 * 
 * This function will set the #GtkLabel:use-markup property to %FALSE
 * as a side effect.
 * 
 * See also: gtk_label_set_markup()
 *
 * @param str The text you want to set
 */
- (void)setText:(OFString*)str;

/**
 * Sets the label’s text from the string @str.
 * If characters in @str are preceded by an underscore, they are underlined
 * indicating that they represent a keyboard accelerator called a mnemonic.
 * The mnemonic key can be used to activate another widget, chosen
 * automatically, or explicitly using gtk_label_set_mnemonic_widget().
 *
 * @param str a string
 */
- (void)setTextWithMnemonic:(OFString*)str;

/**
 * Sets whether the label should keep track of clicked
 * links (and use a different color for them).
 *
 * @param trackLinks %TRUE to track visited links
 */
- (void)setTrackVisitedLinks:(bool)trackLinks;

/**
 * Sets whether the text of the label contains markup in
 * [Pango’s text markup language][PangoMarkupFormat].
 * See gtk_label_set_markup().
 *
 * @param setting %TRUE if the label’s text should be parsed for markup.
 */
- (void)setUseMarkup:(bool)setting;

/**
 * If true, an underline in the text indicates the next character should be
 * used for the mnemonic accelerator key.
 *
 * @param setting %TRUE if underlines in the text indicate mnemonics
 */
- (void)setUseUnderline:(bool)setting;

/**
 * Sets the desired width in characters of @label to @n_chars.
 *
 * @param nchars the new desired width, in characters.
 */
- (void)setWidthChars:(gint)nchars;

/**
 * Sets the #GtkLabel:xalign property for @label.
 *
 * @param xalign the new xalign value, between 0 and 1
 */
- (void)setXalign:(gfloat)xalign;

/**
 * Sets the #GtkLabel:yalign property for @label.
 *
 * @param yalign the new yalign value, between 0 and 1
 */
- (void)setYalign:(gfloat)yalign;

@end