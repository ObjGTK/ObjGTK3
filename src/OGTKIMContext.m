/*
 * OGTKIMContext.m
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
#import "OGTKIMContext.h"

@implementation OGTKIMContext

- (GtkIMContext*)IMCONTEXT
{
	return GTK_IMCONTEXT([self GOBJECT]);
}

- (bool)gtkImContextDeleteSurroundingWithOffset:(gint)offset andNchars:(gint)nchars
{
	return gtk_im_context_delete_surrounding(GTK_IMCONTEXT([self GOBJECT]), offset, nchars);
}

- (bool)gtkImContextFilterKeypress:(GdkEventKey*)event
{
	return gtk_im_context_filter_keypress(GTK_IMCONTEXT([self GOBJECT]), event);
}

- (void)gtkImContextFocusIn
{
	gtk_im_context_focus_in(GTK_IMCONTEXT([self GOBJECT]));
}

- (void)gtkImContextFocusOut
{
	gtk_im_context_focus_out(GTK_IMCONTEXT([self GOBJECT]));
}

- (void)gtkImContextGetPreeditStringWithStr:(gchar**)str andAttrs:(PangoAttrList**)attrs andCursorPos:(gint*)cursorPos
{
	gtk_im_context_get_preedit_string(GTK_IMCONTEXT([self GOBJECT]), str, attrs, cursorPos);
}

- (bool)gtkImContextGetSurroundingWithText:(gchar**)text andCursorIndex:(gint*)cursorIndex
{
	return gtk_im_context_get_surrounding(GTK_IMCONTEXT([self GOBJECT]), text, cursorIndex);
}

- (void)gtkImContextReset
{
	gtk_im_context_reset(GTK_IMCONTEXT([self GOBJECT]));
}

- (void)gtkImContextSetClientWindow:(GdkWindow*)window
{
	gtk_im_context_set_client_window(GTK_IMCONTEXT([self GOBJECT]), window);
}

- (void)gtkImContextSetCursorLocation:(const GdkRectangle*)area
{
	gtk_im_context_set_cursor_location(GTK_IMCONTEXT([self GOBJECT]), area);
}

- (void)gtkImContextSetSurroundingWithText:(OFString*)text andLen:(gint)len andCursorIndex:(gint)cursorIndex
{
	gtk_im_context_set_surrounding(GTK_IMCONTEXT([self GOBJECT]), [text UTF8String], len, cursorIndex);
}

- (void)gtkImContextSetUsePreedit:(bool)usePreedit
{
	gtk_im_context_set_use_preedit(GTK_IMCONTEXT([self GOBJECT]), usePreedit);
}


@end