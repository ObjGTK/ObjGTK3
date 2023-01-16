/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKScrolledWindow.h"

@class OGTKWidget;
@class OGGdkDragContext;

/**
 * #GtkPlacesSidebar is a widget that displays a list of frequently-used places in the
 * file system:  the user’s home directory, the user’s bookmarks, and volumes and drives.
 * This widget is used as a sidebar in #GtkFileChooser and may be used by file managers
 * and similar programs.
 * 
 * The places sidebar displays drives and volumes, and will automatically mount
 * or unmount them when the user selects them.
 * 
 * Applications can hook to various signals in the places sidebar to customize
 * its behavior.  For example, they can add extra commands to the context menu
 * of the sidebar.
 * 
 * While bookmarks are completely in control of the user, the places sidebar also
 * allows individual applications to provide extra shortcut folders that are unique
 * to each application.  For example, a Paint program may want to add a shortcut
 * for a Clipart folder.  You can do this with gtk_places_sidebar_add_shortcut().
 * 
 * To make use of the places sidebar, an application at least needs to connect
 * to the #GtkPlacesSidebar::open-location signal.  This is emitted when the
 * user selects in the sidebar a location to open.  The application should also
 * call gtk_places_sidebar_set_location() when it changes the currently-viewed
 * location.
 * 
 * # CSS nodes
 * 
 * GtkPlacesSidebar uses a single CSS node with name placessidebar and style
 * class .sidebar.
 * 
 * Among the children of the places sidebar, the following style classes can
 * be used:
 * - .sidebar-new-bookmark-row for the 'Add new bookmark' row
 * - .sidebar-placeholder-row for a row that is a placeholder
 * - .has-open-popup when a popup is open for a row
 *
 */
@interface OGTKPlacesSidebar : OGTKScrolledWindow
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkPlacesSidebar*)PLACESSIDEBAR;

/**
 * Applications may want to present some folders in the places sidebar if
 * they could be immediately useful to users.  For example, a drawing
 * program could add a “/usr/share/clipart” location when the sidebar is
 * being used in an “Insert Clipart” dialog box.
 * 
 * This function adds the specified @location to a special place for immutable
 * shortcuts.  The shortcuts are application-specific; they are not shared
 * across applications, and they are not persistent.  If this function
 * is called multiple times with different locations, then they are added
 * to the sidebar’s list in the same order as the function is called.
 *
 * @param location location to add as an application-specific shortcut
 */
- (void)addShortcut:(GFile*)location;

/**
 * Returns the value previously set with gtk_places_sidebar_set_local_only().
 *
 * @return %TRUE if the sidebar will only show local files.
 */
- (bool)localOnly;

/**
 * Gets the currently selected location in the @sidebar. This can be %NULL when
 * nothing is selected, for example, when gtk_places_sidebar_set_location() has
 * been called with a location that is not among the sidebar’s list of places to
 * show.
 * 
 * You can use this function to get the selection in the @sidebar.  Also, if you
 * connect to the #GtkPlacesSidebar::populate-popup signal, you can use this
 * function to get the location that is being referred to during the callbacks
 * for your menu items.
 *
 * @return a #GFile with the selected location, or
 * %NULL if nothing is visually selected.
 */
- (GFile*)location;

/**
 * This function queries the bookmarks added by the user to the places sidebar,
 * and returns one of them.  This function is used by #GtkFileChooser to implement
 * the “Alt-1”, “Alt-2”, etc. shortcuts, which activate the cooresponding bookmark.
 *
 * @param n index of the bookmark to query
 * @return The bookmark specified by the index @n, or
 * %NULL if no such index exist.  Note that the indices start at 0, even though
 * the file chooser starts them with the keyboard shortcut "Alt-1".
 */
- (GFile*)nthBookmark:(gint)n;

/**
 * Gets the open flags.
 *
 * @return the #GtkPlacesOpenFlags of @sidebar
 */
- (GtkPlacesOpenFlags)openFlags;

/**
 * Returns the value previously set with gtk_places_sidebar_set_show_connect_to_server()
 *
 * @return %TRUE if the sidebar will display a “Connect to Server” item.
 */
- (bool)showConnectToServer;

/**
 * Returns the value previously set with gtk_places_sidebar_set_show_desktop()
 *
 * @return %TRUE if the sidebar will display a builtin shortcut to the desktop folder.
 */
- (bool)showDesktop;

/**
 * Returns the value previously set with gtk_places_sidebar_set_show_enter_location()
 *
 * @return %TRUE if the sidebar will display an “Enter Location” item.
 */
- (bool)showEnterLocation;

/**
 * Returns the value previously set with gtk_places_sidebar_set_show_other_locations()
 *
 * @return %TRUE if the sidebar will display an “Other Locations” item.
 */
- (bool)showOtherLocations;

/**
 * Returns the value previously set with gtk_places_sidebar_set_show_recent()
 *
 * @return %TRUE if the sidebar will display a builtin shortcut for recent files
 */
- (bool)showRecent;

/**
 * Returns the value previously set with gtk_places_sidebar_set_show_starred_location()
 *
 * @return %TRUE if the sidebar will display a Starred item.
 */
- (bool)showStarredLocation;

/**
 * Returns the value previously set with gtk_places_sidebar_set_show_trash()
 *
 * @return %TRUE if the sidebar will display a “Trash” item.
 */
- (bool)showTrash;

/**
 * Gets the list of shortcuts.
 *
 * @return A #GSList of #GFile of the locations that have been added as
 *     application-specific shortcuts with gtk_places_sidebar_add_shortcut().
 *     To free this list, you can use
 * |[<!-- language="C" -->
 * g_slist_free_full (list, (GDestroyNotify) g_object_unref);
 * ]|
 */
- (GSList*)listShortcuts;

/**
 * Removes an application-specific shortcut that has been previously been
 * inserted with gtk_places_sidebar_add_shortcut().  If the @location is not a
 * shortcut in the sidebar, then nothing is done.
 *
 * @param location location to remove
 */
- (void)removeShortcut:(GFile*)location;

/**
 * Make the GtkPlacesSidebar show drop targets, so it can show the available
 * drop targets and a "new bookmark" row. This improves the Drag-and-Drop
 * experience of the user and allows applications to show all available
 * drop targets at once.
 * 
 * This needs to be called when the application is aware of an ongoing drag
 * that might target the sidebar. The drop-targets-visible state will be unset
 * automatically if the drag finishes in the GtkPlacesSidebar. You only need
 * to unset the state when the drag ends on some other widget on your application.
 *
 * @param visible whether to show the valid targets or not.
 * @param context drag context used to ask the source about the action that wants to
 *     perform, so hints are more accurate.
 */
- (void)setDropTargetsVisibleWithVisible:(bool)visible context:(OGGdkDragContext*)context;

/**
 * Sets whether the @sidebar should only show local files.
 *
 * @param localOnly whether to show only local files
 */
- (void)setLocalOnly:(bool)localOnly;

/**
 * Sets the location that is being shown in the widgets surrounding the
 * @sidebar, for example, in a folder view in a file manager.  In turn, the
 * @sidebar will highlight that location if it is being shown in the list of
 * places, or it will unhighlight everything if the @location is not among the
 * places in the list.
 *
 * @param location location to select, or %NULL for no current path
 */
- (void)setLocation:(GFile*)location;

/**
 * Sets the way in which the calling application can open new locations from
 * the places sidebar.  For example, some applications only open locations
 * “directly” into their main view, while others may support opening locations
 * in a new notebook tab or a new window.
 * 
 * This function is used to tell the places @sidebar about the ways in which the
 * application can open new locations, so that the sidebar can display (or not)
 * the “Open in new tab” and “Open in new window” menu items as appropriate.
 * 
 * When the #GtkPlacesSidebar::open-location signal is emitted, its flags
 * argument will be set to one of the @flags that was passed in
 * gtk_places_sidebar_set_open_flags().
 * 
 * Passing 0 for @flags will cause #GTK_PLACES_OPEN_NORMAL to always be sent
 * to callbacks for the “open-location” signal.
 *
 * @param flags Bitmask of modes in which the calling application can open locations
 */
- (void)setOpenFlags:(GtkPlacesOpenFlags)flags;

/**
 * Sets whether the @sidebar should show an item for connecting to a network server;
 * this is off by default. An application may want to turn this on if it implements
 * a way for the user to connect to network servers directly.
 * 
 * If you enable this, you should connect to the
 * #GtkPlacesSidebar::show-connect-to-server signal.
 *
 * @param showConnectToServer whether to show an item for the Connect to Server command
 */
- (void)setShowConnectToServer:(bool)showConnectToServer;

/**
 * Sets whether the @sidebar should show an item for the Desktop folder.
 * The default value for this option is determined by the desktop
 * environment and the user’s configuration, but this function can be
 * used to override it on a per-application basis.
 *
 * @param showDesktop whether to show an item for the Desktop folder
 */
- (void)setShowDesktop:(bool)showDesktop;

/**
 * Sets whether the @sidebar should show an item for entering a location;
 * this is off by default. An application may want to turn this on if manually
 * entering URLs is an expected user action.
 * 
 * If you enable this, you should connect to the
 * #GtkPlacesSidebar::show-enter-location signal.
 *
 * @param showEnterLocation whether to show an item to enter a location
 */
- (void)setShowEnterLocation:(bool)showEnterLocation;

/**
 * Sets whether the @sidebar should show an item for the application to show
 * an Other Locations view; this is off by default. When set to %TRUE, persistent
 * devices such as hard drives are hidden, otherwise they are shown in the sidebar.
 * An application may want to turn this on if it implements a way for the user to
 * see and interact with drives and network servers directly.
 * 
 * If you enable this, you should connect to the
 * #GtkPlacesSidebar::show-other-locations signal.
 *
 * @param showOtherLocations whether to show an item for the Other Locations view
 */
- (void)setShowOtherLocations:(bool)showOtherLocations;

/**
 * Sets whether the @sidebar should show an item for recent files.
 * The default value for this option is determined by the desktop
 * environment, but this function can be used to override it on a
 * per-application basis.
 *
 * @param showRecent whether to show an item for recent files
 */
- (void)setShowRecent:(bool)showRecent;

/**
 * If you enable this, you should connect to the
 * #GtkPlacesSidebar::show-starred-location signal.
 *
 * @param showStarredLocation whether to show an item for Starred files
 */
- (void)setShowStarredLocation:(bool)showStarredLocation;

/**
 * Sets whether the @sidebar should show an item for the Trash location.
 *
 * @param showTrash whether to show an item for the Trash location
 */
- (void)setShowTrash:(bool)showTrash;

@end