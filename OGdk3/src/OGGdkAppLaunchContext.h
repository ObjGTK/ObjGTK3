/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkScreen;
@class OGGdkDisplay;

/**
 * GdkAppLaunchContext is an implementation of #GAppLaunchContext that
 * handles launching an application in a graphical context. It provides
 * startup notification and allows to launch applications on a specific
 * screen or workspace.
 * 
 * ## Launching an application
 * 
 * |[<!-- language="C" -->
 * GdkAppLaunchContext *context;
 * 
 * context = gdk_display_get_app_launch_context (display);
 * 
 * gdk_app_launch_context_set_screen (screen);
 * gdk_app_launch_context_set_timestamp (event->time);
 * 
 * if (!g_app_info_launch_default_for_uri ("http://www.gtk.org", context, &error))
 *   g_warning ("Launching failed: %s\n", error->message);
 * 
 * g_object_unref (context);
 * ]|
 *
 */
@interface OGGdkAppLaunchContext : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GdkAppLaunchContext*)APPLAUNCHCONTEXT;

/**
 * Sets the workspace on which applications will be launched when
 * using this context when running under a window manager that
 * supports multiple workspaces, as described in the
 * [Extended Window Manager Hints](http://www.freedesktop.org/Standards/wm-spec).
 * 
 * When the workspace is not specified or @desktop is set to -1,
 * it is up to the window manager to pick one, typically it will
 * be the current workspace.
 *
 * @param desktop the number of a workspace, or -1
 */
- (void)setDesktop:(gint)desktop;

/**
 * Sets the display on which applications will be launched when
 * using this context. See also gdk_app_launch_context_set_screen().
 *
 * @param display a #GdkDisplay
 */
- (void)setDisplay:(OGGdkDisplay*)display;

/**
 * Sets the icon for applications that are launched with this
 * context.
 * 
 * Window Managers can use this information when displaying startup
 * notification.
 * 
 * See also gdk_app_launch_context_set_icon_name().
 *
 * @param icon a #GIcon, or %NULL
 */
- (void)setIcon:(GIcon*)icon;

/**
 * Sets the icon for applications that are launched with this context.
 * The @icon_name will be interpreted in the same way as the Icon field
 * in desktop files. See also gdk_app_launch_context_set_icon().
 * 
 * If both @icon and @icon_name are set, the @icon_name takes priority.
 * If neither @icon or @icon_name is set, the icon is taken from either
 * the file that is passed to launched application or from the #GAppInfo
 * for the launched application itself.
 *
 * @param iconName an icon name, or %NULL
 */
- (void)setIconName:(OFString*)iconName;

/**
 * Sets the screen on which applications will be launched when
 * using this context. See also gdk_app_launch_context_set_display().
 * 
 * Note that, typically, a #GdkScreen represents a logical screen,
 * not a physical monitor.
 * 
 * If both @screen and @display are set, the @screen takes priority.
 * If neither @screen or @display are set, the default screen and
 * display are used.
 *
 * @param screen a #GdkScreen
 */
- (void)setScreen:(OGGdkScreen*)screen;

/**
 * Sets the timestamp of @context. The timestamp should ideally
 * be taken from the event that triggered the launch.
 * 
 * Window managers can use this information to avoid moving the
 * focus to the newly launched application when the user is busy
 * typing in another window. This is also known as 'focus stealing
 * prevention'.
 *
 * @param timestamp a timestamp
 */
- (void)setTimestamp:(guint32)timestamp;

@end