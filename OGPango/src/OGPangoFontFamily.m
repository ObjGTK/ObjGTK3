/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoFontFamily.h"

#import "OGPangoFontFace.h"

@implementation OGPangoFontFamily

- (PangoFontFamily*)FONTFAMILY
{
	return PANGO_FONT_FAMILY([self GOBJECT]);
}

- (OGPangoFontFace*)face:(OFString*)name
{
	return [[[OGPangoFontFace alloc] initWithGObject:(GObject*)pango_font_family_get_face([self FONTFAMILY], [name UTF8String])] autorelease];
}

- (OFString*)name
{
	return [OFString stringWithUTF8String:pango_font_family_get_name([self FONTFAMILY])];
}

- (bool)isMonospace
{
	return pango_font_family_is_monospace([self FONTFAMILY]);
}

- (bool)isVariable
{
	return pango_font_family_is_variable([self FONTFAMILY]);
}

- (void)listFacesWithFaces:(PangoFontFace***)faces nfaces:(int*)nfaces
{
	pango_font_family_list_faces([self FONTFAMILY], faces, nfaces);
}


@end