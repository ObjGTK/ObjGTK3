/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKButton.h"

@class OGTKWidget;

/**
 * The #GtkColorButton is a button which displays the currently selected
 * color and allows to open a color selection dialog to change the color.
 * It is suitable widget for selecting a color in a preference dialog.
 * 
 * # CSS nodes
 * 
 * GtkColorButton has a single CSS node with name button. To differentiate
 * it from a plain #GtkButton, it gets the .color style class.
 *
 */
@interface OGTKColorButton : OGTKButton
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initWithColor:(const GdkColor*)color;
- (instancetype)initWithRgba:(const GdkRGBA*)rgba;

/**
 * Methods
 */

- (GtkColorButton*)COLORBUTTON;

/**
 * Returns the current alpha value.
 *
 * @return an integer between 0 and 65535
 */
- (guint16)alpha;

/**
 * Sets @color to be the current color in the #GtkColorButton widget.
 *
 * @param color a #GdkColor to fill in with the current color
 */
- (void)color:(GdkColor*)color;

/**
 * Sets @rgba to be the current color in the #GtkColorButton widget.
 *
 * @param rgba a #GdkRGBA to fill in with the current color
 */
- (void)rgba:(GdkRGBA*)rgba;

/**
 * Gets the title of the color selection dialog.
 *
 * @return An internal string, do not free the return value
 */
- (OFString*)title;

/**
 * Does the color selection dialog use the alpha channel ?
 *
 * @return %TRUE if the color sample uses alpha channel, %FALSE if not
 */
- (bool)useAlpha;

/**
 * Sets the current opacity to be @alpha.
 *
 * @param alpha an integer between 0 and 65535
 */
- (void)setAlpha:(guint16)alpha;

/**
 * Sets the current color to be @color.
 *
 * @param color A #GdkColor to set the current color with
 */
- (void)setColor:(const GdkColor*)color;

/**
 * Sets the current color to be @rgba.
 *
 * @param rgba a #GdkRGBA to set the current color with
 */
- (void)setRgba:(const GdkRGBA*)rgba;

/**
 * Sets the title for the color selection dialog.
 *
 * @param title String containing new window title
 */
- (void)setTitle:(OFString*)title;

/**
 * Sets whether or not the color button should use the alpha channel.
 *
 * @param useAlpha %TRUE if color button should use alpha channel, %FALSE if not
 */
- (void)setUseAlpha:(bool)useAlpha;

@end