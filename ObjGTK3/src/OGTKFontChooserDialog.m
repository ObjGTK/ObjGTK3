/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFontChooserDialog.h"

#import "OGTKWindow.h"
#import "OGTKWidget.h"

@implementation OGTKFontChooserDialog

- (instancetype)initWithTitle:(OFString*)title parent:(OGTKWindow*)parent
{
	self = [super initWithGObject:(GObject*)gtk_font_chooser_dialog_new([title UTF8String], [parent WINDOW])];

	return self;
}

- (GtkFontChooserDialog*)FONTCHOOSERDIALOG
{
	return GTK_FONT_CHOOSER_DIALOG([self GOBJECT]);
}


@end