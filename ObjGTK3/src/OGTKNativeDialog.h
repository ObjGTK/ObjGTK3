/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtkx.h>
#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>

#import <OGObject/OGObject.h>

@class OGTKWindow;

/**
 * Native dialogs are platform dialogs that don't use #GtkDialog or
 * #GtkWindow. They are used in order to integrate better with a
 * platform, by looking the same as other native applications and
 * supporting platform specific features.
 * 
 * The #GtkDialog functions cannot be used on such objects, but we
 * need a similar API in order to drive them. The #GtkNativeDialog
 * object is an API that allows you to do this. It allows you to set
 * various common properties on the dialog, as well as show and hide
 * it and get a #GtkNativeDialog::response signal when the user finished
 * with the dialog.
 * 
 * There is also a gtk_native_dialog_run() helper that makes it easy
 * to run any native dialog in a modal way with a recursive mainloop,
 * similar to gtk_dialog_run().
 *
 */
@interface OGTKNativeDialog : OGObject
{

}


/**
 * Methods
 */

- (GtkNativeDialog*)NATIVEDIALOG;

/**
 * Destroys a dialog.
 * 
 * When a dialog is destroyed, it will break any references it holds
 * to other objects. If it is visible it will be hidden and any underlying
 * window system resources will be destroyed.
 * 
 * Note that this does not release any reference to the object (as opposed to
 * destroying a GtkWindow) because there is no reference from the windowing
 * system to the #GtkNativeDialog.
 *
 */
- (void)destroy;

/**
 * Returns whether the dialog is modal. See gtk_native_dialog_set_modal().
 *
 * @return %TRUE if the dialog is set to be modal
 */
- (bool)modal;

/**
 * Gets the title of the #GtkNativeDialog.
 *
 * @return the title of the dialog, or %NULL if none has
 *    been set explicitly. The returned string is owned by the widget
 *    and must not be modified or freed.
 */
- (OFString*)title;

/**
 * Fetches the transient parent for this window. See
 * gtk_native_dialog_set_transient_for().
 *
 * @return the transient parent for this window,
 * or %NULL if no transient parent has been set.
 */
- (OGTKWindow*)transientFor;

/**
 * Determines whether the dialog is visible.
 *
 * @return %TRUE if the dialog is visible
 */
- (bool)visible;

/**
 * Hides the dialog if it is visilbe, aborting any interaction. Once this
 * is called the  #GtkNativeDialog::response signal will not be emitted
 * until after the next call to gtk_native_dialog_show().
 * 
 * If the dialog is not visible this does nothing.
 *
 */
- (void)hide;

/**
 * Blocks in a recursive main loop until @self emits the
 * #GtkNativeDialog::response signal. It then returns the response ID
 * from the ::response signal emission.
 * 
 * Before entering the recursive main loop, gtk_native_dialog_run()
 * calls gtk_native_dialog_show() on the dialog for you.
 * 
 * After gtk_native_dialog_run() returns, then dialog will be hidden.
 * 
 * Typical usage of this function might be:
 * |[<!-- language="C" -->
 *   gint result = gtk_native_dialog_run (GTK_NATIVE_DIALOG (dialog));
 *   switch (result)
 *     {
 *       case GTK_RESPONSE_ACCEPT:
 *          do_application_specific_something ();
 *          break;
 *       default:
 *          do_nothing_since_dialog_was_cancelled ();
 *          break;
 *     }
 *   g_object_unref (dialog);
 * ]|
 * 
 * Note that even though the recursive main loop gives the effect of a
 * modal dialog (it prevents the user from interacting with other
 * windows in the same window group while the dialog is run), callbacks
 * such as timeouts, IO channel watches, DND drops, etc, will
 * be triggered during a gtk_nautilus_dialog_run() call.
 *
 * @return response ID
 */
- (gint)run;

/**
 * Sets a dialog modal or non-modal. Modal dialogs prevent interaction
 * with other windows in the same application. To keep modal dialogs
 * on top of main application windows, use
 * gtk_native_dialog_set_transient_for() to make the dialog transient for the
 * parent; most [window managers][gtk-X11-arch]
 * will then disallow lowering the dialog below the parent.
 *
 * @param modal whether the window is modal
 */
- (void)setModal:(bool)modal;

/**
 * Sets the title of the #GtkNativeDialog.
 *
 * @param title title of the dialog
 */
- (void)setTitle:(OFString*)title;

/**
 * Dialog windows should be set transient for the main application
 * window they were spawned from. This allows
 * [window managers][gtk-X11-arch] to e.g. keep the
 * dialog on top of the main window, or center the dialog over the
 * main window.
 * 
 * Passing %NULL for @parent unsets the current transient window.
 *
 * @param parent parent window, or %NULL
 */
- (void)setTransientFor:(OGTKWindow*)parent;

/**
 * Shows the dialog on the display, allowing the user to interact with
 * it. When the user accepts the state of the dialog the dialog will
 * be automatically hidden and the #GtkNativeDialog::response signal
 * will be emitted.
 * 
 * Multiple calls while the dialog is visible will be ignored.
 *
 */
- (void)show;

@end