/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <pango/pango.h>

#import <OGObject/OGObject.h>

@class OGPangoFontMap;
@class OGPangoFontFace;
@class OGPangoCoverage;
@class OGPangoEngineShape;

/**
 * The #PangoFont structure is used to represent
 * a font in a rendering-system-independent matter.
 * To create an implementation of a #PangoFont,
 * the rendering-system specific code should allocate
 * a larger structure that contains a nested
 * #PangoFont, fill in the <structfield>klass</structfield> member of
 * the nested #PangoFont with a pointer to
 * a appropriate #PangoFontClass, then call
 * pango_font_init() on the structure.
 * 
 * The #PangoFont structure contains one member
 * which the implementation fills in.
 *
 */
@interface OGPangoFont : OGObject
{

}

/**
 * Functions
 */

/**
 * Frees an array of font descriptions.
 *
 * @param descs a pointer
 * to an array of #PangoFontDescription, may be %NULL
 * @param ndescs number of font descriptions in @descs
 */
+ (void)descriptionsFreeWithDescs:(PangoFontDescription**)descs ndescs:(int)ndescs;

/**
 * Methods
 */

- (PangoFont*)FONT;

/**
 * Returns a description of the font, with font size set in points.
 * Use pango_font_describe_with_absolute_size() if you want the font
 * size in device units.
 *
 * @return a newly-allocated #PangoFontDescription object.
 */
- (PangoFontDescription*)describe;

/**
 * Returns a description of the font, with absolute font size set
 * (in device units). Use pango_font_describe() if you want the font
 * size in points.
 *
 * @return a newly-allocated #PangoFontDescription object.
 */
- (PangoFontDescription*)describeWithAbsoluteSize;

/**
 * Finds the best matching shaper for a font for a particular
 * language tag and character point.
 *
 * @param language the language tag
 * @param ch a Unicode character.
 * @return the best matching shaper.
 */
- (OGPangoEngineShape*)findShaperWithLanguage:(PangoLanguage*)language ch:(guint32)ch;

/**
 * Computes the coverage map for a given font and language tag.
 *
 * @param language the language tag
 * @return a newly-allocated #PangoCoverage
 *   object.
 */
- (OGPangoCoverage*)coverage:(PangoLanguage*)language;

/**
 * Gets the #PangoFontFace to which @font belongs.
 *
 * @return the #PangoFontFace
 */
- (OGPangoFontFace*)face;

/**
 * Obtain the OpenType features that are provided by the font.
 * These are passed to the rendering system, together with features
 * that have been explicitly set via attributes.
 * 
 * Note that this does not include OpenType features which the
 * rendering system enables by default.
 *
 * @param features Array to features in
 * @param len the length of @features
 * @param numFeatures the number of used items in @features
 */
- (void)featuresWithFeatures:(hb_feature_t*)features len:(guint)len numFeatures:(guint*)numFeatures;

/**
 * Gets the font map for which the font was created.
 * 
 * Note that the font maintains a <firstterm>weak</firstterm> reference
 * to the font map, so if all references to font map are dropped, the font
 * map will be finalized even if there are fonts created with the font
 * map that are still alive.  In that case this function will return %NULL.
 * It is the responsibility of the user to ensure that the font map is kept
 * alive.  In most uses this is not an issue as a #PangoContext holds
 * a reference to the font map.
 *
 * @return the #PangoFontMap for the
 *               font, or %NULL if @font is %NULL.
 */
- (OGPangoFontMap*)fontMap;

/**
 * Gets the logical and ink extents of a glyph within a font. The
 * coordinate system for each rectangle has its origin at the
 * base line and horizontal origin of the character with increasing
 * coordinates extending to the right and down. The macros PANGO_ASCENT(),
 * PANGO_DESCENT(), PANGO_LBEARING(), and PANGO_RBEARING() can be used to convert
 * from the extents rectangle to more traditional font metrics. The units
 * of the rectangles are in 1/PANGO_SCALE of a device unit.
 * 
 * If @font is %NULL, this function gracefully sets some sane values in the
 * output variables and returns.
 *
 * @param glyph the glyph index
 * @param inkRect rectangle used to store the extents of the glyph
 *            as drawn or %NULL to indicate that the result is not needed.
 * @param logicalRect rectangle used to store the logical extents of
 *            the glyph or %NULL to indicate that the result is not needed.
 */
- (void)glyphExtentsWithGlyph:(PangoGlyph)glyph inkRect:(PangoRectangle*)inkRect logicalRect:(PangoRectangle*)logicalRect;

/**
 * Get a hb_font_t object backing this font.
 * 
 * Note that the objects returned by this function
 * are cached and immutable. If you need to make
 * changes to the hb_font_t, use hb_font_create_sub_font().
 *
 * @return the hb_font_t object backing the
 *          font, or %NULL if the font does not have one
 */
- (hb_font_t*)hbFont;

/**
 * Gets overall metric information for a font. Since the metrics may be
 * substantially different for different scripts, a language tag can
 * be provided to indicate that the metrics should be retrieved that
 * correspond to the script(s) used by that language.
 * 
 * If @font is %NULL, this function gracefully sets some sane values in the
 * output variables and returns.
 *
 * @param language language tag used to determine which script to get the metrics
 *            for, or %NULL to indicate to get the metrics for the entire font.
 * @return a #PangoFontMetrics object. The caller must call pango_font_metrics_unref()
 *   when finished using the object.
 */
- (PangoFontMetrics*)metrics:(PangoLanguage*)language;

/**
 * Returns whether the font provides a glyph for this character.
 * 
 * Returns %TRUE if @font can render @wc
 *
 * @param wc a Unicode character
 * @return
 */
- (bool)hasChar:(gunichar)wc;

@end