/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenuItem.h"

@class OGTKWidget;

/**
 * A #GtkCheckMenuItem is a menu item that maintains the state of a boolean
 * value in addition to a #GtkMenuItem usual role in activating application
 * code.
 * 
 * A check box indicating the state of the boolean value is displayed
 * at the left side of the #GtkMenuItem.  Activating the #GtkMenuItem
 * toggles the value.
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * menuitem
 * ├── check.left
 * ╰── <child>
 * ]|
 * 
 * GtkCheckMenuItem has a main CSS node with name menuitem, and a subnode
 * with name check, which gets the .left or .right style class.
 *
 */
@interface OGTKCheckMenuItem : OGTKMenuItem
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initWithLabel:(OFString*)label;
- (instancetype)initWithMnemonic:(OFString*)label;

/**
 * Methods
 */

- (GtkCheckMenuItem*)CHECKMENUITEM;

/**
 * Returns whether the check menu item is active. See
 * gtk_check_menu_item_set_active ().
 *
 * @return %TRUE if the menu item is checked.
 */
- (bool)active;

/**
 * Returns whether @check_menu_item looks like a #GtkRadioMenuItem
 *
 * @return Whether @check_menu_item looks like a #GtkRadioMenuItem
 */
- (bool)drawAsRadio;

/**
 * Retrieves the value set by gtk_check_menu_item_set_inconsistent().
 *
 * @return %TRUE if inconsistent
 */
- (bool)inconsistent;

/**
 * Sets the active state of the menu item’s check box.
 *
 * @param isActive boolean value indicating whether the check box is active.
 */
- (void)setActive:(bool)isActive;

/**
 * Sets whether @check_menu_item is drawn like a #GtkRadioMenuItem
 *
 * @param drawAsRadio whether @check_menu_item is drawn like a #GtkRadioMenuItem
 */
- (void)setDrawAsRadio:(bool)drawAsRadio;

/**
 * If the user has selected a range of elements (such as some text or
 * spreadsheet cells) that are affected by a boolean setting, and the
 * current values in that range are inconsistent, you may want to
 * display the check in an “in between” state. This function turns on
 * “in between” display.  Normally you would turn off the inconsistent
 * state again if the user explicitly selects a setting. This has to be
 * done manually, gtk_check_menu_item_set_inconsistent() only affects
 * visual appearance, it doesn’t affect the semantics of the widget.
 *
 * @param setting %TRUE to display an “inconsistent” third state check
 */
- (void)setInconsistent:(bool)setting;

/**
 * Emits the #GtkCheckMenuItem::toggled signal.
 *
 */
- (void)toggled;

@end