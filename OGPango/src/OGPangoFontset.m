/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGPangoFontset.h"

#import "OGPangoFont.h"

@implementation OGPangoFontset

- (PangoFontset*)FONTSET
{
	return PANGO_FONTSET([self GOBJECT]);
}

- (void)foreachWithFunc:(PangoFontsetForeachFunc)func data:(gpointer)data
{
	pango_fontset_foreach([self FONTSET], func, data);
}

- (OGPangoFont*)font:(guint)wc
{
	return [[[OGPangoFont alloc] initWithGObject:(GObject*)pango_fontset_get_font([self FONTSET], wc)] autorelease];
}

- (PangoFontMetrics*)metrics
{
	return pango_fontset_get_metrics([self FONTSET]);
}


@end