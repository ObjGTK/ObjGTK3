/*
 * OGTKAction.h
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

@interface OGTKAction : OGTKBase
{

}


/**
 * Constructors
 */
- (id)initWithName:(OFString*)name andLabel:(OFString*)label andTooltip:(OFString*)tooltip andStockId:(OFString*)stockId;

/**
 * Methods
 */

- (GtkAction*)ACTION;

/**
 * - (void*)activate;
 *
 */
- (void)activate;

/**
 * - (void*)blockActivate;
 *
 */
- (void)blockActivate;

/**
 * - (void*)connectAccelerator;
 *
 */
- (void)connectAccelerator;

/**
 * - (OGTKWidget**)createIcon:(GtkIconSize)iconSize;
 *
 * @param iconSize
 * @returns OGTKWidget*
 */
- (OGTKWidget*)createIcon:(GtkIconSize)iconSize;

/**
 * - (OGTKWidget**)createMenu;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)createMenu;

/**
 * - (OGTKWidget**)createMenuItem;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)createMenuItem;

/**
 * - (OGTKWidget**)createToolItem;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)createToolItem;

/**
 * - (void*)disconnectAccelerator;
 *
 */
- (void)disconnectAccelerator;

/**
 * - (GClosure**)getAccelClosure;
 *
 * @returns GClosure*
 */
- (GClosure*)getAccelClosure;

/**
 * - (OFString**)getAccelPath;
 *
 * @returns OFString*
 */
- (OFString*)getAccelPath;

/**
 * - (bool*)getAlwaysShowImage;
 *
 * @returns bool
 */
- (bool)getAlwaysShowImage;

/**
 * - (GIcon**)getGicon;
 *
 * @returns GIcon*
 */
- (GIcon*)getGicon;

/**
 * - (OFString**)getIconName;
 *
 * @returns OFString*
 */
- (OFString*)getIconName;

/**
 * - (bool*)getIsImportant;
 *
 * @returns bool
 */
- (bool)getIsImportant;

/**
 * - (OFString**)getLabel;
 *
 * @returns OFString*
 */
- (OFString*)getLabel;

/**
 * - (OFString**)getName;
 *
 * @returns OFString*
 */
- (OFString*)getName;

/**
 * - (GSList**)getProxies;
 *
 * @returns GSList*
 */
- (GSList*)getProxies;

/**
 * - (bool*)getSensitive;
 *
 * @returns bool
 */
- (bool)getSensitive;

/**
 * - (OFString**)getShortLabel;
 *
 * @returns OFString*
 */
- (OFString*)getShortLabel;

/**
 * - (OFString**)getStockId;
 *
 * @returns OFString*
 */
- (OFString*)getStockId;

/**
 * - (OFString**)getTooltip;
 *
 * @returns OFString*
 */
- (OFString*)getTooltip;

/**
 * - (bool*)getVisible;
 *
 * @returns bool
 */
- (bool)getVisible;

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
 * - (bool*)isSensitive;
 *
 * @returns bool
 */
- (bool)isSensitive;

/**
 * - (bool*)isVisible;
 *
 * @returns bool
 */
- (bool)isVisible;

/**
 * - (void*)setAccelGroup:(GtkAccelGroup*)accelGroup;
 *
 * @param accelGroup
 */
- (void)setAccelGroup:(GtkAccelGroup*)accelGroup;

/**
 * - (void*)setAccelPath:(OFString*)accelPath;
 *
 * @param accelPath
 */
- (void)setAccelPath:(OFString*)accelPath;

/**
 * - (void*)setAlwaysShowImage:(bool)alwaysShow;
 *
 * @param alwaysShow
 */
- (void)setAlwaysShowImage:(bool)alwaysShow;

/**
 * - (void*)setGicon:(GIcon*)icon;
 *
 * @param icon
 */
- (void)setGicon:(GIcon*)icon;

/**
 * - (void*)setIconName:(OFString*)iconName;
 *
 * @param iconName
 */
- (void)setIconName:(OFString*)iconName;

/**
 * - (void*)setIsImportant:(bool)isImportant;
 *
 * @param isImportant
 */
- (void)setIsImportant:(bool)isImportant;

/**
 * - (void*)setLabel:(OFString*)label;
 *
 * @param label
 */
- (void)setLabel:(OFString*)label;

/**
 * - (void*)setSensitive:(bool)sensitive;
 *
 * @param sensitive
 */
- (void)setSensitive:(bool)sensitive;

/**
 * - (void*)setShortLabel:(OFString*)shortLabel;
 *
 * @param shortLabel
 */
- (void)setShortLabel:(OFString*)shortLabel;

/**
 * - (void*)setStockId:(OFString*)stockId;
 *
 * @param stockId
 */
- (void)setStockId:(OFString*)stockId;

/**
 * - (void*)setTooltip:(OFString*)tooltip;
 *
 * @param tooltip
 */
- (void)setTooltip:(OFString*)tooltip;

/**
 * - (void*)setVisible:(bool)visible;
 *
 * @param visible
 */
- (void)setVisible:(bool)visible;

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
 * - (void*)unblockActivate;
 *
 */
- (void)unblockActivate;

@end