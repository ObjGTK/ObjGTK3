/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEventControllerMotion.h"

#import "OGTKWidget.h"

@implementation OGTKEventControllerMotion

- (instancetype)init:(OGTKWidget*)widget
{
	self = [super initWithGObject:(GObject*)gtk_event_controller_motion_new([widget WIDGET])];

	return self;
}

- (GtkEventControllerMotion*)EVENTCONTROLLERMOTION
{
	return GTK_EVENT_CONTROLLER_MOTION([self GOBJECT]);
}


@end