/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFileChooserButton.h"

#import "OGTKWidget.h"

@implementation OGTKFileChooserButton

- (instancetype)initWithTitle:(OFString*)title action:(GtkFileChooserAction)action
{
	self = [super initWithGObject:(GObject*)gtk_file_chooser_button_new([title UTF8String], action)];

	return self;
}

- (instancetype)initWithDialog:(OGTKWidget*)dialog
{
	self = [super initWithGObject:(GObject*)gtk_file_chooser_button_new_with_dialog([dialog WIDGET])];

	return self;
}

- (GtkFileChooserButton*)FILECHOOSERBUTTON
{
	return GTK_FILE_CHOOSER_BUTTON([self GOBJECT]);
}

- (bool)focusOnClick
{
	return gtk_file_chooser_button_get_focus_on_click([self FILECHOOSERBUTTON]);
}

- (OFString*)title
{
	return [OFString stringWithUTF8String:gtk_file_chooser_button_get_title([self FILECHOOSERBUTTON])];
}

- (gint)widthChars
{
	return gtk_file_chooser_button_get_width_chars([self FILECHOOSERBUTTON]);
}

- (void)setFocusOnClick:(bool)focusOnClick
{
	gtk_file_chooser_button_set_focus_on_click([self FILECHOOSERBUTTON], focusOnClick);
}

- (void)setTitle:(OFString*)title
{
	gtk_file_chooser_button_set_title([self FILECHOOSERBUTTON], [title UTF8String]);
}

- (void)setWidthChars:(gint)nchars
{
	gtk_file_chooser_button_set_width_chars([self FILECHOOSERBUTTON], nchars);
}


@end