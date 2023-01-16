/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFixed.h"

#import "OGTKWidget.h"

@implementation OGTKFixed

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_fixed_new()];

	return self;
}

- (GtkFixed*)FIXED
{
	return GTK_FIXED([self GOBJECT]);
}

- (void)moveWithWidget:(OGTKWidget*)widget x:(gint)x y:(gint)y
{
	gtk_fixed_move([self FIXED], [widget WIDGET], x, y);
}

- (void)putWithWidget:(OGTKWidget*)widget x:(gint)x y:(gint)y
{
	gtk_fixed_put([self FIXED], [widget WIDGET], x, y);
}


@end