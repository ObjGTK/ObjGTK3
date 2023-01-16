/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSocket.h"

#import <OGdk3/OGGdkWindow.h>
#import "OGTKWidget.h"

@implementation OGTKSocket

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_socket_new()];

	return self;
}

- (GtkSocket*)SOCKET
{
	return GTK_SOCKET([self GOBJECT]);
}

- (void)addId:(Window)window
{
	gtk_socket_add_id([self SOCKET], window);
}

- (Window)id
{
	return gtk_socket_get_id([self SOCKET]);
}

- (OGGdkWindow*)plugWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_socket_get_plug_window([self SOCKET])] autorelease];
}


@end