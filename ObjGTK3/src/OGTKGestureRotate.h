/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGesture.h"

@class OGTKWidget;

/**
 * #GtkGestureRotate is a #GtkGesture implementation able to recognize
 * 2-finger rotations, whenever the angle between both handled sequences
 * changes, the #GtkGestureRotate::angle-changed signal is emitted.
 *
 */
@interface OGTKGestureRotate : OGTKGesture
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKWidget*)widget;

/**
 * Methods
 */

- (GtkGestureRotate*)GESTUREROTATE;

/**
 * If @gesture is active, this function returns the angle difference
 * in radians since the gesture was first recognized. If @gesture is
 * not active, 0 is returned.
 *
 * @return the angle delta in radians
 */
- (gdouble)angleDelta;

@end