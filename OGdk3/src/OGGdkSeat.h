/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkCursor;
@class OGGdkDevice;
@class OGGdkDisplay;
@class OGGdkWindow;

/**
 * The #GdkSeat object represents a collection of input devices
 * that belong to a user.
 *
 */
@interface OGGdkSeat : OGObject
{

}


/**
 * Methods
 */

- (GdkSeat*)SEAT;

/**
 * Returns the capabilities this #GdkSeat currently has.
 *
 * @return the seat capabilities
 */
- (GdkSeatCapabilities)capabilities;

/**
 * Returns the #GdkDisplay this seat belongs to.
 *
 * @return a #GdkDisplay. This object is owned by GTK+
 *          and must not be freed.
 */
- (OGGdkDisplay*)display;

/**
 * Returns the master device that routes keyboard events.
 *
 * @return a master #GdkDevice with keyboard
 *          capabilities. This object is owned by GTK+ and must not be freed.
 */
- (OGGdkDevice*)keyboard;

/**
 * Returns the master device that routes pointer events.
 *
 * @return a master #GdkDevice with pointer
 *          capabilities. This object is owned by GTK+ and must not be freed.
 */
- (OGGdkDevice*)pointer;

/**
 * Returns the slave devices that match the given capabilities.
 *
 * @param capabilities capabilities to get devices for
 * @return A list of #GdkDevices.
 *          The list must be freed with g_list_free(), the elements are owned
 *          by GDK and must not be freed.
 */
- (GList*)slaves:(GdkSeatCapabilities)capabilities;

/**
 * Grabs the seat so that all events corresponding to the given @capabilities
 * are passed to this application until the seat is ungrabbed with gdk_seat_ungrab(),
 * or the window becomes hidden. This overrides any previous grab on the
 * seat by this client.
 * 
 * As a rule of thumb, if a grab is desired over %GDK_SEAT_CAPABILITY_POINTER,
 * all other "pointing" capabilities (eg. %GDK_SEAT_CAPABILITY_TOUCH) should
 * be grabbed too, so the user is able to interact with all of those while
 * the grab holds, you should thus use %GDK_SEAT_CAPABILITY_ALL_POINTING most
 * commonly.
 * 
 * Grabs are used for operations which need complete control over the
 * events corresponding to the given capabilities. For example in GTK+ this
 * is used for Drag and Drop operations, popup menus and such.
 * 
 * Note that if the event mask of a #GdkWindow has selected both button press
 * and button release events, or touch begin and touch end, then a press event
 * will cause an automatic grab until the button is released, equivalent to a
 * grab on the window with @owner_events set to %TRUE. This is done because most
 * applications expect to receive paired press and release events.
 * 
 * If you set up anything at the time you take the grab that needs to be
 * cleaned up when the grab ends, you should handle the #GdkEventGrabBroken
 * events that are emitted when the grab ends unvoluntarily.
 *
 * @param window the #GdkWindow which will own the grab
 * @param capabilities capabilities that will be grabbed
 * @param ownerEvents if %FALSE then all device events are reported with respect to
 *                @window and are only reported if selected by @event_mask. If
 *                %TRUE then pointer events for this application are reported
 *                as normal, but pointer events outside this application are
 *                reported with respect to @window and only if selected by
 *                @event_mask. In either mode, unreported events are discarded.
 * @param cursor the cursor to display while the grab is active. If
 *          this is %NULL then the normal cursors are used for
 *          @window and its descendants, and the cursor for @window is used
 *          elsewhere.
 * @param event the event that is triggering the grab, or %NULL if none
 *         is available.
 * @param prepareFunc function to
 *                prepare the window to be grabbed, it can be %NULL if @window is
 *                visible before this call.
 * @param prepareFuncData user data to pass to @prepare_func
 * @return %GDK_GRAB_SUCCESS if the grab was successful.
 */
- (GdkGrabStatus)grabWithWindow:(OGGdkWindow*)window capabilities:(GdkSeatCapabilities)capabilities ownerEvents:(bool)ownerEvents cursor:(OGGdkCursor*)cursor event:(const GdkEvent*)event prepareFunc:(GdkSeatGrabPrepareFunc)prepareFunc prepareFuncData:(gpointer)prepareFuncData;

/**
 * Releases a grab added through gdk_seat_grab().
 *
 */
- (void)ungrab;

@end