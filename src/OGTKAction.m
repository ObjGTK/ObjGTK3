/*
 * OGTKAction.m
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
#import "OGTKAction.h"

@implementation OGTKAction

- (id)initWithName:(OFString*)name andLabel:(OFString*)label andTooltip:(OFString*)tooltip andStockId:(OFString*)stockId
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
	gtk_action_activate(GTK_ACTION([self GOBJECT]));
}

- (void)blockActivate
{
	gtk_action_block_activate(GTK_ACTION([self GOBJECT]));
}

- (void)connectAccelerator
{
	gtk_action_connect_accelerator(GTK_ACTION([self GOBJECT]));
}

- (OGTKWidget*)createIcon:(GtkIconSize)iconSize
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_action_create_icon(GTK_ACTION([self GOBJECT]), iconSize)];
}

- (OGTKWidget*)createMenu
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_action_create_menu(GTK_ACTION([self GOBJECT]))];
}

- (OGTKWidget*)createMenuItem
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_action_create_menu_item(GTK_ACTION([self GOBJECT]))];
}

- (OGTKWidget*)createToolItem
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_action_create_tool_item(GTK_ACTION([self GOBJECT]))];
}

- (void)disconnectAccelerator
{
	gtk_action_disconnect_accelerator(GTK_ACTION([self GOBJECT]));
}

- (GClosure*)getAccelClosure
{
	return gtk_action_get_accel_closure(GTK_ACTION([self GOBJECT]));
}

- (OFString*)getAccelPath
{
	return [OFString stringWithUTF8String:gtk_action_get_accel_path(GTK_ACTION([self GOBJECT]))];
}

- (bool)getAlwaysShowImage
{
	return gtk_action_get_always_show_image(GTK_ACTION([self GOBJECT]));
}

- (GIcon*)getGicon
{
	return gtk_action_get_gicon(GTK_ACTION([self GOBJECT]));
}

- (OFString*)getIconName
{
	return [OFString stringWithUTF8String:gtk_action_get_icon_name(GTK_ACTION([self GOBJECT]))];
}

- (bool)getIsImportant
{
	return gtk_action_get_is_important(GTK_ACTION([self GOBJECT]));
}

- (OFString*)getLabel
{
	return [OFString stringWithUTF8String:gtk_action_get_label(GTK_ACTION([self GOBJECT]))];
}

- (OFString*)getName
{
	return [OFString stringWithUTF8String:gtk_action_get_name(GTK_ACTION([self GOBJECT]))];
}

- (GSList*)getProxies
{
	return gtk_action_get_proxies(GTK_ACTION([self GOBJECT]));
}

- (bool)getSensitive
{
	return gtk_action_get_sensitive(GTK_ACTION([self GOBJECT]));
}

- (OFString*)getShortLabel
{
	return [OFString stringWithUTF8String:gtk_action_get_short_label(GTK_ACTION([self GOBJECT]))];
}

- (OFString*)getStockId
{
	return [OFString stringWithUTF8String:gtk_action_get_stock_id(GTK_ACTION([self GOBJECT]))];
}

- (OFString*)getTooltip
{
	return [OFString stringWithUTF8String:gtk_action_get_tooltip(GTK_ACTION([self GOBJECT]))];
}

- (bool)getVisible
{
	return gtk_action_get_visible(GTK_ACTION([self GOBJECT]));
}

- (bool)getVisibleHorizontal
{
	return gtk_action_get_visible_horizontal(GTK_ACTION([self GOBJECT]));
}

- (bool)getVisibleVertical
{
	return gtk_action_get_visible_vertical(GTK_ACTION([self GOBJECT]));
}

- (bool)isSensitive
{
	return gtk_action_is_sensitive(GTK_ACTION([self GOBJECT]));
}

- (bool)isVisible
{
	return gtk_action_is_visible(GTK_ACTION([self GOBJECT]));
}

- (void)setAccelGroup:(GtkAccelGroup*)accelGroup
{
	gtk_action_set_accel_group(GTK_ACTION([self GOBJECT]), accelGroup);
}

- (void)setAccelPath:(OFString*)accelPath
{
	gtk_action_set_accel_path(GTK_ACTION([self GOBJECT]), [accelPath UTF8String]);
}

- (void)setAlwaysShowImage:(bool)alwaysShow
{
	gtk_action_set_always_show_image(GTK_ACTION([self GOBJECT]), alwaysShow);
}

- (void)setGicon:(GIcon*)icon
{
	gtk_action_set_gicon(GTK_ACTION([self GOBJECT]), icon);
}

- (void)setIconName:(OFString*)iconName
{
	gtk_action_set_icon_name(GTK_ACTION([self GOBJECT]), [iconName UTF8String]);
}

- (void)setIsImportant:(bool)isImportant
{
	gtk_action_set_is_important(GTK_ACTION([self GOBJECT]), isImportant);
}

- (void)setLabel:(OFString*)label
{
	gtk_action_set_label(GTK_ACTION([self GOBJECT]), [label UTF8String]);
}

- (void)setSensitive:(bool)sensitive
{
	gtk_action_set_sensitive(GTK_ACTION([self GOBJECT]), sensitive);
}

- (void)setShortLabel:(OFString*)shortLabel
{
	gtk_action_set_short_label(GTK_ACTION([self GOBJECT]), [shortLabel UTF8String]);
}

- (void)setStockId:(OFString*)stockId
{
	gtk_action_set_stock_id(GTK_ACTION([self GOBJECT]), [stockId UTF8String]);
}

- (void)setTooltip:(OFString*)tooltip
{
	gtk_action_set_tooltip(GTK_ACTION([self GOBJECT]), [tooltip UTF8String]);
}

- (void)setVisible:(bool)visible
{
	gtk_action_set_visible(GTK_ACTION([self GOBJECT]), visible);
}

- (void)setVisibleHorizontal:(bool)visibleHorizontal
{
	gtk_action_set_visible_horizontal(GTK_ACTION([self GOBJECT]), visibleHorizontal);
}

- (void)setVisibleVertical:(bool)visibleVertical
{
	gtk_action_set_visible_vertical(GTK_ACTION([self GOBJECT]), visibleVertical);
}

- (void)unblockActivate
{
	gtk_action_unblock_activate(GTK_ACTION([self GOBJECT]));
}


@end