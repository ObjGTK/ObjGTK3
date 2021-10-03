/*
 * OGTKFileFilter.h
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

@interface OGTKFileFilter : OGTKBase
{

}


/**
 * Constructors
 */
- (id)init;
- (id)initFromGvariant:(GVariant*)variant;

/**
 * Methods
 */

- (GtkFileFilter*)FILEFILTER;

/**
 * - (void*)addCustomWithNeeded:(GtkFileFilterFlags)needed andFunc:(GtkFileFilterFunc)func andData:(gpointer)data andNotify:(GDestroyNotify)notify;
 *
 * @param needed
 * @param func
 * @param data
 * @param notify
 */
- (void)addCustomWithNeeded:(GtkFileFilterFlags)needed andFunc:(GtkFileFilterFunc)func andData:(gpointer)data andNotify:(GDestroyNotify)notify;

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
 * - (bool*)filter:(const GtkFileFilterInfo*)filterInfo;
 *
 * @param filterInfo
 * @returns bool
 */
- (bool)filter:(const GtkFileFilterInfo*)filterInfo;

/**
 * - (OFString**)getName;
 *
 * @returns OFString*
 */
- (OFString*)getName;

/**
 * - (GtkFileFilterFlags*)getNeeded;
 *
 * @returns GtkFileFilterFlags
 */
- (GtkFileFilterFlags)getNeeded;

/**
 * - (void*)setName:(OFString*)name;
 *
 * @param name
 */
- (void)setName:(OFString*)name;

/**
 * - (GVariant**)toGvariant;
 *
 * @returns GVariant*
 */
- (GVariant*)toGvariant;

@end