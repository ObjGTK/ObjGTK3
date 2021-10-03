/*
 * OGTKTextTagTable.h
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

@interface OGTKTextTagTable : OGTKBase
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkTextTagTable*)TEXTTAGTABLE;

/**
 * - (bool*)add:(GtkTextTag*)tag;
 *
 * @param tag
 * @returns bool
 */
- (bool)add:(GtkTextTag*)tag;

/**
 * - (void*)foreachWithFunc:(GtkTextTagTableForeach)func andData:(gpointer)data;
 *
 * @param func
 * @param data
 */
- (void)foreachWithFunc:(GtkTextTagTableForeach)func andData:(gpointer)data;

/**
 * - (gint*)getSize;
 *
 * @returns gint
 */
- (gint)getSize;

/**
 * - (GtkTextTag**)lookup:(OFString*)name;
 *
 * @param name
 * @returns GtkTextTag*
 */
- (GtkTextTag*)lookup:(OFString*)name;

/**
 * - (void*)remove:(GtkTextTag*)tag;
 *
 * @param tag
 */
- (void)remove:(GtkTextTag*)tag;

@end