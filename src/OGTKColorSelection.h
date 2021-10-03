/*
 * OGTKColorSelection.h
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
#import "OGTKBox.h"

@interface OGTKColorSelection : OGTKBox
{

}

/**
 * Functions
 */
+ (bool)paletteFromStringWithStr:(OFString*)str andColors:(GdkColor**)colors andNcolors:(gint*)ncolors;
+ (OFString*)paletteToStringWithColors:(const GdkColor*)colors andNcolors:(gint)ncolors;
+ (GtkColorSelectionChangePaletteWithScreenFunc)setChangePaletteWithScreenHook:(GtkColorSelectionChangePaletteWithScreenFunc)func;

/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkColorSelection*)COLORSELECTION;

/**
 * - (guint16*)getCurrentAlpha;
 *
 * @returns guint16
 */
- (guint16)getCurrentAlpha;

/**
 * - (void*)getCurrentColor:(GdkColor*)color;
 *
 * @param color
 */
- (void)getCurrentColor:(GdkColor*)color;

/**
 * - (void*)getCurrentRgba:(GdkRGBA*)rgba;
 *
 * @param rgba
 */
- (void)getCurrentRgba:(GdkRGBA*)rgba;

/**
 * - (bool*)getHasOpacityControl;
 *
 * @returns bool
 */
- (bool)getHasOpacityControl;

/**
 * - (bool*)getHasPalette;
 *
 * @returns bool
 */
- (bool)getHasPalette;

/**
 * - (guint16*)getPreviousAlpha;
 *
 * @returns guint16
 */
- (guint16)getPreviousAlpha;

/**
 * - (void*)getPreviousColor:(GdkColor*)color;
 *
 * @param color
 */
- (void)getPreviousColor:(GdkColor*)color;

/**
 * - (void*)getPreviousRgba:(GdkRGBA*)rgba;
 *
 * @param rgba
 */
- (void)getPreviousRgba:(GdkRGBA*)rgba;

/**
 * - (bool*)isAdjusting;
 *
 * @returns bool
 */
- (bool)isAdjusting;

/**
 * - (void*)setCurrentAlpha:(guint16)alpha;
 *
 * @param alpha
 */
- (void)setCurrentAlpha:(guint16)alpha;

/**
 * - (void*)setCurrentColor:(const GdkColor*)color;
 *
 * @param color
 */
- (void)setCurrentColor:(const GdkColor*)color;

/**
 * - (void*)setCurrentRgba:(const GdkRGBA*)rgba;
 *
 * @param rgba
 */
- (void)setCurrentRgba:(const GdkRGBA*)rgba;

/**
 * - (void*)setHasOpacityControl:(bool)hasOpacity;
 *
 * @param hasOpacity
 */
- (void)setHasOpacityControl:(bool)hasOpacity;

/**
 * - (void*)setHasPalette:(bool)hasPalette;
 *
 * @param hasPalette
 */
- (void)setHasPalette:(bool)hasPalette;

/**
 * - (void*)setPreviousAlpha:(guint16)alpha;
 *
 * @param alpha
 */
- (void)setPreviousAlpha:(guint16)alpha;

/**
 * - (void*)setPreviousColor:(const GdkColor*)color;
 *
 * @param color
 */
- (void)setPreviousColor:(const GdkColor*)color;

/**
 * - (void*)setPreviousRgba:(const GdkRGBA*)rgba;
 *
 * @param rgba
 */
- (void)setPreviousRgba:(const GdkRGBA*)rgba;

@end