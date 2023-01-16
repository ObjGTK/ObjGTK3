/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKHSV.h"

@implementation OGTKHSV

+ (void)toRgbWithH:(gdouble)h s:(gdouble)s v:(gdouble)v r:(gdouble*)r g:(gdouble*)g b:(gdouble*)b
{
	gtk_hsv_to_rgb(h, s, v, r, g, b);
}

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_hsv_new()];

	return self;
}

- (GtkHSV*)HSV
{
	return GTK_HSV([self GOBJECT]);
}

- (void)colorWithH:(gdouble*)h s:(gdouble*)s v:(gdouble*)v
{
	gtk_hsv_get_color([self HSV], h, s, v);
}

- (void)metricsWithSize:(gint*)size ringWidth:(gint*)ringWidth
{
	gtk_hsv_get_metrics([self HSV], size, ringWidth);
}

- (bool)isAdjusting
{
	return gtk_hsv_is_adjusting([self HSV]);
}

- (void)setColorWithH:(double)h s:(double)s v:(double)v
{
	gtk_hsv_set_color([self HSV], h, s, v);
}

- (void)setMetricsWithSize:(gint)size ringWidth:(gint)ringWidth
{
	gtk_hsv_set_metrics([self HSV], size, ringWidth);
}


@end