/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEventControllerKey.h"

#import "OGTKIMContext.h"
#import "OGTKWidget.h"

@implementation OGTKEventControllerKey

- (instancetype)init:(OGTKWidget*)widget
{
	self = [super initWithGObject:(GObject*)gtk_event_controller_key_new([widget WIDGET])];

	return self;
}

- (GtkEventControllerKey*)EVENTCONTROLLERKEY
{
	return GTK_EVENT_CONTROLLER_KEY([self GOBJECT]);
}

- (bool)forward:(OGTKWidget*)widget
{
	return gtk_event_controller_key_forward([self EVENTCONTROLLERKEY], [widget WIDGET]);
}

- (guint)group
{
	return gtk_event_controller_key_get_group([self EVENTCONTROLLERKEY]);
}

- (OGTKIMContext*)imContext
{
	return [[[OGTKIMContext alloc] initWithGObject:(GObject*)gtk_event_controller_key_get_im_context([self EVENTCONTROLLERKEY])] autorelease];
}

- (void)setImContext:(OGTKIMContext*)imContext
{
	gtk_event_controller_key_set_im_context([self EVENTCONTROLLERKEY], [imContext IMCONTEXT]);
}


@end