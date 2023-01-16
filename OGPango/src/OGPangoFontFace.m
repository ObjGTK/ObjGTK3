/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoFontFace.h"

#import "OGPangoFontFamily.h"

@implementation OGPangoFontFace

- (PangoFontFace*)FONTFACE
{
	return PANGO_FONT_FACE([self GOBJECT]);
}

- (PangoFontDescription*)describe
{
	return pango_font_face_describe([self FONTFACE]);
}

- (OFString*)faceName
{
	return [OFString stringWithUTF8String:pango_font_face_get_face_name([self FONTFACE])];
}

- (OGPangoFontFamily*)family
{
	return [[[OGPangoFontFamily alloc] initWithGObject:(GObject*)pango_font_face_get_family([self FONTFACE])] autorelease];
}

- (bool)isSynthesized
{
	return pango_font_face_is_synthesized([self FONTFACE]);
}

- (void)listSizesWithSizes:(int**)sizes nsizes:(int*)nsizes
{
	pango_font_face_list_sizes([self FONTFACE], sizes, nsizes);
}


@end