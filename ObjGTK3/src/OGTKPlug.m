/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPlug.h"

#import <OGdk3/OGGdkDisplay.h>
#import "OGTKWidget.h"

@implementation OGTKPlug

- (instancetype)init:(Window)socketId
{
	self = [super initWithGObject:(GObject*)gtk_plug_new(socketId)];

	return self;
}

- (instancetype)initForDisplayWithDisplay:(OGGdkDisplay*)display socketId:(Window)socketId
{
	self = [super initWithGObject:(GObject*)gtk_plug_new_for_display([display DISPLAY], socketId)];

	return self;
}

- (GtkPlug*)PLUG
{
	return GTK_PLUG([self GOBJECT]);
}

- (void)construct:(Window)socketId
{
	gtk_plug_construct([self PLUG], socketId);
}

- (void)constructForDisplayWithDisplay:(OGGdkDisplay*)display socketId:(Window)socketId
{
	gtk_plug_construct_for_display([self PLUG], [display DISPLAY], socketId);
}

- (bool)embedded
{
	return gtk_plug_get_embedded([self PLUG]);
}

- (Window)id
{
	return gtk_plug_get_id([self PLUG]);
}

- (OGGdkWindow*)socketWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_plug_get_socket_window([self PLUG])] autorelease];
}


@end