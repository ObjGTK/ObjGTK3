/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEventController.h"

@class OGTKWidget;
@class OGTKIMContext;

/**
 * #GtkEventControllerKey is an event controller meant for situations
 * where you need access to key events.
 * 
 * This object was added in 3.24.
 *
 */
@interface OGTKEventControllerKey : OGTKEventController
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKWidget*)widget;

/**
 * Methods
 */

- (GtkEventControllerKey*)EVENTCONTROLLERKEY;

/**
 *
 * @param widget
 * @return
 */
- (bool)forward:(OGTKWidget*)widget;

/**
 *
 * @return
 */
- (guint)group;

/**
 * Gets the IM context of a key controller.
 *
 * @return the IM context
 */
- (OGTKIMContext*)imContext;

/**
 *
 * @param imContext
 */
- (void)setImContext:(OGTKIMContext*)imContext;

@end