/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

#import "OGTKWidget.h"

@implementation OGTKBin

- (GtkBin*)BIN
{
	return GTK_BIN([self GOBJECT]);
}

- (OGTKWidget*)child
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_bin_get_child([self BIN])] autorelease];
}


@end