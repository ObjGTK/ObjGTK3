/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPopover.h"

@class OGTKWidget;

/**
 * GtkPopoverMenu is a subclass of #GtkPopover that treats its
 * children like menus and allows switching between them. It is
 * meant to be used primarily together with #GtkModelButton, but
 * any widget can be used, such as #GtkSpinButton or #GtkScale.
 * In this respect, GtkPopoverMenu is more flexible than popovers
 * that are created from a #GMenuModel with gtk_popover_new_from_model().
 * 
 * To add a child as a submenu, set the #GtkPopoverMenu:submenu
 * child property to the name of the submenu. To let the user open
 * this submenu, add a #GtkModelButton whose #GtkModelButton:menu-name
 * property is set to the name you've given to the submenu.
 * 
 * By convention, the first child of a submenu should be a #GtkModelButton
 * to switch back to the parent menu. Such a button should use the
 * #GtkModelButton:inverted and #GtkModelButton:centered properties
 * to achieve a title-like appearance and place the submenu indicator
 * at the opposite side. To switch back to the main menu, use "main"
 * as the menu name.
 * 
 * # Example
 * 
 * |[
 * <object class="GtkPopoverMenu">
 *   <child>
 *     <object class="GtkBox">
 *       <property name="visible">True</property>
 *       <property name="margin">10</property>
 *       <child>
 *         <object class="GtkModelButton">
 *           <property name="visible">True</property>
 *           <property name="action-name">win.frob</property>
 *           <property name="text" translatable="yes">Frob</property>
 *         </object>
 *       </child>
 *       <child>
 *         <object class="GtkModelButton">
 *           <property name="visible">True</property>
 *           <property name="menu-name">more</property>
 *           <property name="text" translatable="yes">More</property>
 *         </object>
 *       </child>
 *     </object>
 *   </child>
 *   <child>
 *     <object class="GtkBox">
 *       <property name="visible">True</property>
 *       <property name="margin">10</property>
 *       <child>
 *         <object class="GtkModelButton">
 *           <property name="visible">True</property>
 *           <property name="action-name">win.foo</property>
 *           <property name="text" translatable="yes">Foo</property>
 *         </object>
 *       </child>
 *       <child>
 *         <object class="GtkModelButton">
 *           <property name="visible">True</property>
 *           <property name="action-name">win.bar</property>
 *           <property name="text" translatable="yes">Bar</property>
 *         </object>
 *       </child>
 *     </object>
 *     <packing>
 *       <property name="submenu">more</property>
 *     </packing>
 *   </child>
 * </object>
 * ]|
 * 
 * Just like normal popovers created using gtk_popover_new_from_model,
 * #GtkPopoverMenu instances have a single css node called "popover"
 * and get the .menu style class.
 *
 */
@interface OGTKPopoverMenu : OGTKPopover
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkPopoverMenu*)POPOVERMENU;

/**
 * Opens a submenu of the @popover. The @name
 * must be one of the names given to the submenus
 * of @popover with #GtkPopoverMenu:submenu, or
 * "main" to switch back to the main menu.
 * 
 * #GtkModelButton will open submenus automatically
 * when the #GtkModelButton:menu-name property is set,
 * so this function is only needed when you are using
 * other kinds of widgets to initiate menu changes.
 *
 * @param name the name of the menu to switch to
 */
- (void)openSubmenu:(OFString*)name;

@end