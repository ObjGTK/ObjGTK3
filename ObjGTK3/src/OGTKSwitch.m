/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSwitch.h"

@implementation OGTKSwitch

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_switch_new()];

	return self;
}

- (GtkSwitch*)SWITCH
{
	return GTK_SWITCH([self GOBJECT]);
}

- (bool)active
{
	return gtk_switch_get_active([self SWITCH]);
}

- (bool)state
{
	return gtk_switch_get_state([self SWITCH]);
}

- (void)setActive:(bool)isActive
{
	gtk_switch_set_active([self SWITCH], isActive);
}

- (void)setState:(bool)state
{
	gtk_switch_set_state([self SWITCH], state);
}


@end