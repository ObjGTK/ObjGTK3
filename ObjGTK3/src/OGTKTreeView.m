/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTreeView.h"

#import "OGTKTreeViewColumn.h"
#import "OGTKCellRenderer.h"
#import "OGTKTreeSelection.h"
#import "OGTKEntry.h"
#import <OGdk3/OGGdkWindow.h>
#import "OGTKAdjustment.h"
#import "OGTKTooltip.h"
#import "OGTKWidget.h"

@implementation OGTKTreeView

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_tree_view_new()];

	return self;
}

- (instancetype)initWithModel:(GtkTreeModel*)model
{
	self = [super initWithGObject:(GObject*)gtk_tree_view_new_with_model(model)];

	return self;
}

- (GtkTreeView*)TREEVIEW
{
	return GTK_TREE_VIEW([self GOBJECT]);
}

- (gint)appendColumn:(OGTKTreeViewColumn*)column
{
	return gtk_tree_view_append_column([self TREEVIEW], [column TREEVIEWCOLUMN]);
}

- (void)collapseAll
{
	gtk_tree_view_collapse_all([self TREEVIEW]);
}

- (bool)collapseRow:(GtkTreePath*)path
{
	return gtk_tree_view_collapse_row([self TREEVIEW], path);
}

- (void)columnsAutosize
{
	gtk_tree_view_columns_autosize([self TREEVIEW]);
}

- (void)convertBinWindowToTreeCoordsWithBx:(gint)bx by:(gint)by tx:(gint*)tx ty:(gint*)ty
{
	gtk_tree_view_convert_bin_window_to_tree_coords([self TREEVIEW], bx, by, tx, ty);
}

- (void)convertBinWindowToWidgetCoordsWithBx:(gint)bx by:(gint)by wx:(gint*)wx wy:(gint*)wy
{
	gtk_tree_view_convert_bin_window_to_widget_coords([self TREEVIEW], bx, by, wx, wy);
}

- (void)convertTreeToBinWindowCoordsWithTx:(gint)tx ty:(gint)ty bx:(gint*)bx by:(gint*)by
{
	gtk_tree_view_convert_tree_to_bin_window_coords([self TREEVIEW], tx, ty, bx, by);
}

- (void)convertTreeToWidgetCoordsWithTx:(gint)tx ty:(gint)ty wx:(gint*)wx wy:(gint*)wy
{
	gtk_tree_view_convert_tree_to_widget_coords([self TREEVIEW], tx, ty, wx, wy);
}

- (void)convertWidgetToBinWindowCoordsWithWx:(gint)wx wy:(gint)wy bx:(gint*)bx by:(gint*)by
{
	gtk_tree_view_convert_widget_to_bin_window_coords([self TREEVIEW], wx, wy, bx, by);
}

- (void)convertWidgetToTreeCoordsWithWx:(gint)wx wy:(gint)wy tx:(gint*)tx ty:(gint*)ty
{
	gtk_tree_view_convert_widget_to_tree_coords([self TREEVIEW], wx, wy, tx, ty);
}

- (cairo_surface_t*)createRowDragIcon:(GtkTreePath*)path
{
	return gtk_tree_view_create_row_drag_icon([self TREEVIEW], path);
}

- (void)enableModelDragDestWithTargets:(const GtkTargetEntry*)targets ntargets:(gint)ntargets actions:(GdkDragAction)actions
{
	gtk_tree_view_enable_model_drag_dest([self TREEVIEW], targets, ntargets, actions);
}

- (void)enableModelDragSourceWithStartButtonMask:(GdkModifierType)startButtonMask targets:(const GtkTargetEntry*)targets ntargets:(gint)ntargets actions:(GdkDragAction)actions
{
	gtk_tree_view_enable_model_drag_source([self TREEVIEW], startButtonMask, targets, ntargets, actions);
}

- (void)expandAll
{
	gtk_tree_view_expand_all([self TREEVIEW]);
}

- (bool)expandRowWithPath:(GtkTreePath*)path openAll:(bool)openAll
{
	return gtk_tree_view_expand_row([self TREEVIEW], path, openAll);
}

- (void)expandToPath:(GtkTreePath*)path
{
	gtk_tree_view_expand_to_path([self TREEVIEW], path);
}

- (bool)activateOnSingleClick
{
	return gtk_tree_view_get_activate_on_single_click([self TREEVIEW]);
}

- (void)backgroundAreaWithPath:(GtkTreePath*)path column:(OGTKTreeViewColumn*)column rect:(GdkRectangle*)rect
{
	gtk_tree_view_get_background_area([self TREEVIEW], path, [column TREEVIEWCOLUMN], rect);
}

- (OGGdkWindow*)binWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_tree_view_get_bin_window([self TREEVIEW])] autorelease];
}

- (void)cellAreaWithPath:(GtkTreePath*)path column:(OGTKTreeViewColumn*)column rect:(GdkRectangle*)rect
{
	gtk_tree_view_get_cell_area([self TREEVIEW], path, [column TREEVIEWCOLUMN], rect);
}

- (OGTKTreeViewColumn*)column:(gint)n
{
	return [[[OGTKTreeViewColumn alloc] initWithGObject:(GObject*)gtk_tree_view_get_column([self TREEVIEW], n)] autorelease];
}

- (GList*)columns
{
	return gtk_tree_view_get_columns([self TREEVIEW]);
}

- (void)cursorWithPath:(GtkTreePath**)path focusColumn:(GtkTreeViewColumn**)focusColumn
{
	gtk_tree_view_get_cursor([self TREEVIEW], path, focusColumn);
}

- (bool)destRowAtPosWithDragX:(gint)dragX dragY:(gint)dragY path:(GtkTreePath**)path pos:(GtkTreeViewDropPosition*)pos
{
	return gtk_tree_view_get_dest_row_at_pos([self TREEVIEW], dragX, dragY, path, pos);
}

- (void)dragDestRowWithPath:(GtkTreePath**)path pos:(GtkTreeViewDropPosition*)pos
{
	gtk_tree_view_get_drag_dest_row([self TREEVIEW], path, pos);
}

- (bool)enableSearch
{
	return gtk_tree_view_get_enable_search([self TREEVIEW]);
}

- (bool)enableTreeLines
{
	return gtk_tree_view_get_enable_tree_lines([self TREEVIEW]);
}

- (OGTKTreeViewColumn*)expanderColumn
{
	return [[[OGTKTreeViewColumn alloc] initWithGObject:(GObject*)gtk_tree_view_get_expander_column([self TREEVIEW])] autorelease];
}

- (bool)fixedHeightMode
{
	return gtk_tree_view_get_fixed_height_mode([self TREEVIEW]);
}

- (GtkTreeViewGridLines)gridLines
{
	return gtk_tree_view_get_grid_lines([self TREEVIEW]);
}

- (OGTKAdjustment*)hadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_tree_view_get_hadjustment([self TREEVIEW])] autorelease];
}

- (bool)headersClickable
{
	return gtk_tree_view_get_headers_clickable([self TREEVIEW]);
}

- (bool)headersVisible
{
	return gtk_tree_view_get_headers_visible([self TREEVIEW]);
}

- (bool)hoverExpand
{
	return gtk_tree_view_get_hover_expand([self TREEVIEW]);
}

- (bool)hoverSelection
{
	return gtk_tree_view_get_hover_selection([self TREEVIEW]);
}

- (gint)levelIndentation
{
	return gtk_tree_view_get_level_indentation([self TREEVIEW]);
}

- (GtkTreeModel*)model
{
	return gtk_tree_view_get_model([self TREEVIEW]);
}

- (guint)ncolumns
{
	return gtk_tree_view_get_n_columns([self TREEVIEW]);
}

- (bool)pathAtPosWithX:(gint)x y:(gint)y path:(GtkTreePath**)path column:(GtkTreeViewColumn**)column cellX:(gint*)cellX cellY:(gint*)cellY
{
	return gtk_tree_view_get_path_at_pos([self TREEVIEW], x, y, path, column, cellX, cellY);
}

- (bool)reorderable
{
	return gtk_tree_view_get_reorderable([self TREEVIEW]);
}

- (GtkTreeViewRowSeparatorFunc)rowSeparatorFunc
{
	return gtk_tree_view_get_row_separator_func([self TREEVIEW]);
}

- (bool)rubberBanding
{
	return gtk_tree_view_get_rubber_banding([self TREEVIEW]);
}

- (bool)rulesHint
{
	return gtk_tree_view_get_rules_hint([self TREEVIEW]);
}

- (gint)searchColumn
{
	return gtk_tree_view_get_search_column([self TREEVIEW]);
}

- (OGTKEntry*)searchEntry
{
	return [[[OGTKEntry alloc] initWithGObject:(GObject*)gtk_tree_view_get_search_entry([self TREEVIEW])] autorelease];
}

- (GtkTreeViewSearchEqualFunc)searchEqualFunc
{
	return gtk_tree_view_get_search_equal_func([self TREEVIEW]);
}

- (GtkTreeViewSearchPositionFunc)searchPositionFunc
{
	return gtk_tree_view_get_search_position_func([self TREEVIEW]);
}

- (OGTKTreeSelection*)selection
{
	return [[[OGTKTreeSelection alloc] initWithGObject:(GObject*)gtk_tree_view_get_selection([self TREEVIEW])] autorelease];
}

- (bool)showExpanders
{
	return gtk_tree_view_get_show_expanders([self TREEVIEW]);
}

- (gint)tooltipColumn
{
	return gtk_tree_view_get_tooltip_column([self TREEVIEW]);
}

- (bool)tooltipContextWithX:(gint*)x y:(gint*)y keyboardTip:(bool)keyboardTip model:(GtkTreeModel**)model path:(GtkTreePath**)path iter:(GtkTreeIter*)iter
{
	return gtk_tree_view_get_tooltip_context([self TREEVIEW], x, y, keyboardTip, model, path, iter);
}

- (OGTKAdjustment*)vadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_tree_view_get_vadjustment([self TREEVIEW])] autorelease];
}

- (bool)visibleRangeWithStartPath:(GtkTreePath**)startPath endPath:(GtkTreePath**)endPath
{
	return gtk_tree_view_get_visible_range([self TREEVIEW], startPath, endPath);
}

- (void)visibleRect:(GdkRectangle*)visibleRect
{
	gtk_tree_view_get_visible_rect([self TREEVIEW], visibleRect);
}

- (gint)insertColumnWithColumn:(OGTKTreeViewColumn*)column position:(gint)position
{
	return gtk_tree_view_insert_column([self TREEVIEW], [column TREEVIEWCOLUMN], position);
}

- (gint)insertColumnWithDataFuncWithPosition:(gint)position title:(OFString*)title cell:(OGTKCellRenderer*)cell func:(GtkTreeCellDataFunc)func data:(gpointer)data dnotify:(GDestroyNotify)dnotify
{
	return gtk_tree_view_insert_column_with_data_func([self TREEVIEW], position, [title UTF8String], [cell CELLRENDERER], func, data, dnotify);
}

- (bool)isBlankAtPosWithX:(gint)x y:(gint)y path:(GtkTreePath**)path column:(GtkTreeViewColumn**)column cellX:(gint*)cellX cellY:(gint*)cellY
{
	return gtk_tree_view_is_blank_at_pos([self TREEVIEW], x, y, path, column, cellX, cellY);
}

- (bool)isRubberBandingActive
{
	return gtk_tree_view_is_rubber_banding_active([self TREEVIEW]);
}

- (void)mapExpandedRowsWithFunc:(GtkTreeViewMappingFunc)func data:(gpointer)data
{
	gtk_tree_view_map_expanded_rows([self TREEVIEW], func, data);
}

- (void)moveColumnAfterWithColumn:(OGTKTreeViewColumn*)column baseColumn:(OGTKTreeViewColumn*)baseColumn
{
	gtk_tree_view_move_column_after([self TREEVIEW], [column TREEVIEWCOLUMN], [baseColumn TREEVIEWCOLUMN]);
}

- (gint)removeColumn:(OGTKTreeViewColumn*)column
{
	return gtk_tree_view_remove_column([self TREEVIEW], [column TREEVIEWCOLUMN]);
}

- (void)rowActivatedWithPath:(GtkTreePath*)path column:(OGTKTreeViewColumn*)column
{
	gtk_tree_view_row_activated([self TREEVIEW], path, [column TREEVIEWCOLUMN]);
}

- (bool)rowExpanded:(GtkTreePath*)path
{
	return gtk_tree_view_row_expanded([self TREEVIEW], path);
}

- (void)scrollToCellWithPath:(GtkTreePath*)path column:(OGTKTreeViewColumn*)column useAlign:(bool)useAlign rowAlign:(gfloat)rowAlign colAlign:(gfloat)colAlign
{
	gtk_tree_view_scroll_to_cell([self TREEVIEW], path, [column TREEVIEWCOLUMN], useAlign, rowAlign, colAlign);
}

- (void)scrollToPointWithTreeX:(gint)treeX treeY:(gint)treeY
{
	gtk_tree_view_scroll_to_point([self TREEVIEW], treeX, treeY);
}

- (void)setActivateOnSingleClick:(bool)single
{
	gtk_tree_view_set_activate_on_single_click([self TREEVIEW], single);
}

- (void)setColumnDragFunctionWithFunc:(GtkTreeViewColumnDropFunc)func userData:(gpointer)userData destroy:(GDestroyNotify)destroy
{
	gtk_tree_view_set_column_drag_function([self TREEVIEW], func, userData, destroy);
}

- (void)setCursorWithPath:(GtkTreePath*)path focusColumn:(OGTKTreeViewColumn*)focusColumn startEditing:(bool)startEditing
{
	gtk_tree_view_set_cursor([self TREEVIEW], path, [focusColumn TREEVIEWCOLUMN], startEditing);
}

- (void)setCursorOnCellWithPath:(GtkTreePath*)path focusColumn:(OGTKTreeViewColumn*)focusColumn focusCell:(OGTKCellRenderer*)focusCell startEditing:(bool)startEditing
{
	gtk_tree_view_set_cursor_on_cell([self TREEVIEW], path, [focusColumn TREEVIEWCOLUMN], [focusCell CELLRENDERER], startEditing);
}

- (void)setDestroyCountFuncWithFunc:(GtkTreeDestroyCountFunc)func data:(gpointer)data destroy:(GDestroyNotify)destroy
{
	gtk_tree_view_set_destroy_count_func([self TREEVIEW], func, data, destroy);
}

- (void)setDragDestRowWithPath:(GtkTreePath*)path pos:(GtkTreeViewDropPosition)pos
{
	gtk_tree_view_set_drag_dest_row([self TREEVIEW], path, pos);
}

- (void)setEnableSearch:(bool)enableSearch
{
	gtk_tree_view_set_enable_search([self TREEVIEW], enableSearch);
}

- (void)setEnableTreeLines:(bool)enabled
{
	gtk_tree_view_set_enable_tree_lines([self TREEVIEW], enabled);
}

- (void)setExpanderColumn:(OGTKTreeViewColumn*)column
{
	gtk_tree_view_set_expander_column([self TREEVIEW], [column TREEVIEWCOLUMN]);
}

- (void)setFixedHeightMode:(bool)enable
{
	gtk_tree_view_set_fixed_height_mode([self TREEVIEW], enable);
}

- (void)setGridLines:(GtkTreeViewGridLines)gridLines
{
	gtk_tree_view_set_grid_lines([self TREEVIEW], gridLines);
}

- (void)setHadjustment:(OGTKAdjustment*)adjustment
{
	gtk_tree_view_set_hadjustment([self TREEVIEW], [adjustment ADJUSTMENT]);
}

- (void)setHeadersClickable:(bool)setting
{
	gtk_tree_view_set_headers_clickable([self TREEVIEW], setting);
}

- (void)setHeadersVisible:(bool)headersVisible
{
	gtk_tree_view_set_headers_visible([self TREEVIEW], headersVisible);
}

- (void)setHoverExpand:(bool)expand
{
	gtk_tree_view_set_hover_expand([self TREEVIEW], expand);
}

- (void)setHoverSelection:(bool)hover
{
	gtk_tree_view_set_hover_selection([self TREEVIEW], hover);
}

- (void)setLevelIndentation:(gint)indentation
{
	gtk_tree_view_set_level_indentation([self TREEVIEW], indentation);
}

- (void)setModel:(GtkTreeModel*)model
{
	gtk_tree_view_set_model([self TREEVIEW], model);
}

- (void)setReorderable:(bool)reorderable
{
	gtk_tree_view_set_reorderable([self TREEVIEW], reorderable);
}

- (void)setRowSeparatorFuncWithFunc:(GtkTreeViewRowSeparatorFunc)func data:(gpointer)data destroy:(GDestroyNotify)destroy
{
	gtk_tree_view_set_row_separator_func([self TREEVIEW], func, data, destroy);
}

- (void)setRubberBanding:(bool)enable
{
	gtk_tree_view_set_rubber_banding([self TREEVIEW], enable);
}

- (void)setRulesHint:(bool)setting
{
	gtk_tree_view_set_rules_hint([self TREEVIEW], setting);
}

- (void)setSearchColumn:(gint)column
{
	gtk_tree_view_set_search_column([self TREEVIEW], column);
}

- (void)setSearchEntry:(OGTKEntry*)entry
{
	gtk_tree_view_set_search_entry([self TREEVIEW], [entry ENTRY]);
}

- (void)setSearchEqualFuncWithSearchEqualFunc:(GtkTreeViewSearchEqualFunc)searchEqualFunc searchUserData:(gpointer)searchUserData searchDestroy:(GDestroyNotify)searchDestroy
{
	gtk_tree_view_set_search_equal_func([self TREEVIEW], searchEqualFunc, searchUserData, searchDestroy);
}

- (void)setSearchPositionFuncWithFunc:(GtkTreeViewSearchPositionFunc)func data:(gpointer)data destroy:(GDestroyNotify)destroy
{
	gtk_tree_view_set_search_position_func([self TREEVIEW], func, data, destroy);
}

- (void)setShowExpanders:(bool)enabled
{
	gtk_tree_view_set_show_expanders([self TREEVIEW], enabled);
}

- (void)setTooltipCellWithTooltip:(OGTKTooltip*)tooltip path:(GtkTreePath*)path column:(OGTKTreeViewColumn*)column cell:(OGTKCellRenderer*)cell
{
	gtk_tree_view_set_tooltip_cell([self TREEVIEW], [tooltip TOOLTIP], path, [column TREEVIEWCOLUMN], [cell CELLRENDERER]);
}

- (void)setTooltipColumn:(gint)column
{
	gtk_tree_view_set_tooltip_column([self TREEVIEW], column);
}

- (void)setTooltipRowWithTooltip:(OGTKTooltip*)tooltip path:(GtkTreePath*)path
{
	gtk_tree_view_set_tooltip_row([self TREEVIEW], [tooltip TOOLTIP], path);
}

- (void)setVadjustment:(OGTKAdjustment*)adjustment
{
	gtk_tree_view_set_vadjustment([self TREEVIEW], [adjustment ADJUSTMENT]);
}

- (void)unsetRowsDragDest
{
	gtk_tree_view_unset_rows_drag_dest([self TREEVIEW]);
}

- (void)unsetRowsDragSource
{
	gtk_tree_view_unset_rows_drag_source([self TREEVIEW]);
}


@end