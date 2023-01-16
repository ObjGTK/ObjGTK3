/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGesturePan.h"

#import "OGTKGesture.h"
#import "OGTKWidget.h"

@implementation OGTKGesturePan

- (instancetype)initWithWidget:(OGTKWidget*)widget orientation:(GtkOrientation)orientation
{
	self = [super initWithGObject:(GObject*)gtk_gesture_pan_new([widget WIDGET], orientation)];

	return self;
}

- (GtkGesturePan*)GESTUREPAN
{
	return GTK_GESTURE_PAN([self GOBJECT]);
}

- (GtkOrientation)orientation
{
	return gtk_gesture_pan_get_orientation([self GESTUREPAN]);
}

- (void)setOrientation:(GtkOrientation)orientation
{
	gtk_gesture_pan_set_orientation([self GESTUREPAN], orientation);
}


@end