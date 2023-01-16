/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKVPaned.h"

#import "OGTKWidget.h"

@implementation OGTKVPaned

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_vpaned_new()];

	return self;
}

- (GtkVPaned*)VPANED
{
	return GTK_VPANED([self GOBJECT]);
}


@end