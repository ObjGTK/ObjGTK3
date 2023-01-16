/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAppChooserButton.h"

#import "OGTKWidget.h"

@implementation OGTKAppChooserButton

- (instancetype)init:(OFString*)contentType
{
	self = [super initWithGObject:(GObject*)gtk_app_chooser_button_new([contentType UTF8String])];

	return self;
}

- (GtkAppChooserButton*)APPCHOOSERBUTTON
{
	return GTK_APP_CHOOSER_BUTTON([self GOBJECT]);
}

- (void)appendCustomItemWithName:(OFString*)name label:(OFString*)label icon:(GIcon*)icon
{
	gtk_app_chooser_button_append_custom_item([self APPCHOOSERBUTTON], [name UTF8String], [label UTF8String], icon);
}

- (void)appendSeparator
{
	gtk_app_chooser_button_append_separator([self APPCHOOSERBUTTON]);
}

- (OFString*)heading
{
	return [OFString stringWithUTF8String:gtk_app_chooser_button_get_heading([self APPCHOOSERBUTTON])];
}

- (bool)showDefaultItem
{
	return gtk_app_chooser_button_get_show_default_item([self APPCHOOSERBUTTON]);
}

- (bool)showDialogItem
{
	return gtk_app_chooser_button_get_show_dialog_item([self APPCHOOSERBUTTON]);
}

- (void)setActiveCustomItem:(OFString*)name
{
	gtk_app_chooser_button_set_active_custom_item([self APPCHOOSERBUTTON], [name UTF8String]);
}

- (void)setHeading:(OFString*)heading
{
	gtk_app_chooser_button_set_heading([self APPCHOOSERBUTTON], [heading UTF8String]);
}

- (void)setShowDefaultItem:(bool)setting
{
	gtk_app_chooser_button_set_show_default_item([self APPCHOOSERBUTTON], setting);
}

- (void)setShowDialogItem:(bool)setting
{
	gtk_app_chooser_button_set_show_dialog_item([self APPCHOOSERBUTTON], setting);
}


@end