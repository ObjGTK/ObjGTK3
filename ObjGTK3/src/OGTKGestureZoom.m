/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureZoom.h"

#import "OGTKWidget.h"

@implementation OGTKGestureZoom

- (instancetype)init:(OGTKWidget*)widget
{
	self = [super initWithGObject:(GObject*)gtk_gesture_zoom_new([widget WIDGET])];

	return self;
}

- (GtkGestureZoom*)GESTUREZOOM
{
	return GTK_GESTURE_ZOOM([self GOBJECT]);
}

- (gdouble)scaleDelta
{
	return gtk_gesture_zoom_get_scale_delta([self GESTUREZOOM]);
}


@end