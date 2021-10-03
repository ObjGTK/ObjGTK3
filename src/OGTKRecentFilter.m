/*
 * OGTKRecentFilter.m
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
#import "OGTKRecentFilter.h"

@implementation OGTKRecentFilter

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_recent_filter_new()];

	return self;
}

- (GtkRecentFilter*)RECENTFILTER
{
	return GTK_RECENT_FILTER([self GOBJECT]);
}

- (void)addAge:(gint)days
{
	gtk_recent_filter_add_age(GTK_RECENT_FILTER([self GOBJECT]), days);
}

- (void)addApplication:(OFString*)application
{
	gtk_recent_filter_add_application(GTK_RECENT_FILTER([self GOBJECT]), [application UTF8String]);
}

- (void)addCustomWithNeeded:(GtkRecentFilterFlags)needed andFunc:(GtkRecentFilterFunc)func andData:(gpointer)data andDataDestroy:(GDestroyNotify)dataDestroy
{
	gtk_recent_filter_add_custom(GTK_RECENT_FILTER([self GOBJECT]), needed, func, data, dataDestroy);
}

- (void)addGroup:(OFString*)group
{
	gtk_recent_filter_add_group(GTK_RECENT_FILTER([self GOBJECT]), [group UTF8String]);
}

- (void)addMimeType:(OFString*)mimeType
{
	gtk_recent_filter_add_mime_type(GTK_RECENT_FILTER([self GOBJECT]), [mimeType UTF8String]);
}

- (void)addPattern:(OFString*)pattern
{
	gtk_recent_filter_add_pattern(GTK_RECENT_FILTER([self GOBJECT]), [pattern UTF8String]);
}

- (void)addPixbufFormats
{
	gtk_recent_filter_add_pixbuf_formats(GTK_RECENT_FILTER([self GOBJECT]));
}

- (bool)filter:(const GtkRecentFilterInfo*)filterInfo
{
	return gtk_recent_filter_filter(GTK_RECENT_FILTER([self GOBJECT]), filterInfo);
}

- (OFString*)getName
{
	return [OFString stringWithUTF8String:gtk_recent_filter_get_name(GTK_RECENT_FILTER([self GOBJECT]))];
}

- (GtkRecentFilterFlags)getNeeded
{
	return gtk_recent_filter_get_needed(GTK_RECENT_FILTER([self GOBJECT]));
}

- (void)setName:(OFString*)name
{
	gtk_recent_filter_set_name(GTK_RECENT_FILTER([self GOBJECT]), [name UTF8String]);
}


@end