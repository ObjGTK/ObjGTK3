/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkObject.h"

/**
 * This object class is derived from AtkObject. It can be used as a
 * basis for implementing accessible objects for GObjects which are
 * not derived from GtkWidget. One example of its use is in providing
 * an accessible object for GnomeCanvasItem in the GAIL library.
 *
 */
@interface OGAtkGObjectAccessible : OGAtkObject
{

}

/**
 * Functions
 */
+ (OGAtkObject*)forObject:(GObject*)obj;

/**
 * Methods
 */

- (AtkGObjectAccessible*)GOBJECTACCESSIBLE;

/**
 * Gets the GObject for which @obj is the accessible object.
 *
 * @return a #GObject which is the object for which @obj is
 * the accessible object
 */
- (GObject*)object;

@end