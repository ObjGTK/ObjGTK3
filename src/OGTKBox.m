/*
 * OGTKBox.m
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
#import "OGTKBox.h"

@implementation OGTKBox

- (id)initWithOrientation:(GtkOrientation)orientation andSpacing:(gint)spacing
{
	self = [super initWithGObject:(GObject*)gtk_box_new(orientation, spacing)];

	return self;
}

- (GtkBox*)BOX
{
	return GTK_BOX([self GOBJECT]);
}

- (GtkBaselinePosition)getBaselinePosition
{
	return gtk_box_get_baseline_position(GTK_BOX([self GOBJECT]));
}

- (OGTKWidget*)getCenterWidget
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_box_get_center_widget(GTK_BOX([self GOBJECT]))];
}

- (bool)getHomogeneous
{
	return gtk_box_get_homogeneous(GTK_BOX([self GOBJECT]));
}

- (gint)getSpacing
{
	return gtk_box_get_spacing(GTK_BOX([self GOBJECT]));
}

- (void)packEndWithChild:(OGTKWidget*)child andExpand:(bool)expand andFill:(bool)fill andPadding:(guint)padding
{
	gtk_box_pack_end(GTK_BOX([self GOBJECT]), [child WIDGET], expand, fill, padding);
}

- (void)packStartWithChild:(OGTKWidget*)child andExpand:(bool)expand andFill:(bool)fill andPadding:(guint)padding
{
	gtk_box_pack_start(GTK_BOX([self GOBJECT]), [child WIDGET], expand, fill, padding);
}

- (void)queryChildPackingWithChild:(OGTKWidget*)child andExpand:(gboolean*)expand andFill:(gboolean*)fill andPadding:(guint*)padding andPackType:(GtkPackType*)packType
{
	gtk_box_query_child_packing(GTK_BOX([self GOBJECT]), [child WIDGET], expand, fill, padding, packType);
}

- (void)reorderChildWithChild:(OGTKWidget*)child andPosition:(gint)position
{
	gtk_box_reorder_child(GTK_BOX([self GOBJECT]), [child WIDGET], position);
}

- (void)setBaselinePosition:(GtkBaselinePosition)position
{
	gtk_box_set_baseline_position(GTK_BOX([self GOBJECT]), position);
}

- (void)setCenterWidget:(OGTKWidget*)widget
{
	gtk_box_set_center_widget(GTK_BOX([self GOBJECT]), [widget WIDGET]);
}

- (void)setChildPackingWithChild:(OGTKWidget*)child andExpand:(bool)expand andFill:(bool)fill andPadding:(guint)padding andPackType:(GtkPackType)packType
{
	gtk_box_set_child_packing(GTK_BOX([self GOBJECT]), [child WIDGET], expand, fill, padding, packType);
}

- (void)setHomogeneous:(bool)homogeneous
{
	gtk_box_set_homogeneous(GTK_BOX([self GOBJECT]), homogeneous);
}

- (void)setSpacing:(gint)spacing
{
	gtk_box_set_spacing(GTK_BOX([self GOBJECT]), spacing);
}


@end