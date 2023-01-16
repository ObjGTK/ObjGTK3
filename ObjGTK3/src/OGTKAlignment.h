/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKWidget;

/**
 * The #GtkAlignment widget controls the alignment and size of its child widget.
 * It has four settings: xscale, yscale, xalign, and yalign.
 * 
 * The scale settings are used to specify how much the child widget should
 * expand to fill the space allocated to the #GtkAlignment.
 * The values can range from 0 (meaning the child doesn’t expand at all) to
 * 1 (meaning the child expands to fill all of the available space).
 * 
 * The align settings are used to place the child widget within the available
 * area. The values range from 0 (top or left) to 1 (bottom or right).
 * Of course, if the scale settings are both set to 1, the alignment settings
 * have no effect.
 * 
 * GtkAlignment has been deprecated in 3.14 and should not be used in
 * newly-written code. The desired effect can be achieved by using the
 * #GtkWidget:halign, #GtkWidget:valign and #GtkWidget:margin properties on the
 * child widget.
 *
 */
@interface OGTKAlignment : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)initWithXalign:(gfloat)xalign yalign:(gfloat)yalign xscale:(gfloat)xscale yscale:(gfloat)yscale;

/**
 * Methods
 */

- (GtkAlignment*)ALIGNMENT;

/**
 * Gets the padding on the different sides of the widget.
 * See gtk_alignment_set_padding ().
 *
 * @param paddingTop location to store the padding for
 *     the top of the widget, or %NULL
 * @param paddingBottom location to store the padding
 *     for the bottom of the widget, or %NULL
 * @param paddingLeft location to store the padding
 *     for the left of the widget, or %NULL
 * @param paddingRight location to store the padding
 *     for the right of the widget, or %NULL
 */
- (void)paddingWithPaddingTop:(guint*)paddingTop paddingBottom:(guint*)paddingBottom paddingLeft:(guint*)paddingLeft paddingRight:(guint*)paddingRight;

/**
 * Sets the #GtkAlignment values.
 *
 * @param xalign the horizontal alignment of the child widget, from 0 (left) to 1
 *  (right).
 * @param yalign the vertical alignment of the child widget, from 0 (top) to 1
 *  (bottom).
 * @param xscale the amount that the child widget expands horizontally to fill up
 *  unused space, from 0 to 1.
 *  A value of 0 indicates that the child widget should never expand.
 *  A value of 1 indicates that the child widget will expand to fill all of the
 *  space allocated for the #GtkAlignment.
 * @param yscale the amount that the child widget expands vertically to fill up
 *  unused space, from 0 to 1. The values are similar to @xscale.
 */
- (void)setWithXalign:(gfloat)xalign yalign:(gfloat)yalign xscale:(gfloat)xscale yscale:(gfloat)yscale;

/**
 * Sets the padding on the different sides of the widget.
 * The padding adds blank space to the sides of the widget. For instance,
 * this can be used to indent the child widget towards the right by adding
 * padding on the left.
 *
 * @param paddingTop the padding at the top of the widget
 * @param paddingBottom the padding at the bottom of the widget
 * @param paddingLeft the padding at the left of the widget
 * @param paddingRight the padding at the right of the widget.
 */
- (void)setPaddingWithPaddingTop:(guint)paddingTop paddingBottom:(guint)paddingBottom paddingLeft:(guint)paddingLeft paddingRight:(guint)paddingRight;

@end