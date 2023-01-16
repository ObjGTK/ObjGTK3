/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellRendererSpinner.h"

@implementation OGTKCellRendererSpinner

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_renderer_spinner_new()];

	return self;
}

- (GtkCellRendererSpinner*)CELLRENDERERSPINNER
{
	return GTK_CELL_RENDERER_SPINNER([self GOBJECT]);
}


@end