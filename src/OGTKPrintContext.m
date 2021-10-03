/*
 * OGTKPrintContext.m
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
#import "OGTKPrintContext.h"

@implementation OGTKPrintContext

- (GtkPrintContext*)PRINTCONTEXT
{
	return GTK_PRINT_CONTEXT([self GOBJECT]);
}

- (PangoContext*)createPangoContext
{
	return gtk_print_context_create_pango_context(GTK_PRINT_CONTEXT([self GOBJECT]));
}

- (PangoLayout*)createPangoLayout
{
	return gtk_print_context_create_pango_layout(GTK_PRINT_CONTEXT([self GOBJECT]));
}

- (cairo_t*)getCairoContext
{
	return gtk_print_context_get_cairo_context(GTK_PRINT_CONTEXT([self GOBJECT]));
}

- (gdouble)getDpiX
{
	return gtk_print_context_get_dpi_x(GTK_PRINT_CONTEXT([self GOBJECT]));
}

- (gdouble)getDpiY
{
	return gtk_print_context_get_dpi_y(GTK_PRINT_CONTEXT([self GOBJECT]));
}

- (bool)getHardMarginsWithTop:(gdouble*)top andBottom:(gdouble*)bottom andLeft:(gdouble*)left andRight:(gdouble*)right
{
	return gtk_print_context_get_hard_margins(GTK_PRINT_CONTEXT([self GOBJECT]), top, bottom, left, right);
}

- (gdouble)getHeight
{
	return gtk_print_context_get_height(GTK_PRINT_CONTEXT([self GOBJECT]));
}

- (GtkPageSetup*)getPageSetup
{
	return gtk_print_context_get_page_setup(GTK_PRINT_CONTEXT([self GOBJECT]));
}

- (PangoFontMap*)getPangoFontmap
{
	return gtk_print_context_get_pango_fontmap(GTK_PRINT_CONTEXT([self GOBJECT]));
}

- (gdouble)getWidth
{
	return gtk_print_context_get_width(GTK_PRINT_CONTEXT([self GOBJECT]));
}

- (void)setCairoContextWithCr:(cairo_t*)cr andDpiX:(double)dpiX andDpiY:(double)dpiY
{
	gtk_print_context_set_cairo_context(GTK_PRINT_CONTEXT([self GOBJECT]), cr, dpiX, dpiY);
}


@end