/*
 * OGTKImage.m
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
#import "OGTKImage.h"

@implementation OGTKImage

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_image_new()];

	return self;
}

- (id)initFromAnimation:(GdkPixbufAnimation*)animation
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_animation(animation)];

	return self;
}

- (id)initFromFile:(OFString*)filename
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_file([filename UTF8String])];

	return self;
}

- (id)initFromGiconWithIcon:(GIcon*)icon andSize:(GtkIconSize)size
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_gicon(icon, size)];

	return self;
}

- (id)initFromIconNameWithIconName:(OFString*)iconName andSize:(GtkIconSize)size
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_icon_name([iconName UTF8String], size)];

	return self;
}

- (id)initFromIconSetWithIconSet:(GtkIconSet*)iconSet andSize:(GtkIconSize)size
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_icon_set(iconSet, size)];

	return self;
}

- (id)initFromPixbuf:(GdkPixbuf*)pixbuf
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_pixbuf(pixbuf)];

	return self;
}

- (id)initFromResource:(OFString*)resourcePath
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_resource([resourcePath UTF8String])];

	return self;
}

- (id)initFromStockWithStockId:(OFString*)stockId andSize:(GtkIconSize)size
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_stock([stockId UTF8String], size)];

	return self;
}

- (id)initFromSurface:(cairo_surface_t*)surface
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_surface(surface)];

	return self;
}

- (GtkImage*)IMAGE
{
	return GTK_IMAGE([self GOBJECT]);
}

- (void)clear
{
	gtk_image_clear(GTK_IMAGE([self GOBJECT]));
}

- (GdkPixbufAnimation*)getAnimation
{
	return gtk_image_get_animation(GTK_IMAGE([self GOBJECT]));
}

- (void)getGiconWithGicon:(GIcon**)gicon andSize:(GtkIconSize*)size
{
	gtk_image_get_gicon(GTK_IMAGE([self GOBJECT]), gicon, size);
}

- (void)getIconNameWithIconName:(const gchar**)iconName andSize:(GtkIconSize*)size
{
	gtk_image_get_icon_name(GTK_IMAGE([self GOBJECT]), iconName, size);
}

- (void)getIconSetWithIconSet:(GtkIconSet**)iconSet andSize:(GtkIconSize*)size
{
	gtk_image_get_icon_set(GTK_IMAGE([self GOBJECT]), iconSet, size);
}

- (GdkPixbuf*)getPixbuf
{
	return gtk_image_get_pixbuf(GTK_IMAGE([self GOBJECT]));
}

- (gint)getPixelSize
{
	return gtk_image_get_pixel_size(GTK_IMAGE([self GOBJECT]));
}

- (void)getStockWithStockId:(gchar**)stockId andSize:(GtkIconSize*)size
{
	gtk_image_get_stock(GTK_IMAGE([self GOBJECT]), stockId, size);
}

- (GtkImageType)getStorageType
{
	return gtk_image_get_storage_type(GTK_IMAGE([self GOBJECT]));
}

- (void)setFromAnimation:(GdkPixbufAnimation*)animation
{
	gtk_image_set_from_animation(GTK_IMAGE([self GOBJECT]), animation);
}

- (void)setFromFile:(OFString*)filename
{
	gtk_image_set_from_file(GTK_IMAGE([self GOBJECT]), [filename UTF8String]);
}

- (void)setFromGiconWithIcon:(GIcon*)icon andSize:(GtkIconSize)size
{
	gtk_image_set_from_gicon(GTK_IMAGE([self GOBJECT]), icon, size);
}

- (void)setFromIconNameWithIconName:(OFString*)iconName andSize:(GtkIconSize)size
{
	gtk_image_set_from_icon_name(GTK_IMAGE([self GOBJECT]), [iconName UTF8String], size);
}

- (void)setFromIconSetWithIconSet:(GtkIconSet*)iconSet andSize:(GtkIconSize)size
{
	gtk_image_set_from_icon_set(GTK_IMAGE([self GOBJECT]), iconSet, size);
}

- (void)setFromPixbuf:(GdkPixbuf*)pixbuf
{
	gtk_image_set_from_pixbuf(GTK_IMAGE([self GOBJECT]), pixbuf);
}

- (void)setFromResource:(OFString*)resourcePath
{
	gtk_image_set_from_resource(GTK_IMAGE([self GOBJECT]), [resourcePath UTF8String]);
}

- (void)setFromStockWithStockId:(OFString*)stockId andSize:(GtkIconSize)size
{
	gtk_image_set_from_stock(GTK_IMAGE([self GOBJECT]), [stockId UTF8String], size);
}

- (void)setFromSurface:(cairo_surface_t*)surface
{
	gtk_image_set_from_surface(GTK_IMAGE([self GOBJECT]), surface);
}

- (void)setPixelSize:(gint)pixelSize
{
	gtk_image_set_pixel_size(GTK_IMAGE([self GOBJECT]), pixelSize);
}


@end