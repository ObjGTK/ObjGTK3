/*
 * OGTKStack.m
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
#import "OGTKStack.h"

@implementation OGTKStack

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_stack_new()];

	return self;
}

- (GtkStack*)STACK
{
	return GTK_STACK([self GOBJECT]);
}

- (void)addNamedWithChild:(OGTKWidget*)child andName:(OFString*)name
{
	gtk_stack_add_named(GTK_STACK([self GOBJECT]), [child WIDGET], [name UTF8String]);
}

- (void)addTitledWithChild:(OGTKWidget*)child andName:(OFString*)name andTitle:(OFString*)title
{
	gtk_stack_add_titled(GTK_STACK([self GOBJECT]), [child WIDGET], [name UTF8String], [title UTF8String]);
}

- (OGTKWidget*)getChildByName:(OFString*)name
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_stack_get_child_by_name(GTK_STACK([self GOBJECT]), [name UTF8String])];
}

- (bool)getHhomogeneous
{
	return gtk_stack_get_hhomogeneous(GTK_STACK([self GOBJECT]));
}

- (bool)getHomogeneous
{
	return gtk_stack_get_homogeneous(GTK_STACK([self GOBJECT]));
}

- (bool)getInterpolateSize
{
	return gtk_stack_get_interpolate_size(GTK_STACK([self GOBJECT]));
}

- (guint)getTransitionDuration
{
	return gtk_stack_get_transition_duration(GTK_STACK([self GOBJECT]));
}

- (bool)getTransitionRunning
{
	return gtk_stack_get_transition_running(GTK_STACK([self GOBJECT]));
}

- (GtkStackTransitionType)getTransitionType
{
	return gtk_stack_get_transition_type(GTK_STACK([self GOBJECT]));
}

- (bool)getVhomogeneous
{
	return gtk_stack_get_vhomogeneous(GTK_STACK([self GOBJECT]));
}

- (OGTKWidget*)getVisibleChild
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_stack_get_visible_child(GTK_STACK([self GOBJECT]))];
}

- (OFString*)getVisibleChildName
{
	return [OFString stringWithUTF8String:gtk_stack_get_visible_child_name(GTK_STACK([self GOBJECT]))];
}

- (void)setHhomogeneous:(bool)hhomogeneous
{
	gtk_stack_set_hhomogeneous(GTK_STACK([self GOBJECT]), hhomogeneous);
}

- (void)setHomogeneous:(bool)homogeneous
{
	gtk_stack_set_homogeneous(GTK_STACK([self GOBJECT]), homogeneous);
}

- (void)setInterpolateSize:(bool)interpolateSize
{
	gtk_stack_set_interpolate_size(GTK_STACK([self GOBJECT]), interpolateSize);
}

- (void)setTransitionDuration:(guint)duration
{
	gtk_stack_set_transition_duration(GTK_STACK([self GOBJECT]), duration);
}

- (void)setTransitionType:(GtkStackTransitionType)transition
{
	gtk_stack_set_transition_type(GTK_STACK([self GOBJECT]), transition);
}

- (void)setVhomogeneous:(bool)vhomogeneous
{
	gtk_stack_set_vhomogeneous(GTK_STACK([self GOBJECT]), vhomogeneous);
}

- (void)setVisibleChild:(OGTKWidget*)child
{
	gtk_stack_set_visible_child(GTK_STACK([self GOBJECT]), [child WIDGET]);
}

- (void)setVisibleChildFullWithName:(OFString*)name andTransition:(GtkStackTransitionType)transition
{
	gtk_stack_set_visible_child_full(GTK_STACK([self GOBJECT]), [name UTF8String], transition);
}

- (void)setVisibleChildName:(OFString*)name
{
	gtk_stack_set_visible_child_name(GTK_STACK([self GOBJECT]), [name UTF8String]);
}


@end