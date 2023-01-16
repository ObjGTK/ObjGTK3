/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKImageMenuItem.h"

#import "OGTKWidget.h"
#import "OGTKAccelGroup.h"

@implementation OGTKImageMenuItem

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_image_menu_item_new()];

	return self;
}

- (instancetype)initFromStockWithStockId:(OFString*)stockId accelGroup:(OGTKAccelGroup*)accelGroup
{
	self = [super initWithGObject:(GObject*)gtk_image_menu_item_new_from_stock([stockId UTF8String], [accelGroup ACCELGROUP])];

	return self;
}

- (instancetype)initWithLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_image_menu_item_new_with_label([label UTF8String])];

	return self;
}

- (instancetype)initWithMnemonic:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_image_menu_item_new_with_mnemonic([label UTF8String])];

	return self;
}

- (GtkImageMenuItem*)IMAGEMENUITEM
{
	return GTK_IMAGE_MENU_ITEM([self GOBJECT]);
}

- (bool)alwaysShowImage
{
	return gtk_image_menu_item_get_always_show_image([self IMAGEMENUITEM]);
}

- (OGTKWidget*)image
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_image_menu_item_get_image([self IMAGEMENUITEM])] autorelease];
}

- (bool)useStock
{
	return gtk_image_menu_item_get_use_stock([self IMAGEMENUITEM]);
}

- (void)setAccelGroup:(OGTKAccelGroup*)accelGroup
{
	gtk_image_menu_item_set_accel_group([self IMAGEMENUITEM], [accelGroup ACCELGROUP]);
}

- (void)setAlwaysShowImage:(bool)alwaysShow
{
	gtk_image_menu_item_set_always_show_image([self IMAGEMENUITEM], alwaysShow);
}

- (void)setImage:(OGTKWidget*)image
{
	gtk_image_menu_item_set_image([self IMAGEMENUITEM], [image WIDGET]);
}

- (void)setUseStock:(bool)useStock
{
	gtk_image_menu_item_set_use_stock([self IMAGEMENUITEM], useStock);
}


@end