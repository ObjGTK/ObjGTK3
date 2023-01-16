/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureSwipe.h"

#import "OGTKWidget.h"
#import "OGTKGesture.h"

@implementation OGTKGestureSwipe

- (instancetype)init:(OGTKWidget*)widget
{
	self = [super initWithGObject:(GObject*)gtk_gesture_swipe_new([widget WIDGET])];

	return self;
}

- (GtkGestureSwipe*)GESTURESWIPE
{
	return GTK_GESTURE_SWIPE([self GOBJECT]);
}

- (bool)velocityWithVelocityX:(gdouble*)velocityX velocityY:(gdouble*)velocityY
{
	return gtk_gesture_swipe_get_velocity([self GESTURESWIPE], velocityX, velocityY);
}


@end