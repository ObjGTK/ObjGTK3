/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTearoffMenuItem.h"

#import "OGTKWidget.h"

@implementation OGTKTearoffMenuItem

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_tearoff_menu_item_new()];

	return self;
}

- (GtkTearoffMenuItem*)TEAROFFMENUITEM
{
	return GTK_TEAROFF_MENU_ITEM([self GOBJECT]);
}


@end