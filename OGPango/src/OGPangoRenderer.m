/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoRenderer.h"

#import "OGPangoFont.h"
#import "OGPangoLayout.h"

@implementation OGPangoRenderer

- (PangoRenderer*)RENDERER
{
	return PANGO_RENDERER([self GOBJECT]);
}

- (void)activate
{
	pango_renderer_activate([self RENDERER]);
}

- (void)deactivate
{
	pango_renderer_deactivate([self RENDERER]);
}

- (void)drawErrorUnderlineWithX:(int)x y:(int)y width:(int)width height:(int)height
{
	pango_renderer_draw_error_underline([self RENDERER], x, y, width, height);
}

- (void)drawGlyphWithFont:(OGPangoFont*)font glyph:(PangoGlyph)glyph x:(double)x y:(double)y
{
	pango_renderer_draw_glyph([self RENDERER], [font FONT], glyph, x, y);
}

- (void)drawGlyphItemWithText:(OFString*)text glyphItem:(PangoGlyphItem*)glyphItem x:(int)x y:(int)y
{
	pango_renderer_draw_glyph_item([self RENDERER], [text UTF8String], glyphItem, x, y);
}

- (void)drawGlyphsWithFont:(OGPangoFont*)font glyphs:(PangoGlyphString*)glyphs x:(int)x y:(int)y
{
	pango_renderer_draw_glyphs([self RENDERER], [font FONT], glyphs, x, y);
}

- (void)drawLayoutWithLayout:(OGPangoLayout*)layout x:(int)x y:(int)y
{
	pango_renderer_draw_layout([self RENDERER], [layout LAYOUT], x, y);
}

- (void)drawLayoutLineWithLine:(PangoLayoutLine*)line x:(int)x y:(int)y
{
	pango_renderer_draw_layout_line([self RENDERER], line, x, y);
}

- (void)drawRectangleWithPart:(PangoRenderPart)part x:(int)x y:(int)y width:(int)width height:(int)height
{
	pango_renderer_draw_rectangle([self RENDERER], part, x, y, width, height);
}

- (void)drawTrapezoidWithPart:(PangoRenderPart)part y1:(double)y1 x11:(double)x11 x21:(double)x21 y2:(double)y2 x12:(double)x12 x22:(double)x22
{
	pango_renderer_draw_trapezoid([self RENDERER], part, y1, x11, x21, y2, x12, x22);
}

- (guint16)alpha:(PangoRenderPart)part
{
	return pango_renderer_get_alpha([self RENDERER], part);
}

- (PangoColor*)color:(PangoRenderPart)part
{
	return pango_renderer_get_color([self RENDERER], part);
}

- (OGPangoLayout*)layout
{
	return [[[OGPangoLayout alloc] initWithGObject:(GObject*)pango_renderer_get_layout([self RENDERER])] autorelease];
}

- (PangoLayoutLine*)layoutLine
{
	return pango_renderer_get_layout_line([self RENDERER]);
}

- (const PangoMatrix*)matrix
{
	return pango_renderer_get_matrix([self RENDERER]);
}

- (void)partChanged:(PangoRenderPart)part
{
	pango_renderer_part_changed([self RENDERER], part);
}

- (void)setAlphaWithPart:(PangoRenderPart)part alpha:(guint16)alpha
{
	pango_renderer_set_alpha([self RENDERER], part, alpha);
}

- (void)setColorWithPart:(PangoRenderPart)part color:(const PangoColor*)color
{
	pango_renderer_set_color([self RENDERER], part, color);
}

- (void)setMatrix:(const PangoMatrix*)matrix
{
	pango_renderer_set_matrix([self RENDERER], matrix);
}


@end