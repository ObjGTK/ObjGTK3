/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKButton.h"

#import <OGdk3/OGGdkWindow.h>
#import "OGTKWidget.h"

@implementation OGTKButton

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_button_new()];

	return self;
}

- (instancetype)initFromIconNameWithIconName:(OFString*)iconName size:(GtkIconSize)size
{
	self = [super initWithGObject:(GObject*)gtk_button_new_from_icon_name([iconName UTF8String], size)];

	return self;
}

- (instancetype)initFromStock:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_button_new_from_stock([stockId UTF8String])];

	return self;
}

- (instancetype)initWithLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_button_new_with_label([label UTF8String])];

	return self;
}

- (instancetype)initWithMnemonic:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_button_new_with_mnemonic([label UTF8String])];

	return self;
}

- (GtkButton*)BUTTON
{
	return GTK_BUTTON([self GOBJECT]);
}

- (void)clicked
{
	gtk_button_clicked([self BUTTON]);
}

- (void)enter
{
	gtk_button_enter([self BUTTON]);
}

- (void)alignmentWithXalign:(gfloat*)xalign yalign:(gfloat*)yalign
{
	gtk_button_get_alignment([self BUTTON], xalign, yalign);
}

- (bool)alwaysShowImage
{
	return gtk_button_get_always_show_image([self BUTTON]);
}

- (OGGdkWindow*)eventWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_button_get_event_window([self BUTTON])] autorelease];
}

- (bool)focusOnClick
{
	return gtk_button_get_focus_on_click([self BUTTON]);
}

- (OGTKWidget*)image
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_button_get_image([self BUTTON])] autorelease];
}

- (GtkPositionType)imagePosition
{
	return gtk_button_get_image_position([self BUTTON]);
}

- (OFString*)label
{
	return [OFString stringWithUTF8String:gtk_button_get_label([self BUTTON])];
}

- (GtkReliefStyle)relief
{
	return gtk_button_get_relief([self BUTTON]);
}

- (bool)useStock
{
	return gtk_button_get_use_stock([self BUTTON]);
}

- (bool)useUnderline
{
	return gtk_button_get_use_underline([self BUTTON]);
}

- (void)leave
{
	gtk_button_leave([self BUTTON]);
}

- (void)pressed
{
	gtk_button_pressed([self BUTTON]);
}

- (void)released
{
	gtk_button_released([self BUTTON]);
}

- (void)setAlignmentWithXalign:(gfloat)xalign yalign:(gfloat)yalign
{
	gtk_button_set_alignment([self BUTTON], xalign, yalign);
}

- (void)setAlwaysShowImage:(bool)alwaysShow
{
	gtk_button_set_always_show_image([self BUTTON], alwaysShow);
}

- (void)setFocusOnClick:(bool)focusOnClick
{
	gtk_button_set_focus_on_click([self BUTTON], focusOnClick);
}

- (void)setImage:(OGTKWidget*)image
{
	gtk_button_set_image([self BUTTON], [image WIDGET]);
}

- (void)setImagePosition:(GtkPositionType)position
{
	gtk_button_set_image_position([self BUTTON], position);
}

- (void)setLabel:(OFString*)label
{
	gtk_button_set_label([self BUTTON], [label UTF8String]);
}

- (void)setRelief:(GtkReliefStyle)relief
{
	gtk_button_set_relief([self BUTTON], relief);
}

- (void)setUseStock:(bool)useStock
{
	gtk_button_set_use_stock([self BUTTON], useStock);
}

- (void)setUseUnderline:(bool)useUnderline
{
	gtk_button_set_use_underline([self BUTTON], useUnderline);
}


@end