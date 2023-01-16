/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoFontMap.h"

#import "OGPangoFontFamily.h"
#import "OGPangoContext.h"
#import "OGPangoFont.h"
#import "OGPangoFontset.h"

@implementation OGPangoFontMap

- (PangoFontMap*)FONTMAP
{
	return PANGO_FONT_MAP([self GOBJECT]);
}

- (void)changed
{
	pango_font_map_changed([self FONTMAP]);
}

- (OGPangoContext*)createContext
{
	return [[[OGPangoContext alloc] initWithGObject:(GObject*)pango_font_map_create_context([self FONTMAP])] autorelease];
}

- (OGPangoFontFamily*)family:(OFString*)name
{
	return [[[OGPangoFontFamily alloc] initWithGObject:(GObject*)pango_font_map_get_family([self FONTMAP], [name UTF8String])] autorelease];
}

- (guint)serial
{
	return pango_font_map_get_serial([self FONTMAP]);
}

- (void)listFamiliesWithFamilies:(PangoFontFamily***)families nfamilies:(int*)nfamilies
{
	pango_font_map_list_families([self FONTMAP], families, nfamilies);
}

- (OGPangoFont*)loadFontWithContext:(OGPangoContext*)context desc:(const PangoFontDescription*)desc
{
	return [[[OGPangoFont alloc] initWithGObject:(GObject*)pango_font_map_load_font([self FONTMAP], [context CONTEXT], desc)] autorelease];
}

- (OGPangoFontset*)loadFontsetWithContext:(OGPangoContext*)context desc:(const PangoFontDescription*)desc language:(PangoLanguage*)language
{
	return [[[OGPangoFontset alloc] initWithGObject:(GObject*)pango_font_map_load_fontset([self FONTMAP], [context CONTEXT], desc, language)] autorelease];
}


@end