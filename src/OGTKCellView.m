/*
 * OGTKCellView.m
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
#import "OGTKCellView.h"

@implementation OGTKCellView

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_view_new()];

	return self;
}

- (id)initWithContextWithArea:(GtkCellArea*)area andContext:(GtkCellAreaContext*)context
{
	self = [super initWithGObject:(GObject*)gtk_cell_view_new_with_context(area, context)];

	return self;
}

- (id)initWithMarkup:(OFString*)markup
{
	self = [super initWithGObject:(GObject*)gtk_cell_view_new_with_markup([markup UTF8String])];

	return self;
}

- (id)initWithPixbuf:(GdkPixbuf*)pixbuf
{
	self = [super initWithGObject:(GObject*)gtk_cell_view_new_with_pixbuf(pixbuf)];

	return self;
}

- (id)initWithText:(OFString*)text
{
	self = [super initWithGObject:(GObject*)gtk_cell_view_new_with_text([text UTF8String])];

	return self;
}

- (GtkCellView*)CELLVIEW
{
	return GTK_CELL_VIEW([self GOBJECT]);
}

- (GtkTreePath*)getDisplayedRow
{
	return gtk_cell_view_get_displayed_row(GTK_CELL_VIEW([self GOBJECT]));
}

- (bool)getDrawSensitive
{
	return gtk_cell_view_get_draw_sensitive(GTK_CELL_VIEW([self GOBJECT]));
}

- (bool)getFitModel
{
	return gtk_cell_view_get_fit_model(GTK_CELL_VIEW([self GOBJECT]));
}

- (GtkTreeModel*)getModel
{
	return gtk_cell_view_get_model(GTK_CELL_VIEW([self GOBJECT]));
}

- (bool)getSizeOfRowWithPath:(GtkTreePath*)path andRequisition:(GtkRequisition*)requisition
{
	return gtk_cell_view_get_size_of_row(GTK_CELL_VIEW([self GOBJECT]), path, requisition);
}

- (void)setBackgroundColor:(const GdkColor*)color
{
	gtk_cell_view_set_background_color(GTK_CELL_VIEW([self GOBJECT]), color);
}

- (void)setBackgroundRgba:(const GdkRGBA*)rgba
{
	gtk_cell_view_set_background_rgba(GTK_CELL_VIEW([self GOBJECT]), rgba);
}

- (void)setDisplayedRow:(GtkTreePath*)path
{
	gtk_cell_view_set_displayed_row(GTK_CELL_VIEW([self GOBJECT]), path);
}

- (void)setDrawSensitive:(bool)drawSensitive
{
	gtk_cell_view_set_draw_sensitive(GTK_CELL_VIEW([self GOBJECT]), drawSensitive);
}

- (void)setFitModel:(bool)fitModel
{
	gtk_cell_view_set_fit_model(GTK_CELL_VIEW([self GOBJECT]), fitModel);
}

- (void)setModel:(GtkTreeModel*)model
{
	gtk_cell_view_set_model(GTK_CELL_VIEW([self GOBJECT]), model);
}


@end