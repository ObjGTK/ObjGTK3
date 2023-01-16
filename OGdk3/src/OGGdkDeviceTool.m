/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkDeviceTool.h"

@implementation OGGdkDeviceTool

- (GdkDeviceTool*)DEVICETOOL
{
	return GDK_DEVICE_TOOL([self GOBJECT]);
}

- (guint64)hardwareId
{
	return gdk_device_tool_get_hardware_id([self DEVICETOOL]);
}

- (guint64)serial
{
	return gdk_device_tool_get_serial([self DEVICETOOL]);
}

- (GdkDeviceToolType)toolType
{
	return gdk_device_tool_get_tool_type([self DEVICETOOL]);
}


@end