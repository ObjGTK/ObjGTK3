/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAction.h"

@class OGTKRecentManager;

/**
 * A #GtkRecentAction represents a list of recently used files, which
 * can be shown by widgets such as #GtkRecentChooserDialog or
 * #GtkRecentChooserMenu.
 * 
 * To construct a submenu showing recently used files, use a #GtkRecentAction
 * as the action for a `<menuitem>`. To construct a menu toolbutton showing
 * the recently used files in the popup menu, use a #GtkRecentAction as the
 * action for a `<toolitem>` element.
 *
 */
@interface OGTKRecentAction : OGTKAction
{

}


/**
 * Constructors
 */
- (instancetype)initWithName:(OFString*)name label:(OFString*)label tooltip:(OFString*)tooltip stockId:(OFString*)stockId;
- (instancetype)initForManagerWithName:(OFString*)name label:(OFString*)label tooltip:(OFString*)tooltip stockId:(OFString*)stockId manager:(OGTKRecentManager*)manager;

/**
 * Methods
 */

- (GtkRecentAction*)RECENTACTION;

/**
 * Returns the value set by gtk_recent_chooser_menu_set_show_numbers().
 *
 * @return %TRUE if numbers should be shown.
 */
- (bool)showNumbers;

/**
 * Sets whether a number should be added to the items shown by the
 * widgets representing @action. The numbers are shown to provide
 * a unique character for a mnemonic to be used inside the menu item's
 * label. Only the first ten items get a number to avoid clashes.
 *
 * @param showNumbers %TRUE if the shown items should be numbered
 */
- (void)setShowNumbers:(bool)showNumbers;

@end