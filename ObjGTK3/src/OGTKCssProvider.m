/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCssProvider.h"

@implementation OGTKCssProvider

+ (OGTKCssProvider*)default
{
	return [[[OGTKCssProvider alloc] initWithGObject:(GObject*)gtk_css_provider_get_default()] autorelease];
}

+ (OGTKCssProvider*)namedWithName:(OFString*)name variant:(OFString*)variant
{
	return [[[OGTKCssProvider alloc] initWithGObject:(GObject*)gtk_css_provider_get_named([name UTF8String], [variant UTF8String])] autorelease];
}

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_css_provider_new()];

	return self;
}

- (GtkCssProvider*)CSSPROVIDER
{
	return GTK_CSS_PROVIDER([self GOBJECT]);
}

- (bool)loadFromDataWithData:(OFString*)data length:(gssize)length err:(GError**)err
{
	return gtk_css_provider_load_from_data([self CSSPROVIDER], [data UTF8String], length, err);
}

- (bool)loadFromFileWithFile:(GFile*)file err:(GError**)err
{
	return gtk_css_provider_load_from_file([self CSSPROVIDER], file, err);
}

- (bool)loadFromPathWithPath:(OFString*)path err:(GError**)err
{
	return gtk_css_provider_load_from_path([self CSSPROVIDER], [path UTF8String], err);
}

- (void)loadFromResource:(OFString*)resourcePath
{
	gtk_css_provider_load_from_resource([self CSSPROVIDER], [resourcePath UTF8String]);
}

- (char*)toString
{
	return gtk_css_provider_to_string([self CSSPROVIDER]);
}


@end