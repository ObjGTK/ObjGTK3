/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToolPalette.h"

#import "OGTKAdjustment.h"
#import "OGTKWidget.h"
#import "OGTKToolItemGroup.h"
#import "OGTKToolItem.h"

@implementation OGTKToolPalette

+ (const GtkTargetEntry*)dragTargetGroup
{
	return gtk_tool_palette_get_drag_target_group();
}

+ (const GtkTargetEntry*)dragTargetItem
{
	return gtk_tool_palette_get_drag_target_item();
}

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_tool_palette_new()];

	return self;
}

- (GtkToolPalette*)TOOLPALETTE
{
	return GTK_TOOL_PALETTE([self GOBJECT]);
}

- (void)addDragDestWithWidget:(OGTKWidget*)widget flags:(GtkDestDefaults)flags targets:(GtkToolPaletteDragTargets)targets actions:(GdkDragAction)actions
{
	gtk_tool_palette_add_drag_dest([self TOOLPALETTE], [widget WIDGET], flags, targets, actions);
}

- (OGTKWidget*)dragItem:(const GtkSelectionData*)selection
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tool_palette_get_drag_item([self TOOLPALETTE], selection)] autorelease];
}

- (OGTKToolItemGroup*)dropGroupWithX:(gint)x y:(gint)y
{
	return [[[OGTKToolItemGroup alloc] initWithGObject:(GObject*)gtk_tool_palette_get_drop_group([self TOOLPALETTE], x, y)] autorelease];
}

- (OGTKToolItem*)dropItemWithX:(gint)x y:(gint)y
{
	return [[[OGTKToolItem alloc] initWithGObject:(GObject*)gtk_tool_palette_get_drop_item([self TOOLPALETTE], x, y)] autorelease];
}

- (bool)exclusive:(OGTKToolItemGroup*)group
{
	return gtk_tool_palette_get_exclusive([self TOOLPALETTE], [group TOOLITEMGROUP]);
}

- (bool)expand:(OGTKToolItemGroup*)group
{
	return gtk_tool_palette_get_expand([self TOOLPALETTE], [group TOOLITEMGROUP]);
}

- (gint)groupPosition:(OGTKToolItemGroup*)group
{
	return gtk_tool_palette_get_group_position([self TOOLPALETTE], [group TOOLITEMGROUP]);
}

- (OGTKAdjustment*)hadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_tool_palette_get_hadjustment([self TOOLPALETTE])] autorelease];
}

- (GtkIconSize)iconSize
{
	return gtk_tool_palette_get_icon_size([self TOOLPALETTE]);
}

- (GtkToolbarStyle)style
{
	return gtk_tool_palette_get_style([self TOOLPALETTE]);
}

- (OGTKAdjustment*)vadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_tool_palette_get_vadjustment([self TOOLPALETTE])] autorelease];
}

- (void)setDragSource:(GtkToolPaletteDragTargets)targets
{
	gtk_tool_palette_set_drag_source([self TOOLPALETTE], targets);
}

- (void)setExclusiveWithGroup:(OGTKToolItemGroup*)group exclusive:(bool)exclusive
{
	gtk_tool_palette_set_exclusive([self TOOLPALETTE], [group TOOLITEMGROUP], exclusive);
}

- (void)setExpandWithGroup:(OGTKToolItemGroup*)group expand:(bool)expand
{
	gtk_tool_palette_set_expand([self TOOLPALETTE], [group TOOLITEMGROUP], expand);
}

- (void)setGroupPositionWithGroup:(OGTKToolItemGroup*)group position:(gint)position
{
	gtk_tool_palette_set_group_position([self TOOLPALETTE], [group TOOLITEMGROUP], position);
}

- (void)setIconSize:(GtkIconSize)iconSize
{
	gtk_tool_palette_set_icon_size([self TOOLPALETTE], iconSize);
}

- (void)setStyle:(GtkToolbarStyle)style
{
	gtk_tool_palette_set_style([self TOOLPALETTE], style);
}

- (void)unsetIconSize
{
	gtk_tool_palette_unset_icon_size([self TOOLPALETTE]);
}

- (void)unsetStyle
{
	gtk_tool_palette_unset_style([self TOOLPALETTE]);
}


@end