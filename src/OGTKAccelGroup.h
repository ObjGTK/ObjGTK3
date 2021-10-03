/*
 * OGTKAccelGroup.h
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

@interface OGTKAccelGroup : OGTKBase
{

}

/**
 * Functions
 */
+ (GtkAccelGroup*)fromAccelClosure:(GClosure*)closure;

/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkAccelGroup*)ACCELGROUP;

/**
 * - (bool*)activateWithAccelQuark:(GQuark)accelQuark andAcceleratable:(GObject*)acceleratable andAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods;
 *
 * @param accelQuark
 * @param acceleratable
 * @param accelKey
 * @param accelMods
 * @returns bool
 */
- (bool)activateWithAccelQuark:(GQuark)accelQuark andAcceleratable:(GObject*)acceleratable andAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods;

/**
 * - (void*)connectWithAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods andAccelFlags:(GtkAccelFlags)accelFlags andClosure:(GClosure*)closure;
 *
 * @param accelKey
 * @param accelMods
 * @param accelFlags
 * @param closure
 */
- (void)connectWithAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods andAccelFlags:(GtkAccelFlags)accelFlags andClosure:(GClosure*)closure;

/**
 * - (void*)connectByPathWithAccelPath:(OFString*)accelPath andClosure:(GClosure*)closure;
 *
 * @param accelPath
 * @param closure
 */
- (void)connectByPathWithAccelPath:(OFString*)accelPath andClosure:(GClosure*)closure;

/**
 * - (bool*)disconnect:(GClosure*)closure;
 *
 * @param closure
 * @returns bool
 */
- (bool)disconnect:(GClosure*)closure;

/**
 * - (bool*)disconnectKeyWithAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods;
 *
 * @param accelKey
 * @param accelMods
 * @returns bool
 */
- (bool)disconnectKeyWithAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods;

/**
 * - (GtkAccelKey**)findWithFindFunc:(GtkAccelGroupFindFunc)findFunc andData:(gpointer)data;
 *
 * @param findFunc
 * @param data
 * @returns GtkAccelKey*
 */
- (GtkAccelKey*)findWithFindFunc:(GtkAccelGroupFindFunc)findFunc andData:(gpointer)data;

/**
 * - (bool*)getIsLocked;
 *
 * @returns bool
 */
- (bool)getIsLocked;

/**
 * - (GdkModifierType*)getModifierMask;
 *
 * @returns GdkModifierType
 */
- (GdkModifierType)getModifierMask;

/**
 * - (void*)lock;
 *
 */
- (void)lock;

/**
 * - (GtkAccelGroupEntry**)queryWithAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods andNentries:(guint*)nentries;
 *
 * @param accelKey
 * @param accelMods
 * @param nentries
 * @returns GtkAccelGroupEntry*
 */
- (GtkAccelGroupEntry*)queryWithAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods andNentries:(guint*)nentries;

/**
 * - (void*)unlock;
 *
 */
- (void)unlock;

@end