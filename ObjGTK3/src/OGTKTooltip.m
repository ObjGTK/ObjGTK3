/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTooltip.h"

#import <OGGdkPixbuf/OGGdkPixbuf.h>
#import <OGdk3/OGGdkDisplay.h>
#import "OGTKWidget.h"

@implementation OGTKTooltip

+ (void)triggerTooltipQuery:(OGGdkDisplay*)display
{
	gtk_tooltip_trigger_tooltip_query([display DISPLAY]);
}

- (GtkTooltip*)TOOLTIP
{
	return GTK_TOOLTIP([self GOBJECT]);
}

- (void)setCustom:(OGTKWidget*)customWidget
{
	gtk_tooltip_set_custom([self TOOLTIP], [customWidget WIDGET]);
}

- (void)setIcon:(OGGdkPixbuf*)pixbuf
{
	gtk_tooltip_set_icon([self TOOLTIP], [pixbuf PIXBUF]);
}

- (void)setIconFromGiconWithGicon:(GIcon*)gicon size:(GtkIconSize)size
{
	gtk_tooltip_set_icon_from_gicon([self TOOLTIP], gicon, size);
}

- (void)setIconFromIconNameWithIconName:(OFString*)iconName size:(GtkIconSize)size
{
	gtk_tooltip_set_icon_from_icon_name([self TOOLTIP], [iconName UTF8String], size);
}

- (void)setIconFromStockWithStockId:(OFString*)stockId size:(GtkIconSize)size
{
	gtk_tooltip_set_icon_from_stock([self TOOLTIP], [stockId UTF8String], size);
}

- (void)setMarkup:(OFString*)markup
{
	gtk_tooltip_set_markup([self TOOLTIP], [markup UTF8String]);
}

- (void)setText:(OFString*)text
{
	gtk_tooltip_set_text([self TOOLTIP], [text UTF8String]);
}

- (void)setTipArea:(const GdkRectangle*)rect
{
	gtk_tooltip_set_tip_area([self TOOLTIP], rect);
}


@end