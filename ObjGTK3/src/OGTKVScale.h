/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKScale.h"

@class OGTKAdjustment;
@class OGTKWidget;

/**
 * The #GtkVScale widget is used to allow the user to select a value using
 * a vertical slider. To create one, use gtk_hscale_new_with_range().
 * 
 * The position to show the current value, and the number of decimal places
 * shown can be set using the parent #GtkScale class’s functions.
 * 
 * GtkVScale has been deprecated, use #GtkScale instead.
 *
 */
@interface OGTKVScale : OGTKScale
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKAdjustment*)adjustment;
- (instancetype)initWithRangeWithMin:(gdouble)min max:(gdouble)max step:(gdouble)step;

/**
 * Methods
 */

- (GtkVScale*)VSCALE;

@end