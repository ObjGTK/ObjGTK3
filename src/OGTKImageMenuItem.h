/*
 * OGTKImageMenuItem.h
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
#import "OGTKMenuItem.h"

@interface OGTKImageMenuItem : OGTKMenuItem
{

}


/**
 * Constructors
 */
- (id)init;
- (id)initFromStockWithStockId:(OFString*)stockId andAccelGroup:(GtkAccelGroup*)accelGroup;
- (id)initWithLabel:(OFString*)label;
- (id)initWithMnemonic:(OFString*)label;

/**
 * Methods
 */

- (GtkImageMenuItem*)IMAGEMENUITEM;

/**
 * - (bool*)getAlwaysShowImage;
 *
 * @returns bool
 */
- (bool)getAlwaysShowImage;

/**
 * - (OGTKWidget**)getImage;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getImage;

/**
 * - (bool*)getUseStock;
 *
 * @returns bool
 */
- (bool)getUseStock;

/**
 * - (void*)setAccelGroup:(GtkAccelGroup*)accelGroup;
 *
 * @param accelGroup
 */
- (void)setAccelGroup:(GtkAccelGroup*)accelGroup;

/**
 * - (void*)setAlwaysShowImage:(bool)alwaysShow;
 *
 * @param alwaysShow
 */
- (void)setAlwaysShowImage:(bool)alwaysShow;

/**
 * - (void*)setImage:(OGTKWidget*)image;
 *
 * @param image
 */
- (void)setImage:(OGTKWidget*)image;

/**
 * - (void*)setUseStock:(bool)useStock;
 *
 * @param useStock
 */
- (void)setUseStock:(bool)useStock;

@end