/*
 * OGTKAccelMap.m
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
#import "OGTKAccelMap.h"

@implementation OGTKAccelMap

+ (void)addEntryWithAccelPath:(OFString*)accelPath andAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods
{
	gtk_accel_map_add_entry([accelPath UTF8String], accelKey, accelMods);
}

+ (void)addFilter:(OFString*)filterPattern
{
	gtk_accel_map_add_filter([filterPattern UTF8String]);
}

+ (bool)changeEntryWithAccelPath:(OFString*)accelPath andAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods andReplace:(bool)replace
{
	return gtk_accel_map_change_entry([accelPath UTF8String], accelKey, accelMods, replace);
}

+ (void)foreachWithData:(gpointer)data andForeachFunc:(GtkAccelMapForeach)foreachFunc
{
	gtk_accel_map_foreach(data, foreachFunc);
}

+ (void)foreachUnfilteredWithData:(gpointer)data andForeachFunc:(GtkAccelMapForeach)foreachFunc
{
	gtk_accel_map_foreach_unfiltered(data, foreachFunc);
}

+ (GtkAccelMap*)get
{
	return gtk_accel_map_get();
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

+ (bool)lookupEntryWithAccelPath:(OFString*)accelPath andKey:(GtkAccelKey*)key
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