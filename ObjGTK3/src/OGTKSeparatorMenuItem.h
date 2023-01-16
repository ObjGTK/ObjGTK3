/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenuItem.h"

@class OGTKWidget;

/**
 * The #GtkSeparatorMenuItem is a separator used to group
 * items within a menu. It displays a horizontal line with a shadow to
 * make it appear sunken into the interface.
 * 
 * # CSS nodes
 * 
 * GtkSeparatorMenuItem has a single CSS node with name separator.
 *
 */
@interface OGTKSeparatorMenuItem : OGTKMenuItem
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkSeparatorMenuItem*)SEPARATORMENUITEM;

@end