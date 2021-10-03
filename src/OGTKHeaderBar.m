/*
 * OGTKHeaderBar.m
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
#import "OGTKHeaderBar.h"

@implementation OGTKHeaderBar

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_header_bar_new()];

	return self;
}

- (GtkHeaderBar*)HEADERBAR
{
	return GTK_HEADER_BAR([self GOBJECT]);
}

- (OGTKWidget*)getCustomTitle
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_header_bar_get_custom_title(GTK_HEADER_BAR([self GOBJECT]))];
}

- (OFString*)getDecorationLayout
{
	return [OFString stringWithUTF8String:gtk_header_bar_get_decoration_layout(GTK_HEADER_BAR([self GOBJECT]))];
}

- (bool)getHasSubtitle
{
	return gtk_header_bar_get_has_subtitle(GTK_HEADER_BAR([self GOBJECT]));
}

- (bool)getShowCloseButton
{
	return gtk_header_bar_get_show_close_button(GTK_HEADER_BAR([self GOBJECT]));
}

- (OFString*)getSubtitle
{
	return [OFString stringWithUTF8String:gtk_header_bar_get_subtitle(GTK_HEADER_BAR([self GOBJECT]))];
}

- (OFString*)getTitle
{
	return [OFString stringWithUTF8String:gtk_header_bar_get_title(GTK_HEADER_BAR([self GOBJECT]))];
}

- (void)packEnd:(OGTKWidget*)child
{
	gtk_header_bar_pack_end(GTK_HEADER_BAR([self GOBJECT]), [child WIDGET]);
}

- (void)packStart:(OGTKWidget*)child
{
	gtk_header_bar_pack_start(GTK_HEADER_BAR([self GOBJECT]), [child WIDGET]);
}

- (void)setCustomTitle:(OGTKWidget*)titleWidget
{
	gtk_header_bar_set_custom_title(GTK_HEADER_BAR([self GOBJECT]), [titleWidget WIDGET]);
}

- (void)setDecorationLayout:(OFString*)layout
{
	gtk_header_bar_set_decoration_layout(GTK_HEADER_BAR([self GOBJECT]), [layout UTF8String]);
}

- (void)setHasSubtitle:(bool)setting
{
	gtk_header_bar_set_has_subtitle(GTK_HEADER_BAR([self GOBJECT]), setting);
}

- (void)setShowCloseButton:(bool)setting
{
	gtk_header_bar_set_show_close_button(GTK_HEADER_BAR([self GOBJECT]), setting);
}

- (void)setSubtitle:(OFString*)subtitle
{
	gtk_header_bar_set_subtitle(GTK_HEADER_BAR([self GOBJECT]), [subtitle UTF8String]);
}

- (void)setTitle:(OFString*)title
{
	gtk_header_bar_set_title(GTK_HEADER_BAR([self GOBJECT]), [title UTF8String]);
}


@end