/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoFontsetSimple.h"

#import "OGPangoFont.h"

@implementation OGPangoFontsetSimple

- (instancetype)init:(PangoLanguage*)language
{
	self = [super initWithGObject:(GObject*)pango_fontset_simple_new(language)];

	return self;
}

- (PangoFontsetSimple*)FONTSETSIMPLE
{
	return PANGO_FONTSET_SIMPLE([self GOBJECT]);
}

- (void)append:(OGPangoFont*)font
{
	pango_fontset_simple_append([self FONTSETSIMPLE], [font FONT]);
}

- (int)size
{
	return pango_fontset_simple_size([self FONTSETSIMPLE]);
}


@end