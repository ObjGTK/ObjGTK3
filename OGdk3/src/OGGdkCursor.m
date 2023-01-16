/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkCursor.h"

#import "OGGdkDisplay.h"
#import <OGGdkPixbuf/OGGdkPixbuf.h>

@implementation OGGdkCursor

- (instancetype)init:(GdkCursorType)cursorType
{
	self = [super initWithGObject:(GObject*)gdk_cursor_new(cursorType)];

	return self;
}

- (instancetype)initForDisplayWithDisplay:(OGGdkDisplay*)display cursorType:(GdkCursorType)cursorType
{
	self = [super initWithGObject:(GObject*)gdk_cursor_new_for_display([display DISPLAY], cursorType)];

	return self;
}

- (instancetype)initFromNameWithDisplay:(OGGdkDisplay*)display name:(OFString*)name
{
	self = [super initWithGObject:(GObject*)gdk_cursor_new_from_name([display DISPLAY], [name UTF8String])];

	return self;
}

- (instancetype)initFromPixbufWithDisplay:(OGGdkDisplay*)display pixbuf:(OGGdkPixbuf*)pixbuf x:(gint)x y:(gint)y
{
	self = [super initWithGObject:(GObject*)gdk_cursor_new_from_pixbuf([display DISPLAY], [pixbuf PIXBUF], x, y)];

	return self;
}

- (instancetype)initFromSurfaceWithDisplay:(OGGdkDisplay*)display surface:(cairo_surface_t*)surface x:(gdouble)x y:(gdouble)y
{
	self = [super initWithGObject:(GObject*)gdk_cursor_new_from_surface([display DISPLAY], surface, x, y)];

	return self;
}

- (GdkCursor*)CURSOR
{
	return GDK_CURSOR([self GOBJECT]);
}

- (GdkCursorType)cursorType
{
	return gdk_cursor_get_cursor_type([self CURSOR]);
}

- (OGGdkDisplay*)display
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_cursor_get_display([self CURSOR])] autorelease];
}

- (OGGdkPixbuf*)image
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gdk_cursor_get_image([self CURSOR])] autorelease];
}

- (cairo_surface_t*)surfaceWithXhot:(gdouble*)xhot yhot:(gdouble*)yhot
{
	return gdk_cursor_get_surface([self CURSOR], xhot, yhot);
}


@end