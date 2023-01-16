/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSearchBar.h"

#import "OGTKEntry.h"
#import "OGTKWidget.h"

@implementation OGTKSearchBar

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_search_bar_new()];

	return self;
}

- (GtkSearchBar*)SEARCHBAR
{
	return GTK_SEARCH_BAR([self GOBJECT]);
}

- (void)connectEntry:(OGTKEntry*)entry
{
	gtk_search_bar_connect_entry([self SEARCHBAR], [entry ENTRY]);
}

- (bool)searchMode
{
	return gtk_search_bar_get_search_mode([self SEARCHBAR]);
}

- (bool)showCloseButton
{
	return gtk_search_bar_get_show_close_button([self SEARCHBAR]);
}

- (bool)handleEvent:(GdkEvent*)event
{
	return gtk_search_bar_handle_event([self SEARCHBAR], event);
}

- (void)setSearchMode:(bool)searchMode
{
	gtk_search_bar_set_search_mode([self SEARCHBAR], searchMode);
}

- (void)setShowCloseButton:(bool)visible
{
	gtk_search_bar_set_show_close_button([self SEARCHBAR], visible);
}


@end