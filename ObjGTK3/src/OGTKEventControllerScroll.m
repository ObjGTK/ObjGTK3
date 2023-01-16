/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEventControllerScroll.h"

#import "OGTKWidget.h"

@implementation OGTKEventControllerScroll

- (instancetype)initWithWidget:(OGTKWidget*)widget flags:(GtkEventControllerScrollFlags)flags
{
	self = [super initWithGObject:(GObject*)gtk_event_controller_scroll_new([widget WIDGET], flags)];

	return self;
}

- (GtkEventControllerScroll*)EVENTCONTROLLERSCROLL
{
	return GTK_EVENT_CONTROLLER_SCROLL([self GOBJECT]);
}

- (GtkEventControllerScrollFlags)flags
{
	return gtk_event_controller_scroll_get_flags([self EVENTCONTROLLERSCROLL]);
}

- (void)setFlags:(GtkEventControllerScrollFlags)flags
{
	gtk_event_controller_scroll_set_flags([self EVENTCONTROLLERSCROLL], flags);
}


@end