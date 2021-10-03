/*
 * OGTKAccelGroup.m
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
#import "OGTKAccelGroup.h"

@implementation OGTKAccelGroup

+ (GtkAccelGroup*)fromAccelClosure:(GClosure*)closure
{
	return gtk_accel_group_from_accel_closure(closure);
}

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_accel_group_new()];

	return self;
}

- (GtkAccelGroup*)ACCELGROUP
{
	return GTK_ACCEL_GROUP([self GOBJECT]);
}

- (bool)activateWithAccelQuark:(GQuark)accelQuark andAcceleratable:(GObject*)acceleratable andAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods
{
	return gtk_accel_group_activate(GTK_ACCEL_GROUP([self GOBJECT]), accelQuark, acceleratable, accelKey, accelMods);
}

- (void)connectWithAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods andAccelFlags:(GtkAccelFlags)accelFlags andClosure:(GClosure*)closure
{
	gtk_accel_group_connect(GTK_ACCEL_GROUP([self GOBJECT]), accelKey, accelMods, accelFlags, closure);
}

- (void)connectByPathWithAccelPath:(OFString*)accelPath andClosure:(GClosure*)closure
{
	gtk_accel_group_connect_by_path(GTK_ACCEL_GROUP([self GOBJECT]), [accelPath UTF8String], closure);
}

- (bool)disconnect:(GClosure*)closure
{
	return gtk_accel_group_disconnect(GTK_ACCEL_GROUP([self GOBJECT]), closure);
}

- (bool)disconnectKeyWithAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods
{
	return gtk_accel_group_disconnect_key(GTK_ACCEL_GROUP([self GOBJECT]), accelKey, accelMods);
}

- (GtkAccelKey*)findWithFindFunc:(GtkAccelGroupFindFunc)findFunc andData:(gpointer)data
{
	return gtk_accel_group_find(GTK_ACCEL_GROUP([self GOBJECT]), findFunc, data);
}

- (bool)getIsLocked
{
	return gtk_accel_group_get_is_locked(GTK_ACCEL_GROUP([self GOBJECT]));
}

- (GdkModifierType)getModifierMask
{
	return gtk_accel_group_get_modifier_mask(GTK_ACCEL_GROUP([self GOBJECT]));
}

- (void)lock
{
	gtk_accel_group_lock(GTK_ACCEL_GROUP([self GOBJECT]));
}

- (GtkAccelGroupEntry*)queryWithAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods andNentries:(guint*)nentries
{
	return gtk_accel_group_query(GTK_ACCEL_GROUP([self GOBJECT]), accelKey, accelMods, nentries);
}

- (void)unlock
{
	gtk_accel_group_unlock(GTK_ACCEL_GROUP([self GOBJECT]));
}


@end