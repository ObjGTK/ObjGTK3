/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToolItem.h"

#import "OGTKWidget.h"
#import "OGTKSizeGroup.h"

@implementation OGTKToolItem

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_tool_item_new()];

	return self;
}

- (GtkToolItem*)TOOLITEM
{
	return GTK_TOOL_ITEM([self GOBJECT]);
}

- (PangoEllipsizeMode)ellipsizeMode
{
	return gtk_tool_item_get_ellipsize_mode([self TOOLITEM]);
}

- (bool)expand
{
	return gtk_tool_item_get_expand([self TOOLITEM]);
}

- (bool)homogeneous
{
	return gtk_tool_item_get_homogeneous([self TOOLITEM]);
}

- (GtkIconSize)iconSize
{
	return gtk_tool_item_get_icon_size([self TOOLITEM]);
}

- (bool)isImportant
{
	return gtk_tool_item_get_is_important([self TOOLITEM]);
}

- (GtkOrientation)orientation
{
	return gtk_tool_item_get_orientation([self TOOLITEM]);
}

- (OGTKWidget*)proxyMenuItem:(OFString*)menuItemId
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tool_item_get_proxy_menu_item([self TOOLITEM], [menuItemId UTF8String])] autorelease];
}

- (GtkReliefStyle)reliefStyle
{
	return gtk_tool_item_get_relief_style([self TOOLITEM]);
}

- (gfloat)textAlignment
{
	return gtk_tool_item_get_text_alignment([self TOOLITEM]);
}

- (GtkOrientation)textOrientation
{
	return gtk_tool_item_get_text_orientation([self TOOLITEM]);
}

- (OGTKSizeGroup*)textSizeGroup
{
	return [[[OGTKSizeGroup alloc] initWithGObject:(GObject*)gtk_tool_item_get_text_size_group([self TOOLITEM])] autorelease];
}

- (GtkToolbarStyle)toolbarStyle
{
	return gtk_tool_item_get_toolbar_style([self TOOLITEM]);
}

- (bool)useDragWindow
{
	return gtk_tool_item_get_use_drag_window([self TOOLITEM]);
}

- (bool)visibleHorizontal
{
	return gtk_tool_item_get_visible_horizontal([self TOOLITEM]);
}

- (bool)visibleVertical
{
	return gtk_tool_item_get_visible_vertical([self TOOLITEM]);
}

- (void)rebuildMenu
{
	gtk_tool_item_rebuild_menu([self TOOLITEM]);
}

- (OGTKWidget*)retrieveProxyMenuItem
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tool_item_retrieve_proxy_menu_item([self TOOLITEM])] autorelease];
}

- (void)setExpand:(bool)expand
{
	gtk_tool_item_set_expand([self TOOLITEM], expand);
}

- (void)setHomogeneous:(bool)homogeneous
{
	gtk_tool_item_set_homogeneous([self TOOLITEM], homogeneous);
}

- (void)setIsImportant:(bool)isImportant
{
	gtk_tool_item_set_is_important([self TOOLITEM], isImportant);
}

- (void)setProxyMenuItemWithMenuItemId:(OFString*)menuItemId menuItem:(OGTKWidget*)menuItem
{
	gtk_tool_item_set_proxy_menu_item([self TOOLITEM], [menuItemId UTF8String], [menuItem WIDGET]);
}

- (void)setTooltipMarkup:(OFString*)markup
{
	gtk_tool_item_set_tooltip_markup([self TOOLITEM], [markup UTF8String]);
}

- (void)setTooltipText:(OFString*)text
{
	gtk_tool_item_set_tooltip_text([self TOOLITEM], [text UTF8String]);
}

- (void)setUseDragWindow:(bool)useDragWindow
{
	gtk_tool_item_set_use_drag_window([self TOOLITEM], useDragWindow);
}

- (void)setVisibleHorizontal:(bool)visibleHorizontal
{
	gtk_tool_item_set_visible_horizontal([self TOOLITEM], visibleHorizontal);
}

- (void)setVisibleVertical:(bool)visibleVertical
{
	gtk_tool_item_set_visible_vertical([self TOOLITEM], visibleVertical);
}

- (void)toolbarReconfigured
{
	gtk_tool_item_toolbar_reconfigured([self TOOLITEM]);
}


@end