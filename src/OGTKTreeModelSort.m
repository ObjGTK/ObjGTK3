/*
 * OGTKTreeModelSort.m
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
#import "OGTKTreeModelSort.h"

@implementation OGTKTreeModelSort

- (id)initWithModel:(GtkTreeModel*)childModel
{
	self = [super initWithGObject:(GObject*)gtk_tree_model_sort_new_with_model(childModel)];

	return self;
}

- (GtkTreeModelSort*)TREEMODELSORT
{
	return GTK_TREE_MODEL_SORT([self GOBJECT]);
}

- (void)clearCache
{
	gtk_tree_model_sort_clear_cache(GTK_TREE_MODEL_SORT([self GOBJECT]));
}

- (bool)convertChildIterToIterWithSortIter:(GtkTreeIter*)sortIter andChildIter:(GtkTreeIter*)childIter
{
	return gtk_tree_model_sort_convert_child_iter_to_iter(GTK_TREE_MODEL_SORT([self GOBJECT]), sortIter, childIter);
}

- (GtkTreePath*)convertChildPathToPath:(GtkTreePath*)childPath
{
	return gtk_tree_model_sort_convert_child_path_to_path(GTK_TREE_MODEL_SORT([self GOBJECT]), childPath);
}

- (void)convertIterToChildIterWithChildIter:(GtkTreeIter*)childIter andSortedIter:(GtkTreeIter*)sortedIter
{
	gtk_tree_model_sort_convert_iter_to_child_iter(GTK_TREE_MODEL_SORT([self GOBJECT]), childIter, sortedIter);
}

- (GtkTreePath*)convertPathToChildPath:(GtkTreePath*)sortedPath
{
	return gtk_tree_model_sort_convert_path_to_child_path(GTK_TREE_MODEL_SORT([self GOBJECT]), sortedPath);
}

- (GtkTreeModel*)getModel
{
	return gtk_tree_model_sort_get_model(GTK_TREE_MODEL_SORT([self GOBJECT]));
}

- (bool)iterIsValid:(GtkTreeIter*)iter
{
	return gtk_tree_model_sort_iter_is_valid(GTK_TREE_MODEL_SORT([self GOBJECT]), iter);
}

- (void)resetDefaultSortFunc
{
	gtk_tree_model_sort_reset_default_sort_func(GTK_TREE_MODEL_SORT([self GOBJECT]));
}


@end