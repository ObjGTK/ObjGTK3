/*
 * OGTKUIManager.h
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

@interface OGTKUIManager : OGTKBase
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkUIManager*)UIMANAGER;

/**
 * - (void*)gtkUiManagerAddUiWithMergeId:(guint)mergeId andPath:(OFString*)path andName:(OFString*)name andAction:(OFString*)action andType:(GtkUIManagerItemType)type andTop:(bool)top;
 *
 * @param mergeId
 * @param path
 * @param name
 * @param action
 * @param type
 * @param top
 */
- (void)gtkUiManagerAddUiWithMergeId:(guint)mergeId andPath:(OFString*)path andName:(OFString*)name andAction:(OFString*)action andType:(GtkUIManagerItemType)type andTop:(bool)top;

/**
 * - (guint*)gtkUiManagerAddUiFromFile:(OFString*)filename;
 *
 * @param filename
 * @returns guint
 */
- (guint)gtkUiManagerAddUiFromFile:(OFString*)filename;

/**
 * - (guint*)gtkUiManagerAddUiFromResource:(OFString*)resourcePath;
 *
 * @param resourcePath
 * @returns guint
 */
- (guint)gtkUiManagerAddUiFromResource:(OFString*)resourcePath;

/**
 * - (guint*)gtkUiManagerAddUiFromStringWithBuffer:(OFString*)buffer andLength:(gssize)length;
 *
 * @param buffer
 * @param length
 * @returns guint
 */
- (guint)gtkUiManagerAddUiFromStringWithBuffer:(OFString*)buffer andLength:(gssize)length;

/**
 * - (void*)gtkUiManagerEnsureUpdate;
 *
 */
- (void)gtkUiManagerEnsureUpdate;

/**
 * - (GtkAccelGroup**)gtkUiManagerGetAccelGroup;
 *
 * @returns GtkAccelGroup*
 */
- (GtkAccelGroup*)gtkUiManagerGetAccelGroup;

/**
 * - (GtkAction**)gtkUiManagerGetAction:(OFString*)path;
 *
 * @param path
 * @returns GtkAction*
 */
- (GtkAction*)gtkUiManagerGetAction:(OFString*)path;

/**
 * - (GList**)gtkUiManagerGetActionGroups;
 *
 * @returns GList*
 */
- (GList*)gtkUiManagerGetActionGroups;

/**
 * - (bool*)gtkUiManagerGetAddTearoffs;
 *
 * @returns bool
 */
- (bool)gtkUiManagerGetAddTearoffs;

/**
 * - (GSList**)gtkUiManagerGetToplevels:(GtkUIManagerItemType)types;
 *
 * @param types
 * @returns GSList*
 */
- (GSList*)gtkUiManagerGetToplevels:(GtkUIManagerItemType)types;

/**
 * - (OFString**)gtkUiManagerGetUi;
 *
 * @returns OFString*
 */
- (OFString*)gtkUiManagerGetUi;

/**
 * - (OGTKWidget**)gtkUiManagerGetWidget:(OFString*)path;
 *
 * @param path
 * @returns OGTKWidget*
 */
- (OGTKWidget*)gtkUiManagerGetWidget:(OFString*)path;

/**
 * - (void*)gtkUiManagerInsertActionGroupWithActionGroup:(GtkActionGroup*)actionGroup andPos:(gint)pos;
 *
 * @param actionGroup
 * @param pos
 */
- (void)gtkUiManagerInsertActionGroupWithActionGroup:(GtkActionGroup*)actionGroup andPos:(gint)pos;

/**
 * - (guint*)gtkUiManagerNewMergeId;
 *
 * @returns guint
 */
- (guint)gtkUiManagerNewMergeId;

/**
 * - (void*)gtkUiManagerRemoveActionGroup:(GtkActionGroup*)actionGroup;
 *
 * @param actionGroup
 */
- (void)gtkUiManagerRemoveActionGroup:(GtkActionGroup*)actionGroup;

/**
 * - (void*)gtkUiManagerRemoveUi:(guint)mergeId;
 *
 * @param mergeId
 */
- (void)gtkUiManagerRemoveUi:(guint)mergeId;

/**
 * - (void*)gtkUiManagerSetAddTearoffs:(bool)addTearoffs;
 *
 * @param addTearoffs
 */
- (void)gtkUiManagerSetAddTearoffs:(bool)addTearoffs;

@end