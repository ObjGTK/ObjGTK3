/*
 * OGTKCellRenderer.h
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

@interface OGTKCellRenderer : OGTKBase
{

}


/**
 * Methods
 */

- (GtkCellRenderer*)CELLRENDERER;

/**
 * - (bool*)activateWithEvent:(GdkEvent*)event andWidget:(OGTKWidget*)widget andPath:(OFString*)path andBackgroundArea:(const GdkRectangle*)backgroundArea andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags;
 *
 * @param event
 * @param widget
 * @param path
 * @param backgroundArea
 * @param cellArea
 * @param flags
 * @returns bool
 */
- (bool)activateWithEvent:(GdkEvent*)event andWidget:(OGTKWidget*)widget andPath:(OFString*)path andBackgroundArea:(const GdkRectangle*)backgroundArea andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags;

/**
 * - (void*)getAlignedAreaWithWidget:(OGTKWidget*)widget andFlags:(GtkCellRendererState)flags andCellArea:(const GdkRectangle*)cellArea andAlignedArea:(GdkRectangle*)alignedArea;
 *
 * @param widget
 * @param flags
 * @param cellArea
 * @param alignedArea
 */
- (void)getAlignedAreaWithWidget:(OGTKWidget*)widget andFlags:(GtkCellRendererState)flags andCellArea:(const GdkRectangle*)cellArea andAlignedArea:(GdkRectangle*)alignedArea;

/**
 * - (void*)getAlignmentWithXalign:(gfloat*)xalign andYalign:(gfloat*)yalign;
 *
 * @param xalign
 * @param yalign
 */
- (void)getAlignmentWithXalign:(gfloat*)xalign andYalign:(gfloat*)yalign;

/**
 * - (void*)getFixedSizeWithWidth:(gint*)width andHeight:(gint*)height;
 *
 * @param width
 * @param height
 */
- (void)getFixedSizeWithWidth:(gint*)width andHeight:(gint*)height;

/**
 * - (void*)getPaddingWithXpad:(gint*)xpad andYpad:(gint*)ypad;
 *
 * @param xpad
 * @param ypad
 */
- (void)getPaddingWithXpad:(gint*)xpad andYpad:(gint*)ypad;

/**
 * - (void*)getPreferredHeightWithWidget:(OGTKWidget*)widget andMinimumSize:(gint*)minimumSize andNaturalSize:(gint*)naturalSize;
 *
 * @param widget
 * @param minimumSize
 * @param naturalSize
 */
- (void)getPreferredHeightWithWidget:(OGTKWidget*)widget andMinimumSize:(gint*)minimumSize andNaturalSize:(gint*)naturalSize;

/**
 * - (void*)getPreferredHeightForWidthWithWidget:(OGTKWidget*)widget andWidth:(gint)width andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight;
 *
 * @param widget
 * @param width
 * @param minimumHeight
 * @param naturalHeight
 */
- (void)getPreferredHeightForWidthWithWidget:(OGTKWidget*)widget andWidth:(gint)width andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight;

/**
 * - (void*)getPreferredSizeWithWidget:(OGTKWidget*)widget andMinimumSize:(GtkRequisition*)minimumSize andNaturalSize:(GtkRequisition*)naturalSize;
 *
 * @param widget
 * @param minimumSize
 * @param naturalSize
 */
- (void)getPreferredSizeWithWidget:(OGTKWidget*)widget andMinimumSize:(GtkRequisition*)minimumSize andNaturalSize:(GtkRequisition*)naturalSize;

/**
 * - (void*)getPreferredWidthWithWidget:(OGTKWidget*)widget andMinimumSize:(gint*)minimumSize andNaturalSize:(gint*)naturalSize;
 *
 * @param widget
 * @param minimumSize
 * @param naturalSize
 */
- (void)getPreferredWidthWithWidget:(OGTKWidget*)widget andMinimumSize:(gint*)minimumSize andNaturalSize:(gint*)naturalSize;

/**
 * - (void*)getPreferredWidthForHeightWithWidget:(OGTKWidget*)widget andHeight:(gint)height andMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth;
 *
 * @param widget
 * @param height
 * @param minimumWidth
 * @param naturalWidth
 */
- (void)getPreferredWidthForHeightWithWidget:(OGTKWidget*)widget andHeight:(gint)height andMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth;

/**
 * - (GtkSizeRequestMode*)getRequestMode;
 *
 * @returns GtkSizeRequestMode
 */
- (GtkSizeRequestMode)getRequestMode;

/**
 * - (bool*)getSensitive;
 *
 * @returns bool
 */
- (bool)getSensitive;

/**
 * - (void*)getSizeWithWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andXoffset:(gint*)xoffset andYoffset:(gint*)yoffset andWidth:(gint*)width andHeight:(gint*)height;
 *
 * @param widget
 * @param cellArea
 * @param xoffset
 * @param yoffset
 * @param width
 * @param height
 */
- (void)getSizeWithWidget:(OGTKWidget*)widget andCellArea:(const GdkRectangle*)cellArea andXoffset:(gint*)xoffset andYoffset:(gint*)yoffset andWidth:(gint*)width andHeight:(gint*)height;

/**
 * - (GtkStateFlags*)getStateWithWidget:(OGTKWidget*)widget andCellState:(GtkCellRendererState)cellState;
 *
 * @param widget
 * @param cellState
 * @returns GtkStateFlags
 */
- (GtkStateFlags)getStateWithWidget:(OGTKWidget*)widget andCellState:(GtkCellRendererState)cellState;

/**
 * - (bool*)getVisible;
 *
 * @returns bool
 */
- (bool)getVisible;

/**
 * - (bool*)isActivatable;
 *
 * @returns bool
 */
- (bool)isActivatable;

/**
 * - (void*)renderWithCr:(cairo_t*)cr andWidget:(OGTKWidget*)widget andBackgroundArea:(const GdkRectangle*)backgroundArea andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags;
 *
 * @param cr
 * @param widget
 * @param backgroundArea
 * @param cellArea
 * @param flags
 */
- (void)renderWithCr:(cairo_t*)cr andWidget:(OGTKWidget*)widget andBackgroundArea:(const GdkRectangle*)backgroundArea andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags;

/**
 * - (void*)setAlignmentWithXalign:(gfloat)xalign andYalign:(gfloat)yalign;
 *
 * @param xalign
 * @param yalign
 */
- (void)setAlignmentWithXalign:(gfloat)xalign andYalign:(gfloat)yalign;

/**
 * - (void*)setFixedSizeWithWidth:(gint)width andHeight:(gint)height;
 *
 * @param width
 * @param height
 */
- (void)setFixedSizeWithWidth:(gint)width andHeight:(gint)height;

/**
 * - (void*)setPaddingWithXpad:(gint)xpad andYpad:(gint)ypad;
 *
 * @param xpad
 * @param ypad
 */
- (void)setPaddingWithXpad:(gint)xpad andYpad:(gint)ypad;

/**
 * - (void*)setSensitive:(bool)sensitive;
 *
 * @param sensitive
 */
- (void)setSensitive:(bool)sensitive;

/**
 * - (void*)setVisible:(bool)visible;
 *
 * @param visible
 */
- (void)setVisible:(bool)visible;

/**
 * - (GtkCellEditable**)startEditingWithEvent:(GdkEvent*)event andWidget:(OGTKWidget*)widget andPath:(OFString*)path andBackgroundArea:(const GdkRectangle*)backgroundArea andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags;
 *
 * @param event
 * @param widget
 * @param path
 * @param backgroundArea
 * @param cellArea
 * @param flags
 * @returns GtkCellEditable*
 */
- (GtkCellEditable*)startEditingWithEvent:(GdkEvent*)event andWidget:(OGTKWidget*)widget andPath:(OFString*)path andBackgroundArea:(const GdkRectangle*)backgroundArea andCellArea:(const GdkRectangle*)cellArea andFlags:(GtkCellRendererState)flags;

/**
 * - (void*)stopEditing:(bool)canceled;
 *
 * @param canceled
 */
- (void)stopEditing:(bool)canceled;

@end