/*
 * OGTKGesture.m
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
#import "OGTKGesture.h"

@implementation OGTKGesture

- (GtkGesture*)GESTURE
{
	return GTK_GESTURE([self GOBJECT]);
}

- (bool)getBoundingBox:(GdkRectangle*)rect
{
	return gtk_gesture_get_bounding_box(GTK_GESTURE([self GOBJECT]), rect);
}

- (bool)getBoundingBoxCenterWithX:(gdouble*)x andY:(gdouble*)y
{
	return gtk_gesture_get_bounding_box_center(GTK_GESTURE([self GOBJECT]), x, y);
}

- (GdkDevice*)getDevice
{
	return gtk_gesture_get_device(GTK_GESTURE([self GOBJECT]));
}

- (GList*)getGroup
{
	return gtk_gesture_get_group(GTK_GESTURE([self GOBJECT]));
}

- (const GdkEvent*)getLastEvent:(GdkEventSequence*)sequence
{
	return gtk_gesture_get_last_event(GTK_GESTURE([self GOBJECT]), sequence);
}

- (GdkEventSequence*)getLastUpdatedSequence
{
	return gtk_gesture_get_last_updated_sequence(GTK_GESTURE([self GOBJECT]));
}

- (bool)getPointWithSequence:(GdkEventSequence*)sequence andX:(gdouble*)x andY:(gdouble*)y
{
	return gtk_gesture_get_point(GTK_GESTURE([self GOBJECT]), sequence, x, y);
}

- (GtkEventSequenceState)getSequenceState:(GdkEventSequence*)sequence
{
	return gtk_gesture_get_sequence_state(GTK_GESTURE([self GOBJECT]), sequence);
}

- (GList*)getSequences
{
	return gtk_gesture_get_sequences(GTK_GESTURE([self GOBJECT]));
}

- (GdkWindow*)getWindow
{
	return gtk_gesture_get_window(GTK_GESTURE([self GOBJECT]));
}

- (void)group:(GtkGesture*)gesture
{
	gtk_gesture_group(GTK_GESTURE([self GOBJECT]), gesture);
}

- (bool)handlesSequence:(GdkEventSequence*)sequence
{
	return gtk_gesture_handles_sequence(GTK_GESTURE([self GOBJECT]), sequence);
}

- (bool)isActive
{
	return gtk_gesture_is_active(GTK_GESTURE([self GOBJECT]));
}

- (bool)isGroupedWith:(GtkGesture*)other
{
	return gtk_gesture_is_grouped_with(GTK_GESTURE([self GOBJECT]), other);
}

- (bool)isRecognized
{
	return gtk_gesture_is_recognized(GTK_GESTURE([self GOBJECT]));
}

- (bool)setSequenceStateWithSequence:(GdkEventSequence*)sequence andState:(GtkEventSequenceState)state
{
	return gtk_gesture_set_sequence_state(GTK_GESTURE([self GOBJECT]), sequence, state);
}

- (bool)setState:(GtkEventSequenceState)state
{
	return gtk_gesture_set_state(GTK_GESTURE([self GOBJECT]), state);
}

- (void)setWindow:(GdkWindow*)window
{
	gtk_gesture_set_window(GTK_GESTURE([self GOBJECT]), window);
}

- (void)ungroup
{
	gtk_gesture_ungroup(GTK_GESTURE([self GOBJECT]));
}


@end