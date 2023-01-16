/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoFont.h"

#import "OGPangoFontMap.h"
#import "OGPangoContext.h"
#import "OGPangoCoverage.h"
#import "OGPangoFontFace.h"

@implementation OGPangoFont

+ (void)descriptionsFreeWithDescs:(PangoFontDescription**)descs ndescs:(int)ndescs
{
	pango_font_descriptions_free(descs, ndescs);
}

+ (OGPangoFont*)deserializeWithContext:(OGPangoContext*)context bytes:(GBytes*)bytes err:(GError**)err
{
	return [[[OGPangoFont alloc] initWithGObject:(GObject*)pango_font_deserialize([context CONTEXT], bytes, err)] autorelease];
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

- (PangoLanguage**)languages
{
	return pango_font_get_languages([self FONT]);
}

- (PangoFontMetrics*)metrics:(PangoLanguage*)language
{
	return pango_font_get_metrics([self FONT], language);
}

- (bool)hasChar:(gunichar)wc
{
	return pango_font_has_char([self FONT], wc);
}

- (GBytes*)serialize
{
	return pango_font_serialize([self FONT]);
}


@end