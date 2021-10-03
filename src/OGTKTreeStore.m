/*
 * OGTKTreeStore.m
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
#import "OGTKTreeStore.h"

@implementation OGTKTreeStore

- (id)initvWithNcolumns:(gint)ncolumns andTypes:(GType*)types
{
	self = [super initWithGObject:(GObject*)gtk_tree_store_newv(ncolumns, types)];

	return self;
}

- (GtkTreeStore*)TREESTORE
{
	return GTK_TREE_STORE([self GOBJECT]);
}

- (void)appendWithIter:(GtkTreeIter*)iter andParent:(GtkTreeIter*)parent
{
	gtk_tree_store_append(GTK_TREE_STORE([self GOBJECT]), iter, parent);
}

- (void)clear
{
	gtk_tree_store_clear(GTK_TREE_STORE([self GOBJECT]));
}

- (void)insertWithIter:(GtkTreeIter*)iter andParent:(GtkTreeIter*)parent andPosition:(gint)position
{
	gtk_tree_store_insert(GTK_TREE_STORE([self GOBJECT]), iter, parent, position);
}

- (void)insertAfterWithIter:(GtkTreeIter*)iter andParent:(GtkTreeIter*)parent andSibling:(GtkTreeIter*)sibling
{
	gtk_tree_store_insert_after(GTK_TREE_STORE([self GOBJECT]), iter, parent, sibling);
}

- (void)insertBeforeWithIter:(GtkTreeIter*)iter andParent:(GtkTreeIter*)parent andSibling:(GtkTreeIter*)sibling
{
	gtk_tree_store_insert_before(GTK_TREE_STORE([self GOBJECT]), iter, parent, sibling);
}

- (void)insertWithValuesvWithIter:(GtkTreeIter*)iter andParent:(GtkTreeIter*)parent andPosition:(gint)position andColumns:(gint*)columns andValues:(GValue*)values andNvalues:(gint)nvalues
{
	gtk_tree_store_insert_with_valuesv(GTK_TREE_STORE([self GOBJECT]), iter, parent, position, columns, values, nvalues);
}

- (bool)isAncestorWithIter:(GtkTreeIter*)iter andDescendant:(GtkTreeIter*)descendant
{
	return gtk_tree_store_is_ancestor(GTK_TREE_STORE([self GOBJECT]), iter, descendant);
}

- (gint)iterDepth:(GtkTreeIter*)iter
{
	return gtk_tree_store_iter_depth(GTK_TREE_STORE([self GOBJECT]), iter);
}

- (bool)iterIsValid:(GtkTreeIter*)iter
{
	return gtk_tree_store_iter_is_valid(GTK_TREE_STORE([self GOBJECT]), iter);
}

- (void)moveAfterWithIter:(GtkTreeIter*)iter andPosition:(GtkTreeIter*)position
{
	gtk_tree_store_move_after(GTK_TREE_STORE([self GOBJECT]), iter, position);
}

- (void)moveBeforeWithIter:(GtkTreeIter*)iter andPosition:(GtkTreeIter*)position
{
	gtk_tree_store_move_before(GTK_TREE_STORE([self GOBJECT]), iter, position);
}

- (void)prependWithIter:(GtkTreeIter*)iter andParent:(GtkTreeIter*)parent
{
	gtk_tree_store_prepend(GTK_TREE_STORE([self GOBJECT]), iter, parent);
}

- (bool)remove:(GtkTreeIter*)iter
{
	return gtk_tree_store_remove(GTK_TREE_STORE([self GOBJECT]), iter);
}

- (void)reorderWithParent:(GtkTreeIter*)parent andNewOrder:(gint*)newOrder
{
	gtk_tree_store_reorder(GTK_TREE_STORE([self GOBJECT]), parent, newOrder);
}

- (void)setColumnTypesWithNcolumns:(gint)ncolumns andTypes:(GType*)types
{
	gtk_tree_store_set_column_types(GTK_TREE_STORE([self GOBJECT]), ncolumns, types);
}

- (void)setValistWithIter:(GtkTreeIter*)iter andVarArgs:(va_list)varArgs
{
	gtk_tree_store_set_valist(GTK_TREE_STORE([self GOBJECT]), iter, varArgs);
}

- (void)setValueWithIter:(GtkTreeIter*)iter andColumn:(gint)column andValue:(GValue*)value
{
	gtk_tree_store_set_value(GTK_TREE_STORE([self GOBJECT]), iter, column, value);
}

- (void)setValuesvWithIter:(GtkTreeIter*)iter andColumns:(gint*)columns andValues:(GValue*)values andNvalues:(gint)nvalues
{
	gtk_tree_store_set_valuesv(GTK_TREE_STORE([self GOBJECT]), iter, columns, values, nvalues);
}

- (void)swapWithA:(GtkTreeIter*)a andB:(GtkTreeIter*)b
{
	gtk_tree_store_swap(GTK_TREE_STORE([self GOBJECT]), a, b);
}


@end