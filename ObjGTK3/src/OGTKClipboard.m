/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKClipboard.h"

#import <OGGdkPixbuf/OGGdkPixbuf.h>
#import <OGdk3/OGGdkDisplay.h>
#import "OGTKTextBuffer.h"

@implementation OGTKClipboard

+ (OGTKClipboard*)instance:(GdkAtom)selection
{
	return [[[OGTKClipboard alloc] initWithGObject:(GObject*)gtk_clipboard_get(selection)] autorelease];
}

+ (OGTKClipboard*)default:(OGGdkDisplay*)display
{
	return [[[OGTKClipboard alloc] initWithGObject:(GObject*)gtk_clipboard_get_default([display DISPLAY])] autorelease];
}

+ (OGTKClipboard*)forDisplayWithDisplay:(OGGdkDisplay*)display selection:(GdkAtom)selection
{
	return [[[OGTKClipboard alloc] initWithGObject:(GObject*)gtk_clipboard_get_for_display([display DISPLAY], selection)] autorelease];
}

- (GtkClipboard*)CLIPBOARD
{
	return GTK_CLIPBOARD([self GOBJECT]);
}

- (void)clear
{
	gtk_clipboard_clear([self CLIPBOARD]);
}

- (OGGdkDisplay*)display
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gtk_clipboard_get_display([self CLIPBOARD])] autorelease];
}

- (GObject*)owner
{
	return gtk_clipboard_get_owner([self CLIPBOARD]);
}

- (GdkAtom)selection
{
	return gtk_clipboard_get_selection([self CLIPBOARD]);
}

- (void)requestContentsWithTarget:(GdkAtom)target callback:(GtkClipboardReceivedFunc)callback userData:(gpointer)userData
{
	gtk_clipboard_request_contents([self CLIPBOARD], target, callback, userData);
}

- (void)requestImageWithCallback:(GtkClipboardImageReceivedFunc)callback userData:(gpointer)userData
{
	gtk_clipboard_request_image([self CLIPBOARD], callback, userData);
}

- (void)requestRichTextWithBuffer:(OGTKTextBuffer*)buffer callback:(GtkClipboardRichTextReceivedFunc)callback userData:(gpointer)userData
{
	gtk_clipboard_request_rich_text([self CLIPBOARD], [buffer TEXTBUFFER], callback, userData);
}

- (void)requestTargetsWithCallback:(GtkClipboardTargetsReceivedFunc)callback userData:(gpointer)userData
{
	gtk_clipboard_request_targets([self CLIPBOARD], callback, userData);
}

- (void)requestTextWithCallback:(GtkClipboardTextReceivedFunc)callback userData:(gpointer)userData
{
	gtk_clipboard_request_text([self CLIPBOARD], callback, userData);
}

- (void)requestUrisWithCallback:(GtkClipboardURIReceivedFunc)callback userData:(gpointer)userData
{
	gtk_clipboard_request_uris([self CLIPBOARD], callback, userData);
}

- (void)setCanStoreWithTargets:(const GtkTargetEntry*)targets ntargets:(gint)ntargets
{
	gtk_clipboard_set_can_store([self CLIPBOARD], targets, ntargets);
}

- (void)setImage:(OGGdkPixbuf*)pixbuf
{
	gtk_clipboard_set_image([self CLIPBOARD], [pixbuf PIXBUF]);
}

- (void)setTextWithText:(OFString*)text len:(gint)len
{
	gtk_clipboard_set_text([self CLIPBOARD], [text UTF8String], len);
}

- (bool)setWithDataWithTargets:(const GtkTargetEntry*)targets ntargets:(guint)ntargets getFunc:(GtkClipboardGetFunc)getFunc clearFunc:(GtkClipboardClearFunc)clearFunc userData:(gpointer)userData
{
	return gtk_clipboard_set_with_data([self CLIPBOARD], targets, ntargets, getFunc, clearFunc, userData);
}

- (bool)setWithOwnerWithTargets:(const GtkTargetEntry*)targets ntargets:(guint)ntargets getFunc:(GtkClipboardGetFunc)getFunc clearFunc:(GtkClipboardClearFunc)clearFunc owner:(GObject*)owner
{
	return gtk_clipboard_set_with_owner([self CLIPBOARD], targets, ntargets, getFunc, clearFunc, owner);
}

- (void)store
{
	gtk_clipboard_store([self CLIPBOARD]);
}

- (GtkSelectionData*)waitForContents:(GdkAtom)target
{
	return gtk_clipboard_wait_for_contents([self CLIPBOARD], target);
}

- (OGGdkPixbuf*)waitForImage
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_clipboard_wait_for_image([self CLIPBOARD])] autorelease];
}

- (guint8*)waitForRichTextWithBuffer:(OGTKTextBuffer*)buffer format:(GdkAtom*)format length:(gsize*)length
{
	return gtk_clipboard_wait_for_rich_text([self CLIPBOARD], [buffer TEXTBUFFER], format, length);
}

- (bool)waitForTargetsWithTargets:(GdkAtom**)targets ntargets:(gint*)ntargets
{
	return gtk_clipboard_wait_for_targets([self CLIPBOARD], targets, ntargets);
}

- (OFString*)waitForText
{
	return [OFString stringWithUTF8String:gtk_clipboard_wait_for_text([self CLIPBOARD])];
}

- (gchar**)waitForUris
{
	return gtk_clipboard_wait_for_uris([self CLIPBOARD]);
}

- (bool)waitIsImageAvailable
{
	return gtk_clipboard_wait_is_image_available([self CLIPBOARD]);
}

- (bool)waitIsRichTextAvailable:(OGTKTextBuffer*)buffer
{
	return gtk_clipboard_wait_is_rich_text_available([self CLIPBOARD], [buffer TEXTBUFFER]);
}

- (bool)waitIsTargetAvailable:(GdkAtom)target
{
	return gtk_clipboard_wait_is_target_available([self CLIPBOARD], target);
}

- (bool)waitIsTextAvailable
{
	return gtk_clipboard_wait_is_text_available([self CLIPBOARD]);
}

- (bool)waitIsUrisAvailable
{
	return gtk_clipboard_wait_is_uris_available([self CLIPBOARD]);
}


@end