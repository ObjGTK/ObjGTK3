/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFlowBox.h"

#import "OGTKAdjustment.h"
#import "OGTKFlowBoxChild.h"
#import "OGTKWidget.h"

@implementation OGTKFlowBox

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_flow_box_new()];

	return self;
}

- (GtkFlowBox*)FLOWBOX
{
	return GTK_FLOW_BOX([self GOBJECT]);
}

- (void)bindModelWithModel:(GListModel*)model createWidgetFunc:(GtkFlowBoxCreateWidgetFunc)createWidgetFunc userData:(gpointer)userData userDataFreeFunc:(GDestroyNotify)userDataFreeFunc
{
	gtk_flow_box_bind_model([self FLOWBOX], model, createWidgetFunc, userData, userDataFreeFunc);
}

- (bool)activateOnSingleClick
{
	return gtk_flow_box_get_activate_on_single_click([self FLOWBOX]);
}

- (OGTKFlowBoxChild*)childAtIndex:(gint)idx
{
	return [[[OGTKFlowBoxChild alloc] initWithGObject:(GObject*)gtk_flow_box_get_child_at_index([self FLOWBOX], idx)] autorelease];
}

- (OGTKFlowBoxChild*)childAtPosWithX:(gint)x y:(gint)y
{
	return [[[OGTKFlowBoxChild alloc] initWithGObject:(GObject*)gtk_flow_box_get_child_at_pos([self FLOWBOX], x, y)] autorelease];
}

- (guint)columnSpacing
{
	return gtk_flow_box_get_column_spacing([self FLOWBOX]);
}

- (bool)homogeneous
{
	return gtk_flow_box_get_homogeneous([self FLOWBOX]);
}

- (guint)maxChildrenPerLine
{
	return gtk_flow_box_get_max_children_per_line([self FLOWBOX]);
}

- (guint)minChildrenPerLine
{
	return gtk_flow_box_get_min_children_per_line([self FLOWBOX]);
}

- (guint)rowSpacing
{
	return gtk_flow_box_get_row_spacing([self FLOWBOX]);
}

- (GList*)selectedChildren
{
	return gtk_flow_box_get_selected_children([self FLOWBOX]);
}

- (GtkSelectionMode)selectionMode
{
	return gtk_flow_box_get_selection_mode([self FLOWBOX]);
}

- (void)insertWithWidget:(OGTKWidget*)widget position:(gint)position
{
	gtk_flow_box_insert([self FLOWBOX], [widget WIDGET], position);
}

- (void)invalidateFilter
{
	gtk_flow_box_invalidate_filter([self FLOWBOX]);
}

- (void)invalidateSort
{
	gtk_flow_box_invalidate_sort([self FLOWBOX]);
}

- (void)selectAll
{
	gtk_flow_box_select_all([self FLOWBOX]);
}

- (void)selectChild:(OGTKFlowBoxChild*)child
{
	gtk_flow_box_select_child([self FLOWBOX], [child FLOWBOXCHILD]);
}

- (void)selectedForeachWithFunc:(GtkFlowBoxForeachFunc)func data:(gpointer)data
{
	gtk_flow_box_selected_foreach([self FLOWBOX], func, data);
}

- (void)setActivateOnSingleClick:(bool)single
{
	gtk_flow_box_set_activate_on_single_click([self FLOWBOX], single);
}

- (void)setColumnSpacing:(guint)spacing
{
	gtk_flow_box_set_column_spacing([self FLOWBOX], spacing);
}

- (void)setFilterFuncWithFilterFunc:(GtkFlowBoxFilterFunc)filterFunc userData:(gpointer)userData destroy:(GDestroyNotify)destroy
{
	gtk_flow_box_set_filter_func([self FLOWBOX], filterFunc, userData, destroy);
}

- (void)setHadjustment:(OGTKAdjustment*)adjustment
{
	gtk_flow_box_set_hadjustment([self FLOWBOX], [adjustment ADJUSTMENT]);
}

- (void)setHomogeneous:(bool)homogeneous
{
	gtk_flow_box_set_homogeneous([self FLOWBOX], homogeneous);
}

- (void)setMaxChildrenPerLine:(guint)nchildren
{
	gtk_flow_box_set_max_children_per_line([self FLOWBOX], nchildren);
}

- (void)setMinChildrenPerLine:(guint)nchildren
{
	gtk_flow_box_set_min_children_per_line([self FLOWBOX], nchildren);
}

- (void)setRowSpacing:(guint)spacing
{
	gtk_flow_box_set_row_spacing([self FLOWBOX], spacing);
}

- (void)setSelectionMode:(GtkSelectionMode)mode
{
	gtk_flow_box_set_selection_mode([self FLOWBOX], mode);
}

- (void)setSortFuncWithSortFunc:(GtkFlowBoxSortFunc)sortFunc userData:(gpointer)userData destroy:(GDestroyNotify)destroy
{
	gtk_flow_box_set_sort_func([self FLOWBOX], sortFunc, userData, destroy);
}

- (void)setVadjustment:(OGTKAdjustment*)adjustment
{
	gtk_flow_box_set_vadjustment([self FLOWBOX], [adjustment ADJUSTMENT]);
}

- (void)unselectAll
{
	gtk_flow_box_unselect_all([self FLOWBOX]);
}

- (void)unselectChild:(OGTKFlowBoxChild*)child
{
	gtk_flow_box_unselect_child([self FLOWBOX], [child FLOWBOXCHILD]);
}


@end