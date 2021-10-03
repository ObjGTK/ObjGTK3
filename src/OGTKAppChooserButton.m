/*
 * OGTKAppChooserButton.m
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
#import "OGTKAppChooserButton.h"

@implementation OGTKAppChooserButton

- (id)init:(OFString*)contentType
{
	self = [super initWithGObject:(GObject*)gtk_app_chooser_button_new([contentType UTF8String])];

	return self;
}

- (GtkAppChooserButton*)APPCHOOSERBUTTON
{
	return GTK_APP_CHOOSER_BUTTON([self GOBJECT]);
}

- (void)appendCustomItemWithName:(OFString*)name andLabel:(OFString*)label andIcon:(GIcon*)icon
{
	gtk_app_chooser_button_append_custom_item(GTK_APP_CHOOSER_BUTTON([self GOBJECT]), [name UTF8String], [label UTF8String], icon);
}

- (void)appendSeparator
{
	gtk_app_chooser_button_append_separator(GTK_APP_CHOOSER_BUTTON([self GOBJECT]));
}

- (OFString*)getHeading
{
	return [OFString stringWithUTF8String:gtk_app_chooser_button_get_heading(GTK_APP_CHOOSER_BUTTON([self GOBJECT]))];
}

- (bool)getShowDefaultItem
{
	return gtk_app_chooser_button_get_show_default_item(GTK_APP_CHOOSER_BUTTON([self GOBJECT]));
}

- (bool)getShowDialogItem
{
	return gtk_app_chooser_button_get_show_dialog_item(GTK_APP_CHOOSER_BUTTON([self GOBJECT]));
}

- (void)setActiveCustomItem:(OFString*)name
{
	gtk_app_chooser_button_set_active_custom_item(GTK_APP_CHOOSER_BUTTON([self GOBJECT]), [name UTF8String]);
}

- (void)setHeading:(OFString*)heading
{
	gtk_app_chooser_button_set_heading(GTK_APP_CHOOSER_BUTTON([self GOBJECT]), [heading UTF8String]);
}

- (void)setShowDefaultItem:(bool)setting
{
	gtk_app_chooser_button_set_show_default_item(GTK_APP_CHOOSER_BUTTON([self GOBJECT]), setting);
}

- (void)setShowDialogItem:(bool)setting
{
	gtk_app_chooser_button_set_show_dialog_item(GTK_APP_CHOOSER_BUTTON([self GOBJECT]), setting);
}


@end