/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRange.h"

#import "OGTKAdjustment.h"

@implementation OGTKRange

- (GtkRange*)RANGE
{
	return GTK_RANGE([self GOBJECT]);
}

- (OGTKAdjustment*)adjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_range_get_adjustment([self RANGE])] autorelease];
}

- (gdouble)fillLevel
{
	return gtk_range_get_fill_level([self RANGE]);
}

- (bool)flippable
{
	return gtk_range_get_flippable([self RANGE]);
}

- (bool)inverted
{
	return gtk_range_get_inverted([self RANGE]);
}

- (GtkSensitivityType)lowerStepperSensitivity
{
	return gtk_range_get_lower_stepper_sensitivity([self RANGE]);
}

- (gint)minSliderSize
{
	return gtk_range_get_min_slider_size([self RANGE]);
}

- (void)rangeRect:(GdkRectangle*)rangeRect
{
	gtk_range_get_range_rect([self RANGE], rangeRect);
}

- (bool)restrictToFillLevel
{
	return gtk_range_get_restrict_to_fill_level([self RANGE]);
}

- (gint)roundDigits
{
	return gtk_range_get_round_digits([self RANGE]);
}

- (bool)showFillLevel
{
	return gtk_range_get_show_fill_level([self RANGE]);
}

- (void)sliderRangeWithSliderStart:(gint*)sliderStart sliderEnd:(gint*)sliderEnd
{
	gtk_range_get_slider_range([self RANGE], sliderStart, sliderEnd);
}

- (bool)sliderSizeFixed
{
	return gtk_range_get_slider_size_fixed([self RANGE]);
}

- (GtkSensitivityType)upperStepperSensitivity
{
	return gtk_range_get_upper_stepper_sensitivity([self RANGE]);
}

- (gdouble)value
{
	return gtk_range_get_value([self RANGE]);
}

- (void)setAdjustment:(OGTKAdjustment*)adjustment
{
	gtk_range_set_adjustment([self RANGE], [adjustment ADJUSTMENT]);
}

- (void)setFillLevel:(gdouble)fillLevel
{
	gtk_range_set_fill_level([self RANGE], fillLevel);
}

- (void)setFlippable:(bool)flippable
{
	gtk_range_set_flippable([self RANGE], flippable);
}

- (void)setIncrementsWithStep:(gdouble)step page:(gdouble)page
{
	gtk_range_set_increments([self RANGE], step, page);
}

- (void)setInverted:(bool)setting
{
	gtk_range_set_inverted([self RANGE], setting);
}

- (void)setLowerStepperSensitivity:(GtkSensitivityType)sensitivity
{
	gtk_range_set_lower_stepper_sensitivity([self RANGE], sensitivity);
}

- (void)setMinSliderSize:(gint)minSize
{
	gtk_range_set_min_slider_size([self RANGE], minSize);
}

- (void)setRangeWithMin:(gdouble)min max:(gdouble)max
{
	gtk_range_set_range([self RANGE], min, max);
}

- (void)setRestrictToFillLevel:(bool)restrictToFillLevel
{
	gtk_range_set_restrict_to_fill_level([self RANGE], restrictToFillLevel);
}

- (void)setRoundDigits:(gint)roundDigits
{
	gtk_range_set_round_digits([self RANGE], roundDigits);
}

- (void)setShowFillLevel:(bool)showFillLevel
{
	gtk_range_set_show_fill_level([self RANGE], showFillLevel);
}

- (void)setSliderSizeFixed:(bool)sizeFixed
{
	gtk_range_set_slider_size_fixed([self RANGE], sizeFixed);
}

- (void)setUpperStepperSensitivity:(GtkSensitivityType)sensitivity
{
	gtk_range_set_upper_stepper_sensitivity([self RANGE], sensitivity);
}

- (void)setValue:(gdouble)value
{
	gtk_range_set_value([self RANGE], value);
}


@end