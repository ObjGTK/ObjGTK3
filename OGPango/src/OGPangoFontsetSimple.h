/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoFontset.h"

@class OGPangoFont;

/**
 * #PangoFontsetSimple is a implementation of the abstract
 * #PangoFontset base class in terms of an array of fonts,
 * which the creator provides when constructing the
 * #PangoFontsetSimple.
 *
 */
@interface OGPangoFontsetSimple : OGPangoFontset
{

}


/**
 * Constructors
 */
- (instancetype)init:(PangoLanguage*)language;

/**
 * Methods
 */

- (PangoFontsetSimple*)FONTSETSIMPLE;

/**
 * Adds a font to the fontset.
 *
 * @param font a #PangoFont.
 */
- (void)append:(OGPangoFont*)font;

/**
 * Returns the number of fonts in the fontset.
 *
 * @return the size of @fontset.
 */
- (int)size;

@end