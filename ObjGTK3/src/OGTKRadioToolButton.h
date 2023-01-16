/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToggleToolButton.h"

@class OGTKToolItem;

/**
 * A #GtkRadioToolButton is a #GtkToolItem that contains a radio button,
 * that is, a button that is part of a group of toggle buttons where only
 * one button can be active at a time.
 * 
 * Use gtk_radio_tool_button_new() to create a new GtkRadioToolButton. Use
 * gtk_radio_tool_button_new_from_widget() to create a new GtkRadioToolButton
 * that is part of the same group as an existing GtkRadioToolButton.
 * 
 * # CSS nodes
 * 
 * GtkRadioToolButton has a single CSS node with name toolbutton.
 *
 */
@interface OGTKRadioToolButton : OGTKToggleToolButton
{

}


/**
 * Constructors
 */
- (instancetype)init:(GSList*)group;
- (instancetype)initFromStockWithGroup:(GSList*)group stockId:(OFString*)stockId;
- (instancetype)initFromWidget:(OGTKRadioToolButton*)group;
- (instancetype)initWithStockFromWidgetWithGroup:(OGTKRadioToolButton*)group stockId:(OFString*)stockId;

/**
 * Methods
 */

- (GtkRadioToolButton*)RADIOTOOLBUTTON;

/**
 * Returns the radio button group @button belongs to.
 *
 * @return The group @button belongs to.
 */
- (GSList*)group;

/**
 * Adds @button to @group, removing it from the group it belonged to before.
 *
 * @param group an existing radio button group, or %NULL
 */
- (void)setGroup:(GSList*)group;

@end