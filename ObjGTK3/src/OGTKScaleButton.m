/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKScaleButton.h"

#import "OGTKWidget.h"
#import "OGTKAdjustment.h"

@implementation OGTKScaleButton

- (instancetype)initWithSize:(GtkIconSize)size min:(gdouble)min max:(gdouble)max step:(gdouble)step icons:(const gchar**)icons
{
	self = [super initWithGObject:(GObject*)gtk_scale_button_new(size, min, max, step, icons)];

	return self;
}

- (GtkScaleButton*)SCALEBUTTON
{
	return GTK_SCALE_BUTTON([self GOBJECT]);
}

- (OGTKAdjustment*)adjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_scale_button_get_adjustment([self SCALEBUTTON])] autorelease];
}

- (OGTKWidget*)minusButton
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_scale_button_get_minus_button([self SCALEBUTTON])] autorelease];
}

- (OGTKWidget*)plusButton
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_scale_button_get_plus_button([self SCALEBUTTON])] autorelease];
}

- (OGTKWidget*)popup
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_scale_button_get_popup([self SCALEBUTTON])] autorelease];
}

- (gdouble)value
{
	return gtk_scale_button_get_value([self SCALEBUTTON]);
}

- (void)setAdjustment:(OGTKAdjustment*)adjustment
{
	gtk_scale_button_set_adjustment([self SCALEBUTTON], [adjustment ADJUSTMENT]);
}

- (void)setIcons:(const gchar**)icons
{
	gtk_scale_button_set_icons([self SCALEBUTTON], icons);
}

- (void)setValue:(gdouble)value
{
	gtk_scale_button_set_value([self SCALEBUTTON], value);
}


@end