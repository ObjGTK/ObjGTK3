/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkDisplay;
@class OGGdkDevice;

/**
 * In addition to a single pointer and keyboard for user interface input,
 * GDK contains support for a variety of input devices, including graphics
 * tablets, touchscreens and multiple pointers/keyboards interacting
 * simultaneously with the user interface. Such input devices often have
 * additional features, such as sub-pixel positioning information and
 * additional device-dependent information.
 * 
 * In order to query the device hierarchy and be aware of changes in the
 * device hierarchy (such as virtual devices being created or removed, or
 * physical devices being plugged or unplugged), GDK provides
 * #GdkDeviceManager.
 * 
 * By default, and if the platform supports it, GDK is aware of multiple
 * keyboard/pointer pairs and multitouch devices. This behavior can be
 * changed by calling gdk_disable_multidevice() before gdk_display_open().
 * There should rarely be a need to do that though, since GDK defaults
 * to a compatibility mode in which it will emit just one enter/leave
 * event pair for all devices on a window. To enable per-device
 * enter/leave events and other multi-pointer interaction features,
 * gdk_window_set_support_multidevice() must be called on
 * #GdkWindows (or gtk_widget_set_support_multidevice() on widgets).
 * window. See the gdk_window_set_support_multidevice() documentation
 * for more information.
 * 
 * On X11, multi-device support is implemented through XInput 2.
 * Unless gdk_disable_multidevice() is called, the XInput 2
 * #GdkDeviceManager implementation will be used as the input source.
 * Otherwise either the core or XInput 1 implementations will be used.
 * 
 * For simple applications that don’t have any special interest in
 * input devices, the so-called “client pointer”
 * provides a reasonable approximation to a simple setup with a single
 * pointer and keyboard. The device that has been set as the client
 * pointer can be accessed via gdk_device_manager_get_client_pointer().
 * 
 * Conceptually, in multidevice mode there are 2 device types. Virtual
 * devices (or master devices) are represented by the pointer cursors
 * and keyboard foci that are seen on the screen. Physical devices (or
 * slave devices) represent the hardware that is controlling the virtual
 * devices, and thus have no visible cursor on the screen.
 * 
 * Virtual devices are always paired, so there is a keyboard device for every
 * pointer device. Associations between devices may be inspected through
 * gdk_device_get_associated_device().
 * 
 * There may be several virtual devices, and several physical devices could
 * be controlling each of these virtual devices. Physical devices may also
 * be “floating”, which means they are not attached to any virtual device.
 * 
 * # Master and slave devices
 * 
 * |[
 * carlos@sacarino:~$ xinput list
 * ⎡ Virtual core pointer                          id=2    [master pointer  (3)]
 * ⎜   ↳ Virtual core XTEST pointer                id=4    [slave  pointer  (2)]
 * ⎜   ↳ Wacom ISDv4 E6 Pen stylus                 id=10   [slave  pointer  (2)]
 * ⎜   ↳ Wacom ISDv4 E6 Finger touch               id=11   [slave  pointer  (2)]
 * ⎜   ↳ SynPS/2 Synaptics TouchPad                id=13   [slave  pointer  (2)]
 * ⎜   ↳ TPPS/2 IBM TrackPoint                     id=14   [slave  pointer  (2)]
 * ⎜   ↳ Wacom ISDv4 E6 Pen eraser                 id=16   [slave  pointer  (2)]
 * ⎣ Virtual core keyboard                         id=3    [master keyboard (2)]
 *     ↳ Virtual core XTEST keyboard               id=5    [slave  keyboard (3)]
 *     ↳ Power Button                              id=6    [slave  keyboard (3)]
 *     ↳ Video Bus                                 id=7    [slave  keyboard (3)]
 *     ↳ Sleep Button                              id=8    [slave  keyboard (3)]
 *     ↳ Integrated Camera                         id=9    [slave  keyboard (3)]
 *     ↳ AT Translated Set 2 keyboard              id=12   [slave  keyboard (3)]
 *     ↳ ThinkPad Extra Buttons                    id=15   [slave  keyboard (3)]
 * ]|
 * 
 * By default, GDK will automatically listen for events coming from all
 * master devices, setting the #GdkDevice for all events coming from input
 * devices. Events containing device information are #GDK_MOTION_NOTIFY,
 * #GDK_BUTTON_PRESS, #GDK_2BUTTON_PRESS, #GDK_3BUTTON_PRESS,
 * #GDK_BUTTON_RELEASE, #GDK_SCROLL, #GDK_KEY_PRESS, #GDK_KEY_RELEASE,
 * #GDK_ENTER_NOTIFY, #GDK_LEAVE_NOTIFY, #GDK_FOCUS_CHANGE,
 * #GDK_PROXIMITY_IN, #GDK_PROXIMITY_OUT, #GDK_DRAG_ENTER, #GDK_DRAG_LEAVE,
 * #GDK_DRAG_MOTION, #GDK_DRAG_STATUS, #GDK_DROP_START, #GDK_DROP_FINISHED
 * and #GDK_GRAB_BROKEN. When dealing with an event on a master device,
 * it is possible to get the source (slave) device that the event originated
 * from via gdk_event_get_source_device().
 * 
 * On a standard session, all physical devices are connected by default to
 * the "Virtual Core Pointer/Keyboard" master devices, hence routing all events
 * through these. This behavior is only modified by device grabs, where the
 * slave device is temporarily detached for as long as the grab is held, and
 * more permanently by user modifications to the device hierarchy.
 * 
 * On certain application specific setups, it may make sense
 * to detach a physical device from its master pointer, and mapping it to
 * an specific window. This can be achieved by the combination of
 * gdk_device_grab() and gdk_device_set_mode().
 * 
 * In order to listen for events coming from devices
 * other than a virtual device, gdk_window_set_device_events() must be
 * called. Generally, this function can be used to modify the event mask
 * for any given device.
 * 
 * Input devices may also provide additional information besides X/Y.
 * For example, graphics tablets may also provide pressure and X/Y tilt
 * information. This information is device-dependent, and may be
 * queried through gdk_device_get_axis(). In multidevice mode, virtual
 * devices will change axes in order to always represent the physical
 * device that is routing events through it. Whenever the physical device
 * changes, the #GdkDevice:n-axes property will be notified, and
 * gdk_device_list_axes() will return the new device axes.
 * 
 * Devices may also have associated “keys” or
 * macro buttons. Such keys can be globally set to map into normal X
 * keyboard events. The mapping is set using gdk_device_set_key().
 * 
 * In GTK+ 3.20, a new #GdkSeat object has been introduced that
 * supersedes #GdkDeviceManager and should be preferred in newly
 * written code.
 *
 */
@interface OGGdkDeviceManager : OGObject
{

}


/**
 * Methods
 */

- (GdkDeviceManager*)DEVICEMANAGER;

/**
 * Returns the client pointer, that is, the master pointer that acts as the core pointer
 * for this application. In X11, window managers may change this depending on the interaction
 * pattern under the presence of several pointers.
 * 
 * You should use this function seldomly, only in code that isn’t triggered by a #GdkEvent
 * and there aren’t other means to get a meaningful #GdkDevice to operate on.
 *
 * @return The client pointer. This memory is
 *          owned by GDK and must not be freed or unreferenced.
 */
- (OGGdkDevice*)clientPointer;

/**
 * Gets the #GdkDisplay associated to @device_manager.
 *
 * @return the #GdkDisplay to which
 *          @device_manager is associated to, or %NULL. This memory is
 *          owned by GDK and must not be freed or unreferenced.
 */
- (OGGdkDisplay*)display;

/**
 * Returns the list of devices of type @type currently attached to
 * @device_manager.
 *
 * @param type device type to get.
 * @return a list of
 *          #GdkDevices. The returned list must be
 *          freed with g_list_free (). The list elements are owned by
 *          GTK+ and must not be freed or unreffed.
 */
- (GList*)listDevices:(GdkDeviceType)type;

@end