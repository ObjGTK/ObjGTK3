/*
 * OGTKMenuButton.m
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
#import "OGTKMenuButton.h"

@implementation OGTKMenuButton

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_menu_button_new()];

	return self;
}

- (GtkMenuButton*)MENUBUTTON
{
	return GTK_MENU_BUTTON([self GOBJECT]);
}

- (OGTKWidget*)getAlignWidget
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_button_get_align_widget(GTK_MENU_BUTTON([self GOBJECT]))];
}

- (GtkArrowType)getDirection
{
	return gtk_menu_button_get_direction(GTK_MENU_BUTTON([self GOBJECT]));
}

- (GMenuModel*)getMenuModel
{
	return gtk_menu_button_get_menu_model(GTK_MENU_BUTTON([self GOBJECT]));
}

- (GtkPopover*)getPopover
{
	return gtk_menu_button_get_popover(GTK_MENU_BUTTON([self GOBJECT]));
}

- (GtkMenu*)getPopup
{
	return gtk_menu_button_get_popup(GTK_MENU_BUTTON([self GOBJECT]));
}

- (bool)getUsePopover
{
	return gtk_menu_button_get_use_popover(GTK_MENU_BUTTON([self GOBJECT]));
}

- (void)setAlignWidget:(OGTKWidget*)alignWidget
{
	gtk_menu_button_set_align_widget(GTK_MENU_BUTTON([self GOBJECT]), [alignWidget WIDGET]);
}

- (void)setDirection:(GtkArrowType)direction
{
	gtk_menu_button_set_direction(GTK_MENU_BUTTON([self GOBJECT]), direction);
}

- (void)setMenuModel:(GMenuModel*)menuModel
{
	gtk_menu_button_set_menu_model(GTK_MENU_BUTTON([self GOBJECT]), menuModel);
}

- (void)setPopover:(OGTKWidget*)popover
{
	gtk_menu_button_set_popover(GTK_MENU_BUTTON([self GOBJECT]), [popover WIDGET]);
}

- (void)setPopup:(OGTKWidget*)menu
{
	gtk_menu_button_set_popup(GTK_MENU_BUTTON([self GOBJECT]), [menu WIDGET]);
}

- (void)setUsePopover:(bool)usePopover
{
	gtk_menu_button_set_use_popover(GTK_MENU_BUTTON([self GOBJECT]), usePopover);
}


@end