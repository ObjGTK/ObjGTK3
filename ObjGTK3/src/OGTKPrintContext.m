/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPrintContext.h"

#import "OGTKPageSetup.h"
#import <OGPango/OGPangoFontMap.h>
#import <OGPango/OGPangoContext.h>
#import <OGPango/OGPangoLayout.h>

@implementation OGTKPrintContext

- (GtkPrintContext*)PRINTCONTEXT
{
	return GTK_PRINT_CONTEXT([self GOBJECT]);
}

- (OGPangoContext*)createPangoContext
{
	return [[[OGPangoContext alloc] initWithGObject:(GObject*)gtk_print_context_create_pango_context([self PRINTCONTEXT])] autorelease];
}

- (OGPangoLayout*)createPangoLayout
{
	return [[[OGPangoLayout alloc] initWithGObject:(GObject*)gtk_print_context_create_pango_layout([self PRINTCONTEXT])] autorelease];
}

- (cairo_t*)cairoContext
{
	return gtk_print_context_get_cairo_context([self PRINTCONTEXT]);
}

- (gdouble)dpiX
{
	return gtk_print_context_get_dpi_x([self PRINTCONTEXT]);
}

- (gdouble)dpiY
{
	return gtk_print_context_get_dpi_y([self PRINTCONTEXT]);
}

- (bool)hardMarginsWithTop:(gdouble*)top bottom:(gdouble*)bottom left:(gdouble*)left right:(gdouble*)right
{
	return gtk_print_context_get_hard_margins([self PRINTCONTEXT], top, bottom, left, right);
}

- (gdouble)height
{
	return gtk_print_context_get_height([self PRINTCONTEXT]);
}

- (OGTKPageSetup*)pageSetup
{
	return [[[OGTKPageSetup alloc] initWithGObject:(GObject*)gtk_print_context_get_page_setup([self PRINTCONTEXT])] autorelease];
}

- (OGPangoFontMap*)pangoFontmap
{
	return [[[OGPangoFontMap alloc] initWithGObject:(GObject*)gtk_print_context_get_pango_fontmap([self PRINTCONTEXT])] autorelease];
}

- (gdouble)width
{
	return gtk_print_context_get_width([self PRINTCONTEXT]);
}

- (void)setCairoContextWithCr:(cairo_t*)cr dpiX:(double)dpiX dpiY:(double)dpiY
{
	gtk_print_context_set_cairo_context([self PRINTCONTEXT], cr, dpiX, dpiY);
}


@end