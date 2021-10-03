/*
 * OGTKTooltip.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKTooltip.h"

@implementation OGTKTooltip

+ (void)triggerTooltipQuery:(GdkDisplay*)display
{
	gtk_tooltip_trigger_tooltip_query(display);
}

- (GtkTooltip*)TOOLTIP
{
	return GTK_TOOLTIP([self GOBJECT]);
}

- (void)setCustom:(OGTKWidget*)customWidget
{
	gtk_tooltip_set_custom(GTK_TOOLTIP([self GOBJECT]), [customWidget WIDGET]);
}

- (void)setIcon:(GdkPixbuf*)pixbuf
{
	gtk_tooltip_set_icon(GTK_TOOLTIP([self GOBJECT]), pixbuf);
}

- (void)setIconFromGiconWithGicon:(GIcon*)gicon andSize:(GtkIconSize)size
{
	gtk_tooltip_set_icon_from_gicon(GTK_TOOLTIP([self GOBJECT]), gicon, size);
}

- (void)setIconFromIconNameWithIconName:(OFString*)iconName andSize:(GtkIconSize)size
{
	gtk_tooltip_set_icon_from_icon_name(GTK_TOOLTIP([self GOBJECT]), [iconName UTF8String], size);
}

- (void)setIconFromStockWithStockId:(OFString*)stockId andSize:(GtkIconSize)size
{
	gtk_tooltip_set_icon_from_stock(GTK_TOOLTIP([self GOBJECT]), [stockId UTF8String], size);
}

- (void)setMarkup:(OFString*)markup
{
	gtk_tooltip_set_markup(GTK_TOOLTIP([self GOBJECT]), [markup UTF8String]);
}

- (void)setText:(OFString*)text
{
	gtk_tooltip_set_text(GTK_TOOLTIP([self GOBJECT]), [text UTF8String]);
}

- (void)setTipArea:(const GdkRectangle*)rect
{
	gtk_tooltip_set_tip_area(GTK_TOOLTIP([self GOBJECT]), rect);
}


@end