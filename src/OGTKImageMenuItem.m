/*
 * OGTKImageMenuItem.m
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
#import "OGTKImageMenuItem.h"

@implementation OGTKImageMenuItem

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_image_menu_item_new()];

	return self;
}

- (id)initFromStockWithStockId:(OFString*)stockId andAccelGroup:(GtkAccelGroup*)accelGroup
{
	self = [super initWithGObject:(GObject*)gtk_image_menu_item_new_from_stock([stockId UTF8String], accelGroup)];

	return self;
}

- (id)initWithLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_image_menu_item_new_with_label([label UTF8String])];

	return self;
}

- (id)initWithMnemonic:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_image_menu_item_new_with_mnemonic([label UTF8String])];

	return self;
}

- (GtkImageMenuItem*)IMAGEMENUITEM
{
	return GTK_IMAGE_MENU_ITEM([self GOBJECT]);
}

- (bool)getAlwaysShowImage
{
	return gtk_image_menu_item_get_always_show_image(GTK_IMAGE_MENU_ITEM([self GOBJECT]));
}

- (OGTKWidget*)getImage
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_image_menu_item_get_image(GTK_IMAGE_MENU_ITEM([self GOBJECT]))];
}

- (bool)getUseStock
{
	return gtk_image_menu_item_get_use_stock(GTK_IMAGE_MENU_ITEM([self GOBJECT]));
}

- (void)setAccelGroup:(GtkAccelGroup*)accelGroup
{
	gtk_image_menu_item_set_accel_group(GTK_IMAGE_MENU_ITEM([self GOBJECT]), accelGroup);
}

- (void)setAlwaysShowImage:(bool)alwaysShow
{
	gtk_image_menu_item_set_always_show_image(GTK_IMAGE_MENU_ITEM([self GOBJECT]), alwaysShow);
}

- (void)setImage:(OGTKWidget*)image
{
	gtk_image_menu_item_set_image(GTK_IMAGE_MENU_ITEM([self GOBJECT]), [image WIDGET]);
}

- (void)setUseStock:(bool)useStock
{
	gtk_image_menu_item_set_use_stock(GTK_IMAGE_MENU_ITEM([self GOBJECT]), useStock);
}


@end