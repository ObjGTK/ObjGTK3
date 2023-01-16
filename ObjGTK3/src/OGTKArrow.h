/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtkx.h>
#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>

#import <OGAtk/OGAtkMisc.h>

@class OGTKWidget;

/**
 * GtkArrow should be used to draw simple arrows that need to point in
 * one of the four cardinal directions (up, down, left, or right).  The
 * style of the arrow can be one of shadow in, shadow out, etched in, or
 * etched out.  Note that these directions and style types may be
 * amended in versions of GTK+ to come.
 * 
 * GtkArrow will fill any space alloted to it, but since it is inherited
 * from #GtkMisc, it can be padded and/or aligned, to fill exactly the
 * space the programmer desires.
 * 
 * Arrows are created with a call to gtk_arrow_new().  The direction or
 * style of an arrow can be changed after creation by using gtk_arrow_set().
 * 
 * GtkArrow has been deprecated; you can simply use a #GtkImage with a
 * suitable icon name, such as “pan-down-symbolic“. When replacing
 * GtkArrow by an image, pay attention to the fact that GtkArrow is
 * doing automatic flipping between #GTK_ARROW_LEFT and #GTK_ARROW_RIGHT,
 * depending on the text direction. To get the same effect with an image,
 * use the icon names “pan-start-symbolic“ and “pan-end-symbolic“, which
 * react to the text direction.
 *
 */
@interface OGTKArrow : OGAtkMisc
{

}


/**
 * Constructors
 */
- (instancetype)initWithArrowType:(GtkArrowType)arrowType shadowType:(GtkShadowType)shadowType;

/**
 * Methods
 */

- (GtkArrow*)ARROW;

/**
 * Sets the direction and style of the #GtkArrow, @arrow.
 *
 * @param arrowType a valid #GtkArrowType.
 * @param shadowType a valid #GtkShadowType.
 */
- (void)setWithArrowType:(GtkArrowType)arrowType shadowType:(GtkShadowType)shadowType;

@end