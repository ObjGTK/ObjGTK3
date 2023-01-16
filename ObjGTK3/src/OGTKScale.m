/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKScale.h"

#import <OGPango/OGPangoLayout.h>
#import "OGTKAdjustment.h"
#import "OGTKWidget.h"

@implementation OGTKScale

- (instancetype)initWithOrientation:(GtkOrientation)orientation adjustment:(OGTKAdjustment*)adjustment
{
	self = [super initWithGObject:(GObject*)gtk_scale_new(orientation, [adjustment ADJUSTMENT])];

	return self;
}

- (instancetype)initWithRangeWithOrientation:(GtkOrientation)orientation min:(gdouble)min max:(gdouble)max step:(gdouble)step
{
	self = [super initWithGObject:(GObject*)gtk_scale_new_with_range(orientation, min, max, step)];

	return self;
}

- (GtkScale*)SCALE
{
	return GTK_SCALE([self GOBJECT]);
}

- (void)addMarkWithValue:(gdouble)value position:(GtkPositionType)position markup:(OFString*)markup
{
	gtk_scale_add_mark([self SCALE], value, position, [markup UTF8String]);
}

- (void)clearMarks
{
	gtk_scale_clear_marks([self SCALE]);
}

- (gint)digits
{
	return gtk_scale_get_digits([self SCALE]);
}

- (bool)drawValue
{
	return gtk_scale_get_draw_value([self SCALE]);
}

- (bool)hasOrigin
{
	return gtk_scale_get_has_origin([self SCALE]);
}

- (OGPangoLayout*)layout
{
	return [[[OGPangoLayout alloc] initWithGObject:(GObject*)gtk_scale_get_layout([self SCALE])] autorelease];
}

- (void)layoutOffsetsWithX:(gint*)x y:(gint*)y
{
	gtk_scale_get_layout_offsets([self SCALE], x, y);
}

- (GtkPositionType)valuePos
{
	return gtk_scale_get_value_pos([self SCALE]);
}

- (void)setDigits:(gint)digits
{
	gtk_scale_set_digits([self SCALE], digits);
}

- (void)setDrawValue:(bool)drawValue
{
	gtk_scale_set_draw_value([self SCALE], drawValue);
}

- (void)setHasOrigin:(bool)hasOrigin
{
	gtk_scale_set_has_origin([self SCALE], hasOrigin);
}

- (void)setValuePos:(GtkPositionType)pos
{
	gtk_scale_set_value_pos([self SCALE], pos);
}


@end