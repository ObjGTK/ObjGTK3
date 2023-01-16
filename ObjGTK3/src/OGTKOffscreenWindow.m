/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKOffscreenWindow.h"

#import <OGGdkPixbuf/OGGdkPixbuf.h>
#import "OGTKWidget.h"

@implementation OGTKOffscreenWindow

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_offscreen_window_new()];

	return self;
}

- (GtkOffscreenWindow*)OFFSCREENWINDOW
{
	return GTK_OFFSCREEN_WINDOW([self GOBJECT]);
}

- (OGGdkPixbuf*)pixbuf
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_offscreen_window_get_pixbuf([self OFFSCREENWINDOW])] autorelease];
}

- (cairo_surface_t*)surface
{
	return gtk_offscreen_window_get_surface([self OFFSCREENWINDOW]);
}


@end