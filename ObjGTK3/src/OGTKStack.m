/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKStack.h"

#import "OGTKWidget.h"

@implementation OGTKStack

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_stack_new()];

	return self;
}

- (GtkStack*)STACK
{
	return GTK_STACK([self GOBJECT]);
}

- (void)addNamedWithChild:(OGTKWidget*)child name:(OFString*)name
{
	gtk_stack_add_named([self STACK], [child WIDGET], [name UTF8String]);
}

- (void)addTitledWithChild:(OGTKWidget*)child name:(OFString*)name title:(OFString*)title
{
	gtk_stack_add_titled([self STACK], [child WIDGET], [name UTF8String], [title UTF8String]);
}

- (OGTKWidget*)childByName:(OFString*)name
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_stack_get_child_by_name([self STACK], [name UTF8String])] autorelease];
}

- (bool)hhomogeneous
{
	return gtk_stack_get_hhomogeneous([self STACK]);
}

- (bool)homogeneous
{
	return gtk_stack_get_homogeneous([self STACK]);
}

- (bool)interpolateSize
{
	return gtk_stack_get_interpolate_size([self STACK]);
}

- (guint)transitionDuration
{
	return gtk_stack_get_transition_duration([self STACK]);
}

- (bool)transitionRunning
{
	return gtk_stack_get_transition_running([self STACK]);
}

- (GtkStackTransitionType)transitionType
{
	return gtk_stack_get_transition_type([self STACK]);
}

- (bool)vhomogeneous
{
	return gtk_stack_get_vhomogeneous([self STACK]);
}

- (OGTKWidget*)visibleChild
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_stack_get_visible_child([self STACK])] autorelease];
}

- (OFString*)visibleChildName
{
	return [OFString stringWithUTF8String:gtk_stack_get_visible_child_name([self STACK])];
}

- (void)setHhomogeneous:(bool)hhomogeneous
{
	gtk_stack_set_hhomogeneous([self STACK], hhomogeneous);
}

- (void)setHomogeneous:(bool)homogeneous
{
	gtk_stack_set_homogeneous([self STACK], homogeneous);
}

- (void)setInterpolateSize:(bool)interpolateSize
{
	gtk_stack_set_interpolate_size([self STACK], interpolateSize);
}

- (void)setTransitionDuration:(guint)duration
{
	gtk_stack_set_transition_duration([self STACK], duration);
}

- (void)setTransitionType:(GtkStackTransitionType)transition
{
	gtk_stack_set_transition_type([self STACK], transition);
}

- (void)setVhomogeneous:(bool)vhomogeneous
{
	gtk_stack_set_vhomogeneous([self STACK], vhomogeneous);
}

- (void)setVisibleChild:(OGTKWidget*)child
{
	gtk_stack_set_visible_child([self STACK], [child WIDGET]);
}

- (void)setVisibleChildFullWithName:(OFString*)name transition:(GtkStackTransitionType)transition
{
	gtk_stack_set_visible_child_full([self STACK], [name UTF8String], transition);
}

- (void)setVisibleChildName:(OFString*)name
{
	gtk_stack_set_visible_child_name([self STACK], [name UTF8String]);
}


@end