/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureRotate.h"

#import "OGTKWidget.h"

@implementation OGTKGestureRotate

- (instancetype)init:(OGTKWidget*)widget
{
	self = [super initWithGObject:(GObject*)gtk_gesture_rotate_new([widget WIDGET])];

	return self;
}

- (GtkGestureRotate*)GESTUREROTATE
{
	return GTK_GESTURE_ROTATE([self GOBJECT]);
}

- (gdouble)angleDelta
{
	return gtk_gesture_rotate_get_angle_delta([self GESTUREROTATE]);
}


@end