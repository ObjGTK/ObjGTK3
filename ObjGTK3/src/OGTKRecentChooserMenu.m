/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRecentChooserMenu.h"

#import "OGTKWidget.h"
#import "OGTKRecentManager.h"

@implementation OGTKRecentChooserMenu

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_recent_chooser_menu_new()];

	return self;
}

- (instancetype)initForManager:(OGTKRecentManager*)manager
{
	self = [super initWithGObject:(GObject*)gtk_recent_chooser_menu_new_for_manager([manager RECENTMANAGER])];

	return self;
}

- (GtkRecentChooserMenu*)RECENTCHOOSERMENU
{
	return GTK_RECENT_CHOOSER_MENU([self GOBJECT]);
}

- (bool)showNumbers
{
	return gtk_recent_chooser_menu_get_show_numbers([self RECENTCHOOSERMENU]);
}

- (void)setShowNumbers:(bool)showNumbers
{
	gtk_recent_chooser_menu_set_show_numbers([self RECENTCHOOSERMENU], showNumbers);
}


@end