/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureSingle.h"

@implementation OGTKGestureSingle

- (GtkGestureSingle*)GESTURESINGLE
{
	return GTK_GESTURE_SINGLE([self GOBJECT]);
}

- (guint)button
{
	return gtk_gesture_single_get_button([self GESTURESINGLE]);
}

- (guint)currentButton
{
	return gtk_gesture_single_get_current_button([self GESTURESINGLE]);
}

- (GdkEventSequence*)currentSequence
{
	return gtk_gesture_single_get_current_sequence([self GESTURESINGLE]);
}

- (bool)exclusive
{
	return gtk_gesture_single_get_exclusive([self GESTURESINGLE]);
}

- (bool)touchOnly
{
	return gtk_gesture_single_get_touch_only([self GESTURESINGLE]);
}

- (void)setButton:(guint)button
{
	gtk_gesture_single_set_button([self GESTURESINGLE], button);
}

- (void)setExclusive:(bool)exclusive
{
	gtk_gesture_single_set_exclusive([self GESTURESINGLE], exclusive);
}

- (void)setTouchOnly:(bool)touchOnly
{
	gtk_gesture_single_set_touch_only([self GESTURESINGLE], touchOnly);
}


@end