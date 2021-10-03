/*
 * OGTKListStore.h
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

@interface OGTKListStore : OGTKBase
{

}


/**
 * Constructors
 */
- (id)initvWithNcolumns:(gint)ncolumns andTypes:(GType*)types;

/**
 * Methods
 */

- (GtkListStore*)LISTSTORE;

/**
 * - (void*)append:(GtkTreeIter*)iter;
 *
 * @param iter
 */
- (void)append:(GtkTreeIter*)iter;

/**
 * - (void*)clear;
 *
 */
- (void)clear;

/**
 * - (void*)insertWithIter:(GtkTreeIter*)iter andPosition:(gint)position;
 *
 * @param iter
 * @param position
 */
- (void)insertWithIter:(GtkTreeIter*)iter andPosition:(gint)position;

/**
 * - (void*)insertAfterWithIter:(GtkTreeIter*)iter andSibling:(GtkTreeIter*)sibling;
 *
 * @param iter
 * @param sibling
 */
- (void)insertAfterWithIter:(GtkTreeIter*)iter andSibling:(GtkTreeIter*)sibling;

/**
 * - (void*)insertBeforeWithIter:(GtkTreeIter*)iter andSibling:(GtkTreeIter*)sibling;
 *
 * @param iter
 * @param sibling
 */
- (void)insertBeforeWithIter:(GtkTreeIter*)iter andSibling:(GtkTreeIter*)sibling;

/**
 * - (void*)insertWithValuesvWithIter:(GtkTreeIter*)iter andPosition:(gint)position andColumns:(gint*)columns andValues:(GValue*)values andNvalues:(gint)nvalues;
 *
 * @param iter
 * @param position
 * @param columns
 * @param values
 * @param nvalues
 */
- (void)insertWithValuesvWithIter:(GtkTreeIter*)iter andPosition:(gint)position andColumns:(gint*)columns andValues:(GValue*)values andNvalues:(gint)nvalues;

/**
 * - (bool*)iterIsValid:(GtkTreeIter*)iter;
 *
 * @param iter
 * @returns bool
 */
- (bool)iterIsValid:(GtkTreeIter*)iter;

/**
 * - (void*)moveAfterWithIter:(GtkTreeIter*)iter andPosition:(GtkTreeIter*)position;
 *
 * @param iter
 * @param position
 */
- (void)moveAfterWithIter:(GtkTreeIter*)iter andPosition:(GtkTreeIter*)position;

/**
 * - (void*)moveBeforeWithIter:(GtkTreeIter*)iter andPosition:(GtkTreeIter*)position;
 *
 * @param iter
 * @param position
 */
- (void)moveBeforeWithIter:(GtkTreeIter*)iter andPosition:(GtkTreeIter*)position;

/**
 * - (void*)prepend:(GtkTreeIter*)iter;
 *
 * @param iter
 */
- (void)prepend:(GtkTreeIter*)iter;

/**
 * - (bool*)remove:(GtkTreeIter*)iter;
 *
 * @param iter
 * @returns bool
 */
- (bool)remove:(GtkTreeIter*)iter;

/**
 * - (void*)reorder:(gint*)newOrder;
 *
 * @param newOrder
 */
- (void)reorder:(gint*)newOrder;

/**
 * - (void*)setColumnTypesWithNcolumns:(gint)ncolumns andTypes:(GType*)types;
 *
 * @param ncolumns
 * @param types
 */
- (void)setColumnTypesWithNcolumns:(gint)ncolumns andTypes:(GType*)types;

/**
 * - (void*)setValistWithIter:(GtkTreeIter*)iter andVarArgs:(va_list)varArgs;
 *
 * @param iter
 * @param varArgs
 */
- (void)setValistWithIter:(GtkTreeIter*)iter andVarArgs:(va_list)varArgs;

/**
 * - (void*)setValueWithIter:(GtkTreeIter*)iter andColumn:(gint)column andValue:(GValue*)value;
 *
 * @param iter
 * @param column
 * @param value
 */
- (void)setValueWithIter:(GtkTreeIter*)iter andColumn:(gint)column andValue:(GValue*)value;

/**
 * - (void*)setValuesvWithIter:(GtkTreeIter*)iter andColumns:(gint*)columns andValues:(GValue*)values andNvalues:(gint)nvalues;
 *
 * @param iter
 * @param columns
 * @param values
 * @param nvalues
 */
- (void)setValuesvWithIter:(GtkTreeIter*)iter andColumns:(gint*)columns andValues:(GValue*)values andNvalues:(gint)nvalues;

/**
 * - (void*)swapWithA:(GtkTreeIter*)a andB:(GtkTreeIter*)b;
 *
 * @param a
 * @param b
 */
- (void)swapWithA:(GtkTreeIter*)a andB:(GtkTreeIter*)b;

@end