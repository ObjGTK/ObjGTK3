/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToolButton.h"

@class OGTKToolItem;

/**
 * A #GtkToggleToolButton is a #GtkToolItem that contains a toggle
 * button.
 * 
 * Use gtk_toggle_tool_button_new() to create a new GtkToggleToolButton.
 * 
 * # CSS nodes
 * 
 * GtkToggleToolButton has a single CSS node with name togglebutton.
 *
 */
@interface OGTKToggleToolButton : OGTKToolButton
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initFromStock:(OFString*)stockId;

/**
 * Methods
 */

- (GtkToggleToolButton*)TOGGLETOOLBUTTON;

/**
 * Queries a #GtkToggleToolButton and returns its current state.
 * Returns %TRUE if the toggle button is pressed in and %FALSE if it is raised.
 *
 * @return %TRUE if the toggle tool button is pressed in, %FALSE if not
 */
- (bool)active;

/**
 * Sets the status of the toggle tool button. Set to %TRUE if you
 * want the GtkToggleButton to be “pressed in”, and %FALSE to raise it.
 * This action causes the toggled signal to be emitted.
 *
 * @param isActive whether @button should be active
 */
- (void)setActive:(bool)isActive;

@end