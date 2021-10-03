/*
 * OGTKToolPalette.m
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
#import "OGTKToolPalette.h"

@implementation OGTKToolPalette

+ (const GtkTargetEntry*)getDragTargetGroup
{
	return gtk_tool_palette_get_drag_target_group();
}

+ (const GtkTargetEntry*)getDragTargetItem
{
	return gtk_tool_palette_get_drag_target_item();
}

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_tool_palette_new()];

	return self;
}

- (GtkToolPalette*)TOOLPALETTE
{
	return GTK_TOOL_PALETTE([self GOBJECT]);
}

- (void)addDragDestWithWidget:(OGTKWidget*)widget andFlags:(GtkDestDefaults)flags andTargets:(GtkToolPaletteDragTargets)targets andActions:(GdkDragAction)actions
{
	gtk_tool_palette_add_drag_dest(GTK_TOOL_PALETTE([self GOBJECT]), [widget WIDGET], flags, targets, actions);
}

- (OGTKWidget*)getDragItem:(const GtkSelectionData*)selection
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tool_palette_get_drag_item(GTK_TOOL_PALETTE([self GOBJECT]), selection)];
}

- (GtkToolItemGroup*)getDropGroupWithX:(gint)x andY:(gint)y
{
	return gtk_tool_palette_get_drop_group(GTK_TOOL_PALETTE([self GOBJECT]), x, y);
}

- (GtkToolItem*)getDropItemWithX:(gint)x andY:(gint)y
{
	return gtk_tool_palette_get_drop_item(GTK_TOOL_PALETTE([self GOBJECT]), x, y);
}

- (bool)getExclusive:(GtkToolItemGroup*)group
{
	return gtk_tool_palette_get_exclusive(GTK_TOOL_PALETTE([self GOBJECT]), group);
}

- (bool)getExpand:(GtkToolItemGroup*)group
{
	return gtk_tool_palette_get_expand(GTK_TOOL_PALETTE([self GOBJECT]), group);
}

- (gint)getGroupPosition:(GtkToolItemGroup*)group
{
	return gtk_tool_palette_get_group_position(GTK_TOOL_PALETTE([self GOBJECT]), group);
}

- (GtkAdjustment*)getHadjustment
{
	return gtk_tool_palette_get_hadjustment(GTK_TOOL_PALETTE([self GOBJECT]));
}

- (GtkIconSize)getIconSize
{
	return gtk_tool_palette_get_icon_size(GTK_TOOL_PALETTE([self GOBJECT]));
}

- (GtkToolbarStyle)getStyle
{
	return gtk_tool_palette_get_style(GTK_TOOL_PALETTE([self GOBJECT]));
}

- (GtkAdjustment*)getVadjustment
{
	return gtk_tool_palette_get_vadjustment(GTK_TOOL_PALETTE([self GOBJECT]));
}

- (void)setDragSource:(GtkToolPaletteDragTargets)targets
{
	gtk_tool_palette_set_drag_source(GTK_TOOL_PALETTE([self GOBJECT]), targets);
}

- (void)setExclusiveWithGroup:(GtkToolItemGroup*)group andExclusive:(bool)exclusive
{
	gtk_tool_palette_set_exclusive(GTK_TOOL_PALETTE([self GOBJECT]), group, exclusive);
}

- (void)setExpandWithGroup:(GtkToolItemGroup*)group andExpand:(bool)expand
{
	gtk_tool_palette_set_expand(GTK_TOOL_PALETTE([self GOBJECT]), group, expand);
}

- (void)setGroupPositionWithGroup:(GtkToolItemGroup*)group andPosition:(gint)position
{
	gtk_tool_palette_set_group_position(GTK_TOOL_PALETTE([self GOBJECT]), group, position);
}

- (void)setIconSize:(GtkIconSize)iconSize
{
	gtk_tool_palette_set_icon_size(GTK_TOOL_PALETTE([self GOBJECT]), iconSize);
}

- (void)setStyle:(GtkToolbarStyle)style
{
	gtk_tool_palette_set_style(GTK_TOOL_PALETTE([self GOBJECT]), style);
}

- (void)unsetIconSize
{
	gtk_tool_palette_unset_icon_size(GTK_TOOL_PALETTE([self GOBJECT]));
}

- (void)unsetStyle
{
	gtk_tool_palette_unset_style(GTK_TOOL_PALETTE([self GOBJECT]));
}


@end