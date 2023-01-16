/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <pango/pango.h>

#import <OGObject/OGObject.h>

@class OGPangoLayout;
@class OGPangoFont;

/**
 * #PangoRenderer is a base class for objects that are used to
 * render Pango objects such as #PangoGlyphString and
 * #PangoLayout.
 *
 */
@interface OGPangoRenderer : OGObject
{

}


/**
 * Methods
 */

- (PangoRenderer*)RENDERER;

/**
 * Does initial setup before rendering operations on @renderer.
 * pango_renderer_deactivate() should be called when done drawing.
 * Calls such as pango_renderer_draw_layout() automatically
 * activate the layout before drawing on it. Calls to
 * pango_renderer_activate() and pango_renderer_deactivate() can
 * be nested and the renderer will only be initialized and
 * deinitialized once.
 *
 */
- (void)activate;

/**
 * Cleans up after rendering operations on @renderer. See
 * docs for pango_renderer_activate().
 *
 */
- (void)deactivate;

/**
 * Draw a squiggly line that approximately covers the given rectangle
 * in the style of an underline used to indicate a spelling error.
 * (The width of the underline is rounded to an integer number
 * of up/down segments and the resulting rectangle is centered
 * in the original rectangle)
 * 
 * This should be called while @renderer is already active.  Use
 * pango_renderer_activate() to activate a renderer.
 *
 * @param x X coordinate of underline, in Pango units in user coordinate system
 * @param y Y coordinate of underline, in Pango units in user coordinate system
 * @param width width of underline, in Pango units in user coordinate system
 * @param height height of underline, in Pango units in user coordinate system
 */
- (void)drawErrorUnderlineWithX:(int)x y:(int)y width:(int)width height:(int)height;

/**
 * Draws a single glyph with coordinates in device space.
 *
 * @param font a #PangoFont
 * @param glyph the glyph index of a single glyph
 * @param x X coordinate of left edge of baseline of glyph
 * @param y Y coordinate of left edge of baseline of glyph
 */
- (void)drawGlyphWithFont:(OGPangoFont*)font glyph:(PangoGlyph)glyph x:(double)x y:(double)y;

/**
 * Draws the glyphs in @glyph_item with the specified #PangoRenderer,
 * embedding the text associated with the glyphs in the output if the
 * output format supports it (PDF for example).
 * 
 * Note that @text is the start of the text for layout, which is then
 * indexed by <literal>@glyph_item->item->offset</literal>.
 * 
 * If @text is %NULL, this simply calls pango_renderer_draw_glyphs().
 * 
 * The default implementation of this method simply falls back to
 * pango_renderer_draw_glyphs().
 *
 * @param text the UTF-8 text that @glyph_item refers to, or %NULL
 * @param glyphItem a #PangoGlyphItem
 * @param x X position of left edge of baseline, in user space coordinates
 *   in Pango units.
 * @param y Y position of left edge of baseline, in user space coordinates
 *    in Pango units.
 */
- (void)drawGlyphItemWithText:(OFString*)text glyphItem:(PangoGlyphItem*)glyphItem x:(int)x y:(int)y;

/**
 * Draws the glyphs in @glyphs with the specified #PangoRenderer.
 *
 * @param font a #PangoFont
 * @param glyphs a #PangoGlyphString
 * @param x X position of left edge of baseline, in user space coordinates
 *   in Pango units.
 * @param y Y position of left edge of baseline, in user space coordinates
 *    in Pango units.
 */
- (void)drawGlyphsWithFont:(OGPangoFont*)font glyphs:(PangoGlyphString*)glyphs x:(int)x y:(int)y;

/**
 * Draws @layout with the specified #PangoRenderer.
 *
 * @param layout a #PangoLayout
 * @param x X position of left edge of baseline, in user space coordinates
 *   in Pango units.
 * @param y Y position of left edge of baseline, in user space coordinates
 *    in Pango units.
 */
- (void)drawLayoutWithLayout:(OGPangoLayout*)layout x:(int)x y:(int)y;

/**
 * Draws @line with the specified #PangoRenderer.
 *
 * @param line a #PangoLayoutLine
 * @param x X position of left edge of baseline, in user space coordinates
 *   in Pango units.
 * @param y Y position of left edge of baseline, in user space coordinates
 *    in Pango units.
 */
- (void)drawLayoutLineWithLine:(PangoLayoutLine*)line x:(int)x y:(int)y;

/**
 * Draws an axis-aligned rectangle in user space coordinates with the
 * specified #PangoRenderer.
 * 
 * This should be called while @renderer is already active.  Use
 * pango_renderer_activate() to activate a renderer.
 *
 * @param part type of object this rectangle is part of
 * @param x X position at which to draw rectangle, in user space coordinates in Pango units
 * @param y Y position at which to draw rectangle, in user space coordinates in Pango units
 * @param width width of rectangle in Pango units in user space coordinates
 * @param height height of rectangle in Pango units in user space coordinates
 */
- (void)drawRectangleWithPart:(PangoRenderPart)part x:(int)x y:(int)y width:(int)width height:(int)height;

/**
 * Draws a trapezoid with the parallel sides aligned with the X axis
 * using the given #PangoRenderer; coordinates are in device space.
 *
 * @param part type of object this trapezoid is part of
 * @param y1 Y coordinate of top of trapezoid
 * @param x11 X coordinate of left end of top of trapezoid
 * @param x21 X coordinate of right end of top of trapezoid
 * @param y2 Y coordinate of bottom of trapezoid
 * @param x12 X coordinate of left end of bottom of trapezoid
 * @param x22 X coordinate of right end of bottom of trapezoid
 */
- (void)drawTrapezoidWithPart:(PangoRenderPart)part y1:(double)y1 x11:(double)x11 x21:(double)x21 y2:(double)y2 x12:(double)x12 x22:(double)x22;

/**
 * Gets the current alpha for the specified part.
 *
 * @param part the part to get the alpha for
 * @return the alpha for the specified part,
 *   or 0 if it hasn't been set and should be
 *   inherited from the environment.
 */
- (guint16)alpha:(PangoRenderPart)part;

/**
 * Gets the current rendering color for the specified part.
 *
 * @param part the part to get the color for
 * @return the color for the
 *   specified part, or %NULL if it hasn't been set and should be
 *   inherited from the environment.
 */
- (PangoColor*)color:(PangoRenderPart)part;

/**
 * Gets the layout currently being rendered using @renderer.
 * Calling this function only makes sense from inside a subclass's
 * methods, like in its draw_shape vfunc, for example.
 * 
 * The returned layout should not be modified while still being
 * rendered.
 *
 * @return the layout, or %NULL if
 *  no layout is being rendered using @renderer at this time.
 */
- (OGPangoLayout*)layout;

/**
 * Gets the layout line currently being rendered using @renderer.
 * Calling this function only makes sense from inside a subclass's
 * methods, like in its draw_shape vfunc, for example.
 * 
 * The returned layout line should not be modified while still being
 * rendered.
 *
 * @return the layout line, or %NULL
 *   if no layout line is being rendered using @renderer at this time.
 */
- (PangoLayoutLine*)layoutLine;

/**
 * Gets the transformation matrix that will be applied when
 * rendering. See pango_renderer_set_matrix().
 *
 * @return the matrix, or %NULL if no matrix has
 *  been set (which is the same as the identity matrix). The returned
 *  matrix is owned by Pango and must not be modified or freed.
 */
- (const PangoMatrix*)matrix;

/**
 * Informs Pango that the way that the rendering is done
 * for @part has changed in a way that would prevent multiple
 * pieces being joined together into one drawing call. For
 * instance, if a subclass of #PangoRenderer was to add a stipple
 * option for drawing underlines, it needs to call
 * 
 * <informalexample><programlisting>
 * pango_renderer_part_changed (render, PANGO_RENDER_PART_UNDERLINE);
 * </programlisting></informalexample>
 * 
 * When the stipple changes or underlines with different stipples
 * might be joined together. Pango automatically calls this for
 * changes to colors. (See pango_renderer_set_color())
 *
 * @param part the part for which rendering has changed.
 */
- (void)partChanged:(PangoRenderPart)part;

/**
 * Sets the alpha for part of the rendering.
 * Note that the alpha may only be used if a color is
 * specified for @part as well.
 *
 * @param part the part to set the alpha for
 * @param alpha an alpha value between 1 and 65536, or 0 to unset the alpha
 */
- (void)setAlphaWithPart:(PangoRenderPart)part alpha:(guint16)alpha;

/**
 * Sets the color for part of the rendering.
 * Also see pango_renderer_set_alpha().
 *
 * @param part the part to change the color of
 * @param color the new color or %NULL to unset the current color
 */
- (void)setColorWithPart:(PangoRenderPart)part color:(const PangoColor*)color;

/**
 * Sets the transformation matrix that will be applied when rendering.
 *
 * @param matrix a #PangoMatrix, or %NULL to unset any existing matrix.
 *  (No matrix set is the same as setting the identity matrix.)
 */
- (void)setMatrix:(const PangoMatrix*)matrix;

@end