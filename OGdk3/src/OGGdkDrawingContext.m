/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkDrawingContext.h"

#import "OGGdkWindow.h"

@implementation OGGdkDrawingContext

- (GdkDrawingContext*)DRAWINGCONTEXT
{
	return GDK_DRAWING_CONTEXT([self GOBJECT]);
}

- (cairo_t*)cairoContext
{
	return gdk_drawing_context_get_cairo_context([self DRAWINGCONTEXT]);
}

- (cairo_region_t*)clip
{
	return gdk_drawing_context_get_clip([self DRAWINGCONTEXT]);
}

- (OGGdkWindow*)window
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_drawing_context_get_window([self DRAWINGCONTEXT])] autorelease];
}

- (bool)isValid
{
	return gdk_drawing_context_is_valid([self DRAWINGCONTEXT]);
}


@end