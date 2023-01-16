/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellArea.h"

#import "OGTKWidget.h"
#import "OGTKCellRenderer.h"
#import "OGTKCellAreaContext.h"

@implementation OGTKCellArea

- (GtkCellArea*)CELLAREA
{
	return GTK_CELL_AREA([self GOBJECT]);
}

- (bool)activateWithContext:(OGTKCellAreaContext*)context widget:(OGTKWidget*)widget cellArea:(const GdkRectangle*)cellArea flags:(GtkCellRendererState)flags editOnly:(bool)editOnly
{
	return gtk_cell_area_activate([self CELLAREA], [context CELLAREACONTEXT], [widget WIDGET], cellArea, flags, editOnly);
}

- (bool)activateCellWithWidget:(OGTKWidget*)widget renderer:(OGTKCellRenderer*)renderer event:(GdkEvent*)event cellArea:(const GdkRectangle*)cellArea flags:(GtkCellRendererState)flags
{
	return gtk_cell_area_activate_cell([self CELLAREA], [widget WIDGET], [renderer CELLRENDERER], event, cellArea, flags);
}

- (void)add:(OGTKCellRenderer*)renderer
{
	gtk_cell_area_add([self CELLAREA], [renderer CELLRENDERER]);
}

- (void)addFocusSiblingWithRenderer:(OGTKCellRenderer*)renderer sibling:(OGTKCellRenderer*)sibling
{
	gtk_cell_area_add_focus_sibling([self CELLAREA], [renderer CELLRENDERER], [sibling CELLRENDERER]);
}

- (void)applyAttributesWithTreeModel:(GtkTreeModel*)treeModel iter:(GtkTreeIter*)iter isExpander:(bool)isExpander isExpanded:(bool)isExpanded
{
	gtk_cell_area_apply_attributes([self CELLAREA], treeModel, iter, isExpander, isExpanded);
}

- (void)attributeConnectWithRenderer:(OGTKCellRenderer*)renderer attribute:(OFString*)attribute column:(gint)column
{
	gtk_cell_area_attribute_connect([self CELLAREA], [renderer CELLRENDERER], [attribute UTF8String], column);
}

- (void)attributeDisconnectWithRenderer:(OGTKCellRenderer*)renderer attribute:(OFString*)attribute
{
	gtk_cell_area_attribute_disconnect([self CELLAREA], [renderer CELLRENDERER], [attribute UTF8String]);
}

- (gint)attributeGetColumnWithRenderer:(OGTKCellRenderer*)renderer attribute:(OFString*)attribute
{
	return gtk_cell_area_attribute_get_column([self CELLAREA], [renderer CELLRENDERER], [attribute UTF8String]);
}

- (void)cellGetPropertyWithRenderer:(OGTKCellRenderer*)renderer propertyName:(OFString*)propertyName value:(GValue*)value
{
	gtk_cell_area_cell_get_property([self CELLAREA], [renderer CELLRENDERER], [propertyName UTF8String], value);
}

- (void)cellGetValistWithRenderer:(OGTKCellRenderer*)renderer firstPropertyName:(OFString*)firstPropertyName varArgs:(va_list)varArgs
{
	gtk_cell_area_cell_get_valist([self CELLAREA], [renderer CELLRENDERER], [firstPropertyName UTF8String], varArgs);
}

- (void)cellSetPropertyWithRenderer:(OGTKCellRenderer*)renderer propertyName:(OFString*)propertyName value:(const GValue*)value
{
	gtk_cell_area_cell_set_property([self CELLAREA], [renderer CELLRENDERER], [propertyName UTF8String], value);
}

- (void)cellSetValistWithRenderer:(OGTKCellRenderer*)renderer firstPropertyName:(OFString*)firstPropertyName varArgs:(va_list)varArgs
{
	gtk_cell_area_cell_set_valist([self CELLAREA], [renderer CELLRENDERER], [firstPropertyName UTF8String], varArgs);
}

- (OGTKCellAreaContext*)copyContext:(OGTKCellAreaContext*)context
{
	return [[[OGTKCellAreaContext alloc] initWithGObject:(GObject*)gtk_cell_area_copy_context([self CELLAREA], [context CELLAREACONTEXT])] autorelease];
}

- (OGTKCellAreaContext*)createContext
{
	return [[[OGTKCellAreaContext alloc] initWithGObject:(GObject*)gtk_cell_area_create_context([self CELLAREA])] autorelease];
}

- (gint)eventWithContext:(OGTKCellAreaContext*)context widget:(OGTKWidget*)widget event:(GdkEvent*)event cellArea:(const GdkRectangle*)cellArea flags:(GtkCellRendererState)flags
{
	return gtk_cell_area_event([self CELLAREA], [context CELLAREACONTEXT], [widget WIDGET], event, cellArea, flags);
}

- (bool)focus:(GtkDirectionType)direction
{
	return gtk_cell_area_focus([self CELLAREA], direction);
}

- (void)foreachWithCallback:(GtkCellCallback)callback callbackData:(gpointer)callbackData
{
	gtk_cell_area_foreach([self CELLAREA], callback, callbackData);
}

- (void)foreachAllocWithContext:(OGTKCellAreaContext*)context widget:(OGTKWidget*)widget cellArea:(const GdkRectangle*)cellArea backgroundArea:(const GdkRectangle*)backgroundArea callback:(GtkCellAllocCallback)callback callbackData:(gpointer)callbackData
{
	gtk_cell_area_foreach_alloc([self CELLAREA], [context CELLAREACONTEXT], [widget WIDGET], cellArea, backgroundArea, callback, callbackData);
}

- (void)cellAllocationWithContext:(OGTKCellAreaContext*)context widget:(OGTKWidget*)widget renderer:(OGTKCellRenderer*)renderer cellArea:(const GdkRectangle*)cellArea allocation:(GdkRectangle*)allocation
{
	gtk_cell_area_get_cell_allocation([self CELLAREA], [context CELLAREACONTEXT], [widget WIDGET], [renderer CELLRENDERER], cellArea, allocation);
}

- (OGTKCellRenderer*)cellAtPositionWithContext:(OGTKCellAreaContext*)context widget:(OGTKWidget*)widget cellArea:(const GdkRectangle*)cellArea x:(gint)x y:(gint)y allocArea:(GdkRectangle*)allocArea
{
	return [[[OGTKCellRenderer alloc] initWithGObject:(GObject*)gtk_cell_area_get_cell_at_position([self CELLAREA], [context CELLAREACONTEXT], [widget WIDGET], cellArea, x, y, allocArea)] autorelease];
}

- (OFString*)currentPathString
{
	return [OFString stringWithUTF8String:gtk_cell_area_get_current_path_string([self CELLAREA])];
}

- (GtkCellEditable*)editWidget
{
	return gtk_cell_area_get_edit_widget([self CELLAREA]);
}

- (OGTKCellRenderer*)editedCell
{
	return [[[OGTKCellRenderer alloc] initWithGObject:(GObject*)gtk_cell_area_get_edited_cell([self CELLAREA])] autorelease];
}

- (OGTKCellRenderer*)focusCell
{
	return [[[OGTKCellRenderer alloc] initWithGObject:(GObject*)gtk_cell_area_get_focus_cell([self CELLAREA])] autorelease];
}

- (OGTKCellRenderer*)focusFromSibling:(OGTKCellRenderer*)renderer
{
	return [[[OGTKCellRenderer alloc] initWithGObject:(GObject*)gtk_cell_area_get_focus_from_sibling([self CELLAREA], [renderer CELLRENDERER])] autorelease];
}

- (const GList*)focusSiblings:(OGTKCellRenderer*)renderer
{
	return gtk_cell_area_get_focus_siblings([self CELLAREA], [renderer CELLRENDERER]);
}

- (void)preferredHeightWithContext:(OGTKCellAreaContext*)context widget:(OGTKWidget*)widget minimumHeight:(gint*)minimumHeight naturalHeight:(gint*)naturalHeight
{
	gtk_cell_area_get_preferred_height([self CELLAREA], [context CELLAREACONTEXT], [widget WIDGET], minimumHeight, naturalHeight);
}

- (void)preferredHeightForWidthWithContext:(OGTKCellAreaContext*)context widget:(OGTKWidget*)widget width:(gint)width minimumHeight:(gint*)minimumHeight naturalHeight:(gint*)naturalHeight
{
	gtk_cell_area_get_preferred_height_for_width([self CELLAREA], [context CELLAREACONTEXT], [widget WIDGET], width, minimumHeight, naturalHeight);
}

- (void)preferredWidthWithContext:(OGTKCellAreaContext*)context widget:(OGTKWidget*)widget minimumWidth:(gint*)minimumWidth naturalWidth:(gint*)naturalWidth
{
	gtk_cell_area_get_preferred_width([self CELLAREA], [context CELLAREACONTEXT], [widget WIDGET], minimumWidth, naturalWidth);
}

- (void)preferredWidthForHeightWithContext:(OGTKCellAreaContext*)context widget:(OGTKWidget*)widget height:(gint)height minimumWidth:(gint*)minimumWidth naturalWidth:(gint*)naturalWidth
{
	gtk_cell_area_get_preferred_width_for_height([self CELLAREA], [context CELLAREACONTEXT], [widget WIDGET], height, minimumWidth, naturalWidth);
}

- (GtkSizeRequestMode)requestMode
{
	return gtk_cell_area_get_request_mode([self CELLAREA]);
}

- (bool)hasRenderer:(OGTKCellRenderer*)renderer
{
	return gtk_cell_area_has_renderer([self CELLAREA], [renderer CELLRENDERER]);
}

- (void)innerCellAreaWithWidget:(OGTKWidget*)widget cellArea:(const GdkRectangle*)cellArea innerArea:(GdkRectangle*)innerArea
{
	gtk_cell_area_inner_cell_area([self CELLAREA], [widget WIDGET], cellArea, innerArea);
}

- (bool)isActivatable
{
	return gtk_cell_area_is_activatable([self CELLAREA]);
}

- (bool)isFocusSiblingWithRenderer:(OGTKCellRenderer*)renderer sibling:(OGTKCellRenderer*)sibling
{
	return gtk_cell_area_is_focus_sibling([self CELLAREA], [renderer CELLRENDERER], [sibling CELLRENDERER]);
}

- (void)remove:(OGTKCellRenderer*)renderer
{
	gtk_cell_area_remove([self CELLAREA], [renderer CELLRENDERER]);
}

- (void)removeFocusSiblingWithRenderer:(OGTKCellRenderer*)renderer sibling:(OGTKCellRenderer*)sibling
{
	gtk_cell_area_remove_focus_sibling([self CELLAREA], [renderer CELLRENDERER], [sibling CELLRENDERER]);
}

- (void)renderWithContext:(OGTKCellAreaContext*)context widget:(OGTKWidget*)widget cr:(cairo_t*)cr backgroundArea:(const GdkRectangle*)backgroundArea cellArea:(const GdkRectangle*)cellArea flags:(GtkCellRendererState)flags paintFocus:(bool)paintFocus
{
	gtk_cell_area_render([self CELLAREA], [context CELLAREACONTEXT], [widget WIDGET], cr, backgroundArea, cellArea, flags, paintFocus);
}

- (void)requestRendererWithRenderer:(OGTKCellRenderer*)renderer orientation:(GtkOrientation)orientation widget:(OGTKWidget*)widget forSize:(gint)forSize minimumSize:(gint*)minimumSize naturalSize:(gint*)naturalSize
{
	gtk_cell_area_request_renderer([self CELLAREA], [renderer CELLRENDERER], orientation, [widget WIDGET], forSize, minimumSize, naturalSize);
}

- (void)setFocusCell:(OGTKCellRenderer*)renderer
{
	gtk_cell_area_set_focus_cell([self CELLAREA], [renderer CELLRENDERER]);
}

- (void)stopEditing:(bool)canceled
{
	gtk_cell_area_stop_editing([self CELLAREA], canceled);
}


@end