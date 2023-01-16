/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoContext.h"

#import "OGPangoFontMap.h"
#import "OGPangoFontFamily.h"
#import "OGPangoFontset.h"
#import "OGPangoFont.h"

@implementation OGPangoContext

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)pango_context_new()];

	return self;
}

- (PangoContext*)CONTEXT
{
	return PANGO_CONTEXT([self GOBJECT]);
}

- (void)changed
{
	pango_context_changed([self CONTEXT]);
}

- (PangoDirection)baseDir
{
	return pango_context_get_base_dir([self CONTEXT]);
}

- (PangoGravity)baseGravity
{
	return pango_context_get_base_gravity([self CONTEXT]);
}

- (PangoFontDescription*)fontDescription
{
	return pango_context_get_font_description([self CONTEXT]);
}

- (OGPangoFontMap*)fontMap
{
	return [[[OGPangoFontMap alloc] initWithGObject:(GObject*)pango_context_get_font_map([self CONTEXT])] autorelease];
}

- (PangoGravity)gravity
{
	return pango_context_get_gravity([self CONTEXT]);
}

- (PangoGravityHint)gravityHint
{
	return pango_context_get_gravity_hint([self CONTEXT]);
}

- (PangoLanguage*)language
{
	return pango_context_get_language([self CONTEXT]);
}

- (const PangoMatrix*)matrix
{
	return pango_context_get_matrix([self CONTEXT]);
}

- (PangoFontMetrics*)metricsWithDesc:(const PangoFontDescription*)desc language:(PangoLanguage*)language
{
	return pango_context_get_metrics([self CONTEXT], desc, language);
}

- (bool)roundGlyphPositions
{
	return pango_context_get_round_glyph_positions([self CONTEXT]);
}

- (guint)serial
{
	return pango_context_get_serial([self CONTEXT]);
}

- (void)listFamiliesWithFamilies:(PangoFontFamily***)families nfamilies:(int*)nfamilies
{
	pango_context_list_families([self CONTEXT], families, nfamilies);
}

- (OGPangoFont*)loadFont:(const PangoFontDescription*)desc
{
	return [[[OGPangoFont alloc] initWithGObject:(GObject*)pango_context_load_font([self CONTEXT], desc)] autorelease];
}

- (OGPangoFontset*)loadFontsetWithDesc:(const PangoFontDescription*)desc language:(PangoLanguage*)language
{
	return [[[OGPangoFontset alloc] initWithGObject:(GObject*)pango_context_load_fontset([self CONTEXT], desc, language)] autorelease];
}

- (void)setBaseDir:(PangoDirection)direction
{
	pango_context_set_base_dir([self CONTEXT], direction);
}

- (void)setBaseGravity:(PangoGravity)gravity
{
	pango_context_set_base_gravity([self CONTEXT], gravity);
}

- (void)setFontDescription:(const PangoFontDescription*)desc
{
	pango_context_set_font_description([self CONTEXT], desc);
}

- (void)setFontMap:(OGPangoFontMap*)fontMap
{
	pango_context_set_font_map([self CONTEXT], [fontMap FONTMAP]);
}

- (void)setGravityHint:(PangoGravityHint)hint
{
	pango_context_set_gravity_hint([self CONTEXT], hint);
}

- (void)setLanguage:(PangoLanguage*)language
{
	pango_context_set_language([self CONTEXT], language);
}

- (void)setMatrix:(const PangoMatrix*)matrix
{
	pango_context_set_matrix([self CONTEXT], matrix);
}

- (void)setRoundGlyphPositions:(bool)roundPositions
{
	pango_context_set_round_glyph_positions([self CONTEXT], roundPositions);
}


@end