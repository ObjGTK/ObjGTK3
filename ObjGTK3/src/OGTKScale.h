/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRange.h"

@class OGTKWidget;
@class OGTKAdjustment;
@class OGPangoLayout;

/**
 * A GtkScale is a slider control used to select a numeric value.
 * To use it, you’ll probably want to investigate the methods on
 * its base class, #GtkRange, in addition to the methods for GtkScale itself.
 * To set the value of a scale, you would normally use gtk_range_set_value().
 * To detect changes to the value, you would normally use the
 * #GtkRange::value-changed signal.
 * 
 * Note that using the same upper and lower bounds for the #GtkScale (through
 * the #GtkRange methods) will hide the slider itself. This is useful for
 * applications that want to show an undeterminate value on the scale, without
 * changing the layout of the application (such as movie or music players).
 * 
 * # GtkScale as GtkBuildable
 * 
 * GtkScale supports a custom <marks> element, which can contain multiple
 * <mark> elements. The “value” and “position” attributes have the same
 * meaning as gtk_scale_add_mark() parameters of the same name. If the
 * element is not empty, its content is taken as the markup to show at
 * the mark. It can be translated with the usual ”translatable” and
 * “context” attributes.
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * scale[.fine-tune][.marks-before][.marks-after]
 * ├── marks.top
 * │   ├── mark
 * │   ┊    ├── [label]
 * │   ┊    ╰── indicator
 * ┊   ┊
 * │   ╰── mark
 * ├── [value]
 * ├── contents
 * │   ╰── trough
 * │       ├── slider
 * │       ├── [highlight]
 * │       ╰── [fill]
 * ╰── marks.bottom
 *     ├── mark
 *     ┊    ├── indicator
 *     ┊    ╰── [label]
 *     ╰── mark
 * ]|
 * 
 * GtkScale has a main CSS node with name scale and a subnode for its contents,
 * with subnodes named trough and slider.
 * 
 * The main node gets the style class .fine-tune added when the scale is in
 * 'fine-tuning' mode.
 * 
 * If the scale has an origin (see gtk_scale_set_has_origin()), there is a
 * subnode with name highlight below the trough node that is used for rendering
 * the highlighted part of the trough.
 * 
 * If the scale is showing a fill level (see gtk_range_set_show_fill_level()),
 * there is a subnode with name fill below the trough node that is used for
 * rendering the filled in part of the trough.
 * 
 * If marks are present, there is a marks subnode before or after the contents
 * node, below which each mark gets a node with name mark. The marks nodes get
 * either the .top or .bottom style class.
 * 
 * The mark node has a subnode named indicator. If the mark has text, it also
 * has a subnode named label. When the mark is either above or left of the
 * scale, the label subnode is the first when present. Otherwise, the indicator
 * subnode is the first.
 * 
 * The main CSS node gets the 'marks-before' and/or 'marks-after' style classes
 * added depending on what marks are present.
 * 
 * If the scale is displaying the value (see #GtkScale:draw-value), there is
 * subnode with name value.
 *
 */
@interface OGTKScale : OGTKRange
{

}


/**
 * Constructors
 */
- (instancetype)initWithOrientation:(GtkOrientation)orientation adjustment:(OGTKAdjustment*)adjustment;
- (instancetype)initWithRangeWithOrientation:(GtkOrientation)orientation min:(gdouble)min max:(gdouble)max step:(gdouble)step;

/**
 * Methods
 */

- (GtkScale*)SCALE;

/**
 * Adds a mark at @value.
 * 
 * A mark is indicated visually by drawing a tick mark next to the scale,
 * and GTK+ makes it easy for the user to position the scale exactly at the
 * marks value.
 * 
 * If @markup is not %NULL, text is shown next to the tick mark.
 * 
 * To remove marks from a scale, use gtk_scale_clear_marks().
 *
 * @param value the value at which the mark is placed, must be between
 *   the lower and upper limits of the scales’ adjustment
 * @param position where to draw the mark. For a horizontal scale, #GTK_POS_TOP
 *   and %GTK_POS_LEFT are drawn above the scale, anything else below.
 *   For a vertical scale, #GTK_POS_LEFT and %GTK_POS_TOP are drawn to
 *   the left of the scale, anything else to the right.
 * @param markup Text to be shown at the mark, using [Pango markup][PangoMarkupFormat], or %NULL
 */
- (void)addMarkWithValue:(gdouble)value position:(GtkPositionType)position markup:(OFString*)markup;

/**
 * Removes any marks that have been added with gtk_scale_add_mark().
 *
 */
- (void)clearMarks;

/**
 * Gets the number of decimal places that are displayed in the value.
 *
 * @return the number of decimal places that are displayed
 */
- (gint)digits;

/**
 * Returns whether the current value is displayed as a string
 * next to the slider.
 *
 * @return whether the current value is displayed as a string
 */
- (bool)drawValue;

/**
 * Returns whether the scale has an origin.
 *
 * @return %TRUE if the scale has an origin.
 */
- (bool)hasOrigin;

/**
 * Gets the #PangoLayout used to display the scale. The returned
 * object is owned by the scale so does not need to be freed by
 * the caller.
 *
 * @return the #PangoLayout for this scale,
 *     or %NULL if the #GtkScale:draw-value property is %FALSE.
 */
- (OGPangoLayout*)layout;

/**
 * Obtains the coordinates where the scale will draw the
 * #PangoLayout representing the text in the scale. Remember
 * when using the #PangoLayout function you need to convert to
 * and from pixels using PANGO_PIXELS() or #PANGO_SCALE.
 * 
 * If the #GtkScale:draw-value property is %FALSE, the return
 * values are undefined.
 *
 * @param x location to store X offset of layout, or %NULL
 * @param y location to store Y offset of layout, or %NULL
 */
- (void)layoutOffsetsWithX:(gint*)x y:(gint*)y;

/**
 * Gets the position in which the current value is displayed.
 *
 * @return the position in which the current value is displayed
 */
- (GtkPositionType)valuePos;

/**
 * Sets the number of decimal places that are displayed in the value. Also
 * causes the value of the adjustment to be rounded to this number of digits,
 * so the retrieved value matches the displayed one, if #GtkScale:draw-value is
 * %TRUE when the value changes. If you want to enforce rounding the value when
 * #GtkScale:draw-value is %FALSE, you can set #GtkRange:round-digits instead.
 * 
 * Note that rounding to a small number of digits can interfere with
 * the smooth autoscrolling that is built into #GtkScale. As an alternative,
 * you can use the #GtkScale::format-value signal to format the displayed
 * value yourself.
 *
 * @param digits the number of decimal places to display,
 *     e.g. use 1 to display 1.0, 2 to display 1.00, etc
 */
- (void)setDigits:(gint)digits;

/**
 * Specifies whether the current value is displayed as a string next
 * to the slider.
 *
 * @param drawValue %TRUE to draw the value
 */
- (void)setDrawValue:(bool)drawValue;

/**
 * If #GtkScale:has-origin is set to %TRUE (the default), the scale will
 * highlight the part of the trough between the origin (bottom or left side)
 * and the current value.
 *
 * @param hasOrigin %TRUE if the scale has an origin
 */
- (void)setHasOrigin:(bool)hasOrigin;

/**
 * Sets the position in which the current value is displayed.
 *
 * @param pos the position in which the current value is displayed
 */
- (void)setValuePos:(GtkPositionType)pos;

@end