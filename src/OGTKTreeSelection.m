/*
 * OGTKTreeSelection.m
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
#import "OGTKTreeSelection.h"

@implementation OGTKTreeSelection

- (GtkTreeSelection*)TREESELECTION
{
	return GTK_TREE_SELECTION([self GOBJECT]);
}

- (gint)countSelectedRows
{
	return gtk_tree_selection_count_selected_rows(GTK_TREE_SELECTION([self GOBJECT]));
}

- (GtkSelectionMode)getMode
{
	return gtk_tree_selection_get_mode(GTK_TREE_SELECTION([self GOBJECT]));
}

- (GtkTreeSelectionFunc)getSelectFunction
{
	return gtk_tree_selection_get_select_function(GTK_TREE_SELECTION([self GOBJECT]));
}

- (bool)getSelectedWithModel:(GtkTreeModel**)model andIter:(GtkTreeIter*)iter
{
	return gtk_tree_selection_get_selected(GTK_TREE_SELECTION([self GOBJECT]), model, iter);
}

- (GList*)getSelectedRows:(GtkTreeModel**)model
{
	return gtk_tree_selection_get_selected_rows(GTK_TREE_SELECTION([self GOBJECT]), model);
}

- (GtkTreeView*)getTreeView
{
	return gtk_tree_selection_get_tree_view(GTK_TREE_SELECTION([self GOBJECT]));
}

- (gpointer)getUserData
{
	return gtk_tree_selection_get_user_data(GTK_TREE_SELECTION([self GOBJECT]));
}

- (bool)iterIsSelected:(GtkTreeIter*)iter
{
	return gtk_tree_selection_iter_is_selected(GTK_TREE_SELECTION([self GOBJECT]), iter);
}

- (bool)pathIsSelected:(GtkTreePath*)path
{
	return gtk_tree_selection_path_is_selected(GTK_TREE_SELECTION([self GOBJECT]), path);
}

- (void)selectAll
{
	gtk_tree_selection_select_all(GTK_TREE_SELECTION([self GOBJECT]));
}

- (void)selectIter:(GtkTreeIter*)iter
{
	gtk_tree_selection_select_iter(GTK_TREE_SELECTION([self GOBJECT]), iter);
}

- (void)selectPath:(GtkTreePath*)path
{
	gtk_tree_selection_select_path(GTK_TREE_SELECTION([self GOBJECT]), path);
}

- (void)selectRangeWithStartPath:(GtkTreePath*)startPath andEndPath:(GtkTreePath*)endPath
{
	gtk_tree_selection_select_range(GTK_TREE_SELECTION([self GOBJECT]), startPath, endPath);
}

- (void)selectedForeachWithFunc:(GtkTreeSelectionForeachFunc)func andData:(gpointer)data
{
	gtk_tree_selection_selected_foreach(GTK_TREE_SELECTION([self GOBJECT]), func, data);
}

- (void)setMode:(GtkSelectionMode)type
{
	gtk_tree_selection_set_mode(GTK_TREE_SELECTION([self GOBJECT]), type);
}

- (void)setSelectFunctionWithFunc:(GtkTreeSelectionFunc)func andData:(gpointer)data andDestroy:(GDestroyNotify)destroy
{
	gtk_tree_selection_set_select_function(GTK_TREE_SELECTION([self GOBJECT]), func, data, destroy);
}

- (void)unselectAll
{
	gtk_tree_selection_unselect_all(GTK_TREE_SELECTION([self GOBJECT]));
}

- (void)unselectIter:(GtkTreeIter*)iter
{
	gtk_tree_selection_unselect_iter(GTK_TREE_SELECTION([self GOBJECT]), iter);
}

- (void)unselectPath:(GtkTreePath*)path
{
	gtk_tree_selection_unselect_path(GTK_TREE_SELECTION([self GOBJECT]), path);
}

- (void)unselectRangeWithStartPath:(GtkTreePath*)startPath andEndPath:(GtkTreePath*)endPath
{
	gtk_tree_selection_unselect_range(GTK_TREE_SELECTION([self GOBJECT]), startPath, endPath);
}


@end