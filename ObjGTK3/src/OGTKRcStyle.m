/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRcStyle.h"

@implementation OGTKRcStyle

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_rc_style_new()];

	return self;
}

- (GtkRcStyle*)RCSTYLE
{
	return GTK_RC_STYLE([self GOBJECT]);
}

- (OGTKRcStyle*)copy
{
	return [[[OGTKRcStyle alloc] initWithGObject:(GObject*)gtk_rc_style_copy([self RCSTYLE])] autorelease];
}


@end