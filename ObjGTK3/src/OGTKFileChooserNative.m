/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFileChooserNative.h"

#import "OGTKWindow.h"

@implementation OGTKFileChooserNative

- (instancetype)initWithTitle:(OFString*)title parent:(OGTKWindow*)parent action:(GtkFileChooserAction)action acceptLabel:(OFString*)acceptLabel cancelLabel:(OFString*)cancelLabel
{
	self = [super initWithGObject:(GObject*)gtk_file_chooser_native_new([title UTF8String], [parent WINDOW], action, [acceptLabel UTF8String], [cancelLabel UTF8String])];

	return self;
}

- (GtkFileChooserNative*)FILECHOOSERNATIVE
{
	return GTK_FILE_CHOOSER_NATIVE([self GOBJECT]);
}

- (OFString*)acceptLabel
{
	return [OFString stringWithUTF8String:gtk_file_chooser_native_get_accept_label([self FILECHOOSERNATIVE])];
}

- (OFString*)cancelLabel
{
	return [OFString stringWithUTF8String:gtk_file_chooser_native_get_cancel_label([self FILECHOOSERNATIVE])];
}

- (void)setAcceptLabel:(OFString*)acceptLabel
{
	gtk_file_chooser_native_set_accept_label([self FILECHOOSERNATIVE], [acceptLabel UTF8String]);
}

- (void)setCancelLabel:(OFString*)cancelLabel
{
	gtk_file_chooser_native_set_cancel_label([self FILECHOOSERNATIVE], [cancelLabel UTF8String]);
}


@end