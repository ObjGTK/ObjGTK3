/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellAreaContext.h"

#import "OGTKCellArea.h"

@implementation OGTKCellAreaContext

- (GtkCellAreaContext*)CELLAREACONTEXT
{
	return GTK_CELL_AREA_CONTEXT([self GOBJECT]);
}

- (void)allocateWithWidth:(gint)width height:(gint)height
{
	gtk_cell_area_context_allocate([self CELLAREACONTEXT], width, height);
}

- (void)allocationWithWidth:(gint*)width height:(gint*)height
{
	gtk_cell_area_context_get_allocation([self CELLAREACONTEXT], width, height);
}

- (OGTKCellArea*)area
{
	return [[[OGTKCellArea alloc] initWithGObject:(GObject*)gtk_cell_area_context_get_area([self CELLAREACONTEXT])] autorelease];
}

- (void)preferredHeightWithMinimumHeight:(gint*)minimumHeight naturalHeight:(gint*)naturalHeight
{
	gtk_cell_area_context_get_preferred_height([self CELLAREACONTEXT], minimumHeight, naturalHeight);
}

- (void)preferredHeightForWidthWithWidth:(gint)width minimumHeight:(gint*)minimumHeight naturalHeight:(gint*)naturalHeight
{
	gtk_cell_area_context_get_preferred_height_for_width([self CELLAREACONTEXT], width, minimumHeight, naturalHeight);
}

- (void)preferredWidthWithMinimumWidth:(gint*)minimumWidth naturalWidth:(gint*)naturalWidth
{
	gtk_cell_area_context_get_preferred_width([self CELLAREACONTEXT], minimumWidth, naturalWidth);
}

- (void)preferredWidthForHeightWithHeight:(gint)height minimumWidth:(gint*)minimumWidth naturalWidth:(gint*)naturalWidth
{
	gtk_cell_area_context_get_preferred_width_for_height([self CELLAREACONTEXT], height, minimumWidth, naturalWidth);
}

- (void)pushPreferredHeightWithMinimumHeight:(gint)minimumHeight naturalHeight:(gint)naturalHeight
{
	gtk_cell_area_context_push_preferred_height([self CELLAREACONTEXT], minimumHeight, naturalHeight);
}

- (void)pushPreferredWidthWithMinimumWidth:(gint)minimumWidth naturalWidth:(gint)naturalWidth
{
	gtk_cell_area_context_push_preferred_width([self CELLAREACONTEXT], minimumWidth, naturalWidth);
}

- (void)reset
{
	gtk_cell_area_context_reset([self CELLAREACONTEXT]);
}


@end