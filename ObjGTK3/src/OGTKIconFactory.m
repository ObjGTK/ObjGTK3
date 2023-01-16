/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKIconFactory.h"

@implementation OGTKIconFactory

+ (GtkIconSet*)lookupDefault:(OFString*)stockId
{
	return gtk_icon_factory_lookup_default([stockId UTF8String]);
}

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_icon_factory_new()];

	return self;
}

- (GtkIconFactory*)ICONFACTORY
{
	return GTK_ICON_FACTORY([self GOBJECT]);
}

- (void)addWithStockId:(OFString*)stockId iconSet:(GtkIconSet*)iconSet
{
	gtk_icon_factory_add([self ICONFACTORY], [stockId UTF8String], iconSet);
}

- (void)addDefault
{
	gtk_icon_factory_add_default([self ICONFACTORY]);
}

- (GtkIconSet*)lookup:(OFString*)stockId
{
	return gtk_icon_factory_lookup([self ICONFACTORY], [stockId UTF8String]);
}

- (void)removeDefault
{
	gtk_icon_factory_remove_default([self ICONFACTORY]);
}


@end