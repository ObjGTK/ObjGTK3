/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRecentAction.h"

#import "OGTKRecentManager.h"

@implementation OGTKRecentAction

- (instancetype)initWithName:(OFString*)name label:(OFString*)label tooltip:(OFString*)tooltip stockId:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_recent_action_new([name UTF8String], [label UTF8String], [tooltip UTF8String], [stockId UTF8String])];

	return self;
}

- (instancetype)initForManagerWithName:(OFString*)name label:(OFString*)label tooltip:(OFString*)tooltip stockId:(OFString*)stockId manager:(OGTKRecentManager*)manager
{
	self = [super initWithGObject:(GObject*)gtk_recent_action_new_for_manager([name UTF8String], [label UTF8String], [tooltip UTF8String], [stockId UTF8String], [manager RECENTMANAGER])];

	return self;
}

- (GtkRecentAction*)RECENTACTION
{
	return GTK_RECENT_ACTION([self GOBJECT]);
}

- (bool)showNumbers
{
	return gtk_recent_action_get_show_numbers([self RECENTACTION]);
}

- (void)setShowNumbers:(bool)showNumbers
{
	gtk_recent_action_set_show_numbers([self RECENTACTION], showNumbers);
}


@end