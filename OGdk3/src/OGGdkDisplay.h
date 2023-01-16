/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkSeat;
@class OGGdkDevice;
@class OGGdkWindow;
@class OGGdkScreen;
@class OGGdkDeviceManager;
@class OGGdkAppLaunchContext;
@class OGGdkMonitor;

/**
 * #GdkDisplay objects purpose are two fold:
 * 
 * - To manage and provide information about input devices (pointers and keyboards)
 * 
 * - To manage and provide information about the available #GdkScreens
 * 
 * GdkDisplay objects are the GDK representation of an X Display,
 * which can be described as a workstation consisting of
 * a keyboard, a pointing device (such as a mouse) and one or more
 * screens.
 * It is used to open and keep track of various GdkScreen objects
 * currently instantiated by the application. It is also used to
 * access the keyboard(s) and mouse pointer(s) of the display.
 * 
 * Most of the input device handling has been factored out into
 * the separate #GdkDeviceManager object. Every display has a
 * device manager, which you can obtain using
 * gdk_display_get_device_manager().
 *
 */
@interface OGGdkDisplay : OGObject
{

}

/**
 * Functions
 */

/**
 * Gets the default #GdkDisplay. This is a convenience
 * function for:
 * `gdk_display_manager_get_default_display (gdk_display_manager_get ())`.
 *
 * @return a #GdkDisplay, or %NULL if
 *   there is no default display.
 */
+ (OGGdkDisplay*)default;

/**
 * Opens a display.
 *
 * @param displayName the name of the display to open
 * @return a #GdkDisplay, or %NULL if the
 *     display could not be opened
 */
+ (OGGdkDisplay*)open:(OFString*)displayName;

/**
 * This symbol was never meant to be used outside
 *   of GTK+
 *
 * @return the default display, if it
 *   could be opened, otherwise %NULL.
 */
+ (OGGdkDisplay*)openDefaultLibgtkOnly;

/**
 * Methods
 */

- (GdkDisplay*)DISPLAY;

/**
 * Emits a short beep on @display
 *
 */
- (void)beep;

/**
 * Closes the connection to the windowing system for the given display,
 * and cleans up associated resources.
 *
 */
- (void)close;

/**
 * Returns %TRUE if there is an ongoing grab on @device for @display.
 *
 * @param device a #GdkDevice
 * @return %TRUE if there is a grab in effect for @device.
 */
- (bool)deviceIsGrabbed:(OGGdkDevice*)device;

/**
 * Flushes any requests queued for the windowing system; this happens automatically
 * when the main loop blocks waiting for new events, but if your application
 * is drawing without returning control to the main loop, you may need
 * to call this function explicitly. A common case where this function
 * needs to be called is when an application is executing drawing commands
 * from a thread other than the thread where the main loop is running.
 * 
 * This is most useful for X11. On windowing systems where requests are
 * handled synchronously, this function will do nothing.
 *
 */
- (void)flush;

/**
 * Returns a #GdkAppLaunchContext suitable for launching
 * applications on the given display.
 *
 * @return a new #GdkAppLaunchContext for @display.
 *     Free with g_object_unref() when done
 */
- (OGGdkAppLaunchContext*)appLaunchContext;

/**
 * Returns the default size to use for cursors on @display.
 *
 * @return the default cursor size.
 */
- (guint)defaultCursorSize;

/**
 * Returns the default group leader window for all toplevel windows
 * on @display. This window is implicitly created by GDK.
 * See gdk_window_set_group().
 *
 * @return The default group leader window
 * for @display
 */
- (OGGdkWindow*)defaultGroup;

/**
 * Get the default #GdkScreen for @display.
 *
 * @return the default #GdkScreen object for @display
 */
- (OGGdkScreen*)defaultScreen;

/**
 * Returns the default #GdkSeat for this display.
 *
 * @return the default seat.
 */
- (OGGdkSeat*)defaultSeat;

/**
 * Returns the #GdkDeviceManager associated to @display.
 *
 * @return A #GdkDeviceManager, or
 *          %NULL. This memory is owned by GDK and must not be freed
 *          or unreferenced.
 */
- (OGGdkDeviceManager*)deviceManager;

/**
 * Gets the next #GdkEvent to be processed for @display, fetching events from the
 * windowing system if necessary.
 *
 * @return the next #GdkEvent to be processed, or %NULL
 * if no events are pending. The returned #GdkEvent should be freed
 * with gdk_event_free().
 */
- (GdkEvent*)event;

/**
 * Gets the maximal size to use for cursors on @display.
 *
 * @param width the return location for the maximal cursor width
 * @param height the return location for the maximal cursor height
 */
- (void)maximalCursorSizeWithWidth:(guint*)width height:(guint*)height;

/**
 * Gets a monitor associated with this display.
 *
 * @param monitorNum number of the monitor
 * @return the #GdkMonitor, or %NULL if
 *    @monitor_num is not a valid monitor number
 */
- (OGGdkMonitor*)monitor:(int)monitorNum;

/**
 * Gets the monitor in which the point (@x, @y) is located,
 * or a nearby monitor if the point is not in any monitor.
 *
 * @param x the x coordinate of the point
 * @param y the y coordinate of the point
 * @return the monitor containing the point
 */
- (OGGdkMonitor*)monitorAtPointWithX:(int)x y:(int)y;

/**
 * Gets the monitor in which the largest area of @window
 * resides, or a monitor close to @window if it is outside
 * of all monitors.
 *
 * @param window a #GdkWindow
 * @return the monitor with the largest overlap with @window
 */
- (OGGdkMonitor*)monitorAtWindow:(OGGdkWindow*)window;

/**
 * Gets the number of monitors that belong to @display.
 * 
 * The returned number is valid until the next emission of the
 * #GdkDisplay::monitor-added or #GdkDisplay::monitor-removed signal.
 *
 * @return the number of monitors
 */
- (int)nmonitors;

/**
 * Gets the number of screen managed by the @display.
 *
 * @return number of screens.
 */
- (gint)nscreens;

/**
 * Gets the name of the display.
 *
 * @return a string representing the display name. This string is owned
 * by GDK and should not be modified or freed.
 */
- (OFString*)name;

/**
 * Gets the current location of the pointer and the current modifier
 * mask for a given display.
 *
 * @param screen location to store the screen that the
 *          cursor is on, or %NULL.
 * @param x location to store root window X coordinate of pointer, or %NULL.
 * @param y location to store root window Y coordinate of pointer, or %NULL.
 * @param mask location to store current modifier mask, or %NULL
 */
- (void)pointerWithScreen:(GdkScreen**)screen x:(gint*)x y:(gint*)y mask:(GdkModifierType*)mask;

/**
 * Gets the primary monitor for the display.
 * 
 * The primary monitor is considered the monitor where the “main desktop”
 * lives. While normal application windows typically allow the window
 * manager to place the windows, specialized desktop applications
 * such as panels should place themselves on the primary monitor.
 *
 * @return the primary monitor, or %NULL if no primary
 *     monitor is configured by the user
 */
- (OGGdkMonitor*)primaryMonitor;

/**
 * Returns a screen object for one of the screens of the display.
 *
 * @param screenNum the screen number
 * @return the #GdkScreen object
 */
- (OGGdkScreen*)screen:(gint)screenNum;

/**
 * Obtains the window underneath the mouse pointer, returning the location
 * of the pointer in that window in @win_x, @win_y for @screen. Returns %NULL
 * if the window under the mouse pointer is not known to GDK (for example,
 * belongs to another application).
 *
 * @param winX return location for x coordinate of the pointer location relative
 *    to the window origin, or %NULL
 * @param winY return location for y coordinate of the pointer location relative
 *  &    to the window origin, or %NULL
 * @return the window under the mouse
 *   pointer, or %NULL
 */
- (OGGdkWindow*)windowAtPointerWithWinX:(gint*)winX winY:(gint*)winY;

/**
 * Returns whether the display has events that are waiting
 * to be processed.
 *
 * @return %TRUE if there are events ready to be processed.
 */
- (bool)hasPending;

/**
 * Finds out if the display has been closed.
 *
 * @return %TRUE if the display is closed.
 */
- (bool)isClosed;

/**
 * Release any keyboard grab
 *
 * @param time a timestap (e.g #GDK_CURRENT_TIME).
 */
- (void)keyboardUngrab:(guint32)time;

/**
 * Returns the list of available input devices attached to @display.
 * The list is statically allocated and should not be freed.
 *
 * @return a list of #GdkDevice
 */
- (GList*)listDevices;

/**
 * Returns the list of seats known to @display.
 *
 * @return the
 *          list of seats known to the #GdkDisplay
 */
- (GList*)listSeats;

/**
 * Indicates to the GUI environment that the application has
 * finished loading, using a given identifier.
 * 
 * GTK+ will call this function automatically for #GtkWindow
 * with custom startup-notification identifier unless
 * gtk_window_set_auto_startup_notification() is called to
 * disable that feature.
 *
 * @param startupId a startup-notification identifier, for which
 *     notification process should be completed
 */
- (void)notifyStartupComplete:(OFString*)startupId;

/**
 * Gets a copy of the first #GdkEvent in the @display’s event queue, without
 * removing the event from the queue.  (Note that this function will
 * not get more events from the windowing system.  It only checks the events
 * that have already been moved to the GDK event queue.)
 *
 * @return a copy of the first #GdkEvent on the event
 * queue, or %NULL if no events are in the queue. The returned
 * #GdkEvent should be freed with gdk_event_free().
 */
- (GdkEvent*)peekEvent;

/**
 * Test if the pointer is grabbed.
 *
 * @return %TRUE if an active X pointer grab is in effect
 */
- (bool)pointerIsGrabbed;

/**
 * Release any pointer grab.
 *
 * @param time a timestap (e.g. %GDK_CURRENT_TIME).
 */
- (void)pointerUngrab:(guint32)time;

/**
 * Appends a copy of the given event onto the front of the event
 * queue for @display.
 *
 * @param event a #GdkEvent.
 */
- (void)putEvent:(const GdkEvent*)event;

/**
 * Request #GdkEventOwnerChange events for ownership changes
 * of the selection named by the given atom.
 *
 * @param selection the #GdkAtom naming the selection for which
 *             ownership change notification is requested
 * @return whether #GdkEventOwnerChange events will
 *               be sent.
 */
- (bool)requestSelectionNotification:(GdkAtom)selection;

/**
 * Sets the double click distance (two clicks within this distance
 * count as a double click and result in a #GDK_2BUTTON_PRESS event).
 * See also gdk_display_set_double_click_time().
 * Applications should not set this, it is a global
 * user-configured setting.
 *
 * @param distance distance in pixels
 */
- (void)setDoubleClickDistance:(guint)distance;

/**
 * Sets the double click time (two clicks within this time interval
 * count as a double click and result in a #GDK_2BUTTON_PRESS event).
 * Applications should not set this, it is a global
 * user-configured setting.
 *
 * @param msec double click time in milliseconds (thousandths of a second)
 */
- (void)setDoubleClickTime:(guint)msec;

/**
 * Issues a request to the clipboard manager to store the
 * clipboard data. On X11, this is a special program that works
 * according to the
 * [FreeDesktop Clipboard Specification](http://www.freedesktop.org/Standards/clipboard-manager-spec).
 *
 * @param clipboardWindow a #GdkWindow belonging to the clipboard owner
 * @param time a timestamp
 * @param targets an array of targets
 *                    that should be saved, or %NULL
 *                    if all available targets should be saved.
 * @param ntargets length of the @targets array
 */
- (void)storeClipboardWithClipboardWindow:(OGGdkWindow*)clipboardWindow time:(guint32)time targets:(const GdkAtom*)targets ntargets:(gint)ntargets;

/**
 * Returns whether the speicifed display supports clipboard
 * persistance; i.e. if it’s possible to store the clipboard data after an
 * application has quit. On X11 this checks if a clipboard daemon is
 * running.
 *
 * @return %TRUE if the display supports clipboard persistance.
 */
- (bool)supportsClipboardPersistence;

/**
 * Returns %TRUE if gdk_window_set_composited() can be used
 * to redirect drawing on the window using compositing.
 * 
 * Currently this only works on X11 with XComposite and
 * XDamage extensions available.
 *
 * @return %TRUE if windows may be composited.
 */
- (bool)supportsComposite;

/**
 * Returns %TRUE if cursors can use an 8bit alpha channel
 * on @display. Otherwise, cursors are restricted to bilevel
 * alpha (i.e. a mask).
 *
 * @return whether cursors can have alpha channels.
 */
- (bool)supportsCursorAlpha;

/**
 * Returns %TRUE if multicolored cursors are supported
 * on @display. Otherwise, cursors have only a forground
 * and a background color.
 *
 * @return whether cursors can have multiple colors.
 */
- (bool)supportsCursorColor;

/**
 * Returns %TRUE if gdk_window_input_shape_combine_mask() can
 * be used to modify the input shape of windows on @display.
 *
 * @return %TRUE if windows with modified input shape are supported
 */
- (bool)supportsInputShapes;

/**
 * Returns whether #GdkEventOwnerChange events will be
 * sent when the owner of a selection changes.
 *
 * @return whether #GdkEventOwnerChange events will
 *               be sent.
 */
- (bool)supportsSelectionNotification;

/**
 * Returns %TRUE if gdk_window_shape_combine_mask() can
 * be used to create shaped windows on @display.
 *
 * @return %TRUE if shaped windows are supported
 */
- (bool)supportsShapes;

/**
 * Flushes any requests queued for the windowing system and waits until all
 * requests have been handled. This is often used for making sure that the
 * display is synchronized with the current state of the program. Calling
 * gdk_display_sync() before gdk_error_trap_pop() makes sure that any errors
 * generated from earlier requests are handled before the error trap is
 * removed.
 * 
 * This is most useful for X11. On windowing systems where requests are
 * handled synchronously, this function will do nothing.
 *
 */
- (void)sync;

/**
 * Warps the pointer of @display to the point @x,@y on
 * the screen @screen, unless the pointer is confined
 * to a window by a grab, in which case it will be moved
 * as far as allowed by the grab. Warping the pointer
 * creates events as if the user had moved the mouse
 * instantaneously to the destination.
 * 
 * Note that the pointer should normally be under the
 * control of the user. This function was added to cover
 * some rare use cases like keyboard navigation support
 * for the color picker in the #GtkColorSelectionDialog.
 *
 * @param screen the screen of @display to warp the pointer to
 * @param x the x coordinate of the destination
 * @param y the y coordinate of the destination
 */
- (void)warpPointerWithScreen:(OGGdkScreen*)screen x:(gint)x y:(gint)y;

@end