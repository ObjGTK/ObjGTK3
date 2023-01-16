/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtkx.h>
#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>

#import <OGObject/OGObject.h>

/**
 * The #GtkRcStyle-struct is used to represent a set
 * of information about the appearance of a widget.
 * This can later be composited together with other
 * #GtkRcStyle-struct<!-- -->s to form a #GtkStyle.
 *
 */
@interface OGTKRcStyle : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkRcStyle*)RCSTYLE;

/**
 * Makes a copy of the specified #GtkRcStyle. This function
 * will correctly copy an RC style that is a member of a class
 * derived from #GtkRcStyle.
 *
 * @return the resulting #GtkRcStyle
 */
- (OGTKRcStyle*)copy;

@end