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

/**
 * Get the visual with the most available colors for the default
 * GDK screen. The return value should not be freed.
 *
 * @return best visual
 */
+ (OGGdkVisual*)best;

/**
 * Get the best available depth for the default GDK screen.  “Best”
 * means “largest,” i.e. 32 preferred over 24 preferred over 8 bits
 * per pixel.
 *
 * @return best available depth
 */
+ (gint)bestDepth;

/**
 * Return the best available visual type for the default GDK screen.
 *
 * @return best visual type
 */
+ (GdkVisualType)bestType;

/**
 * Combines gdk_visual_get_best_with_depth() and
 * gdk_visual_get_best_with_type().
 *
 * @param depth a bit depth
 * @param visualType a visual type
 * @return best visual with both @depth
 *     and @visual_type, or %NULL if none
 */
+ (OGGdkVisual*)bestWithBothWithDepth:(gint)depth visualType:(GdkVisualType)visualType;

/**
 * Get the best visual with depth @depth for the default GDK screen.
 * Color visuals and visuals with mutable colormaps are preferred
 * over grayscale or fixed-colormap visuals. The return value should
 * not be freed. %NULL may be returned if no visual supports @depth.
 *
 * @param depth a bit depth
 * @return best visual for the given depth
 */
+ (OGGdkVisual*)bestWithDepth:(gint)depth;

/**
 * Visual selection should be done using
 *     gdk_screen_get_system_visual() and gdk_screen_get_rgba_visual()
 *
 * @param visualType a visual type
 * @return best visual of the given type
 */
+ (OGGdkVisual*)bestWithType:(GdkVisualType)visualType;

/**
 * Use gdk_screen_get_system_visual (gdk_screen_get_default ()).
 *
 * @return system visual
 */
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