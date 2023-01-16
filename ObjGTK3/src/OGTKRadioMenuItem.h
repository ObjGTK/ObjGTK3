/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCheckMenuItem.h"

@class OGTKWidget;

/**
 * A radio menu item is a check menu item that belongs to a group. At each
 * instant exactly one of the radio menu items from a group is selected.
 * 
 * The group list does not need to be freed, as each #GtkRadioMenuItem will
 * remove itself and its list item when it is destroyed.
 * 
 * The correct way to create a group of radio menu items is approximatively
 * this:
 * 
 * ## How to create a group of radio menu items.
 * 
 * |[<!-- language="C" -->
 * GSList *group = NULL;
 * GtkWidget *item;
 * gint i;
 * 
 * for (i = 0; i < 5; i++)
 * {
 *   item = gtk_radio_menu_item_new_with_label (group, "This is an example");
 *   group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (item));
 *   if (i == 1)
 *     gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (item), TRUE);
 * }
 * ]|
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * menuitem
 * ├── radio.left
 * ╰── <child>
 * ]|
 * 
 * GtkRadioMenuItem has a main CSS node with name menuitem, and a subnode
 * with name radio, which gets the .left or .right style class.
 *
 */
@interface OGTKRadioMenuItem : OGTKCheckMenuItem
{

}


/**
 * Constructors
 */
- (instancetype)init:(GSList*)group;
- (instancetype)initFromWidget:(OGTKRadioMenuItem*)group;
- (instancetype)initWithLabelWithGroup:(GSList*)group label:(OFString*)label;
- (instancetype)initWithLabelFromWidgetWithGroup:(OGTKRadioMenuItem*)group label:(OFString*)label;
- (instancetype)initWithMnemonicWithGroup:(GSList*)group label:(OFString*)label;
- (instancetype)initWithMnemonicFromWidgetWithGroup:(OGTKRadioMenuItem*)group label:(OFString*)label;

/**
 * Methods
 */

- (GtkRadioMenuItem*)RADIOMENUITEM;

/**
 * Returns the group to which the radio menu item belongs, as a #GList of
 * #GtkRadioMenuItem. The list belongs to GTK+ and should not be freed.
 *
 * @return the group
 *     of @radio_menu_item
 */
- (GSList*)group;

/**
 * Joins a #GtkRadioMenuItem object to the group of another #GtkRadioMenuItem
 * object.
 * 
 * This function should be used by language bindings to avoid the memory
 * manangement of the opaque #GSList of gtk_radio_menu_item_get_group()
 * and gtk_radio_menu_item_set_group().
 * 
 * A common way to set up a group of #GtkRadioMenuItem instances is:
 * 
 * |[
 *   GtkRadioMenuItem *last_item = NULL;
 * 
 *   while ( ...more items to add... )
 *     {
 *       GtkRadioMenuItem *radio_item;
 * 
 *       radio_item = gtk_radio_menu_item_new (...);
 * 
 *       gtk_radio_menu_item_join_group (radio_item, last_item);
 *       last_item = radio_item;
 *     }
 * ]|
 *
 * @param groupSource a #GtkRadioMenuItem whose group we are
 *   joining, or %NULL to remove the @radio_menu_item from its current
 *   group
 */
- (void)joinGroup:(OGTKRadioMenuItem*)groupSource;

/**
 * Sets the group of a radio menu item, or changes it.
 *
 * @param group the new group, or %NULL.
 */
- (void)setGroup:(GSList*)group;

@end