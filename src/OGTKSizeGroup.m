/*
 * OGTKSizeGroup.m
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
#import "OGTKSizeGroup.h"

@implementation OGTKSizeGroup

- (id)init:(GtkSizeGroupMode)mode
{
	self = [super initWithGObject:(GObject*)gtk_size_group_new(mode)];

	return self;
}

- (GtkSizeGroup*)SIZEGROUP
{
	return GTK_SIZE_GROUP([self GOBJECT]);
}

- (void)addWidget:(OGTKWidget*)widget
{
	gtk_size_group_add_widget(GTK_SIZE_GROUP([self GOBJECT]), [widget WIDGET]);
}

- (bool)getIgnoreHidden
{
	return gtk_size_group_get_ignore_hidden(GTK_SIZE_GROUP([self GOBJECT]));
}

- (GtkSizeGroupMode)getMode
{
	return gtk_size_group_get_mode(GTK_SIZE_GROUP([self GOBJECT]));
}

- (GSList*)getWidgets
{
	return gtk_size_group_get_widgets(GTK_SIZE_GROUP([self GOBJECT]));
}

- (void)removeWidget:(OGTKWidget*)widget
{
	gtk_size_group_remove_widget(GTK_SIZE_GROUP([self GOBJECT]), [widget WIDGET]);
}

- (void)setIgnoreHidden:(bool)ignoreHidden
{
	gtk_size_group_set_ignore_hidden(GTK_SIZE_GROUP([self GOBJECT]), ignoreHidden);
}

- (void)setMode:(GtkSizeGroupMode)mode
{
	gtk_size_group_set_mode(GTK_SIZE_GROUP([self GOBJECT]), mode);
}


@end