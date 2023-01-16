/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKListBox.h"

#import "OGTKAdjustment.h"
#import "OGTKWidget.h"
#import "OGTKListBoxRow.h"

@implementation OGTKListBox

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_list_box_new()];

	return self;
}

- (GtkListBox*)LISTBOX
{
	return GTK_LIST_BOX([self GOBJECT]);
}

- (void)bindModelWithModel:(GListModel*)model createWidgetFunc:(GtkListBoxCreateWidgetFunc)createWidgetFunc userData:(gpointer)userData userDataFreeFunc:(GDestroyNotify)userDataFreeFunc
{
	gtk_list_box_bind_model([self LISTBOX], model, createWidgetFunc, userData, userDataFreeFunc);
}

- (void)dragHighlightRow:(OGTKListBoxRow*)row
{
	gtk_list_box_drag_highlight_row([self LISTBOX], [row LISTBOXROW]);
}

- (void)dragUnhighlightRow
{
	gtk_list_box_drag_unhighlight_row([self LISTBOX]);
}

- (bool)activateOnSingleClick
{
	return gtk_list_box_get_activate_on_single_click([self LISTBOX]);
}

- (OGTKAdjustment*)adjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_list_box_get_adjustment([self LISTBOX])] autorelease];
}

- (OGTKListBoxRow*)rowAtIndex:(gint)index
{
	return [[[OGTKListBoxRow alloc] initWithGObject:(GObject*)gtk_list_box_get_row_at_index([self LISTBOX], index)] autorelease];
}

- (OGTKListBoxRow*)rowAtY:(gint)y
{
	return [[[OGTKListBoxRow alloc] initWithGObject:(GObject*)gtk_list_box_get_row_at_y([self LISTBOX], y)] autorelease];
}

- (OGTKListBoxRow*)selectedRow
{
	return [[[OGTKListBoxRow alloc] initWithGObject:(GObject*)gtk_list_box_get_selected_row([self LISTBOX])] autorelease];
}

- (GList*)selectedRows
{
	return gtk_list_box_get_selected_rows([self LISTBOX]);
}

- (GtkSelectionMode)selectionMode
{
	return gtk_list_box_get_selection_mode([self LISTBOX]);
}

- (void)insertWithChild:(OGTKWidget*)child position:(gint)position
{
	gtk_list_box_insert([self LISTBOX], [child WIDGET], position);
}

- (void)invalidateFilter
{
	gtk_list_box_invalidate_filter([self LISTBOX]);
}

- (void)invalidateHeaders
{
	gtk_list_box_invalidate_headers([self LISTBOX]);
}

- (void)invalidateSort
{
	gtk_list_box_invalidate_sort([self LISTBOX]);
}

- (void)prepend:(OGTKWidget*)child
{
	gtk_list_box_prepend([self LISTBOX], [child WIDGET]);
}

- (void)selectAll
{
	gtk_list_box_select_all([self LISTBOX]);
}

- (void)selectRow:(OGTKListBoxRow*)row
{
	gtk_list_box_select_row([self LISTBOX], [row LISTBOXROW]);
}

- (void)selectedForeachWithFunc:(GtkListBoxForeachFunc)func data:(gpointer)data
{
	gtk_list_box_selected_foreach([self LISTBOX], func, data);
}

- (void)setActivateOnSingleClick:(bool)single
{
	gtk_list_box_set_activate_on_single_click([self LISTBOX], single);
}

- (void)setAdjustment:(OGTKAdjustment*)adjustment
{
	gtk_list_box_set_adjustment([self LISTBOX], [adjustment ADJUSTMENT]);
}

- (void)setFilterFuncWithFilterFunc:(GtkListBoxFilterFunc)filterFunc userData:(gpointer)userData destroy:(GDestroyNotify)destroy
{
	gtk_list_box_set_filter_func([self LISTBOX], filterFunc, userData, destroy);
}

- (void)setHeaderFuncWithUpdateHeader:(GtkListBoxUpdateHeaderFunc)updateHeader userData:(gpointer)userData destroy:(GDestroyNotify)destroy
{
	gtk_list_box_set_header_func([self LISTBOX], updateHeader, userData, destroy);
}

- (void)setPlaceholder:(OGTKWidget*)placeholder
{
	gtk_list_box_set_placeholder([self LISTBOX], [placeholder WIDGET]);
}

- (void)setSelectionMode:(GtkSelectionMode)mode
{
	gtk_list_box_set_selection_mode([self LISTBOX], mode);
}

- (void)setSortFuncWithSortFunc:(GtkListBoxSortFunc)sortFunc userData:(gpointer)userData destroy:(GDestroyNotify)destroy
{
	gtk_list_box_set_sort_func([self LISTBOX], sortFunc, userData, destroy);
}

- (void)unselectAll
{
	gtk_list_box_unselect_all([self LISTBOX]);
}

- (void)unselectRow:(OGTKListBoxRow*)row
{
	gtk_list_box_unselect_row([self LISTBOX], [row LISTBOXROW]);
}


@end