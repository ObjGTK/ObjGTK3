/*
 * OGTKAdjustment.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKAdjustment.h"

@implementation OGTKAdjustment

- (id)initWithValue:(gdouble)value andLower:(gdouble)lower andUpper:(gdouble)upper andStepIncrement:(gdouble)stepIncrement andPageIncrement:(gdouble)pageIncrement andPageSize:(gdouble)pageSize
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
	gtk_adjustment_changed(GTK_ADJUSTMENT([self GOBJECT]));
}

- (void)clampPageWithLower:(gdouble)lower andUpper:(gdouble)upper
{
	gtk_adjustment_clamp_page(GTK_ADJUSTMENT([self GOBJECT]), lower, upper);
}

- (void)configureWithValue:(gdouble)value andLower:(gdouble)lower andUpper:(gdouble)upper andStepIncrement:(gdouble)stepIncrement andPageIncrement:(gdouble)pageIncrement andPageSize:(gdouble)pageSize
{
	gtk_adjustment_configure(GTK_ADJUSTMENT([self GOBJECT]), value, lower, upper, stepIncrement, pageIncrement, pageSize);
}

- (gdouble)getLower
{
	return gtk_adjustment_get_lower(GTK_ADJUSTMENT([self GOBJECT]));
}

- (gdouble)getMinimumIncrement
{
	return gtk_adjustment_get_minimum_increment(GTK_ADJUSTMENT([self GOBJECT]));
}

- (gdouble)getPageIncrement
{
	return gtk_adjustment_get_page_increment(GTK_ADJUSTMENT([self GOBJECT]));
}

- (gdouble)getPageSize
{
	return gtk_adjustment_get_page_size(GTK_ADJUSTMENT([self GOBJECT]));
}

- (gdouble)getStepIncrement
{
	return gtk_adjustment_get_step_increment(GTK_ADJUSTMENT([self GOBJECT]));
}

- (gdouble)getUpper
{
	return gtk_adjustment_get_upper(GTK_ADJUSTMENT([self GOBJECT]));
}

- (gdouble)getValue
{
	return gtk_adjustment_get_value(GTK_ADJUSTMENT([self GOBJECT]));
}

- (void)setLower:(gdouble)lower
{
	gtk_adjustment_set_lower(GTK_ADJUSTMENT([self GOBJECT]), lower);
}

- (void)setPageIncrement:(gdouble)pageIncrement
{
	gtk_adjustment_set_page_increment(GTK_ADJUSTMENT([self GOBJECT]), pageIncrement);
}

- (void)setPageSize:(gdouble)pageSize
{
	gtk_adjustment_set_page_size(GTK_ADJUSTMENT([self GOBJECT]), pageSize);
}

- (void)setStepIncrement:(gdouble)stepIncrement
{
	gtk_adjustment_set_step_increment(GTK_ADJUSTMENT([self GOBJECT]), stepIncrement);
}

- (void)setUpper:(gdouble)upper
{
	gtk_adjustment_set_upper(GTK_ADJUSTMENT([self GOBJECT]), upper);
}

- (void)setValue:(gdouble)value
{
	gtk_adjustment_set_value(GTK_ADJUSTMENT([self GOBJECT]), value);
}

- (void)valueChanged
{
	gtk_adjustment_value_changed(GTK_ADJUSTMENT([self GOBJECT]));
}


@end