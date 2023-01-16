/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKHPaned.h"

#import "OGTKWidget.h"

@implementation OGTKHPaned

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_hpaned_new()];

	return self;
}

- (GtkHPaned*)HPANED
{
	return GTK_HPANED([self GOBJECT]);
}


@end