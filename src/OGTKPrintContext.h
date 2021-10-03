/*
 * OGTKPrintContext.h
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
#import "OGTKBase.h"

@interface OGTKPrintContext : OGTKBase
{

}


/**
 * Methods
 */

- (GtkPrintContext*)PRINTCONTEXT;

/**
 * - (PangoContext**)createPangoContext;
 *
 * @returns PangoContext*
 */
- (PangoContext*)createPangoContext;

/**
 * - (PangoLayout**)createPangoLayout;
 *
 * @returns PangoLayout*
 */
- (PangoLayout*)createPangoLayout;

/**
 * - (cairo_t**)getCairoContext;
 *
 * @returns cairo_t*
 */
- (cairo_t*)getCairoContext;

/**
 * - (gdouble*)getDpiX;
 *
 * @returns gdouble
 */
- (gdouble)getDpiX;

/**
 * - (gdouble*)getDpiY;
 *
 * @returns gdouble
 */
- (gdouble)getDpiY;

/**
 * - (bool*)getHardMarginsWithTop:(gdouble*)top andBottom:(gdouble*)bottom andLeft:(gdouble*)left andRight:(gdouble*)right;
 *
 * @param top
 * @param bottom
 * @param left
 * @param right
 * @returns bool
 */
- (bool)getHardMarginsWithTop:(gdouble*)top andBottom:(gdouble*)bottom andLeft:(gdouble*)left andRight:(gdouble*)right;

/**
 * - (gdouble*)getHeight;
 *
 * @returns gdouble
 */
- (gdouble)getHeight;

/**
 * - (GtkPageSetup**)getPageSetup;
 *
 * @returns GtkPageSetup*
 */
- (GtkPageSetup*)getPageSetup;

/**
 * - (PangoFontMap**)getPangoFontmap;
 *
 * @returns PangoFontMap*
 */
- (PangoFontMap*)getPangoFontmap;

/**
 * - (gdouble*)getWidth;
 *
 * @returns gdouble
 */
- (gdouble)getWidth;

/**
 * - (void*)setCairoContextWithCr:(cairo_t*)cr andDpiX:(double)dpiX andDpiY:(double)dpiY;
 *
 * @param cr
 * @param dpiX
 * @param dpiY
 */
- (void)setCairoContextWithCr:(cairo_t*)cr andDpiX:(double)dpiX andDpiY:(double)dpiY;

@end