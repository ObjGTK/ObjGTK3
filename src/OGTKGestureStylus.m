/*
 * OGTKGestureStylus.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKGestureStylus.h"

@implementation OGTKGestureStylus

- (id)init:(OGTKWidget*)widget
{
	self = [super initWithGObject:(GObject*)gtk_gesture_stylus_new([widget WIDGET])];

	return self;
}

- (GtkGestureStylus*)GESTURESTYLUS
{
	return GTK_GESTURE_STYLUS([self GOBJECT]);
}

- (bool)getAxesWithAxes:(GdkAxisUse*)axes andValues:(gdouble**)values
{
	return gtk_gesture_stylus_get_axes(GTK_GESTURE_STYLUS([self GOBJECT]), axes, values);
}

- (bool)getAxisWithAxis:(GdkAxisUse)axis andValue:(gdouble*)value
{
	return gtk_gesture_stylus_get_axis(GTK_GESTURE_STYLUS([self GOBJECT]), axis, value);
}

- (GdkDeviceTool*)getDeviceTool
{
	return gtk_gesture_stylus_get_device_tool(GTK_GESTURE_STYLUS([self GOBJECT]));
}


@end