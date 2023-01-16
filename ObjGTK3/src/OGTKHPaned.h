/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPaned.h"

@class OGTKWidget;

/**
 * The HPaned widget is a container widget with two
 * children arranged horizontally. The division between
 * the two panes is adjustable by the user by dragging
 * a handle. See #GtkPaned for details.
 * 
 * GtkHPaned has been deprecated, use #GtkPaned instead.
 *
 */
@interface OGTKHPaned : OGTKPaned
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkHPaned*)HPANED;

@end