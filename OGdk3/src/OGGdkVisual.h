/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkScreen;

/**
 * A #GdkVisual contains information about
 * a particular visual.
 *
 */
@interface OGGdkVisual : OGObject
{

}

/**
 * Functions
 */
+ (OGGdkVisual*)best;
+ (gint)bestDepth;
+ (GdkVisualType)bestType;
+ (OGGdkVisual*)bestWithBothWithDepth:(gint)depth visualType:(GdkVisualType)visualType;
+ (OGGdkVisual*)bestWithDepth:(gint)depth;
+ (OGGdkVisual*)bestWithType:(GdkVisualType)visualType;
+ (OGGdkVisual*)system;

/**
 * Methods
 */

- (GdkVisual*)VISUAL;

/**
 * Returns the number of significant bits per red, green and blue value.
 * 
 * Not all GDK backend provide a meaningful value for this function.
 *
 * @return The number of significant bits per color value for @visual.
 */
- (gint)bitsPerRgb;

/**
 * Obtains values that are needed to calculate blue pixel values in TrueColor
 * and DirectColor. The “mask” is the significant bits within the pixel.
 * The “shift” is the number of bits left we must shift a primary for it
 * to be in position (according to the "mask"). Finally, "precision" refers
 * to how much precision the pixel value contains for a particular primary.
 *
 * @param mask A pointer to a #guint32 to be filled in, or %NULL
 * @param shift A pointer to a #gint to be filled in, or %NULL
 * @param precision A pointer to a #gint to be filled in, or %NULL
 */
- (void)bluePixelDetailsWithMask:(guint32*)mask shift:(gint*)shift precision:(gint*)precision;

/**
 * Returns the byte order of this visual.
 * 
 * The information returned by this function is only relevant
 * when working with XImages, and not all backends return
 * meaningful information for this.
 *
 * @return A #GdkByteOrder stating the byte order of @visual.
 */
- (GdkByteOrder)byteOrder;

/**
 * Returns the size of a colormap for this visual.
 * 
 * You have to use platform-specific APIs to manipulate colormaps.
 *
 * @return The size of a colormap that is suitable for @visual.
 */
- (gint)colormapSize;

/**
 * Returns the bit depth of this visual.
 *
 * @return The bit depth of this visual.
 */
- (gint)depth;

/**
 * Obtains values that are needed to calculate green pixel values in TrueColor
 * and DirectColor. The “mask” is the significant bits within the pixel.
 * The “shift” is the number of bits left we must shift a primary for it
 * to be in position (according to the "mask"). Finally, "precision" refers
 * to how much precision the pixel value contains for a particular primary.
 *
 * @param mask A pointer to a #guint32 to be filled in, or %NULL
 * @param shift A pointer to a #gint to be filled in, or %NULL
 * @param precision A pointer to a #gint to be filled in, or %NULL
 */
- (void)greenPixelDetailsWithMask:(guint32*)mask shift:(gint*)shift precision:(gint*)precision;

/**
 * Obtains values that are needed to calculate red pixel values in TrueColor
 * and DirectColor. The “mask” is the significant bits within the pixel.
 * The “shift” is the number of bits left we must shift a primary for it
 * to be in position (according to the "mask"). Finally, "precision" refers
 * to how much precision the pixel value contains for a particular primary.
 *
 * @param mask A pointer to a #guint32 to be filled in, or %NULL
 * @param shift A pointer to a #gint to be filled in, or %NULL
 * @param precision A pointer to a #gint to be filled in, or %NULL
 */
- (void)redPixelDetailsWithMask:(guint32*)mask shift:(gint*)shift precision:(gint*)precision;

/**
 * Gets the screen to which this visual belongs
 *
 * @return the screen to which this visual belongs.
 */
- (OGGdkScreen*)screen;

/**
 * Returns the type of visual this is (PseudoColor, TrueColor, etc).
 *
 * @return A #GdkVisualType stating the type of @visual.
 */
- (GdkVisualType)visualType;

@end