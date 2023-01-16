/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKListStore.h"

@implementation OGTKListStore

- (instancetype)initvWithNcolumns:(gint)ncolumns types:(GType*)types
{
	self = [super initWithGObject:(GObject*)gtk_list_store_newv(ncolumns, types)];

	return self;
}

- (GtkListStore*)LISTSTORE
{
	return GTK_LIST_STORE([self GOBJECT]);
}

- (void)append:(GtkTreeIter*)iter
{
	gtk_list_store_append([self LISTSTORE], iter);
}

- (void)clear
{
	gtk_list_store_clear([self LISTSTORE]);
}

- (void)insertWithIter:(GtkTreeIter*)iter position:(gint)position
{
	gtk_list_store_insert([self LISTSTORE], iter, position);
}

- (void)insertAfterWithIter:(GtkTreeIter*)iter sibling:(GtkTreeIter*)sibling
{
	gtk_list_store_insert_after([self LISTSTORE], iter, sibling);
}

- (void)insertBeforeWithIter:(GtkTreeIter*)iter sibling:(GtkTreeIter*)sibling
{
	gtk_list_store_insert_before([self LISTSTORE], iter, sibling);
}

- (void)insertWithValuesvWithIter:(GtkTreeIter*)iter position:(gint)position columns:(gint*)columns values:(GValue*)values nvalues:(gint)nvalues
{
	gtk_list_store_insert_with_valuesv([self LISTSTORE], iter, position, columns, values, nvalues);
}

- (bool)iterIsValid:(GtkTreeIter*)iter
{
	return gtk_list_store_iter_is_valid([self LISTSTORE], iter);
}

- (void)moveAfterWithIter:(GtkTreeIter*)iter position:(GtkTreeIter*)position
{
	gtk_list_store_move_after([self LISTSTORE], iter, position);
}

- (void)moveBeforeWithIter:(GtkTreeIter*)iter position:(GtkTreeIter*)position
{
	gtk_list_store_move_before([self LISTSTORE], iter, position);
}

- (void)prepend:(GtkTreeIter*)iter
{
	gtk_list_store_prepend([self LISTSTORE], iter);
}

- (bool)remove:(GtkTreeIter*)iter
{
	return gtk_list_store_remove([self LISTSTORE], iter);
}

- (void)reorder:(gint*)newOrder
{
	gtk_list_store_reorder([self LISTSTORE], newOrder);
}

- (void)setColumnTypesWithNcolumns:(gint)ncolumns types:(GType*)types
{
	gtk_list_store_set_column_types([self LISTSTORE], ncolumns, types);
}

- (void)setValistWithIter:(GtkTreeIter*)iter varArgs:(va_list)varArgs
{
	gtk_list_store_set_valist([self LISTSTORE], iter, varArgs);
}

- (void)setValueWithIter:(GtkTreeIter*)iter column:(gint)column value:(GValue*)value
{
	gtk_list_store_set_value([self LISTSTORE], iter, column, value);
}

- (void)setValuesvWithIter:(GtkTreeIter*)iter columns:(gint*)columns values:(GValue*)values nvalues:(gint)nvalues
{
	gtk_list_store_set_valuesv([self LISTSTORE], iter, columns, values, nvalues);
}

- (void)swapWithA:(GtkTreeIter*)a b:(GtkTreeIter*)b
{
	gtk_list_store_swap([self LISTSTORE], a, b);
}


@end