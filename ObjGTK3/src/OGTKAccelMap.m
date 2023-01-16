/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAccelMap.h"

@implementation OGTKAccelMap

+ (void)addEntryWithAccelPath:(OFString*)accelPath accelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods
{
	gtk_accel_map_add_entry([accelPath UTF8String], accelKey, accelMods);
}

+ (void)addFilter:(OFString*)filterPattern
{
	gtk_accel_map_add_filter([filterPattern UTF8String]);
}

+ (bool)changeEntryWithAccelPath:(OFString*)accelPath accelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods replace:(bool)replace
{
	return gtk_accel_map_change_entry([accelPath UTF8String], accelKey, accelMods, replace);
}

+ (void)foreachWithData:(gpointer)data foreachFunc:(GtkAccelMapForeach)foreachFunc
{
	gtk_accel_map_foreach(data, foreachFunc);
}

+ (void)foreachUnfilteredWithData:(gpointer)data foreachFunc:(GtkAccelMapForeach)foreachFunc
{
	gtk_accel_map_foreach_unfiltered(data, foreachFunc);
}

+ (OGTKAccelMap*)instance
{
	return [[[OGTKAccelMap alloc] initWithGObject:(GObject*)gtk_accel_map_get()] autorelease];
}

+ (void)load:(OFString*)fileName
{
	gtk_accel_map_load([fileName UTF8String]);
}

+ (void)loadFd:(gint)fd
{
	gtk_accel_map_load_fd(fd);
}

+ (void)loadScanner:(GScanner*)scanner
{
	gtk_accel_map_load_scanner(scanner);
}

+ (void)lockPath:(OFString*)accelPath
{
	gtk_accel_map_lock_path([accelPath UTF8String]);
}

+ (bool)lookupEntryWithAccelPath:(OFString*)accelPath key:(GtkAccelKey*)key
{
	return gtk_accel_map_lookup_entry([accelPath UTF8String], key);
}

+ (void)save:(OFString*)fileName
{
	gtk_accel_map_save([fileName UTF8String]);
}

+ (void)saveFd:(gint)fd
{
	gtk_accel_map_save_fd(fd);
}

+ (void)unlockPath:(OFString*)accelPath
{
	gtk_accel_map_unlock_path([accelPath UTF8String]);
}

- (GtkAccelMap*)ACCELMAP
{
	return GTK_ACCEL_MAP([self GOBJECT]);
}


@end