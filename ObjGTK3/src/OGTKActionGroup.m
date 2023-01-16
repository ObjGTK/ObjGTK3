/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKActionGroup.h"

#import "OGTKAction.h"
#import "OGTKAccelGroup.h"

@implementation OGTKActionGroup

- (instancetype)init:(OFString*)name
{
	self = [super initWithGObject:(GObject*)gtk_action_group_new([name UTF8String])];

	return self;
}

- (GtkActionGroup*)ACTIONGROUP
{
	return GTK_ACTION_GROUP([self GOBJECT]);
}

- (void)addAction:(OGTKAction*)action
{
	gtk_action_group_add_action([self ACTIONGROUP], [action ACTION]);
}

- (void)addActionWithAccelWithAction:(OGTKAction*)action accelerator:(OFString*)accelerator
{
	gtk_action_group_add_action_with_accel([self ACTIONGROUP], [action ACTION], [accelerator UTF8String]);
}

- (void)addActionsWithEntries:(const GtkActionEntry*)entries nentries:(guint)nentries userData:(gpointer)userData
{
	gtk_action_group_add_actions([self ACTIONGROUP], entries, nentries, userData);
}

- (void)addActionsFullWithEntries:(const GtkActionEntry*)entries nentries:(guint)nentries userData:(gpointer)userData destroy:(GDestroyNotify)destroy
{
	gtk_action_group_add_actions_full([self ACTIONGROUP], entries, nentries, userData, destroy);
}

- (void)addRadioActionsWithEntries:(const GtkRadioActionEntry*)entries nentries:(guint)nentries value:(gint)value onChange:(GCallback)onChange userData:(gpointer)userData
{
	gtk_action_group_add_radio_actions([self ACTIONGROUP], entries, nentries, value, onChange, userData);
}

- (void)addRadioActionsFullWithEntries:(const GtkRadioActionEntry*)entries nentries:(guint)nentries value:(gint)value onChange:(GCallback)onChange userData:(gpointer)userData destroy:(GDestroyNotify)destroy
{
	gtk_action_group_add_radio_actions_full([self ACTIONGROUP], entries, nentries, value, onChange, userData, destroy);
}

- (void)addToggleActionsWithEntries:(const GtkToggleActionEntry*)entries nentries:(guint)nentries userData:(gpointer)userData
{
	gtk_action_group_add_toggle_actions([self ACTIONGROUP], entries, nentries, userData);
}

- (void)addToggleActionsFullWithEntries:(const GtkToggleActionEntry*)entries nentries:(guint)nentries userData:(gpointer)userData destroy:(GDestroyNotify)destroy
{
	gtk_action_group_add_toggle_actions_full([self ACTIONGROUP], entries, nentries, userData, destroy);
}

- (OGTKAccelGroup*)accelGroup
{
	return [[[OGTKAccelGroup alloc] initWithGObject:(GObject*)gtk_action_group_get_accel_group([self ACTIONGROUP])] autorelease];
}

- (OGTKAction*)action:(OFString*)actionName
{
	return [[[OGTKAction alloc] initWithGObject:(GObject*)gtk_action_group_get_action([self ACTIONGROUP], [actionName UTF8String])] autorelease];
}

- (OFString*)name
{
	return [OFString stringWithUTF8String:gtk_action_group_get_name([self ACTIONGROUP])];
}

- (bool)sensitive
{
	return gtk_action_group_get_sensitive([self ACTIONGROUP]);
}

- (bool)visible
{
	return gtk_action_group_get_visible([self ACTIONGROUP]);
}

- (GList*)listActions
{
	return gtk_action_group_list_actions([self ACTIONGROUP]);
}

- (void)removeAction:(OGTKAction*)action
{
	gtk_action_group_remove_action([self ACTIONGROUP], [action ACTION]);
}

- (void)setAccelGroup:(OGTKAccelGroup*)accelGroup
{
	gtk_action_group_set_accel_group([self ACTIONGROUP], [accelGroup ACCELGROUP]);
}

- (void)setSensitive:(bool)sensitive
{
	gtk_action_group_set_sensitive([self ACTIONGROUP], sensitive);
}

- (void)setTranslateFuncWithFunc:(GtkTranslateFunc)func data:(gpointer)data notify:(GDestroyNotify)notify
{
	gtk_action_group_set_translate_func([self ACTIONGROUP], func, data, notify);
}

- (void)setTranslationDomain:(OFString*)domain
{
	gtk_action_group_set_translation_domain([self ACTIONGROUP], [domain UTF8String]);
}

- (void)setVisible:(bool)visible
{
	gtk_action_group_set_visible([self ACTIONGROUP], visible);
}

- (OFString*)translateString:(OFString*)string
{
	return [OFString stringWithUTF8String:gtk_action_group_translate_string([self ACTIONGROUP], [string UTF8String])];
}


@end