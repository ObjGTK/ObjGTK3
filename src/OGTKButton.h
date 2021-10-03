/*
 * OGTKButton.h
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

@interface OGTKButton : OGTKBin
{

}


/**
 * Constructors
 */
- (id)init;
- (id)initFromIconNameWithIconName:(OFString*)iconName andSize:(GtkIconSize)size;
- (id)initFromStock:(OFString*)stockId;
- (id)initWithLabel:(OFString*)label;
- (id)initWithMnemonic:(OFString*)label;

/**
 * Methods
 */

- (GtkButton*)BUTTON;

/**
 * - (void*)clicked;
 *
 */
- (void)clicked;

/**
 * - (void*)enter;
 *
 */
- (void)enter;

/**
 * - (void*)getAlignmentWithXalign:(gfloat*)xalign andYalign:(gfloat*)yalign;
 *
 * @param xalign
 * @param yalign
 */
- (void)getAlignmentWithXalign:(gfloat*)xalign andYalign:(gfloat*)yalign;

/**
 * - (bool*)getAlwaysShowImage;
 *
 * @returns bool
 */
- (bool)getAlwaysShowImage;

/**
 * - (GdkWindow**)getEventWindow;
 *
 * @returns GdkWindow*
 */
- (GdkWindow*)getEventWindow;

/**
 * - (bool*)getFocusOnClick;
 *
 * @returns bool
 */
- (bool)getFocusOnClick;

/**
 * - (OGTKWidget**)getImage;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getImage;

/**
 * - (GtkPositionType*)getImagePosition;
 *
 * @returns GtkPositionType
 */
- (GtkPositionType)getImagePosition;

/**
 * - (OFString**)getLabel;
 *
 * @returns OFString*
 */
- (OFString*)getLabel;

/**
 * - (GtkReliefStyle*)getRelief;
 *
 * @returns GtkReliefStyle
 */
- (GtkReliefStyle)getRelief;

/**
 * - (bool*)getUseStock;
 *
 * @returns bool
 */
- (bool)getUseStock;

/**
 * - (bool*)getUseUnderline;
 *
 * @returns bool
 */
- (bool)getUseUnderline;

/**
 * - (void*)leave;
 *
 */
- (void)leave;

/**
 * - (void*)pressed;
 *
 */
- (void)pressed;

/**
 * - (void*)released;
 *
 */
- (void)released;

/**
 * - (void*)setAlignmentWithXalign:(gfloat)xalign andYalign:(gfloat)yalign;
 *
 * @param xalign
 * @param yalign
 */
- (void)setAlignmentWithXalign:(gfloat)xalign andYalign:(gfloat)yalign;

/**
 * - (void*)setAlwaysShowImage:(bool)alwaysShow;
 *
 * @param alwaysShow
 */
- (void)setAlwaysShowImage:(bool)alwaysShow;

/**
 * - (void*)setFocusOnClick:(bool)focusOnClick;
 *
 * @param focusOnClick
 */
- (void)setFocusOnClick:(bool)focusOnClick;

/**
 * - (void*)setImage:(OGTKWidget*)image;
 *
 * @param image
 */
- (void)setImage:(OGTKWidget*)image;

/**
 * - (void*)setImagePosition:(GtkPositionType)position;
 *
 * @param position
 */
- (void)setImagePosition:(GtkPositionType)position;

/**
 * - (void*)setLabel:(OFString*)label;
 *
 * @param label
 */
- (void)setLabel:(OFString*)label;

/**
 * - (void*)setRelief:(GtkReliefStyle)relief;
 *
 * @param relief
 */
- (void)setRelief:(GtkReliefStyle)relief;

/**
 * - (void*)setUseStock:(bool)useStock;
 *
 * @param useStock
 */
- (void)setUseStock:(bool)useStock;

/**
 * - (void*)setUseUnderline:(bool)useUnderline;
 *
 * @param useUnderline
 */
- (void)setUseUnderline:(bool)useUnderline;

@end