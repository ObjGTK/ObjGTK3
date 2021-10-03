/*
 * OGTKStatusIcon.m
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
#import "OGTKStatusIcon.h"

@implementation OGTKStatusIcon

+ (void)positionMenuWithMenu:(GtkMenu*)menu andX:(gint*)x andY:(gint*)y andPushIn:(gboolean*)pushIn andUserData:(gpointer)userData
{
	gtk_status_icon_position_menu(menu, x, y, pushIn, userData);
}

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_status_icon_new()];

	return self;
}

- (id)initFromFile:(OFString*)filename
{
	self = [super initWithGObject:(GObject*)gtk_status_icon_new_from_file([filename UTF8String])];

	return self;
}

- (id)initFromGicon:(GIcon*)icon
{
	self = [super initWithGObject:(GObject*)gtk_status_icon_new_from_gicon(icon)];

	return self;
}

- (id)initFromIconName:(OFString*)iconName
{
	self = [super initWithGObject:(GObject*)gtk_status_icon_new_from_icon_name([iconName UTF8String])];

	return self;
}

- (id)initFromPixbuf:(GdkPixbuf*)pixbuf
{
	self = [super initWithGObject:(GObject*)gtk_status_icon_new_from_pixbuf(pixbuf)];

	return self;
}

- (id)initFromStock:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_status_icon_new_from_stock([stockId UTF8String])];

	return self;
}

- (GtkStatusIcon*)STATUSICON
{
	return GTK_STATUS_ICON([self GOBJECT]);
}

- (bool)getGeometryWithScreen:(GdkScreen**)screen andArea:(GdkRectangle*)area andOrientation:(GtkOrientation*)orientation
{
	return gtk_status_icon_get_geometry(GTK_STATUS_ICON([self GOBJECT]), screen, area, orientation);
}

- (GIcon*)getGicon
{
	return gtk_status_icon_get_gicon(GTK_STATUS_ICON([self GOBJECT]));
}

- (bool)getHasTooltip
{
	return gtk_status_icon_get_has_tooltip(GTK_STATUS_ICON([self GOBJECT]));
}

- (OFString*)getIconName
{
	return [OFString stringWithUTF8String:gtk_status_icon_get_icon_name(GTK_STATUS_ICON([self GOBJECT]))];
}

- (GdkPixbuf*)getPixbuf
{
	return gtk_status_icon_get_pixbuf(GTK_STATUS_ICON([self GOBJECT]));
}

- (GdkScreen*)getScreen
{
	return gtk_status_icon_get_screen(GTK_STATUS_ICON([self GOBJECT]));
}

- (gint)getSize
{
	return gtk_status_icon_get_size(GTK_STATUS_ICON([self GOBJECT]));
}

- (OFString*)getStock
{
	return [OFString stringWithUTF8String:gtk_status_icon_get_stock(GTK_STATUS_ICON([self GOBJECT]))];
}

- (GtkImageType)getStorageType
{
	return gtk_status_icon_get_storage_type(GTK_STATUS_ICON([self GOBJECT]));
}

- (OFString*)getTitle
{
	return [OFString stringWithUTF8String:gtk_status_icon_get_title(GTK_STATUS_ICON([self GOBJECT]))];
}

- (OFString*)getTooltipMarkup
{
	return [OFString stringWithUTF8String:gtk_status_icon_get_tooltip_markup(GTK_STATUS_ICON([self GOBJECT]))];
}

- (OFString*)getTooltipText
{
	return [OFString stringWithUTF8String:gtk_status_icon_get_tooltip_text(GTK_STATUS_ICON([self GOBJECT]))];
}

- (bool)getVisible
{
	return gtk_status_icon_get_visible(GTK_STATUS_ICON([self GOBJECT]));
}

- (guint32)getX11WindowId
{
	return gtk_status_icon_get_x11_window_id(GTK_STATUS_ICON([self GOBJECT]));
}

- (bool)isEmbedded
{
	return gtk_status_icon_is_embedded(GTK_STATUS_ICON([self GOBJECT]));
}

- (void)setFromFile:(OFString*)filename
{
	gtk_status_icon_set_from_file(GTK_STATUS_ICON([self GOBJECT]), [filename UTF8String]);
}

- (void)setFromGicon:(GIcon*)icon
{
	gtk_status_icon_set_from_gicon(GTK_STATUS_ICON([self GOBJECT]), icon);
}

- (void)setFromIconName:(OFString*)iconName
{
	gtk_status_icon_set_from_icon_name(GTK_STATUS_ICON([self GOBJECT]), [iconName UTF8String]);
}

- (void)setFromPixbuf:(GdkPixbuf*)pixbuf
{
	gtk_status_icon_set_from_pixbuf(GTK_STATUS_ICON([self GOBJECT]), pixbuf);
}

- (void)setFromStock:(OFString*)stockId
{
	gtk_status_icon_set_from_stock(GTK_STATUS_ICON([self GOBJECT]), [stockId UTF8String]);
}

- (void)setHasTooltip:(bool)hasTooltip
{
	gtk_status_icon_set_has_tooltip(GTK_STATUS_ICON([self GOBJECT]), hasTooltip);
}

- (void)setName:(OFString*)name
{
	gtk_status_icon_set_name(GTK_STATUS_ICON([self GOBJECT]), [name UTF8String]);
}

- (void)setScreen:(GdkScreen*)screen
{
	gtk_status_icon_set_screen(GTK_STATUS_ICON([self GOBJECT]), screen);
}

- (void)setTitle:(OFString*)title
{
	gtk_status_icon_set_title(GTK_STATUS_ICON([self GOBJECT]), [title UTF8String]);
}

- (void)setTooltipMarkup:(OFString*)markup
{
	gtk_status_icon_set_tooltip_markup(GTK_STATUS_ICON([self GOBJECT]), [markup UTF8String]);
}

- (void)setTooltipText:(OFString*)text
{
	gtk_status_icon_set_tooltip_text(GTK_STATUS_ICON([self GOBJECT]), [text UTF8String]);
}

- (void)setVisible:(bool)visible
{
	gtk_status_icon_set_visible(GTK_STATUS_ICON([self GOBJECT]), visible);
}


@end