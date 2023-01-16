/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWidget.h"

/**
 * #GtkSwitch is a widget that has two states: on or off. The user can control
 * which state should be active by clicking the empty area, or by dragging the
 * handle.
 * 
 * GtkSwitch can also handle situations where the underlying state changes with
 * a delay. See #GtkSwitch::state-set for details.
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * switch
 * ╰── slider
 * ]|
 * 
 * GtkSwitch has two css nodes, the main node with the name switch and a subnode
 * named slider. Neither of them is using any style classes.
 *
 */
@interface OGTKSwitch : OGTKWidget
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkSwitch*)SWITCH;

/**
 * Gets whether the #GtkSwitch is in its “on” or “off” state.
 *
 * @return %TRUE if the #GtkSwitch is active, and %FALSE otherwise
 */
- (bool)active;

/**
 * Gets the underlying state of the #GtkSwitch.
 *
 * @return the underlying state
 */
- (bool)state;

/**
 * Changes the state of @sw to the desired one.
 *
 * @param isActive %TRUE if @sw should be active, and %FALSE otherwise
 */
- (void)setActive:(bool)isActive;

/**
 * Sets the underlying state of the #GtkSwitch.
 * 
 * Normally, this is the same as #GtkSwitch:active, unless the switch
 * is set up for delayed state changes. This function is typically
 * called from a #GtkSwitch::state-set signal handler.
 * 
 * See #GtkSwitch::state-set for details.
 *
 * @param state the new state
 */
- (void)setState:(bool)state;

@end