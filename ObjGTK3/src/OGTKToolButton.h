/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToolItem.h"

@class OGTKWidget;

/**
 * #GtkToolButtons are #GtkToolItems containing buttons.
 * 
 * Use gtk_tool_button_new() to create a new #GtkToolButton.
 * 
 * The label of a #GtkToolButton is determined by the properties
 * #GtkToolButton:label-widget, #GtkToolButton:label, and
 * #GtkToolButton:stock-id. If #GtkToolButton:label-widget is
 * non-%NULL, then that widget is used as the label. Otherwise, if
 * #GtkToolButton:label is non-%NULL, that string is used as the label.
 * Otherwise, if #GtkToolButton:stock-id is non-%NULL, the label is
 * determined by the stock item. Otherwise, the button does not have a label.
 * 
 * The icon of a #GtkToolButton is determined by the properties
 * #GtkToolButton:icon-widget and #GtkToolButton:stock-id. If
 * #GtkToolButton:icon-widget is non-%NULL, then
 * that widget is used as the icon. Otherwise, if #GtkToolButton:stock-id is
 * non-%NULL, the icon is determined by the stock item. Otherwise,
 * the button does not have a icon.
 * 
 * # CSS nodes
 * 
 * GtkToolButton has a single CSS node with name toolbutton.
 *
 */
@interface OGTKToolButton : OGTKToolItem
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

- (GtkToolButton*)TOOLBUTTON;

/**
 * Returns the name of the themed icon for the tool button,
 * see gtk_tool_button_set_icon_name().
 *
 * @return the icon name or %NULL if the tool button has
 * no themed icon
 */
- (OFString*)iconName;

/**
 * Return the widget used as icon widget on @button.
 * See gtk_tool_button_set_icon_widget().
 *
 * @return The widget used as icon
 *     on @button, or %NULL.
 */
- (OGTKWidget*)iconWidget;

/**
 * Returns the label used by the tool button, or %NULL if the tool button
 * doesn’t have a label. or uses a the label from a stock item. The returned
 * string is owned by GTK+, and must not be modified or freed.
 *
 * @return The label, or %NULL
 */
- (OFString*)label;

/**
 * Returns the widget used as label on @button.
 * See gtk_tool_button_set_label_widget().
 *
 * @return The widget used as label
 *     on @button, or %NULL.
 */
- (OGTKWidget*)labelWidget;

/**
 * Returns the name of the stock item. See gtk_tool_button_set_stock_id().
 * The returned string is owned by GTK+ and must not be freed or modifed.
 *
 * @return the name of the stock item for @button.
 */
- (OFString*)stockId;

/**
 * Returns whether underscores in the label property are used as mnemonics
 * on menu items on the overflow menu. See gtk_tool_button_set_use_underline().
 *
 * @return %TRUE if underscores in the label property are used as
 * mnemonics on menu items on the overflow menu.
 */
- (bool)useUnderline;

/**
 * Sets the icon for the tool button from a named themed icon.
 * See the docs for #GtkIconTheme for more details.
 * The #GtkToolButton:icon-name property only has an effect if not
 * overridden by non-%NULL #GtkToolButton:label-widget,
 * #GtkToolButton:icon-widget and #GtkToolButton:stock-id properties.
 *
 * @param iconName the name of the themed icon
 */
- (void)setIconName:(OFString*)iconName;

/**
 * Sets @icon as the widget used as icon on @button. If @icon_widget is
 * %NULL the icon is determined by the #GtkToolButton:stock-id property. If the
 * #GtkToolButton:stock-id property is also %NULL, @button will not have an icon.
 *
 * @param iconWidget the widget used as icon, or %NULL
 */
- (void)setIconWidget:(OGTKWidget*)iconWidget;

/**
 * Sets @label as the label used for the tool button. The #GtkToolButton:label
 * property only has an effect if not overridden by a non-%NULL
 * #GtkToolButton:label-widget property. If both the #GtkToolButton:label-widget
 * and #GtkToolButton:label properties are %NULL, the label is determined by the
 * #GtkToolButton:stock-id property. If the #GtkToolButton:stock-id property is
 * also %NULL, @button will not have a label.
 *
 * @param label a string that will be used as label, or %NULL.
 */
- (void)setLabel:(OFString*)label;

/**
 * Sets @label_widget as the widget that will be used as the label
 * for @button. If @label_widget is %NULL the #GtkToolButton:label property is used
 * as label. If #GtkToolButton:label is also %NULL, the label in the stock item
 * determined by the #GtkToolButton:stock-id property is used as label. If
 * #GtkToolButton:stock-id is also %NULL, @button does not have a label.
 *
 * @param labelWidget the widget used as label, or %NULL
 */
- (void)setLabelWidget:(OGTKWidget*)labelWidget;

/**
 * Sets the name of the stock item. See gtk_tool_button_new_from_stock().
 * The stock_id property only has an effect if not overridden by non-%NULL
 * #GtkToolButton:label-widget and #GtkToolButton:icon-widget properties.
 *
 * @param stockId a name of a stock item, or %NULL
 */
- (void)setStockId:(OFString*)stockId;

/**
 * If set, an underline in the label property indicates that the next character
 * should be used for the mnemonic accelerator key in the overflow menu. For
 * example, if the label property is “_Open” and @use_underline is %TRUE,
 * the label on the tool button will be “Open” and the item on the overflow
 * menu will have an underlined “O”.
 * 
 * Labels shown on tool buttons never have mnemonics on them; this property
 * only affects the menu item on the overflow menu.
 *
 * @param useUnderline whether the button label has the form “_Open”
 */
- (void)setUseUnderline:(bool)useUnderline;

@end