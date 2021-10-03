/*
 * OGTKToolPalette.h
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
#import "OGTKContainer.h"

@interface OGTKToolPalette : OGTKContainer
{

}

/**
 * Functions
 */
+ (const GtkTargetEntry*)getDragTargetGroup;
+ (const GtkTargetEntry*)getDragTargetItem;

/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkToolPalette*)TOOLPALETTE;

/**
 * - (void*)addDragDestWithWidget:(OGTKWidget*)widget andFlags:(GtkDestDefaults)flags andTargets:(GtkToolPaletteDragTargets)targets andActions:(GdkDragAction)actions;
 *
 * @param widget
 * @param flags
 * @param targets
 * @param actions
 */
- (void)addDragDestWithWidget:(OGTKWidget*)widget andFlags:(GtkDestDefaults)flags andTargets:(GtkToolPaletteDragTargets)targets andActions:(GdkDragAction)actions;

/**
 * - (OGTKWidget**)getDragItem:(const GtkSelectionData*)selection;
 *
 * @param selection
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getDragItem:(const GtkSelectionData*)selection;

/**
 * - (GtkToolItemGroup**)getDropGroupWithX:(gint)x andY:(gint)y;
 *
 * @param x
 * @param y
 * @returns GtkToolItemGroup*
 */
- (GtkToolItemGroup*)getDropGroupWithX:(gint)x andY:(gint)y;

/**
 * - (GtkToolItem**)getDropItemWithX:(gint)x andY:(gint)y;
 *
 * @param x
 * @param y
 * @returns GtkToolItem*
 */
- (GtkToolItem*)getDropItemWithX:(gint)x andY:(gint)y;

/**
 * - (bool*)getExclusive:(GtkToolItemGroup*)group;
 *
 * @param group
 * @returns bool
 */
- (bool)getExclusive:(GtkToolItemGroup*)group;

/**
 * - (bool*)getExpand:(GtkToolItemGroup*)group;
 *
 * @param group
 * @returns bool
 */
- (bool)getExpand:(GtkToolItemGroup*)group;

/**
 * - (gint*)getGroupPosition:(GtkToolItemGroup*)group;
 *
 * @param group
 * @returns gint
 */
- (gint)getGroupPosition:(GtkToolItemGroup*)group;

/**
 * - (GtkAdjustment**)getHadjustment;
 *
 * @returns GtkAdjustment*
 */
- (GtkAdjustment*)getHadjustment;

/**
 * - (GtkIconSize*)getIconSize;
 *
 * @returns GtkIconSize
 */
- (GtkIconSize)getIconSize;

/**
 * - (GtkToolbarStyle*)getStyle;
 *
 * @returns GtkToolbarStyle
 */
- (GtkToolbarStyle)getStyle;

/**
 * - (GtkAdjustment**)getVadjustment;
 *
 * @returns GtkAdjustment*
 */
- (GtkAdjustment*)getVadjustment;

/**
 * - (void*)setDragSource:(GtkToolPaletteDragTargets)targets;
 *
 * @param targets
 */
- (void)setDragSource:(GtkToolPaletteDragTargets)targets;

/**
 * - (void*)setExclusiveWithGroup:(GtkToolItemGroup*)group andExclusive:(bool)exclusive;
 *
 * @param group
 * @param exclusive
 */
- (void)setExclusiveWithGroup:(GtkToolItemGroup*)group andExclusive:(bool)exclusive;

/**
 * - (void*)setExpandWithGroup:(GtkToolItemGroup*)group andExpand:(bool)expand;
 *
 * @param group
 * @param expand
 */
- (void)setExpandWithGroup:(GtkToolItemGroup*)group andExpand:(bool)expand;

/**
 * - (void*)setGroupPositionWithGroup:(GtkToolItemGroup*)group andPosition:(gint)position;
 *
 * @param group
 * @param position
 */
- (void)setGroupPositionWithGroup:(GtkToolItemGroup*)group andPosition:(gint)position;

/**
 * - (void*)setIconSize:(GtkIconSize)iconSize;
 *
 * @param iconSize
 */
- (void)setIconSize:(GtkIconSize)iconSize;

/**
 * - (void*)setStyle:(GtkToolbarStyle)style;
 *
 * @param style
 */
- (void)setStyle:(GtkToolbarStyle)style;

/**
 * - (void*)unsetIconSize;
 *
 */
- (void)unsetIconSize;

/**
 * - (void*)unsetStyle;
 *
 */
- (void)unsetStyle;

@end