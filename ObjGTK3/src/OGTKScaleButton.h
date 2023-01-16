/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKButton.h"

@class OGTKWidget;
@class OGTKAdjustment;

/**
 * #GtkScaleButton provides a button which pops up a scale widget.
 * This kind of widget is commonly used for volume controls in multimedia
 * applications, and GTK+ provides a #GtkVolumeButton subclass that
 * is tailored for this use case.
 * 
 * # CSS nodes
 * 
 * GtkScaleButton has a single CSS node with name button. To differentiate
 * it from a plain #GtkButton, it gets the .scale style class.
 * 
 * The popup widget that contains the scale has a .scale-popup style class.
 *
 */
@interface OGTKScaleButton : OGTKButton
{

}


/**
 * Constructors
 */
- (instancetype)initWithSize:(GtkIconSize)size min:(gdouble)min max:(gdouble)max step:(gdouble)step icons:(const gchar**)icons;

/**
 * Methods
 */

- (GtkScaleButton*)SCALEBUTTON;

/**
 * Gets the #GtkAdjustment associated with the #GtkScaleButton’s scale.
 * See gtk_range_get_adjustment() for details.
 *
 * @return the adjustment associated with the scale
 */
- (OGTKAdjustment*)adjustment;

/**
 * Retrieves the minus button of the #GtkScaleButton.
 *
 * @return the minus button of the #GtkScaleButton as a #GtkButton
 */
- (OGTKWidget*)minusButton;

/**
 * Retrieves the plus button of the #GtkScaleButton.
 *
 * @return the plus button of the #GtkScaleButton as a #GtkButton
 */
- (OGTKWidget*)plusButton;

/**
 * Retrieves the popup of the #GtkScaleButton.
 *
 * @return the popup of the #GtkScaleButton
 */
- (OGTKWidget*)popup;

/**
 * Gets the current value of the scale button.
 *
 * @return current value of the scale button
 */
- (gdouble)value;

/**
 * Sets the #GtkAdjustment to be used as a model
 * for the #GtkScaleButton’s scale.
 * See gtk_range_set_adjustment() for details.
 *
 * @param adjustment a #GtkAdjustment
 */
- (void)setAdjustment:(OGTKAdjustment*)adjustment;

/**
 * Sets the icons to be used by the scale button.
 * For details, see the #GtkScaleButton:icons property.
 *
 * @param icons a %NULL-terminated array of icon names
 */
- (void)setIcons:(const gchar**)icons;

/**
 * Sets the current value of the scale; if the value is outside
 * the minimum or maximum range values, it will be clamped to fit
 * inside them. The scale button emits the #GtkScaleButton::value-changed
 * signal if the value changes.
 *
 * @param value new value of the scale button
 */
- (void)setValue:(gdouble)value;

@end