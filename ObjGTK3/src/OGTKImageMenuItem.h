/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenuItem.h"

@class OGTKAccelGroup;
@class OGTKWidget;

/**
 * A GtkImageMenuItem is a menu item which has an icon next to the text label.
 * 
 * This is functionally equivalent to:
 * 
 * |[<!-- language="C" -->
 *   GtkWidget *box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 6);
 *   GtkWidget *icon = gtk_image_new_from_icon_name ("folder-music-symbolic", GTK_ICON_SIZE_MENU);
 *   GtkWidget *label = gtk_label_new ("Music");
 *   GtkWidget *menu_item = gtk_menu_item_new ();
 * 
 *   gtk_container_add (GTK_CONTAINER (box), icon);
 *   gtk_container_add (GTK_CONTAINER (box), label);
 * 
 *   gtk_container_add (GTK_CONTAINER (menu_item), box);
 * 
 *   gtk_widget_show_all (menu_item);
 * ]|
 * 
 * Note that the user may disable display of menu icons using
 * the #GtkSettings:gtk-menu-images setting, so make sure to still
 * fill in the text label. If you want to ensure that your menu items
 * show an icon you are strongly encouraged to use a #GtkMenuItem
 * with a #GtkImage instead.
 * 
 * #GtkImageMenuItem has been deprecated since GTK+ 3.10. If you want to
 * display an icon in a menu item, you should use #GtkMenuItem and pack a
 * #GtkBox with a #GtkImage and a #GtkLabel instead. You should also consider
 * using #GtkBuilder and the XML #GMenu description for creating menus, by
 * following the [GMenu guide][https://developer.gnome.org/GMenu/]. You should
 * consider using icons in menu items only sparingly, and for "objects" (or
 * "nouns") elements only, like bookmarks, files, and links; "actions" (or
 * "verbs") should not have icons.
 * 
 * Furthermore, if you would like to display keyboard accelerator, you must
 * pack the accel label into the box using gtk_box_pack_end() and align the
 * label, otherwise the accelerator will not display correctly. The following
 * code snippet adds a keyboard accelerator to the menu item, with a key
 * binding of Ctrl+M:
 * 
 * |[<!-- language="C" -->
 *   GtkWidget *box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 6);
 *   GtkWidget *icon = gtk_image_new_from_icon_name ("folder-music-symbolic", GTK_ICON_SIZE_MENU);
 *   GtkWidget *label = gtk_accel_label_new ("Music");
 *   GtkWidget *menu_item = gtk_menu_item_new ();
 *   GtkAccelGroup *accel_group = gtk_accel_group_new ();
 * 
 *   gtk_container_add (GTK_CONTAINER (box), icon);
 * 
 *   gtk_label_set_use_underline (GTK_LABEL (label), TRUE);
 *   gtk_label_set_xalign (GTK_LABEL (label), 0.0);
 * 
 *   gtk_widget_add_accelerator (menu_item, "activate", accel_group,
 *                               GDK_KEY_m, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
 *   gtk_accel_label_set_accel_widget (GTK_ACCEL_LABEL (label), menu_item);
 * 
 *   gtk_box_pack_end (GTK_BOX (box), label, TRUE, TRUE, 0);
 * 
 *   gtk_container_add (GTK_CONTAINER (menu_item), box);
 * 
 *   gtk_widget_show_all (menu_item);
 * ]|
 *
 */
@interface OGTKImageMenuItem : OGTKMenuItem
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initFromStockWithStockId:(OFString*)stockId accelGroup:(OGTKAccelGroup*)accelGroup;
- (instancetype)initWithLabel:(OFString*)label;
- (instancetype)initWithMnemonic:(OFString*)label;

/**
 * Methods
 */

- (GtkImageMenuItem*)IMAGEMENUITEM;

/**
 * Returns whether the menu item will ignore the #GtkSettings:gtk-menu-images
 * setting and always show the image, if available.
 *
 * @return %TRUE if the menu item will always show the image
 */
- (bool)alwaysShowImage;

/**
 * Gets the widget that is currently set as the image of @image_menu_item.
 * See gtk_image_menu_item_set_image().
 *
 * @return the widget set as image of @image_menu_item
 */
- (OGTKWidget*)image;

/**
 * Checks whether the label set in the menuitem is used as a
 * stock id to select the stock item for the item.
 *
 * @return %TRUE if the label set in the menuitem is used as a
 *     stock id to select the stock item for the item
 */
- (bool)useStock;

/**
 * Specifies an @accel_group to add the menu items accelerator to
 * (this only applies to stock items so a stock item must already
 * be set, make sure to call gtk_image_menu_item_set_use_stock()
 * and gtk_menu_item_set_label() with a valid stock item first).
 * 
 * If you want this menu item to have changeable accelerators then
 * you shouldnt need this (see gtk_image_menu_item_new_from_stock()).
 *
 * @param accelGroup the #GtkAccelGroup
 */
- (void)setAccelGroup:(OGTKAccelGroup*)accelGroup;

/**
 * If %TRUE, the menu item will ignore the #GtkSettings:gtk-menu-images
 * setting and always show the image, if available.
 * 
 * Use this property if the menuitem would be useless or hard to use
 * without the image.
 *
 * @param alwaysShow %TRUE if the menuitem should always show the image
 */
- (void)setAlwaysShowImage:(bool)alwaysShow;

/**
 * Sets the image of @image_menu_item to the given widget.
 * Note that it depends on the show-menu-images setting whether
 * the image will be displayed or not.
 *
 * @param image a widget to set as the image for the menu item.
 */
- (void)setImage:(OGTKWidget*)image;

/**
 * If %TRUE, the label set in the menuitem is used as a
 * stock id to select the stock item for the item.
 *
 * @param useStock %TRUE if the menuitem should use a stock item
 */
- (void)setUseStock:(bool)useStock;

@end