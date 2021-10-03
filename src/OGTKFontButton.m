/*
 * OGTKFontButton.m
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
#import "OGTKFontButton.h"

@implementation OGTKFontButton

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_font_button_new()];

	return self;
}

- (id)initWithFont:(OFString*)fontname
{
	self = [super initWithGObject:(GObject*)gtk_font_button_new_with_font([fontname UTF8String])];

	return self;
}

- (GtkFontButton*)FONTBUTTON
{
	return GTK_FONT_BUTTON([self GOBJECT]);
}

- (OFString*)getFontName
{
	return [OFString stringWithUTF8String:gtk_font_button_get_font_name(GTK_FONT_BUTTON([self GOBJECT]))];
}

- (bool)getShowSize
{
	return gtk_font_button_get_show_size(GTK_FONT_BUTTON([self GOBJECT]));
}

- (bool)getShowStyle
{
	return gtk_font_button_get_show_style(GTK_FONT_BUTTON([self GOBJECT]));
}

- (OFString*)getTitle
{
	return [OFString stringWithUTF8String:gtk_font_button_get_title(GTK_FONT_BUTTON([self GOBJECT]))];
}

- (bool)getUseFont
{
	return gtk_font_button_get_use_font(GTK_FONT_BUTTON([self GOBJECT]));
}

- (bool)getUseSize
{
	return gtk_font_button_get_use_size(GTK_FONT_BUTTON([self GOBJECT]));
}

- (bool)setFontName:(OFString*)fontname
{
	return gtk_font_button_set_font_name(GTK_FONT_BUTTON([self GOBJECT]), [fontname UTF8String]);
}

- (void)setShowSize:(bool)showSize
{
	gtk_font_button_set_show_size(GTK_FONT_BUTTON([self GOBJECT]), showSize);
}

- (void)setShowStyle:(bool)showStyle
{
	gtk_font_button_set_show_style(GTK_FONT_BUTTON([self GOBJECT]), showStyle);
}

- (void)setTitle:(OFString*)title
{
	gtk_font_button_set_title(GTK_FONT_BUTTON([self GOBJECT]), [title UTF8String]);
}

- (void)setUseFont:(bool)useFont
{
	gtk_font_button_set_use_font(GTK_FONT_BUTTON([self GOBJECT]), useFont);
}

- (void)setUseSize:(bool)useSize
{
	gtk_font_button_set_use_size(GTK_FONT_BUTTON([self GOBJECT]), useSize);
}


@end