/*
 * OGTKClipboard.m
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
#import "OGTKClipboard.h"

@implementation OGTKClipboard

+ (GtkClipboard*)get:(GdkAtom)selection
{
	return gtk_clipboard_get(selection);
}

+ (GtkClipboard*)getDefault:(GdkDisplay*)display
{
	return gtk_clipboard_get_default(display);
}

+ (GtkClipboard*)getForDisplayWithDisplay:(GdkDisplay*)display andSelection:(GdkAtom)selection
{
	return gtk_clipboard_get_for_display(display, selection);
}

- (GtkClipboard*)CLIPBOARD
{
	return GTK_CLIPBOARD([self GOBJECT]);
}

- (void)clear
{
	gtk_clipboard_clear(GTK_CLIPBOARD([self GOBJECT]));
}

- (GdkDisplay*)getDisplay
{
	return gtk_clipboard_get_display(GTK_CLIPBOARD([self GOBJECT]));
}

- (GObject*)getOwner
{
	return gtk_clipboard_get_owner(GTK_CLIPBOARD([self GOBJECT]));
}

- (GdkAtom)getSelection
{
	return gtk_clipboard_get_selection(GTK_CLIPBOARD([self GOBJECT]));
}

- (void)requestContentsWithTarget:(GdkAtom)target andCallback:(GtkClipboardReceivedFunc)callback andUserData:(gpointer)userData
{
	gtk_clipboard_request_contents(GTK_CLIPBOARD([self GOBJECT]), target, callback, userData);
}

- (void)requestImageWithCallback:(GtkClipboardImageReceivedFunc)callback andUserData:(gpointer)userData
{
	gtk_clipboard_request_image(GTK_CLIPBOARD([self GOBJECT]), callback, userData);
}

- (void)requestRichTextWithBuffer:(GtkTextBuffer*)buffer andCallback:(GtkClipboardRichTextReceivedFunc)callback andUserData:(gpointer)userData
{
	gtk_clipboard_request_rich_text(GTK_CLIPBOARD([self GOBJECT]), buffer, callback, userData);
}

- (void)requestTargetsWithCallback:(GtkClipboardTargetsReceivedFunc)callback andUserData:(gpointer)userData
{
	gtk_clipboard_request_targets(GTK_CLIPBOARD([self GOBJECT]), callback, userData);
}

- (void)requestTextWithCallback:(GtkClipboardTextReceivedFunc)callback andUserData:(gpointer)userData
{
	gtk_clipboard_request_text(GTK_CLIPBOARD([self GOBJECT]), callback, userData);
}

- (void)requestUrisWithCallback:(GtkClipboardURIReceivedFunc)callback andUserData:(gpointer)userData
{
	gtk_clipboard_request_uris(GTK_CLIPBOARD([self GOBJECT]), callback, userData);
}

- (void)setCanStoreWithTargets:(const GtkTargetEntry*)targets andNtargets:(gint)ntargets
{
	gtk_clipboard_set_can_store(GTK_CLIPBOARD([self GOBJECT]), targets, ntargets);
}

- (void)setImage:(GdkPixbuf*)pixbuf
{
	gtk_clipboard_set_image(GTK_CLIPBOARD([self GOBJECT]), pixbuf);
}

- (void)setTextWithText:(OFString*)text andLen:(gint)len
{
	gtk_clipboard_set_text(GTK_CLIPBOARD([self GOBJECT]), [text UTF8String], len);
}

- (bool)setWithDataWithTargets:(const GtkTargetEntry*)targets andNtargets:(guint)ntargets andGetFunc:(GtkClipboardGetFunc)getFunc andClearFunc:(GtkClipboardClearFunc)clearFunc andUserData:(gpointer)userData
{
	return gtk_clipboard_set_with_data(GTK_CLIPBOARD([self GOBJECT]), targets, ntargets, getFunc, clearFunc, userData);
}

- (bool)setWithOwnerWithTargets:(const GtkTargetEntry*)targets andNtargets:(guint)ntargets andGetFunc:(GtkClipboardGetFunc)getFunc andClearFunc:(GtkClipboardClearFunc)clearFunc andOwner:(GObject*)owner
{
	return gtk_clipboard_set_with_owner(GTK_CLIPBOARD([self GOBJECT]), targets, ntargets, getFunc, clearFunc, owner);
}

- (void)store
{
	gtk_clipboard_store(GTK_CLIPBOARD([self GOBJECT]));
}

- (GtkSelectionData*)waitForContents:(GdkAtom)target
{
	return gtk_clipboard_wait_for_contents(GTK_CLIPBOARD([self GOBJECT]), target);
}

- (GdkPixbuf*)waitForImage
{
	return gtk_clipboard_wait_for_image(GTK_CLIPBOARD([self GOBJECT]));
}

- (guint8*)waitForRichTextWithBuffer:(GtkTextBuffer*)buffer andFormat:(GdkAtom*)format andLength:(gsize*)length
{
	return gtk_clipboard_wait_for_rich_text(GTK_CLIPBOARD([self GOBJECT]), buffer, format, length);
}

- (bool)waitForTargetsWithTargets:(GdkAtom**)targets andNtargets:(gint*)ntargets
{
	return gtk_clipboard_wait_for_targets(GTK_CLIPBOARD([self GOBJECT]), targets, ntargets);
}

- (OFString*)waitForText
{
	return [OFString stringWithUTF8String:gtk_clipboard_wait_for_text(GTK_CLIPBOARD([self GOBJECT]))];
}

- (gchar**)waitForUris
{
	return gtk_clipboard_wait_for_uris(GTK_CLIPBOARD([self GOBJECT]));
}

- (bool)waitIsImageAvailable
{
	return gtk_clipboard_wait_is_image_available(GTK_CLIPBOARD([self GOBJECT]));
}

- (bool)waitIsRichTextAvailable:(GtkTextBuffer*)buffer
{
	return gtk_clipboard_wait_is_rich_text_available(GTK_CLIPBOARD([self GOBJECT]), buffer);
}

- (bool)waitIsTargetAvailable:(GdkAtom)target
{
	return gtk_clipboard_wait_is_target_available(GTK_CLIPBOARD([self GOBJECT]), target);
}

- (bool)waitIsTextAvailable
{
	return gtk_clipboard_wait_is_text_available(GTK_CLIPBOARD([self GOBJECT]));
}

- (bool)waitIsUrisAvailable
{
	return gtk_clipboard_wait_is_uris_available(GTK_CLIPBOARD([self GOBJECT]));
}


@end