/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKSizeGroup;
@class OGTKWidget;

/**
 * #GtkToolItems are widgets that can appear on a toolbar. To
 * create a toolbar item that contain something else than a button, use
 * gtk_tool_item_new(). Use gtk_container_add() to add a child
 * widget to the tool item.
 * 
 * For toolbar items that contain buttons, see the #GtkToolButton,
 * #GtkToggleToolButton and #GtkRadioToolButton classes.
 * 
 * See the #GtkToolbar class for a description of the toolbar widget, and
 * #GtkToolShell for a description of the tool shell interface.
 *
 */
@interface OGTKToolItem : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkToolItem*)TOOLITEM;

/**
 * Returns the ellipsize mode used for @tool_item. Custom subclasses of
 * #GtkToolItem should call this function to find out how text should
 * be ellipsized.
 *
 * @return a #PangoEllipsizeMode indicating how text in @tool_item
 * should be ellipsized.
 */
- (PangoEllipsizeMode)ellipsizeMode;

/**
 * Returns whether @tool_item is allocated extra space.
 * See gtk_tool_item_set_expand().
 *
 * @return %TRUE if @tool_item is allocated extra space.
 */
- (bool)expand;

/**
 * Returns whether @tool_item is the same size as other homogeneous
 * items. See gtk_tool_item_set_homogeneous().
 *
 * @return %TRUE if the item is the same size as other homogeneous
 * items.
 */
- (bool)homogeneous;

/**
 * Returns the icon size used for @tool_item. Custom subclasses of
 * #GtkToolItem should call this function to find out what size icons
 * they should use.
 *
 * @return a #GtkIconSize indicating the icon size
 * used for @tool_item
 */
- (GtkIconSize)iconSize;

/**
 * Returns whether @tool_item is considered important. See
 * gtk_tool_item_set_is_important()
 *
 * @return %TRUE if @tool_item is considered important.
 */
- (bool)isImportant;

/**
 * Returns the orientation used for @tool_item. Custom subclasses of
 * #GtkToolItem should call this function to find out what size icons
 * they should use.
 *
 * @return a #GtkOrientation indicating the orientation
 * used for @tool_item
 */
- (GtkOrientation)orientation;

/**
 * If @menu_item_id matches the string passed to
 * gtk_tool_item_set_proxy_menu_item() return the corresponding #GtkMenuItem.
 * 
 * Custom subclasses of #GtkToolItem should use this function to
 * update their menu item when the #GtkToolItem changes. That the
 * @menu_item_ids must match ensures that a #GtkToolItem
 * will not inadvertently change a menu item that they did not create.
 *
 * @param menuItemId a string used to identify the menu item
 * @return The #GtkMenuItem passed to
 *     gtk_tool_item_set_proxy_menu_item(), if the @menu_item_ids
 *     match.
 */
- (OGTKWidget*)proxyMenuItem:(OFString*)menuItemId;

/**
 * Returns the relief style of @tool_item. See gtk_button_set_relief().
 * Custom subclasses of #GtkToolItem should call this function in the handler
 * of the #GtkToolItem::toolbar_reconfigured signal to find out the
 * relief style of buttons.
 *
 * @return a #GtkReliefStyle indicating the relief style used
 * for @tool_item.
 */
- (GtkReliefStyle)reliefStyle;

/**
 * Returns the text alignment used for @tool_item. Custom subclasses of
 * #GtkToolItem should call this function to find out how text should
 * be aligned.
 *
 * @return a #gfloat indicating the horizontal text alignment
 * used for @tool_item
 */
- (gfloat)textAlignment;

/**
 * Returns the text orientation used for @tool_item. Custom subclasses of
 * #GtkToolItem should call this function to find out how text should
 * be orientated.
 *
 * @return a #GtkOrientation indicating the text orientation
 * used for @tool_item
 */
- (GtkOrientation)textOrientation;

/**
 * Returns the size group used for labels in @tool_item.
 * Custom subclasses of #GtkToolItem should call this function
 * and use the size group for labels.
 *
 * @return a #GtkSizeGroup
 */
- (OGTKSizeGroup*)textSizeGroup;

/**
 * Returns the toolbar style used for @tool_item. Custom subclasses of
 * #GtkToolItem should call this function in the handler of the
 * GtkToolItem::toolbar_reconfigured signal to find out in what style
 * the toolbar is displayed and change themselves accordingly
 * 
 * Possibilities are:
 * - %GTK_TOOLBAR_BOTH, meaning the tool item should show
 *   both an icon and a label, stacked vertically
 * - %GTK_TOOLBAR_ICONS, meaning the toolbar shows only icons
 * - %GTK_TOOLBAR_TEXT, meaning the tool item should only show text
 * - %GTK_TOOLBAR_BOTH_HORIZ, meaning the tool item should show
 *   both an icon and a label, arranged horizontally
 *
 * @return A #GtkToolbarStyle indicating the toolbar style used
 * for @tool_item.
 */
- (GtkToolbarStyle)toolbarStyle;

/**
 * Returns whether @tool_item has a drag window. See
 * gtk_tool_item_set_use_drag_window().
 *
 * @return %TRUE if @tool_item uses a drag window.
 */
- (bool)useDragWindow;

/**
 * Returns whether the @tool_item is visible on toolbars that are
 * docked horizontally.
 *
 * @return %TRUE if @tool_item is visible on toolbars that are
 * docked horizontally.
 */
- (bool)visibleHorizontal;

/**
 * Returns whether @tool_item is visible when the toolbar is docked vertically.
 * See gtk_tool_item_set_visible_vertical().
 *
 * @return Whether @tool_item is visible when the toolbar is docked vertically
 */
- (bool)visibleVertical;

/**
 * Calling this function signals to the toolbar that the
 * overflow menu item for @tool_item has changed. If the
 * overflow menu is visible when this function it called,
 * the menu will be rebuilt.
 * 
 * The function must be called when the tool item changes what it
 * will do in response to the #GtkToolItem::create-menu-proxy signal.
 *
 */
- (void)rebuildMenu;

/**
 * Returns the #GtkMenuItem that was last set by
 * gtk_tool_item_set_proxy_menu_item(), ie. the #GtkMenuItem
 * that is going to appear in the overflow menu.
 *
 * @return The #GtkMenuItem that is going to appear in the
 * overflow menu for @tool_item.
 */
- (OGTKWidget*)retrieveProxyMenuItem;

/**
 * Sets whether @tool_item is allocated extra space when there
 * is more room on the toolbar then needed for the items. The
 * effect is that the item gets bigger when the toolbar gets bigger
 * and smaller when the toolbar gets smaller.
 *
 * @param expand Whether @tool_item is allocated extra space
 */
- (void)setExpand:(bool)expand;

/**
 * Sets whether @tool_item is to be allocated the same size as other
 * homogeneous items. The effect is that all homogeneous items will have
 * the same width as the widest of the items.
 *
 * @param homogeneous whether @tool_item is the same size as other homogeneous items
 */
- (void)setHomogeneous:(bool)homogeneous;

/**
 * Sets whether @tool_item should be considered important. The #GtkToolButton
 * class uses this property to determine whether to show or hide its label
 * when the toolbar style is %GTK_TOOLBAR_BOTH_HORIZ. The result is that
 * only tool buttons with the “is_important” property set have labels, an
 * effect known as “priority text”
 *
 * @param isImportant whether the tool item should be considered important
 */
- (void)setIsImportant:(bool)isImportant;

/**
 * Sets the #GtkMenuItem used in the toolbar overflow menu. The
 * @menu_item_id is used to identify the caller of this function and
 * should also be used with gtk_tool_item_get_proxy_menu_item().
 * 
 * See also #GtkToolItem::create-menu-proxy.
 *
 * @param menuItemId a string used to identify @menu_item
 * @param menuItem a #GtkMenuItem to use in the overflow menu, or %NULL
 */
- (void)setProxyMenuItemWithMenuItemId:(OFString*)menuItemId menuItem:(OGTKWidget*)menuItem;

/**
 * Sets the markup text to be displayed as tooltip on the item.
 * See gtk_widget_set_tooltip_markup().
 *
 * @param markup markup text to be used as tooltip for @tool_item
 */
- (void)setTooltipMarkup:(OFString*)markup;

/**
 * Sets the text to be displayed as tooltip on the item.
 * See gtk_widget_set_tooltip_text().
 *
 * @param text text to be used as tooltip for @tool_item
 */
- (void)setTooltipText:(OFString*)text;

/**
 * Sets whether @tool_item has a drag window. When %TRUE the
 * toolitem can be used as a drag source through gtk_drag_source_set().
 * When @tool_item has a drag window it will intercept all events,
 * even those that would otherwise be sent to a child of @tool_item.
 *
 * @param useDragWindow Whether @tool_item has a drag window.
 */
- (void)setUseDragWindow:(bool)useDragWindow;

/**
 * Sets whether @tool_item is visible when the toolbar is docked horizontally.
 *
 * @param visibleHorizontal Whether @tool_item is visible when in horizontal mode
 */
- (void)setVisibleHorizontal:(bool)visibleHorizontal;

/**
 * Sets whether @tool_item is visible when the toolbar is docked
 * vertically. Some tool items, such as text entries, are too wide to be
 * useful on a vertically docked toolbar. If @visible_vertical is %FALSE
 * @tool_item will not appear on toolbars that are docked vertically.
 *
 * @param visibleVertical whether @tool_item is visible when the toolbar
 * is in vertical mode
 */
- (void)setVisibleVertical:(bool)visibleVertical;

/**
 * Emits the signal #GtkToolItem::toolbar_reconfigured on @tool_item.
 * #GtkToolbar and other #GtkToolShell implementations use this function
 * to notify children, when some aspect of their configuration changes.
 *
 */
- (void)toolbarReconfigured;

@end