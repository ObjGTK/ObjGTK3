/*
 * OGTKSwitch.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKSwitch.h"

@implementation OGTKSwitch

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_switch_new()];

	return self;
}

- (GtkSwitch*)SWITCH
{
	return GTK_SWITCH([self GOBJECT]);
}

- (bool)getActive
{
	return gtk_switch_get_active(GTK_SWITCH([self GOBJECT]));
}

- (bool)getState
{
	return gtk_switch_get_state(GTK_SWITCH([self GOBJECT]));
}

- (void)setActive:(bool)isActive
{
	gtk_switch_set_active(GTK_SWITCH([self GOBJECT]), isActive);
}

- (void)setState:(bool)state
{
	gtk_switch_set_state(GTK_SWITCH([self GOBJECT]), state);
}


@end