/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkDisplay;

/**
 * GdkMonitor objects represent the individual outputs that are
 * associated with a #GdkDisplay. GdkDisplay has APIs to enumerate
 * monitors with gdk_display_get_n_monitors() and gdk_display_get_monitor(), and
 * to find particular monitors with gdk_display_get_primary_monitor() or
 * gdk_display_get_monitor_at_window().
 * 
 * GdkMonitor was introduced in GTK+ 3.22 and supersedes earlier
 * APIs in GdkScreen to obtain monitor-related information.
 *
 */
@interface OGGdkMonitor : OGObject
{

}


/**
 * Methods
 */

- (GdkMonitor*)MONITOR;

/**
 * Gets the display that this monitor belongs to.
 *
 * @return the display
 */
- (OGGdkDisplay*)display;

/**
 * Retrieves the size and position of an individual monitor within the
 * display coordinate space. The returned geometry is in  ”application pixels”,
 * not in ”device pixels” (see gdk_monitor_get_scale_factor()).
 *
 * @param geometry a #GdkRectangle to be filled with the monitor geometry
 */
- (void)geometry:(GdkRectangle*)geometry;

/**
 * Gets the height in millimeters of the monitor.
 *
 * @return the physical height of the monitor
 */
- (int)heightMm;

/**
 * Gets the name or PNP ID of the monitor's manufacturer, if available.
 * 
 * Note that this value might also vary depending on actual
 * display backend.
 * 
 * PNP ID registry is located at https://uefi.org/pnp_id_list
 *
 * @return the name of the manufacturer, or %NULL
 */
- (OFString*)manufacturer;

/**
 * Gets the a string identifying the monitor model, if available.
 *
 * @return the monitor model, or %NULL
 */
- (OFString*)model;

/**
 * Gets the refresh rate of the monitor, if available.
 * 
 * The value is in milli-Hertz, so a refresh rate of 60Hz
 * is returned as 60000.
 *
 * @return the refresh rate in milli-Hertz, or 0
 */
- (int)refreshRate;

/**
 * Gets the internal scale factor that maps from monitor coordinates
 * to the actual device pixels. On traditional systems this is 1, but
 * on very high density outputs this can be a higher value (often 2).
 * 
 * This can be used if you want to create pixel based data for a
 * particular monitor, but most of the time you’re drawing to a window
 * where it is better to use gdk_window_get_scale_factor() instead.
 *
 * @return the scale factor
 */
- (int)scaleFactor;

/**
 * Gets information about the layout of red, green and blue
 * primaries for each pixel in this monitor, if available.
 *
 * @return the subpixel layout
 */
- (GdkSubpixelLayout)subpixelLayout;

/**
 * Gets the width in millimeters of the monitor.
 *
 * @return the physical width of the monitor
 */
- (int)widthMm;

/**
 * Retrieves the size and position of the “work area” on a monitor
 * within the display coordinate space. The returned geometry is in
 * ”application pixels”, not in ”device pixels” (see
 * gdk_monitor_get_scale_factor()).
 * 
 * The work area should be considered when positioning menus and
 * similar popups, to avoid placing them below panels, docks or other
 * desktop components.
 * 
 * Note that not all backends may have a concept of workarea. This
 * function will return the monitor geometry if a workarea is not
 * available, or does not apply.
 *
 * @param workarea a #GdkRectangle to be filled with
 *     the monitor workarea
 */
- (void)workarea:(GdkRectangle*)workarea;

/**
 * Gets whether this monitor should be considered primary
 * (see gdk_display_get_primary_monitor()).
 *
 * @return %TRUE if @monitor is primary
 */
- (bool)isPrimary;

@end