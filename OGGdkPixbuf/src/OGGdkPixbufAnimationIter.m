/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkPixbufAnimationIter.h"

#import "OGGdkPixbuf.h"

@implementation OGGdkPixbufAnimationIter

- (GdkPixbufAnimationIter*)PIXBUFANIMATIONITER
{
	return GDK_PIXBUF_ANIMATION_ITER([self GOBJECT]);
}

- (bool)advance:(const GTimeVal*)currentTime
{
	return gdk_pixbuf_animation_iter_advance([self PIXBUFANIMATIONITER], currentTime);
}

- (int)delayTime
{
	return gdk_pixbuf_animation_iter_get_delay_time([self PIXBUFANIMATIONITER]);
}

- (OGGdkPixbuf*)pixbuf
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gdk_pixbuf_animation_iter_get_pixbuf([self PIXBUFANIMATIONITER])] autorelease];
}

- (bool)onCurrentlyLoadingFrame
{
	return gdk_pixbuf_animation_iter_on_currently_loading_frame([self PIXBUFANIMATIONITER]);
}


@end