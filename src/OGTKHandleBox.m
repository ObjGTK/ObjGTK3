/*
 * OGTKHandleBox.m
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
#import "OGTKHandleBox.h"

@implementation OGTKHandleBox

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_handle_box_new()];

	return self;
}

- (GtkHandleBox*)HANDLEBOX
{
	return GTK_HANDLE_BOX([self GOBJECT]);
}

- (bool)getChildDetached
{
	return gtk_handle_box_get_child_detached(GTK_HANDLE_BOX([self GOBJECT]));
}

- (GtkPositionType)getHandlePosition
{
	return gtk_handle_box_get_handle_position(GTK_HANDLE_BOX([self GOBJECT]));
}

- (GtkShadowType)getShadowType
{
	return gtk_handle_box_get_shadow_type(GTK_HANDLE_BOX([self GOBJECT]));
}

- (GtkPositionType)getSnapEdge
{
	return gtk_handle_box_get_snap_edge(GTK_HANDLE_BOX([self GOBJECT]));
}

- (void)setHandlePosition:(GtkPositionType)position
{
	gtk_handle_box_set_handle_position(GTK_HANDLE_BOX([self GOBJECT]), position);
}

- (void)setShadowType:(GtkShadowType)type
{
	gtk_handle_box_set_shadow_type(GTK_HANDLE_BOX([self GOBJECT]), type);
}

- (void)setSnapEdge:(GtkPositionType)edge
{
	gtk_handle_box_set_snap_edge(GTK_HANDLE_BOX([self GOBJECT]), edge);
}


@end