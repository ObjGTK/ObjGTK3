/*
 * OGTKPlug.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKPlug.h"

@implementation OGTKPlug

- (id)init:(OGTKWindow)socketId
{
	self = [super initWithGObject:(GObject*)gtk_plug_new(socketId)];

	return self;
}

- (id)initForDisplayWithDisplay:(GdkDisplay*)display andSocketId:(OGTKWindow)socketId
{
	self = [super initWithGObject:(GObject*)gtk_plug_new_for_display(display, socketId)];

	return self;
}

- (GtkPlug*)PLUG
{
	return GTK_PLUG([self GOBJECT]);
}

- (void)construct:(OGTKWindow)socketId
{
	gtk_plug_construct(GTK_PLUG([self GOBJECT]), socketId);
}

- (void)constructForDisplayWithDisplay:(GdkDisplay*)display andSocketId:(OGTKWindow)socketId
{
	gtk_plug_construct_for_display(GTK_PLUG([self GOBJECT]), display, socketId);
}

- (bool)getEmbedded
{
	return gtk_plug_get_embedded(GTK_PLUG([self GOBJECT]));
}

- (OGTKWindow)getId
{
	return gtk_plug_get_id(GTK_PLUG([self GOBJECT]));
}

- (GdkWindow*)getSocketWindow
{
	return gtk_plug_get_socket_window(GTK_PLUG([self GOBJECT]));
}


@end