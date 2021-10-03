/*
 * OGTKPlacesSidebar.m
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
#import "OGTKPlacesSidebar.h"

@implementation OGTKPlacesSidebar

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_places_sidebar_new()];

	return self;
}

- (GtkPlacesSidebar*)PLACESSIDEBAR
{
	return GTK_PLACES_SIDEBAR([self GOBJECT]);
}

- (void)addShortcut:(GFile*)location
{
	gtk_places_sidebar_add_shortcut(GTK_PLACES_SIDEBAR([self GOBJECT]), location);
}

- (bool)getLocalOnly
{
	return gtk_places_sidebar_get_local_only(GTK_PLACES_SIDEBAR([self GOBJECT]));
}

- (GFile*)getLocation
{
	return gtk_places_sidebar_get_location(GTK_PLACES_SIDEBAR([self GOBJECT]));
}

- (GFile*)getNthBookmark:(gint)n
{
	return gtk_places_sidebar_get_nth_bookmark(GTK_PLACES_SIDEBAR([self GOBJECT]), n);
}

- (GtkPlacesOpenFlags)getOpenFlags
{
	return gtk_places_sidebar_get_open_flags(GTK_PLACES_SIDEBAR([self GOBJECT]));
}

- (bool)getShowConnectToServer
{
	return gtk_places_sidebar_get_show_connect_to_server(GTK_PLACES_SIDEBAR([self GOBJECT]));
}

- (bool)getShowDesktop
{
	return gtk_places_sidebar_get_show_desktop(GTK_PLACES_SIDEBAR([self GOBJECT]));
}

- (bool)getShowEnterLocation
{
	return gtk_places_sidebar_get_show_enter_location(GTK_PLACES_SIDEBAR([self GOBJECT]));
}

- (bool)getShowOtherLocations
{
	return gtk_places_sidebar_get_show_other_locations(GTK_PLACES_SIDEBAR([self GOBJECT]));
}

- (bool)getShowRecent
{
	return gtk_places_sidebar_get_show_recent(GTK_PLACES_SIDEBAR([self GOBJECT]));
}

- (bool)getShowStarredLocation
{
	return gtk_places_sidebar_get_show_starred_location(GTK_PLACES_SIDEBAR([self GOBJECT]));
}

- (bool)getShowTrash
{
	return gtk_places_sidebar_get_show_trash(GTK_PLACES_SIDEBAR([self GOBJECT]));
}

- (GSList*)listShortcuts
{
	return gtk_places_sidebar_list_shortcuts(GTK_PLACES_SIDEBAR([self GOBJECT]));
}

- (void)removeShortcut:(GFile*)location
{
	gtk_places_sidebar_remove_shortcut(GTK_PLACES_SIDEBAR([self GOBJECT]), location);
}

- (void)setDropTargetsVisibleWithVisible:(bool)visible andContext:(GdkDragContext*)context
{
	gtk_places_sidebar_set_drop_targets_visible(GTK_PLACES_SIDEBAR([self GOBJECT]), visible, context);
}

- (void)setLocalOnly:(bool)localOnly
{
	gtk_places_sidebar_set_local_only(GTK_PLACES_SIDEBAR([self GOBJECT]), localOnly);
}

- (void)setLocation:(GFile*)location
{
	gtk_places_sidebar_set_location(GTK_PLACES_SIDEBAR([self GOBJECT]), location);
}

- (void)setOpenFlags:(GtkPlacesOpenFlags)flags
{
	gtk_places_sidebar_set_open_flags(GTK_PLACES_SIDEBAR([self GOBJECT]), flags);
}

- (void)setShowConnectToServer:(bool)showConnectToServer
{
	gtk_places_sidebar_set_show_connect_to_server(GTK_PLACES_SIDEBAR([self GOBJECT]), showConnectToServer);
}

- (void)setShowDesktop:(bool)showDesktop
{
	gtk_places_sidebar_set_show_desktop(GTK_PLACES_SIDEBAR([self GOBJECT]), showDesktop);
}

- (void)setShowEnterLocation:(bool)showEnterLocation
{
	gtk_places_sidebar_set_show_enter_location(GTK_PLACES_SIDEBAR([self GOBJECT]), showEnterLocation);
}

- (void)setShowOtherLocations:(bool)showOtherLocations
{
	gtk_places_sidebar_set_show_other_locations(GTK_PLACES_SIDEBAR([self GOBJECT]), showOtherLocations);
}

- (void)setShowRecent:(bool)showRecent
{
	gtk_places_sidebar_set_show_recent(GTK_PLACES_SIDEBAR([self GOBJECT]), showRecent);
}

- (void)setShowStarredLocation:(bool)showStarredLocation
{
	gtk_places_sidebar_set_show_starred_location(GTK_PLACES_SIDEBAR([self GOBJECT]), showStarredLocation);
}

- (void)setShowTrash:(bool)showTrash
{
	gtk_places_sidebar_set_show_trash(GTK_PLACES_SIDEBAR([self GOBJECT]), showTrash);
}


@end