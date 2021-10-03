/*
 * OGTKRange.h
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
#import "OGTKWidget.h"

@interface OGTKRange : OGTKWidget
{

}


/**
 * Methods
 */

- (GtkRange*)RANGE;

/**
 * - (GtkAdjustment**)getAdjustment;
 *
 * @returns GtkAdjustment*
 */
- (GtkAdjustment*)getAdjustment;

/**
 * - (gdouble*)getFillLevel;
 *
 * @returns gdouble
 */
- (gdouble)getFillLevel;

/**
 * - (bool*)getFlippable;
 *
 * @returns bool
 */
- (bool)getFlippable;

/**
 * - (bool*)getInverted;
 *
 * @returns bool
 */
- (bool)getInverted;

/**
 * - (GtkSensitivityType*)getLowerStepperSensitivity;
 *
 * @returns GtkSensitivityType
 */
- (GtkSensitivityType)getLowerStepperSensitivity;

/**
 * - (gint*)getMinSliderSize;
 *
 * @returns gint
 */
- (gint)getMinSliderSize;

/**
 * - (void*)getRangeRect:(GdkRectangle*)rangeRect;
 *
 * @param rangeRect
 */
- (void)getRangeRect:(GdkRectangle*)rangeRect;

/**
 * - (bool*)getRestrictToFillLevel;
 *
 * @returns bool
 */
- (bool)getRestrictToFillLevel;

/**
 * - (gint*)getRoundDigits;
 *
 * @returns gint
 */
- (gint)getRoundDigits;

/**
 * - (bool*)getShowFillLevel;
 *
 * @returns bool
 */
- (bool)getShowFillLevel;

/**
 * - (void*)getSliderRangeWithSliderStart:(gint*)sliderStart andSliderEnd:(gint*)sliderEnd;
 *
 * @param sliderStart
 * @param sliderEnd
 */
- (void)getSliderRangeWithSliderStart:(gint*)sliderStart andSliderEnd:(gint*)sliderEnd;

/**
 * - (bool*)getSliderSizeFixed;
 *
 * @returns bool
 */
- (bool)getSliderSizeFixed;

/**
 * - (GtkSensitivityType*)getUpperStepperSensitivity;
 *
 * @returns GtkSensitivityType
 */
- (GtkSensitivityType)getUpperStepperSensitivity;

/**
 * - (gdouble*)getValue;
 *
 * @returns gdouble
 */
- (gdouble)getValue;

/**
 * - (void*)setAdjustment:(GtkAdjustment*)adjustment;
 *
 * @param adjustment
 */
- (void)setAdjustment:(GtkAdjustment*)adjustment;

/**
 * - (void*)setFillLevel:(gdouble)fillLevel;
 *
 * @param fillLevel
 */
- (void)setFillLevel:(gdouble)fillLevel;

/**
 * - (void*)setFlippable:(bool)flippable;
 *
 * @param flippable
 */
- (void)setFlippable:(bool)flippable;

/**
 * - (void*)setIncrementsWithStep:(gdouble)step andPage:(gdouble)page;
 *
 * @param step
 * @param page
 */
- (void)setIncrementsWithStep:(gdouble)step andPage:(gdouble)page;

/**
 * - (void*)setInverted:(bool)setting;
 *
 * @param setting
 */
- (void)setInverted:(bool)setting;

/**
 * - (void*)setLowerStepperSensitivity:(GtkSensitivityType)sensitivity;
 *
 * @param sensitivity
 */
- (void)setLowerStepperSensitivity:(GtkSensitivityType)sensitivity;

/**
 * - (void*)setMinSliderSize:(gint)minSize;
 *
 * @param minSize
 */
- (void)setMinSliderSize:(gint)minSize;

/**
 * - (void*)setRangeWithMin:(gdouble)min andMax:(gdouble)max;
 *
 * @param min
 * @param max
 */
- (void)setRangeWithMin:(gdouble)min andMax:(gdouble)max;

/**
 * - (void*)setRestrictToFillLevel:(bool)restrictToFillLevel;
 *
 * @param restrictToFillLevel
 */
- (void)setRestrictToFillLevel:(bool)restrictToFillLevel;

/**
 * - (void*)setRoundDigits:(gint)roundDigits;
 *
 * @param roundDigits
 */
- (void)setRoundDigits:(gint)roundDigits;

/**
 * - (void*)setShowFillLevel:(bool)showFillLevel;
 *
 * @param showFillLevel
 */
- (void)setShowFillLevel:(bool)showFillLevel;

/**
 * - (void*)setSliderSizeFixed:(bool)sizeFixed;
 *
 * @param sizeFixed
 */
- (void)setSliderSizeFixed:(bool)sizeFixed;

/**
 * - (void*)setUpperStepperSensitivity:(GtkSensitivityType)sensitivity;
 *
 * @param sensitivity
 */
- (void)setUpperStepperSensitivity:(GtkSensitivityType)sensitivity;

/**
 * - (void*)setValue:(gdouble)value;
 *
 * @param value
 */
- (void)setValue:(gdouble)value;

@end