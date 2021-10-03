/*
 * OGTKAccelMap.h
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
#import "OGTKBase.h"

@interface OGTKAccelMap : OGTKBase
{

}

/**
 * Functions
 */
+ (void)addEntryWithAccelPath:(OFString*)accelPath andAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods;
+ (void)addFilter:(OFString*)filterPattern;
+ (bool)changeEntryWithAccelPath:(OFString*)accelPath andAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods andReplace:(bool)replace;
+ (void)foreachWithData:(gpointer)data andForeachFunc:(GtkAccelMapForeach)foreachFunc;
+ (void)foreachUnfilteredWithData:(gpointer)data andForeachFunc:(GtkAccelMapForeach)foreachFunc;
+ (GtkAccelMap*)get;
+ (void)load:(OFString*)fileName;
+ (void)loadFd:(gint)fd;
+ (void)loadScanner:(GScanner*)scanner;
+ (void)lockPath:(OFString*)accelPath;
+ (bool)lookupEntryWithAccelPath:(OFString*)accelPath andKey:(GtkAccelKey*)key;
+ (void)save:(OFString*)fileName;
+ (void)saveFd:(gint)fd;
+ (void)unlockPath:(OFString*)accelPath;

/**
 * Methods
 */

- (GtkAccelMap*)ACCELMAP;

@end