/*
 * OGTKTreeModelFilter.m
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
#import "OGTKTreeModelFilter.h"

@implementation OGTKTreeModelFilter

- (GtkTreeModelFilter*)TREEMODELFILTER
{
	return GTK_TREE_MODEL_FILTER([self GOBJECT]);
}

- (void)clearCache
{
	gtk_tree_model_filter_clear_cache(GTK_TREE_MODEL_FILTER([self GOBJECT]));
}

- (bool)convertChildIterToIterWithFilterIter:(GtkTreeIter*)filterIter andChildIter:(GtkTreeIter*)childIter
{
	return gtk_tree_model_filter_convert_child_iter_to_iter(GTK_TREE_MODEL_FILTER([self GOBJECT]), filterIter, childIter);
}

- (GtkTreePath*)convertChildPathToPath:(GtkTreePath*)childPath
{
	return gtk_tree_model_filter_convert_child_path_to_path(GTK_TREE_MODEL_FILTER([self GOBJECT]), childPath);
}

- (void)convertIterToChildIterWithChildIter:(GtkTreeIter*)childIter andFilterIter:(GtkTreeIter*)filterIter
{
	gtk_tree_model_filter_convert_iter_to_child_iter(GTK_TREE_MODEL_FILTER([self GOBJECT]), childIter, filterIter);
}

- (GtkTreePath*)convertPathToChildPath:(GtkTreePath*)filterPath
{
	return gtk_tree_model_filter_convert_path_to_child_path(GTK_TREE_MODEL_FILTER([self GOBJECT]), filterPath);
}

- (GtkTreeModel*)getModel
{
	return gtk_tree_model_filter_get_model(GTK_TREE_MODEL_FILTER([self GOBJECT]));
}

- (void)refilter
{
	gtk_tree_model_filter_refilter(GTK_TREE_MODEL_FILTER([self GOBJECT]));
}

- (void)setModifyFuncWithNcolumns:(gint)ncolumns andTypes:(GType*)types andFunc:(GtkTreeModelFilterModifyFunc)func andData:(gpointer)data andDestroy:(GDestroyNotify)destroy
{
	gtk_tree_model_filter_set_modify_func(GTK_TREE_MODEL_FILTER([self GOBJECT]), ncolumns, types, func, data, destroy);
}

- (void)setVisibleColumn:(gint)column
{
	gtk_tree_model_filter_set_visible_column(GTK_TREE_MODEL_FILTER([self GOBJECT]), column);
}

- (void)setVisibleFuncWithFunc:(GtkTreeModelFilterVisibleFunc)func andData:(gpointer)data andDestroy:(GDestroyNotify)destroy
{
	gtk_tree_model_filter_set_visible_func(GTK_TREE_MODEL_FILTER([self GOBJECT]), func, data, destroy);
}


@end