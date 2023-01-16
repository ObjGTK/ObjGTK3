/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureSingle.h"

@class OGGdkDeviceTool;
@class OGTKWidget;
@class OGTKGesture;

/**
 * #GtkGestureStylus is a #GtkGesture implementation specific to stylus
 * input. The provided signals just provide the basic information
 *
 */
@interface OGTKGestureStylus : OGTKGestureSingle
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKWidget*)widget;

/**
 * Methods
 */

- (GtkGestureStylus*)GESTURESTYLUS;

/**
 * Returns the current values for the requested @axes. This function
 * must be called from either the #GtkGestureStylus:down,
 * #GtkGestureStylus:motion, #GtkGestureStylus:up or #GtkGestureStylus:proximity
 * signals.
 *
 * @param axes array of requested axes, terminated with #GDK_AXIS_IGNORE
 * @param values return location for the axis values
 * @return #TRUE if there is a current value for the axes
 */
- (bool)axesWithAxes:(GdkAxisUse*)axes values:(gdouble**)values;

/**
 * Returns the current value for the requested @axis. This function
 * must be called from either the #GtkGestureStylus:down,
 * #GtkGestureStylus:motion, #GtkGestureStylus:up or #GtkGestureStylus:proximity
 * signals.
 *
 * @param axis requested device axis
 * @param value return location for the axis value
 * @return #TRUE if there is a current value for the axis
 */
- (bool)axisWithAxis:(GdkAxisUse)axis value:(gdouble*)value;

/**
 * Returns the #GdkDeviceTool currently driving input through this gesture.
 * This function must be called from either the #GtkGestureStylus::down,
 * #GtkGestureStylus::motion, #GtkGestureStylus::up or #GtkGestureStylus::proximity
 * signal handlers.
 *
 * @return The current stylus tool
 */
- (OGGdkDeviceTool*)deviceTool;

@end