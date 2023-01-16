/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureSingle.h"

@class OGTKWidget;
@class OGTKGesture;

/**
 * #GtkGestureSwipe is a #GtkGesture implementation able to recognize
 * swipes, after a press/move/.../move/release sequence happens, the
 * #GtkGestureSwipe::swipe signal will be emitted, providing the velocity
 * and directionality of the sequence at the time it was lifted.
 * 
 * If the velocity is desired in intermediate points,
 * gtk_gesture_swipe_get_velocity() can be called on eg. a
 * #GtkGesture::update handler.
 * 
 * All velocities are reported in pixels/sec units.
 *
 */
@interface OGTKGestureSwipe : OGTKGestureSingle
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKWidget*)widget;

/**
 * Methods
 */

- (GtkGestureSwipe*)GESTURESWIPE;

/**
 * If the gesture is recognized, this function returns %TRUE and fill in
 * @velocity_x and @velocity_y with the recorded velocity, as per the
 * last event(s) processed.
 *
 * @param velocityX return value for the velocity in the X axis, in pixels/sec
 * @param velocityY return value for the velocity in the Y axis, in pixels/sec
 * @return whether velocity could be calculated
 */
- (bool)velocityWithVelocityX:(gdouble*)velocityX velocityY:(gdouble*)velocityY;

@end