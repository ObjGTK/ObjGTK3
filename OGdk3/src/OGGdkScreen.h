/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkDisplay;
@class OGGdkVisual;
@class OGGdkWindow;

/**
 * #GdkScreen objects are the GDK representation of the screen on
 * which windows can be displayed and on which the pointer moves.
 * X originally identified screens with physical screens, but
 * nowadays it is more common to have a single #GdkScreen which
 * combines several physical monitors (see gdk_screen_get_n_monitors()).
 * 
 * GdkScreen is used throughout GDK and GTK+ to specify which screen
 * the top level windows are to be displayed on. it is also used to
 * query the screen specification and default settings such as
 * the default visual (gdk_screen_get_system_visual()), the dimensions
 * of the physical monitors (gdk_screen_get_monitor_geometry()), etc.
 *
 */
@interface OGGdkScreen : OGObject
{

}

/**
 * Functions
 */

/**
 * Gets the default screen for the default display. (See
 * gdk_display_get_default ()).
 *
 * @return a #GdkScreen, or %NULL if
 *     there is no default display.
 */
+ (OGGdkScreen*)default;

/**
 * Use per-monitor information
 *
 * @return the height of the default screen in pixels.
 */
+ (gint)height;

/**
 * Returns the height of the default screen in millimeters.
 * Note that on many X servers this value will not be correct.
 *
 * @return the height of the default screen in millimeters,
 * though it is not always correct.
 */
+ (gint)heightMm;

/**
 * Use per-monitor information
 *
 * @return the width of the default screen in pixels.
 */
+ (gint)width;

/**
 * Returns the width of the default screen in millimeters.
 * Note that on many X servers this value will not be correct.
 *
 * @return the width of the default screen in millimeters,
 * though it is not always correct.
 */
+ (gint)widthMm;

/**
 * Methods
 */

- (GdkScreen*)SCREEN;

/**
 * Returns the screen’s currently active window.
 * 
 * On X11, this is done by inspecting the _NET_ACTIVE_WINDOW property
 * on the root window, as described in the
 * [Extended Window Manager Hints](http://www.freedesktop.org/Standards/wm-spec).
 * If there is no currently currently active
 * window, or the window manager does not support the
 * _NET_ACTIVE_WINDOW hint, this function returns %NULL.
 * 
 * On other platforms, this function may return %NULL, depending on whether
 * it is implementable on that platform.
 * 
 * The returned window should be unrefed using g_object_unref() when
 * no longer needed.
 *
 * @return the currently active window,
 *   or %NULL.
 */
- (OGGdkWindow*)activeWindow;

/**
 * Gets the display to which the @screen belongs.
 *
 * @return the display to which @screen belongs
 */
- (OGGdkDisplay*)display;

/**
 * Gets any options previously set with gdk_screen_set_font_options().
 *
 * @return the current font options, or %NULL if no
 *  default font options have been set.
 */
- (const cairo_font_options_t*)fontOptions;

/**
 * Gets the height of @screen in pixels. The returned size is in
 * ”application pixels”, not in ”device pixels” (see
 * gdk_screen_get_monitor_scale_factor()).
 *
 * @return the height of @screen in pixels.
 */
- (gint)height;

/**
 * Returns the height of @screen in millimeters.
 * 
 * Note that this value is somewhat ill-defined when the screen
 * has multiple monitors of different resolution. It is recommended
 * to use the monitor dimensions instead.
 *
 * @return the heigth of @screen in millimeters.
 */
- (gint)heightMm;

/**
 * Returns the monitor number in which the point (@x,@y) is located.
 *
 * @param x the x coordinate in the virtual screen.
 * @param y the y coordinate in the virtual screen.
 * @return the monitor number in which the point (@x,@y) lies, or
 *   a monitor close to (@x,@y) if the point is not in any monitor.
 */
- (gint)monitorAtPointWithX:(gint)x y:(gint)y;

/**
 * Returns the number of the monitor in which the largest area of the
 * bounding rectangle of @window resides.
 *
 * @param window a #GdkWindow
 * @return the monitor number in which most of @window is located,
 *     or if @window does not intersect any monitors, a monitor,
 *     close to @window.
 */
- (gint)monitorAtWindow:(OGGdkWindow*)window;

/**
 * Retrieves the #GdkRectangle representing the size and position of
 * the individual monitor within the entire screen area. The returned
 * geometry is in ”application pixels”, not in ”device pixels” (see
 * gdk_screen_get_monitor_scale_factor()).
 * 
 * Monitor numbers start at 0. To obtain the number of monitors of
 * @screen, use gdk_screen_get_n_monitors().
 * 
 * Note that the size of the entire screen area can be retrieved via
 * gdk_screen_get_width() and gdk_screen_get_height().
 *
 * @param monitorNum the monitor number
 * @param dest a #GdkRectangle to be filled with
 *     the monitor geometry
 */
- (void)monitorGeometryWithMonitorNum:(gint)monitorNum dest:(GdkRectangle*)dest;

/**
 * Gets the height in millimeters of the specified monitor.
 *
 * @param monitorNum number of the monitor, between 0 and gdk_screen_get_n_monitors (screen)
 * @return the height of the monitor, or -1 if not available
 */
- (gint)monitorHeightMm:(gint)monitorNum;

/**
 * Returns the output name of the specified monitor.
 * Usually something like VGA, DVI, or TV, not the actual
 * product name of the display device.
 *
 * @param monitorNum number of the monitor, between 0 and gdk_screen_get_n_monitors (screen)
 * @return a newly-allocated string containing the name
 *   of the monitor, or %NULL if the name cannot be determined
 */
- (OFString*)monitorPlugName:(gint)monitorNum;

/**
 * Returns the internal scale factor that maps from monitor coordinates
 * to the actual device pixels. On traditional systems this is 1, but
 * on very high density outputs this can be a higher value (often 2).
 * 
 * This can be used if you want to create pixel based data for a
 * particular monitor, but most of the time you’re drawing to a window
 * where it is better to use gdk_window_get_scale_factor() instead.
 *
 * @param monitorNum number of the monitor, between 0 and gdk_screen_get_n_monitors (screen)
 * @return the scale factor
 */
- (gint)monitorScaleFactor:(gint)monitorNum;

/**
 * Gets the width in millimeters of the specified monitor, if available.
 *
 * @param monitorNum number of the monitor, between 0 and gdk_screen_get_n_monitors (screen)
 * @return the width of the monitor, or -1 if not available
 */
- (gint)monitorWidthMm:(gint)monitorNum;

/**
 * Retrieves the #GdkRectangle representing the size and position of
 * the “work area” on a monitor within the entire screen area. The returned
 * geometry is in ”application pixels”, not in ”device pixels” (see
 * gdk_screen_get_monitor_scale_factor()).
 * 
 * The work area should be considered when positioning menus and
 * similar popups, to avoid placing them below panels, docks or other
 * desktop components.
 * 
 * Note that not all backends may have a concept of workarea. This
 * function will return the monitor geometry if a workarea is not
 * available, or does not apply.
 * 
 * Monitor numbers start at 0. To obtain the number of monitors of
 * @screen, use gdk_screen_get_n_monitors().
 *
 * @param monitorNum the monitor number
 * @param dest a #GdkRectangle to be filled with
 *     the monitor workarea
 */
- (void)monitorWorkareaWithMonitorNum:(gint)monitorNum dest:(GdkRectangle*)dest;

/**
 * Returns the number of monitors which @screen consists of.
 *
 * @return number of monitors which @screen consists of
 */
- (gint)nmonitors;

/**
 * Gets the index of @screen among the screens in the display
 * to which it belongs. (See gdk_screen_get_display())
 *
 * @return the index
 */
- (gint)number;

/**
 * Gets the primary monitor for @screen.  The primary monitor
 * is considered the monitor where the “main desktop” lives.
 * While normal application windows typically allow the window
 * manager to place the windows, specialized desktop applications
 * such as panels should place themselves on the primary monitor.
 * 
 * If no primary monitor is configured by the user, the return value
 * will be 0, defaulting to the first monitor.
 *
 * @return An integer index for the primary monitor, or 0 if none is configured.
 */
- (gint)primaryMonitor;

/**
 * Gets the resolution for font handling on the screen; see
 * gdk_screen_set_resolution() for full details.
 *
 * @return the current resolution, or -1 if no resolution
 * has been set.
 */
- (gdouble)resolution;

/**
 * Gets a visual to use for creating windows with an alpha channel.
 * The windowing system on which GTK+ is running
 * may not support this capability, in which case %NULL will
 * be returned. Even if a non-%NULL value is returned, its
 * possible that the window’s alpha channel won’t be honored
 * when displaying the window on the screen: in particular, for
 * X an appropriate windowing manager and compositing manager
 * must be running to provide appropriate display.
 * 
 * This functionality is not implemented in the Windows backend.
 * 
 * For setting an overall opacity for a top-level window, see
 * gdk_window_set_opacity().
 *
 * @return a visual to use for windows
 *     with an alpha channel or %NULL if the capability is not
 *     available.
 */
- (OGGdkVisual*)rgbaVisual;

/**
 * Gets the root window of @screen.
 *
 * @return the root window
 */
- (OGGdkWindow*)rootWindow;

/**
 * Retrieves a desktop-wide setting such as double-click time
 * for the #GdkScreen @screen.
 * 
 * FIXME needs a list of valid settings here, or a link to
 * more information.
 *
 * @param name the name of the setting
 * @param value location to store the value of the setting
 * @return %TRUE if the setting existed and a value was stored
 *   in @value, %FALSE otherwise.
 */
- (bool)settingWithName:(OFString*)name value:(GValue*)value;

/**
 * Get the system’s default visual for @screen.
 * This is the visual for the root window of the display.
 * The return value should not be freed.
 *
 * @return the system visual
 */
- (OGGdkVisual*)systemVisual;

/**
 * Obtains a list of all toplevel windows known to GDK on the screen @screen.
 * A toplevel window is a child of the root window (see
 * gdk_get_default_root_window()).
 * 
 * The returned list should be freed with g_list_free(), but
 * its elements need not be freed.
 *
 * @return list of toplevel windows, free with g_list_free()
 */
- (GList*)toplevelWindows;

/**
 * Gets the width of @screen in pixels. The returned size is in
 * ”application pixels”, not in ”device pixels” (see
 * gdk_screen_get_monitor_scale_factor()).
 *
 * @return the width of @screen in pixels.
 */
- (gint)width;

/**
 * Gets the width of @screen in millimeters.
 * 
 * Note that this value is somewhat ill-defined when the screen
 * has multiple monitors of different resolution. It is recommended
 * to use the monitor dimensions instead.
 *
 * @return the width of @screen in millimeters.
 */
- (gint)widthMm;

/**
 * Returns a #GList of #GdkWindows representing the current
 * window stack.
 * 
 * On X11, this is done by inspecting the _NET_CLIENT_LIST_STACKING
 * property on the root window, as described in the
 * [Extended Window Manager Hints](http://www.freedesktop.org/Standards/wm-spec).
 * If the window manager does not support the
 * _NET_CLIENT_LIST_STACKING hint, this function returns %NULL.
 * 
 * On other platforms, this function may return %NULL, depending on whether
 * it is implementable on that platform.
 * 
 * The returned list is newly allocated and owns references to the
 * windows it contains, so it should be freed using g_list_free() and
 * its windows unrefed using g_object_unref() when no longer needed.
 *
 * @return a
 *     list of #GdkWindows for the current window stack, or %NULL.
 */
- (GList*)windowStack;

/**
 * Returns whether windows with an RGBA visual can reasonably
 * be expected to have their alpha channel drawn correctly on
 * the screen.
 * 
 * On X11 this function returns whether a compositing manager is
 * compositing @screen.
 *
 * @return Whether windows with RGBA visuals can reasonably be
 * expected to have their alpha channels drawn correctly on the screen.
 */
- (bool)isComposited;

/**
 * Lists the available visuals for the specified @screen.
 * A visual describes a hardware image data format.
 * For example, a visual might support 24-bit color, or 8-bit color,
 * and might expect pixels to be in a certain format.
 * 
 * Call g_list_free() on the return value when you’re finished with it.
 *
 * @return a list of visuals; the list must be freed, but not its contents
 */
- (GList*)listVisuals;

/**
 * Determines the name to pass to gdk_display_open() to get
 * a #GdkDisplay with this screen as the default screen.
 *
 * @return a newly allocated string, free with g_free()
 */
- (OFString*)makeDisplayName;

/**
 * Sets the default font options for the screen. These
 * options will be set on any #PangoContext’s newly created
 * with gdk_pango_context_get_for_screen(). Changing the
 * default set of font options does not affect contexts that
 * have already been created.
 *
 * @param options a #cairo_font_options_t, or %NULL to unset any
 *   previously set default font options.
 */
- (void)setFontOptions:(const cairo_font_options_t*)options;

/**
 * Sets the resolution for font handling on the screen. This is a
 * scale factor between points specified in a #PangoFontDescription
 * and cairo units. The default value is 96, meaning that a 10 point
 * font will be 13 units high. (10 * 96. / 72. = 13.3).
 *
 * @param dpi the resolution in “dots per inch”. (Physical inches aren’t actually
 *   involved; the terminology is conventional.)
 */
- (void)setResolution:(gdouble)dpi;

@end