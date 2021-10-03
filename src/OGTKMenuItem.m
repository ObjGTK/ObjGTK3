/*
 * OGTKMenuItem.m
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
#import "OGTKMenuItem.h"

@implementation OGTKMenuItem

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_menu_item_new()];

	return self;
}

- (id)initWithLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_menu_item_new_with_label([label UTF8String])];

	return self;
}

- (id)initWithMnemonic:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_menu_item_new_with_mnemonic([label UTF8String])];

	return self;
}

- (GtkMenuItem*)MENUITEM
{
	return GTK_MENU_ITEM([self GOBJECT]);
}

- (void)activate
{
	gtk_menu_item_activate(GTK_MENU_ITEM([self GOBJECT]));
}

- (void)deselect
{
	gtk_menu_item_deselect(GTK_MENU_ITEM([self GOBJECT]));
}

- (OFString*)getAccelPath
{
	return [OFString stringWithUTF8String:gtk_menu_item_get_accel_path(GTK_MENU_ITEM([self GOBJECT]))];
}

- (OFString*)getLabel
{
	return [OFString stringWithUTF8String:gtk_menu_item_get_label(GTK_MENU_ITEM([self GOBJECT]))];
}

- (bool)getReserveIndicator
{
	return gtk_menu_item_get_reserve_indicator(GTK_MENU_ITEM([self GOBJECT]));
}

- (bool)getRightJustified
{
	return gtk_menu_item_get_right_justified(GTK_MENU_ITEM([self GOBJECT]));
}

- (OGTKWidget*)getSubmenu
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_item_get_submenu(GTK_MENU_ITEM([self GOBJECT]))];
}

- (bool)getUseUnderline
{
	return gtk_menu_item_get_use_underline(GTK_MENU_ITEM([self GOBJECT]));
}

- (void)select
{
	gtk_menu_item_select(GTK_MENU_ITEM([self GOBJECT]));
}

- (void)setAccelPath:(OFString*)accelPath
{
	gtk_menu_item_set_accel_path(GTK_MENU_ITEM([self GOBJECT]), [accelPath UTF8String]);
}

- (void)setLabel:(OFString*)label
{
	gtk_menu_item_set_label(GTK_MENU_ITEM([self GOBJECT]), [label UTF8String]);
}

- (void)setReserveIndicator:(bool)reserve
{
	gtk_menu_item_set_reserve_indicator(GTK_MENU_ITEM([self GOBJECT]), reserve);
}

- (void)setRightJustified:(bool)rightJustified
{
	gtk_menu_item_set_right_justified(GTK_MENU_ITEM([self GOBJECT]), rightJustified);
}

- (void)setSubmenu:(OGTKWidget*)submenu
{
	gtk_menu_item_set_submenu(GTK_MENU_ITEM([self GOBJECT]), [submenu WIDGET]);
}

- (void)setUseUnderline:(bool)setting
{
	gtk_menu_item_set_use_underline(GTK_MENU_ITEM([self GOBJECT]), setting);
}

- (void)toggleSizeAllocate:(gint)allocation
{
	gtk_menu_item_toggle_size_allocate(GTK_MENU_ITEM([self GOBJECT]), allocation);
}

- (void)toggleSizeRequest:(gint*)requisition
{
	gtk_menu_item_toggle_size_request(GTK_MENU_ITEM([self GOBJECT]), requisition);
}


@end