/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFontButton.h"

#import "OGTKWidget.h"

@implementation OGTKFontButton

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_font_button_new()];

	return self;
}

- (instancetype)initWithFont:(OFString*)fontname
{
	self = [super initWithGObject:(GObject*)gtk_font_button_new_with_font([fontname UTF8String])];

	return self;
}

- (GtkFontButton*)FONTBUTTON
{
	return GTK_FONT_BUTTON([self GOBJECT]);
}

- (OFString*)fontName
{
	return [OFString stringWithUTF8String:gtk_font_button_get_font_name([self FONTBUTTON])];
}

- (bool)showSize
{
	return gtk_font_button_get_show_size([self FONTBUTTON]);
}

- (bool)showStyle
{
	return gtk_font_button_get_show_style([self FONTBUTTON]);
}

- (OFString*)title
{
	return [OFString stringWithUTF8String:gtk_font_button_get_title([self FONTBUTTON])];
}

- (bool)useFont
{
	return gtk_font_button_get_use_font([self FONTBUTTON]);
}

- (bool)useSize
{
	return gtk_font_button_get_use_size([self FONTBUTTON]);
}

- (bool)setFontName:(OFString*)fontname
{
	return gtk_font_button_set_font_name([self FONTBUTTON], [fontname UTF8String]);
}

- (void)setShowSize:(bool)showSize
{
	gtk_font_button_set_show_size([self FONTBUTTON], showSize);
}

- (void)setShowStyle:(bool)showStyle
{
	gtk_font_button_set_show_style([self FONTBUTTON], showStyle);
}

- (void)setTitle:(OFString*)title
{
	gtk_font_button_set_title([self FONTBUTTON], [title UTF8String]);
}

- (void)setUseFont:(bool)useFont
{
	gtk_font_button_set_use_font([self FONTBUTTON], useFont);
}

- (void)setUseSize:(bool)useSize
{
	gtk_font_button_set_use_size([self FONTBUTTON], useSize);
}


@end