/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkDisplayManager.h"

#import "OGGdkDisplay.h"

@implementation OGGdkDisplayManager

+ (OGGdkDisplayManager*)instance
{
	return [[[OGGdkDisplayManager alloc] initWithGObject:(GObject*)gdk_display_manager_get()] autorelease];
}

- (GdkDisplayManager*)DISPLAYMANAGER
{
	return GDK_DISPLAY_MANAGER([self GOBJECT]);
}

- (OGGdkDisplay*)defaultDisplay
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_display_manager_get_default_display([self DISPLAYMANAGER])] autorelease];
}

- (GSList*)listDisplays
{
	return gdk_display_manager_list_displays([self DISPLAYMANAGER]);
}

- (OGGdkDisplay*)openDisplay:(OFString*)name
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_display_manager_open_display([self DISPLAYMANAGER], [name UTF8String])] autorelease];
}

- (void)setDefaultDisplay:(OGGdkDisplay*)display
{
	gdk_display_manager_set_default_display([self DISPLAYMANAGER], [display DISPLAY]);
}


@end