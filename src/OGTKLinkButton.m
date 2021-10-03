/*
 * OGTKLinkButton.m
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
#import "OGTKLinkButton.h"

@implementation OGTKLinkButton

- (id)init:(OFString*)uri
{
	self = [super initWithGObject:(GObject*)gtk_link_button_new([uri UTF8String])];

	return self;
}

- (id)initWithLabelWithUri:(OFString*)uri andLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_link_button_new_with_label([uri UTF8String], [label UTF8String])];

	return self;
}

- (GtkLinkButton*)LINKBUTTON
{
	return GTK_LINK_BUTTON([self GOBJECT]);
}

- (OFString*)getUri
{
	return [OFString stringWithUTF8String:gtk_link_button_get_uri(GTK_LINK_BUTTON([self GOBJECT]))];
}

- (bool)getVisited
{
	return gtk_link_button_get_visited(GTK_LINK_BUTTON([self GOBJECT]));
}

- (void)setUri:(OFString*)uri
{
	gtk_link_button_set_uri(GTK_LINK_BUTTON([self GOBJECT]), [uri UTF8String]);
}

- (void)setVisited:(bool)visited
{
	gtk_link_button_set_visited(GTK_LINK_BUTTON([self GOBJECT]), visited);
}


@end