/*
 * OGTKListStore.m
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
#import "OGTKListStore.h"

@implementation OGTKListStore

- (id)initvWithNcolumns:(gint)ncolumns andTypes:(GType*)types
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
	gtk_list_store_append(GTK_LIST_STORE([self GOBJECT]), iter);
}

- (void)clear
{
	gtk_list_store_clear(GTK_LIST_STORE([self GOBJECT]));
}

- (void)insertWithIter:(GtkTreeIter*)iter andPosition:(gint)position
{
	gtk_list_store_insert(GTK_LIST_STORE([self GOBJECT]), iter, position);
}

- (void)insertAfterWithIter:(GtkTreeIter*)iter andSibling:(GtkTreeIter*)sibling
{
	gtk_list_store_insert_after(GTK_LIST_STORE([self GOBJECT]), iter, sibling);
}

- (void)insertBeforeWithIter:(GtkTreeIter*)iter andSibling:(GtkTreeIter*)sibling
{
	gtk_list_store_insert_before(GTK_LIST_STORE([self GOBJECT]), iter, sibling);
}

- (void)insertWithValuesvWithIter:(GtkTreeIter*)iter andPosition:(gint)position andColumns:(gint*)columns andValues:(GValue*)values andNvalues:(gint)nvalues
{
	gtk_list_store_insert_with_valuesv(GTK_LIST_STORE([self GOBJECT]), iter, position, columns, values, nvalues);
}

- (bool)iterIsValid:(GtkTreeIter*)iter
{
	return gtk_list_store_iter_is_valid(GTK_LIST_STORE([self GOBJECT]), iter);
}

- (void)moveAfterWithIter:(GtkTreeIter*)iter andPosition:(GtkTreeIter*)position
{
	gtk_list_store_move_after(GTK_LIST_STORE([self GOBJECT]), iter, position);
}

- (void)moveBeforeWithIter:(GtkTreeIter*)iter andPosition:(GtkTreeIter*)position
{
	gtk_list_store_move_before(GTK_LIST_STORE([self GOBJECT]), iter, position);
}

- (void)prepend:(GtkTreeIter*)iter
{
	gtk_list_store_prepend(GTK_LIST_STORE([self GOBJECT]), iter);
}

- (bool)remove:(GtkTreeIter*)iter
{
	return gtk_list_store_remove(GTK_LIST_STORE([self GOBJECT]), iter);
}

- (void)reorder:(gint*)newOrder
{
	gtk_list_store_reorder(GTK_LIST_STORE([self GOBJECT]), newOrder);
}

- (void)setColumnTypesWithNcolumns:(gint)ncolumns andTypes:(GType*)types
{
	gtk_list_store_set_column_types(GTK_LIST_STORE([self GOBJECT]), ncolumns, types);
}

- (void)setValistWithIter:(GtkTreeIter*)iter andVarArgs:(va_list)varArgs
{
	gtk_list_store_set_valist(GTK_LIST_STORE([self GOBJECT]), iter, varArgs);
}

- (void)setValueWithIter:(GtkTreeIter*)iter andColumn:(gint)column andValue:(GValue*)value
{
	gtk_list_store_set_value(GTK_LIST_STORE([self GOBJECT]), iter, column, value);
}

- (void)setValuesvWithIter:(GtkTreeIter*)iter andColumns:(gint*)columns andValues:(GValue*)values andNvalues:(gint)nvalues
{
	gtk_list_store_set_valuesv(GTK_LIST_STORE([self GOBJECT]), iter, columns, values, nvalues);
}

- (void)swapWithA:(GtkTreeIter*)a andB:(GtkTreeIter*)b
{
	gtk_list_store_swap(GTK_LIST_STORE([self GOBJECT]), a, b);
}


@end