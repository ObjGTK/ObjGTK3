/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@interface OGGdkDeviceTool : OGObject
{

}


/**
 * Methods
 */

- (GdkDeviceTool*)DEVICETOOL;

/**
 * Gets the hardware ID of this tool, or 0 if it's not known. When
 * non-zero, the identificator is unique for the given tool model,
 * meaning that two identical tools will share the same @hardware_id,
 * but will have different serial numbers (see gdk_device_tool_get_serial()).
 * 
 * This is a more concrete (and device specific) method to identify
 * a #GdkDeviceTool than gdk_device_tool_get_tool_type(), as a tablet
 * may support multiple devices with the same #GdkDeviceToolType,
 * but having different hardware identificators.
 *
 * @return The hardware identificator of this tool.
 */
- (guint64)hardwareId;

/**
 * Gets the serial of this tool, this value can be used to identify a
 * physical tool (eg. a tablet pen) across program executions.
 *
 * @return The serial ID for this tool
 */
- (guint64)serial;

/**
 * Gets the #GdkDeviceToolType of the tool.
 *
 * @return The physical type for this tool. This can be used to figure out what
 * sort of pen is being used, such as an airbrush or a pencil.
 */
- (GdkDeviceToolType)toolType;

@end