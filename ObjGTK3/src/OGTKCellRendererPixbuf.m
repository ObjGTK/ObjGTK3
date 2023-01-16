/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellRendererPixbuf.h"

@implementation OGTKCellRendererPixbuf

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_renderer_pixbuf_new()];

	return self;
}

- (GtkCellRendererPixbuf*)CELLRENDERERPIXBUF
{
	return GTK_CELL_RENDERER_PIXBUF([self GOBJECT]);
}


@end