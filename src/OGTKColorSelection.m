/*
 * OGTKColorSelection.m
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
#import "OGTKColorSelection.h"

@implementation OGTKColorSelection

+ (bool)paletteFromStringWithStr:(OFString*)str andColors:(GdkColor**)colors andNcolors:(gint*)ncolors
{
	return gtk_color_selection_palette_from_string([str UTF8String], colors, ncolors);
}

+ (OFString*)paletteToStringWithColors:(const GdkColor*)colors andNcolors:(gint)ncolors
{
	return [OFString stringWithUTF8String:gtk_color_selection_palette_to_string(colors, ncolors)];
}

+ (GtkColorSelectionChangePaletteWithScreenFunc)setChangePaletteWithScreenHook:(GtkColorSelectionChangePaletteWithScreenFunc)func
{
	return gtk_color_selection_set_change_palette_with_screen_hook(func);
}

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_color_selection_new()];

	return self;
}

- (GtkColorSelection*)COLORSELECTION
{
	return GTK_COLOR_SELECTION([self GOBJECT]);
}

- (guint16)getCurrentAlpha
{
	return gtk_color_selection_get_current_alpha(GTK_COLOR_SELECTION([self GOBJECT]));
}

- (void)getCurrentColor:(GdkColor*)color
{
	gtk_color_selection_get_current_color(GTK_COLOR_SELECTION([self GOBJECT]), color);
}

- (void)getCurrentRgba:(GdkRGBA*)rgba
{
	gtk_color_selection_get_current_rgba(GTK_COLOR_SELECTION([self GOBJECT]), rgba);
}

- (bool)getHasOpacityControl
{
	return gtk_color_selection_get_has_opacity_control(GTK_COLOR_SELECTION([self GOBJECT]));
}

- (bool)getHasPalette
{
	return gtk_color_selection_get_has_palette(GTK_COLOR_SELECTION([self GOBJECT]));
}

- (guint16)getPreviousAlpha
{
	return gtk_color_selection_get_previous_alpha(GTK_COLOR_SELECTION([self GOBJECT]));
}

- (void)getPreviousColor:(GdkColor*)color
{
	gtk_color_selection_get_previous_color(GTK_COLOR_SELECTION([self GOBJECT]), color);
}

- (void)getPreviousRgba:(GdkRGBA*)rgba
{
	gtk_color_selection_get_previous_rgba(GTK_COLOR_SELECTION([self GOBJECT]), rgba);
}

- (bool)isAdjusting
{
	return gtk_color_selection_is_adjusting(GTK_COLOR_SELECTION([self GOBJECT]));
}

- (void)setCurrentAlpha:(guint16)alpha
{
	gtk_color_selection_set_current_alpha(GTK_COLOR_SELECTION([self GOBJECT]), alpha);
}

- (void)setCurrentColor:(const GdkColor*)color
{
	gtk_color_selection_set_current_color(GTK_COLOR_SELECTION([self GOBJECT]), color);
}

- (void)setCurrentRgba:(const GdkRGBA*)rgba
{
	gtk_color_selection_set_current_rgba(GTK_COLOR_SELECTION([self GOBJECT]), rgba);
}

- (void)setHasOpacityControl:(bool)hasOpacity
{
	gtk_color_selection_set_has_opacity_control(GTK_COLOR_SELECTION([self GOBJECT]), hasOpacity);
}

- (void)setHasPalette:(bool)hasPalette
{
	gtk_color_selection_set_has_palette(GTK_COLOR_SELECTION([self GOBJECT]), hasPalette);
}

- (void)setPreviousAlpha:(guint16)alpha
{
	gtk_color_selection_set_previous_alpha(GTK_COLOR_SELECTION([self GOBJECT]), alpha);
}

- (void)setPreviousColor:(const GdkColor*)color
{
	gtk_color_selection_set_previous_color(GTK_COLOR_SELECTION([self GOBJECT]), color);
}

- (void)setPreviousRgba:(const GdkRGBA*)rgba
{
	gtk_color_selection_set_previous_rgba(GTK_COLOR_SELECTION([self GOBJECT]), rgba);
}


@end