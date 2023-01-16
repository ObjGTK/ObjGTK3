/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkAppLaunchContext.h"

#import "OGGdkDisplay.h"
#import "OGGdkScreen.h"

@implementation OGGdkAppLaunchContext

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gdk_app_launch_context_new()];

	return self;
}

- (GdkAppLaunchContext*)APPLAUNCHCONTEXT
{
	return GDK_APP_LAUNCH_CONTEXT([self GOBJECT]);
}

- (void)setDesktop:(gint)desktop
{
	gdk_app_launch_context_set_desktop([self APPLAUNCHCONTEXT], desktop);
}

- (void)setDisplay:(OGGdkDisplay*)display
{
	gdk_app_launch_context_set_display([self APPLAUNCHCONTEXT], [display DISPLAY]);
}

- (void)setIcon:(GIcon*)icon
{
	gdk_app_launch_context_set_icon([self APPLAUNCHCONTEXT], icon);
}

- (void)setIconName:(OFString*)iconName
{
	gdk_app_launch_context_set_icon_name([self APPLAUNCHCONTEXT], [iconName UTF8String]);
}

- (void)setScreen:(OGGdkScreen*)screen
{
	gdk_app_launch_context_set_screen([self APPLAUNCHCONTEXT], [screen SCREEN]);
}

- (void)setTimestamp:(guint32)timestamp
{
	gdk_app_launch_context_set_timestamp([self APPLAUNCHCONTEXT], timestamp);
}


@end