/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureMultiPress.h"

#import "OGTKWidget.h"
#import "OGTKGesture.h"

@implementation OGTKGestureMultiPress

- (instancetype)init:(OGTKWidget*)widget
{
	self = [super initWithGObject:(GObject*)gtk_gesture_multi_press_new([widget WIDGET])];

	return self;
}

- (GtkGestureMultiPress*)GESTUREMULTIPRESS
{
	return GTK_GESTURE_MULTI_PRESS([self GOBJECT]);
}

- (bool)area:(GdkRectangle*)rect
{
	return gtk_gesture_multi_press_get_area([self GESTUREMULTIPRESS], rect);
}

- (void)setArea:(const GdkRectangle*)rect
{
	gtk_gesture_multi_press_set_area([self GESTUREMULTIPRESS], rect);
}


@end