/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

/**
 * The #GtkAdjustment object represents a value which has an associated lower
 * and upper bound, together with step and page increments, and a page size.
 * It is used within several GTK+ widgets, including #GtkSpinButton, #GtkViewport,
 * and #GtkRange (which is a base class for #GtkScrollbar and #GtkScale).
 * 
 * The #GtkAdjustment object does not update the value itself. Instead
 * it is left up to the owner of the #GtkAdjustment to control the value.
 *
 */
@interface OGTKAdjustment : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)initWithValue:(gdouble)value lower:(gdouble)lower upper:(gdouble)upper stepIncrement:(gdouble)stepIncrement pageIncrement:(gdouble)pageIncrement pageSize:(gdouble)pageSize;

/**
 * Methods
 */

- (GtkAdjustment*)ADJUSTMENT;

/**
 * Emits a #GtkAdjustment::changed signal from the #GtkAdjustment.
 * This is typically called by the owner of the #GtkAdjustment after it has
 * changed any of the #GtkAdjustment properties other than the value.
 *
 */
- (void)changed;

/**
 * Updates the #GtkAdjustment:value property to ensure that the range
 * between @lower and @upper is in the current page (i.e. between
 * #GtkAdjustment:value and #GtkAdjustment:value + #GtkAdjustment:page-size).
 * If the range is larger than the page size, then only the start of it will
 * be in the current page.
 * 
 * A #GtkAdjustment::value-changed signal will be emitted if the value is changed.
 *
 * @param lower the lower value
 * @param upper the upper value
 */
- (void)clampPageWithLower:(gdouble)lower upper:(gdouble)upper;

/**
 * Sets all properties of the adjustment at once.
 * 
 * Use this function to avoid multiple emissions of the
 * #GtkAdjustment::changed signal. See gtk_adjustment_set_lower()
 * for an alternative way of compressing multiple emissions of
 * #GtkAdjustment::changed into one.
 *
 * @param value the new value
 * @param lower the new minimum value
 * @param upper the new maximum value
 * @param stepIncrement the new step increment
 * @param pageIncrement the new page increment
 * @param pageSize the new page size
 */
- (void)configureWithValue:(gdouble)value lower:(gdouble)lower upper:(gdouble)upper stepIncrement:(gdouble)stepIncrement pageIncrement:(gdouble)pageIncrement pageSize:(gdouble)pageSize;

/**
 * Retrieves the minimum value of the adjustment.
 *
 * @return The current minimum value of the adjustment
 */
- (gdouble)lower;

/**
 * Gets the smaller of step increment and page increment.
 *
 * @return the minimum increment of @adjustment
 */
- (gdouble)minimumIncrement;

/**
 * Retrieves the page increment of the adjustment.
 *
 * @return The current page increment of the adjustment
 */
- (gdouble)pageIncrement;

/**
 * Retrieves the page size of the adjustment.
 *
 * @return The current page size of the adjustment
 */
- (gdouble)pageSize;

/**
 * Retrieves the step increment of the adjustment.
 *
 * @return The current step increment of the adjustment.
 */
- (gdouble)stepIncrement;

/**
 * Retrieves the maximum value of the adjustment.
 *
 * @return The current maximum value of the adjustment
 */
- (gdouble)upper;

/**
 * Gets the current value of the adjustment.
 * See gtk_adjustment_set_value().
 *
 * @return The current value of the adjustment
 */
- (gdouble)value;

/**
 * Sets the minimum value of the adjustment.
 * 
 * When setting multiple adjustment properties via their individual
 * setters, multiple #GtkAdjustment::changed signals will be emitted.
 * However, since the emission of the #GtkAdjustment::changed signal
 * is tied to the emission of the #GObject::notify signals of the changed
 * properties, it’s possible to compress the #GtkAdjustment::changed
 * signals into one by calling g_object_freeze_notify() and
 * g_object_thaw_notify() around the calls to the individual setters.
 * 
 * Alternatively, using a single g_object_set() for all the properties
 * to change, or using gtk_adjustment_configure() has the same effect
 * of compressing #GtkAdjustment::changed emissions.
 *
 * @param lower the new minimum value
 */
- (void)setLower:(gdouble)lower;

/**
 * Sets the page increment of the adjustment.
 * 
 * See gtk_adjustment_set_lower() about how to compress multiple
 * emissions of the #GtkAdjustment::changed signal when setting
 * multiple adjustment properties.
 *
 * @param pageIncrement the new page increment
 */
- (void)setPageIncrement:(gdouble)pageIncrement;

/**
 * Sets the page size of the adjustment.
 * 
 * See gtk_adjustment_set_lower() about how to compress multiple
 * emissions of the GtkAdjustment::changed signal when setting
 * multiple adjustment properties.
 *
 * @param pageSize the new page size
 */
- (void)setPageSize:(gdouble)pageSize;

/**
 * Sets the step increment of the adjustment.
 * 
 * See gtk_adjustment_set_lower() about how to compress multiple
 * emissions of the #GtkAdjustment::changed signal when setting
 * multiple adjustment properties.
 *
 * @param stepIncrement the new step increment
 */
- (void)setStepIncrement:(gdouble)stepIncrement;

/**
 * Sets the maximum value of the adjustment.
 * 
 * Note that values will be restricted by `upper - page-size`
 * if the page-size property is nonzero.
 * 
 * See gtk_adjustment_set_lower() about how to compress multiple
 * emissions of the #GtkAdjustment::changed signal when setting
 * multiple adjustment properties.
 *
 * @param upper the new maximum value
 */
- (void)setUpper:(gdouble)upper;

/**
 * Sets the #GtkAdjustment value. The value is clamped to lie between
 * #GtkAdjustment:lower and #GtkAdjustment:upper.
 * 
 * Note that for adjustments which are used in a #GtkScrollbar, the
 * effective range of allowed values goes from #GtkAdjustment:lower to
 * #GtkAdjustment:upper - #GtkAdjustment:page-size.
 *
 * @param value the new value
 */
- (void)setValue:(gdouble)value;

/**
 * Emits a #GtkAdjustment::value-changed signal from the #GtkAdjustment.
 * This is typically called by the owner of the #GtkAdjustment after it has
 * changed the #GtkAdjustment:value property.
 *
 */
- (void)valueChanged;

@end