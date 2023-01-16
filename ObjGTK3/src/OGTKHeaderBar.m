/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKHeaderBar.h"

#import "OGTKWidget.h"

@implementation OGTKHeaderBar

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_header_bar_new()];

	return self;
}

- (GtkHeaderBar*)HEADERBAR
{
	return GTK_HEADER_BAR([self GOBJECT]);
}

- (OGTKWidget*)customTitle
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_header_bar_get_custom_title([self HEADERBAR])] autorelease];
}

- (OFString*)decorationLayout
{
	return [OFString stringWithUTF8String:gtk_header_bar_get_decoration_layout([self HEADERBAR])];
}

- (bool)hasSubtitle
{
	return gtk_header_bar_get_has_subtitle([self HEADERBAR]);
}

- (bool)showCloseButton
{
	return gtk_header_bar_get_show_close_button([self HEADERBAR]);
}

- (OFString*)subtitle
{
	return [OFString stringWithUTF8String:gtk_header_bar_get_subtitle([self HEADERBAR])];
}

- (OFString*)title
{
	return [OFString stringWithUTF8String:gtk_header_bar_get_title([self HEADERBAR])];
}

- (void)packEnd:(OGTKWidget*)child
{
	gtk_header_bar_pack_end([self HEADERBAR], [child WIDGET]);
}

- (void)packStart:(OGTKWidget*)child
{
	gtk_header_bar_pack_start([self HEADERBAR], [child WIDGET]);
}

- (void)setCustomTitle:(OGTKWidget*)titleWidget
{
	gtk_header_bar_set_custom_title([self HEADERBAR], [titleWidget WIDGET]);
}

- (void)setDecorationLayout:(OFString*)layout
{
	gtk_header_bar_set_decoration_layout([self HEADERBAR], [layout UTF8String]);
}

- (void)setHasSubtitle:(bool)setting
{
	gtk_header_bar_set_has_subtitle([self HEADERBAR], setting);
}

- (void)setShowCloseButton:(bool)setting
{
	gtk_header_bar_set_show_close_button([self HEADERBAR], setting);
}

- (void)setSubtitle:(OFString*)subtitle
{
	gtk_header_bar_set_subtitle([self HEADERBAR], [subtitle UTF8String]);
}

- (void)setTitle:(OFString*)title
{
	gtk_header_bar_set_title([self HEADERBAR], [title UTF8String]);
}


@end