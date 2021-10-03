/*
 * OGTKPaned.m
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
#import "OGTKPaned.h"

@implementation OGTKPaned

- (id)init:(GtkOrientation)orientation
{
	self = [super initWithGObject:(GObject*)gtk_paned_new(orientation)];

	return self;
}

- (GtkPaned*)PANED
{
	return GTK_PANED([self GOBJECT]);
}

- (void)add1:(OGTKWidget*)child
{
	gtk_paned_add1(GTK_PANED([self GOBJECT]), [child WIDGET]);
}

- (void)add2:(OGTKWidget*)child
{
	gtk_paned_add2(GTK_PANED([self GOBJECT]), [child WIDGET]);
}

- (OGTKWidget*)getChild1
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_paned_get_child1(GTK_PANED([self GOBJECT]))];
}

- (OGTKWidget*)getChild2
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_paned_get_child2(GTK_PANED([self GOBJECT]))];
}

- (GdkWindow*)getHandleWindow
{
	return gtk_paned_get_handle_window(GTK_PANED([self GOBJECT]));
}

- (gint)getPosition
{
	return gtk_paned_get_position(GTK_PANED([self GOBJECT]));
}

- (bool)getWideHandle
{
	return gtk_paned_get_wide_handle(GTK_PANED([self GOBJECT]));
}

- (void)pack1WithChild:(OGTKWidget*)child andResize:(bool)resize andShrink:(bool)shrink
{
	gtk_paned_pack1(GTK_PANED([self GOBJECT]), [child WIDGET], resize, shrink);
}

- (void)pack2WithChild:(OGTKWidget*)child andResize:(bool)resize andShrink:(bool)shrink
{
	gtk_paned_pack2(GTK_PANED([self GOBJECT]), [child WIDGET], resize, shrink);
}

- (void)setPosition:(gint)position
{
	gtk_paned_set_position(GTK_PANED([self GOBJECT]), position);
}

- (void)setWideHandle:(bool)wide
{
	gtk_paned_set_wide_handle(GTK_PANED([self GOBJECT]), wide);
}


@end