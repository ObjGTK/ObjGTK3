/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPopoverMenu.h"

#import "OGTKWidget.h"

@implementation OGTKPopoverMenu

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_popover_menu_new()];

	return self;
}

- (GtkPopoverMenu*)POPOVERMENU
{
	return GTK_POPOVER_MENU([self GOBJECT]);
}

- (void)openSubmenu:(OFString*)name
{
	gtk_popover_menu_open_submenu([self POPOVERMENU], [name UTF8String]);
}


@end