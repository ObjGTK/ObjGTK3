/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtkx.h>
#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>

#import <OGObject/OGObject.h>

@class OGGdkWindow;

/**
 * #GtkIMContext defines the interface for GTK+ input methods. An input method
 * is used by GTK+ text input widgets like #GtkEntry to map from key events to
 * Unicode character strings.
 * 
 * The default input method can be set programmatically via the
 * #GtkSettings:gtk-im-module GtkSettings property. Alternatively, you may set
 * the GTK_IM_MODULE environment variable as documented in
 * [Running GTK+ Applications][gtk-running].
 * 
 * The #GtkEntry #GtkEntry:im-module and #GtkTextView #GtkTextView:im-module
 * properties may also be used to set input methods for specific widget
 * instances. For instance, a certain entry widget might be expected to contain
 * certain characters which would be easier to input with a certain input
 * method.
 * 
 * An input method may consume multiple key events in sequence and finally
 * output the composed result. This is called preediting, and an input method
 * may provide feedback about this process by displaying the intermediate
 * composition states as preedit text. For instance, the default GTK+ input
 * method implements the input of arbitrary Unicode code points by holding down
 * the Control and Shift keys and then typing “U” followed by the hexadecimal
 * digits of the code point.  When releasing the Control and Shift keys,
 * preediting ends and the character is inserted as text. Ctrl+Shift+u20AC for
 * example results in the € sign.
 * 
 * Additional input methods can be made available for use by GTK+ widgets as
 * loadable modules. An input method module is a small shared library which
 * implements a subclass of #GtkIMContext or #GtkIMContextSimple and exports
 * these four functions:
 * 
 * |[<!-- language="C" -->
 * void im_module_init(GTypeModule *module);
 * ]|
 * This function should register the #GType of the #GtkIMContext subclass which
 * implements the input method by means of g_type_module_register_type(). Note
 * that g_type_register_static() cannot be used as the type needs to be
 * registered dynamically.
 * 
 * |[<!-- language="C" -->
 * void im_module_exit(void);
 * ]|
 * Here goes any cleanup code your input method might require on module unload.
 * 
 * |[<!-- language="C" -->
 * void im_module_list(const GtkIMContextInfo ***contexts, int *n_contexts)
 * {
 *   *contexts = info_list;
 *   *n_contexts = G_N_ELEMENTS (info_list);
 * }
 * ]|
 * This function returns the list of input methods provided by the module. The
 * example implementation above shows a common solution and simply returns a
 * pointer to statically defined array of #GtkIMContextInfo items for each
 * provided input method.
 * 
 * |[<!-- language="C" -->
 * GtkIMContext * im_module_create(const gchar *context_id);
 * ]|
 * This function should return a pointer to a newly created instance of the
 * #GtkIMContext subclass identified by @context_id. The context ID is the same
 * as specified in the #GtkIMContextInfo array returned by im_module_list().
 * 
 * After a new loadable input method module has been installed on the system,
 * the configuration file `gtk.immodules` needs to be
 * regenerated by [gtk-query-immodules-3.0][gtk-query-immodules-3.0],
 * in order for the new input method to become available to GTK+ applications.
 *
 */
@interface OGTKIMContext : OGObject
{

}


/**
 * Methods
 */

- (GtkIMContext*)IMCONTEXT;

/**
 * Asks the widget that the input context is attached to to delete
 * characters around the cursor position by emitting the
 * GtkIMContext::delete_surrounding signal. Note that @offset and @n_chars
 * are in characters not in bytes which differs from the usage other
 * places in #GtkIMContext.
 * 
 * In order to use this function, you should first call
 * gtk_im_context_get_surrounding() to get the current context, and
 * call this function immediately afterwards to make sure that you
 * know what you are deleting. You should also account for the fact
 * that even if the signal was handled, the input context might not
 * have deleted all the characters that were requested to be deleted.
 * 
 * This function is used by an input method that wants to make
 * subsitutions in the existing text in response to new input. It is
 * not useful for applications.
 *
 * @param offset offset from cursor position in chars;
 *    a negative value means start before the cursor.
 * @param nchars number of characters to delete.
 * @return %TRUE if the signal was handled.
 */
- (bool)deleteSurroundingWithOffset:(gint)offset nchars:(gint)nchars;

/**
 * Allow an input method to internally handle key press and release
 * events. If this function returns %TRUE, then no further processing
 * should be done for this key event.
 *
 * @param event the key event
 * @return %TRUE if the input method handled the key event.
 */
- (bool)filterKeypress:(GdkEventKey*)event;

/**
 * Notify the input method that the widget to which this
 * input context corresponds has gained focus. The input method
 * may, for example, change the displayed feedback to reflect
 * this change.
 *
 */
- (void)focusIn;

/**
 * Notify the input method that the widget to which this
 * input context corresponds has lost focus. The input method
 * may, for example, change the displayed feedback or reset the contexts
 * state to reflect this change.
 *
 */
- (void)focusOut;

/**
 * Retrieve the current preedit string for the input context,
 * and a list of attributes to apply to the string.
 * This string should be displayed inserted at the insertion
 * point.
 *
 * @param str location to store the retrieved
 *              string. The string retrieved must be freed with g_free().
 * @param attrs location to store the retrieved
 *              attribute list.  When you are done with this list, you
 *              must unreference it with pango_attr_list_unref().
 * @param cursorPos location to store position of cursor (in characters)
 *              within the preedit string.
 */
- (void)preeditStringWithStr:(gchar**)str attrs:(PangoAttrList**)attrs cursorPos:(gint*)cursorPos;

/**
 * Retrieves context around the insertion point. Input methods
 * typically want context in order to constrain input text based on
 * existing text; this is important for languages such as Thai where
 * only some sequences of characters are allowed.
 * 
 * This function is implemented by emitting the
 * GtkIMContext::retrieve_surrounding signal on the input method; in
 * response to this signal, a widget should provide as much context as
 * is available, up to an entire paragraph, by calling
 * gtk_im_context_set_surrounding(). Note that there is no obligation
 * for a widget to respond to the ::retrieve_surrounding signal, so input
 * methods must be prepared to function without context.
 *
 * @param text location to store a UTF-8 encoded
 *        string of text holding context around the insertion point.
 *        If the function returns %TRUE, then you must free the result
 *        stored in this location with g_free().
 * @param cursorIndex location to store byte index of the insertion
 *        cursor within @text.
 * @return %TRUE if surrounding text was provided; in this case
 *    you must free the result stored in *text.
 */
- (bool)surroundingWithText:(gchar**)text cursorIndex:(gint*)cursorIndex;

/**
 * Notify the input method that a change such as a change in cursor
 * position has been made. This will typically cause the input
 * method to clear the preedit state.
 *
 */
- (void)reset;

/**
 * Set the client window for the input context; this is the
 * #GdkWindow in which the input appears. This window is
 * used in order to correctly position status windows, and may
 * also be used for purposes internal to the input method.
 *
 * @param window the client window. This may be %NULL to indicate
 *           that the previous client window no longer exists.
 */
- (void)setClientWindow:(OGGdkWindow*)window;

/**
 * Notify the input method that a change in cursor
 * position has been made. The location is relative to the client
 * window.
 *
 * @param area new location
 */
- (void)setCursorLocation:(const GdkRectangle*)area;

/**
 * Sets surrounding context around the insertion point and preedit
 * string. This function is expected to be called in response to the
 * GtkIMContext::retrieve_surrounding signal, and will likely have no
 * effect if called at other times.
 *
 * @param text text surrounding the insertion point, as UTF-8.
 *        the preedit string should not be included within
 *        @text.
 * @param len the length of @text, or -1 if @text is nul-terminated
 * @param cursorIndex the byte index of the insertion cursor within @text.
 */
- (void)setSurroundingWithText:(OFString*)text len:(gint)len cursorIndex:(gint)cursorIndex;

/**
 * Sets whether the IM context should use the preedit string
 * to display feedback. If @use_preedit is FALSE (default
 * is TRUE), then the IM context may use some other method to display
 * feedback, such as displaying it in a child of the root window.
 *
 * @param usePreedit whether the IM context should use the preedit string.
 */
- (void)setUsePreedit:(bool)usePreedit;

@end