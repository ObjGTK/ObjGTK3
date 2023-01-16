/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKImage.h"

#import "OGTKWidget.h"
#import <OGGdkPixbuf/OGGdkPixbufAnimation.h>
#import <OGGdkPixbuf/OGGdkPixbuf.h>

@implementation OGTKImage

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_image_new()];

	return self;
}

- (instancetype)initFromAnimation:(OGGdkPixbufAnimation*)animation
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_animation([animation PIXBUFANIMATION])];

	return self;
}

- (instancetype)initFromFile:(OFString*)filename
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_file([filename UTF8String])];

	return self;
}

- (instancetype)initFromGiconWithIcon:(GIcon*)icon size:(GtkIconSize)size
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_gicon(icon, size)];

	return self;
}

- (instancetype)initFromIconNameWithIconName:(OFString*)iconName size:(GtkIconSize)size
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_icon_name([iconName UTF8String], size)];

	return self;
}

- (instancetype)initFromIconSetWithIconSet:(GtkIconSet*)iconSet size:(GtkIconSize)size
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_icon_set(iconSet, size)];

	return self;
}

- (instancetype)initFromPixbuf:(OGGdkPixbuf*)pixbuf
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_pixbuf([pixbuf PIXBUF])];

	return self;
}

- (instancetype)initFromResource:(OFString*)resourcePath
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_resource([resourcePath UTF8String])];

	return self;
}

- (instancetype)initFromStockWithStockId:(OFString*)stockId size:(GtkIconSize)size
{
	self = [super initWithGObject:(GObject*)gtk_image_new_from_stock([stockId UTF8String], size)];

	return self;
}

- (instancetype)initFromSurface:(cairo_surface_t*)surface
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
	gtk_image_clear([self IMAGE]);
}

- (OGGdkPixbufAnimation*)animation
{
	return [[[OGGdkPixbufAnimation alloc] initWithGObject:(GObject*)gtk_image_get_animation([self IMAGE])] autorelease];
}

- (void)giconWithGicon:(GIcon**)gicon size:(GtkIconSize*)size
{
	gtk_image_get_gicon([self IMAGE], gicon, size);
}

- (void)iconNameWithIconName:(const gchar**)iconName size:(GtkIconSize*)size
{
	gtk_image_get_icon_name([self IMAGE], iconName, size);
}

- (void)iconSetWithIconSet:(GtkIconSet**)iconSet size:(GtkIconSize*)size
{
	gtk_image_get_icon_set([self IMAGE], iconSet, size);
}

- (OGGdkPixbuf*)pixbuf
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_image_get_pixbuf([self IMAGE])] autorelease];
}

- (gint)pixelSize
{
	return gtk_image_get_pixel_size([self IMAGE]);
}

- (void)stockWithStockId:(gchar**)stockId size:(GtkIconSize*)size
{
	gtk_image_get_stock([self IMAGE], stockId, size);
}

- (GtkImageType)storageType
{
	return gtk_image_get_storage_type([self IMAGE]);
}

- (void)setFromAnimation:(OGGdkPixbufAnimation*)animation
{
	gtk_image_set_from_animation([self IMAGE], [animation PIXBUFANIMATION]);
}

- (void)setFromFile:(OFString*)filename
{
	gtk_image_set_from_file([self IMAGE], [filename UTF8String]);
}

- (void)setFromGiconWithIcon:(GIcon*)icon size:(GtkIconSize)size
{
	gtk_image_set_from_gicon([self IMAGE], icon, size);
}

- (void)setFromIconNameWithIconName:(OFString*)iconName size:(GtkIconSize)size
{
	gtk_image_set_from_icon_name([self IMAGE], [iconName UTF8String], size);
}

- (void)setFromIconSetWithIconSet:(GtkIconSet*)iconSet size:(GtkIconSize)size
{
	gtk_image_set_from_icon_set([self IMAGE], iconSet, size);
}

- (void)setFromPixbuf:(OGGdkPixbuf*)pixbuf
{
	gtk_image_set_from_pixbuf([self IMAGE], [pixbuf PIXBUF]);
}

- (void)setFromResource:(OFString*)resourcePath
{
	gtk_image_set_from_resource([self IMAGE], [resourcePath UTF8String]);
}

- (void)setFromStockWithStockId:(OFString*)stockId size:(GtkIconSize)size
{
	gtk_image_set_from_stock([self IMAGE], [stockId UTF8String], size);
}

- (void)setFromSurface:(cairo_surface_t*)surface
{
	gtk_image_set_from_surface([self IMAGE], surface);
}

- (void)setPixelSize:(gint)pixelSize
{
	gtk_image_set_pixel_size([self IMAGE], pixelSize);
}


@end