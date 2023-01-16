/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureDrag.h"

#import "OGTKWidget.h"
#import "OGTKGesture.h"

@implementation OGTKGestureDrag

- (instancetype)init:(OGTKWidget*)widget
{
	self = [super initWithGObject:(GObject*)gtk_gesture_drag_new([widget WIDGET])];

	return self;
}

- (GtkGestureDrag*)GESTUREDRAG
{
	return GTK_GESTURE_DRAG([self GOBJECT]);
}

- (bool)offsetWithX:(gdouble*)x y:(gdouble*)y
{
	return gtk_gesture_drag_get_offset([self GESTUREDRAG], x, y);
}

- (bool)startPointWithX:(gdouble*)x y:(gdouble*)y
{
	return gtk_gesture_drag_get_start_point([self GESTUREDRAG], x, y);
}


@end