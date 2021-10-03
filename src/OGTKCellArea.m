/*
 * OGTKCellArea.m
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
#import "OGTKCellArea.h"

@implementation OGTKCellArea

- (GtkCellArea*)CELLAREA
{
	return GTK_CELL_AREA([self GOBJECT]);
}

- (bool)activateWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags andEditOnly:(bool)editOnly
{
	return gtk_cell_area_activate(GTK_CELL_AREA([self GOBJECT]), context, [widget WIDGET], cellArea, flags, editOnly);
}

- (bool)activateCellWithWidget:(OGTKWidget*)widget andRenderer:(GtkCellRenderer*)renderer andEvent:(GdkEvent*)event andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags
{
	return gtk_cell_area_activate_cell(GTK_CELL_AREA([self GOBJECT]), [widget WIDGET], renderer, event, cellArea, flags);
}

- (void)add:(GtkCellRenderer*)renderer
{
	gtk_cell_area_add(GTK_CELL_AREA([self GOBJECT]), renderer);
}

- (void)addFocusSiblingWithRenderer:(GtkCellRenderer*)renderer andSibling:(GtkCellRenderer*)sibling
{
	gtk_cell_area_add_focus_sibling(GTK_CELL_AREA([self GOBJECT]), renderer, sibling);
}

- (void)applyAttributesWithTreeModel:(GtkTreeModel*)treeModel andIter:(GtkTreeIter*)iter andIsExpander:(bool)isExpander andIsExpanded:(bool)isExpanded
{
	gtk_cell_area_apply_attributes(GTK_CELL_AREA([self GOBJECT]), treeModel, iter, isExpander, isExpanded);
}

- (void)attributeConnectWithRenderer:(GtkCellRenderer*)renderer andAttribute:(OFString*)attribute andColumn:(gint)column
{
	gtk_cell_area_attribute_connect(GTK_CELL_AREA([self GOBJECT]), renderer, [attribute UTF8String], column);
}

- (void)attributeDisconnectWithRenderer:(GtkCellRenderer*)renderer andAttribute:(OFString*)attribute
{
	gtk_cell_area_attribute_disconnect(GTK_CELL_AREA([self GOBJECT]), renderer, [attribute UTF8String]);
}

- (gint)attributeGetColumnWithRenderer:(GtkCellRenderer*)renderer andAttribute:(OFString*)attribute
{
	return gtk_cell_area_attribute_get_column(GTK_CELL_AREA([self GOBJECT]), renderer, [attribute UTF8String]);
}

- (void)cellGetPropertyWithRenderer:(GtkCellRenderer*)renderer andPropertyName:(OFString*)propertyName andValue:(GValue*)value
{
	gtk_cell_area_cell_get_property(GTK_CELL_AREA([self GOBJECT]), renderer, [propertyName UTF8String], value);
}

- (void)cellGetValistWithRenderer:(GtkCellRenderer*)renderer andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs
{
	gtk_cell_area_cell_get_valist(GTK_CELL_AREA([self GOBJECT]), renderer, [firstPropertyName UTF8String], varArgs);
}

- (void)cellSetPropertyWithRenderer:(GtkCellRenderer*)renderer andPropertyName:(OFString*)propertyName andValue:(const GValue*)value
{
	gtk_cell_area_cell_set_property(GTK_CELL_AREA([self GOBJECT]), renderer, [propertyName UTF8String], value);
}

- (void)cellSetValistWithRenderer:(GtkCellRenderer*)renderer andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs
{
	gtk_cell_area_cell_set_valist(GTK_CELL_AREA([self GOBJECT]), renderer, [firstPropertyName UTF8String], varArgs);
}

- (GtkCellAreaContext*)copyContext:(GtkCellAreaContext*)context
{
	return gtk_cell_area_copy_context(GTK_CELL_AREA([self GOBJECT]), context);
}

- (GtkCellAreaContext*)createContext
{
	return gtk_cell_area_create_context(GTK_CELL_AREA([self GOBJECT]));
}

- (gint)eventWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andEvent:(GdkEvent*)event andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags
{
	return gtk_cell_area_event(GTK_CELL_AREA([self GOBJECT]), context, [widget WIDGET], event, cellArea, flags);
}

- (bool)focus:(GtkDirectionType)direction
{
	return gtk_cell_area_focus(GTK_CELL_AREA([self GOBJECT]), direction);
}

- (void)foreachWithCallback:(GtkCellCallback)callback andCallbackData:(gpointer)callbackData
{
	gtk_cell_area_foreach(GTK_CELL_AREA([self GOBJECT]), callback, callbackData);
}

- (void)foreachAllocWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andBackgroundArea:(const GdkRectangle*)backgroundArea andCallback:(GtkCellAllocCallback)callback andCallbackData:(gpointer)callbackData
{
	gtk_cell_area_foreach_alloc(GTK_CELL_AREA([self GOBJECT]), context, [widget WIDGET], cellArea, backgroundArea, callback, callbackData);
}

- (void)getCellAllocationWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andRenderer:(GtkCellRenderer*)renderer andCellArea:(const GdkRectangle*)cellArea andAllocation:(GdkRectangle*)allocation
{
	gtk_cell_area_get_cell_allocation(GTK_CELL_AREA([self GOBJECT]), context, [widget WIDGET], renderer, cellArea, allocation);
}

- (GtkCellRenderer*)getCellAtPositionWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andX:(gint)x andY:(gint)y andAllocArea:(GdkRectangle*)allocArea
{
	return gtk_cell_area_get_cell_at_position(GTK_CELL_AREA([self GOBJECT]), context, [widget WIDGET], cellArea, x, y, allocArea);
}

- (OFString*)getCurrentPathString
{
	return [OFString stringWithUTF8String:gtk_cell_area_get_current_path_string(GTK_CELL_AREA([self GOBJECT]))];
}

- (GtkCellEditable*)getEditWidget
{
	return gtk_cell_area_get_edit_widget(GTK_CELL_AREA([self GOBJECT]));
}

- (GtkCellRenderer*)getEditedCell
{
	return gtk_cell_area_get_edited_cell(GTK_CELL_AREA([self GOBJECT]));
}

- (GtkCellRenderer*)getFocusCell
{
	return gtk_cell_area_get_focus_cell(GTK_CELL_AREA([self GOBJECT]));
}

- (GtkCellRenderer*)getFocusFromSibling:(GtkCellRenderer*)renderer
{
	return gtk_cell_area_get_focus_from_sibling(GTK_CELL_AREA([self GOBJECT]), renderer);
}

- (const GList*)getFocusSiblings:(GtkCellRenderer*)renderer
{
	return gtk_cell_area_get_focus_siblings(GTK_CELL_AREA([self GOBJECT]), renderer);
}

- (void)getPreferredHeightWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight
{
	gtk_cell_area_get_preferred_height(GTK_CELL_AREA([self GOBJECT]), context, [widget WIDGET], minimumHeight, naturalHeight);
}

- (void)getPreferredHeightForWidthWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andWidth:(gint)width andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight
{
	gtk_cell_area_get_preferred_height_for_width(GTK_CELL_AREA([self GOBJECT]), context, [widget WIDGET], width, minimumHeight, naturalHeight);
}

- (void)getPreferredWidthWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth
{
	gtk_cell_area_get_preferred_width(GTK_CELL_AREA([self GOBJECT]), context, [widget WIDGET], minimumWidth, naturalWidth);
}

- (void)getPreferredWidthForHeightWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andHeight:(gint)height andMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth
{
	gtk_cell_area_get_preferred_width_for_height(GTK_CELL_AREA([self GOBJECT]), context, [widget WIDGET], height, minimumWidth, naturalWidth);
}

- (GtkSizeRequestMode)getRequestMode
{
	return gtk_cell_area_get_request_mode(GTK_CELL_AREA([self GOBJECT]));
}

- (bool)hasRenderer:(GtkCellRenderer*)renderer
{
	return gtk_cell_area_has_renderer(GTK_CELL_AREA([self GOBJECT]), renderer);
}

- (void)innerCellAreaWithWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andInnerArea:(GdkRectangle*)innerArea
{
	gtk_cell_area_inner_cell_area(GTK_CELL_AREA([self GOBJECT]), [widget WIDGET], cellArea, innerArea);
}

- (bool)isActivatable
{
	return gtk_cell_area_is_activatable(GTK_CELL_AREA([self GOBJECT]));
}

- (bool)isFocusSiblingWithRenderer:(GtkCellRenderer*)renderer andSibling:(GtkCellRenderer*)sibling
{
	return gtk_cell_area_is_focus_sibling(GTK_CELL_AREA([self GOBJECT]), renderer, sibling);
}

- (void)remove:(GtkCellRenderer*)renderer
{
	gtk_cell_area_remove(GTK_CELL_AREA([self GOBJECT]), renderer);
}

- (void)removeFocusSiblingWithRenderer:(GtkCellRenderer*)renderer andSibling:(GtkCellRenderer*)sibling
{
	gtk_cell_area_remove_focus_sibling(GTK_CELL_AREA([self GOBJECT]), renderer, sibling);
}

- (void)renderWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andCr:(cairo_t*)cr andBackgroundArea:(const GdkRectangle*)backgroundArea andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags andPaintFocus:(bool)paintFocus
{
	gtk_cell_area_render(GTK_CELL_AREA([self GOBJECT]), context, [widget WIDGET], cr, backgroundArea, cellArea, flags, paintFocus);
}

- (void)requestRendererWithRenderer:(GtkCellRenderer*)renderer andOrientation:(GtkOrientation)orientation andWidget:(OGTKWidget*)widget andForSize:(gint)forSize andMinimumSize:(gint*)minimumSize andNaturalSize:(gint*)naturalSize
{
	gtk_cell_area_request_renderer(GTK_CELL_AREA([self GOBJECT]), renderer, orientation, [widget WIDGET], forSize, minimumSize, naturalSize);
}

- (void)setFocusCell:(GtkCellRenderer*)renderer
{
	gtk_cell_area_set_focus_cell(GTK_CELL_AREA([self GOBJECT]), renderer);
}

- (void)stopEditing:(bool)canceled
{
	gtk_cell_area_stop_editing(GTK_CELL_AREA([self GOBJECT]), canceled);
}


@end