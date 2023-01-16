/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTreeViewColumn.h"

#import "OGTKCellArea.h"
#import "OGTKWidget.h"
#import "OGTKCellRenderer.h"

@implementation OGTKTreeViewColumn

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_tree_view_column_new()];

	return self;
}

- (instancetype)initWithArea:(OGTKCellArea*)area
{
	self = [super initWithGObject:(GObject*)gtk_tree_view_column_new_with_area([area CELLAREA])];

	return self;
}

- (GtkTreeViewColumn*)TREEVIEWCOLUMN
{
	return GTK_TREE_VIEW_COLUMN([self GOBJECT]);
}

- (void)addAttributeWithCellRenderer:(OGTKCellRenderer*)cellRenderer attribute:(OFString*)attribute column:(gint)column
{
	gtk_tree_view_column_add_attribute([self TREEVIEWCOLUMN], [cellRenderer CELLRENDERER], [attribute UTF8String], column);
}

- (bool)cellGetPositionWithCellRenderer:(OGTKCellRenderer*)cellRenderer xoffset:(gint*)xoffset width:(gint*)width
{
	return gtk_tree_view_column_cell_get_position([self TREEVIEWCOLUMN], [cellRenderer CELLRENDERER], xoffset, width);
}

- (void)cellGetSizeWithCellArea:(const GdkRectangle*)cellArea xoffset:(gint*)xoffset yoffset:(gint*)yoffset width:(gint*)width height:(gint*)height
{
	gtk_tree_view_column_cell_get_size([self TREEVIEWCOLUMN], cellArea, xoffset, yoffset, width, height);
}

- (bool)cellIsVisible
{
	return gtk_tree_view_column_cell_is_visible([self TREEVIEWCOLUMN]);
}

- (void)cellSetCellDataWithTreeModel:(GtkTreeModel*)treeModel iter:(GtkTreeIter*)iter isExpander:(bool)isExpander isExpanded:(bool)isExpanded
{
	gtk_tree_view_column_cell_set_cell_data([self TREEVIEWCOLUMN], treeModel, iter, isExpander, isExpanded);
}

- (void)clear
{
	gtk_tree_view_column_clear([self TREEVIEWCOLUMN]);
}

- (void)clearAttributes:(OGTKCellRenderer*)cellRenderer
{
	gtk_tree_view_column_clear_attributes([self TREEVIEWCOLUMN], [cellRenderer CELLRENDERER]);
}

- (void)clicked
{
	gtk_tree_view_column_clicked([self TREEVIEWCOLUMN]);
}

- (void)focusCell:(OGTKCellRenderer*)cell
{
	gtk_tree_view_column_focus_cell([self TREEVIEWCOLUMN], [cell CELLRENDERER]);
}

- (gfloat)alignment
{
	return gtk_tree_view_column_get_alignment([self TREEVIEWCOLUMN]);
}

- (OGTKWidget*)button
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tree_view_column_get_button([self TREEVIEWCOLUMN])] autorelease];
}

- (bool)clickable
{
	return gtk_tree_view_column_get_clickable([self TREEVIEWCOLUMN]);
}

- (bool)expand
{
	return gtk_tree_view_column_get_expand([self TREEVIEWCOLUMN]);
}

- (gint)fixedWidth
{
	return gtk_tree_view_column_get_fixed_width([self TREEVIEWCOLUMN]);
}

- (gint)maxWidth
{
	return gtk_tree_view_column_get_max_width([self TREEVIEWCOLUMN]);
}

- (gint)minWidth
{
	return gtk_tree_view_column_get_min_width([self TREEVIEWCOLUMN]);
}

- (bool)reorderable
{
	return gtk_tree_view_column_get_reorderable([self TREEVIEWCOLUMN]);
}

- (bool)resizable
{
	return gtk_tree_view_column_get_resizable([self TREEVIEWCOLUMN]);
}

- (GtkTreeViewColumnSizing)sizing
{
	return gtk_tree_view_column_get_sizing([self TREEVIEWCOLUMN]);
}

- (gint)sortColumnId
{
	return gtk_tree_view_column_get_sort_column_id([self TREEVIEWCOLUMN]);
}

- (bool)sortIndicator
{
	return gtk_tree_view_column_get_sort_indicator([self TREEVIEWCOLUMN]);
}

- (GtkSortType)sortOrder
{
	return gtk_tree_view_column_get_sort_order([self TREEVIEWCOLUMN]);
}

- (gint)spacing
{
	return gtk_tree_view_column_get_spacing([self TREEVIEWCOLUMN]);
}

- (OFString*)title
{
	return [OFString stringWithUTF8String:gtk_tree_view_column_get_title([self TREEVIEWCOLUMN])];
}

- (OGTKWidget*)treeView
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tree_view_column_get_tree_view([self TREEVIEWCOLUMN])] autorelease];
}

- (bool)visible
{
	return gtk_tree_view_column_get_visible([self TREEVIEWCOLUMN]);
}

- (OGTKWidget*)widget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tree_view_column_get_widget([self TREEVIEWCOLUMN])] autorelease];
}

- (gint)width
{
	return gtk_tree_view_column_get_width([self TREEVIEWCOLUMN]);
}

- (gint)xoffset
{
	return gtk_tree_view_column_get_x_offset([self TREEVIEWCOLUMN]);
}

- (void)packEndWithCell:(OGTKCellRenderer*)cell expand:(bool)expand
{
	gtk_tree_view_column_pack_end([self TREEVIEWCOLUMN], [cell CELLRENDERER], expand);
}

- (void)packStartWithCell:(OGTKCellRenderer*)cell expand:(bool)expand
{
	gtk_tree_view_column_pack_start([self TREEVIEWCOLUMN], [cell CELLRENDERER], expand);
}

- (void)queueResize
{
	gtk_tree_view_column_queue_resize([self TREEVIEWCOLUMN]);
}

- (void)setAlignment:(gfloat)xalign
{
	gtk_tree_view_column_set_alignment([self TREEVIEWCOLUMN], xalign);
}

- (void)setCellDataFuncWithCellRenderer:(OGTKCellRenderer*)cellRenderer func:(GtkTreeCellDataFunc)func funcData:(gpointer)funcData destroy:(GDestroyNotify)destroy
{
	gtk_tree_view_column_set_cell_data_func([self TREEVIEWCOLUMN], [cellRenderer CELLRENDERER], func, funcData, destroy);
}

- (void)setClickable:(bool)clickable
{
	gtk_tree_view_column_set_clickable([self TREEVIEWCOLUMN], clickable);
}

- (void)setExpand:(bool)expand
{
	gtk_tree_view_column_set_expand([self TREEVIEWCOLUMN], expand);
}

- (void)setFixedWidth:(gint)fixedWidth
{
	gtk_tree_view_column_set_fixed_width([self TREEVIEWCOLUMN], fixedWidth);
}

- (void)setMaxWidth:(gint)maxWidth
{
	gtk_tree_view_column_set_max_width([self TREEVIEWCOLUMN], maxWidth);
}

- (void)setMinWidth:(gint)minWidth
{
	gtk_tree_view_column_set_min_width([self TREEVIEWCOLUMN], minWidth);
}

- (void)setReorderable:(bool)reorderable
{
	gtk_tree_view_column_set_reorderable([self TREEVIEWCOLUMN], reorderable);
}

- (void)setResizable:(bool)resizable
{
	gtk_tree_view_column_set_resizable([self TREEVIEWCOLUMN], resizable);
}

- (void)setSizing:(GtkTreeViewColumnSizing)type
{
	gtk_tree_view_column_set_sizing([self TREEVIEWCOLUMN], type);
}

- (void)setSortColumnId:(gint)sortColumnId
{
	gtk_tree_view_column_set_sort_column_id([self TREEVIEWCOLUMN], sortColumnId);
}

- (void)setSortIndicator:(bool)setting
{
	gtk_tree_view_column_set_sort_indicator([self TREEVIEWCOLUMN], setting);
}

- (void)setSortOrder:(GtkSortType)order
{
	gtk_tree_view_column_set_sort_order([self TREEVIEWCOLUMN], order);
}

- (void)setSpacing:(gint)spacing
{
	gtk_tree_view_column_set_spacing([self TREEVIEWCOLUMN], spacing);
}

- (void)setTitle:(OFString*)title
{
	gtk_tree_view_column_set_title([self TREEVIEWCOLUMN], [title UTF8String]);
}

- (void)setVisible:(bool)visible
{
	gtk_tree_view_column_set_visible([self TREEVIEWCOLUMN], visible);
}

- (void)setWidget:(OGTKWidget*)widget
{
	gtk_tree_view_column_set_widget([self TREEVIEWCOLUMN], [widget WIDGET]);
}


@end