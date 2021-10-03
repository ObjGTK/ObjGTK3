/*
 * OGTKButton.m
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
#import "OGTKButton.h"

@implementation OGTKButton

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_button_new()];

	return self;
}

- (id)initFromIconNameWithIconName:(OFString*)iconName andSize:(GtkIconSize)size
{
	self = [super initWithGObject:(GObject*)gtk_button_new_from_icon_name([iconName UTF8String], size)];

	return self;
}

- (id)initFromStock:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_button_new_from_stock([stockId UTF8String])];

	return self;
}

- (id)initWithLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_button_new_with_label([label UTF8String])];

	return self;
}

- (id)initWithMnemonic:(OFString*)label
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
	gtk_button_clicked(GTK_BUTTON([self GOBJECT]));
}

- (void)enter
{
	gtk_button_enter(GTK_BUTTON([self GOBJECT]));
}

- (void)getAlignmentWithXalign:(gfloat*)xalign andYalign:(gfloat*)yalign
{
	gtk_button_get_alignment(GTK_BUTTON([self GOBJECT]), xalign, yalign);
}

- (bool)getAlwaysShowImage
{
	return gtk_button_get_always_show_image(GTK_BUTTON([self GOBJECT]));
}

- (GdkWindow*)getEventWindow
{
	return gtk_button_get_event_window(GTK_BUTTON([self GOBJECT]));
}

- (bool)getFocusOnClick
{
	return gtk_button_get_focus_on_click(GTK_BUTTON([self GOBJECT]));
}

- (OGTKWidget*)getImage
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_button_get_image(GTK_BUTTON([self GOBJECT]))];
}

- (GtkPositionType)getImagePosition
{
	return gtk_button_get_image_position(GTK_BUTTON([self GOBJECT]));
}

- (OFString*)getLabel
{
	return [OFString stringWithUTF8String:gtk_button_get_label(GTK_BUTTON([self GOBJECT]))];
}

- (GtkReliefStyle)getRelief
{
	return gtk_button_get_relief(GTK_BUTTON([self GOBJECT]));
}

- (bool)getUseStock
{
	return gtk_button_get_use_stock(GTK_BUTTON([self GOBJECT]));
}

- (bool)getUseUnderline
{
	return gtk_button_get_use_underline(GTK_BUTTON([self GOBJECT]));
}

- (void)leave
{
	gtk_button_leave(GTK_BUTTON([self GOBJECT]));
}

- (void)pressed
{
	gtk_button_pressed(GTK_BUTTON([self GOBJECT]));
}

- (void)released
{
	gtk_button_released(GTK_BUTTON([self GOBJECT]));
}

- (void)setAlignmentWithXalign:(gfloat)xalign andYalign:(gfloat)yalign
{
	gtk_button_set_alignment(GTK_BUTTON([self GOBJECT]), xalign, yalign);
}

- (void)setAlwaysShowImage:(bool)alwaysShow
{
	gtk_button_set_always_show_image(GTK_BUTTON([self GOBJECT]), alwaysShow);
}

- (void)setFocusOnClick:(bool)focusOnClick
{
	gtk_button_set_focus_on_click(GTK_BUTTON([self GOBJECT]), focusOnClick);
}

- (void)setImage:(OGTKWidget*)image
{
	gtk_button_set_image(GTK_BUTTON([self GOBJECT]), [image WIDGET]);
}

- (void)setImagePosition:(GtkPositionType)position
{
	gtk_button_set_image_position(GTK_BUTTON([self GOBJECT]), position);
}

- (void)setLabel:(OFString*)label
{
	gtk_button_set_label(GTK_BUTTON([self GOBJECT]), [label UTF8String]);
}

- (void)setRelief:(GtkReliefStyle)relief
{
	gtk_button_set_relief(GTK_BUTTON([self GOBJECT]), relief);
}

- (void)setUseStock:(bool)useStock
{
	gtk_button_set_use_stock(GTK_BUTTON([self GOBJECT]), useStock);
}

- (void)setUseUnderline:(bool)useUnderline
{
	gtk_button_set_use_underline(GTK_BUTTON([self GOBJECT]), useUnderline);
}


@end