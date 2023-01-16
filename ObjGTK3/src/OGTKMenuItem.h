/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKWidget;

/**
 * The #GtkMenuItem widget and the derived widgets are the only valid
 * children for menus. Their function is to correctly handle highlighting,
 * alignment, events and submenus.
 * 
 * As a GtkMenuItem derives from #GtkBin it can hold any valid child widget,
 * although only a few are really useful.
 * 
 * By default, a GtkMenuItem sets a #GtkAccelLabel as its child.
 * GtkMenuItem has direct functions to set the label and its mnemonic.
 * For more advanced label settings, you can fetch the child widget from the GtkBin.
 * 
 * An example for setting markup and accelerator on a MenuItem:
 * 
 * |[<!-- language="C" -->
 * GtkWidget *menu_item = gtk_menu_item_new_with_label ("Example Menu Item");
 * 
 * GtkWidget *child = gtk_bin_get_child (GTK_BIN (menu_item));
 * gtk_label_set_markup (GTK_LABEL (child), "<i>new label</i> with <b>markup</b>");
 * gtk_accel_label_set_accel (GTK_ACCEL_LABEL (child), GDK_KEY_1, 0);
 * ]|
 * 
 * # GtkMenuItem as GtkBuildable
 * 
 * The GtkMenuItem implementation of the #GtkBuildable interface supports
 * adding a submenu by specifying “submenu” as the “type” attribute of
 * a `<child>` element.
 * 
 * An example of UI definition fragment with submenus:
 * 
 * |[<!-- language="xml" -->
 * <object class="GtkMenuItem">
 *   <child type="submenu">
 *     <object class="GtkMenu"/>
 *   </child>
 * </object>
 * ]|
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * menuitem
 * ├── <child>
 * ╰── [arrow.right]
 * ]|
 * 
 * GtkMenuItem has a single CSS node with name menuitem. If the menuitem
 * has a submenu, it gets another CSS node with name arrow, which has
 * the .left or .right style class.
 *
 */
@interface OGTKMenuItem : OGTKBin
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

- (GtkMenuItem*)MENUITEM;

/**
 * Emits the #GtkMenuItem::activate signal on the given item
 *
 */
- (void)activate;

/**
 * Emits the #GtkMenuItem::deselect signal on the given item.
 *
 */
- (void)deselect;

/**
 * Retrieve the accelerator path that was previously set on @menu_item.
 * 
 * See gtk_menu_item_set_accel_path() for details.
 *
 * @return the accelerator path corresponding to
 *     this menu item’s functionality, or %NULL if not set
 */
- (OFString*)accelPath;

/**
 * Sets @text on the @menu_item label
 *
 * @return The text in the @menu_item label. This is the internal
 *   string used by the label, and must not be modified.
 */
- (OFString*)label;

/**
 * Returns whether the @menu_item reserves space for
 * the submenu indicator, regardless if it has a submenu
 * or not.
 *
 * @return %TRUE if @menu_item always reserves space for the
 *     submenu indicator
 */
- (bool)reserveIndicator;

/**
 * Gets whether the menu item appears justified at the right
 * side of the menu bar.
 *
 * @return %TRUE if the menu item will appear at the
 *   far right if added to a menu bar.
 */
- (bool)rightJustified;

/**
 * Gets the submenu underneath this menu item, if any.
 * See gtk_menu_item_set_submenu().
 *
 * @return submenu for this menu item, or %NULL if none
 */
- (OGTKWidget*)submenu;

/**
 * Checks if an underline in the text indicates the next character
 * should be used for the mnemonic accelerator key.
 *
 * @return %TRUE if an embedded underline in the label
 *     indicates the mnemonic accelerator key.
 */
- (bool)useUnderline;

/**
 * Emits the #GtkMenuItem::select signal on the given item.
 *
 */
- (void)select;

/**
 * Set the accelerator path on @menu_item, through which runtime
 * changes of the menu item’s accelerator caused by the user can be
 * identified and saved to persistent storage (see gtk_accel_map_save()
 * on this). To set up a default accelerator for this menu item, call
 * gtk_accel_map_add_entry() with the same @accel_path. See also
 * gtk_accel_map_add_entry() on the specifics of accelerator paths,
 * and gtk_menu_set_accel_path() for a more convenient variant of
 * this function.
 * 
 * This function is basically a convenience wrapper that handles
 * calling gtk_widget_set_accel_path() with the appropriate accelerator
 * group for the menu item.
 * 
 * Note that you do need to set an accelerator on the parent menu with
 * gtk_menu_set_accel_group() for this to work.
 * 
 * Note that @accel_path string will be stored in a #GQuark.
 * Therefore, if you pass a static string, you can save some memory
 * by interning it first with g_intern_static_string().
 *
 * @param accelPath accelerator path, corresponding to this menu
 *     item’s functionality, or %NULL to unset the current path.
 */
- (void)setAccelPath:(OFString*)accelPath;

/**
 * Sets @text on the @menu_item label
 *
 * @param label the text you want to set
 */
- (void)setLabel:(OFString*)label;

/**
 * Sets whether the @menu_item should reserve space for
 * the submenu indicator, regardless if it actually has
 * a submenu or not.
 * 
 * There should be little need for applications to call
 * this functions.
 *
 * @param reserve the new value
 */
- (void)setReserveIndicator:(bool)reserve;

/**
 * Sets whether the menu item appears justified at the right
 * side of a menu bar. This was traditionally done for “Help”
 * menu items, but is now considered a bad idea. (If the widget
 * layout is reversed for a right-to-left language like Hebrew
 * or Arabic, right-justified-menu-items appear at the left.)
 *
 * @param rightJustified if %TRUE the menu item will appear at the
 *   far right if added to a menu bar
 */
- (void)setRightJustified:(bool)rightJustified;

/**
 * Sets or replaces the menu item’s submenu, or removes it when a %NULL
 * submenu is passed.
 *
 * @param submenu the submenu, or %NULL
 */
- (void)setSubmenu:(OGTKWidget*)submenu;

/**
 * If true, an underline in the text indicates the next character
 * should be used for the mnemonic accelerator key.
 *
 * @param setting %TRUE if underlines in the text indicate mnemonics
 */
- (void)setUseUnderline:(bool)setting;

/**
 * Emits the #GtkMenuItem::toggle-size-allocate signal on the given item.
 *
 * @param allocation the allocation to use as signal data.
 */
- (void)toggleSizeAllocate:(gint)allocation;

/**
 * Emits the #GtkMenuItem::toggle-size-request signal on the given item.
 *
 * @param requisition the requisition to use as signal data.
 */
- (void)toggleSizeRequest:(gint*)requisition;

@end