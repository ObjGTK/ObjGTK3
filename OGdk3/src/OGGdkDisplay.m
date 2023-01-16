/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkDisplay.h"

#import "OGGdkAppLaunchContext.h"
#import "OGGdkDevice.h"
#import "OGGdkScreen.h"
#import "OGGdkDeviceManager.h"
#import "OGGdkMonitor.h"
#import "OGGdkWindow.h"
#import "OGGdkSeat.h"

@implementation OGGdkDisplay

+ (OGGdkDisplay*)default
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_display_get_default()] autorelease];
}

+ (OGGdkDisplay*)open:(OFString*)displayName
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_display_open([displayName UTF8String])] autorelease];
}

+ (OGGdkDisplay*)openDefaultLibgtkOnly
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_display_open_default_libgtk_only()] autorelease];
}

- (GdkDisplay*)DISPLAY
{
	return GDK_DISPLAY([self GOBJECT]);
}

- (void)beep
{
	gdk_display_beep([self DISPLAY]);
}

- (void)close
{
	gdk_display_close([self DISPLAY]);
}

- (bool)deviceIsGrabbed:(OGGdkDevice*)device
{
	return gdk_display_device_is_grabbed([self DISPLAY], [device DEVICE]);
}

- (void)flush
{
	gdk_display_flush([self DISPLAY]);
}

- (OGGdkAppLaunchContext*)appLaunchContext
{
	return [[[OGGdkAppLaunchContext alloc] initWithGObject:(GObject*)gdk_display_get_app_launch_context([self DISPLAY])] autorelease];
}

- (guint)defaultCursorSize
{
	return gdk_display_get_default_cursor_size([self DISPLAY]);
}

- (OGGdkWindow*)defaultGroup
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_display_get_default_group([self DISPLAY])] autorelease];
}

- (OGGdkScreen*)defaultScreen
{
	return [[[OGGdkScreen alloc] initWithGObject:(GObject*)gdk_display_get_default_screen([self DISPLAY])] autorelease];
}

- (OGGdkSeat*)defaultSeat
{
	return [[[OGGdkSeat alloc] initWithGObject:(GObject*)gdk_display_get_default_seat([self DISPLAY])] autorelease];
}

- (OGGdkDeviceManager*)deviceManager
{
	return [[[OGGdkDeviceManager alloc] initWithGObject:(GObject*)gdk_display_get_device_manager([self DISPLAY])] autorelease];
}

- (GdkEvent*)event
{
	return gdk_display_get_event([self DISPLAY]);
}

- (void)maximalCursorSizeWithWidth:(guint*)width height:(guint*)height
{
	gdk_display_get_maximal_cursor_size([self DISPLAY], width, height);
}

- (OGGdkMonitor*)monitor:(int)monitorNum
{
	return [[[OGGdkMonitor alloc] initWithGObject:(GObject*)gdk_display_get_monitor([self DISPLAY], monitorNum)] autorelease];
}

- (OGGdkMonitor*)monitorAtPointWithX:(int)x y:(int)y
{
	return [[[OGGdkMonitor alloc] initWithGObject:(GObject*)gdk_display_get_monitor_at_point([self DISPLAY], x, y)] autorelease];
}

- (OGGdkMonitor*)monitorAtWindow:(OGGdkWindow*)window
{
	return [[[OGGdkMonitor alloc] initWithGObject:(GObject*)gdk_display_get_monitor_at_window([self DISPLAY], [window WINDOW])] autorelease];
}

- (int)nmonitors
{
	return gdk_display_get_n_monitors([self DISPLAY]);
}

- (gint)nscreens
{
	return gdk_display_get_n_screens([self DISPLAY]);
}

- (OFString*)name
{
	return [OFString stringWithUTF8String:gdk_display_get_name([self DISPLAY])];
}

- (void)pointerWithScreen:(GdkScreen**)screen x:(gint*)x y:(gint*)y mask:(GdkModifierType*)mask
{
	gdk_display_get_pointer([self DISPLAY], screen, x, y, mask);
}

- (OGGdkMonitor*)primaryMonitor
{
	return [[[OGGdkMonitor alloc] initWithGObject:(GObject*)gdk_display_get_primary_monitor([self DISPLAY])] autorelease];
}

- (OGGdkScreen*)screen:(gint)screenNum
{
	return [[[OGGdkScreen alloc] initWithGObject:(GObject*)gdk_display_get_screen([self DISPLAY], screenNum)] autorelease];
}

- (OGGdkWindow*)windowAtPointerWithWinX:(gint*)winX winY:(gint*)winY
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_display_get_window_at_pointer([self DISPLAY], winX, winY)] autorelease];
}

- (bool)hasPending
{
	return gdk_display_has_pending([self DISPLAY]);
}

- (bool)isClosed
{
	return gdk_display_is_closed([self DISPLAY]);
}

- (void)keyboardUngrab:(guint32)time
{
	gdk_display_keyboard_ungrab([self DISPLAY], time);
}

- (GList*)listDevices
{
	return gdk_display_list_devices([self DISPLAY]);
}

- (GList*)listSeats
{
	return gdk_display_list_seats([self DISPLAY]);
}

- (void)notifyStartupComplete:(OFString*)startupId
{
	gdk_display_notify_startup_complete([self DISPLAY], [startupId UTF8String]);
}

- (GdkEvent*)peekEvent
{
	return gdk_display_peek_event([self DISPLAY]);
}

- (bool)pointerIsGrabbed
{
	return gdk_display_pointer_is_grabbed([self DISPLAY]);
}

- (void)pointerUngrab:(guint32)time
{
	gdk_display_pointer_ungrab([self DISPLAY], time);
}

- (void)putEvent:(const GdkEvent*)event
{
	gdk_display_put_event([self DISPLAY], event);
}

- (bool)requestSelectionNotification:(GdkAtom)selection
{
	return gdk_display_request_selection_notification([self DISPLAY], selection);
}

- (void)setDoubleClickDistance:(guint)distance
{
	gdk_display_set_double_click_distance([self DISPLAY], distance);
}

- (void)setDoubleClickTime:(guint)msec
{
	gdk_display_set_double_click_time([self DISPLAY], msec);
}

- (void)storeClipboardWithClipboardWindow:(OGGdkWindow*)clipboardWindow time:(guint32)time targets:(const GdkAtom*)targets ntargets:(gint)ntargets
{
	gdk_display_store_clipboard([self DISPLAY], [clipboardWindow WINDOW], time, targets, ntargets);
}

- (bool)supportsClipboardPersistence
{
	return gdk_display_supports_clipboard_persistence([self DISPLAY]);
}

- (bool)supportsComposite
{
	return gdk_display_supports_composite([self DISPLAY]);
}

- (bool)supportsCursorAlpha
{
	return gdk_display_supports_cursor_alpha([self DISPLAY]);
}

- (bool)supportsCursorColor
{
	return gdk_display_supports_cursor_color([self DISPLAY]);
}

- (bool)supportsInputShapes
{
	return gdk_display_supports_input_shapes([self DISPLAY]);
}

- (bool)supportsSelectionNotification
{
	return gdk_display_supports_selection_notification([self DISPLAY]);
}

- (bool)supportsShapes
{
	return gdk_display_supports_shapes([self DISPLAY]);
}

- (void)sync
{
	gdk_display_sync([self DISPLAY]);
}

- (void)warpPointerWithScreen:(OGGdkScreen*)screen x:(gint)x y:(gint)y
{
	gdk_display_warp_pointer([self DISPLAY], [screen SCREEN], x, y);
}


@end