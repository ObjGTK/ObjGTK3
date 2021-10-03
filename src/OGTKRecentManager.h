/*
 * OGTKRecentManager.h
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

@interface OGTKRecentManager : OGTKBase
{

}

/**
 * Functions
 */
+ (GtkRecentManager*)getDefault;

/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkRecentManager*)RECENTMANAGER;

/**
 * - (bool*)addFullWithUri:(OFString*)uri andRecentData:(const GtkRecentData*)recentData;
 *
 * @param uri
 * @param recentData
 * @returns bool
 */
- (bool)addFullWithUri:(OFString*)uri andRecentData:(const GtkRecentData*)recentData;

/**
 * - (bool*)addItem:(OFString*)uri;
 *
 * @param uri
 * @returns bool
 */
- (bool)addItem:(OFString*)uri;

/**
 * - (GList**)getItems;
 *
 * @returns GList*
 */
- (GList*)getItems;

/**
 * - (bool*)hasItem:(OFString*)uri;
 *
 * @param uri
 * @returns bool
 */
- (bool)hasItem:(OFString*)uri;

/**
 * - (GtkRecentInfo**)lookupItem:(OFString*)uri;
 *
 * @param uri
 * @returns GtkRecentInfo*
 */
- (GtkRecentInfo*)lookupItem:(OFString*)uri;

/**
 * - (bool*)moveItemWithUri:(OFString*)uri andNewUri:(OFString*)newUri;
 *
 * @param uri
 * @param newUri
 * @returns bool
 */
- (bool)moveItemWithUri:(OFString*)uri andNewUri:(OFString*)newUri;

/**
 * - (gint*)purgeItems;
 *
 * @returns gint
 */
- (gint)purgeItems;

/**
 * - (bool*)removeItem:(OFString*)uri;
 *
 * @param uri
 * @returns bool
 */
- (bool)removeItem:(OFString*)uri;

@end