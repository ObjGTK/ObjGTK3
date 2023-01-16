/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKWidget;

/**
 * The frame widget is a bin that surrounds its child with a decorative
 * frame and an optional label. If present, the label is drawn in a gap
 * in the top side of the frame. The position of the label can be
 * controlled with gtk_frame_set_label_align().
 * 
 * # GtkFrame as GtkBuildable
 * 
 * The GtkFrame implementation of the #GtkBuildable interface supports
 * placing a child in the label position by specifying “label” as the
 * “type” attribute of a `<child>` element. A normal content child can
 * be specified without specifying a `<child>` type attribute.
 * 
 * An example of a UI definition fragment with `GtkFrame`:
 * 
 * |[<!-- language="xml" -->
 * <object class="GtkFrame">
 *   <child type="label">
 *     <object class="GtkLabel" id="frame-label"/>
 *   </child>
 *   <child>
 *     <object class="GtkEntry" id="frame-content"/>
 *   </child>
 * </object>
 * ]|
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * frame
 * ├── border[.flat]
 * ├── <label widget>
 * ╰── <child>
 * ]|
 * 
 * GtkFrame has a main CSS node named “frame” and a subnode named “border”. The
 * “border” node is used to draw the visible border. You can set the appearance
 * of the border using CSS properties like “border-style” on the “border” node.
 * 
 * The border node can be given the style class “.flat”, which is used by themes
 * to disable drawing of the border. To do this from code, call
 * gtk_frame_set_shadow_type() with %GTK_SHADOW_NONE to add the “.flat” class or
 * any other shadow type to remove it.
 *
 */
@interface OGTKFrame : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)label;

/**
 * Methods
 */

- (GtkFrame*)FRAME;

/**
 * If the frame’s label widget is a #GtkLabel, returns the
 * text in the label widget. (The frame will have a #GtkLabel
 * for the label widget if a non-%NULL argument was passed
 * to gtk_frame_new().)
 *
 * @return the text in the label, or %NULL if there
 *               was no label widget or the lable widget was not
 *               a #GtkLabel. This string is owned by GTK+ and
 *               must not be modified or freed.
 */
- (OFString*)label;

/**
 * Retrieves the X and Y alignment of the frame’s label. See
 * gtk_frame_set_label_align().
 *
 * @param xalign location to store X alignment of
 *     frame’s label, or %NULL
 * @param yalign location to store X alignment of
 *     frame’s label, or %NULL
 */
- (void)labelAlignWithXalign:(gfloat*)xalign yalign:(gfloat*)yalign;

/**
 * Retrieves the label widget for the frame. See
 * gtk_frame_set_label_widget().
 *
 * @return the label widget, or %NULL if
 * there is none.
 */
- (OGTKWidget*)labelWidget;

/**
 * Retrieves the shadow type of the frame. See
 * gtk_frame_set_shadow_type().
 *
 * @return the current shadow type of the frame.
 */
- (GtkShadowType)shadowType;

/**
 * Removes the current #GtkFrame:label-widget. If @label is not %NULL, creates a
 * new #GtkLabel with that text and adds it as the #GtkFrame:label-widget.
 *
 * @param label the text to use as the label of the frame
 */
- (void)setLabel:(OFString*)label;

/**
 * Sets the alignment of the frame widget’s label. The
 * default values for a newly created frame are 0.0 and 0.5.
 *
 * @param xalign The position of the label along the top edge
 *   of the widget. A value of 0.0 represents left alignment;
 *   1.0 represents right alignment.
 * @param yalign The y alignment of the label. A value of 0.0 aligns under
 *   the frame; 1.0 aligns above the frame. If the values are exactly
 *   0.0 or 1.0 the gap in the frame won’t be painted because the label
 *   will be completely above or below the frame.
 */
- (void)setLabelAlignWithXalign:(gfloat)xalign yalign:(gfloat)yalign;

/**
 * Sets the #GtkFrame:label-widget for the frame. This is the widget that
 * will appear embedded in the top edge of the frame as a title.
 *
 * @param labelWidget the new label widget
 */
- (void)setLabelWidget:(OGTKWidget*)labelWidget;

/**
 * Sets the #GtkFrame:shadow-type for @frame, i.e. whether it is drawn without
 * (%GTK_SHADOW_NONE) or with (other values) a visible border. Values other than
 * %GTK_SHADOW_NONE are treated identically by GtkFrame. The chosen type is
 * applied by removing or adding the .flat class to the CSS node named border.
 *
 * @param type the new #GtkShadowType
 */
- (void)setShadowType:(GtkShadowType)type;

@end