/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenu.h"

@class OGTKRecentManager;
@class OGTKWidget;

/**
 * #GtkRecentChooserMenu is a widget suitable for displaying recently used files
 * inside a menu.  It can be used to set a sub-menu of a #GtkMenuItem using
 * gtk_menu_item_set_submenu(), or as the menu of a #GtkMenuToolButton.
 * 
 * Note that #GtkRecentChooserMenu does not have any methods of its own. Instead,
 * you should use the functions that work on a #GtkRecentChooser.
 * 
 * Note also that #GtkRecentChooserMenu does not support multiple filters, as it
 * has no way to let the user choose between them as the #GtkRecentChooserWidget
 * and #GtkRecentChooserDialog widgets do. Thus using gtk_recent_chooser_add_filter()
 * on a #GtkRecentChooserMenu widget will yield the same effects as using
 * gtk_recent_chooser_set_filter(), replacing any currently set filter
 * with the supplied filter; gtk_recent_chooser_remove_filter() will remove
 * any currently set #GtkRecentFilter object and will unset the current filter;
 * gtk_recent_chooser_list_filters() will return a list containing a single
 * #GtkRecentFilter object.
 * 
 * Recently used files are supported since GTK+ 2.10.
 *
 */
@interface OGTKRecentChooserMenu : OGTKMenu
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initForManager:(OGTKRecentManager*)manager;

/**
 * Methods
 */

- (GtkRecentChooserMenu*)RECENTCHOOSERMENU;

/**
 * Returns the value set by gtk_recent_chooser_menu_set_show_numbers().
 *
 * @return %TRUE if numbers should be shown.
 */
- (bool)showNumbers;

/**
 * Sets whether a number should be added to the items of @menu.  The
 * numbers are shown to provide a unique character for a mnemonic to
 * be used inside ten menu item’s label.  Only the first the items
 * get a number to avoid clashes.
 *
 * @param showNumbers whether to show numbers
 */
- (void)setShowNumbers:(bool)showNumbers;

@end