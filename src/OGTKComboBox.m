/*
 * OGTKComboBox.m
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
#import "OGTKComboBox.h"

@implementation OGTKComboBox

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_new()];

	return self;
}

- (id)initWithArea:(GtkCellArea*)area
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_new_with_area(area)];

	return self;
}

- (id)initWithAreaAndEntry:(GtkCellArea*)area
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_new_with_area_and_entry(area)];

	return self;
}

- (id)initWithEntry
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_new_with_entry()];

	return self;
}

- (id)initWithModel:(GtkTreeModel*)model
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_new_with_model(model)];

	return self;
}

- (id)initWithModelAndEntry:(GtkTreeModel*)model
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_new_with_model_and_entry(model)];

	return self;
}

- (GtkComboBox*)COMBOBOX
{
	return GTK_COMBO_BOX([self GOBJECT]);
}

- (gint)getActive
{
	return gtk_combo_box_get_active(GTK_COMBO_BOX([self GOBJECT]));
}

- (OFString*)getActiveId
{
	return [OFString stringWithUTF8String:gtk_combo_box_get_active_id(GTK_COMBO_BOX([self GOBJECT]))];
}

- (bool)getActiveIter:(GtkTreeIter*)iter
{
	return gtk_combo_box_get_active_iter(GTK_COMBO_BOX([self GOBJECT]), iter);
}

- (bool)getAddTearoffs
{
	return gtk_combo_box_get_add_tearoffs(GTK_COMBO_BOX([self GOBJECT]));
}

- (GtkSensitivityType)getButtonSensitivity
{
	return gtk_combo_box_get_button_sensitivity(GTK_COMBO_BOX([self GOBJECT]));
}

- (gint)getColumnSpanColumn
{
	return gtk_combo_box_get_column_span_column(GTK_COMBO_BOX([self GOBJECT]));
}

- (gint)getEntryTextColumn
{
	return gtk_combo_box_get_entry_text_column(GTK_COMBO_BOX([self GOBJECT]));
}

- (bool)getFocusOnClick
{
	return gtk_combo_box_get_focus_on_click(GTK_COMBO_BOX([self GOBJECT]));
}

- (bool)getHasEntry
{
	return gtk_combo_box_get_has_entry(GTK_COMBO_BOX([self GOBJECT]));
}

- (gint)getIdColumn
{
	return gtk_combo_box_get_id_column(GTK_COMBO_BOX([self GOBJECT]));
}

- (GtkTreeModel*)getModel
{
	return gtk_combo_box_get_model(GTK_COMBO_BOX([self GOBJECT]));
}

- (AtkObject*)getPopupAccessible
{
	return gtk_combo_box_get_popup_accessible(GTK_COMBO_BOX([self GOBJECT]));
}

- (bool)getPopupFixedWidth
{
	return gtk_combo_box_get_popup_fixed_width(GTK_COMBO_BOX([self GOBJECT]));
}

- (GtkTreeViewRowSeparatorFunc)getRowSeparatorFunc
{
	return gtk_combo_box_get_row_separator_func(GTK_COMBO_BOX([self GOBJECT]));
}

- (gint)getRowSpanColumn
{
	return gtk_combo_box_get_row_span_column(GTK_COMBO_BOX([self GOBJECT]));
}

- (OFString*)getTitle
{
	return [OFString stringWithUTF8String:gtk_combo_box_get_title(GTK_COMBO_BOX([self GOBJECT]))];
}

- (gint)getWrapWidth
{
	return gtk_combo_box_get_wrap_width(GTK_COMBO_BOX([self GOBJECT]));
}

- (void)popdown
{
	gtk_combo_box_popdown(GTK_COMBO_BOX([self GOBJECT]));
}

- (void)popup
{
	gtk_combo_box_popup(GTK_COMBO_BOX([self GOBJECT]));
}

- (void)popupForDevice:(GdkDevice*)device
{
	gtk_combo_box_popup_for_device(GTK_COMBO_BOX([self GOBJECT]), device);
}

- (void)setActive:(gint)index
{
	gtk_combo_box_set_active(GTK_COMBO_BOX([self GOBJECT]), index);
}

- (bool)setActiveId:(OFString*)activeId
{
	return gtk_combo_box_set_active_id(GTK_COMBO_BOX([self GOBJECT]), [activeId UTF8String]);
}

- (void)setActiveIter:(GtkTreeIter*)iter
{
	gtk_combo_box_set_active_iter(GTK_COMBO_BOX([self GOBJECT]), iter);
}

- (void)setAddTearoffs:(bool)addTearoffs
{
	gtk_combo_box_set_add_tearoffs(GTK_COMBO_BOX([self GOBJECT]), addTearoffs);
}

- (void)setButtonSensitivity:(GtkSensitivityType)sensitivity
{
	gtk_combo_box_set_button_sensitivity(GTK_COMBO_BOX([self GOBJECT]), sensitivity);
}

- (void)setColumnSpanColumn:(gint)columnSpan
{
	gtk_combo_box_set_column_span_column(GTK_COMBO_BOX([self GOBJECT]), columnSpan);
}

- (void)setEntryTextColumn:(gint)textColumn
{
	gtk_combo_box_set_entry_text_column(GTK_COMBO_BOX([self GOBJECT]), textColumn);
}

- (void)setFocusOnClick:(bool)focusOnClick
{
	gtk_combo_box_set_focus_on_click(GTK_COMBO_BOX([self GOBJECT]), focusOnClick);
}

- (void)setIdColumn:(gint)idColumn
{
	gtk_combo_box_set_id_column(GTK_COMBO_BOX([self GOBJECT]), idColumn);
}

- (void)setModel:(GtkTreeModel*)model
{
	gtk_combo_box_set_model(GTK_COMBO_BOX([self GOBJECT]), model);
}

- (void)setPopupFixedWidth:(bool)fixed
{
	gtk_combo_box_set_popup_fixed_width(GTK_COMBO_BOX([self GOBJECT]), fixed);
}

- (void)setRowSeparatorFuncWithFunc:(GtkTreeViewRowSeparatorFunc)func andData:(gpointer)data andDestroy:(GDestroyNotify)destroy
{
	gtk_combo_box_set_row_separator_func(GTK_COMBO_BOX([self GOBJECT]), func, data, destroy);
}

- (void)setRowSpanColumn:(gint)rowSpan
{
	gtk_combo_box_set_row_span_column(GTK_COMBO_BOX([self GOBJECT]), rowSpan);
}

- (void)setTitle:(OFString*)title
{
	gtk_combo_box_set_title(GTK_COMBO_BOX([self GOBJECT]), [title UTF8String]);
}

- (void)setWrapWidth:(gint)width
{
	gtk_combo_box_set_wrap_width(GTK_COMBO_BOX([self GOBJECT]), width);
}


@end