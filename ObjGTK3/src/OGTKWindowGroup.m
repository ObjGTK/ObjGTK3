/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWindowGroup.h"

#import "OGTKWindow.h"
#import <OGdk3/OGGdkDevice.h>
#import "OGTKWidget.h"

@implementation OGTKWindowGroup

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_window_group_new()];

	return self;
}

- (GtkWindowGroup*)WINDOWGROUP
{
	return GTK_WINDOW_GROUP([self GOBJECT]);
}

- (void)addWindow:(OGTKWindow*)window
{
	gtk_window_group_add_window([self WINDOWGROUP], [window WINDOW]);
}

- (OGTKWidget*)currentDeviceGrab:(OGGdkDevice*)device
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_window_group_get_current_device_grab([self WINDOWGROUP], [device DEVICE])] autorelease];
}

- (OGTKWidget*)currentGrab
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_window_group_get_current_grab([self WINDOWGROUP])] autorelease];
}

- (GList*)listWindows
{
	return gtk_window_group_list_windows([self WINDOWGROUP]);
}

- (void)removeWindow:(OGTKWindow*)window
{
	gtk_window_group_remove_window([self WINDOWGROUP], [window WINDOW]);
}


@end