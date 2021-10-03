/*
 * OGTKCellArea.h
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

@interface OGTKCellArea : OGTKBase
{

}


/**
 * Methods
 */

- (GtkCellArea*)CELLAREA;

/**
 * - (bool*)activateWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags andEditOnly:(bool)editOnly;
 *
 * @param context
 * @param widget
 * @param cellArea
 * @param flags
 * @param editOnly
 * @returns bool
 */
- (bool)activateWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags andEditOnly:(bool)editOnly;

/**
 * - (bool*)activateCellWithWidget:(OGTKWidget*)widget andRenderer:(GtkCellRenderer*)renderer andEvent:(GdkEvent*)event andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags;
 *
 * @param widget
 * @param renderer
 * @param event
 * @param cellArea
 * @param flags
 * @returns bool
 */
- (bool)activateCellWithWidget:(OGTKWidget*)widget andRenderer:(GtkCellRenderer*)renderer andEvent:(GdkEvent*)event andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags;

/**
 * - (void*)add:(GtkCellRenderer*)renderer;
 *
 * @param renderer
 */
- (void)add:(GtkCellRenderer*)renderer;

/**
 * - (void*)addFocusSiblingWithRenderer:(GtkCellRenderer*)renderer andSibling:(GtkCellRenderer*)sibling;
 *
 * @param renderer
 * @param sibling
 */
- (void)addFocusSiblingWithRenderer:(GtkCellRenderer*)renderer andSibling:(GtkCellRenderer*)sibling;

/**
 * - (void*)applyAttributesWithTreeModel:(GtkTreeModel*)treeModel andIter:(GtkTreeIter*)iter andIsExpander:(bool)isExpander andIsExpanded:(bool)isExpanded;
 *
 * @param treeModel
 * @param iter
 * @param isExpander
 * @param isExpanded
 */
- (void)applyAttributesWithTreeModel:(GtkTreeModel*)treeModel andIter:(GtkTreeIter*)iter andIsExpander:(bool)isExpander andIsExpanded:(bool)isExpanded;

/**
 * - (void*)attributeConnectWithRenderer:(GtkCellRenderer*)renderer andAttribute:(OFString*)attribute andColumn:(gint)column;
 *
 * @param renderer
 * @param attribute
 * @param column
 */
- (void)attributeConnectWithRenderer:(GtkCellRenderer*)renderer andAttribute:(OFString*)attribute andColumn:(gint)column;

/**
 * - (void*)attributeDisconnectWithRenderer:(GtkCellRenderer*)renderer andAttribute:(OFString*)attribute;
 *
 * @param renderer
 * @param attribute
 */
- (void)attributeDisconnectWithRenderer:(GtkCellRenderer*)renderer andAttribute:(OFString*)attribute;

/**
 * - (gint*)attributeGetColumnWithRenderer:(GtkCellRenderer*)renderer andAttribute:(OFString*)attribute;
 *
 * @param renderer
 * @param attribute
 * @returns gint
 */
- (gint)attributeGetColumnWithRenderer:(GtkCellRenderer*)renderer andAttribute:(OFString*)attribute;

/**
 * - (void*)cellGetPropertyWithRenderer:(GtkCellRenderer*)renderer andPropertyName:(OFString*)propertyName andValue:(GValue*)value;
 *
 * @param renderer
 * @param propertyName
 * @param value
 */
- (void)cellGetPropertyWithRenderer:(GtkCellRenderer*)renderer andPropertyName:(OFString*)propertyName andValue:(GValue*)value;

/**
 * - (void*)cellGetValistWithRenderer:(GtkCellRenderer*)renderer andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs;
 *
 * @param renderer
 * @param firstPropertyName
 * @param varArgs
 */
- (void)cellGetValistWithRenderer:(GtkCellRenderer*)renderer andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs;

/**
 * - (void*)cellSetPropertyWithRenderer:(GtkCellRenderer*)renderer andPropertyName:(OFString*)propertyName andValue:(const GValue*)value;
 *
 * @param renderer
 * @param propertyName
 * @param value
 */
- (void)cellSetPropertyWithRenderer:(GtkCellRenderer*)renderer andPropertyName:(OFString*)propertyName andValue:(const GValue*)value;

/**
 * - (void*)cellSetValistWithRenderer:(GtkCellRenderer*)renderer andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs;
 *
 * @param renderer
 * @param firstPropertyName
 * @param varArgs
 */
- (void)cellSetValistWithRenderer:(GtkCellRenderer*)renderer andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs;

/**
 * - (GtkCellAreaContext**)copyContext:(GtkCellAreaContext*)context;
 *
 * @param context
 * @returns GtkCellAreaContext*
 */
- (GtkCellAreaContext*)copyContext:(GtkCellAreaContext*)context;

/**
 * - (GtkCellAreaContext**)createContext;
 *
 * @returns GtkCellAreaContext*
 */
- (GtkCellAreaContext*)createContext;

/**
 * - (gint*)eventWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andEvent:(GdkEvent*)event andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags;
 *
 * @param context
 * @param widget
 * @param event
 * @param cellArea
 * @param flags
 * @returns gint
 */
- (gint)eventWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andEvent:(GdkEvent*)event andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags;

/**
 * - (bool*)focus:(GtkDirectionType)direction;
 *
 * @param direction
 * @returns bool
 */
- (bool)focus:(GtkDirectionType)direction;

/**
 * - (void*)foreachWithCallback:(GtkCellCallback)callback andCallbackData:(gpointer)callbackData;
 *
 * @param callback
 * @param callbackData
 */
- (void)foreachWithCallback:(GtkCellCallback)callback andCallbackData:(gpointer)callbackData;

/**
 * - (void*)foreachAllocWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andBackgroundArea:(const GdkRectangle*)backgroundArea andCallback:(GtkCellAllocCallback)callback andCallbackData:(gpointer)callbackData;
 *
 * @param context
 * @param widget
 * @param cellArea
 * @param backgroundArea
 * @param callback
 * @param callbackData
 */
- (void)foreachAllocWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andBackgroundArea:(const GdkRectangle*)backgroundArea andCallback:(GtkCellAllocCallback)callback andCallbackData:(gpointer)callbackData;

/**
 * - (void*)getCellAllocationWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andRenderer:(GtkCellRenderer*)renderer andCellArea:(const GdkRectangle*)cellArea andAllocation:(GdkRectangle*)allocation;
 *
 * @param context
 * @param widget
 * @param renderer
 * @param cellArea
 * @param allocation
 */
- (void)getCellAllocationWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andRenderer:(GtkCellRenderer*)renderer andCellArea:(const GdkRectangle*)cellArea andAllocation:(GdkRectangle*)allocation;

/**
 * - (GtkCellRenderer**)getCellAtPositionWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andX:(gint)x andY:(gint)y andAllocArea:(GdkRectangle*)allocArea;
 *
 * @param context
 * @param widget
 * @param cellArea
 * @param x
 * @param y
 * @param allocArea
 * @returns GtkCellRenderer*
 */
- (GtkCellRenderer*)getCellAtPositionWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andX:(gint)x andY:(gint)y andAllocArea:(GdkRectangle*)allocArea;

/**
 * - (OFString**)getCurrentPathString;
 *
 * @returns OFString*
 */
- (OFString*)getCurrentPathString;

/**
 * - (GtkCellEditable**)getEditWidget;
 *
 * @returns GtkCellEditable*
 */
- (GtkCellEditable*)getEditWidget;

/**
 * - (GtkCellRenderer**)getEditedCell;
 *
 * @returns GtkCellRenderer*
 */
- (GtkCellRenderer*)getEditedCell;

/**
 * - (GtkCellRenderer**)getFocusCell;
 *
 * @returns GtkCellRenderer*
 */
- (GtkCellRenderer*)getFocusCell;

/**
 * - (GtkCellRenderer**)getFocusFromSibling:(GtkCellRenderer*)renderer;
 *
 * @param renderer
 * @returns GtkCellRenderer*
 */
- (GtkCellRenderer*)getFocusFromSibling:(GtkCellRenderer*)renderer;

/**
 * - (const GList**)getFocusSiblings:(GtkCellRenderer*)renderer;
 *
 * @param renderer
 * @returns const GList*
 */
- (const GList*)getFocusSiblings:(GtkCellRenderer*)renderer;

/**
 * - (void*)getPreferredHeightWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight;
 *
 * @param context
 * @param widget
 * @param minimumHeight
 * @param naturalHeight
 */
- (void)getPreferredHeightWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight;

/**
 * - (void*)getPreferredHeightForWidthWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andWidth:(gint)width andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight;
 *
 * @param context
 * @param widget
 * @param width
 * @param minimumHeight
 * @param naturalHeight
 */
- (void)getPreferredHeightForWidthWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andWidth:(gint)width andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight;

/**
 * - (void*)getPreferredWidthWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth;
 *
 * @param context
 * @param widget
 * @param minimumWidth
 * @param naturalWidth
 */
- (void)getPreferredWidthWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth;

/**
 * - (void*)getPreferredWidthForHeightWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andHeight:(gint)height andMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth;
 *
 * @param context
 * @param widget
 * @param height
 * @param minimumWidth
 * @param naturalWidth
 */
- (void)getPreferredWidthForHeightWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andHeight:(gint)height andMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth;

/**
 * - (GtkSizeRequestMode*)getRequestMode;
 *
 * @returns GtkSizeRequestMode
 */
- (GtkSizeRequestMode)getRequestMode;

/**
 * - (bool*)hasRenderer:(GtkCellRenderer*)renderer;
 *
 * @param renderer
 * @returns bool
 */
- (bool)hasRenderer:(GtkCellRenderer*)renderer;

/**
 * - (void*)innerCellAreaWithWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andInnerArea:(GdkRectangle*)innerArea;
 *
 * @param widget
 * @param cellArea
 * @param innerArea
 */
- (void)innerCellAreaWithWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andInnerArea:(GdkRectangle*)innerArea;

/**
 * - (bool*)isActivatable;
 *
 * @returns bool
 */
- (bool)isActivatable;

/**
 * - (bool*)isFocusSiblingWithRenderer:(GtkCellRenderer*)renderer andSibling:(GtkCellRenderer*)sibling;
 *
 * @param renderer
 * @param sibling
 * @returns bool
 */
- (bool)isFocusSiblingWithRenderer:(GtkCellRenderer*)renderer andSibling:(GtkCellRenderer*)sibling;

/**
 * - (void*)remove:(GtkCellRenderer*)renderer;
 *
 * @param renderer
 */
- (void)remove:(GtkCellRenderer*)renderer;

/**
 * - (void*)removeFocusSiblingWithRenderer:(GtkCellRenderer*)renderer andSibling:(GtkCellRenderer*)sibling;
 *
 * @param renderer
 * @param sibling
 */
- (void)removeFocusSiblingWithRenderer:(GtkCellRenderer*)renderer andSibling:(GtkCellRenderer*)sibling;

/**
 * - (void*)renderWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andCr:(cairo_t*)cr andBackgroundArea:(const GdkRectangle*)backgroundArea andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags andPaintFocus:(bool)paintFocus;
 *
 * @param context
 * @param widget
 * @param cr
 * @param backgroundArea
 * @param cellArea
 * @param flags
 * @param paintFocus
 */
- (void)renderWithContext:(GtkCellAreaContext*)context andWidget:(OGTKWidget*)widget andCr:(cairo_t*)cr andBackgroundArea:(const GdkRectangle*)backgroundArea andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags andPaintFocus:(bool)paintFocus;

/**
 * - (void*)requestRendererWithRenderer:(GtkCellRenderer*)renderer andOrientation:(GtkOrientation)orientation andWidget:(OGTKWidget*)widget andForSize:(gint)forSize andMinimumSize:(gint*)minimumSize andNaturalSize:(gint*)naturalSize;
 *
 * @param renderer
 * @param orientation
 * @param widget
 * @param forSize
 * @param minimumSize
 * @param naturalSize
 */
- (void)requestRendererWithRenderer:(GtkCellRenderer*)renderer andOrientation:(GtkOrientation)orientation andWidget:(OGTKWidget*)widget andForSize:(gint)forSize andMinimumSize:(gint*)minimumSize andNaturalSize:(gint*)naturalSize;

/**
 * - (void*)setFocusCell:(GtkCellRenderer*)renderer;
 *
 * @param renderer
 */
- (void)setFocusCell:(GtkCellRenderer*)renderer;

/**
 * - (void*)stopEditing:(bool)canceled;
 *
 * @param canceled
 */
- (void)stopEditing:(bool)canceled;

@end