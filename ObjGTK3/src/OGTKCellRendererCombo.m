/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellRendererCombo.h"

#import "OGTKCellRenderer.h"

@implementation OGTKCellRendererCombo

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_renderer_combo_new()];

	return self;
}

- (GtkCellRendererCombo*)CELLRENDERERCOMBO
{
	return GTK_CELL_RENDERER_COMBO([self GOBJECT]);
}


@end