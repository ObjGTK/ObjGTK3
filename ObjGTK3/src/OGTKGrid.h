/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKWidget;

/**
 * GtkGrid is a container which arranges its child widgets in
 * rows and columns, with arbitrary positions and horizontal/vertical spans.
 * 
 * Children are added using gtk_grid_attach(). They can span multiple
 * rows or columns. It is also possible to add a child next to an
 * existing child, using gtk_grid_attach_next_to(). The behaviour of
 * GtkGrid when several children occupy the same grid cell is undefined.
 * 
 * GtkGrid can be used like a #GtkBox by just using gtk_container_add(),
 * which will place children next to each other in the direction determined
 * by the #GtkOrientable:orientation property. However, if all you want is a
 * single row or column, then #GtkBox is the preferred widget.
 * 
 * # CSS nodes
 * 
 * GtkGrid uses a single CSS node with name grid.
 *
 */
@interface OGTKGrid : OGTKContainer
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkGrid*)GRID;

/**
 * Adds a widget to the grid.
 * 
 * The position of @child is determined by @left and @top. The
 * number of “cells” that @child will occupy is determined by
 * @width and @height.
 *
 * @param child the widget to add
 * @param left the column number to attach the left side of @child to
 * @param top the row number to attach the top side of @child to
 * @param width the number of columns that @child will span
 * @param height the number of rows that @child will span
 */
- (void)attachWithChild:(OGTKWidget*)child left:(gint)left top:(gint)top width:(gint)width height:(gint)height;

/**
 * Adds a widget to the grid.
 * 
 * The widget is placed next to @sibling, on the side determined by
 * @side. When @sibling is %NULL, the widget is placed in row (for
 * left or right placement) or column 0 (for top or bottom placement),
 * at the end indicated by @side.
 * 
 * Attaching widgets labeled [1], [2], [3] with @sibling == %NULL and
 * @side == %GTK_POS_LEFT yields a layout of [3][2][1].
 *
 * @param child the widget to add
 * @param sibling the child of @grid that @child will be placed
 *     next to, or %NULL to place @child at the beginning or end
 * @param side the side of @sibling that @child is positioned next to
 * @param width the number of columns that @child will span
 * @param height the number of rows that @child will span
 */
- (void)attachNextToWithChild:(OGTKWidget*)child sibling:(OGTKWidget*)sibling side:(GtkPositionType)side width:(gint)width height:(gint)height;

/**
 * Returns which row defines the global baseline of @grid.
 *
 * @return the row index defining the global baseline
 */
- (gint)baselineRow;

/**
 * Gets the child of @grid whose area covers the grid
 * cell whose upper left corner is at @left, @top.
 *
 * @param left the left edge of the cell
 * @param top the top edge of the cell
 * @return the child at the given position, or %NULL
 */
- (OGTKWidget*)childAtWithLeft:(gint)left top:(gint)top;

/**
 * Returns whether all columns of @grid have the same width.
 *
 * @return whether all columns of @grid have the same width.
 */
- (bool)columnHomogeneous;

/**
 * Returns the amount of space between the columns of @grid.
 *
 * @return the column spacing of @grid
 */
- (guint)columnSpacing;

/**
 * Returns the baseline position of @row as set
 * by gtk_grid_set_row_baseline_position() or the default value
 * %GTK_BASELINE_POSITION_CENTER.
 *
 * @param row a row index
 * @return the baseline position of @row
 */
- (GtkBaselinePosition)rowBaselinePosition:(gint)row;

/**
 * Returns whether all rows of @grid have the same height.
 *
 * @return whether all rows of @grid have the same height.
 */
- (bool)rowHomogeneous;

/**
 * Returns the amount of space between the rows of @grid.
 *
 * @return the row spacing of @grid
 */
- (guint)rowSpacing;

/**
 * Inserts a column at the specified position.
 * 
 * Children which are attached at or to the right of this position
 * are moved one column to the right. Children which span across this
 * position are grown to span the new column.
 *
 * @param position the position to insert the column at
 */
- (void)insertColumn:(gint)position;

/**
 * Inserts a row or column at the specified position.
 * 
 * The new row or column is placed next to @sibling, on the side
 * determined by @side. If @side is %GTK_POS_TOP or %GTK_POS_BOTTOM,
 * a row is inserted. If @side is %GTK_POS_LEFT of %GTK_POS_RIGHT,
 * a column is inserted.
 *
 * @param sibling the child of @grid that the new row or column will be
 *     placed next to
 * @param side the side of @sibling that @child is positioned next to
 */
- (void)insertNextToWithSibling:(OGTKWidget*)sibling side:(GtkPositionType)side;

/**
 * Inserts a row at the specified position.
 * 
 * Children which are attached at or below this position
 * are moved one row down. Children which span across this
 * position are grown to span the new row.
 *
 * @param position the position to insert the row at
 */
- (void)insertRow:(gint)position;

/**
 * Removes a column from the grid.
 * 
 * Children that are placed in this column are removed,
 * spanning children that overlap this column have their
 * width reduced by one, and children after the column
 * are moved to the left.
 *
 * @param position the position of the column to remove
 */
- (void)removeColumn:(gint)position;

/**
 * Removes a row from the grid.
 * 
 * Children that are placed in this row are removed,
 * spanning children that overlap this row have their
 * height reduced by one, and children below the row
 * are moved up.
 *
 * @param position the position of the row to remove
 */
- (void)removeRow:(gint)position;

/**
 * Sets which row defines the global baseline for the entire grid.
 * Each row in the grid can have its own local baseline, but only
 * one of those is global, meaning it will be the baseline in the
 * parent of the @grid.
 *
 * @param row the row index
 */
- (void)setBaselineRow:(gint)row;

/**
 * Sets whether all columns of @grid will have the same width.
 *
 * @param homogeneous %TRUE to make columns homogeneous
 */
- (void)setColumnHomogeneous:(bool)homogeneous;

/**
 * Sets the amount of space between columns of @grid.
 *
 * @param spacing the amount of space to insert between columns
 */
- (void)setColumnSpacing:(guint)spacing;

/**
 * Sets how the baseline should be positioned on @row of the
 * grid, in case that row is assigned more space than is requested.
 *
 * @param row a row index
 * @param pos a #GtkBaselinePosition
 */
- (void)setRowBaselinePositionWithRow:(gint)row pos:(GtkBaselinePosition)pos;

/**
 * Sets whether all rows of @grid will have the same height.
 *
 * @param homogeneous %TRUE to make rows homogeneous
 */
- (void)setRowHomogeneous:(bool)homogeneous;

/**
 * Sets the amount of space between rows of @grid.
 *
 * @param spacing the amount of space to insert between rows
 */
- (void)setRowSpacing:(guint)spacing;

@end