/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtkx.h>
#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>

#import <OGdk3/OGGdkWindow.h>

@class OGGdkDisplay;
@class OGTKWidget;

/**
 * Together with #GtkSocket, #GtkPlug provides the ability to embed
 * widgets from one process into another process in a fashion that is
 * transparent to the user. One process creates a #GtkSocket widget
 * and passes the ID of that widget’s window to the other process,
 * which then creates a #GtkPlug with that window ID. Any widgets
 * contained in the #GtkPlug then will appear inside the first
 * application’s window.
 * 
 * The communication between a #GtkSocket and a #GtkPlug follows the
 * [XEmbed Protocol](http://www.freedesktop.org/Standards/xembed-spec).
 * This protocol has also been implemented in other toolkits, e.g. Qt,
 * allowing the same level of integration when embedding a Qt widget
 * in GTK+ or vice versa.
 * 
 * The #GtkPlug and #GtkSocket widgets are only available when GTK+
 * is compiled for the X11 platform and %GDK_WINDOWING_X11 is defined.
 * They can only be used on a #GdkX11Display. To use #GtkPlug and
 * #GtkSocket, you need to include the `gtk/gtkx.h` header.
 *
 */
@interface OGTKPlug : OGGdkWindow
{

}


/**
 * Constructors
 */
- (instancetype)init:(Window)socketId;
- (instancetype)initForDisplayWithDisplay:(OGGdkDisplay*)display socketId:(Window)socketId;

/**
 * Methods
 */

- (GtkPlug*)PLUG;

/**
 * Finish the initialization of @plug for a given #GtkSocket identified by
 * @socket_id. This function will generally only be used by classes deriving from #GtkPlug.
 *
 * @param socketId the XID of the socket’s window.
 */
- (void)construct:(Window)socketId;

/**
 * Finish the initialization of @plug for a given #GtkSocket identified by
 * @socket_id which is currently displayed on @display.
 * This function will generally only be used by classes deriving from #GtkPlug.
 *
 * @param display the #GdkDisplay associated with @socket_id’s
 *      #GtkSocket.
 * @param socketId the XID of the socket’s window.
 */
- (void)constructForDisplayWithDisplay:(OGGdkDisplay*)display socketId:(Window)socketId;

/**
 * Determines whether the plug is embedded in a socket.
 *
 * @return %TRUE if the plug is embedded in a socket
 */
- (bool)embedded;

/**
 * Gets the window ID of a #GtkPlug widget, which can then
 * be used to embed this window inside another window, for
 * instance with gtk_socket_add_id().
 *
 * @return the window ID for the plug
 */
- (Window)id;

/**
 * Retrieves the socket the plug is embedded in.
 *
 * @return the window of the socket, or %NULL
 */
- (OGGdkWindow*)socketWindow;

@end