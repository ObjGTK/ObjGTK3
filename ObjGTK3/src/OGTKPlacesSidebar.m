/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPlacesSidebar.h"

#import "OGTKWidget.h"
#import <OGdk3/OGGdkDragContext.h>

@implementation OGTKPlacesSidebar

- (instancetype)init
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
	gtk_places_sidebar_add_shortcut([self PLACESSIDEBAR], location);
}

- (bool)localOnly
{
	return gtk_places_sidebar_get_local_only([self PLACESSIDEBAR]);
}

- (GFile*)location
{
	return gtk_places_sidebar_get_location([self PLACESSIDEBAR]);
}

- (GFile*)nthBookmark:(gint)n
{
	return gtk_places_sidebar_get_nth_bookmark([self PLACESSIDEBAR], n);
}

- (GtkPlacesOpenFlags)openFlags
{
	return gtk_places_sidebar_get_open_flags([self PLACESSIDEBAR]);
}

- (bool)showConnectToServer
{
	return gtk_places_sidebar_get_show_connect_to_server([self PLACESSIDEBAR]);
}

- (bool)showDesktop
{
	return gtk_places_sidebar_get_show_desktop([self PLACESSIDEBAR]);
}

- (bool)showEnterLocation
{
	return gtk_places_sidebar_get_show_enter_location([self PLACESSIDEBAR]);
}

- (bool)showOtherLocations
{
	return gtk_places_sidebar_get_show_other_locations([self PLACESSIDEBAR]);
}

- (bool)showRecent
{
	return gtk_places_sidebar_get_show_recent([self PLACESSIDEBAR]);
}

- (bool)showStarredLocation
{
	return gtk_places_sidebar_get_show_starred_location([self PLACESSIDEBAR]);
}

- (bool)showTrash
{
	return gtk_places_sidebar_get_show_trash([self PLACESSIDEBAR]);
}

- (GSList*)listShortcuts
{
	return gtk_places_sidebar_list_shortcuts([self PLACESSIDEBAR]);
}

- (void)removeShortcut:(GFile*)location
{
	gtk_places_sidebar_remove_shortcut([self PLACESSIDEBAR], location);
}

- (void)setDropTargetsVisibleWithVisible:(bool)visible context:(OGGdkDragContext*)context
{
	gtk_places_sidebar_set_drop_targets_visible([self PLACESSIDEBAR], visible, [context DRAGCONTEXT]);
}

- (void)setLocalOnly:(bool)localOnly
{
	gtk_places_sidebar_set_local_only([self PLACESSIDEBAR], localOnly);
}

- (void)setLocation:(GFile*)location
{
	gtk_places_sidebar_set_location([self PLACESSIDEBAR], location);
}

- (void)setOpenFlags:(GtkPlacesOpenFlags)flags
{
	gtk_places_sidebar_set_open_flags([self PLACESSIDEBAR], flags);
}

- (void)setShowConnectToServer:(bool)showConnectToServer
{
	gtk_places_sidebar_set_show_connect_to_server([self PLACESSIDEBAR], showConnectToServer);
}

- (void)setShowDesktop:(bool)showDesktop
{
	gtk_places_sidebar_set_show_desktop([self PLACESSIDEBAR], showDesktop);
}

- (void)setShowEnterLocation:(bool)showEnterLocation
{
	gtk_places_sidebar_set_show_enter_location([self PLACESSIDEBAR], showEnterLocation);
}

- (void)setShowOtherLocations:(bool)showOtherLocations
{
	gtk_places_sidebar_set_show_other_locations([self PLACESSIDEBAR], showOtherLocations);
}

- (void)setShowRecent:(bool)showRecent
{
	gtk_places_sidebar_set_show_recent([self PLACESSIDEBAR], showRecent);
}

- (void)setShowStarredLocation:(bool)showStarredLocation
{
	gtk_places_sidebar_set_show_starred_location([self PLACESSIDEBAR], showStarredLocation);
}

- (void)setShowTrash:(bool)showTrash
{
	gtk_places_sidebar_set_show_trash([self PLACESSIDEBAR], showTrash);
}


@end