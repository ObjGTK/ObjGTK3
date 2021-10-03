/*
 * OGTKStyleProperties.h
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

@interface OGTKStyleProperties : OGTKBase
{

}

/**
 * Functions
 */
+ (bool)lookupPropertyWithPropertyName:(OFString*)propertyName andParseFunc:(GtkStylePropertyParser*)parseFunc andPspec:(GParamSpec**)pspec;
+ (void)registerPropertyWithParseFunc:(GtkStylePropertyParser)parseFunc andPspec:(GParamSpec*)pspec;

/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkStyleProperties*)STYLEPROPERTIES;

/**
 * - (void*)clear;
 *
 */
- (void)clear;

/**
 * - (bool*)getPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state andValue:(GValue*)value;
 *
 * @param property
 * @param state
 * @param value
 * @returns bool
 */
- (bool)getPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state andValue:(GValue*)value;

/**
 * - (void*)getValistWithState:(GtkStateFlags)state andArgs:(va_list)args;
 *
 * @param state
 * @param args
 */
- (void)getValistWithState:(GtkStateFlags)state andArgs:(va_list)args;

/**
 * - (GtkSymbolicColor**)lookupColor:(OFString*)name;
 *
 * @param name
 * @returns GtkSymbolicColor*
 */
- (GtkSymbolicColor*)lookupColor:(OFString*)name;

/**
 * - (void*)mapColorWithName:(OFString*)name andColor:(GtkSymbolicColor*)color;
 *
 * @param name
 * @param color
 */
- (void)mapColorWithName:(OFString*)name andColor:(GtkSymbolicColor*)color;

/**
 * - (void*)mergeWithPropsToMerge:(const GtkStyleProperties*)propsToMerge andReplace:(bool)replace;
 *
 * @param propsToMerge
 * @param replace
 */
- (void)mergeWithPropsToMerge:(const GtkStyleProperties*)propsToMerge andReplace:(bool)replace;

/**
 * - (void*)setPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state andValue:(const GValue*)value;
 *
 * @param property
 * @param state
 * @param value
 */
- (void)setPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state andValue:(const GValue*)value;

/**
 * - (void*)setValistWithState:(GtkStateFlags)state andArgs:(va_list)args;
 *
 * @param state
 * @param args
 */
- (void)setValistWithState:(GtkStateFlags)state andArgs:(va_list)args;

/**
 * - (void*)unsetPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state;
 *
 * @param property
 * @param state
 */
- (void)unsetPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state;

@end