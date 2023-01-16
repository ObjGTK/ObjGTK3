/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFileChooserWidget.h"

#import "OGTKWidget.h"

@implementation OGTKFileChooserWidget

- (instancetype)init:(GtkFileChooserAction)action
{
	self = [super initWithGObject:(GObject*)gtk_file_chooser_widget_new(action)];

	return self;
}

- (GtkFileChooserWidget*)FILECHOOSERWIDGET
{
	return GTK_FILE_CHOOSER_WIDGET([self GOBJECT]);
}


@end