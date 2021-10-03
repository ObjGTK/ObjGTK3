/*
 * OGTKSettings.h
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

@interface OGTKSettings : OGTKBase
{

}

/**
 * Functions
 */
+ (GtkSettings*)getDefault;
+ (GtkSettings*)getForScreen:(GdkScreen*)screen;
+ (void)installProperty:(GParamSpec*)pspec;
+ (void)installPropertyParserWithPspec:(GParamSpec*)pspec andParser:(GtkRcPropertyParser)parser;

/**
 * Methods
 */

- (GtkSettings*)SETTINGS;

/**
 * - (void*)resetProperty:(OFString*)name;
 *
 * @param name
 */
- (void)resetProperty:(OFString*)name;

/**
 * - (void*)setDoublePropertyWithName:(OFString*)name andVdouble:(gdouble)vdouble andOrigin:(OFString*)origin;
 *
 * @param name
 * @param vdouble
 * @param origin
 */
- (void)setDoublePropertyWithName:(OFString*)name andVdouble:(gdouble)vdouble andOrigin:(OFString*)origin;

/**
 * - (void*)setLongPropertyWithName:(OFString*)name andVlong:(glong)vlong andOrigin:(OFString*)origin;
 *
 * @param name
 * @param vlong
 * @param origin
 */
- (void)setLongPropertyWithName:(OFString*)name andVlong:(glong)vlong andOrigin:(OFString*)origin;

/**
 * - (void*)setPropertyValueWithName:(OFString*)name andSvalue:(const GtkSettingsValue*)svalue;
 *
 * @param name
 * @param svalue
 */
- (void)setPropertyValueWithName:(OFString*)name andSvalue:(const GtkSettingsValue*)svalue;

/**
 * - (void*)setStringPropertyWithName:(OFString*)name andVstring:(OFString*)vstring andOrigin:(OFString*)origin;
 *
 * @param name
 * @param vstring
 * @param origin
 */
- (void)setStringPropertyWithName:(OFString*)name andVstring:(OFString*)vstring andOrigin:(OFString*)origin;

@end