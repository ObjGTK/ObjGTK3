/*
 * OGTKTreeModelSort.h
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

@interface OGTKTreeModelSort : OGTKBase
{

}


/**
 * Constructors
 */
- (id)initWithModel:(GtkTreeModel*)childModel;

/**
 * Methods
 */

- (GtkTreeModelSort*)TREEMODELSORT;

/**
 * - (void*)clearCache;
 *
 */
- (void)clearCache;

/**
 * - (bool*)convertChildIterToIterWithSortIter:(GtkTreeIter*)sortIter andChildIter:(GtkTreeIter*)childIter;
 *
 * @param sortIter
 * @param childIter
 * @returns bool
 */
- (bool)convertChildIterToIterWithSortIter:(GtkTreeIter*)sortIter andChildIter:(GtkTreeIter*)childIter;

/**
 * - (GtkTreePath**)convertChildPathToPath:(GtkTreePath*)childPath;
 *
 * @param childPath
 * @returns GtkTreePath*
 */
- (GtkTreePath*)convertChildPathToPath:(GtkTreePath*)childPath;

/**
 * - (void*)convertIterToChildIterWithChildIter:(GtkTreeIter*)childIter andSortedIter:(GtkTreeIter*)sortedIter;
 *
 * @param childIter
 * @param sortedIter
 */
- (void)convertIterToChildIterWithChildIter:(GtkTreeIter*)childIter andSortedIter:(GtkTreeIter*)sortedIter;

/**
 * - (GtkTreePath**)convertPathToChildPath:(GtkTreePath*)sortedPath;
 *
 * @param sortedPath
 * @returns GtkTreePath*
 */
- (GtkTreePath*)convertPathToChildPath:(GtkTreePath*)sortedPath;

/**
 * - (GtkTreeModel**)getModel;
 *
 * @returns GtkTreeModel*
 */
- (GtkTreeModel*)getModel;

/**
 * - (bool*)iterIsValid:(GtkTreeIter*)iter;
 *
 * @param iter
 * @returns bool
 */
- (bool)iterIsValid:(GtkTreeIter*)iter;

/**
 * - (void*)resetDefaultSortFunc;
 *
 */
- (void)resetDefaultSortFunc;

@end