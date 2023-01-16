/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSeparatorToolItem.h"

@implementation OGTKSeparatorToolItem

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_separator_tool_item_new()];

	return self;
}

- (GtkSeparatorToolItem*)SEPARATORTOOLITEM
{
	return GTK_SEPARATOR_TOOL_ITEM([self GOBJECT]);
}

- (bool)draw
{
	return gtk_separator_tool_item_get_draw([self SEPARATORTOOLITEM]);
}

- (void)setDraw:(bool)draw
{
	gtk_separator_tool_item_set_draw([self SEPARATORTOOLITEM], draw);
}


@end