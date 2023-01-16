/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKHBox.h"

#import "OGTKWidget.h"

@implementation OGTKHBox

- (instancetype)initWithHomogeneous:(bool)homogeneous spacing:(gint)spacing
{
	self = [super initWithGObject:(GObject*)gtk_hbox_new(homogeneous, spacing)];

	return self;
}

- (GtkHBox*)HBOX
{
	return GTK_HBOX([self GOBJECT]);
}


@end