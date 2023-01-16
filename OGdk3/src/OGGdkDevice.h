/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkWindow;
@class OGGdkCursor;
@class OGGdkScreen;
@class OGGdkDisplay;
@class OGGdkSeat;

/**
 * The #GdkDevice object represents a single input device, such
 * as a keyboard, a mouse, a touchpad, etc.
 * 
 * See the #GdkDeviceManager documentation for more information
 * about the various kinds of master and slave devices, and their
 * relationships.
 *
 */
@interface OGGdkDevice : OGObject
{

}

/**
 * Functions
 */

/**
 * Frees an array of #GdkTimeCoord that was returned by gdk_device_get_history().
 *
 * @param events an array of #GdkTimeCoord.
 * @param nevents the length of the array.
 */
+ (void)freeHistoryWithEvents:(GdkTimeCoord**)events nevents:(gint)nevents;

/**
 * The symbol was never meant to be used outside
 *   of GTK+
 *
 * @param display the display for which to get the grab information
 * @param device device to get the grab information from
 * @param grabWindow location to store current grab window
 * @param ownerEvents location to store boolean indicating whether
 *   the @owner_events flag to gdk_keyboard_grab() or
 *   gdk_pointer_grab() was %TRUE.
 * @return %TRUE if this application currently has the
 *  keyboard grabbed.
 */
+ (bool)grabInfoLibgtkOnlyWithDisplay:(OGGdkDisplay*)display device:(OGGdkDevice*)device grabWindow:(GdkWindow**)grabWindow ownerEvents:(gboolean*)ownerEvents;

/**
 * Methods
 */

- (GdkDevice*)DEVICE;

/**
 * Returns the associated device to @device, if @device is of type
 * %GDK_DEVICE_TYPE_MASTER, it will return the paired pointer or
 * keyboard.
 * 
 * If @device is of type %GDK_DEVICE_TYPE_SLAVE, it will return
 * the master device to which @device is attached to.
 * 
 * If @device is of type %GDK_DEVICE_TYPE_FLOATING, %NULL will be
 * returned, as there is no associated device.
 *
 * @return The associated device, or
 *   %NULL
 */
- (OGGdkDevice*)associatedDevice;

/**
 * Returns the axes currently available on the device.
 *
 * @return
 */
- (GdkAxisFlags)axes;

/**
 * Interprets an array of double as axis values for a given device,
 * and locates the value in the array for a given axis use.
 *
 * @param axes pointer to an array of axes
 * @param use the use to look for
 * @param value location to store the found value.
 * @return %TRUE if the given axis use was found, otherwise %FALSE
 */
- (bool)axisWithAxes:(gdouble*)axes use:(GdkAxisUse)use value:(gdouble*)value;

/**
 * Returns the axis use for @index_.
 *
 * @param index the index of the axis.
 * @return a #GdkAxisUse specifying how the axis is used.
 */
- (GdkAxisUse)axisUse:(guint)index;

/**
 * Interprets an array of double as axis values for a given device,
 * and locates the value in the array for a given axis label, as returned
 * by gdk_device_list_axes()
 *
 * @param axes pointer to an array of axes
 * @param axisLabel #GdkAtom with the axis label.
 * @param value location to store the found value.
 * @return %TRUE if the given axis use was found, otherwise %FALSE.
 */
- (bool)axisValueWithAxes:(gdouble*)axes axisLabel:(GdkAtom)axisLabel value:(gdouble*)value;

/**
 * Returns the device type for @device.
 *
 * @return the #GdkDeviceType for @device.
 */
- (GdkDeviceType)deviceType;

/**
 * Returns the #GdkDisplay to which @device pertains.
 *
 * @return a #GdkDisplay. This memory is owned
 *          by GTK+, and must not be freed or unreffed.
 */
- (OGGdkDisplay*)display;

/**
 * Determines whether the pointer follows device motion.
 * This is not meaningful for keyboard devices, which don't have a pointer.
 *
 * @return %TRUE if the pointer follows device motion
 */
- (bool)hasCursor;

/**
 * Obtains the motion history for a pointer device; given a starting and
 * ending timestamp, return all events in the motion history for
 * the device in the given range of time. Some windowing systems
 * do not support motion history, in which case, %FALSE will
 * be returned. (This is not distinguishable from the case where
 * motion history is supported and no events were found.)
 * 
 * Note that there is also gdk_window_set_event_compression() to get
 * more motion events delivered directly, independent of the windowing
 * system.
 *
 * @param window the window with respect to which which the event coordinates will be reported
 * @param start starting timestamp for range of events to return
 * @param stop ending timestamp for the range of events to return
 * @param events location to store a newly-allocated array of #GdkTimeCoord, or
 *   %NULL
 * @param nevents location to store the length of
 *   @events, or %NULL
 * @return %TRUE if the windowing system supports motion history and
 *  at least one event was found.
 */
- (bool)historyWithWindow:(OGGdkWindow*)window start:(guint32)start stop:(guint32)stop events:(GdkTimeCoord***)events nevents:(gint*)nevents;

/**
 * If @index_ has a valid keyval, this function will return %TRUE
 * and fill in @keyval and @modifiers with the keyval settings.
 *
 * @param index the index of the macro button to get.
 * @param keyval return value for the keyval.
 * @param modifiers return value for modifiers.
 * @return %TRUE if keyval is set for @index.
 */
- (bool)keyWithIndex:(guint)index keyval:(guint*)keyval modifiers:(GdkModifierType*)modifiers;

/**
 * Gets information about which window the given pointer device is in, based on events
 * that have been received so far from the display server. If another application
 * has a pointer grab, or this application has a grab with owner_events = %FALSE,
 * %NULL may be returned even if the pointer is physically over one of this
 * application's windows.
 *
 * @return the last window the device
 */
- (OGGdkWindow*)lastEventWindow;

/**
 * Determines the mode of the device.
 *
 * @return a #GdkInputSource
 */
- (GdkInputMode)mode;

/**
 * Returns the number of axes the device currently has.
 *
 * @return the number of axes.
 */
- (gint)naxes;

/**
 * Returns the number of keys the device currently has.
 *
 * @return the number of keys.
 */
- (gint)nkeys;

/**
 * Determines the name of the device.
 *
 * @return a name
 */
- (OFString*)name;

/**
 * Gets the current location of @device. As a slave device
 * coordinates are those of its master pointer, This function
 * may not be called on devices of type %GDK_DEVICE_TYPE_SLAVE,
 * unless there is an ongoing grab on them, see gdk_device_grab().
 *
 * @param screen location to store the #GdkScreen
 *          the @device is on, or %NULL.
 * @param x location to store root window X coordinate of @device, or %NULL.
 * @param y location to store root window Y coordinate of @device, or %NULL.
 */
- (void)positionWithScreen:(GdkScreen**)screen x:(gint*)x y:(gint*)y;

/**
 * Gets the current location of @device in double precision. As a slave device's
 * coordinates are those of its master pointer, this function
 * may not be called on devices of type %GDK_DEVICE_TYPE_SLAVE,
 * unless there is an ongoing grab on them. See gdk_device_grab().
 *
 * @param screen location to store the #GdkScreen
 *          the @device is on, or %NULL.
 * @param x location to store root window X coordinate of @device, or %NULL.
 * @param y location to store root window Y coordinate of @device, or %NULL.
 */
- (void)positionDoubleWithScreen:(GdkScreen**)screen x:(gdouble*)x y:(gdouble*)y;

/**
 * Returns the product ID of this device, or %NULL if this information couldn't
 * be obtained. This ID is retrieved from the device, and is thus constant for
 * it. See gdk_device_get_vendor_id() for more information.
 *
 * @return the product ID, or %NULL
 */
- (OFString*)productId;

/**
 * Returns the #GdkSeat the device belongs to.
 *
 * @return A #GdkSeat. This memory is owned by GTK+ and
 *          must not be freed.
 */
- (OGGdkSeat*)seat;

/**
 * Determines the type of the device.
 *
 * @return a #GdkInputSource
 */
- (GdkInputSource)source;

/**
 * Gets the current state of a pointer device relative to @window. As a slave
 * device’s coordinates are those of its master pointer, this
 * function may not be called on devices of type %GDK_DEVICE_TYPE_SLAVE,
 * unless there is an ongoing grab on them. See gdk_device_grab().
 *
 * @param window a #GdkWindow.
 * @param axes an array of doubles to store the values of
 * the axes of @device in, or %NULL.
 * @param mask location to store the modifiers, or %NULL.
 */
- (void)stateWithWindow:(OGGdkWindow*)window axes:(gdouble*)axes mask:(GdkModifierType*)mask;

/**
 * Returns the vendor ID of this device, or %NULL if this information couldn't
 * be obtained. This ID is retrieved from the device, and is thus constant for
 * it.
 * 
 * This function, together with gdk_device_get_product_id(), can be used to eg.
 * compose #GSettings paths to store settings for this device.
 * 
 * |[<!-- language="C" -->
 *  static GSettings *
 *  get_device_settings (GdkDevice *device)
 *  {
 *    const gchar *vendor, *product;
 *    GSettings *settings;
 *    GdkDevice *device;
 *    gchar *path;
 * 
 *    vendor = gdk_device_get_vendor_id (device);
 *    product = gdk_device_get_product_id (device);
 * 
 *    path = g_strdup_printf ("/org/example/app/devices/%s:%s/", vendor, product);
 *    settings = g_settings_new_with_path (DEVICE_SCHEMA, path);
 *    g_free (path);
 * 
 *    return settings;
 *  }
 * ]|
 *
 * @return the vendor ID, or %NULL
 */
- (OFString*)vendorId;

/**
 * Obtains the window underneath @device, returning the location of the device in @win_x and @win_y. Returns
 * %NULL if the window tree under @device is not known to GDK (for example, belongs to another application).
 * 
 * As a slave device coordinates are those of its master pointer, This
 * function may not be called on devices of type %GDK_DEVICE_TYPE_SLAVE,
 * unless there is an ongoing grab on them, see gdk_device_grab().
 *
 * @param winX return location for the X coordinate of the device location,
 *         relative to the window origin, or %NULL.
 * @param winY return location for the Y coordinate of the device location,
 *         relative to the window origin, or %NULL.
 * @return the #GdkWindow under the
 * device position, or %NULL.
 */
- (OGGdkWindow*)windowAtPositionWithWinX:(gint*)winX winY:(gint*)winY;

/**
 * Obtains the window underneath @device, returning the location of the device in @win_x and @win_y in
 * double precision. Returns %NULL if the window tree under @device is not known to GDK (for example,
 * belongs to another application).
 * 
 * As a slave device coordinates are those of its master pointer, This
 * function may not be called on devices of type %GDK_DEVICE_TYPE_SLAVE,
 * unless there is an ongoing grab on them, see gdk_device_grab().
 *
 * @param winX return location for the X coordinate of the device location,
 *         relative to the window origin, or %NULL.
 * @param winY return location for the Y coordinate of the device location,
 *         relative to the window origin, or %NULL.
 * @return the #GdkWindow under the
 *   device position, or %NULL.
 */
- (OGGdkWindow*)windowAtPositionDoubleWithWinX:(gdouble*)winX winY:(gdouble*)winY;

/**
 * Grabs the device so that all events coming from this device are passed to
 * this application until the device is ungrabbed with gdk_device_ungrab(),
 * or the window becomes unviewable. This overrides any previous grab on the device
 * by this client.
 * 
 * Note that @device and @window need to be on the same display.
 * 
 * Device grabs are used for operations which need complete control over the
 * given device events (either pointer or keyboard). For example in GTK+ this
 * is used for Drag and Drop operations, popup menus and such.
 * 
 * Note that if the event mask of an X window has selected both button press
 * and button release events, then a button press event will cause an automatic
 * pointer grab until the button is released. X does this automatically since
 * most applications expect to receive button press and release events in pairs.
 * It is equivalent to a pointer grab on the window with @owner_events set to
 * %TRUE.
 * 
 * If you set up anything at the time you take the grab that needs to be
 * cleaned up when the grab ends, you should handle the #GdkEventGrabBroken
 * events that are emitted when the grab ends unvoluntarily.
 *
 * @param window the #GdkWindow which will own the grab (the grab window)
 * @param grabOwnership specifies the grab ownership.
 * @param ownerEvents if %FALSE then all device events are reported with respect to
 *                @window and are only reported if selected by @event_mask. If
 *                %TRUE then pointer events for this application are reported
 *                as normal, but pointer events outside this application are
 *                reported with respect to @window and only if selected by
 *                @event_mask. In either mode, unreported events are discarded.
 * @param eventMask specifies the event mask, which is used in accordance with
 *              @owner_events.
 * @param cursor the cursor to display while the grab is active if the device is
 *          a pointer. If this is %NULL then the normal cursors are used for
 *          @window and its descendants, and the cursor for @window is used
 *          elsewhere.
 * @param time the timestamp of the event which led to this pointer grab. This
 *         usually comes from the #GdkEvent struct, though %GDK_CURRENT_TIME
 *         can be used if the time isn’t known.
 * @return %GDK_GRAB_SUCCESS if the grab was successful.
 */
- (GdkGrabStatus)grabWithWindow:(OGGdkWindow*)window grabOwnership:(GdkGrabOwnership)grabOwnership ownerEvents:(bool)ownerEvents eventMask:(GdkEventMask)eventMask cursor:(OGGdkCursor*)cursor time:(guint32)time;

/**
 * Returns a #GList of #GdkAtoms, containing the labels for
 * the axes that @device currently has.
 *
 * @return A #GList of #GdkAtoms, free with g_list_free().
 */
- (GList*)listAxes;

/**
 * If the device if of type %GDK_DEVICE_TYPE_MASTER, it will return
 * the list of slave devices attached to it, otherwise it will return
 * %NULL
 *
 * @return the list of slave devices, or %NULL. The list must be
 *          freed with g_list_free(), the contents of the list are
 *          owned by GTK+ and should not be freed.
 */
- (GList*)listSlaveDevices;

/**
 * Specifies how an axis of a device is used.
 *
 * @param index the index of the axis
 * @param use specifies how the axis is used
 */
- (void)setAxisUseWithIndex:(guint)index use:(GdkAxisUse)use;

/**
 * Specifies the X key event to generate when a macro button of a device
 * is pressed.
 *
 * @param index the index of the macro button to set
 * @param keyval the keyval to generate
 * @param modifiers the modifiers to set
 */
- (void)setKeyWithIndex:(guint)index keyval:(guint)keyval modifiers:(GdkModifierType)modifiers;

/**
 * Sets a the mode of an input device. The mode controls if the
 * device is active and whether the device’s range is mapped to the
 * entire screen or to a single window.
 * 
 * Note: This is only meaningful for floating devices, master devices (and
 * slaves connected to these) drive the pointer cursor, which is not limited
 * by the input mode.
 *
 * @param mode the input mode.
 * @return %TRUE if the mode was successfully changed.
 */
- (bool)setMode:(GdkInputMode)mode;

/**
 * Release any grab on @device.
 *
 * @param time a timestap (e.g. %GDK_CURRENT_TIME).
 */
- (void)ungrab:(guint32)time;

/**
 * Warps @device in @display to the point @x,@y on
 * the screen @screen, unless the device is confined
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
 * @param screen the screen to warp @device to.
 * @param x the X coordinate of the destination.
 * @param y the Y coordinate of the destination.
 */
- (void)warpWithScreen:(OGGdkScreen*)screen x:(gint)x y:(gint)y;

@end