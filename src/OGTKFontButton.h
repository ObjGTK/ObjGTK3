/*
 * OGTKFontButton.h
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
#import "OGTKButton.h"

@interface OGTKFontButton : OGTKButton
{

}


/**
 * Constructors
 */
- (id)init;
- (id)initWithFont:(OFString*)fontname;

/**
 * Methods
 */

- (GtkFontButton*)FONTBUTTON;

/**
 * - (OFString**)getFontName;
 *
 * @returns OFString*
 */
- (OFString*)getFontName;

/**
 * - (bool*)getShowSize;
 *
 * @returns bool
 */
- (bool)getShowSize;

/**
 * - (bool*)getShowStyle;
 *
 * @returns bool
 */
- (bool)getShowStyle;

/**
 * - (OFString**)getTitle;
 *
 * @returns OFString*
 */
- (OFString*)getTitle;

/**
 * - (bool*)getUseFont;
 *
 * @returns bool
 */
- (bool)getUseFont;

/**
 * - (bool*)getUseSize;
 *
 * @returns bool
 */
- (bool)getUseSize;

/**
 * - (bool*)setFontName:(OFString*)fontname;
 *
 * @param fontname
 * @returns bool
 */
- (bool)setFontName:(OFString*)fontname;

/**
 * - (void*)setShowSize:(bool)showSize;
 *
 * @param showSize
 */
- (void)setShowSize:(bool)showSize;

/**
 * - (void*)setShowStyle:(bool)showStyle;
 *
 * @param showStyle
 */
- (void)setShowStyle:(bool)showStyle;

/**
 * - (void*)setTitle:(OFString*)title;
 *
 * @param title
 */
- (void)setTitle:(OFString*)title;

/**
 * - (void*)setUseFont:(bool)useFont;
 *
 * @param useFont
 */
- (void)setUseFont:(bool)useFont;

/**
 * - (void*)setUseSize:(bool)useSize;
 *
 * @param useSize
 */
- (void)setUseSize:(bool)useSize;

@end