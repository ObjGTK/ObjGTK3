/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKColorChooserDialog.h"

#import "OGTKWidget.h"
#import "OGTKWindow.h"

@implementation OGTKColorChooserDialog

- (instancetype)initWithTitle:(OFString*)title parent:(OGTKWindow*)parent
{
	self = [super initWithGObject:(GObject*)gtk_color_chooser_dialog_new([title UTF8String], [parent WINDOW])];

	return self;
}

- (GtkColorChooserDialog*)COLORCHOOSERDIALOG
{
	return GTK_COLOR_CHOOSER_DIALOG([self GOBJECT]);
}


@end