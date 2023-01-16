/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKHScrollbar.h"

#import "OGTKAdjustment.h"
#import "OGTKWidget.h"

@implementation OGTKHScrollbar

- (instancetype)init:(OGTKAdjustment*)adjustment
{
	self = [super initWithGObject:(GObject*)gtk_hscrollbar_new([adjustment ADJUSTMENT])];

	return self;
}

- (GtkHScrollbar*)HSCROLLBAR
{
	return GTK_HSCROLLBAR([self GOBJECT]);
}


@end