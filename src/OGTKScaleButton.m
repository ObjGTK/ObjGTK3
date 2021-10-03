/*
 * OGTKScaleButton.m
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
#import "OGTKScaleButton.h"

@implementation OGTKScaleButton

- (id)initWithSize:(GtkIconSize)size andMin:(gdouble)min andMax:(gdouble)max andStep:(gdouble)step andIcons:(const gchar**)icons
{
	self = [super initWithGObject:(GObject*)gtk_scale_button_new(size, min, max, step, icons)];

	return self;
}

- (GtkScaleButton*)SCALEBUTTON
{
	return GTK_SCALE_BUTTON([self GOBJECT]);
}

- (GtkAdjustment*)getAdjustment
{
	return gtk_scale_button_get_adjustment(GTK_SCALE_BUTTON([self GOBJECT]));
}

- (OGTKWidget*)getMinusButton
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_scale_button_get_minus_button(GTK_SCALE_BUTTON([self GOBJECT]))];
}

- (OGTKWidget*)getPlusButton
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_scale_button_get_plus_button(GTK_SCALE_BUTTON([self GOBJECT]))];
}

- (OGTKWidget*)getPopup
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_scale_button_get_popup(GTK_SCALE_BUTTON([self GOBJECT]))];
}

- (gdouble)getValue
{
	return gtk_scale_button_get_value(GTK_SCALE_BUTTON([self GOBJECT]));
}

- (void)setAdjustment:(GtkAdjustment*)adjustment
{
	gtk_scale_button_set_adjustment(GTK_SCALE_BUTTON([self GOBJECT]), adjustment);
}

- (void)setIcons:(const gchar**)icons
{
	gtk_scale_button_set_icons(GTK_SCALE_BUTTON([self GOBJECT]), icons);
}

- (void)setValue:(gdouble)value
{
	gtk_scale_button_set_value(GTK_SCALE_BUTTON([self GOBJECT]), value);
}


@end