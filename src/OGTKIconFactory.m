/*
 * OGTKIconFactory.m
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
#import "OGTKIconFactory.h"

@implementation OGTKIconFactory

+ (GtkIconSet*)lookupDefault:(OFString*)stockId
{
	return gtk_icon_factory_lookup_default([stockId UTF8String]);
}

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_icon_factory_new()];

	return self;
}

- (GtkIconFactory*)ICONFACTORY
{
	return GTK_ICON_FACTORY([self GOBJECT]);
}

- (void)addWithStockId:(OFString*)stockId andIconSet:(GtkIconSet*)iconSet
{
	gtk_icon_factory_add(GTK_ICON_FACTORY([self GOBJECT]), [stockId UTF8String], iconSet);
}

- (void)addDefault
{
	gtk_icon_factory_add_default(GTK_ICON_FACTORY([self GOBJECT]));
}

- (GtkIconSet*)lookup:(OFString*)stockId
{
	return gtk_icon_factory_lookup(GTK_ICON_FACTORY([self GOBJECT]), [stockId UTF8String]);
}

- (void)removeDefault
{
	gtk_icon_factory_remove_default(GTK_ICON_FACTORY([self GOBJECT]));
}


@end