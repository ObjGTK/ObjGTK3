/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToolButton.h"

@class OGTKToolItem;
@class OGTKWidget;

/**
 * A #GtkMenuToolButton is a #GtkToolItem that contains a button and
 * a small additional button with an arrow. When clicked, the arrow
 * button pops up a dropdown menu.
 * 
 * Use gtk_menu_tool_button_new() to create a new
 * #GtkMenuToolButton.
 * 
 * # GtkMenuToolButton as GtkBuildable
 * 
 * The GtkMenuToolButton implementation of the GtkBuildable interface
 * supports adding a menu by specifying “menu” as the “type” attribute
 * of a <child> element.
 * 
 * An example for a UI definition fragment with menus:
 * |[
 * <object class="GtkMenuToolButton">
 *   <child type="menu">
 *     <object class="GtkMenu"/>
 *   </child>
 * </object>
 * ]|
 *
 */
@interface OGTKMenuToolButton : OGTKToolButton
{

}


/**
 * Constructors
 */
- (instancetype)initWithIconWidget:(OGTKWidget*)iconWidget label:(OFString*)label;
- (instancetype)initFromStock:(OFString*)stockId;

/**
 * Methods
 */

- (GtkMenuToolButton*)MENUTOOLBUTTON;

/**
 * Gets the #GtkMenu associated with #GtkMenuToolButton.
 *
 * @return the #GtkMenu associated
 *     with #GtkMenuToolButton
 */
- (OGTKWidget*)menu;

/**
 * Sets the tooltip markup text to be used as tooltip for the arrow button
 * which pops up the menu.  See gtk_tool_item_set_tooltip_text() for setting
 * a tooltip on the whole #GtkMenuToolButton.
 *
 * @param markup markup text to be used as tooltip text for button’s arrow button
 */
- (void)setArrowTooltipMarkup:(OFString*)markup;

/**
 * Sets the tooltip text to be used as tooltip for the arrow button which
 * pops up the menu.  See gtk_tool_item_set_tooltip_text() for setting a tooltip
 * on the whole #GtkMenuToolButton.
 *
 * @param text text to be used as tooltip text for button’s arrow button
 */
- (void)setArrowTooltipText:(OFString*)text;

/**
 * Sets the #GtkMenu that is popped up when the user clicks on the arrow.
 * If @menu is NULL, the arrow button becomes insensitive.
 *
 * @param menu the #GtkMenu associated with #GtkMenuToolButton
 */
- (void)setMenu:(OGTKWidget*)menu;

@end