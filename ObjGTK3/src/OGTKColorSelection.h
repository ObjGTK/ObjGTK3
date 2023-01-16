/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

@class OGTKWidget;

@interface OGTKColorSelection : OGTKBox
{

}

/**
 * Functions
 */
+ (bool)paletteFromStringWithStr:(OFString*)str colors:(GdkColor**)colors ncolors:(gint*)ncolors;
+ (OFString*)paletteToStringWithColors:(const GdkColor*)colors ncolors:(gint)ncolors;
+ (GtkColorSelectionChangePaletteWithScreenFunc)setChangePaletteWithScreenHook:(GtkColorSelectionChangePaletteWithScreenFunc)func;

/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkColorSelection*)COLORSELECTION;

/**
 * Returns the current alpha value.
 *
 * @return an integer between 0 and 65535
 */
- (guint16)currentAlpha;

/**
 * Sets @color to be the current color in the GtkColorSelection widget.
 *
 * @param color a #GdkColor to fill in with the current color
 */
- (void)currentColor:(GdkColor*)color;

/**
 * Sets @rgba to be the current color in the GtkColorSelection widget.
 *
 * @param rgba a #GdkRGBA to fill in with the current color
 */
- (void)currentRgba:(GdkRGBA*)rgba;

/**
 * Determines whether the colorsel has an opacity control.
 *
 * @return %TRUE if the @colorsel has an opacity control,
 *     %FALSE if it does't
 */
- (bool)hasOpacityControl;

/**
 * Determines whether the color selector has a color palette.
 *
 * @return %TRUE if the selector has a palette, %FALSE if it hasn't
 */
- (bool)hasPalette;

/**
 * Returns the previous alpha value.
 *
 * @return an integer between 0 and 65535
 */
- (guint16)previousAlpha;

/**
 * Fills @color in with the original color value.
 *
 * @param color a #GdkColor to fill in with the original color value
 */
- (void)previousColor:(GdkColor*)color;

/**
 * Fills @rgba in with the original color value.
 *
 * @param rgba a #GdkRGBA to fill in with the original color value
 */
- (void)previousRgba:(GdkRGBA*)rgba;

/**
 * Gets the current state of the @colorsel.
 *
 * @return %TRUE if the user is currently dragging
 *     a color around, and %FALSE if the selection has stopped
 */
- (bool)isAdjusting;

/**
 * Sets the current opacity to be @alpha.
 * 
 * The first time this is called, it will also set
 * the original opacity to be @alpha too.
 *
 * @param alpha an integer between 0 and 65535
 */
- (void)setCurrentAlpha:(guint16)alpha;

/**
 * Sets the current color to be @color.
 * 
 * The first time this is called, it will also set
 * the original color to be @color too.
 *
 * @param color a #GdkColor to set the current color with
 */
- (void)setCurrentColor:(const GdkColor*)color;

/**
 * Sets the current color to be @rgba.
 * 
 * The first time this is called, it will also set
 * the original color to be @rgba too.
 *
 * @param rgba A #GdkRGBA to set the current color with
 */
- (void)setCurrentRgba:(const GdkRGBA*)rgba;

/**
 * Sets the @colorsel to use or not use opacity.
 *
 * @param hasOpacity %TRUE if @colorsel can set the opacity, %FALSE otherwise
 */
- (void)setHasOpacityControl:(bool)hasOpacity;

/**
 * Shows and hides the palette based upon the value of @has_palette.
 *
 * @param hasPalette %TRUE if palette is to be visible, %FALSE otherwise
 */
- (void)setHasPalette:(bool)hasPalette;

/**
 * Sets the “previous” alpha to be @alpha.
 * 
 * This function should be called with some hesitations,
 * as it might seem confusing to have that alpha change.
 *
 * @param alpha an integer between 0 and 65535
 */
- (void)setPreviousAlpha:(guint16)alpha;

/**
 * Sets the “previous” color to be @color.
 * 
 * This function should be called with some hesitations,
 * as it might seem confusing to have that color change.
 * Calling gtk_color_selection_set_current_color() will also
 * set this color the first time it is called.
 *
 * @param color a #GdkColor to set the previous color with
 */
- (void)setPreviousColor:(const GdkColor*)color;

/**
 * Sets the “previous” color to be @rgba.
 * 
 * This function should be called with some hesitations,
 * as it might seem confusing to have that color change.
 * Calling gtk_color_selection_set_current_rgba() will also
 * set this color the first time it is called.
 *
 * @param rgba a #GdkRGBA to set the previous color with
 */
- (void)setPreviousRgba:(const GdkRGBA*)rgba;

@end