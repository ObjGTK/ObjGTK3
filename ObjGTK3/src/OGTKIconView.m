/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKIconView.h"

#import "OGTKCellArea.h"
#import "OGTKTooltip.h"
#import "OGTKWidget.h"
#import "OGTKCellRenderer.h"

@implementation OGTKIconView

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_icon_view_new()];

	return self;
}

- (instancetype)initWithArea:(OGTKCellArea*)area
{
	self = [super initWithGObject:(GObject*)gtk_icon_view_new_with_area([area CELLAREA])];

	return self;
}

- (instancetype)initWithModel:(GtkTreeModel*)model
{
	self = [super initWithGObject:(GObject*)gtk_icon_view_new_with_model(model)];

	return self;
}

- (GtkIconView*)ICONVIEW
{
	return GTK_ICON_VIEW([self GOBJECT]);
}

- (void)convertWidgetToBinWindowCoordsWithWx:(gint)wx wy:(gint)wy bx:(gint*)bx by:(gint*)by
{
	gtk_icon_view_convert_widget_to_bin_window_coords([self ICONVIEW], wx, wy, bx, by);
}

- (cairo_surface_t*)createDragIcon:(GtkTreePath*)path
{
	return gtk_icon_view_create_drag_icon([self ICONVIEW], path);
}

- (void)enableModelDragDestWithTargets:(const GtkTargetEntry*)targets ntargets:(gint)ntargets actions:(GdkDragAction)actions
{
	gtk_icon_view_enable_model_drag_dest([self ICONVIEW], targets, ntargets, actions);
}

- (void)enableModelDragSourceWithStartButtonMask:(GdkModifierType)startButtonMask targets:(const GtkTargetEntry*)targets ntargets:(gint)ntargets actions:(GdkDragAction)actions
{
	gtk_icon_view_enable_model_drag_source([self ICONVIEW], startButtonMask, targets, ntargets, actions);
}

- (bool)activateOnSingleClick
{
	return gtk_icon_view_get_activate_on_single_click([self ICONVIEW]);
}

- (bool)cellRectWithPath:(GtkTreePath*)path cell:(OGTKCellRenderer*)cell rect:(GdkRectangle*)rect
{
	return gtk_icon_view_get_cell_rect([self ICONVIEW], path, [cell CELLRENDERER], rect);
}

- (gint)columnSpacing
{
	return gtk_icon_view_get_column_spacing([self ICONVIEW]);
}

- (gint)columns
{
	return gtk_icon_view_get_columns([self ICONVIEW]);
}

- (bool)cursorWithPath:(GtkTreePath**)path cell:(GtkCellRenderer**)cell
{
	return gtk_icon_view_get_cursor([self ICONVIEW], path, cell);
}

- (bool)destItemAtPosWithDragX:(gint)dragX dragY:(gint)dragY path:(GtkTreePath**)path pos:(GtkIconViewDropPosition*)pos
{
	return gtk_icon_view_get_dest_item_at_pos([self ICONVIEW], dragX, dragY, path, pos);
}

- (void)dragDestItemWithPath:(GtkTreePath**)path pos:(GtkIconViewDropPosition*)pos
{
	gtk_icon_view_get_drag_dest_item([self ICONVIEW], path, pos);
}

- (bool)itemAtPosWithX:(gint)x y:(gint)y path:(GtkTreePath**)path cell:(GtkCellRenderer**)cell
{
	return gtk_icon_view_get_item_at_pos([self ICONVIEW], x, y, path, cell);
}

- (gint)itemColumn:(GtkTreePath*)path
{
	return gtk_icon_view_get_item_column([self ICONVIEW], path);
}

- (GtkOrientation)itemOrientation
{
	return gtk_icon_view_get_item_orientation([self ICONVIEW]);
}

- (gint)itemPadding
{
	return gtk_icon_view_get_item_padding([self ICONVIEW]);
}

- (gint)itemRow:(GtkTreePath*)path
{
	return gtk_icon_view_get_item_row([self ICONVIEW], path);
}

- (gint)itemWidth
{
	return gtk_icon_view_get_item_width([self ICONVIEW]);
}

- (gint)margin
{
	return gtk_icon_view_get_margin([self ICONVIEW]);
}

- (gint)markupColumn
{
	return gtk_icon_view_get_markup_column([self ICONVIEW]);
}

- (GtkTreeModel*)model
{
	return gtk_icon_view_get_model([self ICONVIEW]);
}

- (GtkTreePath*)pathAtPosWithX:(gint)x y:(gint)y
{
	return gtk_icon_view_get_path_at_pos([self ICONVIEW], x, y);
}

- (gint)pixbufColumn
{
	return gtk_icon_view_get_pixbuf_column([self ICONVIEW]);
}

- (bool)reorderable
{
	return gtk_icon_view_get_reorderable([self ICONVIEW]);
}

- (gint)rowSpacing
{
	return gtk_icon_view_get_row_spacing([self ICONVIEW]);
}

- (GList*)selectedItems
{
	return gtk_icon_view_get_selected_items([self ICONVIEW]);
}

- (GtkSelectionMode)selectionMode
{
	return gtk_icon_view_get_selection_mode([self ICONVIEW]);
}

- (gint)spacing
{
	return gtk_icon_view_get_spacing([self ICONVIEW]);
}

- (gint)textColumn
{
	return gtk_icon_view_get_text_column([self ICONVIEW]);
}

- (gint)tooltipColumn
{
	return gtk_icon_view_get_tooltip_column([self ICONVIEW]);
}

- (bool)tooltipContextWithX:(gint*)x y:(gint*)y keyboardTip:(bool)keyboardTip model:(GtkTreeModel**)model path:(GtkTreePath**)path iter:(GtkTreeIter*)iter
{
	return gtk_icon_view_get_tooltip_context([self ICONVIEW], x, y, keyboardTip, model, path, iter);
}

- (bool)visibleRangeWithStartPath:(GtkTreePath**)startPath endPath:(GtkTreePath**)endPath
{
	return gtk_icon_view_get_visible_range([self ICONVIEW], startPath, endPath);
}

- (void)itemActivated:(GtkTreePath*)path
{
	gtk_icon_view_item_activated([self ICONVIEW], path);
}

- (bool)pathIsSelected:(GtkTreePath*)path
{
	return gtk_icon_view_path_is_selected([self ICONVIEW], path);
}

- (void)scrollToPathWithPath:(GtkTreePath*)path useAlign:(bool)useAlign rowAlign:(gfloat)rowAlign colAlign:(gfloat)colAlign
{
	gtk_icon_view_scroll_to_path([self ICONVIEW], path, useAlign, rowAlign, colAlign);
}

- (void)selectAll
{
	gtk_icon_view_select_all([self ICONVIEW]);
}

- (void)selectPath:(GtkTreePath*)path
{
	gtk_icon_view_select_path([self ICONVIEW], path);
}

- (void)selectedForeachWithFunc:(GtkIconViewForeachFunc)func data:(gpointer)data
{
	gtk_icon_view_selected_foreach([self ICONVIEW], func, data);
}

- (void)setActivateOnSingleClick:(bool)single
{
	gtk_icon_view_set_activate_on_single_click([self ICONVIEW], single);
}

- (void)setColumnSpacing:(gint)columnSpacing
{
	gtk_icon_view_set_column_spacing([self ICONVIEW], columnSpacing);
}

- (void)setColumns:(gint)columns
{
	gtk_icon_view_set_columns([self ICONVIEW], columns);
}

- (void)setCursorWithPath:(GtkTreePath*)path cell:(OGTKCellRenderer*)cell startEditing:(bool)startEditing
{
	gtk_icon_view_set_cursor([self ICONVIEW], path, [cell CELLRENDERER], startEditing);
}

- (void)setDragDestItemWithPath:(GtkTreePath*)path pos:(GtkIconViewDropPosition)pos
{
	gtk_icon_view_set_drag_dest_item([self ICONVIEW], path, pos);
}

- (void)setItemOrientation:(GtkOrientation)orientation
{
	gtk_icon_view_set_item_orientation([self ICONVIEW], orientation);
}

- (void)setItemPadding:(gint)itemPadding
{
	gtk_icon_view_set_item_padding([self ICONVIEW], itemPadding);
}

- (void)setItemWidth:(gint)itemWidth
{
	gtk_icon_view_set_item_width([self ICONVIEW], itemWidth);
}

- (void)setMargin:(gint)margin
{
	gtk_icon_view_set_margin([self ICONVIEW], margin);
}

- (void)setMarkupColumn:(gint)column
{
	gtk_icon_view_set_markup_column([self ICONVIEW], column);
}

- (void)setModel:(GtkTreeModel*)model
{
	gtk_icon_view_set_model([self ICONVIEW], model);
}

- (void)setPixbufColumn:(gint)column
{
	gtk_icon_view_set_pixbuf_column([self ICONVIEW], column);
}

- (void)setReorderable:(bool)reorderable
{
	gtk_icon_view_set_reorderable([self ICONVIEW], reorderable);
}

- (void)setRowSpacing:(gint)rowSpacing
{
	gtk_icon_view_set_row_spacing([self ICONVIEW], rowSpacing);
}

- (void)setSelectionMode:(GtkSelectionMode)mode
{
	gtk_icon_view_set_selection_mode([self ICONVIEW], mode);
}

- (void)setSpacing:(gint)spacing
{
	gtk_icon_view_set_spacing([self ICONVIEW], spacing);
}

- (void)setTextColumn:(gint)column
{
	gtk_icon_view_set_text_column([self ICONVIEW], column);
}

- (void)setTooltipCellWithTooltip:(OGTKTooltip*)tooltip path:(GtkTreePath*)path cell:(OGTKCellRenderer*)cell
{
	gtk_icon_view_set_tooltip_cell([self ICONVIEW], [tooltip TOOLTIP], path, [cell CELLRENDERER]);
}

- (void)setTooltipColumn:(gint)column
{
	gtk_icon_view_set_tooltip_column([self ICONVIEW], column);
}

- (void)setTooltipItemWithTooltip:(OGTKTooltip*)tooltip path:(GtkTreePath*)path
{
	gtk_icon_view_set_tooltip_item([self ICONVIEW], [tooltip TOOLTIP], path);
}

- (void)unselectAll
{
	gtk_icon_view_unselect_all([self ICONVIEW]);
}

- (void)unselectPath:(GtkTreePath*)path
{
	gtk_icon_view_unselect_path([self ICONVIEW], path);
}

- (void)unsetModelDragDest
{
	gtk_icon_view_unset_model_drag_dest([self ICONVIEW]);
}

- (void)unsetModelDragSource
{
	gtk_icon_view_unset_model_drag_source([self ICONVIEW]);
}


@end