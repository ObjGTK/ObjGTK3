/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKComboBox.h"

#import <OGdk3/OGGdkDevice.h>
#import "OGTKWidget.h"
#import <OGAtk/OGAtkObject.h>
#import "OGTKCellArea.h"

@implementation OGTKComboBox

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_new()];

	return self;
}

- (instancetype)initWithArea:(OGTKCellArea*)area
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_new_with_area([area CELLAREA])];

	return self;
}

- (instancetype)initWithAreaAndEntry:(OGTKCellArea*)area
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_new_with_area_and_entry([area CELLAREA])];

	return self;
}

- (instancetype)initWithEntry
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_new_with_entry()];

	return self;
}

- (instancetype)initWithModel:(GtkTreeModel*)model
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_new_with_model(model)];

	return self;
}

- (instancetype)initWithModelAndEntry:(GtkTreeModel*)model
{
	self = [super initWithGObject:(GObject*)gtk_combo_box_new_with_model_and_entry(model)];

	return self;
}

- (GtkComboBox*)COMBOBOX
{
	return GTK_COMBO_BOX([self GOBJECT]);
}

- (gint)active
{
	return gtk_combo_box_get_active([self COMBOBOX]);
}

- (OFString*)activeId
{
	return [OFString stringWithUTF8String:gtk_combo_box_get_active_id([self COMBOBOX])];
}

- (bool)activeIter:(GtkTreeIter*)iter
{
	return gtk_combo_box_get_active_iter([self COMBOBOX], iter);
}

- (bool)addTearoffs
{
	return gtk_combo_box_get_add_tearoffs([self COMBOBOX]);
}

- (GtkSensitivityType)buttonSensitivity
{
	return gtk_combo_box_get_button_sensitivity([self COMBOBOX]);
}

- (gint)columnSpanColumn
{
	return gtk_combo_box_get_column_span_column([self COMBOBOX]);
}

- (gint)entryTextColumn
{
	return gtk_combo_box_get_entry_text_column([self COMBOBOX]);
}

- (bool)focusOnClick
{
	return gtk_combo_box_get_focus_on_click([self COMBOBOX]);
}

- (bool)hasEntry
{
	return gtk_combo_box_get_has_entry([self COMBOBOX]);
}

- (gint)idColumn
{
	return gtk_combo_box_get_id_column([self COMBOBOX]);
}

- (GtkTreeModel*)model
{
	return gtk_combo_box_get_model([self COMBOBOX]);
}

- (OGAtkObject*)popupAccessible
{
	return [[[OGAtkObject alloc] initWithGObject:(GObject*)gtk_combo_box_get_popup_accessible([self COMBOBOX])] autorelease];
}

- (bool)popupFixedWidth
{
	return gtk_combo_box_get_popup_fixed_width([self COMBOBOX]);
}

- (GtkTreeViewRowSeparatorFunc)rowSeparatorFunc
{
	return gtk_combo_box_get_row_separator_func([self COMBOBOX]);
}

- (gint)rowSpanColumn
{
	return gtk_combo_box_get_row_span_column([self COMBOBOX]);
}

- (OFString*)title
{
	return [OFString stringWithUTF8String:gtk_combo_box_get_title([self COMBOBOX])];
}

- (gint)wrapWidth
{
	return gtk_combo_box_get_wrap_width([self COMBOBOX]);
}

- (void)popdown
{
	gtk_combo_box_popdown([self COMBOBOX]);
}

- (void)popup
{
	gtk_combo_box_popup([self COMBOBOX]);
}

- (void)popupForDevice:(OGGdkDevice*)device
{
	gtk_combo_box_popup_for_device([self COMBOBOX], [device DEVICE]);
}

- (void)setActive:(gint)index
{
	gtk_combo_box_set_active([self COMBOBOX], index);
}

- (bool)setActiveId:(OFString*)activeId
{
	return gtk_combo_box_set_active_id([self COMBOBOX], [activeId UTF8String]);
}

- (void)setActiveIter:(GtkTreeIter*)iter
{
	gtk_combo_box_set_active_iter([self COMBOBOX], iter);
}

- (void)setAddTearoffs:(bool)addTearoffs
{
	gtk_combo_box_set_add_tearoffs([self COMBOBOX], addTearoffs);
}

- (void)setButtonSensitivity:(GtkSensitivityType)sensitivity
{
	gtk_combo_box_set_button_sensitivity([self COMBOBOX], sensitivity);
}

- (void)setColumnSpanColumn:(gint)columnSpan
{
	gtk_combo_box_set_column_span_column([self COMBOBOX], columnSpan);
}

- (void)setEntryTextColumn:(gint)textColumn
{
	gtk_combo_box_set_entry_text_column([self COMBOBOX], textColumn);
}

- (void)setFocusOnClick:(bool)focusOnClick
{
	gtk_combo_box_set_focus_on_click([self COMBOBOX], focusOnClick);
}

- (void)setIdColumn:(gint)idColumn
{
	gtk_combo_box_set_id_column([self COMBOBOX], idColumn);
}

- (void)setModel:(GtkTreeModel*)model
{
	gtk_combo_box_set_model([self COMBOBOX], model);
}

- (void)setPopupFixedWidth:(bool)fixed
{
	gtk_combo_box_set_popup_fixed_width([self COMBOBOX], fixed);
}

- (void)setRowSeparatorFuncWithFunc:(GtkTreeViewRowSeparatorFunc)func data:(gpointer)data destroy:(GDestroyNotify)destroy
{
	gtk_combo_box_set_row_separator_func([self COMBOBOX], func, data, destroy);
}

- (void)setRowSpanColumn:(gint)rowSpan
{
	gtk_combo_box_set_row_span_column([self COMBOBOX], rowSpan);
}

- (void)setTitle:(OFString*)title
{
	gtk_combo_box_set_title([self COMBOBOX], [title UTF8String]);
}

- (void)setWrapWidth:(gint)width
{
	gtk_combo_box_set_wrap_width([self COMBOBOX], width);
}


@end