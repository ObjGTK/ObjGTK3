/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkPixbufAnimation.h"

#import "OGGdkPixbufAnimationIter.h"
#import "OGGdkPixbuf.h"

@implementation OGGdkPixbufAnimation

+ (void)newFromStreamAsyncWithStream:(GInputStream*)stream cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData
{
	gdk_pixbuf_animation_new_from_stream_async(stream, cancellable, callback, userData);
}

- (instancetype)initFromFileWithFilename:(OFString*)filename err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_animation_new_from_file([filename UTF8String], err)];

	return self;
}

- (instancetype)initFromResourceWithResourcePath:(OFString*)resourcePath err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_animation_new_from_resource([resourcePath UTF8String], err)];

	return self;
}

- (instancetype)initFromStreamWithStream:(GInputStream*)stream cancellable:(GCancellable*)cancellable err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_animation_new_from_stream(stream, cancellable, err)];

	return self;
}

- (instancetype)initFromStreamFinishWithAsyncResult:(GAsyncResult*)asyncResult err:(GError**)err
{
	self = [super initWithGObject:(GObject*)gdk_pixbuf_animation_new_from_stream_finish(asyncResult, err)];

	return self;
}

- (GdkPixbufAnimation*)PIXBUFANIMATION
{
	return GDK_PIXBUF_ANIMATION([self GOBJECT]);
}

- (int)height
{
	return gdk_pixbuf_animation_get_height([self PIXBUFANIMATION]);
}

- (OGGdkPixbufAnimationIter*)iter:(const GTimeVal*)startTime
{
	return [[[OGGdkPixbufAnimationIter alloc] initWithGObject:(GObject*)gdk_pixbuf_animation_get_iter([self PIXBUFANIMATION], startTime)] autorelease];
}

- (OGGdkPixbuf*)staticImage
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gdk_pixbuf_animation_get_static_image([self PIXBUFANIMATION])] autorelease];
}

- (int)width
{
	return gdk_pixbuf_animation_get_width([self PIXBUFANIMATION]);
}

- (bool)isStaticImage
{
	return gdk_pixbuf_animation_is_static_image([self PIXBUFANIMATION]);
}


@end