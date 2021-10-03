/*
 * OGTKCheckMenuItem.m
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
#import "OGTKCheckMenuItem.h"

@implementation OGTKCheckMenuItem

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_check_menu_item_new()];

	return self;
}

- (id)initWithLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_check_menu_item_new_with_label([label UTF8String])];

	return self;
}

- (id)initWithMnemonic:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_check_menu_item_new_with_mnemonic([label UTF8String])];

	return self;
}

- (GtkCheckMenuItem*)CHECKMENUITEM
{
	return GTK_CHECK_MENU_ITEM([self GOBJECT]);
}

- (bool)getActive
{
	return gtk_check_menu_item_get_active(GTK_CHECK_MENU_ITEM([self GOBJECT]));
}

- (bool)getDrawAsRadio
{
	return gtk_check_menu_item_get_draw_as_radio(GTK_CHECK_MENU_ITEM([self GOBJECT]));
}

- (bool)getInconsistent
{
	return gtk_check_menu_item_get_inconsistent(GTK_CHECK_MENU_ITEM([self GOBJECT]));
}

- (void)setActive:(bool)isActive
{
	gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM([self GOBJECT]), isActive);
}

- (void)setDrawAsRadio:(bool)drawAsRadio
{
	gtk_check_menu_item_set_draw_as_radio(GTK_CHECK_MENU_ITEM([self GOBJECT]), drawAsRadio);
}

- (void)setInconsistent:(bool)setting
{
	gtk_check_menu_item_set_inconsistent(GTK_CHECK_MENU_ITEM([self GOBJECT]), setting);
}

- (void)toggled
{
	gtk_check_menu_item_toggled(GTK_CHECK_MENU_ITEM([self GOBJECT]));
}


@end