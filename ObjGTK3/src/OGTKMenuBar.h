/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenuShell.h"

@class OGTKWidget;

/**
 * The #GtkMenuBar is a subclass of #GtkMenuShell which contains one or
 * more #GtkMenuItems. The result is a standard menu bar which can hold
 * many menu items.
 * 
 * # CSS nodes
 * 
 * GtkMenuBar has a single CSS node with name menubar.
 *
 */
@interface OGTKMenuBar : OGTKMenuShell
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initFromModel:(GMenuModel*)model;

/**
 * Methods
 */

- (GtkMenuBar*)MENUBAR;

/**
 * Retrieves the current child pack direction of the menubar.
 * See gtk_menu_bar_set_child_pack_direction().
 *
 * @return the child pack direction
 */
- (GtkPackDirection)childPackDirection;

/**
 * Retrieves the current pack direction of the menubar.
 * See gtk_menu_bar_set_pack_direction().
 *
 * @return the pack direction
 */
- (GtkPackDirection)packDirection;

/**
 * Sets how widgets should be packed inside the children of a menubar.
 *
 * @param childPackDir a new #GtkPackDirection
 */
- (void)setChildPackDirection:(GtkPackDirection)childPackDir;

/**
 * Sets how items should be packed inside a menubar.
 *
 * @param packDir a new #GtkPackDirection
 */
- (void)setPackDirection:(GtkPackDirection)packDir;

@end