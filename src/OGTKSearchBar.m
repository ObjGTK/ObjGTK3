/*
 * OGTKSearchBar.m
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
#import "OGTKSearchBar.h"

@implementation OGTKSearchBar

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_search_bar_new()];

	return self;
}

- (GtkSearchBar*)SEARCHBAR
{
	return GTK_SEARCH_BAR([self GOBJECT]);
}

- (void)connectEntry:(GtkEntry*)entry
{
	gtk_search_bar_connect_entry(GTK_SEARCH_BAR([self GOBJECT]), entry);
}

- (bool)getSearchMode
{
	return gtk_search_bar_get_search_mode(GTK_SEARCH_BAR([self GOBJECT]));
}

- (bool)getShowCloseButton
{
	return gtk_search_bar_get_show_close_button(GTK_SEARCH_BAR([self GOBJECT]));
}

- (bool)handleEvent:(GdkEvent*)event
{
	return gtk_search_bar_handle_event(GTK_SEARCH_BAR([self GOBJECT]), event);
}

- (void)setSearchMode:(bool)searchMode
{
	gtk_search_bar_set_search_mode(GTK_SEARCH_BAR([self GOBJECT]), searchMode);
}

- (void)setShowCloseButton:(bool)visible
{
	gtk_search_bar_set_show_close_button(GTK_SEARCH_BAR([self GOBJECT]), visible);
}


@end