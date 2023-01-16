/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCheckMenuItem.h"

#import "OGTKWidget.h"

@implementation OGTKCheckMenuItem

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_check_menu_item_new()];

	return self;
}

- (instancetype)initWithLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_check_menu_item_new_with_label([label UTF8String])];

	return self;
}

- (instancetype)initWithMnemonic:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_check_menu_item_new_with_mnemonic([label UTF8String])];

	return self;
}

- (GtkCheckMenuItem*)CHECKMENUITEM
{
	return GTK_CHECK_MENU_ITEM([self GOBJECT]);
}

- (bool)active
{
	return gtk_check_menu_item_get_active([self CHECKMENUITEM]);
}

- (bool)drawAsRadio
{
	return gtk_check_menu_item_get_draw_as_radio([self CHECKMENUITEM]);
}

- (bool)inconsistent
{
	return gtk_check_menu_item_get_inconsistent([self CHECKMENUITEM]);
}

- (void)setActive:(bool)isActive
{
	gtk_check_menu_item_set_active([self CHECKMENUITEM], isActive);
}

- (void)setDrawAsRadio:(bool)drawAsRadio
{
	gtk_check_menu_item_set_draw_as_radio([self CHECKMENUITEM], drawAsRadio);
}

- (void)setInconsistent:(bool)setting
{
	gtk_check_menu_item_set_inconsistent([self CHECKMENUITEM], setting);
}

- (void)toggled
{
	gtk_check_menu_item_toggled([self CHECKMENUITEM]);
}


@end