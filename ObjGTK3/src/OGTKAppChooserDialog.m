/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAppChooserDialog.h"

#import "OGTKWindow.h"
#import "OGTKWidget.h"

@implementation OGTKAppChooserDialog

- (instancetype)initWithParent:(OGTKWindow*)parent flags:(GtkDialogFlags)flags file:(GFile*)file
{
	self = [super initWithGObject:(GObject*)gtk_app_chooser_dialog_new([parent WINDOW], flags, file)];

	return self;
}

- (instancetype)initForContentTypeWithParent:(OGTKWindow*)parent flags:(GtkDialogFlags)flags contentType:(OFString*)contentType
{
	self = [super initWithGObject:(GObject*)gtk_app_chooser_dialog_new_for_content_type([parent WINDOW], flags, [contentType UTF8String])];

	return self;
}

- (GtkAppChooserDialog*)APPCHOOSERDIALOG
{
	return GTK_APP_CHOOSER_DIALOG([self GOBJECT]);
}

- (OFString*)heading
{
	return [OFString stringWithUTF8String:gtk_app_chooser_dialog_get_heading([self APPCHOOSERDIALOG])];
}

- (OGTKWidget*)widget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_app_chooser_dialog_get_widget([self APPCHOOSERDIALOG])] autorelease];
}

- (void)setHeading:(OFString*)heading
{
	gtk_app_chooser_dialog_set_heading([self APPCHOOSERDIALOG], [heading UTF8String]);
}


@end