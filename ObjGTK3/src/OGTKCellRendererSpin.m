/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellRendererSpin.h"

#import "OGTKCellRenderer.h"

@implementation OGTKCellRendererSpin

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_renderer_spin_new()];

	return self;
}

- (GtkCellRendererSpin*)CELLRENDERERSPIN
{
	return GTK_CELL_RENDERER_SPIN([self GOBJECT]);
}


@end