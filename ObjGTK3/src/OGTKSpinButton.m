/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSpinButton.h"

#import "OGTKWidget.h"
#import "OGTKAdjustment.h"

@implementation OGTKSpinButton

- (instancetype)initWithAdjustment:(OGTKAdjustment*)adjustment climbRate:(gdouble)climbRate digits:(guint)digits
{
	self = [super initWithGObject:(GObject*)gtk_spin_button_new([adjustment ADJUSTMENT], climbRate, digits)];

	return self;
}

- (instancetype)initWithRangeWithMin:(gdouble)min max:(gdouble)max step:(gdouble)step
{
	self = [super initWithGObject:(GObject*)gtk_spin_button_new_with_range(min, max, step)];

	return self;
}

- (GtkSpinButton*)SPINBUTTON
{
	return GTK_SPIN_BUTTON([self GOBJECT]);
}

- (void)configureWithAdjustment:(OGTKAdjustment*)adjustment climbRate:(gdouble)climbRate digits:(guint)digits
{
	gtk_spin_button_configure([self SPINBUTTON], [adjustment ADJUSTMENT], climbRate, digits);
}

- (OGTKAdjustment*)adjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_spin_button_get_adjustment([self SPINBUTTON])] autorelease];
}

- (guint)digits
{
	return gtk_spin_button_get_digits([self SPINBUTTON]);
}

- (void)incrementsWithStep:(gdouble*)step page:(gdouble*)page
{
	gtk_spin_button_get_increments([self SPINBUTTON], step, page);
}

- (bool)numeric
{
	return gtk_spin_button_get_numeric([self SPINBUTTON]);
}

- (void)rangeWithMin:(gdouble*)min max:(gdouble*)max
{
	gtk_spin_button_get_range([self SPINBUTTON], min, max);
}

- (bool)snapToTicks
{
	return gtk_spin_button_get_snap_to_ticks([self SPINBUTTON]);
}

- (GtkSpinButtonUpdatePolicy)updatePolicy
{
	return gtk_spin_button_get_update_policy([self SPINBUTTON]);
}

- (gdouble)value
{
	return gtk_spin_button_get_value([self SPINBUTTON]);
}

- (gint)valueAsInt
{
	return gtk_spin_button_get_value_as_int([self SPINBUTTON]);
}

- (bool)wrap
{
	return gtk_spin_button_get_wrap([self SPINBUTTON]);
}

- (void)setAdjustment:(OGTKAdjustment*)adjustment
{
	gtk_spin_button_set_adjustment([self SPINBUTTON], [adjustment ADJUSTMENT]);
}

- (void)setDigits:(guint)digits
{
	gtk_spin_button_set_digits([self SPINBUTTON], digits);
}

- (void)setIncrementsWithStep:(gdouble)step page:(gdouble)page
{
	gtk_spin_button_set_increments([self SPINBUTTON], step, page);
}

- (void)setNumeric:(bool)numeric
{
	gtk_spin_button_set_numeric([self SPINBUTTON], numeric);
}

- (void)setRangeWithMin:(gdouble)min max:(gdouble)max
{
	gtk_spin_button_set_range([self SPINBUTTON], min, max);
}

- (void)setSnapToTicks:(bool)snapToTicks
{
	gtk_spin_button_set_snap_to_ticks([self SPINBUTTON], snapToTicks);
}

- (void)setUpdatePolicy:(GtkSpinButtonUpdatePolicy)policy
{
	gtk_spin_button_set_update_policy([self SPINBUTTON], policy);
}

- (void)setValue:(gdouble)value
{
	gtk_spin_button_set_value([self SPINBUTTON], value);
}

- (void)setWrap:(bool)wrap
{
	gtk_spin_button_set_wrap([self SPINBUTTON], wrap);
}

- (void)spinWithDirection:(GtkSpinType)direction increment:(gdouble)increment
{
	gtk_spin_button_spin([self SPINBUTTON], direction, increment);
}

- (void)update
{
	gtk_spin_button_update([self SPINBUTTON]);
}


@end