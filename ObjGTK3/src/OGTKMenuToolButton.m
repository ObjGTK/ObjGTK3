/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenuToolButton.h"

#import "OGTKWidget.h"
#import "OGTKToolItem.h"

@implementation OGTKMenuToolButton

- (instancetype)initWithIconWidget:(OGTKWidget*)iconWidget label:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_menu_tool_button_new([iconWidget WIDGET], [label UTF8String])];

	return self;
}

- (instancetype)initFromStock:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_menu_tool_button_new_from_stock([stockId UTF8String])];

	return self;
}

- (GtkMenuToolButton*)MENUTOOLBUTTON
{
	return GTK_MENU_TOOL_BUTTON([self GOBJECT]);
}

- (OGTKWidget*)menu
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_tool_button_get_menu([self MENUTOOLBUTTON])] autorelease];
}

- (void)setArrowTooltipMarkup:(OFString*)markup
{
	gtk_menu_tool_button_set_arrow_tooltip_markup([self MENUTOOLBUTTON], [markup UTF8String]);
}

- (void)setArrowTooltipText:(OFString*)text
{
	gtk_menu_tool_button_set_arrow_tooltip_text([self MENUTOOLBUTTON], [text UTF8String]);
}

- (void)setMenu:(OGTKWidget*)menu
{
	gtk_menu_tool_button_set_menu([self MENUTOOLBUTTON], [menu WIDGET]);
}


@end