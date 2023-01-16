/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMountOperation.h"

#import <OGdk3/OGGdkScreen.h>
#import "OGTKWindow.h"

@implementation OGTKMountOperation

- (instancetype)init:(OGTKWindow*)parent
{
	self = [super initWithGObject:(GObject*)gtk_mount_operation_new([parent WINDOW])];

	return self;
}

- (GtkMountOperation*)MOUNTOPERATION
{
	return GTK_MOUNT_OPERATION([self GOBJECT]);
}

- (OGTKWindow*)parent
{
	return [[[OGTKWindow alloc] initWithGObject:(GObject*)gtk_mount_operation_get_parent([self MOUNTOPERATION])] autorelease];
}

- (OGGdkScreen*)screen
{
	return [[[OGGdkScreen alloc] initWithGObject:(GObject*)gtk_mount_operation_get_screen([self MOUNTOPERATION])] autorelease];
}

- (bool)isShowing
{
	return gtk_mount_operation_is_showing([self MOUNTOPERATION]);
}

- (void)setParent:(OGTKWindow*)parent
{
	gtk_mount_operation_set_parent([self MOUNTOPERATION], [parent WINDOW]);
}

- (void)setScreen:(OGGdkScreen*)screen
{
	gtk_mount_operation_set_screen([self MOUNTOPERATION], [screen SCREEN]);
}


@end