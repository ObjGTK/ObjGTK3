/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKWidget;

/**
 * A #GtkMenuShell is the abstract base class used to derive the
 * #GtkMenu and #GtkMenuBar subclasses.
 * 
 * A #GtkMenuShell is a container of #GtkMenuItem objects arranged
 * in a list which can be navigated, selected, and activated by the
 * user to perform application functions. A #GtkMenuItem can have a
 * submenu associated with it, allowing for nested hierarchical menus.
 * 
 * # Terminology
 * 
 * A menu item can be “selected”, this means that it is displayed
 * in the prelight state, and if it has a submenu, that submenu
 * will be popped up.
 * 
 * A menu is “active” when it is visible onscreen and the user
 * is selecting from it. A menubar is not active until the user
 * clicks on one of its menuitems. When a menu is active,
 * passing the mouse over a submenu will pop it up.
 * 
 * There is also is a concept of the current menu and a current
 * menu item. The current menu item is the selected menu item
 * that is furthest down in the hierarchy. (Every active menu shell
 * does not necessarily contain a selected menu item, but if
 * it does, then the parent menu shell must also contain
 * a selected menu item.) The current menu is the menu that
 * contains the current menu item. It will always have a GTK
 * grab and receive all key presses.
 *
 */
@interface OGTKMenuShell : OGTKContainer
{

}


/**
 * Methods
 */

- (GtkMenuShell*)MENUSHELL;

/**
 * Activates the menu item within the menu shell.
 *
 * @param menuItem the #GtkMenuItem to activate
 * @param forceDeactivate if %TRUE, force the deactivation of the
 *     menu shell after the menu item is activated
 */
- (void)activateItemWithMenuItem:(OGTKWidget*)menuItem forceDeactivate:(bool)forceDeactivate;

/**
 * Adds a new #GtkMenuItem to the end of the menu shell's
 * item list.
 *
 * @param child The #GtkMenuItem to add
 */
- (void)append:(OGTKWidget*)child;

/**
 * Establishes a binding between a #GtkMenuShell and a #GMenuModel.
 * 
 * The contents of @shell are removed and then refilled with menu items
 * according to @model.  When @model changes, @shell is updated.
 * Calling this function twice on @shell with different @model will
 * cause the first binding to be replaced with a binding to the new
 * model. If @model is %NULL then any previous binding is undone and
 * all children are removed.
 * 
 * @with_separators determines if toplevel items (eg: sections) have
 * separators inserted between them.  This is typically desired for
 * menus but doesn’t make sense for menubars.
 * 
 * If @action_namespace is non-%NULL then the effect is as if all
 * actions mentioned in the @model have their names prefixed with the
 * namespace, plus a dot.  For example, if the action “quit” is
 * mentioned and @action_namespace is “app” then the effective action
 * name is “app.quit”.
 * 
 * This function uses #GtkActionable to define the action name and
 * target values on the created menu items.  If you want to use an
 * action group other than “app” and “win”, or if you want to use a
 * #GtkMenuShell outside of a #GtkApplicationWindow, then you will need
 * to attach your own action group to the widget hierarchy using
 * gtk_widget_insert_action_group().  As an example, if you created a
 * group with a “quit” action and inserted it with the name “mygroup”
 * then you would use the action name “mygroup.quit” in your
 * #GMenuModel.
 * 
 * For most cases you are probably better off using
 * gtk_menu_new_from_model() or gtk_menu_bar_new_from_model() or just
 * directly passing the #GMenuModel to gtk_application_set_app_menu() or
 * gtk_application_set_menubar().
 *
 * @param model the #GMenuModel to bind to or %NULL to remove
 *   binding
 * @param actionNamespace the namespace for actions in @model
 * @param withSeparators %TRUE if toplevel items in @shell should have
 *   separators between them
 */
- (void)bindModelWithModel:(GMenuModel*)model actionNamespace:(OFString*)actionNamespace withSeparators:(bool)withSeparators;

/**
 * Cancels the selection within the menu shell.
 *
 */
- (void)cancel;

/**
 * Deactivates the menu shell.
 * 
 * Typically this results in the menu shell being erased
 * from the screen.
 *
 */
- (void)deactivate;

/**
 * Deselects the currently selected item from the menu shell,
 * if any.
 *
 */
- (void)deselect;

/**
 * Gets the parent menu shell.
 * 
 * The parent menu shell of a submenu is the #GtkMenu or #GtkMenuBar
 * from which it was opened up.
 *
 * @return the parent #GtkMenuShell
 */
- (OGTKWidget*)parentShell;

/**
 * Gets the currently selected item.
 *
 * @return the currently selected item
 */
- (OGTKWidget*)selectedItem;

/**
 * Returns %TRUE if the menu shell will take the keyboard focus on popup.
 *
 * @return %TRUE if the menu shell will take the keyboard focus on popup.
 */
- (bool)takeFocus;

/**
 * Adds a new #GtkMenuItem to the menu shell’s item list
 * at the position indicated by @position.
 *
 * @param child The #GtkMenuItem to add
 * @param position The position in the item list where @child
 *     is added. Positions are numbered from 0 to n-1
 */
- (void)insertWithChild:(OGTKWidget*)child position:(gint)position;

/**
 * Adds a new #GtkMenuItem to the beginning of the menu shell's
 * item list.
 *
 * @param child The #GtkMenuItem to add
 */
- (void)prepend:(OGTKWidget*)child;

/**
 * Select the first visible or selectable child of the menu shell;
 * don’t select tearoff items unless the only item is a tearoff
 * item.
 *
 * @param searchSensitive if %TRUE, search for the first selectable
 *                    menu item, otherwise select nothing if
 *                    the first item isn’t sensitive. This
 *                    should be %FALSE if the menu is being
 *                    popped up initially.
 */
- (void)selectFirst:(bool)searchSensitive;

/**
 * Selects the menu item from the menu shell.
 *
 * @param menuItem The #GtkMenuItem to select
 */
- (void)selectItem:(OGTKWidget*)menuItem;

/**
 * If @take_focus is %TRUE (the default) the menu shell will take
 * the keyboard focus so that it will receive all keyboard events
 * which is needed to enable keyboard navigation in menus.
 * 
 * Setting @take_focus to %FALSE is useful only for special applications
 * like virtual keyboard implementations which should not take keyboard
 * focus.
 * 
 * The @take_focus state of a menu or menu bar is automatically
 * propagated to submenus whenever a submenu is popped up, so you
 * don’t have to worry about recursively setting it for your entire
 * menu hierarchy. Only when programmatically picking a submenu and
 * popping it up manually, the @take_focus property of the submenu
 * needs to be set explicitly.
 * 
 * Note that setting it to %FALSE has side-effects:
 * 
 * If the focus is in some other app, it keeps the focus and keynav in
 * the menu doesn’t work. Consequently, keynav on the menu will only
 * work if the focus is on some toplevel owned by the onscreen keyboard.
 * 
 * To avoid confusing the user, menus with @take_focus set to %FALSE
 * should not display mnemonics or accelerators, since it cannot be
 * guaranteed that they will work.
 * 
 * See also gdk_keyboard_grab()
 *
 * @param takeFocus %TRUE if the menu shell should take the keyboard
 *     focus on popup
 */
- (void)setTakeFocus:(bool)takeFocus;

@end