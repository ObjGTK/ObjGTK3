/*
 * OGTKTreeModelFilter.h
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

@interface OGTKTreeModelFilter : OGTKBase
{

}


/**
 * Methods
 */

- (GtkTreeModelFilter*)TREEMODELFILTER;

/**
 * - (void*)clearCache;
 *
 */
- (void)clearCache;

/**
 * - (bool*)convertChildIterToIterWithFilterIter:(GtkTreeIter*)filterIter andChildIter:(GtkTreeIter*)childIter;
 *
 * @param filterIter
 * @param childIter
 * @returns bool
 */
- (bool)convertChildIterToIterWithFilterIter:(GtkTreeIter*)filterIter andChildIter:(GtkTreeIter*)childIter;

/**
 * - (GtkTreePath**)convertChildPathToPath:(GtkTreePath*)childPath;
 *
 * @param childPath
 * @returns GtkTreePath*
 */
- (GtkTreePath*)convertChildPathToPath:(GtkTreePath*)childPath;

/**
 * - (void*)convertIterToChildIterWithChildIter:(GtkTreeIter*)childIter andFilterIter:(GtkTreeIter*)filterIter;
 *
 * @param childIter
 * @param filterIter
 */
- (void)convertIterToChildIterWithChildIter:(GtkTreeIter*)childIter andFilterIter:(GtkTreeIter*)filterIter;

/**
 * - (GtkTreePath**)convertPathToChildPath:(GtkTreePath*)filterPath;
 *
 * @param filterPath
 * @returns GtkTreePath*
 */
- (GtkTreePath*)convertPathToChildPath:(GtkTreePath*)filterPath;

/**
 * - (GtkTreeModel**)getModel;
 *
 * @returns GtkTreeModel*
 */
- (GtkTreeModel*)getModel;

/**
 * - (void*)refilter;
 *
 */
- (void)refilter;

/**
 * - (void*)setModifyFuncWithNcolumns:(gint)ncolumns andTypes:(GType*)types andFunc:(GtkTreeModelFilterModifyFunc)func andData:(gpointer)data andDestroy:(GDestroyNotify)destroy;
 *
 * @param ncolumns
 * @param types
 * @param func
 * @param data
 * @param destroy
 */
- (void)setModifyFuncWithNcolumns:(gint)ncolumns andTypes:(GType*)types andFunc:(GtkTreeModelFilterModifyFunc)func andData:(gpointer)data andDestroy:(GDestroyNotify)destroy;

/**
 * - (void*)setVisibleColumn:(gint)column;
 *
 * @param column
 */
- (void)setVisibleColumn:(gint)column;

/**
 * - (void*)setVisibleFuncWithFunc:(GtkTreeModelFilterVisibleFunc)func andData:(gpointer)data andDestroy:(GDestroyNotify)destroy;
 *
 * @param func
 * @param data
 * @param destroy
 */
- (void)setVisibleFuncWithFunc:(GtkTreeModelFilterVisibleFunc)func andData:(gpointer)data andDestroy:(GDestroyNotify)destroy;

@end