/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWidget.h"

@class OGTKCellArea;
@class OGGdkPixbuf;
@class OGTKCellAreaContext;

/**
 * A #GtkCellView displays a single row of a #GtkTreeModel using a #GtkCellArea
 * and #GtkCellAreaContext. A #GtkCellAreaContext can be provided to the
 * #GtkCellView at construction time in order to keep the cellview in context
 * of a group of cell views, this ensures that the renderers displayed will
 * be properly aligned with eachother (like the aligned cells in the menus
 * of #GtkComboBox).
 * 
 * #GtkCellView is #GtkOrientable in order to decide in which orientation
 * the underlying #GtkCellAreaContext should be allocated. Taking the #GtkComboBox
 * menu as an example, cellviews should be oriented horizontally if the menus are
 * listed top-to-bottom and thus all share the same width but may have separate
 * individual heights (left-to-right menus should be allocated vertically since
 * they all share the same height but may have variable widths).
 * 
 * # CSS nodes
 * 
 * GtkCellView has a single CSS node with name cellview.
 *
 */
@interface OGTKCellView : OGTKWidget
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initWithContextWithArea:(OGTKCellArea*)area context:(OGTKCellAreaContext*)context;
- (instancetype)initWithMarkup:(OFString*)markup;
- (instancetype)initWithPixbuf:(OGGdkPixbuf*)pixbuf;
- (instancetype)initWithText:(OFString*)text;

/**
 * Methods
 */

- (GtkCellView*)CELLVIEW;

/**
 * Returns a #GtkTreePath referring to the currently
 * displayed row. If no row is currently displayed,
 * %NULL is returned.
 *
 * @return the currently displayed row or %NULL
 */
- (GtkTreePath*)displayedRow;

/**
 * Gets whether @cell_view is configured to draw all of its
 * cells in a sensitive state.
 *
 * @return whether @cell_view draws all of its
 * cells in a sensitive state
 */
- (bool)drawSensitive;

/**
 * Gets whether @cell_view is configured to request space
 * to fit the entire #GtkTreeModel.
 *
 * @return whether @cell_view requests space to fit
 * the entire #GtkTreeModel.
 */
- (bool)fitModel;

/**
 * Returns the model for @cell_view. If no model is used %NULL is
 * returned.
 *
 * @return a #GtkTreeModel used or %NULL
 */
- (GtkTreeModel*)model;

/**
 * Sets @requisition to the size needed by @cell_view to display
 * the model row pointed to by @path.
 *
 * @param path a #GtkTreePath
 * @param requisition return location for the size
 * @return %TRUE
 */
- (bool)sizeOfRowWithPath:(GtkTreePath*)path requisition:(GtkRequisition*)requisition;

/**
 * Sets the background color of @view.
 *
 * @param color the new background color
 */
- (void)setBackgroundColor:(const GdkColor*)color;

/**
 * Sets the background color of @cell_view.
 *
 * @param rgba the new background color
 */
- (void)setBackgroundRgba:(const GdkRGBA*)rgba;

/**
 * Sets the row of the model that is currently displayed
 * by the #GtkCellView. If the path is unset, then the
 * contents of the cellview “stick” at their last value;
 * this is not normally a desired result, but may be
 * a needed intermediate state if say, the model for
 * the #GtkCellView becomes temporarily empty.
 *
 * @param path a #GtkTreePath or %NULL to unset.
 */
- (void)setDisplayedRow:(GtkTreePath*)path;

/**
 * Sets whether @cell_view should draw all of its
 * cells in a sensitive state, this is used by #GtkComboBox menus
 * to ensure that rows with insensitive cells that contain
 * children appear sensitive in the parent menu item.
 *
 * @param drawSensitive whether to draw all cells in a sensitive state.
 */
- (void)setDrawSensitive:(bool)drawSensitive;

/**
 * Sets whether @cell_view should request space to fit the entire #GtkTreeModel.
 * 
 * This is used by #GtkComboBox to ensure that the cell view displayed on
 * the combo box’s button always gets enough space and does not resize
 * when selection changes.
 *
 * @param fitModel whether @cell_view should request space for the whole model.
 */
- (void)setFitModel:(bool)fitModel;

/**
 * Sets the model for @cell_view.  If @cell_view already has a model
 * set, it will remove it before setting the new model.  If @model is
 * %NULL, then it will unset the old model.
 *
 * @param model a #GtkTreeModel
 */
- (void)setModel:(GtkTreeModel*)model;

@end