/*
 * OGTKCellAreaBox.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKCellAreaBox.h"

@implementation OGTKCellAreaBox

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_area_box_new()];

	return self;
}

- (GtkCellAreaBox*)CELLAREABOX
{
	return GTK_CELL_AREA_BOX([self GOBJECT]);
}

- (gint)getSpacing
{
	return gtk_cell_area_box_get_spacing(GTK_CELL_AREA_BOX([self GOBJECT]));
}

- (void)packEndWithRenderer:(GtkCellRenderer*)renderer andExpand:(bool)expand andAlign:(bool)align andFixed:(bool)fixed
{
	gtk_cell_area_box_pack_end(GTK_CELL_AREA_BOX([self GOBJECT]), renderer, expand, align, fixed);
}

- (void)packStartWithRenderer:(GtkCellRenderer*)renderer andExpand:(bool)expand andAlign:(bool)align andFixed:(bool)fixed
{
	gtk_cell_area_box_pack_start(GTK_CELL_AREA_BOX([self GOBJECT]), renderer, expand, align, fixed);
}

- (void)setSpacing:(gint)spacing
{
	gtk_cell_area_box_set_spacing(GTK_CELL_AREA_BOX([self GOBJECT]), spacing);
}


@end