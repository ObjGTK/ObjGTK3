/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKHSeparator.h"

#import "OGTKWidget.h"

@implementation OGTKHSeparator

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_hseparator_new()];

	return self;
}

- (GtkHSeparator*)HSEPARATOR
{
	return GTK_HSEPARATOR([self GOBJECT]);
}


@end