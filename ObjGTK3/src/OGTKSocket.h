/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKWidget;
@class OGGdkWindow;

/**
 * Together with #GtkPlug, #GtkSocket provides the ability to embed
 * widgets from one process into another process in a fashion that
 * is transparent to the user. One process creates a #GtkSocket widget
 * and passes that widget’s window ID to the other process, which then
 * creates a #GtkPlug with that window ID. Any widgets contained in the
 * #GtkPlug then will appear inside the first application’s window.
 * 
 * The socket’s window ID is obtained by using gtk_socket_get_id().
 * Before using this function, the socket must have been realized,
 * and for hence, have been added to its parent.
 * 
 * ## Obtaining the window ID of a socket.
 * 
 * |[<!-- language="C" -->
 * GtkWidget *socket = gtk_socket_new ();
 * gtk_widget_show (socket);
 * gtk_container_add (GTK_CONTAINER (parent), socket);
 * 
 * // The following call is only necessary if one of
 * // the ancestors of the socket is not yet visible.
 * gtk_widget_realize (socket);
 * g_print ("The ID of the sockets window is %#x\n",
 *          gtk_socket_get_id (socket));
 * ]|
 * 
 * Note that if you pass the window ID of the socket to another
 * process that will create a plug in the socket, you must make
 * sure that the socket widget is not destroyed until that plug
 * is created. Violating this rule will cause unpredictable
 * consequences, the most likely consequence being that the plug
 * will appear as a separate toplevel window. You can check if
 * the plug has been created by using gtk_socket_get_plug_window().
 * If it returns a non-%NULL value, then the plug has been
 * successfully created inside of the socket.
 * 
 * When GTK+ is notified that the embedded window has been destroyed,
 * then it will destroy the socket as well. You should always,
 * therefore, be prepared for your sockets to be destroyed at any
 * time when the main event loop is running. To prevent this from
 * happening, you can connect to the #GtkSocket::plug-removed signal.
 * 
 * The communication between a #GtkSocket and a #GtkPlug follows the
 * [XEmbed Protocol](http://www.freedesktop.org/Standards/xembed-spec).
 * This protocol has also been implemented in other toolkits, e.g. Qt,
 * allowing the same level of integration when embedding a Qt widget
 * in GTK or vice versa.
 * 
 * The #GtkPlug and #GtkSocket widgets are only available when GTK+
 * is compiled for the X11 platform and %GDK_WINDOWING_X11 is defined.
 * They can only be used on a #GdkX11Display. To use #GtkPlug and
 * #GtkSocket, you need to include the `gtk/gtkx.h` header.
 *
 */
@interface OGTKSocket : OGTKContainer
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkSocket*)SOCKET;

/**
 * Adds an XEMBED client, such as a #GtkPlug, to the #GtkSocket.  The
 * client may be in the same process or in a different process.
 * 
 * To embed a #GtkPlug in a #GtkSocket, you can either create the
 * #GtkPlug with `gtk_plug_new (0)`, call
 * gtk_plug_get_id() to get the window ID of the plug, and then pass that to the
 * gtk_socket_add_id(), or you can call gtk_socket_get_id() to get the
 * window ID for the socket, and call gtk_plug_new() passing in that
 * ID.
 * 
 * The #GtkSocket must have already be added into a toplevel window
 *  before you can make this call.
 *
 * @param window the Window of a client participating in the XEMBED protocol.
 */
- (void)addId:(Window)window;

/**
 * Gets the window ID of a #GtkSocket widget, which can then
 * be used to create a client embedded inside the socket, for
 * instance with gtk_plug_new().
 * 
 * The #GtkSocket must have already be added into a toplevel window
 * before you can make this call.
 *
 * @return the window ID for the socket
 */
- (Window)id;

/**
 * Retrieves the window of the plug. Use this to check if the plug has
 * been created inside of the socket.
 *
 * @return the window of the plug if
 * available, or %NULL
 */
- (OGGdkWindow*)plugWindow;

@end