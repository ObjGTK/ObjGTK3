/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

@class OGGdkPixbuf;
@class OGTKTextBuffer;
@class OGGdkDisplay;

/**
 * The #GtkClipboard object represents a clipboard of data shared
 * between different processes or between different widgets in
 * the same process. Each clipboard is identified by a name encoded as a
 * #GdkAtom. (Conversion to and from strings can be done with
 * gdk_atom_intern() and gdk_atom_name().) The default clipboard
 * corresponds to the “CLIPBOARD” atom; another commonly used clipboard
 * is the “PRIMARY” clipboard, which, in X, traditionally contains
 * the currently selected text.
 * 
 * To support having a number of different formats on the clipboard
 * at the same time, the clipboard mechanism allows providing
 * callbacks instead of the actual data.  When you set the contents
 * of the clipboard, you can either supply the data directly (via
 * functions like gtk_clipboard_set_text()), or you can supply a
 * callback to be called at a later time when the data is needed (via
 * gtk_clipboard_set_with_data() or gtk_clipboard_set_with_owner().)
 * Providing a callback also avoids having to make copies of the data
 * when it is not needed.
 * 
 * gtk_clipboard_set_with_data() and gtk_clipboard_set_with_owner()
 * are quite similar; the choice between the two depends mostly on
 * which is more convenient in a particular situation.
 * The former is most useful when you want to have a blob of data
 * with callbacks to convert it into the various data types that you
 * advertise. When the @clear_func you provided is called, you
 * simply free the data blob. The latter is more useful when the
 * contents of clipboard reflect the internal state of a #GObject
 * (As an example, for the PRIMARY clipboard, when an entry widget
 * provides the clipboard’s contents the contents are simply the
 * text within the selected region.) If the contents change, the
 * entry widget can call gtk_clipboard_set_with_owner() to update
 * the timestamp for clipboard ownership, without having to worry
 * about @clear_func being called.
 * 
 * Requesting the data from the clipboard is essentially
 * asynchronous. If the contents of the clipboard are provided within
 * the same process, then a direct function call will be made to
 * retrieve the data, but if they are provided by another process,
 * then the data needs to be retrieved from the other process, which
 * may take some time. To avoid blocking the user interface, the call
 * to request the selection, gtk_clipboard_request_contents() takes a
 * callback that will be called when the contents are received (or
 * when the request fails.) If you don’t want to deal with providing
 * a separate callback, you can also use gtk_clipboard_wait_for_contents().
 * What this does is run the GLib main loop recursively waiting for
 * the contents. This can simplify the code flow, but you still have
 * to be aware that other callbacks in your program can be called
 * while this recursive mainloop is running.
 * 
 * Along with the functions to get the clipboard contents as an
 * arbitrary data chunk, there are also functions to retrieve
 * it as text, gtk_clipboard_request_text() and
 * gtk_clipboard_wait_for_text(). These functions take care of
 * determining which formats are advertised by the clipboard
 * provider, asking for the clipboard in the best available format
 * and converting the results into the UTF-8 encoding. (The standard
 * form for representing strings in GTK+.)
 *
 */
@interface OGTKClipboard : OGObject
{

}

/**
 * Functions
 */
+ (OGTKClipboard*):(GdkAtom)selection;
+ (OGTKClipboard*)default:(OGGdkDisplay*)display;
+ (OGTKClipboard*)forDisplayWithDisplay:(OGGdkDisplay*)display selection:(GdkAtom)selection;

/**
 * Methods
 */

- (GtkClipboard*)CLIPBOARD;

/**
 * Clears the contents of the clipboard. Generally this should only
 * be called between the time you call gtk_clipboard_set_with_owner()
 * or gtk_clipboard_set_with_data(),
 * and when the @clear_func you supplied is called. Otherwise, the
 * clipboard may be owned by someone else.
 *
 */
- (void)clear;

/**
 * Gets the #GdkDisplay associated with @clipboard
 *
 * @return the #GdkDisplay associated with @clipboard
 */
- (OGGdkDisplay*)display;

/**
 * If the clipboard contents callbacks were set with
 * gtk_clipboard_set_with_owner(), and the gtk_clipboard_set_with_data() or
 * gtk_clipboard_clear() has not subsequently called, returns the owner set
 * by gtk_clipboard_set_with_owner().
 *
 * @return the owner of the clipboard, if any;
 *     otherwise %NULL.
 */
- (GObject*)owner;

/**
 * Gets the selection that this clipboard is for.
 *
 * @return the selection
 */
- (GdkAtom)selection;

/**
 * Requests the contents of clipboard as the given target.
 * When the results of the result are later received the supplied callback
 * will be called.
 *
 * @param target an atom representing the form into which the clipboard
 *     owner should convert the selection.
 * @param callback A function to call when the results are received
 *     (or the retrieval fails). If the retrieval fails the length field of
 *     @selection_data will be negative.
 * @param userData user data to pass to @callback
 */
- (void)requestContentsWithTarget:(GdkAtom)target callback:(GtkClipboardReceivedFunc)callback userData:(gpointer)userData;

/**
 * Requests the contents of the clipboard as image. When the image is
 * later received, it will be converted to a #GdkPixbuf, and
 * @callback will be called.
 * 
 * The @pixbuf parameter to @callback will contain the resulting
 * #GdkPixbuf if the request succeeded, or %NULL if it failed. This
 * could happen for various reasons, in particular if the clipboard
 * was empty or if the contents of the clipboard could not be
 * converted into an image.
 *
 * @param callback a function to call when the image is received,
 *     or the retrieval fails. (It will always be called one way or the other.)
 * @param userData user data to pass to @callback.
 */
- (void)requestImageWithCallback:(GtkClipboardImageReceivedFunc)callback userData:(gpointer)userData;

/**
 * Requests the contents of the clipboard as rich text. When the rich
 * text is later received, @callback will be called.
 * 
 * The @text parameter to @callback will contain the resulting rich
 * text if the request succeeded, or %NULL if it failed. The @length
 * parameter will contain @text’s length. This function can fail for
 * various reasons, in particular if the clipboard was empty or if the
 * contents of the clipboard could not be converted into rich text form.
 *
 * @param buffer a #GtkTextBuffer
 * @param callback a function to call when the text is received,
 *     or the retrieval fails. (It will always be called one way or the other.)
 * @param userData user data to pass to @callback.
 */
- (void)requestRichTextWithBuffer:(OGTKTextBuffer*)buffer callback:(GtkClipboardRichTextReceivedFunc)callback userData:(gpointer)userData;

/**
 * Requests the contents of the clipboard as list of supported targets.
 * When the list is later received, @callback will be called.
 * 
 * The @targets parameter to @callback will contain the resulting targets if
 * the request succeeded, or %NULL if it failed.
 *
 * @param callback a function to call when the targets are
 *     received, or the retrieval fails. (It will always be called
 *     one way or the other.)
 * @param userData user data to pass to @callback.
 */
- (void)requestTargetsWithCallback:(GtkClipboardTargetsReceivedFunc)callback userData:(gpointer)userData;

/**
 * Requests the contents of the clipboard as text. When the text is
 * later received, it will be converted to UTF-8 if necessary, and
 * @callback will be called.
 * 
 * The @text parameter to @callback will contain the resulting text if
 * the request succeeded, or %NULL if it failed. This could happen for
 * various reasons, in particular if the clipboard was empty or if the
 * contents of the clipboard could not be converted into text form.
 *
 * @param callback a function to call when the text is received,
 *     or the retrieval fails. (It will always be called one way or the other.)
 * @param userData user data to pass to @callback.
 */
- (void)requestTextWithCallback:(GtkClipboardTextReceivedFunc)callback userData:(gpointer)userData;

/**
 * Requests the contents of the clipboard as URIs. When the URIs are
 * later received @callback will be called.
 * 
 * The @uris parameter to @callback will contain the resulting array of
 * URIs if the request succeeded, or %NULL if it failed. This could happen
 * for various reasons, in particular if the clipboard was empty or if the
 * contents of the clipboard could not be converted into URI form.
 *
 * @param callback a function to call when the URIs are received,
 *     or the retrieval fails. (It will always be called one way or the other.)
 * @param userData user data to pass to @callback.
 */
- (void)requestUrisWithCallback:(GtkClipboardURIReceivedFunc)callback userData:(gpointer)userData;

/**
 * Hints that the clipboard data should be stored somewhere when the
 * application exits or when gtk_clipboard_store () is called.
 * 
 * This value is reset when the clipboard owner changes.
 * Where the clipboard data is stored is platform dependent,
 * see gdk_display_store_clipboard () for more information.
 *
 * @param targets array containing
 *           information about which forms should be stored or %NULL
 *           to indicate that all forms should be stored.
 * @param ntargets number of elements in @targets
 */
- (void)setCanStoreWithTargets:(const GtkTargetEntry*)targets ntargets:(gint)ntargets;

/**
 * Sets the contents of the clipboard to the given #GdkPixbuf.
 * GTK+ will take responsibility for responding for requests
 * for the image, and for converting the image into the
 * requested format.
 *
 * @param pixbuf a #GdkPixbuf
 */
- (void)setImage:(OGGdkPixbuf*)pixbuf;

/**
 * Sets the contents of the clipboard to the given UTF-8 string. GTK+ will
 * make a copy of the text and take responsibility for responding
 * for requests for the text, and for converting the text into
 * the requested format.
 *
 * @param text a UTF-8 string.
 * @param len length of @text, in bytes, or -1, in which case
 *             the length will be determined with strlen().
 */
- (void)setTextWithText:(OFString*)text len:(gint)len;

/**
 * Virtually sets the contents of the specified clipboard by providing
 * a list of supported formats for the clipboard data and a function
 * to call to get the actual data when it is requested.
 *
 * @param targets array containing information
 *     about the available forms for the clipboard data
 * @param ntargets number of elements in @targets
 * @param getFunc function to call to get the actual clipboard data
 * @param clearFunc when the clipboard contents are set again,
 *     this function will be called, and @get_func will not be subsequently
 *     called.
 * @param userData user data to pass to @get_func and @clear_func.
 * @return %TRUE if setting the clipboard data succeeded.
 *    If setting the clipboard data failed the provided callback
 *    functions will be ignored.
 */
- (bool)setWithDataWithTargets:(const GtkTargetEntry*)targets ntargets:(guint)ntargets getFunc:(GtkClipboardGetFunc)getFunc clearFunc:(GtkClipboardClearFunc)clearFunc userData:(gpointer)userData;

/**
 * Virtually sets the contents of the specified clipboard by providing
 * a list of supported formats for the clipboard data and a function
 * to call to get the actual data when it is requested.
 * 
 * The difference between this function and gtk_clipboard_set_with_data()
 * is that instead of an generic @user_data pointer, a #GObject is passed
 * in.
 *
 * @param targets array containing information
 *     about the available forms for the clipboard data
 * @param ntargets number of elements in @targets
 * @param getFunc function to call to get the actual clipboard data
 * @param clearFunc when the clipboard contents are set again,
 *     this function will be called, and @get_func will not be subsequently
 *     called
 * @param owner an object that “owns” the data. This object will be passed
 *     to the callbacks when called
 * @return %TRUE if setting the clipboard data succeeded.
 *     If setting the clipboard data failed the provided callback
 *     functions will be ignored.
 */
- (bool)setWithOwnerWithTargets:(const GtkTargetEntry*)targets ntargets:(guint)ntargets getFunc:(GtkClipboardGetFunc)getFunc clearFunc:(GtkClipboardClearFunc)clearFunc owner:(GObject*)owner;

/**
 * Stores the current clipboard data somewhere so that it will stay
 * around after the application has quit.
 *
 */
- (void)store;

/**
 * Requests the contents of the clipboard using the given target.
 * This function waits for the data to be received using the main
 * loop, so events, timeouts, etc, may be dispatched during the wait.
 *
 * @param target an atom representing the form into which the clipboard
 *          owner should convert the selection.
 * @return a newly-allocated #GtkSelectionData object or %NULL
 *               if retrieving the given target failed. If non-%NULL,
 *               this value must be freed with gtk_selection_data_free()
 *               when you are finished with it.
 */
- (GtkSelectionData*)waitForContents:(GdkAtom)target;

/**
 * Requests the contents of the clipboard as image and converts
 * the result to a #GdkPixbuf. This function waits for
 * the data to be received using the main loop, so events,
 * timeouts, etc, may be dispatched during the wait.
 *
 * @return a newly-allocated #GdkPixbuf
 *     object which must be disposed with g_object_unref(), or
 *     %NULL if retrieving the selection data failed. (This could
 *     happen for various reasons, in particular if the clipboard
 *     was empty or if the contents of the clipboard could not be
 *     converted into an image.)
 */
- (OGGdkPixbuf*)waitForImage;

/**
 * Requests the contents of the clipboard as rich text.  This function
 * waits for the data to be received using the main loop, so events,
 * timeouts, etc, may be dispatched during the wait.
 *
 * @param buffer a #GtkTextBuffer
 * @param format return location for the format of the returned data
 * @param length return location for the length of the returned data
 * @return a
 *               newly-allocated binary block of data which must be
 *               freed with g_free(), or %NULL if retrieving the
 *               selection data failed. (This could happen for various
 *               reasons, in particular if the clipboard was empty or
 *               if the contents of the clipboard could not be
 *               converted into text form.)
 */
- (guint8*)waitForRichTextWithBuffer:(OGTKTextBuffer*)buffer format:(GdkAtom*)format length:(gsize*)length;

/**
 * Returns a list of targets that are present on the clipboard, or %NULL
 * if there aren’t any targets available. The returned list must be
 * freed with g_free().
 * This function waits for the data to be received using the main
 * loop, so events, timeouts, etc, may be dispatched during the wait.
 *
 * @param targets location
 *           to store an array of targets. The result stored here must
 *           be freed with g_free().
 * @param ntargets location to store number of items in @targets.
 * @return %TRUE if any targets are present on the clipboard,
 *               otherwise %FALSE.
 */
- (bool)waitForTargetsWithTargets:(GdkAtom**)targets ntargets:(gint*)ntargets;

/**
 * Requests the contents of the clipboard as text and converts
 * the result to UTF-8 if necessary. This function waits for
 * the data to be received using the main loop, so events,
 * timeouts, etc, may be dispatched during the wait.
 *
 * @return a newly-allocated UTF-8 string which must
 *               be freed with g_free(), or %NULL if retrieving
 *               the selection data failed. (This could happen
 *               for various reasons, in particular if the
 *               clipboard was empty or if the contents of the
 *               clipboard could not be converted into text form.)
 */
- (OFString*)waitForText;

/**
 * Requests the contents of the clipboard as URIs. This function waits
 * for the data to be received using the main loop, so events,
 * timeouts, etc, may be dispatched during the wait.
 *
 * @return a newly-allocated %NULL-terminated array of strings which must
 *     be freed with g_strfreev(), or %NULL if retrieving the
 *     selection data failed. (This could happen for various reasons,
 *     in particular if the clipboard was empty or if the contents of
 *     the clipboard could not be converted into URI form.)
 */
- (gchar**)waitForUris;

/**
 * Test to see if there is an image available to be pasted
 * This is done by requesting the TARGETS atom and checking
 * if it contains any of the supported image targets. This function
 * waits for the data to be received using the main loop, so events,
 * timeouts, etc, may be dispatched during the wait.
 * 
 * This function is a little faster than calling
 * gtk_clipboard_wait_for_image() since it doesn’t need to retrieve
 * the actual image data.
 *
 * @return %TRUE is there is an image available, %FALSE otherwise.
 */
- (bool)waitIsImageAvailable;

/**
 * Test to see if there is rich text available to be pasted
 * This is done by requesting the TARGETS atom and checking
 * if it contains any of the supported rich text targets. This function
 * waits for the data to be received using the main loop, so events,
 * timeouts, etc, may be dispatched during the wait.
 * 
 * This function is a little faster than calling
 * gtk_clipboard_wait_for_rich_text() since it doesn’t need to retrieve
 * the actual text.
 *
 * @param buffer a #GtkTextBuffer
 * @return %TRUE is there is rich text available, %FALSE otherwise.
 */
- (bool)waitIsRichTextAvailable:(OGTKTextBuffer*)buffer;

/**
 * Checks if a clipboard supports pasting data of a given type. This
 * function can be used to determine if a “Paste” menu item should be
 * insensitive or not.
 * 
 * If you want to see if there’s text available on the clipboard, use
 * gtk_clipboard_wait_is_text_available () instead.
 *
 * @param target A #GdkAtom indicating which target to look for.
 * @return %TRUE if the target is available, %FALSE otherwise.
 */
- (bool)waitIsTargetAvailable:(GdkAtom)target;

/**
 * Test to see if there is text available to be pasted
 * This is done by requesting the TARGETS atom and checking
 * if it contains any of the supported text targets. This function
 * waits for the data to be received using the main loop, so events,
 * timeouts, etc, may be dispatched during the wait.
 * 
 * This function is a little faster than calling
 * gtk_clipboard_wait_for_text() since it doesn’t need to retrieve
 * the actual text.
 *
 * @return %TRUE is there is text available, %FALSE otherwise.
 */
- (bool)waitIsTextAvailable;

/**
 * Test to see if there is a list of URIs available to be pasted
 * This is done by requesting the TARGETS atom and checking
 * if it contains the URI targets. This function
 * waits for the data to be received using the main loop, so events,
 * timeouts, etc, may be dispatched during the wait.
 * 
 * This function is a little faster than calling
 * gtk_clipboard_wait_for_uris() since it doesn’t need to retrieve
 * the actual URI data.
 *
 * @return %TRUE is there is an URI list available, %FALSE otherwise.
 */
- (bool)waitIsUrisAvailable;

@end