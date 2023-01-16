/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureStylus.h"

#import <OGdk3/OGGdkDeviceTool.h>
#import "OGTKWidget.h"
#import "OGTKGesture.h"

@implementation OGTKGestureStylus

- (instancetype)init:(OGTKWidget*)widget
{
	self = [super initWithGObject:(GObject*)gtk_gesture_stylus_new([widget WIDGET])];

	return self;
}

- (GtkGestureStylus*)GESTURESTYLUS
{
	return GTK_GESTURE_STYLUS([self GOBJECT]);
}

- (bool)axesWithAxes:(GdkAxisUse*)axes values:(gdouble**)values
{
	return gtk_gesture_stylus_get_axes([self GESTURESTYLUS], axes, values);
}

- (bool)axisWithAxis:(GdkAxisUse)axis value:(gdouble*)value
{
	return gtk_gesture_stylus_get_axis([self GESTURESTYLUS], axis, value);
}

- (OGGdkDeviceTool*)deviceTool
{
	return [[[OGGdkDeviceTool alloc] initWithGObject:(GObject*)gtk_gesture_stylus_get_device_tool([self GESTURESTYLUS])] autorelease];
}


@end