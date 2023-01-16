/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureLongPress.h"

#import "OGTKWidget.h"
#import "OGTKGesture.h"

@implementation OGTKGestureLongPress

- (instancetype)init:(OGTKWidget*)widget
{
	self = [super initWithGObject:(GObject*)gtk_gesture_long_press_new([widget WIDGET])];

	return self;
}

- (GtkGestureLongPress*)GESTURELONGPRESS
{
	return GTK_GESTURE_LONG_PRESS([self GOBJECT]);
}


@end