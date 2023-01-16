/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkDisplay;

/**
 * The purpose of the #GdkDisplayManager singleton object is to offer
 * notification when displays appear or disappear or the default display
 * changes.
 * 
 * You can use gdk_display_manager_get() to obtain the #GdkDisplayManager
 * singleton, but that should be rarely necessary. Typically, initializing
 * GTK+ opens a display that you can work with without ever accessing the
 * #GdkDisplayManager.
 * 
 * The GDK library can be built with support for multiple backends.
 * The #GdkDisplayManager object determines which backend is used
 * at runtime.
 * 
 * When writing backend-specific code that is supposed to work with
 * multiple GDK backends, you have to consider both compile time and
 * runtime. At compile time, use the #GDK_WINDOWING_X11, #GDK_WINDOWING_WIN32
 * macros, etc. to find out which backends are present in the GDK library
 * you are building your application against. At runtime, use type-check
 * macros like GDK_IS_X11_DISPLAY() to find out which backend is in use:
 * 
 * ## Backend-specific code ## {#backend-specific}
 * 
 * |[<!-- language="C" -->
 * #ifdef GDK_WINDOWING_X11
 *   if (GDK_IS_X11_DISPLAY (display))
 *     {
 *       // make X11-specific calls here
 *     }
 *   else
 * #endif
 * #ifdef GDK_WINDOWING_QUARTZ
 *   if (GDK_IS_QUARTZ_DISPLAY (display))
 *     {
 *       // make Quartz-specific calls here
 *     }
 *   else
 * #endif
 *   g_error ("Unsupported GDK backend");
 * ]|
 *
 */
@interface OGGdkDisplayManager : OGObject
{

}

/**
 * Functions
 */
+ (OGGdkDisplayManager*);

/**
 * Methods
 */

- (GdkDisplayManager*)DISPLAYMANAGER;

/**
 * Gets the default #GdkDisplay.
 *
 * @return a #GdkDisplay, or %NULL if
 *     there is no default display.
 */
- (OGGdkDisplay*)defaultDisplay;

/**
 * List all currently open displays.
 *
 * @return a newly
 *     allocated #GSList of #GdkDisplay objects. Free with g_slist_free()
 *     when you are done with it.
 */
- (GSList*)listDisplays;

/**
 * Opens a display.
 *
 * @param name the name of the display to open
 * @return a #GdkDisplay, or %NULL if the
 *     display could not be opened
 */
- (OGGdkDisplay*)openDisplay:(OFString*)name;

/**
 * Sets @display as the default display.
 *
 * @param display a #GdkDisplay
 */
- (void)setDefaultDisplay:(OGGdkDisplay*)display;

@end