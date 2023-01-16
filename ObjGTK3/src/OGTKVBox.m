/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKVBox.h"

#import "OGTKWidget.h"

@implementation OGTKVBox

- (instancetype)initWithHomogeneous:(bool)homogeneous spacing:(gint)spacing
{
	self = [super initWithGObject:(GObject*)gtk_vbox_new(homogeneous, spacing)];

	return self;
}

- (GtkVBox*)VBOX
{
	return GTK_VBOX([self GOBJECT]);
}


@end