/*
 * OGTKToolItem.h
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
#import "OGTKBin.h"

@interface OGTKToolItem : OGTKBin
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkToolItem*)TOOLITEM;

/**
 * - (PangoEllipsizeMode*)getEllipsizeMode;
 *
 * @returns PangoEllipsizeMode
 */
- (PangoEllipsizeMode)getEllipsizeMode;

/**
 * - (bool*)getExpand;
 *
 * @returns bool
 */
- (bool)getExpand;

/**
 * - (bool*)getHomogeneous;
 *
 * @returns bool
 */
- (bool)getHomogeneous;

/**
 * - (GtkIconSize*)getIconSize;
 *
 * @returns GtkIconSize
 */
- (GtkIconSize)getIconSize;

/**
 * - (bool*)getIsImportant;
 *
 * @returns bool
 */
- (bool)getIsImportant;

/**
 * - (GtkOrientation*)getOrientation;
 *
 * @returns GtkOrientation
 */
- (GtkOrientation)getOrientation;

/**
 * - (OGTKWidget**)getProxyMenuItem:(OFString*)menuItemId;
 *
 * @param menuItemId
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getProxyMenuItem:(OFString*)menuItemId;

/**
 * - (GtkReliefStyle*)getReliefStyle;
 *
 * @returns GtkReliefStyle
 */
- (GtkReliefStyle)getReliefStyle;

/**
 * - (gfloat*)getTextAlignment;
 *
 * @returns gfloat
 */
- (gfloat)getTextAlignment;

/**
 * - (GtkOrientation*)getTextOrientation;
 *
 * @returns GtkOrientation
 */
- (GtkOrientation)getTextOrientation;

/**
 * - (GtkSizeGroup**)getTextSizeGroup;
 *
 * @returns GtkSizeGroup*
 */
- (GtkSizeGroup*)getTextSizeGroup;

/**
 * - (GtkToolbarStyle*)getToolbarStyle;
 *
 * @returns GtkToolbarStyle
 */
- (GtkToolbarStyle)getToolbarStyle;

/**
 * - (bool*)getUseDragWindow;
 *
 * @returns bool
 */
- (bool)getUseDragWindow;

/**
 * - (bool*)getVisibleHorizontal;
 *
 * @returns bool
 */
- (bool)getVisibleHorizontal;

/**
 * - (bool*)getVisibleVertical;
 *
 * @returns bool
 */
- (bool)getVisibleVertical;

/**
 * - (void*)rebuildMenu;
 *
 */
- (void)rebuildMenu;

/**
 * - (OGTKWidget**)retrieveProxyMenuItem;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)retrieveProxyMenuItem;

/**
 * - (void*)setExpand:(bool)expand;
 *
 * @param expand
 */
- (void)setExpand:(bool)expand;

/**
 * - (void*)setHomogeneous:(bool)homogeneous;
 *
 * @param homogeneous
 */
- (void)setHomogeneous:(bool)homogeneous;

/**
 * - (void*)setIsImportant:(bool)isImportant;
 *
 * @param isImportant
 */
- (void)setIsImportant:(bool)isImportant;

/**
 * - (void*)setProxyMenuItemWithMenuItemId:(OFString*)menuItemId andMenuItem:(OGTKWidget*)menuItem;
 *
 * @param menuItemId
 * @param menuItem
 */
- (void)setProxyMenuItemWithMenuItemId:(OFString*)menuItemId andMenuItem:(OGTKWidget*)menuItem;

/**
 * - (void*)setTooltipMarkup:(OFString*)markup;
 *
 * @param markup
 */
- (void)setTooltipMarkup:(OFString*)markup;

/**
 * - (void*)setTooltipText:(OFString*)text;
 *
 * @param text
 */
- (void)setTooltipText:(OFString*)text;

/**
 * - (void*)setUseDragWindow:(bool)useDragWindow;
 *
 * @param useDragWindow
 */
- (void)setUseDragWindow:(bool)useDragWindow;

/**
 * - (void*)setVisibleHorizontal:(bool)visibleHorizontal;
 *
 * @param visibleHorizontal
 */
- (void)setVisibleHorizontal:(bool)visibleHorizontal;

/**
 * - (void*)setVisibleVertical:(bool)visibleVertical;
 *
 * @param visibleVertical
 */
- (void)setVisibleVertical:(bool)visibleVertical;

/**
 * - (void*)toolbarReconfigured;
 *
 */
- (void)toolbarReconfigured;

@end