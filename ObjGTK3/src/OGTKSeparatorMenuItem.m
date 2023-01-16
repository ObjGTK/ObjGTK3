/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSeparatorMenuItem.h"

#import "OGTKWidget.h"

@implementation OGTKSeparatorMenuItem

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_separator_menu_item_new()];

	return self;
}

- (GtkSeparatorMenuItem*)SEPARATORMENUITEM
{
	return GTK_SEPARATOR_MENU_ITEM([self GOBJECT]);
}


@end