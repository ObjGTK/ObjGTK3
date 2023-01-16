/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTreeModelSort.h"

@implementation OGTKTreeModelSort

- (instancetype)initWithModel:(GtkTreeModel*)childModel
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
	gtk_tree_model_sort_clear_cache([self TREEMODELSORT]);
}

- (bool)convertChildIterToIterWithSortIter:(GtkTreeIter*)sortIter childIter:(GtkTreeIter*)childIter
{
	return gtk_tree_model_sort_convert_child_iter_to_iter([self TREEMODELSORT], sortIter, childIter);
}

- (GtkTreePath*)convertChildPathToPath:(GtkTreePath*)childPath
{
	return gtk_tree_model_sort_convert_child_path_to_path([self TREEMODELSORT], childPath);
}

- (void)convertIterToChildIterWithChildIter:(GtkTreeIter*)childIter sortedIter:(GtkTreeIter*)sortedIter
{
	gtk_tree_model_sort_convert_iter_to_child_iter([self TREEMODELSORT], childIter, sortedIter);
}

- (GtkTreePath*)convertPathToChildPath:(GtkTreePath*)sortedPath
{
	return gtk_tree_model_sort_convert_path_to_child_path([self TREEMODELSORT], sortedPath);
}

- (GtkTreeModel*)model
{
	return gtk_tree_model_sort_get_model([self TREEMODELSORT]);
}

- (bool)iterIsValid:(GtkTreeIter*)iter
{
	return gtk_tree_model_sort_iter_is_valid([self TREEMODELSORT], iter);
}

- (void)resetDefaultSortFunc
{
	gtk_tree_model_sort_reset_default_sort_func([self TREEMODELSORT]);
}


@end