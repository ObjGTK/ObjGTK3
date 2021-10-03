/*
 * OGTKRevealer.m
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
#import "OGTKRevealer.h"

@implementation OGTKRevealer

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_revealer_new()];

	return self;
}

- (GtkRevealer*)REVEALER
{
	return GTK_REVEALER([self GOBJECT]);
}

- (bool)getChildRevealed
{
	return gtk_revealer_get_child_revealed(GTK_REVEALER([self GOBJECT]));
}

- (bool)getRevealChild
{
	return gtk_revealer_get_reveal_child(GTK_REVEALER([self GOBJECT]));
}

- (guint)getTransitionDuration
{
	return gtk_revealer_get_transition_duration(GTK_REVEALER([self GOBJECT]));
}

- (GtkRevealerTransitionType)getTransitionType
{
	return gtk_revealer_get_transition_type(GTK_REVEALER([self GOBJECT]));
}

- (void)setRevealChild:(bool)revealChild
{
	gtk_revealer_set_reveal_child(GTK_REVEALER([self GOBJECT]), revealChild);
}

- (void)setTransitionDuration:(guint)duration
{
	gtk_revealer_set_transition_duration(GTK_REVEALER([self GOBJECT]), duration);
}

- (void)setTransitionType:(GtkRevealerTransitionType)transition
{
	gtk_revealer_set_transition_type(GTK_REVEALER([self GOBJECT]), transition);
}


@end