/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToggleButton.h"

@class OGTKMenu;
@class OGTKWidget;
@class OGTKPopover;

/**
 * The #GtkMenuButton widget is used to display a popup when clicked on.
 * This popup can be provided either as a #GtkMenu, a #GtkPopover or an
 * abstract #GMenuModel.
 * 
 * The #GtkMenuButton widget can hold any valid child widget. That is, it
 * can hold almost any other standard #GtkWidget. The most commonly used
 * child is #GtkImage. If no widget is explicitely added to the #GtkMenuButton,
 * a #GtkImage is automatically created, using an arrow image oriented
 * according to #GtkMenuButton:direction or the generic “open-menu-symbolic”
 * icon if the direction is not set.
 * 
 * The positioning of the popup is determined by the #GtkMenuButton:direction
 * property of the menu button.
 * 
 * For menus, the #GtkWidget:halign and #GtkWidget:valign properties of the
 * menu are also taken into account. For example, when the direction is
 * %GTK_ARROW_DOWN and the horizontal alignment is %GTK_ALIGN_START, the
 * menu will be positioned below the button, with the starting edge
 * (depending on the text direction) of the menu aligned with the starting
 * edge of the button. If there is not enough space below the button, the
 * menu is popped up above the button instead. If the alignment would move
 * part of the menu offscreen, it is “pushed in”.
 * 
 * ## Direction = Down
 * 
 * - halign = start
 * 
 *     ![](down-start.png)
 * 
 * - halign = center
 * 
 *     ![](down-center.png)
 * 
 * - halign = end
 * 
 *     ![](down-end.png)
 * 
 * ## Direction = Up
 * 
 * - halign = start
 * 
 *     ![](up-start.png)
 * 
 * - halign = center
 * 
 *     ![](up-center.png)
 * 
 * - halign = end
 * 
 *     ![](up-end.png)
 * 
 * ## Direction = Left
 * 
 * - valign = start
 * 
 *     ![](left-start.png)
 * 
 * - valign = center
 * 
 *     ![](left-center.png)
 * 
 * - valign = end
 * 
 *     ![](left-end.png)
 * 
 * ## Direction = Right
 * 
 * - valign = start
 * 
 *     ![](right-start.png)
 * 
 * - valign = center
 * 
 *     ![](right-center.png)
 * 
 * - valign = end
 * 
 *     ![](right-end.png)
 * 
 * # CSS nodes
 * 
 * GtkMenuButton has a single CSS node with name button. To differentiate
 * it from a plain #GtkButton, it gets the .popup style class.
 *
 */
@interface OGTKMenuButton : OGTKToggleButton
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkMenuButton*)MENUBUTTON;

/**
 * Returns the parent #GtkWidget to use to line up with menu.
 *
 * @return a #GtkWidget value or %NULL
 */
- (OGTKWidget*)alignWidget;

/**
 * Returns the direction the popup will be pointing at when popped up.
 *
 * @return a #GtkArrowType value
 */
- (GtkArrowType)direction;

/**
 * Returns the #GMenuModel used to generate the popup.
 *
 * @return a #GMenuModel or %NULL
 */
- (GMenuModel*)menuModel;

/**
 * Returns the #GtkPopover that pops out of the button.
 * If the button is not using a #GtkPopover, this function
 * returns %NULL.
 *
 * @return a #GtkPopover or %NULL
 */
- (OGTKPopover*)popover;

/**
 * Returns the #GtkMenu that pops out of the button.
 * If the button does not use a #GtkMenu, this function
 * returns %NULL.
 *
 * @return a #GtkMenu or %NULL
 */
- (OGTKMenu*)popup;

/**
 * Returns whether a #GtkPopover or a #GtkMenu will be constructed
 * from the menu model.
 *
 * @return %TRUE if using a #GtkPopover
 */
- (bool)usePopover;

/**
 * Sets the #GtkWidget to use to line the menu with when popped up.
 * Note that the @align_widget must contain the #GtkMenuButton itself.
 * 
 * Setting it to %NULL means that the menu will be aligned with the
 * button itself.
 * 
 * Note that this property is only used with menus currently,
 * and not for popovers.
 *
 * @param alignWidget a #GtkWidget
 */
- (void)setAlignWidget:(OGTKWidget*)alignWidget;

/**
 * Sets the direction in which the popup will be popped up, as
 * well as changing the arrow’s direction. The child will not
 * be changed to an arrow if it was customized.
 * 
 * If the does not fit in the available space in the given direction,
 * GTK+ will its best to keep it inside the screen and fully visible.
 * 
 * If you pass %GTK_ARROW_NONE for a @direction, the popup will behave
 * as if you passed %GTK_ARROW_DOWN (although you won’t see any arrows).
 *
 * @param direction a #GtkArrowType
 */
- (void)setDirection:(GtkArrowType)direction;

/**
 * Sets the #GMenuModel from which the popup will be constructed,
 * or %NULL to dissociate any existing menu model and disable the button.
 * 
 * Depending on the value of #GtkMenuButton:use-popover, either a
 * #GtkMenu will be created with gtk_menu_new_from_model(), or a
 * #GtkPopover with gtk_popover_new_from_model(). In either case,
 * actions will be connected as documented for these functions.
 * 
 * If #GtkMenuButton:popup or #GtkMenuButton:popover are already set, those
 * widgets are dissociated from the @menu_button, and those properties are set
 * to %NULL.
 *
 * @param menuModel a #GMenuModel, or %NULL to unset and disable the
 *   button
 */
- (void)setMenuModel:(GMenuModel*)menuModel;

/**
 * Sets the #GtkPopover that will be popped up when the @menu_button is clicked,
 * or %NULL to dissociate any existing popover and disable the button.
 * 
 * If #GtkMenuButton:menu-model or #GtkMenuButton:popup are set, those objects
 * are dissociated from the @menu_button, and those properties are set to %NULL.
 *
 * @param popover a #GtkPopover, or %NULL to unset and disable the button
 */
- (void)setPopover:(OGTKWidget*)popover;

/**
 * Sets the #GtkMenu that will be popped up when the @menu_button is clicked, or
 * %NULL to dissociate any existing menu and disable the button.
 * 
 * If #GtkMenuButton:menu-model or #GtkMenuButton:popover are set, those objects
 * are dissociated from the @menu_button, and those properties are set to %NULL.
 *
 * @param menu a #GtkMenu, or %NULL to unset and disable the button
 */
- (void)setPopup:(OGTKWidget*)menu;

/**
 * Sets whether to construct a #GtkPopover instead of #GtkMenu
 * when gtk_menu_button_set_menu_model() is called. Note that
 * this property is only consulted when a new menu model is set.
 *
 * @param usePopover %TRUE to construct a popover from the menu model
 */
- (void)setUsePopover:(bool)usePopover;

@end