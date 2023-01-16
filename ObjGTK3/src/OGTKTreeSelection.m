/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTreeSelection.h"

#import "OGTKTreeView.h"

@implementation OGTKTreeSelection

- (GtkTreeSelection*)TREESELECTION
{
	return GTK_TREE_SELECTION([self GOBJECT]);
}

- (gint)countSelectedRows
{
	return gtk_tree_selection_count_selected_rows([self TREESELECTION]);
}

- (GtkSelectionMode)mode
{
	return gtk_tree_selection_get_mode([self TREESELECTION]);
}

- (GtkTreeSelectionFunc)selectFunction
{
	return gtk_tree_selection_get_select_function([self TREESELECTION]);
}

- (bool)selectedWithModel:(GtkTreeModel**)model iter:(GtkTreeIter*)iter
{
	return gtk_tree_selection_get_selected([self TREESELECTION], model, iter);
}

- (GList*)selectedRows:(GtkTreeModel**)model
{
	return gtk_tree_selection_get_selected_rows([self TREESELECTION], model);
}

- (OGTKTreeView*)treeView
{
	return [[[OGTKTreeView alloc] initWithGObject:(GObject*)gtk_tree_selection_get_tree_view([self TREESELECTION])] autorelease];
}

- (gpointer)userData
{
	return gtk_tree_selection_get_user_data([self TREESELECTION]);
}

- (bool)iterIsSelected:(GtkTreeIter*)iter
{
	return gtk_tree_selection_iter_is_selected([self TREESELECTION], iter);
}

- (bool)pathIsSelected:(GtkTreePath*)path
{
	return gtk_tree_selection_path_is_selected([self TREESELECTION], path);
}

- (void)selectAll
{
	gtk_tree_selection_select_all([self TREESELECTION]);
}

- (void)selectIter:(GtkTreeIter*)iter
{
	gtk_tree_selection_select_iter([self TREESELECTION], iter);
}

- (void)selectPath:(GtkTreePath*)path
{
	gtk_tree_selection_select_path([self TREESELECTION], path);
}

- (void)selectRangeWithStartPath:(GtkTreePath*)startPath endPath:(GtkTreePath*)endPath
{
	gtk_tree_selection_select_range([self TREESELECTION], startPath, endPath);
}

- (void)selectedForeachWithFunc:(GtkTreeSelectionForeachFunc)func data:(gpointer)data
{
	gtk_tree_selection_selected_foreach([self TREESELECTION], func, data);
}

- (void)setMode:(GtkSelectionMode)type
{
	gtk_tree_selection_set_mode([self TREESELECTION], type);
}

- (void)setSelectFunctionWithFunc:(GtkTreeSelectionFunc)func data:(gpointer)data destroy:(GDestroyNotify)destroy
{
	gtk_tree_selection_set_select_function([self TREESELECTION], func, data, destroy);
}

- (void)unselectAll
{
	gtk_tree_selection_unselect_all([self TREESELECTION]);
}

- (void)unselectIter:(GtkTreeIter*)iter
{
	gtk_tree_selection_unselect_iter([self TREESELECTION], iter);
}

- (void)unselectPath:(GtkTreePath*)path
{
	gtk_tree_selection_unselect_path([self TREESELECTION], path);
}

- (void)unselectRangeWithStartPath:(GtkTreePath*)startPath endPath:(GtkTreePath*)endPath
{
	gtk_tree_selection_unselect_range([self TREESELECTION], startPath, endPath);
}


@end