/*
 * OGTKOverlay.m
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
#import "OGTKOverlay.h"

@implementation OGTKOverlay

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_overlay_new()];

	return self;
}

- (GtkOverlay*)OVERLAY
{
	return GTK_OVERLAY([self GOBJECT]);
}

- (void)addOverlay:(OGTKWidget*)widget
{
	gtk_overlay_add_overlay(GTK_OVERLAY([self GOBJECT]), [widget WIDGET]);
}

- (bool)getOverlayPassThrough:(OGTKWidget*)widget
{
	return gtk_overlay_get_overlay_pass_through(GTK_OVERLAY([self GOBJECT]), [widget WIDGET]);
}

- (void)reorderOverlayWithChild:(OGTKWidget*)child andIndex:(int)index
{
	gtk_overlay_reorder_overlay(GTK_OVERLAY([self GOBJECT]), [child WIDGET], index);
}

- (void)setOverlayPassThroughWithWidget:(OGTKWidget*)widget andPassThrough:(bool)passThrough
{
	gtk_overlay_set_overlay_pass_through(GTK_OVERLAY([self GOBJECT]), [widget WIDGET], passThrough);
}


@end