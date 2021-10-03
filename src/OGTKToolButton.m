/*
 * OGTKToolButton.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKToolButton.h"

@implementation OGTKToolButton

- (id)initWithIconWidget:(OGTKWidget*)iconWidget andLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_tool_button_new([iconWidget WIDGET], [label UTF8String])];

	return self;
}

- (id)initFromStock:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_tool_button_new_from_stock([stockId UTF8String])];

	return self;
}

- (GtkToolButton*)TOOLBUTTON
{
	return GTK_TOOL_BUTTON([self GOBJECT]);
}

- (OFString*)getIconName
{
	return [OFString stringWithUTF8String:gtk_tool_button_get_icon_name(GTK_TOOL_BUTTON([self GOBJECT]))];
}

- (OGTKWidget*)getIconWidget
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tool_button_get_icon_widget(GTK_TOOL_BUTTON([self GOBJECT]))];
}

- (OFString*)getLabel
{
	return [OFString stringWithUTF8String:gtk_tool_button_get_label(GTK_TOOL_BUTTON([self GOBJECT]))];
}

- (OGTKWidget*)getLabelWidget
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tool_button_get_label_widget(GTK_TOOL_BUTTON([self GOBJECT]))];
}

- (OFString*)getStockId
{
	return [OFString stringWithUTF8String:gtk_tool_button_get_stock_id(GTK_TOOL_BUTTON([self GOBJECT]))];
}

- (bool)getUseUnderline
{
	return gtk_tool_button_get_use_underline(GTK_TOOL_BUTTON([self GOBJECT]));
}

- (void)setIconName:(OFString*)iconName
{
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON([self GOBJECT]), [iconName UTF8String]);
}

- (void)setIconWidget:(OGTKWidget*)iconWidget
{
	gtk_tool_button_set_icon_widget(GTK_TOOL_BUTTON([self GOBJECT]), [iconWidget WIDGET]);
}

- (void)setLabel:(OFString*)label
{
	gtk_tool_button_set_label(GTK_TOOL_BUTTON([self GOBJECT]), [label UTF8String]);
}

- (void)setLabelWidget:(OGTKWidget*)labelWidget
{
	gtk_tool_button_set_label_widget(GTK_TOOL_BUTTON([self GOBJECT]), [labelWidget WIDGET]);
}

- (void)setStockId:(OFString*)stockId
{
	gtk_tool_button_set_stock_id(GTK_TOOL_BUTTON([self GOBJECT]), [stockId UTF8String]);
}

- (void)setUseUnderline:(bool)useUnderline
{
	gtk_tool_button_set_use_underline(GTK_TOOL_BUTTON([self GOBJECT]), useUnderline);
}


@end