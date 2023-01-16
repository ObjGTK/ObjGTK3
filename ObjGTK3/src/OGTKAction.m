/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAction.h"

#import "OGTKAccelGroup.h"
#import "OGTKWidget.h"

@implementation OGTKAction

- (instancetype)initWithName:(OFString*)name label:(OFString*)label tooltip:(OFString*)tooltip stockId:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_action_new([name UTF8String], [label UTF8String], [tooltip UTF8String], [stockId UTF8String])];

	return self;
}

- (GtkAction*)ACTION
{
	return GTK_ACTION([self GOBJECT]);
}

- (void)activate
{
	gtk_action_activate([self ACTION]);
}

- (void)blockActivate
{
	gtk_action_block_activate([self ACTION]);
}

- (void)connectAccelerator
{
	gtk_action_connect_accelerator([self ACTION]);
}

- (OGTKWidget*)createIcon:(GtkIconSize)iconSize
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_action_create_icon([self ACTION], iconSize)] autorelease];
}

- (OGTKWidget*)createMenu
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_action_create_menu([self ACTION])] autorelease];
}

- (OGTKWidget*)createMenuItem
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_action_create_menu_item([self ACTION])] autorelease];
}

- (OGTKWidget*)createToolItem
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_action_create_tool_item([self ACTION])] autorelease];
}

- (void)disconnectAccelerator
{
	gtk_action_disconnect_accelerator([self ACTION]);
}

- (GClosure*)accelClosure
{
	return gtk_action_get_accel_closure([self ACTION]);
}

- (OFString*)accelPath
{
	return [OFString stringWithUTF8String:gtk_action_get_accel_path([self ACTION])];
}

- (bool)alwaysShowImage
{
	return gtk_action_get_always_show_image([self ACTION]);
}

- (GIcon*)gicon
{
	return gtk_action_get_gicon([self ACTION]);
}

- (OFString*)iconName
{
	return [OFString stringWithUTF8String:gtk_action_get_icon_name([self ACTION])];
}

- (bool)isImportant
{
	return gtk_action_get_is_important([self ACTION]);
}

- (OFString*)label
{
	return [OFString stringWithUTF8String:gtk_action_get_label([self ACTION])];
}

- (OFString*)name
{
	return [OFString stringWithUTF8String:gtk_action_get_name([self ACTION])];
}

- (GSList*)proxies
{
	return gtk_action_get_proxies([self ACTION]);
}

- (bool)sensitive
{
	return gtk_action_get_sensitive([self ACTION]);
}

- (OFString*)shortLabel
{
	return [OFString stringWithUTF8String:gtk_action_get_short_label([self ACTION])];
}

- (OFString*)stockId
{
	return [OFString stringWithUTF8String:gtk_action_get_stock_id([self ACTION])];
}

- (OFString*)tooltip
{
	return [OFString stringWithUTF8String:gtk_action_get_tooltip([self ACTION])];
}

- (bool)visible
{
	return gtk_action_get_visible([self ACTION]);
}

- (bool)visibleHorizontal
{
	return gtk_action_get_visible_horizontal([self ACTION]);
}

- (bool)visibleVertical
{
	return gtk_action_get_visible_vertical([self ACTION]);
}

- (bool)isSensitive
{
	return gtk_action_is_sensitive([self ACTION]);
}

- (bool)isVisible
{
	return gtk_action_is_visible([self ACTION]);
}

- (void)setAccelGroup:(OGTKAccelGroup*)accelGroup
{
	gtk_action_set_accel_group([self ACTION], [accelGroup ACCELGROUP]);
}

- (void)setAccelPath:(OFString*)accelPath
{
	gtk_action_set_accel_path([self ACTION], [accelPath UTF8String]);
}

- (void)setAlwaysShowImage:(bool)alwaysShow
{
	gtk_action_set_always_show_image([self ACTION], alwaysShow);
}

- (void)setGicon:(GIcon*)icon
{
	gtk_action_set_gicon([self ACTION], icon);
}

- (void)setIconName:(OFString*)iconName
{
	gtk_action_set_icon_name([self ACTION], [iconName UTF8String]);
}

- (void)setIsImportant:(bool)isImportant
{
	gtk_action_set_is_important([self ACTION], isImportant);
}

- (void)setLabel:(OFString*)label
{
	gtk_action_set_label([self ACTION], [label UTF8String]);
}

- (void)setSensitive:(bool)sensitive
{
	gtk_action_set_sensitive([self ACTION], sensitive);
}

- (void)setShortLabel:(OFString*)shortLabel
{
	gtk_action_set_short_label([self ACTION], [shortLabel UTF8String]);
}

- (void)setStockId:(OFString*)stockId
{
	gtk_action_set_stock_id([self ACTION], [stockId UTF8String]);
}

- (void)setTooltip:(OFString*)tooltip
{
	gtk_action_set_tooltip([self ACTION], [tooltip UTF8String]);
}

- (void)setVisible:(bool)visible
{
	gtk_action_set_visible([self ACTION], visible);
}

- (void)setVisibleHorizontal:(bool)visibleHorizontal
{
	gtk_action_set_visible_horizontal([self ACTION], visibleHorizontal);
}

- (void)setVisibleVertical:(bool)visibleVertical
{
	gtk_action_set_visible_vertical([self ACTION], visibleVertical);
}

- (void)unblockActivate
{
	gtk_action_unblock_activate([self ACTION]);
}


@end