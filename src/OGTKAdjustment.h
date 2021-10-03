/*
 * OGTKAdjustment.h
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
#import "OGTKBase.h"

@interface OGTKAdjustment : OGTKBase
{

}


/**
 * Constructors
 */
- (id)initWithValue:(gdouble)value andLower:(gdouble)lower andUpper:(gdouble)upper andStepIncrement:(gdouble)stepIncrement andPageIncrement:(gdouble)pageIncrement andPageSize:(gdouble)pageSize;

/**
 * Methods
 */

- (GtkAdjustment*)ADJUSTMENT;

/**
 * - (void*)changed;
 *
 */
- (void)changed;

/**
 * - (void*)clampPageWithLower:(gdouble)lower andUpper:(gdouble)upper;
 *
 * @param lower
 * @param upper
 */
- (void)clampPageWithLower:(gdouble)lower andUpper:(gdouble)upper;

/**
 * - (void*)configureWithValue:(gdouble)value andLower:(gdouble)lower andUpper:(gdouble)upper andStepIncrement:(gdouble)stepIncrement andPageIncrement:(gdouble)pageIncrement andPageSize:(gdouble)pageSize;
 *
 * @param value
 * @param lower
 * @param upper
 * @param stepIncrement
 * @param pageIncrement
 * @param pageSize
 */
- (void)configureWithValue:(gdouble)value andLower:(gdouble)lower andUpper:(gdouble)upper andStepIncrement:(gdouble)stepIncrement andPageIncrement:(gdouble)pageIncrement andPageSize:(gdouble)pageSize;

/**
 * - (gdouble*)getLower;
 *
 * @returns gdouble
 */
- (gdouble)getLower;

/**
 * - (gdouble*)getMinimumIncrement;
 *
 * @returns gdouble
 */
- (gdouble)getMinimumIncrement;

/**
 * - (gdouble*)getPageIncrement;
 *
 * @returns gdouble
 */
- (gdouble)getPageIncrement;

/**
 * - (gdouble*)getPageSize;
 *
 * @returns gdouble
 */
- (gdouble)getPageSize;

/**
 * - (gdouble*)getStepIncrement;
 *
 * @returns gdouble
 */
- (gdouble)getStepIncrement;

/**
 * - (gdouble*)getUpper;
 *
 * @returns gdouble
 */
- (gdouble)getUpper;

/**
 * - (gdouble*)getValue;
 *
 * @returns gdouble
 */
- (gdouble)getValue;

/**
 * - (void*)setLower:(gdouble)lower;
 *
 * @param lower
 */
- (void)setLower:(gdouble)lower;

/**
 * - (void*)setPageIncrement:(gdouble)pageIncrement;
 *
 * @param pageIncrement
 */
- (void)setPageIncrement:(gdouble)pageIncrement;

/**
 * - (void*)setPageSize:(gdouble)pageSize;
 *
 * @param pageSize
 */
- (void)setPageSize:(gdouble)pageSize;

/**
 * - (void*)setStepIncrement:(gdouble)stepIncrement;
 *
 * @param stepIncrement
 */
- (void)setStepIncrement:(gdouble)stepIncrement;

/**
 * - (void*)setUpper:(gdouble)upper;
 *
 * @param upper
 */
- (void)setUpper:(gdouble)upper;

/**
 * - (void*)setValue:(gdouble)value;
 *
 * @param value
 */
- (void)setValue:(gdouble)value;

/**
 * - (void*)valueChanged;
 *
 */
- (void)valueChanged;

@end