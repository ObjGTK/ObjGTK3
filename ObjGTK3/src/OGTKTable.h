/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKWidget;

/**
 * The #GtkTable functions allow the programmer to arrange widgets in rows and
 * columns, making it easy to align many widgets next to each other,
 * horizontally and vertically.
 * 
 * Tables are created with a call to gtk_table_new(), the size of which can
 * later be changed with gtk_table_resize().
 * 
 * Widgets can be added to a table using gtk_table_attach() or the more
 * convenient (but slightly less flexible) gtk_table_attach_defaults().
 * 
 * To alter the space next to a specific row, use gtk_table_set_row_spacing(),
 * and for a column, gtk_table_set_col_spacing().
 * The gaps between all rows or columns can be changed by
 * calling gtk_table_set_row_spacings() or gtk_table_set_col_spacings()
 * respectively. Note that spacing is added between the
 * children, while padding added by gtk_table_attach() is added on
 * either side of the widget it belongs to.
 * 
 * gtk_table_set_homogeneous(), can be used to set whether all cells in the
 * table will resize themselves to the size of the largest widget in the table.
 * 
 * > #GtkTable has been deprecated. Use #GtkGrid instead. It provides the same
 * > capabilities as GtkTable for arranging widgets in a rectangular grid, but
 * > does support height-for-width geometry management.
 *
 */
@interface OGTKTable : OGTKContainer
{

}


/**
 * Constructors
 */
- (instancetype)initWithRows:(guint)rows columns:(guint)columns homogeneous:(bool)homogeneous;

/**
 * Methods
 */

- (GtkTable*)TABLE;

/**
 * Adds a widget to a table. The number of “cells” that a widget will occupy is
 * specified by @left_attach, @right_attach, @top_attach and @bottom_attach.
 * These each represent the leftmost, rightmost, uppermost and lowest column
 * and row numbers of the table. (Columns and rows are indexed from zero).
 * 
 * To make a button occupy the lower right cell of a 2x2 table, use
 * |[
 * gtk_table_attach (table, button,
 *                   1, 2, // left, right attach
 *                   1, 2, // top, bottom attach
 *                   xoptions, yoptions,
 *                   xpadding, ypadding);
 * ]|
 * If you want to make the button span the entire bottom row, use @left_attach == 0 and @right_attach = 2 instead.
 *
 * @param child The widget to add.
 * @param leftAttach the column number to attach the left side of a child widget to.
 * @param rightAttach the column number to attach the right side of a child widget to.
 * @param topAttach the row number to attach the top of a child widget to.
 * @param bottomAttach the row number to attach the bottom of a child widget to.
 * @param xoptions Used to specify the properties of the child widget when the table is resized.
 * @param yoptions The same as xoptions, except this field determines behaviour of vertical resizing.
 * @param xpadding An integer value specifying the padding on the left and right of the widget being added to the table.
 * @param ypadding The amount of padding above and below the child widget.
 */
- (void)attachWithChild:(OGTKWidget*)child leftAttach:(guint)leftAttach rightAttach:(guint)rightAttach topAttach:(guint)topAttach bottomAttach:(guint)bottomAttach xoptions:(GtkAttachOptions)xoptions yoptions:(GtkAttachOptions)yoptions xpadding:(guint)xpadding ypadding:(guint)ypadding;

/**
 * As there are many options associated with gtk_table_attach(), this convenience
 * function provides the programmer with a means to add children to a table with
 * identical padding and expansion options. The values used for the #GtkAttachOptions
 * are `GTK_EXPAND | GTK_FILL`, and the padding is set to 0.
 *
 * @param widget The child widget to add.
 * @param leftAttach The column number to attach the left side of the child widget to.
 * @param rightAttach The column number to attach the right side of the child widget to.
 * @param topAttach The row number to attach the top of the child widget to.
 * @param bottomAttach The row number to attach the bottom of the child widget to.
 */
- (void)attachDefaultsWithWidget:(OGTKWidget*)widget leftAttach:(guint)leftAttach rightAttach:(guint)rightAttach topAttach:(guint)topAttach bottomAttach:(guint)bottomAttach;

/**
 * Gets the amount of space between column @col, and
 * column @col + 1. See gtk_table_set_col_spacing().
 *
 * @param column a column in the table, 0 indicates the first column
 * @return the column spacing
 */
- (guint)colSpacing:(guint)column;

/**
 * Gets the default column spacing for the table. This is
 * the spacing that will be used for newly added columns.
 * (See gtk_table_set_col_spacings())
 *
 * @return the default column spacing
 */
- (guint)defaultColSpacing;

/**
 * Gets the default row spacing for the table. This is
 * the spacing that will be used for newly added rows.
 * (See gtk_table_set_row_spacings())
 *
 * @return the default row spacing
 */
- (guint)defaultRowSpacing;

/**
 * Returns whether the table cells are all constrained to the same
 * width and height. (See gtk_table_set_homogeneous ())
 *
 * @return %TRUE if the cells are all constrained to the same size
 */
- (bool)homogeneous;

/**
 * Gets the amount of space between row @row, and
 * row @row + 1. See gtk_table_set_row_spacing().
 *
 * @param row a row in the table, 0 indicates the first row
 * @return the row spacing
 */
- (guint)rowSpacing:(guint)row;

/**
 * Gets the number of rows and columns in the table.
 *
 * @param rows return location for the number of
 *   rows, or %NULL
 * @param columns return location for the number
 *   of columns, or %NULL
 */
- (void)sizeWithRows:(guint*)rows columns:(guint*)columns;

/**
 * If you need to change a table’s size after
 * it has been created, this function allows you to do so.
 *
 * @param rows The new number of rows.
 * @param columns The new number of columns.
 */
- (void)resizeWithRows:(guint)rows columns:(guint)columns;

/**
 * Alters the amount of space between a given table column and the following
 * column.
 *
 * @param column the column whose spacing should be changed.
 * @param spacing number of pixels that the spacing should take up.
 */
- (void)setColSpacingWithColumn:(guint)column spacing:(guint)spacing;

/**
 * Sets the space between every column in @table equal to @spacing.
 *
 * @param spacing the number of pixels of space to place between every column
 *   in the table.
 */
- (void)setColSpacings:(guint)spacing;

/**
 * Changes the homogenous property of table cells, ie. whether all cells are
 * an equal size or not.
 *
 * @param homogeneous Set to %TRUE to ensure all table cells are the same size. Set
 *   to %FALSE if this is not your desired behaviour.
 */
- (void)setHomogeneous:(bool)homogeneous;

/**
 * Changes the space between a given table row and the subsequent row.
 *
 * @param row row number whose spacing will be changed.
 * @param spacing number of pixels that the spacing should take up.
 */
- (void)setRowSpacingWithRow:(guint)row spacing:(guint)spacing;

/**
 * Sets the space between every row in @table equal to @spacing.
 *
 * @param spacing the number of pixels of space to place between every row in the table.
 */
- (void)setRowSpacings:(guint)spacing;

@end