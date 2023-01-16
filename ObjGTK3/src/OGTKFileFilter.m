/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFileFilter.h"

@implementation OGTKFileFilter

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_file_filter_new()];

	return self;
}

- (instancetype)initFromGvariant:(GVariant*)variant
{
	self = [super initWithGObject:(GObject*)gtk_file_filter_new_from_gvariant(variant)];

	return self;
}

- (GtkFileFilter*)FILEFILTER
{
	return GTK_FILE_FILTER([self GOBJECT]);
}

- (void)addCustomWithNeeded:(GtkFileFilterFlags)needed func:(GtkFileFilterFunc)func data:(gpointer)data notify:(GDestroyNotify)notify
{
	gtk_file_filter_add_custom([self FILEFILTER], needed, func, data, notify);
}

- (void)addMimeType:(OFString*)mimeType
{
	gtk_file_filter_add_mime_type([self FILEFILTER], [mimeType UTF8String]);
}

- (void)addPattern:(OFString*)pattern
{
	gtk_file_filter_add_pattern([self FILEFILTER], [pattern UTF8String]);
}

- (void)addPixbufFormats
{
	gtk_file_filter_add_pixbuf_formats([self FILEFILTER]);
}

- (bool)filter:(const GtkFileFilterInfo*)filterInfo
{
	return gtk_file_filter_filter([self FILEFILTER], filterInfo);
}

- (OFString*)name
{
	return [OFString stringWithUTF8String:gtk_file_filter_get_name([self FILEFILTER])];
}

- (GtkFileFilterFlags)needed
{
	return gtk_file_filter_get_needed([self FILEFILTER]);
}

- (void)setName:(OFString*)name
{
	gtk_file_filter_set_name([self FILEFILTER], [name UTF8String]);
}

- (GVariant*)toGvariant
{
	return gtk_file_filter_to_gvariant([self FILEFILTER]);
}


@end