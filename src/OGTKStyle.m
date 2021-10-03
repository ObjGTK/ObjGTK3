/*
 * OGTKStyle.m
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
#import "OGTKStyle.h"

@implementation OGTKStyle

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_style_new()];

	return self;
}

- (GtkStyle*)STYLE
{
	return GTK_STYLE([self GOBJECT]);
}

- (void)applyDefaultBackgroundWithCr:(cairo_t*)cr andWindow:(GdkWindow*)window andStateType:(GtkStateType)stateType andX:(gint)x andY:(gint)y andWidth:(gint)width andHeight:(gint)height
{
	gtk_style_apply_default_background(GTK_STYLE([self GOBJECT]), cr, window, stateType, x, y, width, height);
}

- (GtkStyle*)attach:(GdkWindow*)window
{
	return gtk_style_attach(GTK_STYLE([self GOBJECT]), window);
}

- (GtkStyle*)copy
{
	return gtk_style_copy(GTK_STYLE([self GOBJECT]));
}

- (void)detach
{
	gtk_style_detach(GTK_STYLE([self GOBJECT]));
}

- (void)getStylePropertyWithWidgetType:(GType)widgetType andPropertyName:(OFString*)propertyName andValue:(GValue*)value
{
	gtk_style_get_style_property(GTK_STYLE([self GOBJECT]), widgetType, [propertyName UTF8String], value);
}

- (void)getValistWithWidgetType:(GType)widgetType andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs
{
	gtk_style_get_valist(GTK_STYLE([self GOBJECT]), widgetType, [firstPropertyName UTF8String], varArgs);
}

- (bool)hasContext
{
	return gtk_style_has_context(GTK_STYLE([self GOBJECT]));
}

- (bool)lookupColorWithColorName:(OFString*)colorName andColor:(GdkColor*)color
{
	return gtk_style_lookup_color(GTK_STYLE([self GOBJECT]), [colorName UTF8String], color);
}

- (GtkIconSet*)lookupIconSet:(OFString*)stockId
{
	return gtk_style_lookup_icon_set(GTK_STYLE([self GOBJECT]), [stockId UTF8String]);
}

- (GdkPixbuf*)renderIconWithSource:(const GtkIconSource*)source andDirection:(GtkTextDirection)direction andState:(GtkStateType)state andSize:(GtkIconSize)size andWidget:(OGTKWidget*)widget andDetail:(OFString*)detail
{
	return gtk_style_render_icon(GTK_STYLE([self GOBJECT]), source, direction, state, size, [widget WIDGET], [detail UTF8String]);
}

- (void)setBackgroundWithWindow:(GdkWindow*)window andStateType:(GtkStateType)stateType
{
	gtk_style_set_background(GTK_STYLE([self GOBJECT]), window, stateType);
}


@end