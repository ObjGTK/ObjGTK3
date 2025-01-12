/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtkx.h>
#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>

#import <OGObject/OGObject.h>

/**
 * The #GtkTreeStore object is a list model for use with a #GtkTreeView
 * widget.  It implements the #GtkTreeModel interface, and consequentially,
 * can use all of the methods available there.  It also implements the
 * #GtkTreeSortable interface so it can be sorted by the view.  Finally,
 * it also implements the tree
 * [drag and drop][gtk3-GtkTreeView-drag-and-drop]
 * interfaces.
 * 
 * # GtkTreeStore as GtkBuildable
 * 
 * The GtkTreeStore implementation of the #GtkBuildable interface allows
 * to specify the model columns with a <columns> element that may contain
 * multiple <column> elements, each specifying one model column. The “type”
 * attribute specifies the data type for the column.
 * 
 * An example of a UI Definition fragment for a tree store:
 * |[
 * <object class="GtkTreeStore">
 *   <columns>
 *     <column type="gchararray"/>
 *     <column type="gchararray"/>
 *     <column type="gint"/>
 *   </columns>
 * </object>
 * ]|
 *
 */
@interface OGTKTreeStore : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)initvWithNcolumns:(gint)ncolumns types:(GType*)types;

/**
 * Methods
 */

- (GtkTreeStore*)TREESTORE;

/**
 * Appends a new row to @tree_store.  If @parent is non-%NULL, then it will append the
 * new row after the last child of @parent, otherwise it will append a row to
 * the top level.  @iter will be changed to point to this new row.  The row will
 * be empty after this function is called.  To fill in values, you need to call
 * gtk_tree_store_set() or gtk_tree_store_set_value().
 *
 * @param iter An unset #GtkTreeIter to set to the appended row
 * @param parent A valid #GtkTreeIter, or %NULL
 */
- (void)appendWithIter:(GtkTreeIter*)iter parent:(GtkTreeIter*)parent;

/**
 * Removes all rows from @tree_store
 *
 */
- (void)clear;

/**
 * Creates a new row at @position.  If parent is non-%NULL, then the row will be
 * made a child of @parent.  Otherwise, the row will be created at the toplevel.
 * If @position is -1 or is larger than the number of rows at that level, then
 * the new row will be inserted to the end of the list.  @iter will be changed
 * to point to this new row.  The row will be empty after this function is
 * called.  To fill in values, you need to call gtk_tree_store_set() or
 * gtk_tree_store_set_value().
 *
 * @param iter An unset #GtkTreeIter to set to the new row
 * @param parent A valid #GtkTreeIter, or %NULL
 * @param position position to insert the new row, or -1 for last
 */
- (void)insertWithIter:(GtkTreeIter*)iter parent:(GtkTreeIter*)parent position:(gint)position;

/**
 * Inserts a new row after @sibling.  If @sibling is %NULL, then the row will be
 * prepended to @parent ’s children.  If @parent and @sibling are %NULL, then
 * the row will be prepended to the toplevel.  If both @sibling and @parent are
 * set, then @parent must be the parent of @sibling.  When @sibling is set,
 * @parent is optional.
 * 
 * @iter will be changed to point to this new row.  The row will be empty after
 * this function is called.  To fill in values, you need to call
 * gtk_tree_store_set() or gtk_tree_store_set_value().
 *
 * @param iter An unset #GtkTreeIter to set to the new row
 * @param parent A valid #GtkTreeIter, or %NULL
 * @param sibling A valid #GtkTreeIter, or %NULL
 */
- (void)insertAfterWithIter:(GtkTreeIter*)iter parent:(GtkTreeIter*)parent sibling:(GtkTreeIter*)sibling;

/**
 * Inserts a new row before @sibling.  If @sibling is %NULL, then the row will
 * be appended to @parent ’s children.  If @parent and @sibling are %NULL, then
 * the row will be appended to the toplevel.  If both @sibling and @parent are
 * set, then @parent must be the parent of @sibling.  When @sibling is set,
 * @parent is optional.
 * 
 * @iter will be changed to point to this new row.  The row will be empty after
 * this function is called.  To fill in values, you need to call
 * gtk_tree_store_set() or gtk_tree_store_set_value().
 *
 * @param iter An unset #GtkTreeIter to set to the new row
 * @param parent A valid #GtkTreeIter, or %NULL
 * @param sibling A valid #GtkTreeIter, or %NULL
 */
- (void)insertBeforeWithIter:(GtkTreeIter*)iter parent:(GtkTreeIter*)parent sibling:(GtkTreeIter*)sibling;

/**
 * A variant of gtk_tree_store_insert_with_values() which takes
 * the columns and values as two arrays, instead of varargs.  This
 * function is mainly intended for language bindings.
 *
 * @param iter An unset #GtkTreeIter to set the new row, or %NULL.
 * @param parent A valid #GtkTreeIter, or %NULL
 * @param position position to insert the new row, or -1 for last
 * @param columns an array of column numbers
 * @param values an array of GValues
 * @param nvalues the length of the @columns and @values arrays
 */
- (void)insertWithValuesvWithIter:(GtkTreeIter*)iter parent:(GtkTreeIter*)parent position:(gint)position columns:(gint*)columns values:(GValue*)values nvalues:(gint)nvalues;

/**
 * Returns %TRUE if @iter is an ancestor of @descendant.  That is, @iter is the
 * parent (or grandparent or great-grandparent) of @descendant.
 *
 * @param iter A valid #GtkTreeIter
 * @param descendant A valid #GtkTreeIter
 * @return %TRUE, if @iter is an ancestor of @descendant
 */
- (bool)isAncestorWithIter:(GtkTreeIter*)iter descendant:(GtkTreeIter*)descendant;

/**
 * Returns the depth of @iter.  This will be 0 for anything on the root level, 1
 * for anything down a level, etc.
 *
 * @param iter A valid #GtkTreeIter
 * @return The depth of @iter
 */
- (gint)iterDepth:(GtkTreeIter*)iter;

/**
 * WARNING: This function is slow. Only use it for debugging and/or testing
 * purposes.
 * 
 * Checks if the given iter is a valid iter for this #GtkTreeStore.
 *
 * @param iter A #GtkTreeIter.
 * @return %TRUE if the iter is valid, %FALSE if the iter is invalid.
 */
- (bool)iterIsValid:(GtkTreeIter*)iter;

/**
 * Moves @iter in @tree_store to the position after @position. @iter and
 * @position should be in the same level. Note that this function only
 * works with unsorted stores. If @position is %NULL, @iter will be moved
 * to the start of the level.
 *
 * @param iter A #GtkTreeIter.
 * @param position A #GtkTreeIter.
 */
- (void)moveAfterWithIter:(GtkTreeIter*)iter position:(GtkTreeIter*)position;

/**
 * Moves @iter in @tree_store to the position before @position. @iter and
 * @position should be in the same level. Note that this function only
 * works with unsorted stores. If @position is %NULL, @iter will be
 * moved to the end of the level.
 *
 * @param iter A #GtkTreeIter.
 * @param position A #GtkTreeIter or %NULL.
 */
- (void)moveBeforeWithIter:(GtkTreeIter*)iter position:(GtkTreeIter*)position;

/**
 * Prepends a new row to @tree_store.  If @parent is non-%NULL, then it will prepend
 * the new row before the first child of @parent, otherwise it will prepend a row
 * to the top level.  @iter will be changed to point to this new row.  The row
 * will be empty after this function is called.  To fill in values, you need to
 * call gtk_tree_store_set() or gtk_tree_store_set_value().
 *
 * @param iter An unset #GtkTreeIter to set to the prepended row
 * @param parent A valid #GtkTreeIter, or %NULL
 */
- (void)prependWithIter:(GtkTreeIter*)iter parent:(GtkTreeIter*)parent;

/**
 * Removes @iter from @tree_store.  After being removed, @iter is set to the
 * next valid row at that level, or invalidated if it previously pointed to the
 * last one.
 *
 * @param iter A valid #GtkTreeIter
 * @return %TRUE if @iter is still valid, %FALSE if not.
 */
- (bool)remove:(GtkTreeIter*)iter;

/**
 * Reorders the children of @parent in @tree_store to follow the order
 * indicated by @new_order. Note that this function only works with
 * unsorted stores.
 *
 * @param parent A #GtkTreeIter, or %NULL
 * @param newOrder an array of integers mapping the new position of each child
 *      to its old position before the re-ordering,
 *      i.e. @new_order`[newpos] = oldpos`.
 */
- (void)reorderWithParent:(GtkTreeIter*)parent newOrder:(gint*)newOrder;

/**
 * This function is meant primarily for #GObjects that inherit from
 * #GtkTreeStore, and should only be used when constructing a new
 * #GtkTreeStore.  It will not function after a row has been added,
 * or a method on the #GtkTreeModel interface is called.
 *
 * @param ncolumns Number of columns for the tree store
 * @param types An array of #GType types, one for each column
 */
- (void)setColumnTypesWithNcolumns:(gint)ncolumns types:(GType*)types;

/**
 * See gtk_tree_store_set(); this version takes a va_list for
 * use by language bindings.
 *
 * @param iter A valid #GtkTreeIter for the row being modified
 * @param varArgs va_list of column/value pairs
 */
- (void)setValistWithIter:(GtkTreeIter*)iter varArgs:(va_list)varArgs;

/**
 * Sets the data in the cell specified by @iter and @column.
 * The type of @value must be convertible to the type of the
 * column.
 *
 * @param iter A valid #GtkTreeIter for the row being modified
 * @param column column number to modify
 * @param value new value for the cell
 */
- (void)setValueWithIter:(GtkTreeIter*)iter column:(gint)column value:(GValue*)value;

/**
 * A variant of gtk_tree_store_set_valist() which takes
 * the columns and values as two arrays, instead of varargs.  This
 * function is mainly intended for language bindings or in case
 * the number of columns to change is not known until run-time.
 *
 * @param iter A valid #GtkTreeIter for the row being modified
 * @param columns an array of column numbers
 * @param values an array of GValues
 * @param nvalues the length of the @columns and @values arrays
 */
- (void)setValuesvWithIter:(GtkTreeIter*)iter columns:(gint*)columns values:(GValue*)values nvalues:(gint)nvalues;

/**
 * Swaps @a and @b in the same level of @tree_store. Note that this function
 * only works with unsorted stores.
 *
 * @param a A #GtkTreeIter.
 * @param b Another #GtkTreeIter.
 */
- (void)swapWithA:(GtkTreeIter*)a b:(GtkTreeIter*)b;

@end