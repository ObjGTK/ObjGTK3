/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKColorSelectionDialog.h"

#import "OGTKWidget.h"

@implementation OGTKColorSelectionDialog

- (instancetype)init:(OFString*)title
{
	self = [super initWithGObject:(GObject*)gtk_color_selection_dialog_new([title UTF8String])];

	return self;
}

- (GtkColorSelectionDialog*)COLORSELECTIONDIALOG
{
	return GTK_COLOR_SELECTION_DIALOG([self GOBJECT]);
}

- (OGTKWidget*)colorSelection
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_color_selection_dialog_get_color_selection([self COLORSELECTIONDIALOG])] autorelease];
}


@end