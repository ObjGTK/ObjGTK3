/*
 * OGTKToolButton.h
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
#import "OGTKToolItem.h"

@interface OGTKToolButton : OGTKToolItem
{

}


/**
 * Constructors
 */
- (id)initWithIconWidget:(OGTKWidget*)iconWidget andLabel:(OFString*)label;
- (id)initFromStock:(OFString*)stockId;

/**
 * Methods
 */

- (GtkToolButton*)TOOLBUTTON;

/**
 * - (OFString**)getIconName;
 *
 * @returns OFString*
 */
- (OFString*)getIconName;

/**
 * - (OGTKWidget**)getIconWidget;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getIconWidget;

/**
 * - (OFString**)getLabel;
 *
 * @returns OFString*
 */
- (OFString*)getLabel;

/**
 * - (OGTKWidget**)getLabelWidget;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getLabelWidget;

/**
 * - (OFString**)getStockId;
 *
 * @returns OFString*
 */
- (OFString*)getStockId;

/**
 * - (bool*)getUseUnderline;
 *
 * @returns bool
 */
- (bool)getUseUnderline;

/**
 * - (void*)setIconName:(OFString*)iconName;
 *
 * @param iconName
 */
- (void)setIconName:(OFString*)iconName;

/**
 * - (void*)setIconWidget:(OGTKWidget*)iconWidget;
 *
 * @param iconWidget
 */
- (void)setIconWidget:(OGTKWidget*)iconWidget;

/**
 * - (void*)setLabel:(OFString*)label;
 *
 * @param label
 */
- (void)setLabel:(OFString*)label;

/**
 * - (void*)setLabelWidget:(OGTKWidget*)labelWidget;
 *
 * @param labelWidget
 */
- (void)setLabelWidget:(OGTKWidget*)labelWidget;

/**
 * - (void*)setStockId:(OFString*)stockId;
 *
 * @param stockId
 */
- (void)setStockId:(OFString*)stockId;

/**
 * - (void*)setUseUnderline:(bool)useUnderline;
 *
 * @param useUnderline
 */
- (void)setUseUnderline:(bool)useUnderline;

@end