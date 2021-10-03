/*
 * OGTKFontSelection.h
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
#import "OGTKBox.h"

@interface OGTKFontSelection : OGTKBox
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkFontSelection*)FONTSELECTION;

/**
 * - (PangoFontFace**)getFace;
 *
 * @returns PangoFontFace*
 */
- (PangoFontFace*)getFace;

/**
 * - (OGTKWidget**)getFaceList;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getFaceList;

/**
 * - (PangoFontFamily**)getFamily;
 *
 * @returns PangoFontFamily*
 */
- (PangoFontFamily*)getFamily;

/**
 * - (OGTKWidget**)getFamilyList;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getFamilyList;

/**
 * - (OFString**)getFontName;
 *
 * @returns OFString*
 */
- (OFString*)getFontName;

/**
 * - (OGTKWidget**)getPreviewEntry;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getPreviewEntry;

/**
 * - (OFString**)getPreviewText;
 *
 * @returns OFString*
 */
- (OFString*)getPreviewText;

/**
 * - (gint*)getSize;
 *
 * @returns gint
 */
- (gint)getSize;

/**
 * - (OGTKWidget**)getSizeEntry;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getSizeEntry;

/**
 * - (OGTKWidget**)getSizeList;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getSizeList;

/**
 * - (bool*)setFontName:(OFString*)fontname;
 *
 * @param fontname
 * @returns bool
 */
- (bool)setFontName:(OFString*)fontname;

/**
 * - (void*)setPreviewText:(OFString*)text;
 *
 * @param text
 */
- (void)setPreviewText:(OFString*)text;

@end