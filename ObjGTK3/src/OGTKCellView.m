/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellView.h"

#import "OGTKCellArea.h"
#import <OGGdkPixbuf/OGGdkPixbuf.h>
#import "OGTKCellAreaContext.h"

@implementation OGTKCellView

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_view_new()];

	return self;
}

- (instancetype)initWithContextWithArea:(OGTKCellArea*)area context:(OGTKCellAreaContext*)context
{
	self = [super initWithGObject:(GObject*)gtk_cell_view_new_with_context([area CELLAREA], [context CELLAREACONTEXT])];

	return self;
}

- (instancetype)initWithMarkup:(OFString*)markup
{
	self = [super initWithGObject:(GObject*)gtk_cell_view_new_with_markup([markup UTF8String])];

	return self;
}

- (instancetype)initWithPixbuf:(OGGdkPixbuf*)pixbuf
{
	self = [super initWithGObject:(GObject*)gtk_cell_view_new_with_pixbuf([pixbuf PIXBUF])];

	return self;
}

- (instancetype)initWithText:(OFString*)text
{
	self = [super initWithGObject:(GObject*)gtk_cell_view_new_with_text([text UTF8String])];

	return self;
}

- (GtkCellView*)CELLVIEW
{
	return GTK_CELL_VIEW([self GOBJECT]);
}

- (GtkTreePath*)displayedRow
{
	return gtk_cell_view_get_displayed_row([self CELLVIEW]);
}

- (bool)drawSensitive
{
	return gtk_cell_view_get_draw_sensitive([self CELLVIEW]);
}

- (bool)fitModel
{
	return gtk_cell_view_get_fit_model([self CELLVIEW]);
}

- (GtkTreeModel*)model
{
	return gtk_cell_view_get_model([self CELLVIEW]);
}

- (bool)sizeOfRowWithPath:(GtkTreePath*)path requisition:(GtkRequisition*)requisition
{
	return gtk_cell_view_get_size_of_row([self CELLVIEW], path, requisition);
}

- (void)setBackgroundColor:(const GdkColor*)color
{
	gtk_cell_view_set_background_color([self CELLVIEW], color);
}

- (void)setBackgroundRgba:(const GdkRGBA*)rgba
{
	gtk_cell_view_set_background_rgba([self CELLVIEW], rgba);
}

- (void)setDisplayedRow:(GtkTreePath*)path
{
	gtk_cell_view_set_displayed_row([self CELLVIEW], path);
}

- (void)setDrawSensitive:(bool)drawSensitive
{
	gtk_cell_view_set_draw_sensitive([self CELLVIEW], drawSensitive);
}

- (void)setFitModel:(bool)fitModel
{
	gtk_cell_view_set_fit_model([self CELLVIEW], fitModel);
}

- (void)setModel:(GtkTreeModel*)model
{
	gtk_cell_view_set_model([self CELLVIEW], model);
}


@end