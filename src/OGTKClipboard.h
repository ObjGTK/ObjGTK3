/*
 * OGTKClipboard.h
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
#import "OGTKBase.h"

@interface OGTKClipboard : OGTKBase
{

}

/**
 * Functions
 */
+ (GtkClipboard*)get:(GdkAtom)selection;
+ (GtkClipboard*)getDefault:(GdkDisplay*)display;
+ (GtkClipboard*)getForDisplayWithDisplay:(GdkDisplay*)display andSelection:(GdkAtom)selection;

/**
 * Methods
 */

- (GtkClipboard*)CLIPBOARD;

/**
 * - (void*)clear;
 *
 */
- (void)clear;

/**
 * - (GdkDisplay**)getDisplay;
 *
 * @returns GdkDisplay*
 */
- (GdkDisplay*)getDisplay;

/**
 * - (GObject**)getOwner;
 *
 * @returns GObject*
 */
- (GObject*)getOwner;

/**
 * - (GdkAtom*)getSelection;
 *
 * @returns GdkAtom
 */
- (GdkAtom)getSelection;

/**
 * - (void*)requestContentsWithTarget:(GdkAtom)target andCallback:(GtkClipboardReceivedFunc)callback andUserData:(gpointer)userData;
 *
 * @param target
 * @param callback
 * @param userData
 */
- (void)requestContentsWithTarget:(GdkAtom)target andCallback:(GtkClipboardReceivedFunc)callback andUserData:(gpointer)userData;

/**
 * - (void*)requestImageWithCallback:(GtkClipboardImageReceivedFunc)callback andUserData:(gpointer)userData;
 *
 * @param callback
 * @param userData
 */
- (void)requestImageWithCallback:(GtkClipboardImageReceivedFunc)callback andUserData:(gpointer)userData;

/**
 * - (void*)requestRichTextWithBuffer:(GtkTextBuffer*)buffer andCallback:(GtkClipboardRichTextReceivedFunc)callback andUserData:(gpointer)userData;
 *
 * @param buffer
 * @param callback
 * @param userData
 */
- (void)requestRichTextWithBuffer:(GtkTextBuffer*)buffer andCallback:(GtkClipboardRichTextReceivedFunc)callback andUserData:(gpointer)userData;

/**
 * - (void*)requestTargetsWithCallback:(GtkClipboardTargetsReceivedFunc)callback andUserData:(gpointer)userData;
 *
 * @param callback
 * @param userData
 */
- (void)requestTargetsWithCallback:(GtkClipboardTargetsReceivedFunc)callback andUserData:(gpointer)userData;

/**
 * - (void*)requestTextWithCallback:(GtkClipboardTextReceivedFunc)callback andUserData:(gpointer)userData;
 *
 * @param callback
 * @param userData
 */
- (void)requestTextWithCallback:(GtkClipboardTextReceivedFunc)callback andUserData:(gpointer)userData;

/**
 * - (void*)requestUrisWithCallback:(GtkClipboardURIReceivedFunc)callback andUserData:(gpointer)userData;
 *
 * @param callback
 * @param userData
 */
- (void)requestUrisWithCallback:(GtkClipboardURIReceivedFunc)callback andUserData:(gpointer)userData;

/**
 * - (void*)setCanStoreWithTargets:(const GtkTargetEntry*)targets andNtargets:(gint)ntargets;
 *
 * @param targets
 * @param ntargets
 */
- (void)setCanStoreWithTargets:(const GtkTargetEntry*)targets andNtargets:(gint)ntargets;

/**
 * - (void*)setImage:(GdkPixbuf*)pixbuf;
 *
 * @param pixbuf
 */
- (void)setImage:(GdkPixbuf*)pixbuf;

/**
 * - (void*)setTextWithText:(OFString*)text andLen:(gint)len;
 *
 * @param text
 * @param len
 */
- (void)setTextWithText:(OFString*)text andLen:(gint)len;

/**
 * - (bool*)setWithDataWithTargets:(const GtkTargetEntry*)targets andNtargets:(guint)ntargets andGetFunc:(GtkClipboardGetFunc)getFunc andClearFunc:(GtkClipboardClearFunc)clearFunc andUserData:(gpointer)userData;
 *
 * @param targets
 * @param ntargets
 * @param getFunc
 * @param clearFunc
 * @param userData
 * @returns bool
 */
- (bool)setWithDataWithTargets:(const GtkTargetEntry*)targets andNtargets:(guint)ntargets andGetFunc:(GtkClipboardGetFunc)getFunc andClearFunc:(GtkClipboardClearFunc)clearFunc andUserData:(gpointer)userData;

/**
 * - (bool*)setWithOwnerWithTargets:(const GtkTargetEntry*)targets andNtargets:(guint)ntargets andGetFunc:(GtkClipboardGetFunc)getFunc andClearFunc:(GtkClipboardClearFunc)clearFunc andOwner:(GObject*)owner;
 *
 * @param targets
 * @param ntargets
 * @param getFunc
 * @param clearFunc
 * @param owner
 * @returns bool
 */
- (bool)setWithOwnerWithTargets:(const GtkTargetEntry*)targets andNtargets:(guint)ntargets andGetFunc:(GtkClipboardGetFunc)getFunc andClearFunc:(GtkClipboardClearFunc)clearFunc andOwner:(GObject*)owner;

/**
 * - (void*)store;
 *
 */
- (void)store;

/**
 * - (GtkSelectionData**)waitForContents:(GdkAtom)target;
 *
 * @param target
 * @returns GtkSelectionData*
 */
- (GtkSelectionData*)waitForContents:(GdkAtom)target;

/**
 * - (GdkPixbuf**)waitForImage;
 *
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)waitForImage;

/**
 * - (guint8**)waitForRichTextWithBuffer:(GtkTextBuffer*)buffer andFormat:(GdkAtom*)format andLength:(gsize*)length;
 *
 * @param buffer
 * @param format
 * @param length
 * @returns guint8*
 */
- (guint8*)waitForRichTextWithBuffer:(GtkTextBuffer*)buffer andFormat:(GdkAtom*)format andLength:(gsize*)length;

/**
 * - (bool*)waitForTargetsWithTargets:(GdkAtom**)targets andNtargets:(gint*)ntargets;
 *
 * @param targets
 * @param ntargets
 * @returns bool
 */
- (bool)waitForTargetsWithTargets:(GdkAtom**)targets andNtargets:(gint*)ntargets;

/**
 * - (OFString**)waitForText;
 *
 * @returns OFString*
 */
- (OFString*)waitForText;

/**
 * - (gchar***)waitForUris;
 *
 * @returns gchar**
 */
- (gchar**)waitForUris;

/**
 * - (bool*)waitIsImageAvailable;
 *
 * @returns bool
 */
- (bool)waitIsImageAvailable;

/**
 * - (bool*)waitIsRichTextAvailable:(GtkTextBuffer*)buffer;
 *
 * @param buffer
 * @returns bool
 */
- (bool)waitIsRichTextAvailable:(GtkTextBuffer*)buffer;

/**
 * - (bool*)waitIsTargetAvailable:(GdkAtom)target;
 *
 * @param target
 * @returns bool
 */
- (bool)waitIsTargetAvailable:(GdkAtom)target;

/**
 * - (bool*)waitIsTextAvailable;
 *
 * @returns bool
 */
- (bool)waitIsTextAvailable;

/**
 * - (bool*)waitIsUrisAvailable;
 *
 * @returns bool
 */
- (bool)waitIsUrisAvailable;

@end