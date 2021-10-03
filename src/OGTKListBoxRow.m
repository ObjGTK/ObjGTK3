/*
 * OGTKListBoxRow.m
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
#import "OGTKListBoxRow.h"

@implementation OGTKListBoxRow

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_list_box_row_new()];

	return self;
}

- (GtkListBoxRow*)LISTBOXROW
{
	return GTK_LIST_BOX_ROW([self GOBJECT]);
}

- (void)changed
{
	gtk_list_box_row_changed(GTK_LIST_BOX_ROW([self GOBJECT]));
}

- (bool)getActivatable
{
	return gtk_list_box_row_get_activatable(GTK_LIST_BOX_ROW([self GOBJECT]));
}

- (OGTKWidget*)getHeader
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_list_box_row_get_header(GTK_LIST_BOX_ROW([self GOBJECT]))];
}

- (gint)getIndex
{
	return gtk_list_box_row_get_index(GTK_LIST_BOX_ROW([self GOBJECT]));
}

- (bool)getSelectable
{
	return gtk_list_box_row_get_selectable(GTK_LIST_BOX_ROW([self GOBJECT]));
}

- (bool)isSelected
{
	return gtk_list_box_row_is_selected(GTK_LIST_BOX_ROW([self GOBJECT]));
}

- (void)setActivatable:(bool)activatable
{
	gtk_list_box_row_set_activatable(GTK_LIST_BOX_ROW([self GOBJECT]), activatable);
}

- (void)setHeader:(OGTKWidget*)header
{
	gtk_list_box_row_set_header(GTK_LIST_BOX_ROW([self GOBJECT]), [header WIDGET]);
}

- (void)setSelectable:(bool)selectable
{
	gtk_list_box_row_set_selectable(GTK_LIST_BOX_ROW([self GOBJECT]), selectable);
}


@end