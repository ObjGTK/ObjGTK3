/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkVisual.h"

#import "OGGdkScreen.h"

@implementation OGGdkVisual

+ (OGGdkVisual*)best
{
	return [[[OGGdkVisual alloc] initWithGObject:(GObject*)gdk_visual_get_best()] autorelease];
}

+ (gint)bestDepth
{
	return gdk_visual_get_best_depth();
}

+ (GdkVisualType)bestType
{
	return gdk_visual_get_best_type();
}

+ (OGGdkVisual*)bestWithBothWithDepth:(gint)depth visualType:(GdkVisualType)visualType
{
	return [[[OGGdkVisual alloc] initWithGObject:(GObject*)gdk_visual_get_best_with_both(depth, visualType)] autorelease];
}

+ (OGGdkVisual*)bestWithDepth:(gint)depth
{
	return [[[OGGdkVisual alloc] initWithGObject:(GObject*)gdk_visual_get_best_with_depth(depth)] autorelease];
}

+ (OGGdkVisual*)bestWithType:(GdkVisualType)visualType
{
	return [[[OGGdkVisual alloc] initWithGObject:(GObject*)gdk_visual_get_best_with_type(visualType)] autorelease];
}

+ (OGGdkVisual*)system
{
	return [[[OGGdkVisual alloc] initWithGObject:(GObject*)gdk_visual_get_system()] autorelease];
}

- (GdkVisual*)VISUAL
{
	return GDK_VISUAL([self GOBJECT]);
}

- (gint)bitsPerRgb
{
	return gdk_visual_get_bits_per_rgb([self VISUAL]);
}

- (void)bluePixelDetailsWithMask:(guint32*)mask shift:(gint*)shift precision:(gint*)precision
{
	gdk_visual_get_blue_pixel_details([self VISUAL], mask, shift, precision);
}

- (GdkByteOrder)byteOrder
{
	return gdk_visual_get_byte_order([self VISUAL]);
}

- (gint)colormapSize
{
	return gdk_visual_get_colormap_size([self VISUAL]);
}

- (gint)depth
{
	return gdk_visual_get_depth([self VISUAL]);
}

- (void)greenPixelDetailsWithMask:(guint32*)mask shift:(gint*)shift precision:(gint*)precision
{
	gdk_visual_get_green_pixel_details([self VISUAL], mask, shift, precision);
}

- (void)redPixelDetailsWithMask:(guint32*)mask shift:(gint*)shift precision:(gint*)precision
{
	gdk_visual_get_red_pixel_details([self VISUAL], mask, shift, precision);
}

- (OGGdkScreen*)screen
{
	return [[[OGGdkScreen alloc] initWithGObject:(GObject*)gdk_visual_get_screen([self VISUAL])] autorelease];
}

- (GdkVisualType)visualType
{
	return gdk_visual_get_visual_type([self VISUAL]);
}


@end