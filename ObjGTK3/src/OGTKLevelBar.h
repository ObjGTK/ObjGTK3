/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWidget.h"

/**
 * The #GtkLevelBar is a bar widget that can be used
 * as a level indicator. Typical use cases are displaying the strength
 * of a password, or showing the charge level of a battery.
 * 
 * Use gtk_level_bar_set_value() to set the current value, and
 * gtk_level_bar_add_offset_value() to set the value offsets at which
 * the bar will be considered in a different state. GTK will add a few
 * offsets by default on the level bar: #GTK_LEVEL_BAR_OFFSET_LOW,
 * #GTK_LEVEL_BAR_OFFSET_HIGH and #GTK_LEVEL_BAR_OFFSET_FULL, with
 * values 0.25, 0.75 and 1.0 respectively.
 * 
 * Note that it is your responsibility to update preexisting offsets
 * when changing the minimum or maximum value. GTK+ will simply clamp
 * them to the new range.
 * 
 * ## Adding a custom offset on the bar
 * 
 * |[<!-- language="C" -->
 * 
 * static GtkWidget *
 * create_level_bar (void)
 * {
 *   GtkWidget *widget;
 *   GtkLevelBar *bar;
 * 
 *   widget = gtk_level_bar_new ();
 *   bar = GTK_LEVEL_BAR (widget);
 * 
 *   // This changes the value of the default low offset
 * 
 *   gtk_level_bar_add_offset_value (bar,
 *                                   GTK_LEVEL_BAR_OFFSET_LOW,
 *                                   0.10);
 * 
 *   // This adds a new offset to the bar; the application will
 *   // be able to change its color CSS like this:
 *   //
 *   // levelbar block.my-offset {
 *   //   background-color: magenta;
 *   //   border-style: solid;
 *   //   border-color: black;
 *   //   border-style: 1px;
 *   // }
 * 
 *   gtk_level_bar_add_offset_value (bar, "my-offset", 0.60);
 * 
 *   return widget;
 * }
 * ]|
 * 
 * The default interval of values is between zero and one, but it’s possible to
 * modify the interval using gtk_level_bar_set_min_value() and
 * gtk_level_bar_set_max_value(). The value will be always drawn in proportion to
 * the admissible interval, i.e. a value of 15 with a specified interval between
 * 10 and 20 is equivalent to a value of 0.5 with an interval between 0 and 1.
 * When #GTK_LEVEL_BAR_MODE_DISCRETE is used, the bar level is rendered
 * as a finite number of separated blocks instead of a single one. The number
 * of blocks that will be rendered is equal to the number of units specified by
 * the admissible interval.
 * 
 * For instance, to build a bar rendered with five blocks, it’s sufficient to
 * set the minimum value to 0 and the maximum value to 5 after changing the indicator
 * mode to discrete.
 * 
 * GtkLevelBar was introduced in GTK+ 3.6.
 * 
 * # GtkLevelBar as GtkBuildable
 * 
 * The GtkLevelBar implementation of the GtkBuildable interface supports a
 * custom <offsets> element, which can contain any number of <offset> elements,
 * each of which must have name and value attributes.
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * levelbar[.discrete]
 * ╰── trough
 *     ├── block.filled.level-name
 *     ┊
 *     ├── block.empty
 *     ┊
 * ]|
 * 
 * GtkLevelBar has a main CSS node with name levelbar and one of the style
 * classes .discrete or .continuous and a subnode with name trough. Below the
 * trough node are a number of nodes with name block and style class .filled
 * or .empty. In continuous mode, there is exactly one node of each, in discrete
 * mode, the number of filled and unfilled nodes corresponds to blocks that are
 * drawn. The block.filled nodes also get a style class .level-name corresponding
 * to the level for the current value.
 * 
 * In horizontal orientation, the nodes are always arranged from left to right,
 * regardless of text direction.
 *
 */
@interface OGTKLevelBar : OGTKWidget
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initForIntervalWithMinValue:(gdouble)minValue maxValue:(gdouble)maxValue;

/**
 * Methods
 */

- (GtkLevelBar*)LEVELBAR;

/**
 * Adds a new offset marker on @self at the position specified by @value.
 * When the bar value is in the interval topped by @value (or between @value
 * and #GtkLevelBar:max-value in case the offset is the last one on the bar)
 * a style class named `level-`@name will be applied
 * when rendering the level bar fill.
 * If another offset marker named @name exists, its value will be
 * replaced by @value.
 *
 * @param name the name of the new offset
 * @param value the value for the new offset
 */
- (void)addOffsetValueWithName:(OFString*)name value:(gdouble)value;

/**
 * Return the value of the #GtkLevelBar:inverted property.
 *
 * @return %TRUE if the level bar is inverted
 */
- (bool)inverted;

/**
 * Returns the value of the #GtkLevelBar:max-value property.
 *
 * @return a positive value
 */
- (gdouble)maxValue;

/**
 * Returns the value of the #GtkLevelBar:min-value property.
 *
 * @return a positive value
 */
- (gdouble)minValue;

/**
 * Returns the value of the #GtkLevelBar:mode property.
 *
 * @return a #GtkLevelBarMode
 */
- (GtkLevelBarMode)mode;

/**
 * Fetches the value specified for the offset marker @name in @self,
 * returning %TRUE in case an offset named @name was found.
 *
 * @param name the name of an offset in the bar
 * @param value location where to store the value
 * @return %TRUE if the specified offset is found
 */
- (bool)offsetValueWithName:(OFString*)name value:(gdouble*)value;

/**
 * Returns the value of the #GtkLevelBar:value property.
 *
 * @return a value in the interval between
 *     #GtkLevelBar:min-value and #GtkLevelBar:max-value
 */
- (gdouble)value;

/**
 * Removes an offset marker previously added with
 * gtk_level_bar_add_offset_value().
 *
 * @param name the name of an offset in the bar
 */
- (void)removeOffsetValue:(OFString*)name;

/**
 * Sets the value of the #GtkLevelBar:inverted property.
 *
 * @param inverted %TRUE to invert the level bar
 */
- (void)setInverted:(bool)inverted;

/**
 * Sets the value of the #GtkLevelBar:max-value property.
 * 
 * You probably want to update preexisting level offsets after calling
 * this function.
 *
 * @param value a positive value
 */
- (void)setMaxValue:(gdouble)value;

/**
 * Sets the value of the #GtkLevelBar:min-value property.
 * 
 * You probably want to update preexisting level offsets after calling
 * this function.
 *
 * @param value a positive value
 */
- (void)setMinValue:(gdouble)value;

/**
 * Sets the value of the #GtkLevelBar:mode property.
 *
 * @param mode a #GtkLevelBarMode
 */
- (void)setMode:(GtkLevelBarMode)mode;

/**
 * Sets the value of the #GtkLevelBar:value property.
 *
 * @param value a value in the interval between
 *     #GtkLevelBar:min-value and #GtkLevelBar:max-value
 */
- (void)setValue:(gdouble)value;

@end