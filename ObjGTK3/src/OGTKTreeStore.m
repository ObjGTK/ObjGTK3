/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTreeStore.h"

@implementation OGTKTreeStore

- (instancetype)initvWithNcolumns:(gint)ncolumns types:(GType*)types
{
	self = [super initWithGObject:(GObject*)gtk_tree_store_newv(ncolumns, types)];

	return self;
}

- (GtkTreeStore*)TREESTORE
{
	return GTK_TREE_STORE([self GOBJECT]);
}

- (void)appendWithIter:(GtkTreeIter*)iter parent:(GtkTreeIter*)parent
{
	gtk_tree_store_append([self TREESTORE], iter, parent);
}

- (void)clear
{
	gtk_tree_store_clear([self TREESTORE]);
}

- (void)insertWithIter:(GtkTreeIter*)iter parent:(GtkTreeIter*)parent position:(gint)position
{
	gtk_tree_store_insert([self TREESTORE], iter, parent, position);
}

- (void)insertAfterWithIter:(GtkTreeIter*)iter parent:(GtkTreeIter*)parent sibling:(GtkTreeIter*)sibling
{
	gtk_tree_store_insert_after([self TREESTORE], iter, parent, sibling);
}

- (void)insertBeforeWithIter:(GtkTreeIter*)iter parent:(GtkTreeIter*)parent sibling:(GtkTreeIter*)sibling
{
	gtk_tree_store_insert_before([self TREESTORE], iter, parent, sibling);
}

- (void)insertWithValuesvWithIter:(GtkTreeIter*)iter parent:(GtkTreeIter*)parent position:(gint)position columns:(gint*)columns values:(GValue*)values nvalues:(gint)nvalues
{
	gtk_tree_store_insert_with_valuesv([self TREESTORE], iter, parent, position, columns, values, nvalues);
}

- (bool)isAncestorWithIter:(GtkTreeIter*)iter descendant:(GtkTreeIter*)descendant
{
	return gtk_tree_store_is_ancestor([self TREESTORE], iter, descendant);
}

- (gint)iterDepth:(GtkTreeIter*)iter
{
	return gtk_tree_store_iter_depth([self TREESTORE], iter);
}

- (bool)iterIsValid:(GtkTreeIter*)iter
{
	return gtk_tree_store_iter_is_valid([self TREESTORE], iter);
}

- (void)moveAfterWithIter:(GtkTreeIter*)iter position:(GtkTreeIter*)position
{
	gtk_tree_store_move_after([self TREESTORE], iter, position);
}

- (void)moveBeforeWithIter:(GtkTreeIter*)iter position:(GtkTreeIter*)position
{
	gtk_tree_store_move_before([self TREESTORE], iter, position);
}

- (void)prependWithIter:(GtkTreeIter*)iter parent:(GtkTreeIter*)parent
{
	gtk_tree_store_prepend([self TREESTORE], iter, parent);
}

- (bool)remove:(GtkTreeIter*)iter
{
	return gtk_tree_store_remove([self TREESTORE], iter);
}

- (void)reorderWithParent:(GtkTreeIter*)parent newOrder:(gint*)newOrder
{
	gtk_tree_store_reorder([self TREESTORE], parent, newOrder);
}

- (void)setColumnTypesWithNcolumns:(gint)ncolumns types:(GType*)types
{
	gtk_tree_store_set_column_types([self TREESTORE], ncolumns, types);
}

- (void)setValistWithIter:(GtkTreeIter*)iter varArgs:(va_list)varArgs
{
	gtk_tree_store_set_valist([self TREESTORE], iter, varArgs);
}

- (void)setValueWithIter:(GtkTreeIter*)iter column:(gint)column value:(GValue*)value
{
	gtk_tree_store_set_value([self TREESTORE], iter, column, value);
}

- (void)setValuesvWithIter:(GtkTreeIter*)iter columns:(gint*)columns values:(GValue*)values nvalues:(gint)nvalues
{
	gtk_tree_store_set_valuesv([self TREESTORE], iter, columns, values, nvalues);
}

- (void)swapWithA:(GtkTreeIter*)a b:(GtkTreeIter*)b
{
	gtk_tree_store_swap([self TREESTORE], a, b);
}


@end