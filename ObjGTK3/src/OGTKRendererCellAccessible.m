/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRendererCellAccessible.h"

#import "OGTKCellRenderer.h"
#import <OGAtk/OGAtkObject.h>

@implementation OGTKRendererCellAccessible

- (instancetype)init:(OGTKCellRenderer*)renderer
{
	self = [super initWithGObject:(GObject*)gtk_renderer_cell_accessible_new([renderer CELLRENDERER])];

	return self;
}

- (GtkRendererCellAccessible*)RENDERERCELLACCESSIBLE
{
	return GTK_RENDERER_CELL_ACCESSIBLE([self GOBJECT]);
}


@end