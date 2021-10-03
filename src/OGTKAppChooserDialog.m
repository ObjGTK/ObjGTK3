/*
 * OGTKAppChooserDialog.m
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
#import "OGTKAppChooserDialog.h"

@implementation OGTKAppChooserDialog

- (id)initWithParent:(GtkWindow*)parent andFlags:(GtkDialogFlags)flags andFile:(GFile*)file
{
	self = [super initWithGObject:(GObject*)gtk_app_chooser_dialog_new(parent, flags, file)];

	return self;
}

- (id)initForContentTypeWithParent:(GtkWindow*)parent andFlags:(GtkDialogFlags)flags andContentType:(OFString*)contentType
{
	self = [super initWithGObject:(GObject*)gtk_app_chooser_dialog_new_for_content_type(parent, flags, [contentType UTF8String])];

	return self;
}

- (GtkAppChooserDialog*)APPCHOOSERDIALOG
{
	return GTK_APP_CHOOSER_DIALOG([self GOBJECT]);
}

- (OFString*)getHeading
{
	return [OFString stringWithUTF8String:gtk_app_chooser_dialog_get_heading(GTK_APP_CHOOSER_DIALOG([self GOBJECT]))];
}

- (OGTKWidget*)getWidget
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_app_chooser_dialog_get_widget(GTK_APP_CHOOSER_DIALOG([self GOBJECT]))];
}

- (void)setHeading:(OFString*)heading
{
	gtk_app_chooser_dialog_set_heading(GTK_APP_CHOOSER_DIALOG([self GOBJECT]), [heading UTF8String]);
}


@end