/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellRendererProgress.h"

@implementation OGTKCellRendererProgress

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_renderer_progress_new()];

	return self;
}

- (GtkCellRendererProgress*)CELLRENDERERPROGRESS
{
	return GTK_CELL_RENDERER_PROGRESS([self GOBJECT]);
}


@end