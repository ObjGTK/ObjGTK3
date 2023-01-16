/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenuBar.h"

#import "OGTKWidget.h"

@implementation OGTKMenuBar

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_menu_bar_new()];

	return self;
}

- (instancetype)initFromModel:(GMenuModel*)model
{
	self = [super initWithGObject:(GObject*)gtk_menu_bar_new_from_model(model)];

	return self;
}

- (GtkMenuBar*)MENUBAR
{
	return GTK_MENU_BAR([self GOBJECT]);
}

- (GtkPackDirection)childPackDirection
{
	return gtk_menu_bar_get_child_pack_direction([self MENUBAR]);
}

- (GtkPackDirection)packDirection
{
	return gtk_menu_bar_get_pack_direction([self MENUBAR]);
}

- (void)setChildPackDirection:(GtkPackDirection)childPackDir
{
	gtk_menu_bar_set_child_pack_direction([self MENUBAR], childPackDir);
}

- (void)setPackDirection:(GtkPackDirection)packDir
{
	gtk_menu_bar_set_pack_direction([self MENUBAR], packDir);
}


@end