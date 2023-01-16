/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSeparator.h"

@class OGTKWidget;

/**
 * The #GtkHSeparator widget is a horizontal separator, used to group the
 * widgets within a window. It displays a horizontal line with a shadow to
 * make it appear sunken into the interface.
 * 
 * > The #GtkHSeparator widget is not used as a separator within menus.
 * > To create a separator in a menu create an empty #GtkSeparatorMenuItem
 * > widget using gtk_separator_menu_item_new() and add it to the menu with
 * > gtk_menu_shell_append().
 * 
 * GtkHSeparator has been deprecated, use #GtkSeparator instead.
 *
 */
@interface OGTKHSeparator : OGTKSeparator
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkHSeparator*)HSEPARATOR;

@end