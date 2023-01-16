/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWidget.h"

@class OGTKAdjustment;

/**
 * #GtkRange is the common base class for widgets which visualize an
 * adjustment, e.g #GtkScale or #GtkScrollbar.
 * 
 * Apart from signals for monitoring the parameters of the adjustment,
 * #GtkRange provides properties and methods for influencing the sensitivity
 * of the “steppers”. It also provides properties and methods for setting a
 * “fill level” on range widgets. See gtk_range_set_fill_level().
 *
 */
@interface OGTKRange : OGTKWidget
{

}


/**
 * Methods
 */

- (GtkRange*)RANGE;

/**
 * Get the #GtkAdjustment which is the “model” object for #GtkRange.
 * See gtk_range_set_adjustment() for details.
 * The return value does not have a reference added, so should not
 * be unreferenced.
 *
 * @return a #GtkAdjustment
 */
- (OGTKAdjustment*)adjustment;

/**
 * Gets the current position of the fill level indicator.
 *
 * @return The current fill level
 */
- (gdouble)fillLevel;

/**
 * Gets the value set by gtk_range_set_flippable().
 *
 * @return %TRUE if the range is flippable
 */
- (bool)flippable;

/**
 * Gets the value set by gtk_range_set_inverted().
 *
 * @return %TRUE if the range is inverted
 */
- (bool)inverted;

/**
 * Gets the sensitivity policy for the stepper that points to the
 * 'lower' end of the GtkRange’s adjustment.
 *
 * @return The lower stepper’s sensitivity policy.
 */
- (GtkSensitivityType)lowerStepperSensitivity;

/**
 * This function is useful mainly for #GtkRange subclasses.
 * 
 * See gtk_range_set_min_slider_size().
 *
 * @return The minimum size of the range’s slider.
 */
- (gint)minSliderSize;

/**
 * This function returns the area that contains the range’s trough
 * and its steppers, in widget->window coordinates.
 * 
 * This function is useful mainly for #GtkRange subclasses.
 *
 * @param rangeRect return location for the range rectangle
 */
- (void)rangeRect:(GdkRectangle*)rangeRect;

/**
 * Gets whether the range is restricted to the fill level.
 *
 * @return %TRUE if @range is restricted to the fill level.
 */
- (bool)restrictToFillLevel;

/**
 * Gets the number of digits to round the value to when
 * it changes. See #GtkRange::change-value.
 *
 * @return the number of digits to round to
 */
- (gint)roundDigits;

/**
 * Gets whether the range displays the fill level graphically.
 *
 * @return %TRUE if @range shows the fill level.
 */
- (bool)showFillLevel;

/**
 * This function returns sliders range along the long dimension,
 * in widget->window coordinates.
 * 
 * This function is useful mainly for #GtkRange subclasses.
 *
 * @param sliderStart return location for the slider's
 *     start, or %NULL
 * @param sliderEnd return location for the slider's
 *     end, or %NULL
 */
- (void)sliderRangeWithSliderStart:(gint*)sliderStart sliderEnd:(gint*)sliderEnd;

/**
 * This function is useful mainly for #GtkRange subclasses.
 * 
 * See gtk_range_set_slider_size_fixed().
 *
 * @return whether the range’s slider has a fixed size.
 */
- (bool)sliderSizeFixed;

/**
 * Gets the sensitivity policy for the stepper that points to the
 * 'upper' end of the GtkRange’s adjustment.
 *
 * @return The upper stepper’s sensitivity policy.
 */
- (GtkSensitivityType)upperStepperSensitivity;

/**
 * Gets the current value of the range.
 *
 * @return current value of the range.
 */
- (gdouble)value;

/**
 * Sets the adjustment to be used as the “model” object for this range
 * widget. The adjustment indicates the current range value, the
 * minimum and maximum range values, the step/page increments used
 * for keybindings and scrolling, and the page size. The page size
 * is normally 0 for #GtkScale and nonzero for #GtkScrollbar, and
 * indicates the size of the visible area of the widget being scrolled.
 * The page size affects the size of the scrollbar slider.
 *
 * @param adjustment a #GtkAdjustment
 */
- (void)setAdjustment:(OGTKAdjustment*)adjustment;

/**
 * Set the new position of the fill level indicator.
 * 
 * The “fill level” is probably best described by its most prominent
 * use case, which is an indicator for the amount of pre-buffering in
 * a streaming media player. In that use case, the value of the range
 * would indicate the current play position, and the fill level would
 * be the position up to which the file/stream has been downloaded.
 * 
 * This amount of prebuffering can be displayed on the range’s trough
 * and is themeable separately from the trough. To enable fill level
 * display, use gtk_range_set_show_fill_level(). The range defaults
 * to not showing the fill level.
 * 
 * Additionally, it’s possible to restrict the range’s slider position
 * to values which are smaller than the fill level. This is controller
 * by gtk_range_set_restrict_to_fill_level() and is by default
 * enabled.
 *
 * @param fillLevel the new position of the fill level indicator
 */
- (void)setFillLevel:(gdouble)fillLevel;

/**
 * If a range is flippable, it will switch its direction if it is
 * horizontal and its direction is %GTK_TEXT_DIR_RTL.
 * 
 * See gtk_widget_get_direction().
 *
 * @param flippable %TRUE to make the range flippable
 */
- (void)setFlippable:(bool)flippable;

/**
 * Sets the step and page sizes for the range.
 * The step size is used when the user clicks the #GtkScrollbar
 * arrows or moves #GtkScale via arrow keys. The page size
 * is used for example when moving via Page Up or Page Down keys.
 *
 * @param step step size
 * @param page page size
 */
- (void)setIncrementsWithStep:(gdouble)step page:(gdouble)page;

/**
 * Ranges normally move from lower to higher values as the
 * slider moves from top to bottom or left to right. Inverted
 * ranges have higher values at the top or on the right rather than
 * on the bottom or left.
 *
 * @param setting %TRUE to invert the range
 */
- (void)setInverted:(bool)setting;

/**
 * Sets the sensitivity policy for the stepper that points to the
 * 'lower' end of the GtkRange’s adjustment.
 *
 * @param sensitivity the lower stepper’s sensitivity policy.
 */
- (void)setLowerStepperSensitivity:(GtkSensitivityType)sensitivity;

/**
 * Sets the minimum size of the range’s slider.
 * 
 * This function is useful mainly for #GtkRange subclasses.
 *
 * @param minSize The slider’s minimum size
 */
- (void)setMinSliderSize:(gint)minSize;

/**
 * Sets the allowable values in the #GtkRange, and clamps the range
 * value to be between @min and @max. (If the range has a non-zero
 * page size, it is clamped between @min and @max - page-size.)
 *
 * @param min minimum range value
 * @param max maximum range value
 */
- (void)setRangeWithMin:(gdouble)min max:(gdouble)max;

/**
 * Sets whether the slider is restricted to the fill level. See
 * gtk_range_set_fill_level() for a general description of the fill
 * level concept.
 *
 * @param restrictToFillLevel Whether the fill level restricts slider movement.
 */
- (void)setRestrictToFillLevel:(bool)restrictToFillLevel;

/**
 * Sets the number of digits to round the value to when
 * it changes. See #GtkRange::change-value.
 *
 * @param roundDigits the precision in digits, or -1
 */
- (void)setRoundDigits:(gint)roundDigits;

/**
 * Sets whether a graphical fill level is show on the trough. See
 * gtk_range_set_fill_level() for a general description of the fill
 * level concept.
 *
 * @param showFillLevel Whether a fill level indicator graphics is shown.
 */
- (void)setShowFillLevel:(bool)showFillLevel;

/**
 * Sets whether the range’s slider has a fixed size, or a size that
 * depends on its adjustment’s page size.
 * 
 * This function is useful mainly for #GtkRange subclasses.
 *
 * @param sizeFixed %TRUE to make the slider size constant
 */
- (void)setSliderSizeFixed:(bool)sizeFixed;

/**
 * Sets the sensitivity policy for the stepper that points to the
 * 'upper' end of the GtkRange’s adjustment.
 *
 * @param sensitivity the upper stepper’s sensitivity policy.
 */
- (void)setUpperStepperSensitivity:(GtkSensitivityType)sensitivity;

/**
 * Sets the current value of the range; if the value is outside the
 * minimum or maximum range values, it will be clamped to fit inside
 * them. The range emits the #GtkRange::value-changed signal if the
 * value changes.
 *
 * @param value new value of the range
 */
- (void)setValue:(gdouble)value;

@end