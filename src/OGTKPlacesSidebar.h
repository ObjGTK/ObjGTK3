/*
 * OGTKPlacesSidebar.h
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKScrolledWindow.h"

@interface OGTKPlacesSidebar : OGTKScrolledWindow
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkPlacesSidebar*)PLACESSIDEBAR;

/**
 * - (void*)addShortcut:(GFile*)location;
 *
 * @param location
 */
- (void)addShortcut:(GFile*)location;

/**
 * - (bool*)getLocalOnly;
 *
 * @returns bool
 */
- (bool)getLocalOnly;

/**
 * - (GFile**)getLocation;
 *
 * @returns GFile*
 */
- (GFile*)getLocation;

/**
 * - (GFile**)getNthBookmark:(gint)n;
 *
 * @param n
 * @returns GFile*
 */
- (GFile*)getNthBookmark:(gint)n;

/**
 * - (GtkPlacesOpenFlags*)getOpenFlags;
 *
 * @returns GtkPlacesOpenFlags
 */
- (GtkPlacesOpenFlags)getOpenFlags;

/**
 * - (bool*)getShowConnectToServer;
 *
 * @returns bool
 */
- (bool)getShowConnectToServer;

/**
 * - (bool*)getShowDesktop;
 *
 * @returns bool
 */
- (bool)getShowDesktop;

/**
 * - (bool*)getShowEnterLocation;
 *
 * @returns bool
 */
- (bool)getShowEnterLocation;

/**
 * - (bool*)getShowOtherLocations;
 *
 * @returns bool
 */
- (bool)getShowOtherLocations;

/**
 * - (bool*)getShowRecent;
 *
 * @returns bool
 */
- (bool)getShowRecent;

/**
 * - (bool*)getShowStarredLocation;
 *
 * @returns bool
 */
- (bool)getShowStarredLocation;

/**
 * - (bool*)getShowTrash;
 *
 * @returns bool
 */
- (bool)getShowTrash;

/**
 * - (GSList**)listShortcuts;
 *
 * @returns GSList*
 */
- (GSList*)listShortcuts;

/**
 * - (void*)removeShortcut:(GFile*)location;
 *
 * @param location
 */
- (void)removeShortcut:(GFile*)location;

/**
 * - (void*)setDropTargetsVisibleWithVisible:(bool)visible andContext:(GdkDragContext*)context;
 *
 * @param visible
 * @param context
 */
- (void)setDropTargetsVisibleWithVisible:(bool)visible andContext:(GdkDragContext*)context;

/**
 * - (void*)setLocalOnly:(bool)localOnly;
 *
 * @param localOnly
 */
- (void)setLocalOnly:(bool)localOnly;

/**
 * - (void*)setLocation:(GFile*)location;
 *
 * @param location
 */
- (void)setLocation:(GFile*)location;

/**
 * - (void*)setOpenFlags:(GtkPlacesOpenFlags)flags;
 *
 * @param flags
 */
- (void)setOpenFlags:(GtkPlacesOpenFlags)flags;

/**
 * - (void*)setShowConnectToServer:(bool)showConnectToServer;
 *
 * @param showConnectToServer
 */
- (void)setShowConnectToServer:(bool)showConnectToServer;

/**
 * - (void*)setShowDesktop:(bool)showDesktop;
 *
 * @param showDesktop
 */
- (void)setShowDesktop:(bool)showDesktop;

/**
 * - (void*)setShowEnterLocation:(bool)showEnterLocation;
 *
 * @param showEnterLocation
 */
- (void)setShowEnterLocation:(bool)showEnterLocation;

/**
 * - (void*)setShowOtherLocations:(bool)showOtherLocations;
 *
 * @param showOtherLocations
 */
- (void)setShowOtherLocations:(bool)showOtherLocations;

/**
 * - (void*)setShowRecent:(bool)showRecent;
 *
 * @param showRecent
 */
- (void)setShowRecent:(bool)showRecent;

/**
 * - (void*)setShowStarredLocation:(bool)showStarredLocation;
 *
 * @param showStarredLocation
 */
- (void)setShowStarredLocation:(bool)showStarredLocation;

/**
 * - (void*)setShowTrash:(bool)showTrash;
 *
 * @param showTrash
 */
- (void)setShowTrash:(bool)showTrash;

@end