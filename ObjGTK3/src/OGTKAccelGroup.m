/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAccelGroup.h"

@implementation OGTKAccelGroup

+ (OGTKAccelGroup*)fromAccelClosure:(GClosure*)closure
{
	return [[[OGTKAccelGroup alloc] initWithGObject:(GObject*)gtk_accel_group_from_accel_closure(closure)] autorelease];
}

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_accel_group_new()];

	return self;
}

- (GtkAccelGroup*)ACCELGROUP
{
	return GTK_ACCEL_GROUP([self GOBJECT]);
}

- (bool)activateWithAccelQuark:(GQuark)accelQuark acceleratable:(GObject*)acceleratable accelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods
{
	return gtk_accel_group_activate([self ACCELGROUP], accelQuark, acceleratable, accelKey, accelMods);
}

- (void)connectWithAccelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods accelFlags:(GtkAccelFlags)accelFlags closure:(GClosure*)closure
{
	gtk_accel_group_connect([self ACCELGROUP], accelKey, accelMods, accelFlags, closure);
}

- (void)connectByPathWithAccelPath:(OFString*)accelPath closure:(GClosure*)closure
{
	gtk_accel_group_connect_by_path([self ACCELGROUP], [accelPath UTF8String], closure);
}

- (bool)disconnect:(GClosure*)closure
{
	return gtk_accel_group_disconnect([self ACCELGROUP], closure);
}

- (bool)disconnectKeyWithAccelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods
{
	return gtk_accel_group_disconnect_key([self ACCELGROUP], accelKey, accelMods);
}

- (GtkAccelKey*)findWithFindFunc:(GtkAccelGroupFindFunc)findFunc data:(gpointer)data
{
	return gtk_accel_group_find([self ACCELGROUP], findFunc, data);
}

- (bool)isLocked
{
	return gtk_accel_group_get_is_locked([self ACCELGROUP]);
}

- (GdkModifierType)modifierMask
{
	return gtk_accel_group_get_modifier_mask([self ACCELGROUP]);
}

- (void)lock
{
	gtk_accel_group_lock([self ACCELGROUP]);
}

- (GtkAccelGroupEntry*)queryWithAccelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods nentries:(guint*)nentries
{
	return gtk_accel_group_query([self ACCELGROUP], accelKey, accelMods, nentries);
}

- (void)unlock
{
	gtk_accel_group_unlock([self ACCELGROUP]);
}


@end