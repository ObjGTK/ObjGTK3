/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKInvisible.h"

#import <OGdk3/OGGdkScreen.h>

@implementation OGTKInvisible

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_invisible_new()];

	return self;
}

- (instancetype)initForScreen:(OGGdkScreen*)screen
{
	self = [super initWithGObject:(GObject*)gtk_invisible_new_for_screen([screen SCREEN])];

	return self;
}

- (GtkInvisible*)INVISIBLE
{
	return GTK_INVISIBLE([self GOBJECT]);
}

- (OGGdkScreen*)screen
{
	return [[[OGGdkScreen alloc] initWithGObject:(GObject*)gtk_invisible_get_screen([self INVISIBLE])] autorelease];
}

- (void)setScreen:(OGGdkScreen*)screen
{
	gtk_invisible_set_screen([self INVISIBLE], [screen SCREEN]);
}


@end