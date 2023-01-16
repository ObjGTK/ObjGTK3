/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenuItem.h"

#import "OGTKWidget.h"

@implementation OGTKMenuItem

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_menu_item_new()];

	return self;
}

- (instancetype)initWithLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_menu_item_new_with_label([label UTF8String])];

	return self;
}

- (instancetype)initWithMnemonic:(OFString*)label
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
	gtk_menu_item_activate([self MENUITEM]);
}

- (void)deselect
{
	gtk_menu_item_deselect([self MENUITEM]);
}

- (OFString*)accelPath
{
	return [OFString stringWithUTF8String:gtk_menu_item_get_accel_path([self MENUITEM])];
}

- (OFString*)label
{
	return [OFString stringWithUTF8String:gtk_menu_item_get_label([self MENUITEM])];
}

- (bool)reserveIndicator
{
	return gtk_menu_item_get_reserve_indicator([self MENUITEM]);
}

- (bool)rightJustified
{
	return gtk_menu_item_get_right_justified([self MENUITEM]);
}

- (OGTKWidget*)submenu
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_item_get_submenu([self MENUITEM])] autorelease];
}

- (bool)useUnderline
{
	return gtk_menu_item_get_use_underline([self MENUITEM]);
}

- (void)select
{
	gtk_menu_item_select([self MENUITEM]);
}

- (void)setAccelPath:(OFString*)accelPath
{
	gtk_menu_item_set_accel_path([self MENUITEM], [accelPath UTF8String]);
}

- (void)setLabel:(OFString*)label
{
	gtk_menu_item_set_label([self MENUITEM], [label UTF8String]);
}

- (void)setReserveIndicator:(bool)reserve
{
	gtk_menu_item_set_reserve_indicator([self MENUITEM], reserve);
}

- (void)setRightJustified:(bool)rightJustified
{
	gtk_menu_item_set_right_justified([self MENUITEM], rightJustified);
}

- (void)setSubmenu:(OGTKWidget*)submenu
{
	gtk_menu_item_set_submenu([self MENUITEM], [submenu WIDGET]);
}

- (void)setUseUnderline:(bool)setting
{
	gtk_menu_item_set_use_underline([self MENUITEM], setting);
}

- (void)toggleSizeAllocate:(gint)allocation
{
	gtk_menu_item_toggle_size_allocate([self MENUITEM], allocation);
}

- (void)toggleSizeRequest:(gint*)requisition
{
	gtk_menu_item_toggle_size_request([self MENUITEM], requisition);
}


@end