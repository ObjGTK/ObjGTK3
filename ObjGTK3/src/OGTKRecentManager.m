/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRecentManager.h"

@implementation OGTKRecentManager

+ (OGTKRecentManager*)default
{
	return [[[OGTKRecentManager alloc] initWithGObject:(GObject*)gtk_recent_manager_get_default()] autorelease];
}

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_recent_manager_new()];

	return self;
}

- (GtkRecentManager*)RECENTMANAGER
{
	return GTK_RECENT_MANAGER([self GOBJECT]);
}

- (bool)addFullWithUri:(OFString*)uri recentData:(const GtkRecentData*)recentData
{
	return gtk_recent_manager_add_full([self RECENTMANAGER], [uri UTF8String], recentData);
}

- (bool)addItem:(OFString*)uri
{
	return gtk_recent_manager_add_item([self RECENTMANAGER], [uri UTF8String]);
}

- (GList*)items
{
	return gtk_recent_manager_get_items([self RECENTMANAGER]);
}

- (bool)hasItem:(OFString*)uri
{
	return gtk_recent_manager_has_item([self RECENTMANAGER], [uri UTF8String]);
}

- (GtkRecentInfo*)lookupItemWithUri:(OFString*)uri err:(GError**)err
{
	return gtk_recent_manager_lookup_item([self RECENTMANAGER], [uri UTF8String], err);
}

- (bool)moveItemWithUri:(OFString*)uri newUri:(OFString*)newUri err:(GError**)err
{
	return gtk_recent_manager_move_item([self RECENTMANAGER], [uri UTF8String], [newUri UTF8String], err);
}

- (gint)purgeItems:(GError**)err
{
	return gtk_recent_manager_purge_items([self RECENTMANAGER], err);
}

- (bool)removeItemWithUri:(OFString*)uri err:(GError**)err
{
	return gtk_recent_manager_remove_item([self RECENTMANAGER], [uri UTF8String], err);
}


@end