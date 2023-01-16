/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoLayout.h"

#import "OGPangoContext.h"

@implementation OGPangoLayout

+ (OGPangoLayout*)deserializeWithContext:(OGPangoContext*)context bytes:(GBytes*)bytes flags:(PangoLayoutDeserializeFlags)flags err:(GError**)err
{
	return [[[OGPangoLayout alloc] initWithGObject:(GObject*)pango_layout_deserialize([context CONTEXT], bytes, flags, err)] autorelease];
}

- (instancetype)init:(OGPangoContext*)context
{
	self = [super initWithGObject:(GObject*)pango_layout_new([context CONTEXT])];

	return self;
}

- (PangoLayout*)LAYOUT
{
	return PANGO_LAYOUT([self GOBJECT]);
}

- (void)contextChanged
{
	pango_layout_context_changed([self LAYOUT]);
}

- (OGPangoLayout*)copy
{
	return [[[OGPangoLayout alloc] initWithGObject:(GObject*)pango_layout_copy([self LAYOUT])] autorelease];
}

- (PangoAlignment)alignment
{
	return pango_layout_get_alignment([self LAYOUT]);
}

- (PangoAttrList*)attributes
{
	return pango_layout_get_attributes([self LAYOUT]);
}

- (bool)autoDir
{
	return pango_layout_get_auto_dir([self LAYOUT]);
}

- (int)baseline
{
	return pango_layout_get_baseline([self LAYOUT]);
}

- (void)caretPosWithIndex:(int)index strongPos:(PangoRectangle*)strongPos weakPos:(PangoRectangle*)weakPos
{
	pango_layout_get_caret_pos([self LAYOUT], index, strongPos, weakPos);
}

- (gint)characterCount
{
	return pango_layout_get_character_count([self LAYOUT]);
}

- (OGPangoContext*)context
{
	return [[[OGPangoContext alloc] initWithGObject:(GObject*)pango_layout_get_context([self LAYOUT])] autorelease];
}

- (void)cursorPosWithIndex:(int)index strongPos:(PangoRectangle*)strongPos weakPos:(PangoRectangle*)weakPos
{
	pango_layout_get_cursor_pos([self LAYOUT], index, strongPos, weakPos);
}

- (PangoDirection)direction:(int)index
{
	return pango_layout_get_direction([self LAYOUT], index);
}

- (PangoEllipsizeMode)ellipsize
{
	return pango_layout_get_ellipsize([self LAYOUT]);
}

- (void)extentsWithInkRect:(PangoRectangle*)inkRect logicalRect:(PangoRectangle*)logicalRect
{
	pango_layout_get_extents([self LAYOUT], inkRect, logicalRect);
}

- (const PangoFontDescription*)fontDescription
{
	return pango_layout_get_font_description([self LAYOUT]);
}

- (int)height
{
	return pango_layout_get_height([self LAYOUT]);
}

- (int)indent
{
	return pango_layout_get_indent([self LAYOUT]);
}

- (PangoLayoutIter*)iter
{
	return pango_layout_get_iter([self LAYOUT]);
}

- (bool)justify
{
	return pango_layout_get_justify([self LAYOUT]);
}

- (bool)justifyLastLine
{
	return pango_layout_get_justify_last_line([self LAYOUT]);
}

- (PangoLayoutLine*)line:(int)line
{
	return pango_layout_get_line([self LAYOUT], line);
}

- (int)lineCount
{
	return pango_layout_get_line_count([self LAYOUT]);
}

- (PangoLayoutLine*)lineReadonly:(int)line
{
	return pango_layout_get_line_readonly([self LAYOUT], line);
}

- (float)lineSpacing
{
	return pango_layout_get_line_spacing([self LAYOUT]);
}

- (GSList*)lines
{
	return pango_layout_get_lines([self LAYOUT]);
}

- (GSList*)linesReadonly
{
	return pango_layout_get_lines_readonly([self LAYOUT]);
}

- (void)logAttrsWithAttrs:(PangoLogAttr**)attrs nattrs:(gint*)nattrs
{
	pango_layout_get_log_attrs([self LAYOUT], attrs, nattrs);
}

- (const PangoLogAttr*)logAttrsReadonly:(gint*)nattrs
{
	return pango_layout_get_log_attrs_readonly([self LAYOUT], nattrs);
}

- (void)pixelExtentsWithInkRect:(PangoRectangle*)inkRect logicalRect:(PangoRectangle*)logicalRect
{
	pango_layout_get_pixel_extents([self LAYOUT], inkRect, logicalRect);
}

- (void)pixelSizeWithWidth:(int*)width height:(int*)height
{
	pango_layout_get_pixel_size([self LAYOUT], width, height);
}

- (guint)serial
{
	return pango_layout_get_serial([self LAYOUT]);
}

- (bool)singleParagraphMode
{
	return pango_layout_get_single_paragraph_mode([self LAYOUT]);
}

- (void)sizeWithWidth:(int*)width height:(int*)height
{
	pango_layout_get_size([self LAYOUT], width, height);
}

- (int)spacing
{
	return pango_layout_get_spacing([self LAYOUT]);
}

- (PangoTabArray*)tabs
{
	return pango_layout_get_tabs([self LAYOUT]);
}

- (OFString*)text
{
	return [OFString stringWithUTF8String:pango_layout_get_text([self LAYOUT])];
}

- (int)unknownGlyphsCount
{
	return pango_layout_get_unknown_glyphs_count([self LAYOUT]);
}

- (int)width
{
	return pango_layout_get_width([self LAYOUT]);
}

- (PangoWrapMode)wrap
{
	return pango_layout_get_wrap([self LAYOUT]);
}

- (void)indexToLineXWithIndex:(int)index trailing:(bool)trailing line:(int*)line xpos:(int*)xpos
{
	pango_layout_index_to_line_x([self LAYOUT], index, trailing, line, xpos);
}

- (void)indexToPosWithIndex:(int)index pos:(PangoRectangle*)pos
{
	pango_layout_index_to_pos([self LAYOUT], index, pos);
}

- (bool)isEllipsized
{
	return pango_layout_is_ellipsized([self LAYOUT]);
}

- (bool)isWrapped
{
	return pango_layout_is_wrapped([self LAYOUT]);
}

- (void)moveCursorVisuallyWithStrong:(bool)strong oldIndex:(int)oldIndex oldTrailing:(int)oldTrailing direction:(int)direction newIndex:(int*)newIndex newTrailing:(int*)newTrailing
{
	pango_layout_move_cursor_visually([self LAYOUT], strong, oldIndex, oldTrailing, direction, newIndex, newTrailing);
}

- (GBytes*)serialize:(PangoLayoutSerializeFlags)flags
{
	return pango_layout_serialize([self LAYOUT], flags);
}

- (void)setAlignment:(PangoAlignment)alignment
{
	pango_layout_set_alignment([self LAYOUT], alignment);
}

- (void)setAttributes:(PangoAttrList*)attrs
{
	pango_layout_set_attributes([self LAYOUT], attrs);
}

- (void)setAutoDir:(bool)autoDir
{
	pango_layout_set_auto_dir([self LAYOUT], autoDir);
}

- (void)setEllipsize:(PangoEllipsizeMode)ellipsize
{
	pango_layout_set_ellipsize([self LAYOUT], ellipsize);
}

- (void)setFontDescription:(const PangoFontDescription*)desc
{
	pango_layout_set_font_description([self LAYOUT], desc);
}

- (void)setHeight:(int)height
{
	pango_layout_set_height([self LAYOUT], height);
}

- (void)setIndent:(int)indent
{
	pango_layout_set_indent([self LAYOUT], indent);
}

- (void)setJustify:(bool)justify
{
	pango_layout_set_justify([self LAYOUT], justify);
}

- (void)setJustifyLastLine:(bool)justify
{
	pango_layout_set_justify_last_line([self LAYOUT], justify);
}

- (void)setLineSpacing:(float)factor
{
	pango_layout_set_line_spacing([self LAYOUT], factor);
}

- (void)setMarkupWithMarkup:(OFString*)markup length:(int)length
{
	pango_layout_set_markup([self LAYOUT], [markup UTF8String], length);
}

- (void)setMarkupWithAccelWithMarkup:(OFString*)markup length:(int)length accelMarker:(gunichar)accelMarker accelChar:(gunichar*)accelChar
{
	pango_layout_set_markup_with_accel([self LAYOUT], [markup UTF8String], length, accelMarker, accelChar);
}

- (void)setSingleParagraphMode:(bool)setting
{
	pango_layout_set_single_paragraph_mode([self LAYOUT], setting);
}

- (void)setSpacing:(int)spacing
{
	pango_layout_set_spacing([self LAYOUT], spacing);
}

- (void)setTabs:(PangoTabArray*)tabs
{
	pango_layout_set_tabs([self LAYOUT], tabs);
}

- (void)setTextWithText:(OFString*)text length:(int)length
{
	pango_layout_set_text([self LAYOUT], [text UTF8String], length);
}

- (void)setWidth:(int)width
{
	pango_layout_set_width([self LAYOUT], width);
}

- (void)setWrap:(PangoWrapMode)wrap
{
	pango_layout_set_wrap([self LAYOUT], wrap);
}

- (bool)writeToFileWithFlags:(PangoLayoutSerializeFlags)flags filename:(OFString*)filename err:(GError**)err
{
	return pango_layout_write_to_file([self LAYOUT], flags, [filename UTF8String], err);
}

- (bool)xyToIndexWithX:(int)x y:(int)y index:(int*)index trailing:(int*)trailing
{
	return pango_layout_xy_to_index([self LAYOUT], x, y, index, trailing);
}


@end