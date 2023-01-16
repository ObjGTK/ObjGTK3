/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGesture.h"

#import <OGdk3/OGGdkWindow.h>
#import <OGdk3/OGGdkDevice.h>

@implementation OGTKGesture

- (GtkGesture*)GESTURE
{
	return GTK_GESTURE([self GOBJECT]);
}

- (bool)boundingBox:(GdkRectangle*)rect
{
	return gtk_gesture_get_bounding_box([self GESTURE], rect);
}

- (bool)boundingBoxCenterWithX:(gdouble*)x y:(gdouble*)y
{
	return gtk_gesture_get_bounding_box_center([self GESTURE], x, y);
}

- (OGGdkDevice*)device
{
	return [[[OGGdkDevice alloc] initWithGObject:(GObject*)gtk_gesture_get_device([self GESTURE])] autorelease];
}

- (GList*)group
{
	return gtk_gesture_get_group([self GESTURE]);
}

- (const GdkEvent*)lastEvent:(GdkEventSequence*)sequence
{
	return gtk_gesture_get_last_event([self GESTURE], sequence);
}

- (GdkEventSequence*)lastUpdatedSequence
{
	return gtk_gesture_get_last_updated_sequence([self GESTURE]);
}

- (bool)pointWithSequence:(GdkEventSequence*)sequence x:(gdouble*)x y:(gdouble*)y
{
	return gtk_gesture_get_point([self GESTURE], sequence, x, y);
}

- (GtkEventSequenceState)sequenceState:(GdkEventSequence*)sequence
{
	return gtk_gesture_get_sequence_state([self GESTURE], sequence);
}

- (GList*)sequences
{
	return gtk_gesture_get_sequences([self GESTURE]);
}

- (OGGdkWindow*)window
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_gesture_get_window([self GESTURE])] autorelease];
}

- (void)group:(OGTKGesture*)gesture
{
	gtk_gesture_group([self GESTURE], [gesture GESTURE]);
}

- (bool)handlesSequence:(GdkEventSequence*)sequence
{
	return gtk_gesture_handles_sequence([self GESTURE], sequence);
}

- (bool)isActive
{
	return gtk_gesture_is_active([self GESTURE]);
}

- (bool)isGroupedWith:(OGTKGesture*)other
{
	return gtk_gesture_is_grouped_with([self GESTURE], [other GESTURE]);
}

- (bool)isRecognized
{
	return gtk_gesture_is_recognized([self GESTURE]);
}

- (bool)setSequenceStateWithSequence:(GdkEventSequence*)sequence state:(GtkEventSequenceState)state
{
	return gtk_gesture_set_sequence_state([self GESTURE], sequence, state);
}

- (bool)setState:(GtkEventSequenceState)state
{
	return gtk_gesture_set_state([self GESTURE], state);
}

- (void)setWindow:(OGGdkWindow*)window
{
	gtk_gesture_set_window([self GESTURE], [window WINDOW]);
}

- (void)ungroup
{
	gtk_gesture_ungroup([self GESTURE]);
}


@end