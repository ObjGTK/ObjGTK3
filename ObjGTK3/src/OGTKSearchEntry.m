/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSearchEntry.h"

#import "OGTKWidget.h"

@implementation OGTKSearchEntry

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_search_entry_new()];

	return self;
}

- (GtkSearchEntry*)SEARCHENTRY
{
	return GTK_SEARCH_ENTRY([self GOBJECT]);
}

- (bool)handleEvent:(GdkEvent*)event
{
	return gtk_search_entry_handle_event([self SEARCHENTRY], event);
}


@end