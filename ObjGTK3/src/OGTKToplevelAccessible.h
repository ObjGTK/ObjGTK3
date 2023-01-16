/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGAtk/OGAtkObject.h>

@interface OGTKToplevelAccessible : OGAtkObject
{

}


/**
 * Methods
 */

- (GtkToplevelAccessible*)TOPLEVELACCESSIBLE;

/**
 *
 * @return List of
 *   children.
 */
- (GList*)children;

@end