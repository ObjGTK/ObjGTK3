/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKIMContext.h"

#import <OGdk3/OGGdkWindow.h>

@implementation OGTKIMContext

- (GtkIMContext*)IMCONTEXT
{
	return GTK_IM_CONTEXT([self GOBJECT]);
}

- (bool)deleteSurroundingWithOffset:(gint)offset nchars:(gint)nchars
{
	return gtk_im_context_delete_surrounding([self IMCONTEXT], offset, nchars);
}

- (bool)filterKeypress:(GdkEventKey*)event
{
	return gtk_im_context_filter_keypress([self IMCONTEXT], event);
}

- (void)focusIn
{
	gtk_im_context_focus_in([self IMCONTEXT]);
}

- (void)focusOut
{
	gtk_im_context_focus_out([self IMCONTEXT]);
}

- (void)preeditStringWithStr:(gchar**)str attrs:(PangoAttrList**)attrs cursorPos:(gint*)cursorPos
{
	gtk_im_context_get_preedit_string([self IMCONTEXT], str, attrs, cursorPos);
}

- (bool)surroundingWithText:(gchar**)text cursorIndex:(gint*)cursorIndex
{
	return gtk_im_context_get_surrounding([self IMCONTEXT], text, cursorIndex);
}

- (void)reset
{
	gtk_im_context_reset([self IMCONTEXT]);
}

- (void)setClientWindow:(OGGdkWindow*)window
{
	gtk_im_context_set_client_window([self IMCONTEXT], [window WINDOW]);
}

- (void)setCursorLocation:(const GdkRectangle*)area
{
	gtk_im_context_set_cursor_location([self IMCONTEXT], area);
}

- (void)setSurroundingWithText:(OFString*)text len:(gint)len cursorIndex:(gint)cursorIndex
{
	gtk_im_context_set_surrounding([self IMCONTEXT], [text UTF8String], len, cursorIndex);
}

- (void)setUsePreedit:(bool)usePreedit
{
	gtk_im_context_set_use_preedit([self IMCONTEXT], usePreedit);
}


@end