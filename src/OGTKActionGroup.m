/*
 * OGTKActionGroup.m
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
#import "OGTKActionGroup.h"

@implementation OGTKActionGroup

- (id)init:(OFString*)name
{
	self = [super initWithGObject:(GObject*)gtk_action_group_new([name UTF8String])];

	return self;
}

- (GtkActionGroup*)ACTIONGROUP
{
	return GTK_ACTION_GROUP([self GOBJECT]);
}

- (void)addAction:(GtkAction*)action
{
	gtk_action_group_add_action(GTK_ACTION_GROUP([self GOBJECT]), action);
}

- (void)addActionWithAccelWithAction:(GtkAction*)action andAccelerator:(OFString*)accelerator
{
	gtk_action_group_add_action_with_accel(GTK_ACTION_GROUP([self GOBJECT]), action, [accelerator UTF8String]);
}

- (void)addActionsWithEntries:(const GtkActionEntry*)entries andNentries:(guint)nentries andUserData:(gpointer)userData
{
	gtk_action_group_add_actions(GTK_ACTION_GROUP([self GOBJECT]), entries, nentries, userData);
}

- (void)addActionsFullWithEntries:(const GtkActionEntry*)entries andNentries:(guint)nentries andUserData:(gpointer)userData andDestroy:(GDestroyNotify)destroy
{
	gtk_action_group_add_actions_full(GTK_ACTION_GROUP([self GOBJECT]), entries, nentries, userData, destroy);
}

- (void)addRadioActionsWithEntries:(const GtkRadioActionEntry*)entries andNentries:(guint)nentries andValue:(gint)value andOnChange:(GCallback)onChange andUserData:(gpointer)userData
{
	gtk_action_group_add_radio_actions(GTK_ACTION_GROUP([self GOBJECT]), entries, nentries, value, onChange, userData);
}

- (void)addRadioActionsFullWithEntries:(const GtkRadioActionEntry*)entries andNentries:(guint)nentries andValue:(gint)value andOnChange:(GCallback)onChange andUserData:(gpointer)userData andDestroy:(GDestroyNotify)destroy
{
	gtk_action_group_add_radio_actions_full(GTK_ACTION_GROUP([self GOBJECT]), entries, nentries, value, onChange, userData, destroy);
}

- (void)addToggleActionsWithEntries:(const GtkToggleActionEntry*)entries andNentries:(guint)nentries andUserData:(gpointer)userData
{
	gtk_action_group_add_toggle_actions(GTK_ACTION_GROUP([self GOBJECT]), entries, nentries, userData);
}

- (void)addToggleActionsFullWithEntries:(const GtkToggleActionEntry*)entries andNentries:(guint)nentries andUserData:(gpointer)userData andDestroy:(GDestroyNotify)destroy
{
	gtk_action_group_add_toggle_actions_full(GTK_ACTION_GROUP([self GOBJECT]), entries, nentries, userData, destroy);
}

- (GtkAccelGroup*)getAccelGroup
{
	return gtk_action_group_get_accel_group(GTK_ACTION_GROUP([self GOBJECT]));
}

- (GtkAction*)getAction:(OFString*)actionName
{
	return gtk_action_group_get_action(GTK_ACTION_GROUP([self GOBJECT]), [actionName UTF8String]);
}

- (OFString*)getName
{
	return [OFString stringWithUTF8String:gtk_action_group_get_name(GTK_ACTION_GROUP([self GOBJECT]))];
}

- (bool)getSensitive
{
	return gtk_action_group_get_sensitive(GTK_ACTION_GROUP([self GOBJECT]));
}

- (bool)getVisible
{
	return gtk_action_group_get_visible(GTK_ACTION_GROUP([self GOBJECT]));
}

- (GList*)listActions
{
	return gtk_action_group_list_actions(GTK_ACTION_GROUP([self GOBJECT]));
}

- (void)removeAction:(GtkAction*)action
{
	gtk_action_group_remove_action(GTK_ACTION_GROUP([self GOBJECT]), action);
}

- (void)setAccelGroup:(GtkAccelGroup*)accelGroup
{
	gtk_action_group_set_accel_group(GTK_ACTION_GROUP([self GOBJECT]), accelGroup);
}

- (void)setSensitive:(bool)sensitive
{
	gtk_action_group_set_sensitive(GTK_ACTION_GROUP([self GOBJECT]), sensitive);
}

- (void)setTranslateFuncWithFunc:(GtkTranslateFunc)func andData:(gpointer)data andNotify:(GDestroyNotify)notify
{
	gtk_action_group_set_translate_func(GTK_ACTION_GROUP([self GOBJECT]), func, data, notify);
}

- (void)setTranslationDomain:(OFString*)domain
{
	gtk_action_group_set_translation_domain(GTK_ACTION_GROUP([self GOBJECT]), [domain UTF8String]);
}

- (void)setVisible:(bool)visible
{
	gtk_action_group_set_visible(GTK_ACTION_GROUP([self GOBJECT]), visible);
}

- (OFString*)translateString:(OFString*)string
{
	return [OFString stringWithUTF8String:gtk_action_group_translate_string(GTK_ACTION_GROUP([self GOBJECT]), [string UTF8String])];
}


@end