/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGrid.h"

#import "OGTKWidget.h"

@implementation OGTKGrid

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_grid_new()];

	return self;
}

- (GtkGrid*)GRID
{
	return GTK_GRID([self GOBJECT]);
}

- (void)attachWithChild:(OGTKWidget*)child left:(gint)left top:(gint)top width:(gint)width height:(gint)height
{
	gtk_grid_attach([self GRID], [child WIDGET], left, top, width, height);
}

- (void)attachNextToWithChild:(OGTKWidget*)child sibling:(OGTKWidget*)sibling side:(GtkPositionType)side width:(gint)width height:(gint)height
{
	gtk_grid_attach_next_to([self GRID], [child WIDGET], [sibling WIDGET], side, width, height);
}

- (gint)baselineRow
{
	return gtk_grid_get_baseline_row([self GRID]);
}

- (OGTKWidget*)childAtWithLeft:(gint)left top:(gint)top
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_grid_get_child_at([self GRID], left, top)] autorelease];
}

- (bool)columnHomogeneous
{
	return gtk_grid_get_column_homogeneous([self GRID]);
}

- (guint)columnSpacing
{
	return gtk_grid_get_column_spacing([self GRID]);
}

- (GtkBaselinePosition)rowBaselinePosition:(gint)row
{
	return gtk_grid_get_row_baseline_position([self GRID], row);
}

- (bool)rowHomogeneous
{
	return gtk_grid_get_row_homogeneous([self GRID]);
}

- (guint)rowSpacing
{
	return gtk_grid_get_row_spacing([self GRID]);
}

- (void)insertColumn:(gint)position
{
	gtk_grid_insert_column([self GRID], position);
}

- (void)insertNextToWithSibling:(OGTKWidget*)sibling side:(GtkPositionType)side
{
	gtk_grid_insert_next_to([self GRID], [sibling WIDGET], side);
}

- (void)insertRow:(gint)position
{
	gtk_grid_insert_row([self GRID], position);
}

- (void)removeColumn:(gint)position
{
	gtk_grid_remove_column([self GRID], position);
}

- (void)removeRow:(gint)position
{
	gtk_grid_remove_row([self GRID], position);
}

- (void)setBaselineRow:(gint)row
{
	gtk_grid_set_baseline_row([self GRID], row);
}

- (void)setColumnHomogeneous:(bool)homogeneous
{
	gtk_grid_set_column_homogeneous([self GRID], homogeneous);
}

- (void)setColumnSpacing:(guint)spacing
{
	gtk_grid_set_column_spacing([self GRID], spacing);
}

- (void)setRowBaselinePositionWithRow:(gint)row pos:(GtkBaselinePosition)pos
{
	gtk_grid_set_row_baseline_position([self GRID], row, pos);
}

- (void)setRowHomogeneous:(bool)homogeneous
{
	gtk_grid_set_row_homogeneous([self GRID], homogeneous);
}

- (void)setRowSpacing:(guint)spacing
{
	gtk_grid_set_row_spacing([self GRID], spacing);
}


@end