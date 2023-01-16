/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKColorButton.h"

#import "OGTKWidget.h"

@implementation OGTKColorButton

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_color_button_new()];

	return self;
}

- (instancetype)initWithColor:(const GdkColor*)color
{
	self = [super initWithGObject:(GObject*)gtk_color_button_new_with_color(color)];

	return self;
}

- (instancetype)initWithRgba:(const GdkRGBA*)rgba
{
	self = [super initWithGObject:(GObject*)gtk_color_button_new_with_rgba(rgba)];

	return self;
}

- (GtkColorButton*)COLORBUTTON
{
	return GTK_COLOR_BUTTON([self GOBJECT]);
}

- (guint16)alpha
{
	return gtk_color_button_get_alpha([self COLORBUTTON]);
}

- (void)color:(GdkColor*)color
{
	gtk_color_button_get_color([self COLORBUTTON], color);
}

- (void)rgba:(GdkRGBA*)rgba
{
	gtk_color_button_get_rgba([self COLORBUTTON], rgba);
}

- (OFString*)title
{
	return [OFString stringWithUTF8String:gtk_color_button_get_title([self COLORBUTTON])];
}

- (bool)useAlpha
{
	return gtk_color_button_get_use_alpha([self COLORBUTTON]);
}

- (void)setAlpha:(guint16)alpha
{
	gtk_color_button_set_alpha([self COLORBUTTON], alpha);
}

- (void)setColor:(const GdkColor*)color
{
	gtk_color_button_set_color([self COLORBUTTON], color);
}

- (void)setRgba:(const GdkRGBA*)rgba
{
	gtk_color_button_set_rgba([self COLORBUTTON], rgba);
}

- (void)setTitle:(OFString*)title
{
	gtk_color_button_set_title([self COLORBUTTON], [title UTF8String]);
}

- (void)setUseAlpha:(bool)useAlpha
{
	gtk_color_button_set_use_alpha([self COLORBUTTON], useAlpha);
}


@end