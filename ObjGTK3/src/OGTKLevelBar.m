/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKLevelBar.h"

@implementation OGTKLevelBar

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_level_bar_new()];

	return self;
}

- (instancetype)initForIntervalWithMinValue:(gdouble)minValue maxValue:(gdouble)maxValue
{
	self = [super initWithGObject:(GObject*)gtk_level_bar_new_for_interval(minValue, maxValue)];

	return self;
}

- (GtkLevelBar*)LEVELBAR
{
	return GTK_LEVEL_BAR([self GOBJECT]);
}

- (void)addOffsetValueWithName:(OFString*)name value:(gdouble)value
{
	gtk_level_bar_add_offset_value([self LEVELBAR], [name UTF8String], value);
}

- (bool)inverted
{
	return gtk_level_bar_get_inverted([self LEVELBAR]);
}

- (gdouble)maxValue
{
	return gtk_level_bar_get_max_value([self LEVELBAR]);
}

- (gdouble)minValue
{
	return gtk_level_bar_get_min_value([self LEVELBAR]);
}

- (GtkLevelBarMode)mode
{
	return gtk_level_bar_get_mode([self LEVELBAR]);
}

- (bool)offsetValueWithName:(OFString*)name value:(gdouble*)value
{
	return gtk_level_bar_get_offset_value([self LEVELBAR], [name UTF8String], value);
}

- (gdouble)value
{
	return gtk_level_bar_get_value([self LEVELBAR]);
}

- (void)removeOffsetValue:(OFString*)name
{
	gtk_level_bar_remove_offset_value([self LEVELBAR], [name UTF8String]);
}

- (void)setInverted:(bool)inverted
{
	gtk_level_bar_set_inverted([self LEVELBAR], inverted);
}

- (void)setMaxValue:(gdouble)value
{
	gtk_level_bar_set_max_value([self LEVELBAR], value);
}

- (void)setMinValue:(gdouble)value
{
	gtk_level_bar_set_min_value([self LEVELBAR], value);
}

- (void)setMode:(GtkLevelBarMode)mode
{
	gtk_level_bar_set_mode([self LEVELBAR], mode);
}

- (void)setValue:(gdouble)value
{
	gtk_level_bar_set_value([self LEVELBAR], value);
}


@end