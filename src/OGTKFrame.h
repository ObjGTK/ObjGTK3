/*
 * OGTKFrame.h
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

@interface OGTKFrame : OGTKBin
{

}


/**
 * Constructors
 */
- (id)init:(OFString*)label;

/**
 * Methods
 */

- (GtkFrame*)FRAME;

/**
 * - (OFString**)getLabel;
 *
 * @returns OFString*
 */
- (OFString*)getLabel;

/**
 * - (void*)getLabelAlignWithXalign:(gfloat*)xalign andYalign:(gfloat*)yalign;
 *
 * @param xalign
 * @param yalign
 */
- (void)getLabelAlignWithXalign:(gfloat*)xalign andYalign:(gfloat*)yalign;

/**
 * - (OGTKWidget**)getLabelWidget;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getLabelWidget;

/**
 * - (GtkShadowType*)getShadowType;
 *
 * @returns GtkShadowType
 */
- (GtkShadowType)getShadowType;

/**
 * - (void*)setLabel:(OFString*)label;
 *
 * @param label
 */
- (void)setLabel:(OFString*)label;

/**
 * - (void*)setLabelAlignWithXalign:(gfloat)xalign andYalign:(gfloat)yalign;
 *
 * @param xalign
 * @param yalign
 */
- (void)setLabelAlignWithXalign:(gfloat)xalign andYalign:(gfloat)yalign;

/**
 * - (void*)setLabelWidget:(OGTKWidget*)labelWidget;
 *
 * @param labelWidget
 */
- (void)setLabelWidget:(OGTKWidget*)labelWidget;

/**
 * - (void*)setShadowType:(GtkShadowType)type;
 *
 * @param type
 */
- (void)setShadowType:(GtkShadowType)type;

@end