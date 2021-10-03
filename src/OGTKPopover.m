/*
 * OGTKPopover.m
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
#import "OGTKPopover.h"

@implementation OGTKPopover

- (id)init:(OGTKWidget*)relativeTo
{
	self = [super initWithGObject:(GObject*)gtk_popover_new([relativeTo WIDGET])];

	return self;
}

- (id)initFromModelWithRelativeTo:(OGTKWidget*)relativeTo andModel:(GMenuModel*)model
{
	self = [super initWithGObject:(GObject*)gtk_popover_new_from_model([relativeTo WIDGET], model)];

	return self;
}

- (GtkPopover*)POPOVER
{
	return GTK_POPOVER([self GOBJECT]);
}

- (void)bindModelWithModel:(GMenuModel*)model andActionNamespace:(OFString*)actionNamespace
{
	gtk_popover_bind_model(GTK_POPOVER([self GOBJECT]), model, [actionNamespace UTF8String]);
}

- (GtkPopoverConstraint)getConstrainTo
{
	return gtk_popover_get_constrain_to(GTK_POPOVER([self GOBJECT]));
}

- (OGTKWidget*)getDefaultWidget
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_popover_get_default_widget(GTK_POPOVER([self GOBJECT]))];
}

- (bool)getModal
{
	return gtk_popover_get_modal(GTK_POPOVER([self GOBJECT]));
}

- (bool)getPointingTo:(GdkRectangle*)rect
{
	return gtk_popover_get_pointing_to(GTK_POPOVER([self GOBJECT]), rect);
}

- (GtkPositionType)getPosition
{
	return gtk_popover_get_position(GTK_POPOVER([self GOBJECT]));
}

- (OGTKWidget*)getRelativeTo
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_popover_get_relative_to(GTK_POPOVER([self GOBJECT]))];
}

- (bool)getTransitionsEnabled
{
	return gtk_popover_get_transitions_enabled(GTK_POPOVER([self GOBJECT]));
}

- (void)popdown
{
	gtk_popover_popdown(GTK_POPOVER([self GOBJECT]));
}

- (void)popup
{
	gtk_popover_popup(GTK_POPOVER([self GOBJECT]));
}

- (void)setConstrainTo:(GtkPopoverConstraint)constraint
{
	gtk_popover_set_constrain_to(GTK_POPOVER([self GOBJECT]), constraint);
}

- (void)setDefaultWidget:(OGTKWidget*)widget
{
	gtk_popover_set_default_widget(GTK_POPOVER([self GOBJECT]), [widget WIDGET]);
}

- (void)setModal:(bool)modal
{
	gtk_popover_set_modal(GTK_POPOVER([self GOBJECT]), modal);
}

- (void)setPointingTo:(const GdkRectangle*)rect
{
	gtk_popover_set_pointing_to(GTK_POPOVER([self GOBJECT]), rect);
}

- (void)setPosition:(GtkPositionType)position
{
	gtk_popover_set_position(GTK_POPOVER([self GOBJECT]), position);
}

- (void)setRelativeTo:(OGTKWidget*)relativeTo
{
	gtk_popover_set_relative_to(GTK_POPOVER([self GOBJECT]), [relativeTo WIDGET]);
}

- (void)setTransitionsEnabled:(bool)transitionsEnabled
{
	gtk_popover_set_transitions_enabled(GTK_POPOVER([self GOBJECT]), transitionsEnabled);
}


@end