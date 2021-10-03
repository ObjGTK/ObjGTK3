/*
 * OGTKCellAreaContext.m
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
#import "OGTKCellAreaContext.h"

@implementation OGTKCellAreaContext

- (GtkCellAreaContext*)CELLAREACONTEXT
{
	return GTK_CELL_AREA_CONTEXT([self GOBJECT]);
}

- (void)allocateWithWidth:(gint)width andHeight:(gint)height
{
	gtk_cell_area_context_allocate(GTK_CELL_AREA_CONTEXT([self GOBJECT]), width, height);
}

- (void)getAllocationWithWidth:(gint*)width andHeight:(gint*)height
{
	gtk_cell_area_context_get_allocation(GTK_CELL_AREA_CONTEXT([self GOBJECT]), width, height);
}

- (GtkCellArea*)getArea
{
	return gtk_cell_area_context_get_area(GTK_CELL_AREA_CONTEXT([self GOBJECT]));
}

- (void)getPreferredHeightWithMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight
{
	gtk_cell_area_context_get_preferred_height(GTK_CELL_AREA_CONTEXT([self GOBJECT]), minimumHeight, naturalHeight);
}

- (void)getPreferredHeightForWidthWithWidth:(gint)width andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight
{
	gtk_cell_area_context_get_preferred_height_for_width(GTK_CELL_AREA_CONTEXT([self GOBJECT]), width, minimumHeight, naturalHeight);
}

- (void)getPreferredWidthWithMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth
{
	gtk_cell_area_context_get_preferred_width(GTK_CELL_AREA_CONTEXT([self GOBJECT]), minimumWidth, naturalWidth);
}

- (void)getPreferredWidthForHeightWithHeight:(gint)height andMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth
{
	gtk_cell_area_context_get_preferred_width_for_height(GTK_CELL_AREA_CONTEXT([self GOBJECT]), height, minimumWidth, naturalWidth);
}

- (void)pushPreferredHeightWithMinimumHeight:(gint)minimumHeight andNaturalHeight:(gint)naturalHeight
{
	gtk_cell_area_context_push_preferred_height(GTK_CELL_AREA_CONTEXT([self GOBJECT]), minimumHeight, naturalHeight);
}

- (void)pushPreferredWidthWithMinimumWidth:(gint)minimumWidth andNaturalWidth:(gint)naturalWidth
{
	gtk_cell_area_context_push_preferred_width(GTK_CELL_AREA_CONTEXT([self GOBJECT]), minimumWidth, naturalWidth);
}

- (void)reset
{
	gtk_cell_area_context_reset(GTK_CELL_AREA_CONTEXT([self GOBJECT]));
}


@end