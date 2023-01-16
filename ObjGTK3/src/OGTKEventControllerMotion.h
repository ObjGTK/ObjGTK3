/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEventController.h"

@class OGTKWidget;

/**
 * #GtkEventControllerMotion is an event controller meant for situations
 * where you need to track the position of the pointer.
 * 
 * This object was added in 3.24.
 *
 */
@interface OGTKEventControllerMotion : OGTKEventController
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKWidget*)widget;

/**
 * Methods
 */

- (GtkEventControllerMotion*)EVENTCONTROLLERMOTION;

@end