/*
 * OGTKIMContextSimple.m
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
#import "OGTKIMContextSimple.h"

@implementation OGTKIMContextSimple

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_im_context_simple_new()];

	return self;
}

- (GtkIMContextSimple*)IMCONTEXTSIMPLE
{
	return GTK_IMCONTEXT_SIMPLE([self GOBJECT]);
}

- (void)gtkImContextSimpleAddComposeFile:(OFString*)composeFile
{
	gtk_im_context_simple_add_compose_file(GTK_IMCONTEXT_SIMPLE([self GOBJECT]), [composeFile UTF8String]);
}

- (void)gtkImContextSimpleAddTableWithData:(guint16*)data andMaxSeqLen:(gint)maxSeqLen andNseqs:(gint)nseqs
{
	gtk_im_context_simple_add_table(GTK_IMCONTEXT_SIMPLE([self GOBJECT]), data, maxSeqLen, nseqs);
}


@end