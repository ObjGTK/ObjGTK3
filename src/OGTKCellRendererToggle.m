/*
 * OGTKCellRendererToggle.m
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
#import "OGTKCellRendererToggle.h"

@implementation OGTKCellRendererToggle

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_cell_renderer_toggle_new()];

	return self;
}

- (GtkCellRendererToggle*)CELLRENDERERTOGGLE
{
	return GTK_CELL_RENDERER_TOGGLE([self GOBJECT]);
}

- (bool)getActivatable
{
	return gtk_cell_renderer_toggle_get_activatable(GTK_CELL_RENDERER_TOGGLE([self GOBJECT]));
}

- (bool)getActive
{
	return gtk_cell_renderer_toggle_get_active(GTK_CELL_RENDERER_TOGGLE([self GOBJECT]));
}

- (bool)getRadio
{
	return gtk_cell_renderer_toggle_get_radio(GTK_CELL_RENDERER_TOGGLE([self GOBJECT]));
}

- (void)setActivatable:(bool)setting
{
	gtk_cell_renderer_toggle_set_activatable(GTK_CELL_RENDERER_TOGGLE([self GOBJECT]), setting);
}

- (void)setActive:(bool)setting
{
	gtk_cell_renderer_toggle_set_active(GTK_CELL_RENDERER_TOGGLE([self GOBJECT]), setting);
}

- (void)setRadio:(bool)radio
{
	gtk_cell_renderer_toggle_set_radio(GTK_CELL_RENDERER_TOGGLE([self GOBJECT]), radio);
}


@end