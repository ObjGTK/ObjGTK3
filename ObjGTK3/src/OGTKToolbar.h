/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKWidget;
@class OGTKToolItem;

/**
 * A toolbar is created with a call to gtk_toolbar_new().
 * 
 * A toolbar can contain instances of a subclass of #GtkToolItem. To add
 * a #GtkToolItem to the a toolbar, use gtk_toolbar_insert(). To remove
 * an item from the toolbar use gtk_container_remove(). To add a button
 * to the toolbar, add an instance of #GtkToolButton.
 * 
 * Toolbar items can be visually grouped by adding instances of
 * #GtkSeparatorToolItem to the toolbar. If the GtkToolbar child property
 * “expand” is #TRUE and the property #GtkSeparatorToolItem:draw is set to
 * #FALSE, the effect is to force all following items to the end of the toolbar.
 * 
 * By default, a toolbar can be shrunk, upon which it will add an arrow button
 * to show an overflow menu offering access to any #GtkToolItem child that has
 * a proxy menu item. To disable this and request enough size for all children,
 * call gtk_toolbar_set_show_arrow() to set #GtkToolbar:show-arrow to %FALSE.
 * 
 * Creating a context menu for the toolbar can be done by connecting to
 * the #GtkToolbar::popup-context-menu signal.
 * 
 * # CSS nodes
 * 
 * GtkToolbar has a single CSS node with name toolbar.
 *
 */
@interface OGTKToolbar : OGTKContainer
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkToolbar*)TOOLBAR;

/**
 * Returns the position corresponding to the indicated point on
 * @toolbar. This is useful when dragging items to the toolbar:
 * this function returns the position a new item should be
 * inserted.
 * 
 * @x and @y are in @toolbar coordinates.
 *
 * @param x x coordinate of a point on the toolbar
 * @param y y coordinate of a point on the toolbar
 * @return The position corresponding to the point (@x, @y) on the toolbar.
 */
- (gint)dropIndexWithX:(gint)x y:(gint)y;

/**
 * Retrieves the icon size for the toolbar. See gtk_toolbar_set_icon_size().
 *
 * @return the current icon size for the icons on the toolbar.
 */
- (GtkIconSize)iconSize;

/**
 * Returns the position of @item on the toolbar, starting from 0.
 * It is an error if @item is not a child of the toolbar.
 *
 * @param item a #GtkToolItem that is a child of @toolbar
 * @return the position of item on the toolbar.
 */
- (gint)itemIndex:(OGTKToolItem*)item;

/**
 * Returns the number of items on the toolbar.
 *
 * @return the number of items on the toolbar
 */
- (gint)nitems;

/**
 * Returns the @n'th item on @toolbar, or %NULL if the
 * toolbar does not contain an @n'th item.
 *
 * @param n A position on the toolbar
 * @return The @n'th #GtkToolItem on @toolbar,
 *     or %NULL if there isn’t an @n'th item.
 */
- (OGTKToolItem*)nthItem:(gint)n;

/**
 * Returns the relief style of buttons on @toolbar. See
 * gtk_button_set_relief().
 *
 * @return The relief style of buttons on @toolbar.
 */
- (GtkReliefStyle)reliefStyle;

/**
 * Returns whether the toolbar has an overflow menu.
 * See gtk_toolbar_set_show_arrow().
 *
 * @return %TRUE if the toolbar has an overflow menu.
 */
- (bool)showArrow;

/**
 * Retrieves whether the toolbar has text, icons, or both . See
 * gtk_toolbar_set_style().
 *
 * @return the current style of @toolbar
 */
- (GtkToolbarStyle)style;

/**
 * Insert a #GtkToolItem into the toolbar at position @pos. If @pos is
 * 0 the item is prepended to the start of the toolbar. If @pos is
 * negative, the item is appended to the end of the toolbar.
 *
 * @param item a #GtkToolItem
 * @param pos the position of the new item
 */
- (void)insertWithItem:(OGTKToolItem*)item pos:(gint)pos;

/**
 * Highlights @toolbar to give an idea of what it would look like
 * if @item was added to @toolbar at the position indicated by @index_.
 * If @item is %NULL, highlighting is turned off. In that case @index_
 * is ignored.
 * 
 * The @tool_item passed to this function must not be part of any widget
 * hierarchy. When an item is set as drop highlight item it can not
 * added to any widget hierarchy or used as highlight item for another
 * toolbar.
 *
 * @param toolItem a #GtkToolItem, or %NULL to turn of highlighting
 * @param index a position on @toolbar
 */
- (void)setDropHighlightItemWithToolItem:(OGTKToolItem*)toolItem index:(gint)index;

/**
 * This function sets the size of stock icons in the toolbar. You
 * can call it both before you add the icons and after they’ve been
 * added. The size you set will override user preferences for the default
 * icon size.
 * 
 * This should only be used for special-purpose toolbars, normal
 * application toolbars should respect the user preferences for the
 * size of icons.
 *
 * @param iconSize The #GtkIconSize that stock icons in the toolbar shall have.
 */
- (void)setIconSize:(GtkIconSize)iconSize;

/**
 * Sets whether to show an overflow menu when @toolbar isn’t allocated enough
 * size to show all of its items. If %TRUE, items which can’t fit in @toolbar,
 * and which have a proxy menu item set by gtk_tool_item_set_proxy_menu_item()
 * or #GtkToolItem::create-menu-proxy, will be available in an overflow menu,
 * which can be opened by an added arrow button. If %FALSE, @toolbar will
 * request enough size to fit all of its child items without any overflow.
 *
 * @param showArrow Whether to show an overflow menu
 */
- (void)setShowArrow:(bool)showArrow;

/**
 * Alters the view of @toolbar to display either icons only, text only, or both.
 *
 * @param style the new style for @toolbar.
 */
- (void)setStyle:(GtkToolbarStyle)style;

/**
 * Unsets toolbar icon size set with gtk_toolbar_set_icon_size(), so that
 * user preferences will be used to determine the icon size.
 *
 */
- (void)unsetIconSize;

/**
 * Unsets a toolbar style set with gtk_toolbar_set_style(), so that
 * user preferences will be used to determine the toolbar style.
 *
 */
- (void)unsetStyle;

@end