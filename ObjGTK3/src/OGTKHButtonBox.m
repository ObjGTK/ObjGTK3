/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKHButtonBox.h"

#import "OGTKWidget.h"

@implementation OGTKHButtonBox

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_hbutton_box_new()];

	return self;
}

- (GtkHButtonBox*)HBUTTONBOX
{
	return GTK_HBUTTON_BOX([self GOBJECT]);
}


@end