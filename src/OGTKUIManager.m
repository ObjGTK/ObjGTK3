/*
 * OGTKUIManager.m
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
#import "OGTKUIManager.h"

@implementation OGTKUIManager

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_ui_manager_new()];

	return self;
}

- (GtkUIManager*)UIMANAGER
{
	return GTK_UIMANAGER([self GOBJECT]);
}

- (void)gtkUiManagerAddUiWithMergeId:(guint)mergeId andPath:(OFString*)path andName:(OFString*)name andAction:(OFString*)action andType:(GtkUIManagerItemType)type andTop:(bool)top
{
	gtk_ui_manager_add_ui(GTK_UIMANAGER([self GOBJECT]), mergeId, [path UTF8String], [name UTF8String], [action UTF8String], type, top);
}

- (guint)gtkUiManagerAddUiFromFile:(OFString*)filename
{
	return gtk_ui_manager_add_ui_from_file(GTK_UIMANAGER([self GOBJECT]), [filename UTF8String]);
}

- (guint)gtkUiManagerAddUiFromResource:(OFString*)resourcePath
{
	return gtk_ui_manager_add_ui_from_resource(GTK_UIMANAGER([self GOBJECT]), [resourcePath UTF8String]);
}

- (guint)gtkUiManagerAddUiFromStringWithBuffer:(OFString*)buffer andLength:(gssize)length
{
	return gtk_ui_manager_add_ui_from_string(GTK_UIMANAGER([self GOBJECT]), [buffer UTF8String], length);
}

- (void)gtkUiManagerEnsureUpdate
{
	gtk_ui_manager_ensure_update(GTK_UIMANAGER([self GOBJECT]));
}

- (GtkAccelGroup*)gtkUiManagerGetAccelGroup
{
	return gtk_ui_manager_get_accel_group(GTK_UIMANAGER([self GOBJECT]));
}

- (GtkAction*)gtkUiManagerGetAction:(OFString*)path
{
	return gtk_ui_manager_get_action(GTK_UIMANAGER([self GOBJECT]), [path UTF8String]);
}

- (GList*)gtkUiManagerGetActionGroups
{
	return gtk_ui_manager_get_action_groups(GTK_UIMANAGER([self GOBJECT]));
}

- (bool)gtkUiManagerGetAddTearoffs
{
	return gtk_ui_manager_get_add_tearoffs(GTK_UIMANAGER([self GOBJECT]));
}

- (GSList*)gtkUiManagerGetToplevels:(GtkUIManagerItemType)types
{
	return gtk_ui_manager_get_toplevels(GTK_UIMANAGER([self GOBJECT]), types);
}

- (OFString*)gtkUiManagerGetUi
{
	return [OFString stringWithUTF8String:gtk_ui_manager_get_ui(GTK_UIMANAGER([self GOBJECT]))];
}

- (OGTKWidget*)gtkUiManagerGetWidget:(OFString*)path
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_ui_manager_get_widget(GTK_UIMANAGER([self GOBJECT]), [path UTF8String])];
}

- (void)gtkUiManagerInsertActionGroupWithActionGroup:(GtkActionGroup*)actionGroup andPos:(gint)pos
{
	gtk_ui_manager_insert_action_group(GTK_UIMANAGER([self GOBJECT]), actionGroup, pos);
}

- (guint)gtkUiManagerNewMergeId
{
	return gtk_ui_manager_new_merge_id(GTK_UIMANAGER([self GOBJECT]));
}

- (void)gtkUiManagerRemoveActionGroup:(GtkActionGroup*)actionGroup
{
	gtk_ui_manager_remove_action_group(GTK_UIMANAGER([self GOBJECT]), actionGroup);
}

- (void)gtkUiManagerRemoveUi:(guint)mergeId
{
	gtk_ui_manager_remove_ui(GTK_UIMANAGER([self GOBJECT]), mergeId);
}

- (void)gtkUiManagerSetAddTearoffs:(bool)addTearoffs
{
	gtk_ui_manager_set_add_tearoffs(GTK_UIMANAGER([self GOBJECT]), addTearoffs);
}


@end