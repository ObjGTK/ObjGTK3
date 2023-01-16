/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWidget.h"

/**
 * The #GtkMisc widget is an abstract widget which is not useful itself, but
 * is used to derive subclasses which have alignment and padding attributes.
 * 
 * The horizontal and vertical padding attributes allows extra space to be
 * added around the widget.
 * 
 * The horizontal and vertical alignment attributes enable the widget to be
 * positioned within its allocated area. Note that if the widget is added to
 * a container in such a way that it expands automatically to fill its
 * allocated area, the alignment settings will not alter the widget's position.
 * 
 * Note that the desired effect can in most cases be achieved by using the
 * #GtkWidget:halign, #GtkWidget:valign and #GtkWidget:margin properties
 * on the child widget, so GtkMisc should not be used in new code. To reflect
 * this fact, all #GtkMisc API has been deprecated.
 *
 */
@interface OGTKMisc : OGTKWidget
{

}


/**
 * Methods
 */

- (GtkMisc*)MISC;

/**
 * Gets the X and Y alignment of the widget within its allocation.
 * See gtk_misc_set_alignment().
 *
 * @param xalign location to store X alignment of @misc, or %NULL
 * @param yalign location to store Y alignment of @misc, or %NULL
 */
- (void)alignmentWithXalign:(gfloat*)xalign yalign:(gfloat*)yalign;

/**
 * Gets the padding in the X and Y directions of the widget.
 * See gtk_misc_set_padding().
 *
 * @param xpad location to store padding in the X
 *        direction, or %NULL
 * @param ypad location to store padding in the Y
 *        direction, or %NULL
 */
- (void)paddingWithXpad:(gint*)xpad ypad:(gint*)ypad;

/**
 * Sets the alignment of the widget.
 *
 * @param xalign the horizontal alignment, from 0 (left) to 1 (right).
 * @param yalign the vertical alignment, from 0 (top) to 1 (bottom).
 */
- (void)setAlignmentWithXalign:(gfloat)xalign yalign:(gfloat)yalign;

/**
 * Sets the amount of space to add around the widget.
 *
 * @param xpad the amount of space to add on the left and right of the widget,
 *   in pixels.
 * @param ypad the amount of space to add on the top and bottom of the widget,
 *   in pixels.
 */
- (void)setPaddingWithXpad:(gint)xpad ypad:(gint)ypad;

@end