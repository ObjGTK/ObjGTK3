/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoFont.h"

#import "OGPangoFontMap.h"
#import "OGPangoFontFace.h"
#import "OGPangoCoverage.h"
#import "OGPangoEngineShape.h"

@implementation OGPangoFont

+ (void)descriptionsFreeWithDescs:(PangoFontDescription**)descs ndescs:(int)ndescs
{
	pango_font_descriptions_free(descs, ndescs);
}

- (PangoFont*)FONT
{
	return PANGO_FONT([self GOBJECT]);
}

- (PangoFontDescription*)describe
{
	return pango_font_describe([self FONT]);
}

- (PangoFontDescription*)describeWithAbsoluteSize
{
	return pango_font_describe_with_absolute_size([self FONT]);
}

- (OGPangoEngineShape*)findShaperWithLanguage:(PangoLanguage*)language ch:(guint32)ch
{
	return [[[OGPangoEngineShape alloc] initWithGObject:(GObject*)pango_font_find_shaper([self FONT], language, ch)] autorelease];
}

- (OGPangoCoverage*)coverage:(PangoLanguage*)language
{
	return [[[OGPangoCoverage alloc] initWithGObject:(GObject*)pango_font_get_coverage([self FONT], language)] autorelease];
}

- (OGPangoFontFace*)face
{
	return [[[OGPangoFontFace alloc] initWithGObject:(GObject*)pango_font_get_face([self FONT])] autorelease];
}

- (void)featuresWithFeatures:(hb_feature_t*)features len:(guint)len numFeatures:(guint*)numFeatures
{
	pango_font_get_features([self FONT], features, len, numFeatures);
}

- (OGPangoFontMap*)fontMap
{
	return [[[OGPangoFontMap alloc] initWithGObject:(GObject*)pango_font_get_font_map([self FONT])] autorelease];
}

- (void)glyphExtentsWithGlyph:(PangoGlyph)glyph inkRect:(PangoRectangle*)inkRect logicalRect:(PangoRectangle*)logicalRect
{
	pango_font_get_glyph_extents([self FONT], glyph, inkRect, logicalRect);
}

- (hb_font_t*)hbFont
{
	return pango_font_get_hb_font([self FONT]);
}

- (PangoFontMetrics*)metrics:(PangoLanguage*)language
{
	return pango_font_get_metrics([self FONT], language);
}

- (bool)hasChar:(gunichar)wc
{
	return pango_font_has_char([self FONT], wc);
}


@end