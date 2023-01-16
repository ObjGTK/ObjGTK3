/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkDeviceManager.h"

#import "OGGdkDisplay.h"
#import "OGGdkDevice.h"

@implementation OGGdkDeviceManager

- (GdkDeviceManager*)DEVICEMANAGER
{
	return GDK_DEVICE_MANAGER([self GOBJECT]);
}

- (OGGdkDevice*)clientPointer
{
	return [[[OGGdkDevice alloc] initWithGObject:(GObject*)gdk_device_manager_get_client_pointer([self DEVICEMANAGER])] autorelease];
}

- (OGGdkDisplay*)display
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_device_manager_get_display([self DEVICEMANAGER])] autorelease];
}

- (GList*)listDevices:(GdkDeviceType)type
{
	return gdk_device_manager_list_devices([self DEVICEMANAGER], type);
}


@end