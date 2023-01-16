/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToolButton.h"

#import "OGTKWidget.h"

@implementation OGTKToolButton

- (instancetype)initWithIconWidget:(OGTKWidget*)iconWidget label:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_tool_button_new([iconWidget WIDGET], [label UTF8String])];

	return self;
}

- (instancetype)initFromStock:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_tool_button_new_from_stock([stockId UTF8String])];

	return self;
}

- (GtkToolButton*)TOOLBUTTON
{
	return GTK_TOOL_BUTTON([self GOBJECT]);
}

- (OFString*)iconName
{
	return [OFString stringWithUTF8String:gtk_tool_button_get_icon_name([self TOOLBUTTON])];
}

- (OGTKWidget*)iconWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tool_button_get_icon_widget([self TOOLBUTTON])] autorelease];
}

- (OFString*)label
{
	return [OFString stringWithUTF8String:gtk_tool_button_get_label([self TOOLBUTTON])];
}

- (OGTKWidget*)labelWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tool_button_get_label_widget([self TOOLBUTTON])] autorelease];
}

- (OFString*)stockId
{
	return [OFString stringWithUTF8String:gtk_tool_button_get_stock_id([self TOOLBUTTON])];
}

- (bool)useUnderline
{
	return gtk_tool_button_get_use_underline([self TOOLBUTTON]);
}

- (void)setIconName:(OFString*)iconName
{
	gtk_tool_button_set_icon_name([self TOOLBUTTON], [iconName UTF8String]);
}

- (void)setIconWidget:(OGTKWidget*)iconWidget
{
	gtk_tool_button_set_icon_widget([self TOOLBUTTON], [iconWidget WIDGET]);
}

- (void)setLabel:(OFString*)label
{
	gtk_tool_button_set_label([self TOOLBUTTON], [label UTF8String]);
}

- (void)setLabelWidget:(OGTKWidget*)labelWidget
{
	gtk_tool_button_set_label_widget([self TOOLBUTTON], [labelWidget WIDGET]);
}

- (void)setStockId:(OFString*)stockId
{
	gtk_tool_button_set_stock_id([self TOOLBUTTON], [stockId UTF8String]);
}

- (void)setUseUnderline:(bool)useUnderline
{
	gtk_tool_button_set_use_underline([self TOOLBUTTON], useUnderline);
}


@end