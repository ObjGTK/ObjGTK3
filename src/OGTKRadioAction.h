/*
 * OGTKRadioAction.h
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
#import "ToggleAction.h"

@interface OGTKRadioAction : ToggleAction
{

}


/**
 * Constructors
 */
- (id)initWithName:(OFString*)name andLabel:(OFString*)label andTooltip:(OFString*)tooltip andStockId:(OFString*)stockId andValue:(gint)value;

/**
 * Methods
 */

- (GtkRadioAction*)RADIOACTION;

/**
 * - (gint*)getCurrentValue;
 *
 * @returns gint
 */
- (gint)getCurrentValue;

/**
 * - (GSList**)getGroup;
 *
 * @returns GSList*
 */
- (GSList*)getGroup;

/**
 * - (void*)joinGroup:(GtkRadioAction*)groupSource;
 *
 * @param groupSource
 */
- (void)joinGroup:(GtkRadioAction*)groupSource;

/**
 * - (void*)setCurrentValue:(gint)currentValue;
 *
 * @param currentValue
 */
- (void)setCurrentValue:(gint)currentValue;

/**
 * - (void*)setGroup:(GSList*)group;
 *
 * @param group
 */
- (void)setGroup:(GSList*)group;

@end