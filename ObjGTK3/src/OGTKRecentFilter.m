/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRecentFilter.h"

@implementation OGTKRecentFilter

- (instancetype)init
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
	gtk_recent_filter_add_age([self RECENTFILTER], days);
}

- (void)addApplication:(OFString*)application
{
	gtk_recent_filter_add_application([self RECENTFILTER], [application UTF8String]);
}

- (void)addCustomWithNeeded:(GtkRecentFilterFlags)needed func:(GtkRecentFilterFunc)func data:(gpointer)data dataDestroy:(GDestroyNotify)dataDestroy
{
	gtk_recent_filter_add_custom([self RECENTFILTER], needed, func, data, dataDestroy);
}

- (void)addGroup:(OFString*)group
{
	gtk_recent_filter_add_group([self RECENTFILTER], [group UTF8String]);
}

- (void)addMimeType:(OFString*)mimeType
{
	gtk_recent_filter_add_mime_type([self RECENTFILTER], [mimeType UTF8String]);
}

- (void)addPattern:(OFString*)pattern
{
	gtk_recent_filter_add_pattern([self RECENTFILTER], [pattern UTF8String]);
}

- (void)addPixbufFormats
{
	gtk_recent_filter_add_pixbuf_formats([self RECENTFILTER]);
}

- (bool)filter:(const GtkRecentFilterInfo*)filterInfo
{
	return gtk_recent_filter_filter([self RECENTFILTER], filterInfo);
}

- (OFString*)name
{
	return [OFString stringWithUTF8String:gtk_recent_filter_get_name([self RECENTFILTER])];
}

- (GtkRecentFilterFlags)needed
{
	return gtk_recent_filter_get_needed([self RECENTFILTER]);
}

- (void)setName:(OFString*)name
{
	gtk_recent_filter_set_name([self RECENTFILTER], [name UTF8String]);
}


@end