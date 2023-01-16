/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKUIManager.h"

#import "OGTKAccelGroup.h"
#import "OGTKAction.h"
#import "OGTKActionGroup.h"
#import "OGTKWidget.h"

@implementation OGTKUIManager

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_ui_manager_new()];

	return self;
}

- (GtkUIManager*)UIMANAGER
{
	return GTK_UI_MANAGER([self GOBJECT]);
}

- (void)addUiWithMergeId:(guint)mergeId path:(OFString*)path name:(OFString*)name action:(OFString*)action type:(GtkUIManagerItemType)type top:(bool)top
{
	gtk_ui_manager_add_ui([self UIMANAGER], mergeId, [path UTF8String], [name UTF8String], [action UTF8String], type, top);
}

- (guint)addUiFromFileWithFilename:(OFString*)filename err:(GError**)err
{
	return gtk_ui_manager_add_ui_from_file([self UIMANAGER], [filename UTF8String], err);
}

- (guint)addUiFromResourceWithResourcePath:(OFString*)resourcePath err:(GError**)err
{
	return gtk_ui_manager_add_ui_from_resource([self UIMANAGER], [resourcePath UTF8String], err);
}

- (guint)addUiFromStringWithBuffer:(OFString*)buffer length:(gssize)length err:(GError**)err
{
	return gtk_ui_manager_add_ui_from_string([self UIMANAGER], [buffer UTF8String], length, err);
}

- (void)ensureUpdate
{
	gtk_ui_manager_ensure_update([self UIMANAGER]);
}

- (OGTKAccelGroup*)accelGroup
{
	return [[[OGTKAccelGroup alloc] initWithGObject:(GObject*)gtk_ui_manager_get_accel_group([self UIMANAGER])] autorelease];
}

- (OGTKAction*)action:(OFString*)path
{
	return [[[OGTKAction alloc] initWithGObject:(GObject*)gtk_ui_manager_get_action([self UIMANAGER], [path UTF8String])] autorelease];
}

- (GList*)actionGroups
{
	return gtk_ui_manager_get_action_groups([self UIMANAGER]);
}

- (bool)addTearoffs
{
	return gtk_ui_manager_get_add_tearoffs([self UIMANAGER]);
}

- (GSList*)toplevels:(GtkUIManagerItemType)types
{
	return gtk_ui_manager_get_toplevels([self UIMANAGER], types);
}

- (OFString*)ui
{
	return [OFString stringWithUTF8String:gtk_ui_manager_get_ui([self UIMANAGER])];
}

- (OGTKWidget*)widget:(OFString*)path
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_ui_manager_get_widget([self UIMANAGER], [path UTF8String])] autorelease];
}

- (void)insertActionGroupWithActionGroup:(OGTKActionGroup*)actionGroup pos:(gint)pos
{
	gtk_ui_manager_insert_action_group([self UIMANAGER], [actionGroup ACTIONGROUP], pos);
}

- (guint)newMergeId
{
	return gtk_ui_manager_new_merge_id([self UIMANAGER]);
}

- (void)removeActionGroup:(OGTKActionGroup*)actionGroup
{
	gtk_ui_manager_remove_action_group([self UIMANAGER], [actionGroup ACTIONGROUP]);
}

- (void)removeUi:(guint)mergeId
{
	gtk_ui_manager_remove_ui([self UIMANAGER], mergeId);
}

- (void)setAddTearoffs:(bool)addTearoffs
{
	gtk_ui_manager_set_add_tearoffs([self UIMANAGER], addTearoffs);
}


@end