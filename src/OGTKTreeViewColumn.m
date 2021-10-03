/*
 * OGTKTreeViewColumn.m
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
#import "OGTKTreeViewColumn.h"

@implementation OGTKTreeViewColumn

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_tree_view_column_new()];

	return self;
}

- (id)initWithArea:(GtkCellArea*)area
{
	self = [super initWithGObject:(GObject*)gtk_tree_view_column_new_with_area(area)];

	return self;
}

- (GtkTreeViewColumn*)TREEVIEWCOLUMN
{
	return GTK_TREE_VIEW_COLUMN([self GOBJECT]);
}

- (void)addAttributeWithCellRenderer:(GtkCellRenderer*)cellRenderer andAttribute:(OFString*)attribute andColumn:(gint)column
{
	gtk_tree_view_column_add_attribute(GTK_TREE_VIEW_COLUMN([self GOBJECT]), cellRenderer, [attribute UTF8String], column);
}

- (bool)cellGetPositionWithCellRenderer:(GtkCellRenderer*)cellRenderer andXoffset:(gint*)xoffset andWidth:(gint*)width
{
	return gtk_tree_view_column_cell_get_position(GTK_TREE_VIEW_COLUMN([self GOBJECT]), cellRenderer, xoffset, width);
}

- (void)cellGetSizeWithCellArea:(const GdkRectangle*)cellArea andXoffset:(gint*)xoffset andYoffset:(gint*)yoffset andWidth:(gint*)width andHeight:(gint*)height
{
	gtk_tree_view_column_cell_get_size(GTK_TREE_VIEW_COLUMN([self GOBJECT]), cellArea, xoffset, yoffset, width, height);
}

- (bool)cellIsVisible
{
	return gtk_tree_view_column_cell_is_visible(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (void)cellSetCellDataWithTreeModel:(GtkTreeModel*)treeModel andIter:(GtkTreeIter*)iter andIsExpander:(bool)isExpander andIsExpanded:(bool)isExpanded
{
	gtk_tree_view_column_cell_set_cell_data(GTK_TREE_VIEW_COLUMN([self GOBJECT]), treeModel, iter, isExpander, isExpanded);
}

- (void)clear
{
	gtk_tree_view_column_clear(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (void)clearAttributes:(GtkCellRenderer*)cellRenderer
{
	gtk_tree_view_column_clear_attributes(GTK_TREE_VIEW_COLUMN([self GOBJECT]), cellRenderer);
}

- (void)clicked
{
	gtk_tree_view_column_clicked(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (void)focusCell:(GtkCellRenderer*)cell
{
	gtk_tree_view_column_focus_cell(GTK_TREE_VIEW_COLUMN([self GOBJECT]), cell);
}

- (gfloat)getAlignment
{
	return gtk_tree_view_column_get_alignment(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (OGTKWidget*)getButton
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tree_view_column_get_button(GTK_TREE_VIEW_COLUMN([self GOBJECT]))];
}

- (bool)getClickable
{
	return gtk_tree_view_column_get_clickable(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (bool)getExpand
{
	return gtk_tree_view_column_get_expand(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (gint)getFixedWidth
{
	return gtk_tree_view_column_get_fixed_width(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (gint)getMaxWidth
{
	return gtk_tree_view_column_get_max_width(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (gint)getMinWidth
{
	return gtk_tree_view_column_get_min_width(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (bool)getReorderable
{
	return gtk_tree_view_column_get_reorderable(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (bool)getResizable
{
	return gtk_tree_view_column_get_resizable(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (GtkTreeViewColumnSizing)getSizing
{
	return gtk_tree_view_column_get_sizing(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (gint)getSortColumnId
{
	return gtk_tree_view_column_get_sort_column_id(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (bool)getSortIndicator
{
	return gtk_tree_view_column_get_sort_indicator(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (GtkSortType)getSortOrder
{
	return gtk_tree_view_column_get_sort_order(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (gint)getSpacing
{
	return gtk_tree_view_column_get_spacing(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (OFString*)getTitle
{
	return [OFString stringWithUTF8String:gtk_tree_view_column_get_title(GTK_TREE_VIEW_COLUMN([self GOBJECT]))];
}

- (OGTKWidget*)getTreeView
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tree_view_column_get_tree_view(GTK_TREE_VIEW_COLUMN([self GOBJECT]))];
}

- (bool)getVisible
{
	return gtk_tree_view_column_get_visible(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (OGTKWidget*)getWidget
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_tree_view_column_get_widget(GTK_TREE_VIEW_COLUMN([self GOBJECT]))];
}

- (gint)getWidth
{
	return gtk_tree_view_column_get_width(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (gint)getXoffset
{
	return gtk_tree_view_column_get_x_offset(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (void)packEndWithCell:(GtkCellRenderer*)cell andExpand:(bool)expand
{
	gtk_tree_view_column_pack_end(GTK_TREE_VIEW_COLUMN([self GOBJECT]), cell, expand);
}

- (void)packStartWithCell:(GtkCellRenderer*)cell andExpand:(bool)expand
{
	gtk_tree_view_column_pack_start(GTK_TREE_VIEW_COLUMN([self GOBJECT]), cell, expand);
}

- (void)queueResize
{
	gtk_tree_view_column_queue_resize(GTK_TREE_VIEW_COLUMN([self GOBJECT]));
}

- (void)setAlignment:(gfloat)xalign
{
	gtk_tree_view_column_set_alignment(GTK_TREE_VIEW_COLUMN([self GOBJECT]), xalign);
}

- (void)setCellDataFuncWithCellRenderer:(GtkCellRenderer*)cellRenderer andFunc:(GtkTreeCellDataFunc)func andFuncData:(gpointer)funcData andDestroy:(GDestroyNotify)destroy
{
	gtk_tree_view_column_set_cell_data_func(GTK_TREE_VIEW_COLUMN([self GOBJECT]), cellRenderer, func, funcData, destroy);
}

- (void)setClickable:(bool)clickable
{
	gtk_tree_view_column_set_clickable(GTK_TREE_VIEW_COLUMN([self GOBJECT]), clickable);
}

- (void)setExpand:(bool)expand
{
	gtk_tree_view_column_set_expand(GTK_TREE_VIEW_COLUMN([self GOBJECT]), expand);
}

- (void)setFixedWidth:(gint)fixedWidth
{
	gtk_tree_view_column_set_fixed_width(GTK_TREE_VIEW_COLUMN([self GOBJECT]), fixedWidth);
}

- (void)setMaxWidth:(gint)maxWidth
{
	gtk_tree_view_column_set_max_width(GTK_TREE_VIEW_COLUMN([self GOBJECT]), maxWidth);
}

- (void)setMinWidth:(gint)minWidth
{
	gtk_tree_view_column_set_min_width(GTK_TREE_VIEW_COLUMN([self GOBJECT]), minWidth);
}

- (void)setReorderable:(bool)reorderable
{
	gtk_tree_view_column_set_reorderable(GTK_TREE_VIEW_COLUMN([self GOBJECT]), reorderable);
}

- (void)setResizable:(bool)resizable
{
	gtk_tree_view_column_set_resizable(GTK_TREE_VIEW_COLUMN([self GOBJECT]), resizable);
}

- (void)setSizing:(GtkTreeViewColumnSizing)type
{
	gtk_tree_view_column_set_sizing(GTK_TREE_VIEW_COLUMN([self GOBJECT]), type);
}

- (void)setSortColumnId:(gint)sortColumnId
{
	gtk_tree_view_column_set_sort_column_id(GTK_TREE_VIEW_COLUMN([self GOBJECT]), sortColumnId);
}

- (void)setSortIndicator:(bool)setting
{
	gtk_tree_view_column_set_sort_indicator(GTK_TREE_VIEW_COLUMN([self GOBJECT]), setting);
}

- (void)setSortOrder:(GtkSortType)order
{
	gtk_tree_view_column_set_sort_order(GTK_TREE_VIEW_COLUMN([self GOBJECT]), order);
}

- (void)setSpacing:(gint)spacing
{
	gtk_tree_view_column_set_spacing(GTK_TREE_VIEW_COLUMN([self GOBJECT]), spacing);
}

- (void)setTitle:(OFString*)title
{
	gtk_tree_view_column_set_title(GTK_TREE_VIEW_COLUMN([self GOBJECT]), [title UTF8String]);
}

- (void)setVisible:(bool)visible
{
	gtk_tree_view_column_set_visible(GTK_TREE_VIEW_COLUMN([self GOBJECT]), visible);
}

- (void)setWidget:(OGTKWidget*)widget
{
	gtk_tree_view_column_set_widget(GTK_TREE_VIEW_COLUMN([self GOBJECT]), [widget WIDGET]);
}


@end