/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKHandleBox.h"

#import "OGTKWidget.h"

@implementation OGTKHandleBox

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_handle_box_new()];

	return self;
}

- (GtkHandleBox*)HANDLEBOX
{
	return GTK_HANDLE_BOX([self GOBJECT]);
}

- (bool)childDetached
{
	return gtk_handle_box_get_child_detached([self HANDLEBOX]);
}

- (GtkPositionType)handlePosition
{
	return gtk_handle_box_get_handle_position([self HANDLEBOX]);
}

- (GtkShadowType)shadowType
{
	return gtk_handle_box_get_shadow_type([self HANDLEBOX]);
}

- (GtkPositionType)snapEdge
{
	return gtk_handle_box_get_snap_edge([self HANDLEBOX]);
}

- (void)setHandlePosition:(GtkPositionType)position
{
	gtk_handle_box_set_handle_position([self HANDLEBOX], position);
}

- (void)setShadowType:(GtkShadowType)type
{
	gtk_handle_box_set_shadow_type([self HANDLEBOX], type);
}

- (void)setSnapEdge:(GtkPositionType)edge
{
	gtk_handle_box_set_snap_edge([self HANDLEBOX], edge);
}


@end