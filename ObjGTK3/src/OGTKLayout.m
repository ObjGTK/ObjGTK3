/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKLayout.h"

#import "OGTKAdjustment.h"
#import "OGTKWidget.h"
#import <OGdk3/OGGdkWindow.h>

@implementation OGTKLayout

- (instancetype)initWithHadjustment:(OGTKAdjustment*)hadjustment vadjustment:(OGTKAdjustment*)vadjustment
{
	self = [super initWithGObject:(GObject*)gtk_layout_new([hadjustment ADJUSTMENT], [vadjustment ADJUSTMENT])];

	return self;
}

- (GtkLayout*)LAYOUT
{
	return GTK_LAYOUT([self GOBJECT]);
}

- (OGGdkWindow*)binWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_layout_get_bin_window([self LAYOUT])] autorelease];
}

- (OGTKAdjustment*)hadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_layout_get_hadjustment([self LAYOUT])] autorelease];
}

- (void)sizeWithWidth:(guint*)width height:(guint*)height
{
	gtk_layout_get_size([self LAYOUT], width, height);
}

- (OGTKAdjustment*)vadjustment
{
	return [[[OGTKAdjustment alloc] initWithGObject:(GObject*)gtk_layout_get_vadjustment([self LAYOUT])] autorelease];
}

- (void)moveWithChildWidget:(OGTKWidget*)childWidget x:(gint)x y:(gint)y
{
	gtk_layout_move([self LAYOUT], [childWidget WIDGET], x, y);
}

- (void)putWithChildWidget:(OGTKWidget*)childWidget x:(gint)x y:(gint)y
{
	gtk_layout_put([self LAYOUT], [childWidget WIDGET], x, y);
}

- (void)setHadjustment:(OGTKAdjustment*)adjustment
{
	gtk_layout_set_hadjustment([self LAYOUT], [adjustment ADJUSTMENT]);
}

- (void)setSizeWithWidth:(guint)width height:(guint)height
{
	gtk_layout_set_size([self LAYOUT], width, height);
}

- (void)setVadjustment:(OGTKAdjustment*)adjustment
{
	gtk_layout_set_vadjustment([self LAYOUT], [adjustment ADJUSTMENT]);
}


@end