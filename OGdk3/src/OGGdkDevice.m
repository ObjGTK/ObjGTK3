/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkDevice.h"

#import "OGGdkCursor.h"
#import "OGGdkSeat.h"
#import "OGGdkDisplay.h"
#import "OGGdkScreen.h"
#import "OGGdkWindow.h"

@implementation OGGdkDevice

+ (void)freeHistoryWithEvents:(GdkTimeCoord**)events nevents:(gint)nevents
{
	gdk_device_free_history(events, nevents);
}

+ (bool)grabInfoLibgtkOnlyWithDisplay:(OGGdkDisplay*)display device:(OGGdkDevice*)device grabWindow:(GdkWindow**)grabWindow ownerEvents:(gboolean*)ownerEvents
{
	return gdk_device_grab_info_libgtk_only([display DISPLAY], [device DEVICE], grabWindow, ownerEvents);
}

- (GdkDevice*)DEVICE
{
	return GDK_DEVICE([self GOBJECT]);
}

- (OGGdkDevice*)associatedDevice
{
	return [[[OGGdkDevice alloc] initWithGObject:(GObject*)gdk_device_get_associated_device([self DEVICE])] autorelease];
}

- (GdkAxisFlags)axes
{
	return gdk_device_get_axes([self DEVICE]);
}

- (bool)axisWithAxes:(gdouble*)axes use:(GdkAxisUse)use value:(gdouble*)value
{
	return gdk_device_get_axis([self DEVICE], axes, use, value);
}

- (GdkAxisUse)axisUse:(guint)index
{
	return gdk_device_get_axis_use([self DEVICE], index);
}

- (bool)axisValueWithAxes:(gdouble*)axes axisLabel:(GdkAtom)axisLabel value:(gdouble*)value
{
	return gdk_device_get_axis_value([self DEVICE], axes, axisLabel, value);
}

- (GdkDeviceType)deviceType
{
	return gdk_device_get_device_type([self DEVICE]);
}

- (OGGdkDisplay*)display
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_device_get_display([self DEVICE])] autorelease];
}

- (bool)hasCursor
{
	return gdk_device_get_has_cursor([self DEVICE]);
}

- (bool)historyWithWindow:(OGGdkWindow*)window start:(guint32)start stop:(guint32)stop events:(GdkTimeCoord***)events nevents:(gint*)nevents
{
	return gdk_device_get_history([self DEVICE], [window WINDOW], start, stop, events, nevents);
}

- (bool)keyWithIndex:(guint)index keyval:(guint*)keyval modifiers:(GdkModifierType*)modifiers
{
	return gdk_device_get_key([self DEVICE], index, keyval, modifiers);
}

- (OGGdkWindow*)lastEventWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_device_get_last_event_window([self DEVICE])] autorelease];
}

- (GdkInputMode)mode
{
	return gdk_device_get_mode([self DEVICE]);
}

- (gint)naxes
{
	return gdk_device_get_n_axes([self DEVICE]);
}

- (gint)nkeys
{
	return gdk_device_get_n_keys([self DEVICE]);
}

- (OFString*)name
{
	return [OFString stringWithUTF8String:gdk_device_get_name([self DEVICE])];
}

- (void)positionWithScreen:(GdkScreen**)screen x:(gint*)x y:(gint*)y
{
	gdk_device_get_position([self DEVICE], screen, x, y);
}

- (void)positionDoubleWithScreen:(GdkScreen**)screen x:(gdouble*)x y:(gdouble*)y
{
	gdk_device_get_position_double([self DEVICE], screen, x, y);
}

- (OFString*)productId
{
	return [OFString stringWithUTF8String:gdk_device_get_product_id([self DEVICE])];
}

- (OGGdkSeat*)seat
{
	return [[[OGGdkSeat alloc] initWithGObject:(GObject*)gdk_device_get_seat([self DEVICE])] autorelease];
}

- (GdkInputSource)source
{
	return gdk_device_get_source([self DEVICE]);
}

- (void)stateWithWindow:(OGGdkWindow*)window axes:(gdouble*)axes mask:(GdkModifierType*)mask
{
	gdk_device_get_state([self DEVICE], [window WINDOW], axes, mask);
}

- (OFString*)vendorId
{
	return [OFString stringWithUTF8String:gdk_device_get_vendor_id([self DEVICE])];
}

- (OGGdkWindow*)windowAtPositionWithWinX:(gint*)winX winY:(gint*)winY
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_device_get_window_at_position([self DEVICE], winX, winY)] autorelease];
}

- (OGGdkWindow*)windowAtPositionDoubleWithWinX:(gdouble*)winX winY:(gdouble*)winY
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_device_get_window_at_position_double([self DEVICE], winX, winY)] autorelease];
}

- (GdkGrabStatus)grabWithWindow:(OGGdkWindow*)window grabOwnership:(GdkGrabOwnership)grabOwnership ownerEvents:(bool)ownerEvents eventMask:(GdkEventMask)eventMask cursor:(OGGdkCursor*)cursor time:(guint32)time
{
	return gdk_device_grab([self DEVICE], [window WINDOW], grabOwnership, ownerEvents, eventMask, [cursor CURSOR], time);
}

- (GList*)listAxes
{
	return gdk_device_list_axes([self DEVICE]);
}

- (GList*)listSlaveDevices
{
	return gdk_device_list_slave_devices([self DEVICE]);
}

- (void)setAxisUseWithIndex:(guint)index use:(GdkAxisUse)use
{
	gdk_device_set_axis_use([self DEVICE], index, use);
}

- (void)setKeyWithIndex:(guint)index keyval:(guint)keyval modifiers:(GdkModifierType)modifiers
{
	gdk_device_set_key([self DEVICE], index, keyval, modifiers);
}

- (bool)setMode:(GdkInputMode)mode
{
	return gdk_device_set_mode([self DEVICE], mode);
}

- (void)ungrab:(guint32)time
{
	gdk_device_ungrab([self DEVICE], time);
}

- (void)warpWithScreen:(OGGdkScreen*)screen x:(gint)x y:(gint)y
{
	gdk_device_warp([self DEVICE], [screen SCREEN], x, y);
}


@end