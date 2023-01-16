/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

@class OGTKWidget;
@class OGTKAccelGroup;

/**
 * > In GTK+ 3.10, GtkAction has been deprecated. Use #GAction
 * > instead, and associate actions with #GtkActionable widgets. Use
 * > #GMenuModel for creating menus with gtk_menu_new_from_model().
 * 
 * Actions represent operations that the user can be perform, along with
 * some information how it should be presented in the interface. Each action
 * provides methods to create icons, menu items and toolbar items
 * representing itself.
 * 
 * As well as the callback that is called when the action gets activated,
 * the following also gets associated with the action:
 * 
 * - a name (not translated, for path lookup)
 * 
 * - a label (translated, for display)
 * 
 * - an accelerator
 * 
 * - whether label indicates a stock id
 * 
 * - a tooltip (optional, translated)
 * 
 * - a toolbar label (optional, shorter than label)
 * 
 * 
 * The action will also have some state information:
 * 
 * - visible (shown/hidden)
 * 
 * - sensitive (enabled/disabled)
 * 
 * Apart from regular actions, there are [toggle actions][GtkToggleAction],
 * which can be toggled between two states and
 * [radio actions][GtkRadioAction], of which only one in a group
 * can be in the “active” state. Other actions can be implemented as #GtkAction
 * subclasses.
 * 
 * Each action can have one or more proxy widgets. To act as an action proxy,
 * widget needs to implement #GtkActivatable interface. Proxies mirror the state
 * of the action and should change when the action’s state changes. Properties
 * that are always mirrored by proxies are #GtkAction:sensitive and
 * #GtkAction:visible. #GtkAction:gicon, #GtkAction:icon-name, #GtkAction:label,
 * #GtkAction:short-label and #GtkAction:stock-id properties are only mirorred
 * if proxy widget has #GtkActivatable:use-action-appearance property set to
 * %TRUE.
 * 
 * When the proxy is activated, it should activate its action.
 *
 */
@interface OGTKAction : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)initWithName:(OFString*)name label:(OFString*)label tooltip:(OFString*)tooltip stockId:(OFString*)stockId;

/**
 * Methods
 */

- (GtkAction*)ACTION;

/**
 * Emits the “activate” signal on the specified action, if it isn't
 * insensitive. This gets called by the proxy widgets when they get
 * activated.
 * 
 * It can also be used to manually activate an action.
 *
 */
- (void)activate;

/**
 * Disable activation signals from the action
 * 
 * This is needed when updating the state of your proxy
 * #GtkActivatable widget could result in calling gtk_action_activate(),
 * this is a convenience function to avoid recursing in those
 * cases (updating toggle state for instance).
 *
 */
- (void)blockActivate;

/**
 * Installs the accelerator for @action if @action has an
 * accel path and group. See gtk_action_set_accel_path() and
 * gtk_action_set_accel_group()
 * 
 * Since multiple proxies may independently trigger the installation
 * of the accelerator, the @action counts the number of times this
 * function has been called and doesn’t remove the accelerator until
 * gtk_action_disconnect_accelerator() has been called as many times.
 *
 */
- (void)connectAccelerator;

/**
 * This function is intended for use by action implementations to
 * create icons displayed in the proxy widgets.
 *
 * @param iconSize the size of the icon (#GtkIconSize) that should
 *      be created.
 * @return a widget that displays the icon for this action.
 */
- (OGTKWidget*)createIcon:(GtkIconSize)iconSize;

/**
 * If @action provides a #GtkMenu widget as a submenu for the menu
 * item or the toolbar item it creates, this function returns an
 * instance of that menu.
 *
 * @return the menu item provided by the
 *               action, or %NULL.
 */
- (OGTKWidget*)createMenu;

/**
 * Creates a menu item widget that proxies for the given action.
 *
 * @return a menu item connected to the action.
 */
- (OGTKWidget*)createMenuItem;

/**
 * Creates a toolbar item widget that proxies for the given action.
 *
 * @return a toolbar item connected to the action.
 */
- (OGTKWidget*)createToolItem;

/**
 * Undoes the effect of one call to gtk_action_connect_accelerator().
 *
 */
- (void)disconnectAccelerator;

/**
 * Returns the accel closure for this action.
 *
 * @return the accel closure for this action. The
 *          returned closure is owned by GTK+ and must not be unreffed
 *          or modified.
 */
- (GClosure*)accelClosure;

/**
 * Returns the accel path for this action.
 *
 * @return the accel path for this action, or %NULL
 *   if none is set. The returned string is owned by GTK+
 *   and must not be freed or modified.
 */
- (OFString*)accelPath;

/**
 * Returns whether @action's menu item proxies will always
 * show their image, if available.
 *
 * @return %TRUE if the menu item proxies will always show their image
 */
- (bool)alwaysShowImage;

/**
 * Gets the gicon of @action.
 *
 * @return The action’s #GIcon if one is set.
 */
- (GIcon*)gicon;

/**
 * Gets the icon name of @action.
 *
 * @return the icon name
 */
- (OFString*)iconName;

/**
 * Checks whether @action is important or not
 *
 * @return whether @action is important
 */
- (bool)isImportant;

/**
 * Gets the label text of @action.
 *
 * @return the label text
 */
- (OFString*)label;

/**
 * Returns the name of the action.
 *
 * @return the name of the action. The string belongs to GTK+ and should not
 *   be freed.
 */
- (OFString*)name;

/**
 * Returns the proxy widgets for an action.
 * See also gtk_activatable_get_related_action().
 *
 * @return a #GSList of proxy widgets. The list is owned by GTK+
 * and must not be modified.
 */
- (GSList*)proxies;

/**
 * Returns whether the action itself is sensitive. Note that this doesn’t
 * necessarily mean effective sensitivity. See gtk_action_is_sensitive()
 * for that.
 *
 * @return %TRUE if the action itself is sensitive.
 */
- (bool)sensitive;

/**
 * Gets the short label text of @action.
 *
 * @return the short label text.
 */
- (OFString*)shortLabel;

/**
 * Gets the stock id of @action.
 *
 * @return the stock id
 */
- (OFString*)stockId;

/**
 * Gets the tooltip text of @action.
 *
 * @return the tooltip text
 */
- (OFString*)tooltip;

/**
 * Returns whether the action itself is visible. Note that this doesn’t
 * necessarily mean effective visibility. See gtk_action_is_sensitive()
 * for that.
 *
 * @return %TRUE if the action itself is visible.
 */
- (bool)visible;

/**
 * Checks whether @action is visible when horizontal
 *
 * @return whether @action is visible when horizontal
 */
- (bool)visibleHorizontal;

/**
 * Checks whether @action is visible when horizontal
 *
 * @return whether @action is visible when horizontal
 */
- (bool)visibleVertical;

/**
 * Returns whether the action is effectively sensitive.
 *
 * @return %TRUE if the action and its associated action group
 * are both sensitive.
 */
- (bool)isSensitive;

/**
 * Returns whether the action is effectively visible.
 *
 * @return %TRUE if the action and its associated action group
 * are both visible.
 */
- (bool)isVisible;

/**
 * Sets the #GtkAccelGroup in which the accelerator for this action
 * will be installed.
 *
 * @param accelGroup a #GtkAccelGroup or %NULL
 */
- (void)setAccelGroup:(OGTKAccelGroup*)accelGroup;

/**
 * Sets the accel path for this action.  All proxy widgets associated
 * with the action will have this accel path, so that their
 * accelerators are consistent.
 * 
 * Note that @accel_path string will be stored in a #GQuark. Therefore, if you
 * pass a static string, you can save some memory by interning it first with
 * g_intern_static_string().
 *
 * @param accelPath the accelerator path
 */
- (void)setAccelPath:(OFString*)accelPath;

/**
 * Sets whether @action's menu item proxies will ignore the
 * #GtkSettings:gtk-menu-images setting and always show their image, if available.
 * 
 * Use this if the menu item would be useless or hard to use
 * without their image.
 *
 * @param alwaysShow %TRUE if menuitem proxies should always show their image
 */
- (void)setAlwaysShowImage:(bool)alwaysShow;

/**
 * Sets the icon of @action.
 *
 * @param icon the #GIcon to set
 */
- (void)setGicon:(GIcon*)icon;

/**
 * Sets the icon name on @action
 *
 * @param iconName the icon name to set
 */
- (void)setIconName:(OFString*)iconName;

/**
 * Sets whether the action is important, this attribute is used
 * primarily by toolbar items to decide whether to show a label
 * or not.
 *
 * @param isImportant %TRUE to make the action important
 */
- (void)setIsImportant:(bool)isImportant;

/**
 * Sets the label of @action.
 *
 * @param label the label text to set
 */
- (void)setLabel:(OFString*)label;

/**
 * Sets the :sensitive property of the action to @sensitive. Note that
 * this doesn’t necessarily mean effective sensitivity. See
 * gtk_action_is_sensitive()
 * for that.
 *
 * @param sensitive %TRUE to make the action sensitive
 */
- (void)setSensitive:(bool)sensitive;

/**
 * Sets a shorter label text on @action.
 *
 * @param shortLabel the label text to set
 */
- (void)setShortLabel:(OFString*)shortLabel;

/**
 * Sets the stock id on @action
 *
 * @param stockId the stock id
 */
- (void)setStockId:(OFString*)stockId;

/**
 * Sets the tooltip text on @action
 *
 * @param tooltip the tooltip text
 */
- (void)setTooltip:(OFString*)tooltip;

/**
 * Sets the :visible property of the action to @visible. Note that
 * this doesn’t necessarily mean effective visibility. See
 * gtk_action_is_visible()
 * for that.
 *
 * @param visible %TRUE to make the action visible
 */
- (void)setVisible:(bool)visible;

/**
 * Sets whether @action is visible when horizontal
 *
 * @param visibleHorizontal whether the action is visible horizontally
 */
- (void)setVisibleHorizontal:(bool)visibleHorizontal;

/**
 * Sets whether @action is visible when vertical
 *
 * @param visibleVertical whether the action is visible vertically
 */
- (void)setVisibleVertical:(bool)visibleVertical;

/**
 * Reenable activation signals from the action
 *
 */
- (void)unblockActivate;

@end