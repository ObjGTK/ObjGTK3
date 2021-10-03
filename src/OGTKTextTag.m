/*
 * OGTKTextTag.m
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
#import "OGTKTextTag.h"

@implementation OGTKTextTag

- (id)init:(OFString*)name
{
	self = [super initWithGObject:(GObject*)gtk_text_tag_new([name UTF8String])];

	return self;
}

- (GtkTextTag*)TEXTTAG
{
	return GTK_TEXT_TAG([self GOBJECT]);
}

- (void)changed:(bool)sizeChanged
{
	gtk_text_tag_changed(GTK_TEXT_TAG([self GOBJECT]), sizeChanged);
}

- (bool)eventWithEventObject:(GObject*)eventObject andEvent:(GdkEvent*)event andIter:(const GtkTextIter*)iter
{
	return gtk_text_tag_event(GTK_TEXT_TAG([self GOBJECT]), eventObject, event, iter);
}

- (gint)getPriority
{
	return gtk_text_tag_get_priority(GTK_TEXT_TAG([self GOBJECT]));
}

- (void)setPriority:(gint)priority
{
	gtk_text_tag_set_priority(GTK_TEXT_TAG([self GOBJECT]), priority);
}


@end