/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPaned.h"

@class OGTKWidget;

/**
 * The VPaned widget is a container widget with two
 * children arranged vertically. The division between
 * the two panes is adjustable by the user by dragging
 * a handle. See #GtkPaned for details.
 * 
 * GtkVPaned has been deprecated, use #GtkPaned instead.
 *
 */
@interface OGTKVPaned : OGTKPaned
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkVPaned*)VPANED;

@end