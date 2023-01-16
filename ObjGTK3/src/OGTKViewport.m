/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKViewport.h"

#import "OGTKWidget.h"
#import "OGTKAdjustment.h"
#import <OGdk3/OGGdkWindow.h>

@implementation OGTKViewport

- (instancetype)initWithHadjustment:(OGTKAdjustment*)hadjustment vadjustment:(OGTKAdjustment*)vadjustment
{
	self = [super initWithGObject:(GObject*)gtk_viewport_new([hadjustment ADJUSTMENT], [vadjustment ADJUSTMENT])];

	return self;
}

- (GtkViewport*)VIEWPORT
{
	return GTK_VIEWPORT([self GOBJECT]);
}

- (OGGdkWindow*)binWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_viewport_get_bin_window([self VIEWPORT])] autorelease];
}

- (OGTKAdjustment*)hadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_viewport_get_hadjustment([self VIEWPORT])] autorelease];
}

- (GtkShadowType)shadowType
{
	return gtk_viewport_get_shadow_type([self VIEWPORT]);
}

- (OGTKAdjustment*)vadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_viewport_get_vadjustment([self VIEWPORT])] autorelease];
}

- (OGGdkWindow*)viewWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_viewport_get_view_window([self VIEWPORT])] autorelease];
}

- (void)setHadjustment:(OGTKAdjustment*)adjustment
{
	gtk_viewport_set_hadjustment([self VIEWPORT], [adjustment ADJUSTMENT]);
}

- (void)setShadowType:(GtkShadowType)type
{
	gtk_viewport_set_shadow_type([self VIEWPORT], type);
}

- (void)setVadjustment:(OGTKAdjustment*)adjustment
{
	gtk_viewport_set_vadjustment([self VIEWPORT], [adjustment ADJUSTMENT]);
}


@end