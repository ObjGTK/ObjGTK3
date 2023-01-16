/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKHScale.h"

#import "OGTKAdjustment.h"
#import "OGTKWidget.h"

@implementation OGTKHScale

- (instancetype)init:(OGTKAdjustment*)adjustment
{
	self = [super initWithGObject:(GObject*)gtk_hscale_new([adjustment ADJUSTMENT])];

	return self;
}

- (instancetype)initWithRangeWithMin:(gdouble)min max:(gdouble)max step:(gdouble)step
{
	self = [super initWithGObject:(GObject*)gtk_hscale_new_with_range(min, max, step)];

	return self;
}

- (GtkHScale*)HSCALE
{
	return GTK_HSCALE([self GOBJECT]);
}


@end