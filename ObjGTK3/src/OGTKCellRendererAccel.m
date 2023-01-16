/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellRendererAccel.h"

#import "OGTKCellRenderer.h"

@implementation OGTKCellRendererAccel

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_renderer_accel_new()];

	return self;
}

- (GtkCellRendererAccel*)CELLRENDERERACCEL
{
	return GTK_CELL_RENDERER_ACCEL([self GOBJECT]);
}


@end