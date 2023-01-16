/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkScreen.h"

#import "OGGdkWindow.h"
#import "OGGdkDisplay.h"
#import "OGGdkVisual.h"

@implementation OGGdkScreen

+ (OGGdkScreen*)default
{
	return [[[OGGdkScreen alloc] initWithGObject:(GObject*)gdk_screen_get_default()] autorelease];
}

+ (gint)height
{
	return gdk_screen_height();
}

+ (gint)heightMm
{
	return gdk_screen_height_mm();
}

+ (gint)width
{
	return gdk_screen_width();
}

+ (gint)widthMm
{
	return gdk_screen_width_mm();
}

- (GdkScreen*)SCREEN
{
	return GDK_SCREEN([self GOBJECT]);
}

- (OGGdkWindow*)activeWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_screen_get_active_window([self SCREEN])] autorelease];
}

- (OGGdkDisplay*)display
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_screen_get_display([self SCREEN])] autorelease];
}

- (const cairo_font_options_t*)fontOptions
{
	return gdk_screen_get_font_options([self SCREEN]);
}

- (gint)height
{
	return gdk_screen_get_height([self SCREEN]);
}

- (gint)heightMm
{
	return gdk_screen_get_height_mm([self SCREEN]);
}

- (gint)monitorAtPointWithX:(gint)x y:(gint)y
{
	return gdk_screen_get_monitor_at_point([self SCREEN], x, y);
}

- (gint)monitorAtWindow:(OGGdkWindow*)window
{
	return gdk_screen_get_monitor_at_window([self SCREEN], [window WINDOW]);
}

- (void)monitorGeometryWithMonitorNum:(gint)monitorNum dest:(GdkRectangle*)dest
{
	gdk_screen_get_monitor_geometry([self SCREEN], monitorNum, dest);
}

- (gint)monitorHeightMm:(gint)monitorNum
{
	return gdk_screen_get_monitor_height_mm([self SCREEN], monitorNum);
}

- (OFString*)monitorPlugName:(gint)monitorNum
{
	return [OFString stringWithUTF8String:gdk_screen_get_monitor_plug_name([self SCREEN], monitorNum)];
}

- (gint)monitorScaleFactor:(gint)monitorNum
{
	return gdk_screen_get_monitor_scale_factor([self SCREEN], monitorNum);
}

- (gint)monitorWidthMm:(gint)monitorNum
{
	return gdk_screen_get_monitor_width_mm([self SCREEN], monitorNum);
}

- (void)monitorWorkareaWithMonitorNum:(gint)monitorNum dest:(GdkRectangle*)dest
{
	gdk_screen_get_monitor_workarea([self SCREEN], monitorNum, dest);
}

- (gint)nmonitors
{
	return gdk_screen_get_n_monitors([self SCREEN]);
}

- (gint)number
{
	return gdk_screen_get_number([self SCREEN]);
}

- (gint)primaryMonitor
{
	return gdk_screen_get_primary_monitor([self SCREEN]);
}

- (gdouble)resolution
{
	return gdk_screen_get_resolution([self SCREEN]);
}

- (OGGdkVisual*)rgbaVisual
{
	return [[[OGGdkVisual alloc] initWithGObject:(GObject*)gdk_screen_get_rgba_visual([self SCREEN])] autorelease];
}

- (OGGdkWindow*)rootWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_screen_get_root_window([self SCREEN])] autorelease];
}

- (bool)settingWithName:(OFString*)name value:(GValue*)value
{
	return gdk_screen_get_setting([self SCREEN], [name UTF8String], value);
}

- (OGGdkVisual*)systemVisual
{
	return [[[OGGdkVisual alloc] initWithGObject:(GObject*)gdk_screen_get_system_visual([self SCREEN])] autorelease];
}

- (GList*)toplevelWindows
{
	return gdk_screen_get_toplevel_windows([self SCREEN]);
}

- (gint)width
{
	return gdk_screen_get_width([self SCREEN]);
}

- (gint)widthMm
{
	return gdk_screen_get_width_mm([self SCREEN]);
}

- (GList*)windowStack
{
	return gdk_screen_get_window_stack([self SCREEN]);
}

- (bool)isComposited
{
	return gdk_screen_is_composited([self SCREEN]);
}

- (GList*)listVisuals
{
	return gdk_screen_list_visuals([self SCREEN]);
}

- (OFString*)makeDisplayName
{
	return [OFString stringWithUTF8String:gdk_screen_make_display_name([self SCREEN])];
}

- (void)setFontOptions:(const cairo_font_options_t*)options
{
	gdk_screen_set_font_options([self SCREEN], options);
}

- (void)setResolution:(gdouble)dpi
{
	gdk_screen_set_resolution([self SCREEN], dpi);
}


@end