/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkPixbufSimpleAnim.h"

#import "OGGdkPixbuf.h"

@implementation OGGdkPixbufSimpleAnim

- (instancetype)initWithWidth:(gint)width height:(gint)height rate:(gfloat)rate
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_simple_anim_new(width, height, rate)];

	return self;
}

- (GdkPixbufSimpleAnim*)PIXBUFSIMPLEANIM
{
	return GDK_PIXBUF_SIMPLE_ANIM([self GOBJECT]);
}

- (void)addFrame:(OGGdkPixbuf*)pixbuf
{
	gdk_pixbuf_simple_anim_add_frame([self PIXBUFSIMPLEANIM], [pixbuf PIXBUF]);
}

- (bool)loop
{
	return gdk_pixbuf_simple_anim_get_loop([self PIXBUFSIMPLEANIM]);
}

- (void)setLoop:(bool)loop
{
	gdk_pixbuf_simple_anim_set_loop([self PIXBUFSIMPLEANIM], loop);
}


@end