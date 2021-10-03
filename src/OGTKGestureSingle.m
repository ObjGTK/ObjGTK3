/*
 * OGTKGestureSingle.m
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
#import "OGTKGestureSingle.h"

@implementation OGTKGestureSingle

- (GtkGestureSingle*)GESTURESINGLE
{
	return GTK_GESTURE_SINGLE([self GOBJECT]);
}

- (guint)getButton
{
	return gtk_gesture_single_get_button(GTK_GESTURE_SINGLE([self GOBJECT]));
}

- (guint)getCurrentButton
{
	return gtk_gesture_single_get_current_button(GTK_GESTURE_SINGLE([self GOBJECT]));
}

- (GdkEventSequence*)getCurrentSequence
{
	return gtk_gesture_single_get_current_sequence(GTK_GESTURE_SINGLE([self GOBJECT]));
}

- (bool)getExclusive
{
	return gtk_gesture_single_get_exclusive(GTK_GESTURE_SINGLE([self GOBJECT]));
}

- (bool)getTouchOnly
{
	return gtk_gesture_single_get_touch_only(GTK_GESTURE_SINGLE([self GOBJECT]));
}

- (void)setButton:(guint)button
{
	gtk_gesture_single_set_button(GTK_GESTURE_SINGLE([self GOBJECT]), button);
}

- (void)setExclusive:(bool)exclusive
{
	gtk_gesture_single_set_exclusive(GTK_GESTURE_SINGLE([self GOBJECT]), exclusive);
}

- (void)setTouchOnly:(bool)touchOnly
{
	gtk_gesture_single_set_touch_only(GTK_GESTURE_SINGLE([self GOBJECT]), touchOnly);
}


@end