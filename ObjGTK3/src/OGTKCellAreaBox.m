/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellAreaBox.h"

#import "OGTKCellRenderer.h"

@implementation OGTKCellAreaBox

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_area_box_new()];

	return self;
}

- (GtkCellAreaBox*)CELLAREABOX
{
	return GTK_CELL_AREA_BOX([self GOBJECT]);
}

- (gint)spacing
{
	return gtk_cell_area_box_get_spacing([self CELLAREABOX]);
}

- (void)packEndWithRenderer:(OGTKCellRenderer*)renderer expand:(bool)expand align:(bool)align fixed:(bool)fixed
{
	gtk_cell_area_box_pack_end([self CELLAREABOX], [renderer CELLRENDERER], expand, align, fixed);
}

- (void)packStartWithRenderer:(OGTKCellRenderer*)renderer expand:(bool)expand align:(bool)align fixed:(bool)fixed
{
	gtk_cell_area_box_pack_start([self CELLAREABOX], [renderer CELLRENDERER], expand, align, fixed);
}

- (void)setSpacing:(gint)spacing
{
	gtk_cell_area_box_set_spacing([self CELLAREABOX], spacing);
}


@end