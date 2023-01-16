/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkSeat.h"

#import "OGGdkDisplay.h"
#import "OGGdkDevice.h"
#import "OGGdkCursor.h"
#import "OGGdkWindow.h"

@implementation OGGdkSeat

- (GdkSeat*)SEAT
{
	return GDK_SEAT([self GOBJECT]);
}

- (GdkSeatCapabilities)capabilities
{
	return gdk_seat_get_capabilities([self SEAT]);
}

- (OGGdkDisplay*)display
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_seat_get_display([self SEAT])] autorelease];
}

- (OGGdkDevice*)keyboard
{
	return [[[OGGdkDevice alloc] initWithGObject:(GObject*)gdk_seat_get_keyboard([self SEAT])] autorelease];
}

- (OGGdkDevice*)pointer
{
	return [[[OGGdkDevice alloc] initWithGObject:(GObject*)gdk_seat_get_pointer([self SEAT])] autorelease];
}

- (GList*)slaves:(GdkSeatCapabilities)capabilities
{
	return gdk_seat_get_slaves([self SEAT], capabilities);
}

- (GdkGrabStatus)grabWithWindow:(OGGdkWindow*)window capabilities:(GdkSeatCapabilities)capabilities ownerEvents:(bool)ownerEvents cursor:(OGGdkCursor*)cursor event:(const GdkEvent*)event prepareFunc:(GdkSeatGrabPrepareFunc)prepareFunc prepareFuncData:(gpointer)prepareFuncData
{
	return gdk_seat_grab([self SEAT], [window WINDOW], capabilities, ownerEvents, [cursor CURSOR], event, prepareFunc, prepareFuncData);
}

- (void)ungrab
{
	gdk_seat_ungrab([self SEAT]);
}


@end