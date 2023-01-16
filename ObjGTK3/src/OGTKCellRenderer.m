/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellRenderer.h"

#import "OGTKWidget.h"

@implementation OGTKCellRenderer

- (GtkCellRenderer*)CELLRENDERER
{
	return GTK_CELL_RENDERER([self GOBJECT]);
}

- (bool)activateWithEvent:(GdkEvent*)event widget:(OGTKWidget*)widget path:(OFString*)path backgroundArea:(const GdkRectangle*)backgroundArea cellArea:(const GdkRectangle*)cellArea flags:(GtkCellRendererState)flags
{
	return gtk_cell_renderer_activate([self CELLRENDERER], event, [widget WIDGET], [path UTF8String], backgroundArea, cellArea, flags);
}

- (void)alignedAreaWithWidget:(OGTKWidget*)widget flags:(GtkCellRendererState)flags cellArea:(const GdkRectangle*)cellArea alignedArea:(GdkRectangle*)alignedArea
{
	gtk_cell_renderer_get_aligned_area([self CELLRENDERER], [widget WIDGET], flags, cellArea, alignedArea);
}

- (void)alignmentWithXalign:(gfloat*)xalign yalign:(gfloat*)yalign
{
	gtk_cell_renderer_get_alignment([self CELLRENDERER], xalign, yalign);
}

- (void)fixedSizeWithWidth:(gint*)width height:(gint*)height
{
	gtk_cell_renderer_get_fixed_size([self CELLRENDERER], width, height);
}

- (void)paddingWithXpad:(gint*)xpad ypad:(gint*)ypad
{
	gtk_cell_renderer_get_padding([self CELLRENDERER], xpad, ypad);
}

- (void)preferredHeightWithWidget:(OGTKWidget*)widget minimumSize:(gint*)minimumSize naturalSize:(gint*)naturalSize
{
	gtk_cell_renderer_get_preferred_height([self CELLRENDERER], [widget WIDGET], minimumSize, naturalSize);
}

- (void)preferredHeightForWidthWithWidget:(OGTKWidget*)widget width:(gint)width minimumHeight:(gint*)minimumHeight naturalHeight:(gint*)naturalHeight
{
	gtk_cell_renderer_get_preferred_height_for_width([self CELLRENDERER], [widget WIDGET], width, minimumHeight, naturalHeight);
}

- (void)preferredSizeWithWidget:(OGTKWidget*)widget minimumSize:(GtkRequisition*)minimumSize naturalSize:(GtkRequisition*)naturalSize
{
	gtk_cell_renderer_get_preferred_size([self CELLRENDERER], [widget WIDGET], minimumSize, naturalSize);
}

- (void)preferredWidthWithWidget:(OGTKWidget*)widget minimumSize:(gint*)minimumSize naturalSize:(gint*)naturalSize
{
	gtk_cell_renderer_get_preferred_width([self CELLRENDERER], [widget WIDGET], minimumSize, naturalSize);
}

- (void)preferredWidthForHeightWithWidget:(OGTKWidget*)widget height:(gint)height minimumWidth:(gint*)minimumWidth naturalWidth:(gint*)naturalWidth
{
	gtk_cell_renderer_get_preferred_width_for_height([self CELLRENDERER], [widget WIDGET], height, minimumWidth, naturalWidth);
}

- (GtkSizeRequestMode)requestMode
{
	return gtk_cell_renderer_get_request_mode([self CELLRENDERER]);
}

- (bool)sensitive
{
	return gtk_cell_renderer_get_sensitive([self CELLRENDERER]);
}

- (void)sizeWithWidget:(OGTKWidget*)widget cellArea:(const GdkRectangle*)cellArea xoffset:(gint*)xoffset yoffset:(gint*)yoffset width:(gint*)width height:(gint*)height
{
	gtk_cell_renderer_get_size([self CELLRENDERER], [widget WIDGET], cellArea, xoffset, yoffset, width, height);
}

- (GtkStateFlags)stateWithWidget:(OGTKWidget*)widget cellState:(GtkCellRendererState)cellState
{
	return gtk_cell_renderer_get_state([self CELLRENDERER], [widget WIDGET], cellState);
}

- (bool)visible
{
	return gtk_cell_renderer_get_visible([self CELLRENDERER]);
}

- (bool)isActivatable
{
	return gtk_cell_renderer_is_activatable([self CELLRENDERER]);
}

- (void)renderWithCr:(cairo_t*)cr widget:(OGTKWidget*)widget backgroundArea:(const GdkRectangle*)backgroundArea cellArea:(const GdkRectangle*)cellArea flags:(GtkCellRendererState)flags
{
	gtk_cell_renderer_render([self CELLRENDERER], cr, [widget WIDGET], backgroundArea, cellArea, flags);
}

- (void)setAlignmentWithXalign:(gfloat)xalign yalign:(gfloat)yalign
{
	gtk_cell_renderer_set_alignment([self CELLRENDERER], xalign, yalign);
}

- (void)setFixedSizeWithWidth:(gint)width height:(gint)height
{
	gtk_cell_renderer_set_fixed_size([self CELLRENDERER], width, height);
}

- (void)setPaddingWithXpad:(gint)xpad ypad:(gint)ypad
{
	gtk_cell_renderer_set_padding([self CELLRENDERER], xpad, ypad);
}

- (void)setSensitive:(bool)sensitive
{
	gtk_cell_renderer_set_sensitive([self CELLRENDERER], sensitive);
}

- (void)setVisible:(bool)visible
{
	gtk_cell_renderer_set_visible([self CELLRENDERER], visible);
}

- (GtkCellEditable*)startEditingWithEvent:(GdkEvent*)event widget:(OGTKWidget*)widget path:(OFString*)path backgroundArea:(const GdkRectangle*)backgroundArea cellArea:(const GdkRectangle*)cellArea flags:(GtkCellRendererState)flags
{
	return gtk_cell_renderer_start_editing([self CELLRENDERER], event, [widget WIDGET], [path UTF8String], backgroundArea, cellArea, flags);
}

- (void)stopEditing:(bool)canceled
{
	gtk_cell_renderer_stop_editing([self CELLRENDERER], canceled);
}


@end