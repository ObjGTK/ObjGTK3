/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFrame.h"

@class OGTKWidget;

/**
 * The #GtkAspectFrame is useful when you want
 * pack a widget so that it can resize but always retains
 * the same aspect ratio. For instance, one might be
 * drawing a small preview of a larger image. #GtkAspectFrame
 * derives from #GtkFrame, so it can draw a label and
 * a frame around the child. The frame will be
 * “shrink-wrapped” to the size of the child.
 * 
 * # CSS nodes
 * 
 * GtkAspectFrame uses a CSS node with name frame.
 *
 */
@interface OGTKAspectFrame : OGTKFrame
{

}


/**
 * Constructors
 */
- (instancetype)initWithLabel:(OFString*)label xalign:(gfloat)xalign yalign:(gfloat)yalign ratio:(gfloat)ratio obeyChild:(bool)obeyChild;

/**
 * Methods
 */

- (GtkAspectFrame*)ASPECTFRAME;

/**
 * Set parameters for an existing #GtkAspectFrame.
 *
 * @param xalign Horizontal alignment of the child within the allocation of
 *  the #GtkAspectFrame. This ranges from 0.0 (left aligned)
 *  to 1.0 (right aligned)
 * @param yalign Vertical alignment of the child within the allocation of
 *  the #GtkAspectFrame. This ranges from 0.0 (top aligned)
 *  to 1.0 (bottom aligned)
 * @param ratio The desired aspect ratio.
 * @param obeyChild If %TRUE, @ratio is ignored, and the aspect
 *  ratio is taken from the requistion of the child.
 */
- (void)setWithXalign:(gfloat)xalign yalign:(gfloat)yalign ratio:(gfloat)ratio obeyChild:(bool)obeyChild;

@end