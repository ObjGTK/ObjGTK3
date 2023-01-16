/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkMonitor.h"

#import "OGGdkDisplay.h"

@implementation OGGdkMonitor

- (GdkMonitor*)MONITOR
{
	return GDK_MONITOR([self GOBJECT]);
}

- (OGGdkDisplay*)display
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_monitor_get_display([self MONITOR])] autorelease];
}

- (void)geometry:(GdkRectangle*)geometry
{
	gdk_monitor_get_geometry([self MONITOR], geometry);
}

- (int)heightMm
{
	return gdk_monitor_get_height_mm([self MONITOR]);
}

- (OFString*)manufacturer
{
	return [OFString stringWithUTF8String:gdk_monitor_get_manufacturer([self MONITOR])];
}

- (OFString*)model
{
	return [OFString stringWithUTF8String:gdk_monitor_get_model([self MONITOR])];
}

- (int)refreshRate
{
	return gdk_monitor_get_refresh_rate([self MONITOR]);
}

- (int)scaleFactor
{
	return gdk_monitor_get_scale_factor([self MONITOR]);
}

- (GdkSubpixelLayout)subpixelLayout
{
	return gdk_monitor_get_subpixel_layout([self MONITOR]);
}

- (int)widthMm
{
	return gdk_monitor_get_width_mm([self MONITOR]);
}

- (void)workarea:(GdkRectangle*)workarea
{
	gdk_monitor_get_workarea([self MONITOR], workarea);
}

- (bool)isPrimary
{
	return gdk_monitor_is_primary([self MONITOR]);
}


@end