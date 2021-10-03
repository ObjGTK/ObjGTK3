/*
 * OGTKStatusbar.m
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
#import "OGTKStatusbar.h"

@implementation OGTKStatusbar

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_statusbar_new()];

	return self;
}

- (GtkStatusbar*)STATUSBAR
{
	return GTK_STATUSBAR([self GOBJECT]);
}

- (guint)getContextId:(OFString*)contextDescription
{
	return gtk_statusbar_get_context_id(GTK_STATUSBAR([self GOBJECT]), [contextDescription UTF8String]);
}

- (OGTKWidget*)getMessageArea
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_statusbar_get_message_area(GTK_STATUSBAR([self GOBJECT]))];
}

- (void)pop:(guint)contextId
{
	gtk_statusbar_pop(GTK_STATUSBAR([self GOBJECT]), contextId);
}

- (guint)pushWithContextId:(guint)contextId andText:(OFString*)text
{
	return gtk_statusbar_push(GTK_STATUSBAR([self GOBJECT]), contextId, [text UTF8String]);
}

- (void)removeWithContextId:(guint)contextId andMessageId:(guint)messageId
{
	gtk_statusbar_remove(GTK_STATUSBAR([self GOBJECT]), contextId, messageId);
}

- (void)removeAll:(guint)contextId
{
	gtk_statusbar_remove_all(GTK_STATUSBAR([self GOBJECT]), contextId);
}


@end