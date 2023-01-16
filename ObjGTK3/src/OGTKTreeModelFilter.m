/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTreeModelFilter.h"

@implementation OGTKTreeModelFilter

- (GtkTreeModelFilter*)TREEMODELFILTER
{
	return GTK_TREE_MODEL_FILTER([self GOBJECT]);
}

- (void)clearCache
{
	gtk_tree_model_filter_clear_cache([self TREEMODELFILTER]);
}

- (bool)convertChildIterToIterWithFilterIter:(GtkTreeIter*)filterIter childIter:(GtkTreeIter*)childIter
{
	return gtk_tree_model_filter_convert_child_iter_to_iter([self TREEMODELFILTER], filterIter, childIter);
}

- (GtkTreePath*)convertChildPathToPath:(GtkTreePath*)childPath
{
	return gtk_tree_model_filter_convert_child_path_to_path([self TREEMODELFILTER], childPath);
}

- (void)convertIterToChildIterWithChildIter:(GtkTreeIter*)childIter filterIter:(GtkTreeIter*)filterIter
{
	gtk_tree_model_filter_convert_iter_to_child_iter([self TREEMODELFILTER], childIter, filterIter);
}

- (GtkTreePath*)convertPathToChildPath:(GtkTreePath*)filterPath
{
	return gtk_tree_model_filter_convert_path_to_child_path([self TREEMODELFILTER], filterPath);
}

- (GtkTreeModel*)model
{
	return gtk_tree_model_filter_get_model([self TREEMODELFILTER]);
}

- (void)refilter
{
	gtk_tree_model_filter_refilter([self TREEMODELFILTER]);
}

- (void)setModifyFuncWithNcolumns:(gint)ncolumns types:(GType*)types func:(GtkTreeModelFilterModifyFunc)func data:(gpointer)data destroy:(GDestroyNotify)destroy
{
	gtk_tree_model_filter_set_modify_func([self TREEMODELFILTER], ncolumns, types, func, data, destroy);
}

- (void)setVisibleColumn:(gint)column
{
	gtk_tree_model_filter_set_visible_column([self TREEMODELFILTER], column);
}

- (void)setVisibleFuncWithFunc:(GtkTreeModelFilterVisibleFunc)func data:(gpointer)data destroy:(GDestroyNotify)destroy
{
	gtk_tree_model_filter_set_visible_func([self TREEMODELFILTER], func, data, destroy);
}


@end