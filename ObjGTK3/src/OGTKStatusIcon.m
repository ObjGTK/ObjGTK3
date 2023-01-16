/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKStatusIcon.h"

#import <OGdk3/OGGdkScreen.h>
#import <OGGdkPixbuf/OGGdkPixbuf.h>
#import "OGTKMenu.h"

@implementation OGTKStatusIcon

+ (void)positionMenuWithMenu:(OGTKMenu*)menu x:(gint*)x y:(gint*)y pushIn:(gboolean*)pushIn userData:(gpointer)userData
{
	gtk_status_icon_position_menu([menu MENU], x, y, pushIn, userData);
}

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_status_icon_new()];

	return self;
}

- (instancetype)initFromFile:(OFString*)filename
{
	self = [super initWithGObject:(GObject*)gtk_status_icon_new_from_file([filename UTF8String])];

	return self;
}

- (instancetype)initFromGicon:(GIcon*)icon
{
	self = [super initWithGObject:(GObject*)gtk_status_icon_new_from_gicon(icon)];

	return self;
}

- (instancetype)initFromIconName:(OFString*)iconName
{
	self = [super initWithGObject:(GObject*)gtk_status_icon_new_from_icon_name([iconName UTF8String])];

	return self;
}

- (instancetype)initFromPixbuf:(OGGdkPixbuf*)pixbuf
{
	self = [super initWithGObject:(GObject*)gtk_status_icon_new_from_pixbuf([pixbuf PIXBUF])];

	return self;
}

- (instancetype)initFromStock:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_status_icon_new_from_stock([stockId UTF8String])];

	return self;
}

- (GtkStatusIcon*)STATUSICON
{
	return GTK_STATUS_ICON([self GOBJECT]);
}

- (bool)geometryWithScreen:(GdkScreen**)screen area:(GdkRectangle*)area orientation:(GtkOrientation*)orientation
{
	return gtk_status_icon_get_geometry([self STATUSICON], screen, area, orientation);
}

- (GIcon*)gicon
{
	return gtk_status_icon_get_gicon([self STATUSICON]);
}

- (bool)hasTooltip
{
	return gtk_status_icon_get_has_tooltip([self STATUSICON]);
}

- (OFString*)iconName
{
	return [OFString stringWithUTF8String:gtk_status_icon_get_icon_name([self STATUSICON])];
}

- (OGGdkPixbuf*)pixbuf
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_status_icon_get_pixbuf([self STATUSICON])] autorelease];
}

- (OGGdkScreen*)screen
{
	return [[[OGGdkScreen alloc] initWithGObject:(GObject*)gtk_status_icon_get_screen([self STATUSICON])] autorelease];
}

- (gint)size
{
	return gtk_status_icon_get_size([self STATUSICON]);
}

- (OFString*)stock
{
	return [OFString stringWithUTF8String:gtk_status_icon_get_stock([self STATUSICON])];
}

- (GtkImageType)storageType
{
	return gtk_status_icon_get_storage_type([self STATUSICON]);
}

- (OFString*)title
{
	return [OFString stringWithUTF8String:gtk_status_icon_get_title([self STATUSICON])];
}

- (OFString*)tooltipMarkup
{
	return [OFString stringWithUTF8String:gtk_status_icon_get_tooltip_markup([self STATUSICON])];
}

- (OFString*)tooltipText
{
	return [OFString stringWithUTF8String:gtk_status_icon_get_tooltip_text([self STATUSICON])];
}

- (bool)visible
{
	return gtk_status_icon_get_visible([self STATUSICON]);
}

- (guint32)x11WindowId
{
	return gtk_status_icon_get_x11_window_id([self STATUSICON]);
}

- (bool)isEmbedded
{
	return gtk_status_icon_is_embedded([self STATUSICON]);
}

- (void)setFromFile:(OFString*)filename
{
	gtk_status_icon_set_from_file([self STATUSICON], [filename UTF8String]);
}

- (void)setFromGicon:(GIcon*)icon
{
	gtk_status_icon_set_from_gicon([self STATUSICON], icon);
}

- (void)setFromIconName:(OFString*)iconName
{
	gtk_status_icon_set_from_icon_name([self STATUSICON], [iconName UTF8String]);
}

- (void)setFromPixbuf:(OGGdkPixbuf*)pixbuf
{
	gtk_status_icon_set_from_pixbuf([self STATUSICON], [pixbuf PIXBUF]);
}

- (void)setFromStock:(OFString*)stockId
{
	gtk_status_icon_set_from_stock([self STATUSICON], [stockId UTF8String]);
}

- (void)setHasTooltip:(bool)hasTooltip
{
	gtk_status_icon_set_has_tooltip([self STATUSICON], hasTooltip);
}

- (void)setName:(OFString*)name
{
	gtk_status_icon_set_name([self STATUSICON], [name UTF8String]);
}

- (void)setScreen:(OGGdkScreen*)screen
{
	gtk_status_icon_set_screen([self STATUSICON], [screen SCREEN]);
}

- (void)setTitle:(OFString*)title
{
	gtk_status_icon_set_title([self STATUSICON], [title UTF8String]);
}

- (void)setTooltipMarkup:(OFString*)markup
{
	gtk_status_icon_set_tooltip_markup([self STATUSICON], [markup UTF8String]);
}

- (void)setTooltipText:(OFString*)text
{
	gtk_status_icon_set_tooltip_text([self STATUSICON], [text UTF8String]);
}

- (void)setVisible:(bool)visible
{
	gtk_status_icon_set_visible([self STATUSICON], visible);
}


@end