/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellRendererText.h"

@implementation OGTKCellRendererText

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_renderer_text_new()];

	return self;
}

- (GtkCellRendererText*)CELLRENDERERTEXT
{
	return GTK_CELL_RENDERER_TEXT([self GOBJECT]);
}

- (void)setFixedHeightFromFont:(gint)numberOfRows
{
	gtk_cell_renderer_text_set_fixed_height_from_font([self CELLRENDERERTEXT], numberOfRows);
}


@end