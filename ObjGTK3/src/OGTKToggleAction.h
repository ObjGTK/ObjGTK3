/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAction.h"

/**
 * A #GtkToggleAction corresponds roughly to a #GtkCheckMenuItem. It has an
 * “active” state specifying whether the action has been checked or not.
 *
 */
@interface OGTKToggleAction : OGTKAction
{

}


/**
 * Constructors
 */
- (instancetype)initWithName:(OFString*)name label:(OFString*)label tooltip:(OFString*)tooltip stockId:(OFString*)stockId;

/**
 * Methods
 */

- (GtkToggleAction*)TOGGLEACTION;

/**
 * Returns the checked state of the toggle action.
 *
 * @return the checked state of the toggle action
 */
- (bool)active;

/**
 * Returns whether the action should have proxies like a radio action.
 *
 * @return whether the action should have proxies like a radio action.
 */
- (bool)drawAsRadio;

/**
 * Sets the checked state on the toggle action.
 *
 * @param isActive whether the action should be checked or not
 */
- (void)setActive:(bool)isActive;

/**
 * Sets whether the action should have proxies like a radio action.
 *
 * @param drawAsRadio whether the action should have proxies like a radio
 *    action
 */
- (void)setDrawAsRadio:(bool)drawAsRadio;

/**
 * Emits the “toggled” signal on the toggle action.
 *
 */
- (void)toggled;

@end