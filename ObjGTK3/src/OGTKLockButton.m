/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKLockButton.h"

#import "OGTKWidget.h"

@implementation OGTKLockButton

- (instancetype)init:(GPermission*)permission
{
	self = [super initWithGObject:(GObject*)gtk_lock_button_new(permission)];

	return self;
}

- (GtkLockButton*)LOCKBUTTON
{
	return GTK_LOCK_BUTTON([self GOBJECT]);
}

- (GPermission*)permission
{
	return gtk_lock_button_get_permission([self LOCKBUTTON]);
}

- (void)setPermission:(GPermission*)permission
{
	gtk_lock_button_set_permission([self LOCKBUTTON], permission);
}


@end