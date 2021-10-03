/*
 * OGTKTreeViewColumn.h
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
#import "OGTKBase.h"

@interface OGTKTreeViewColumn : OGTKBase
{

}


/**
 * Constructors
 */
- (id)init;
- (id)initWithArea:(GtkCellArea*)area;

/**
 * Methods
 */

- (GtkTreeViewColumn*)TREEVIEWCOLUMN;

/**
 * - (void*)addAttributeWithCellRenderer:(GtkCellRenderer*)cellRenderer andAttribute:(OFString*)attribute andColumn:(gint)column;
 *
 * @param cellRenderer
 * @param attribute
 * @param column
 */
- (void)addAttributeWithCellRenderer:(GtkCellRenderer*)cellRenderer andAttribute:(OFString*)attribute andColumn:(gint)column;

/**
 * - (bool*)cellGetPositionWithCellRenderer:(GtkCellRenderer*)cellRenderer andXoffset:(gint*)xoffset andWidth:(gint*)width;
 *
 * @param cellRenderer
 * @param xoffset
 * @param width
 * @returns bool
 */
- (bool)cellGetPositionWithCellRenderer:(GtkCellRenderer*)cellRenderer andXoffset:(gint*)xoffset andWidth:(gint*)width;

/**
 * - (void*)cellGetSizeWithCellArea:(const GdkRectangle*)cellArea andXoffset:(gint*)xoffset andYoffset:(gint*)yoffset andWidth:(gint*)width andHeight:(gint*)height;
 *
 * @param cellArea
 * @param xoffset
 * @param yoffset
 * @param width
 * @param height
 */
- (void)cellGetSizeWithCellArea:(const GdkRectangle*)cellArea andXoffset:(gint*)xoffset andYoffset:(gint*)yoffset andWidth:(gint*)width andHeight:(gint*)height;

/**
 * - (bool*)cellIsVisible;
 *
 * @returns bool
 */
- (bool)cellIsVisible;

/**
 * - (void*)cellSetCellDataWithTreeModel:(GtkTreeModel*)treeModel andIter:(GtkTreeIter*)iter andIsExpander:(bool)isExpander andIsExpanded:(bool)isExpanded;
 *
 * @param treeModel
 * @param iter
 * @param isExpander
 * @param isExpanded
 */
- (void)cellSetCellDataWithTreeModel:(GtkTreeModel*)treeModel andIter:(GtkTreeIter*)iter andIsExpander:(bool)isExpander andIsExpanded:(bool)isExpanded;

/**
 * - (void*)clear;
 *
 */
- (void)clear;

/**
 * - (void*)clearAttributes:(GtkCellRenderer*)cellRenderer;
 *
 * @param cellRenderer
 */
- (void)clearAttributes:(GtkCellRenderer*)cellRenderer;

/**
 * - (void*)clicked;
 *
 */
- (void)clicked;

/**
 * - (void*)focusCell:(GtkCellRenderer*)cell;
 *
 * @param cell
 */
- (void)focusCell:(GtkCellRenderer*)cell;

/**
 * - (gfloat*)getAlignment;
 *
 * @returns gfloat
 */
- (gfloat)getAlignment;

/**
 * - (OGTKWidget**)getButton;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getButton;

/**
 * - (bool*)getClickable;
 *
 * @returns bool
 */
- (bool)getClickable;

/**
 * - (bool*)getExpand;
 *
 * @returns bool
 */
- (bool)getExpand;

/**
 * - (gint*)getFixedWidth;
 *
 * @returns gint
 */
- (gint)getFixedWidth;

/**
 * - (gint*)getMaxWidth;
 *
 * @returns gint
 */
- (gint)getMaxWidth;

/**
 * - (gint*)getMinWidth;
 *
 * @returns gint
 */
- (gint)getMinWidth;

/**
 * - (bool*)getReorderable;
 *
 * @returns bool
 */
- (bool)getReorderable;

/**
 * - (bool*)getResizable;
 *
 * @returns bool
 */
- (bool)getResizable;

/**
 * - (GtkTreeViewColumnSizing*)getSizing;
 *
 * @returns GtkTreeViewColumnSizing
 */
- (GtkTreeViewColumnSizing)getSizing;

/**
 * - (gint*)getSortColumnId;
 *
 * @returns gint
 */
- (gint)getSortColumnId;

/**
 * - (bool*)getSortIndicator;
 *
 * @returns bool
 */
- (bool)getSortIndicator;

/**
 * - (GtkSortType*)getSortOrder;
 *
 * @returns GtkSortType
 */
- (GtkSortType)getSortOrder;

/**
 * - (gint*)getSpacing;
 *
 * @returns gint
 */
- (gint)getSpacing;

/**
 * - (OFString**)getTitle;
 *
 * @returns OFString*
 */
- (OFString*)getTitle;

/**
 * - (OGTKWidget**)getTreeView;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getTreeView;

/**
 * - (bool*)getVisible;
 *
 * @returns bool
 */
- (bool)getVisible;

/**
 * - (OGTKWidget**)getWidget;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getWidget;

/**
 * - (gint*)getWidth;
 *
 * @returns gint
 */
- (gint)getWidth;

/**
 * - (gint*)getXoffset;
 *
 * @returns gint
 */
- (gint)getXoffset;

/**
 * - (void*)packEndWithCell:(GtkCellRenderer*)cell andExpand:(bool)expand;
 *
 * @param cell
 * @param expand
 */
- (void)packEndWithCell:(GtkCellRenderer*)cell andExpand:(bool)expand;

/**
 * - (void*)packStartWithCell:(GtkCellRenderer*)cell andExpand:(bool)expand;
 *
 * @param cell
 * @param expand
 */
- (void)packStartWithCell:(GtkCellRenderer*)cell andExpand:(bool)expand;

/**
 * - (void*)queueResize;
 *
 */
- (void)queueResize;

/**
 * - (void*)setAlignment:(gfloat)xalign;
 *
 * @param xalign
 */
- (void)setAlignment:(gfloat)xalign;

/**
 * - (void*)setCellDataFuncWithCellRenderer:(GtkCellRenderer*)cellRenderer andFunc:(GtkTreeCellDataFunc)func andFuncData:(gpointer)funcData andDestroy:(GDestroyNotify)destroy;
 *
 * @param cellRenderer
 * @param func
 * @param funcData
 * @param destroy
 */
- (void)setCellDataFuncWithCellRenderer:(GtkCellRenderer*)cellRenderer andFunc:(GtkTreeCellDataFunc)func andFuncData:(gpointer)funcData andDestroy:(GDestroyNotify)destroy;

/**
 * - (void*)setClickable:(bool)clickable;
 *
 * @param clickable
 */
- (void)setClickable:(bool)clickable;

/**
 * - (void*)setExpand:(bool)expand;
 *
 * @param expand
 */
- (void)setExpand:(bool)expand;

/**
 * - (void*)setFixedWidth:(gint)fixedWidth;
 *
 * @param fixedWidth
 */
- (void)setFixedWidth:(gint)fixedWidth;

/**
 * - (void*)setMaxWidth:(gint)maxWidth;
 *
 * @param maxWidth
 */
- (void)setMaxWidth:(gint)maxWidth;

/**
 * - (void*)setMinWidth:(gint)minWidth;
 *
 * @param minWidth
 */
- (void)setMinWidth:(gint)minWidth;

/**
 * - (void*)setReorderable:(bool)reorderable;
 *
 * @param reorderable
 */
- (void)setReorderable:(bool)reorderable;

/**
 * - (void*)setResizable:(bool)resizable;
 *
 * @param resizable
 */
- (void)setResizable:(bool)resizable;

/**
 * - (void*)setSizing:(GtkTreeViewColumnSizing)type;
 *
 * @param type
 */
- (void)setSizing:(GtkTreeViewColumnSizing)type;

/**
 * - (void*)setSortColumnId:(gint)sortColumnId;
 *
 * @param sortColumnId
 */
- (void)setSortColumnId:(gint)sortColumnId;

/**
 * - (void*)setSortIndicator:(bool)setting;
 *
 * @param setting
 */
- (void)setSortIndicator:(bool)setting;

/**
 * - (void*)setSortOrder:(GtkSortType)order;
 *
 * @param order
 */
- (void)setSortOrder:(GtkSortType)order;

/**
 * - (void*)setSpacing:(gint)spacing;
 *
 * @param spacing
 */
- (void)setSpacing:(gint)spacing;

/**
 * - (void*)setTitle:(OFString*)title;
 *
 * @param title
 */
- (void)setTitle:(OFString*)title;

/**
 * - (void*)setVisible:(bool)visible;
 *
 * @param visible
 */
- (void)setVisible:(bool)visible;

/**
 * - (void*)setWidget:(OGTKWidget*)widget;
 *
 * @param widget
 */
- (void)setWidget:(OGTKWidget*)widget;

@end