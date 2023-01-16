/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToggleToolButton.h"

#import "OGTKToolItem.h"

@implementation OGTKToggleToolButton

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_toggle_tool_button_new()];

	return self;
}

- (instancetype)initFromStock:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_toggle_tool_button_new_from_stock([stockId UTF8String])];

	return self;
}

- (GtkToggleToolButton*)TOGGLETOOLBUTTON
{
	return GTK_TOGGLE_TOOL_BUTTON([self GOBJECT]);
}

- (bool)active
{
	return gtk_toggle_tool_button_get_active([self TOGGLETOOLBUTTON]);
}

- (void)setActive:(bool)isActive
{
	gtk_toggle_tool_button_set_active([self TOGGLETOOLBUTTON], isActive);
}


@end