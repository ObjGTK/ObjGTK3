/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureDrag.h"

@class OGTKGesture;
@class OGTKWidget;

/**
 * #GtkGesturePan is a #GtkGesture implementation able to recognize
 * pan gestures, those are drags that are locked to happen along one
 * axis. The axis that a #GtkGesturePan handles is defined at
 * construct time, and can be changed through
 * gtk_gesture_pan_set_orientation().
 * 
 * When the gesture starts to be recognized, #GtkGesturePan will
 * attempt to determine as early as possible whether the sequence
 * is moving in the expected direction, and denying the sequence if
 * this does not happen.
 * 
 * Once a panning gesture along the expected axis is recognized,
 * the #GtkGesturePan::pan signal will be emitted as input events
 * are received, containing the offset in the given axis.
 *
 */
@interface OGTKGesturePan : OGTKGestureDrag
{

}


/**
 * Constructors
 */
- (instancetype)initWithWidget:(OGTKWidget*)widget orientation:(GtkOrientation)orientation;

/**
 * Methods
 */

- (GtkGesturePan*)GESTUREPAN;

/**
 * Returns the orientation of the pan gestures that this @gesture expects.
 *
 * @return the expected orientation for pan gestures
 */
- (GtkOrientation)orientation;

/**
 * Sets the orientation to be expected on pan gestures.
 *
 * @param orientation expected orientation
 */
- (void)setOrientation:(GtkOrientation)orientation;

@end