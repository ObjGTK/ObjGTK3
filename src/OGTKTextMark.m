/*
 * OGTKTextMark.m
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
#import "OGTKTextMark.h"

@implementation OGTKTextMark

- (id)initWithName:(OFString*)name andLeftGravity:(bool)leftGravity
{
	self = [super initWithGObject:(GObject*)gtk_text_mark_new([name UTF8String], leftGravity)];

	return self;
}

- (GtkTextMark*)TEXTMARK
{
	return GTK_TEXT_MARK([self GOBJECT]);
}

- (GtkTextBuffer*)getBuffer
{
	return gtk_text_mark_get_buffer(GTK_TEXT_MARK([self GOBJECT]));
}

- (bool)getDeleted
{
	return gtk_text_mark_get_deleted(GTK_TEXT_MARK([self GOBJECT]));
}

- (bool)getLeftGravity
{
	return gtk_text_mark_get_left_gravity(GTK_TEXT_MARK([self GOBJECT]));
}

- (OFString*)getName
{
	return [OFString stringWithUTF8String:gtk_text_mark_get_name(GTK_TEXT_MARK([self GOBJECT]))];
}

- (bool)getVisible
{
	return gtk_text_mark_get_visible(GTK_TEXT_MARK([self GOBJECT]));
}

- (void)setVisible:(bool)setting
{
	gtk_text_mark_set_visible(GTK_TEXT_MARK([self GOBJECT]), setting);
}


@end