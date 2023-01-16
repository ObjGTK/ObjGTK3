/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAdjustment.h"

@implementation OGTKAdjustment

- (instancetype)initWithValue:(gdouble)value lower:(gdouble)lower upper:(gdouble)upper stepIncrement:(gdouble)stepIncrement pageIncrement:(gdouble)pageIncrement pageSize:(gdouble)pageSize
{
	self = [super initWithGObject:(GObject*)gtk_adjustment_new(value, lower, upper, stepIncrement, pageIncrement, pageSize)];

	return self;
}

- (GtkAdjustment*)ADJUSTMENT
{
	return GTK_ADJUSTMENT([self GOBJECT]);
}

- (void)changed
{
	gtk_adjustment_changed([self ADJUSTMENT]);
}

- (void)clampPageWithLower:(gdouble)lower upper:(gdouble)upper
{
	gtk_adjustment_clamp_page([self ADJUSTMENT], lower, upper);
}

- (void)configureWithValue:(gdouble)value lower:(gdouble)lower upper:(gdouble)upper stepIncrement:(gdouble)stepIncrement pageIncrement:(gdouble)pageIncrement pageSize:(gdouble)pageSize
{
	gtk_adjustment_configure([self ADJUSTMENT], value, lower, upper, stepIncrement, pageIncrement, pageSize);
}

- (gdouble)lower
{
	return gtk_adjustment_get_lower([self ADJUSTMENT]);
}

- (gdouble)minimumIncrement
{
	return gtk_adjustment_get_minimum_increment([self ADJUSTMENT]);
}

- (gdouble)pageIncrement
{
	return gtk_adjustment_get_page_increment([self ADJUSTMENT]);
}

- (gdouble)pageSize
{
	return gtk_adjustment_get_page_size([self ADJUSTMENT]);
}

- (gdouble)stepIncrement
{
	return gtk_adjustment_get_step_increment([self ADJUSTMENT]);
}

- (gdouble)upper
{
	return gtk_adjustment_get_upper([self ADJUSTMENT]);
}

- (gdouble)value
{
	return gtk_adjustment_get_value([self ADJUSTMENT]);
}

- (void)setLower:(gdouble)lower
{
	gtk_adjustment_set_lower([self ADJUSTMENT], lower);
}

- (void)setPageIncrement:(gdouble)pageIncrement
{
	gtk_adjustment_set_page_increment([self ADJUSTMENT], pageIncrement);
}

- (void)setPageSize:(gdouble)pageSize
{
	gtk_adjustment_set_page_size([self ADJUSTMENT], pageSize);
}

- (void)setStepIncrement:(gdouble)stepIncrement
{
	gtk_adjustment_set_step_increment([self ADJUSTMENT], stepIncrement);
}

- (void)setUpper:(gdouble)upper
{
	gtk_adjustment_set_upper([self ADJUSTMENT], upper);
}

- (void)setValue:(gdouble)value
{
	gtk_adjustment_set_value([self ADJUSTMENT], value);
}

- (void)valueChanged
{
	gtk_adjustment_value_changed([self ADJUSTMENT]);
}


@end