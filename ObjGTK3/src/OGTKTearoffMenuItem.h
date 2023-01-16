/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenuItem.h"

@class OGTKWidget;

/**
 * A #GtkTearoffMenuItem is a special #GtkMenuItem which is used to
 * tear off and reattach its menu.
 * 
 * When its menu is shown normally, the #GtkTearoffMenuItem is drawn as a
 * dotted line indicating that the menu can be torn off.  Activating it
 * causes its menu to be torn off and displayed in its own window
 * as a tearoff menu.
 * 
 * When its menu is shown as a tearoff menu, the #GtkTearoffMenuItem is drawn
 * as a dotted line which has a left pointing arrow graphic indicating that
 * the tearoff menu can be reattached.  Activating it will erase the tearoff
 * menu window.
 * 
 * > #GtkTearoffMenuItem is deprecated and should not be used in newly
 * > written code. Menus are not meant to be torn around.
 *
 */
@interface OGTKTearoffMenuItem : OGTKMenuItem
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkTearoffMenuItem*)TEAROFFMENUITEM;

@end