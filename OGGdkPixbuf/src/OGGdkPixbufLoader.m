/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkPixbufLoader.h"

#import "OGGdkPixbuf.h"
#import "OGGdkPixbufAnimation.h"

@implementation OGGdkPixbufLoader

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_loader_new()];

	return self;
}

- (instancetype)initWithMimeTypeWithMimeType:(OFString*)mimeType err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_loader_new_with_mime_type([mimeType UTF8String], err)];

	return self;
}

- (instancetype)initWithTypeWithImageType:(OFString*)imageType err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_loader_new_with_type([imageType UTF8String], err)];

	return self;
}

- (GdkPixbufLoader*)PIXBUFLOADER
{
	return GDK_PIXBUF_LOADER([self GOBJECT]);
}

- (bool)close:(GError**)err
{
	return gdk_pixbuf_loader_close([self PIXBUFLOADER], err);
}

- (OGGdkPixbufAnimation*)animation
{
	return [[[OGGdkPixbufAnimation alloc] initWithGObject:(GObject*)gdk_pixbuf_loader_get_animation([self PIXBUFLOADER])] autorelease];
}

- (GdkPixbufFormat*)format
{
	return gdk_pixbuf_loader_get_format([self PIXBUFLOADER]);
}

- (OGGdkPixbuf*)pixbuf
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gdk_pixbuf_loader_get_pixbuf([self PIXBUFLOADER])] autorelease];
}

- (void)setSizeWithWidth:(int)width height:(int)height
{
	gdk_pixbuf_loader_set_size([self PIXBUFLOADER], width, height);
}

- (bool)writeWithBuf:(const guchar*)buf count:(gsize)count err:(GError**)err
{
	return gdk_pixbuf_loader_write([self PIXBUFLOADER], buf, count, err);
}

- (bool)writeBytesWithBuffer:(GBytes*)buffer err:(GError**)err
{
	return gdk_pixbuf_loader_write_bytes([self PIXBUFLOADER], buffer, err);
}


@end