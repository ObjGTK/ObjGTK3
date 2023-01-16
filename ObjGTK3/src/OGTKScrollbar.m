/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKScrollbar.h"

#import "OGTKWidget.h"
#import "OGTKAdjustment.h"

@implementation OGTKScrollbar

- (instancetype)initWithOrientation:(GtkOrientation)orientation adjustment:(OGTKAdjustment*)adjustment
{
	self = [super initWithGObject:(GObject*)gtk_scrollbar_new(orientation, [adjustment ADJUSTMENT])];

	return self;
}

- (GtkScrollbar*)SCROLLBAR
{
	return GTK_SCROLLBAR([self GOBJECT]);
}


@end