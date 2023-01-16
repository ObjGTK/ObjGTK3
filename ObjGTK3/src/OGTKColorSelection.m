/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKColorSelection.h"

#import "OGTKWidget.h"

@implementation OGTKColorSelection

+ (bool)paletteFromStringWithStr:(OFString*)str colors:(GdkColor**)colors ncolors:(gint*)ncolors
{
	return gtk_color_selection_palette_from_string([str UTF8String], colors, ncolors);
}

+ (OFString*)paletteToStringWithColors:(const GdkColor*)colors ncolors:(gint)ncolors
{
	return [OFString stringWithUTF8String:gtk_color_selection_palette_to_string(colors, ncolors)];
}

+ (GtkColorSelectionChangePaletteWithScreenFunc)setChangePaletteWithScreenHook:(GtkColorSelectionChangePaletteWithScreenFunc)func
{
	return gtk_color_selection_set_change_palette_with_screen_hook(func);
}

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_color_selection_new()];

	return self;
}

- (GtkColorSelection*)COLORSELECTION
{
	return GTK_COLOR_SELECTION([self GOBJECT]);
}

- (guint16)currentAlpha
{
	return gtk_color_selection_get_current_alpha([self COLORSELECTION]);
}

- (void)currentColor:(GdkColor*)color
{
	gtk_color_selection_get_current_color([self COLORSELECTION], color);
}

- (void)currentRgba:(GdkRGBA*)rgba
{
	gtk_color_selection_get_current_rgba([self COLORSELECTION], rgba);
}

- (bool)hasOpacityControl
{
	return gtk_color_selection_get_has_opacity_control([self COLORSELECTION]);
}

- (bool)hasPalette
{
	return gtk_color_selection_get_has_palette([self COLORSELECTION]);
}

- (guint16)previousAlpha
{
	return gtk_color_selection_get_previous_alpha([self COLORSELECTION]);
}

- (void)previousColor:(GdkColor*)color
{
	gtk_color_selection_get_previous_color([self COLORSELECTION], color);
}

- (void)previousRgba:(GdkRGBA*)rgba
{
	gtk_color_selection_get_previous_rgba([self COLORSELECTION], rgba);
}

- (bool)isAdjusting
{
	return gtk_color_selection_is_adjusting([self COLORSELECTION]);
}

- (void)setCurrentAlpha:(guint16)alpha
{
	gtk_color_selection_set_current_alpha([self COLORSELECTION], alpha);
}

- (void)setCurrentColor:(const GdkColor*)color
{
	gtk_color_selection_set_current_color([self COLORSELECTION], color);
}

- (void)setCurrentRgba:(const GdkRGBA*)rgba
{
	gtk_color_selection_set_current_rgba([self COLORSELECTION], rgba);
}

- (void)setHasOpacityControl:(bool)hasOpacity
{
	gtk_color_selection_set_has_opacity_control([self COLORSELECTION], hasOpacity);
}

- (void)setHasPalette:(bool)hasPalette
{
	gtk_color_selection_set_has_palette([self COLORSELECTION], hasPalette);
}

- (void)setPreviousAlpha:(guint16)alpha
{
	gtk_color_selection_set_previous_alpha([self COLORSELECTION], alpha);
}

- (void)setPreviousColor:(const GdkColor*)color
{
	gtk_color_selection_set_previous_color([self COLORSELECTION], color);
}

- (void)setPreviousRgba:(const GdkRGBA*)rgba
{
	gtk_color_selection_set_previous_rgba([self COLORSELECTION], rgba);
}


@end