/*
 * OGTKCellRenderer.m
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
#import "OGTKCellRenderer.h"

@implementation OGTKCellRenderer

- (GtkCellRenderer*)CELLRENDERER
{
	return GTK_CELL_RENDERER([self GOBJECT]);
}

- (bool)activateWithEvent:(GdkEvent*)event andWidget:(OGTKWidget*)widget andPath:(OFString*)path andBackgroundArea:(const GdkRectangle*)backgroundArea andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags
{
	return gtk_cell_renderer_activate(GTK_CELL_RENDERER([self GOBJECT]), event, [widget WIDGET], [path UTF8String], backgroundArea, cellArea, flags);
}

- (void)getAlignedAreaWithWidget:(OGTKWidget*)widget andFlags:(GtkCellRendererState)flags andCellArea:(const GdkRectangle*)cellArea andAlignedArea:(GdkRectangle*)alignedArea
{
	gtk_cell_renderer_get_aligned_area(GTK_CELL_RENDERER([self GOBJECT]), [widget WIDGET], flags, cellArea, alignedArea);
}

- (void)getAlignmentWithXalign:(gfloat*)xalign andYalign:(gfloat*)yalign
{
	gtk_cell_renderer_get_alignment(GTK_CELL_RENDERER([self GOBJECT]), xalign, yalign);
}

- (void)getFixedSizeWithWidth:(gint*)width andHeight:(gint*)height
{
	gtk_cell_renderer_get_fixed_size(GTK_CELL_RENDERER([self GOBJECT]), width, height);
}

- (void)getPaddingWithXpad:(gint*)xpad andYpad:(gint*)ypad
{
	gtk_cell_renderer_get_padding(GTK_CELL_RENDERER([self GOBJECT]), xpad, ypad);
}

- (void)getPreferredHeightWithWidget:(OGTKWidget*)widget andMinimumSize:(gint*)minimumSize andNaturalSize:(gint*)naturalSize
{
	gtk_cell_renderer_get_preferred_height(GTK_CELL_RENDERER([self GOBJECT]), [widget WIDGET], minimumSize, naturalSize);
}

- (void)getPreferredHeightForWidthWithWidget:(OGTKWidget*)widget andWidth:(gint)width andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight
{
	gtk_cell_renderer_get_preferred_height_for_width(GTK_CELL_RENDERER([self GOBJECT]), [widget WIDGET], width, minimumHeight, naturalHeight);
}

- (void)getPreferredSizeWithWidget:(OGTKWidget*)widget andMinimumSize:(GtkRequisition*)minimumSize andNaturalSize:(GtkRequisition*)naturalSize
{
	gtk_cell_renderer_get_preferred_size(GTK_CELL_RENDERER([self GOBJECT]), [widget WIDGET], minimumSize, naturalSize);
}

- (void)getPreferredWidthWithWidget:(OGTKWidget*)widget andMinimumSize:(gint*)minimumSize andNaturalSize:(gint*)naturalSize
{
	gtk_cell_renderer_get_preferred_width(GTK_CELL_RENDERER([self GOBJECT]), [widget WIDGET], minimumSize, naturalSize);
}

- (void)getPreferredWidthForHeightWithWidget:(OGTKWidget*)widget andHeight:(gint)height andMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth
{
	gtk_cell_renderer_get_preferred_width_for_height(GTK_CELL_RENDERER([self GOBJECT]), [widget WIDGET], height, minimumWidth, naturalWidth);
}

- (GtkSizeRequestMode)getRequestMode
{
	return gtk_cell_renderer_get_request_mode(GTK_CELL_RENDERER([self GOBJECT]));
}

- (bool)getSensitive
{
	return gtk_cell_renderer_get_sensitive(GTK_CELL_RENDERER([self GOBJECT]));
}

- (void)getSizeWithWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andXoffset:(gint*)xoffset andYoffset:(gint*)yoffset andWidth:(gint*)width andHeight:(gint*)height
{
	gtk_cell_renderer_get_size(GTK_CELL_RENDERER([self GOBJECT]), [widget WIDGET], cellArea, xoffset, yoffset, width, height);
}

- (GtkStateFlags)getStateWithWidget:(OGTKWidget*)widget andCellState:(GtkCellRendererState)cellState
{
	return gtk_cell_renderer_get_state(GTK_CELL_RENDERER([self GOBJECT]), [widget WIDGET], cellState);
}

- (bool)getVisible
{
	return gtk_cell_renderer_get_visible(GTK_CELL_RENDERER([self GOBJECT]));
}

- (bool)isActivatable
{
	return gtk_cell_renderer_is_activatable(GTK_CELL_RENDERER([self GOBJECT]));
}

- (void)renderWithCr:(cairo_t*)cr andWidget:(OGTKWidget*)widget andBackgroundArea:(const GdkRectangle*)backgroundArea andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags
{
	gtk_cell_renderer_render(GTK_CELL_RENDERER([self GOBJECT]), cr, [widget WIDGET], backgroundArea, cellArea, flags);
}

- (void)setAlignmentWithXalign:(gfloat)xalign andYalign:(gfloat)yalign
{
	gtk_cell_renderer_set_alignment(GTK_CELL_RENDERER([self GOBJECT]), xalign, yalign);
}

- (void)setFixedSizeWithWidth:(gint)width andHeight:(gint)height
{
	gtk_cell_renderer_set_fixed_size(GTK_CELL_RENDERER([self GOBJECT]), width, height);
}

- (void)setPaddingWithXpad:(gint)xpad andYpad:(gint)ypad
{
	gtk_cell_renderer_set_padding(GTK_CELL_RENDERER([self GOBJECT]), xpad, ypad);
}

- (void)setSensitive:(bool)sensitive
{
	gtk_cell_renderer_set_sensitive(GTK_CELL_RENDERER([self GOBJECT]), sensitive);
}

- (void)setVisible:(bool)visible
{
	gtk_cell_renderer_set_visible(GTK_CELL_RENDERER([self GOBJECT]), visible);
}

- (GtkCellEditable*)startEditingWithEvent:(GdkEvent*)event andWidget:(OGTKWidget*)widget andPath:(OFString*)path andBackgroundArea:(const GdkRectangle*)backgroundArea andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags
{
	return gtk_cell_renderer_start_editing(GTK_CELL_RENDERER([self GOBJECT]), event, [widget WIDGET], [path UTF8String], backgroundArea, cellArea, flags);
}

- (void)stopEditing:(bool)canceled
{
	gtk_cell_renderer_stop_editing(GTK_CELL_RENDERER([self GOBJECT]), canceled);
}


@end