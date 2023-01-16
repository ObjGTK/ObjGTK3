/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWidget.h"

/**
 * #GtkHSV is the “color wheel” part of a complete color selector widget.
 * It allows to select a color by determining its HSV components in an
 * intuitive way. Moving the selection around the outer ring changes the hue,
 * and moving the selection point inside the inner triangle changes value and
 * saturation.
 * 
 * #GtkHSV has been deprecated together with #GtkColorSelection, where
 * it was used.
 *
 */
@interface OGTKHSV : OGTKWidget
{

}

/**
 * Functions
 */
+ (void)toRgbWithH:(gdouble)h s:(gdouble)s v:(gdouble)v r:(gdouble*)r g:(gdouble*)g b:(gdouble*)b;

/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkHSV*)HSV;

/**
 * Queries the current color in an HSV color selector.
 * Returned values will be in the [0.0, 1.0] range.
 *
 * @param h Return value for the hue
 * @param s Return value for the saturation
 * @param v Return value for the value
 */
- (void)colorWithH:(gdouble*)h s:(gdouble*)s v:(gdouble*)v;

/**
 * Queries the size and ring width of an HSV color selector.
 *
 * @param size Return value for the diameter of the hue ring
 * @param ringWidth Return value for the width of the hue ring
 */
- (void)metricsWithSize:(gint*)size ringWidth:(gint*)ringWidth;

/**
 * An HSV color selector can be said to be adjusting if multiple rapid
 * changes are being made to its value, for example, when the user is
 * adjusting the value with the mouse. This function queries whether
 * the HSV color selector is being adjusted or not.
 *
 * @return %TRUE if clients can ignore changes to the color value,
 *     since they may be transitory, or %FALSE if they should consider
 *     the color value status to be final.
 */
- (bool)isAdjusting;

/**
 * Sets the current color in an HSV color selector.
 * Color component values must be in the [0.0, 1.0] range.
 *
 * @param h Hue
 * @param s Saturation
 * @param v Value
 */
- (void)setColorWithH:(double)h s:(double)s v:(double)v;

/**
 * Sets the size and ring width of an HSV color selector.
 *
 * @param size Diameter for the hue ring
 * @param ringWidth Width of the hue ring
 */
- (void)setMetricsWithSize:(gint)size ringWidth:(gint)ringWidth;

@end