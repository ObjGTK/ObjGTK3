/*
 * OGTKNumerableIcon.m
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
#import "OGTKNumerableIcon.h"

@implementation OGTKNumerableIcon

+ (GIcon*)new:(GIcon*)baseIcon
{
	return gtk_numerable_icon_new(baseIcon);
}

+ (GIcon*)newWithStyleContextWithBaseIcon:(GIcon*)baseIcon andContext:(GtkStyleContext*)context
{
	return gtk_numerable_icon_new_with_style_context(baseIcon, context);
}

- (GtkNumerableIcon*)NUMERABLEICON
{
	return GTK_NUMERABLE_ICON([self GOBJECT]);
}

- (GIcon*)getBackgroundGicon
{
	return gtk_numerable_icon_get_background_gicon(GTK_NUMERABLE_ICON([self GOBJECT]));
}

- (OFString*)getBackgroundIconName
{
	return [OFString stringWithUTF8String:gtk_numerable_icon_get_background_icon_name(GTK_NUMERABLE_ICON([self GOBJECT]))];
}

- (gint)getCount
{
	return gtk_numerable_icon_get_count(GTK_NUMERABLE_ICON([self GOBJECT]));
}

- (OFString*)getLabel
{
	return [OFString stringWithUTF8String:gtk_numerable_icon_get_label(GTK_NUMERABLE_ICON([self GOBJECT]))];
}

- (GtkStyleContext*)getStyleContext
{
	return gtk_numerable_icon_get_style_context(GTK_NUMERABLE_ICON([self GOBJECT]));
}

- (void)setBackgroundGicon:(GIcon*)icon
{
	gtk_numerable_icon_set_background_gicon(GTK_NUMERABLE_ICON([self GOBJECT]), icon);
}

- (void)setBackgroundIconName:(OFString*)iconName
{
	gtk_numerable_icon_set_background_icon_name(GTK_NUMERABLE_ICON([self GOBJECT]), [iconName UTF8String]);
}

- (void)setCount:(gint)count
{
	gtk_numerable_icon_set_count(GTK_NUMERABLE_ICON([self GOBJECT]), count);
}

- (void)setLabel:(OFString*)label
{
	gtk_numerable_icon_set_label(GTK_NUMERABLE_ICON([self GOBJECT]), [label UTF8String]);
}

- (void)setStyleContext:(GtkStyleContext*)style
{
	gtk_numerable_icon_set_style_context(GTK_NUMERABLE_ICON([self GOBJECT]), style);
}


@end