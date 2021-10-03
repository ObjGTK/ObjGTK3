/*
 * OGTKRecentFilter.h
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

@interface OGTKRecentFilter : OGTKBase
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkRecentFilter*)RECENTFILTER;

/**
 * - (void*)addAge:(gint)days;
 *
 * @param days
 */
- (void)addAge:(gint)days;

/**
 * - (void*)addApplication:(OFString*)application;
 *
 * @param application
 */
- (void)addApplication:(OFString*)application;

/**
 * - (void*)addCustomWithNeeded:(GtkRecentFilterFlags)needed andFunc:(GtkRecentFilterFunc)func andData:(gpointer)data andDataDestroy:(GDestroyNotify)dataDestroy;
 *
 * @param needed
 * @param func
 * @param data
 * @param dataDestroy
 */
- (void)addCustomWithNeeded:(GtkRecentFilterFlags)needed andFunc:(GtkRecentFilterFunc)func andData:(gpointer)data andDataDestroy:(GDestroyNotify)dataDestroy;

/**
 * - (void*)addGroup:(OFString*)group;
 *
 * @param group
 */
- (void)addGroup:(OFString*)group;

/**
 * - (void*)addMimeType:(OFString*)mimeType;
 *
 * @param mimeType
 */
- (void)addMimeType:(OFString*)mimeType;

/**
 * - (void*)addPattern:(OFString*)pattern;
 *
 * @param pattern
 */
- (void)addPattern:(OFString*)pattern;

/**
 * - (void*)addPixbufFormats;
 *
 */
- (void)addPixbufFormats;

/**
 * - (bool*)filter:(const GtkRecentFilterInfo*)filterInfo;
 *
 * @param filterInfo
 * @returns bool
 */
- (bool)filter:(const GtkRecentFilterInfo*)filterInfo;

/**
 * - (OFString**)getName;
 *
 * @returns OFString*
 */
- (OFString*)getName;

/**
 * - (GtkRecentFilterFlags*)getNeeded;
 *
 * @returns GtkRecentFilterFlags
 */
- (GtkRecentFilterFlags)getNeeded;

/**
 * - (void*)setName:(OFString*)name;
 *
 * @param name
 */
- (void)setName:(OFString*)name;

@end