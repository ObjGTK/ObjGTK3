/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKDialog.h"

@class OGTKWidget;

/**
 * #GtkMessageDialog presents a dialog with some message text. It’s simply a
 * convenience widget; you could construct the equivalent of #GtkMessageDialog
 * from #GtkDialog without too much effort, but #GtkMessageDialog saves typing.
 * 
 * One difference from #GtkDialog is that #GtkMessageDialog sets the
 * #GtkWindow:skip-taskbar-hint property to %TRUE, so that the dialog is hidden
 * from the taskbar by default.
 * 
 * The easiest way to do a modal message dialog is to use gtk_dialog_run(), though
 * you can also pass in the %GTK_DIALOG_MODAL flag, gtk_dialog_run() automatically
 * makes the dialog modal and waits for the user to respond to it. gtk_dialog_run()
 * returns when any dialog button is clicked.
 * 
 * An example for using a modal dialog:
 * |[<!-- language="C" -->
 *  GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
 *  dialog = gtk_message_dialog_new (parent_window,
 *                                   flags,
 *                                   GTK_MESSAGE_ERROR,
 *                                   GTK_BUTTONS_CLOSE,
 *                                   "Error reading “%s”: %s",
 *                                   filename,
 *                                   g_strerror (errno));
 *  gtk_dialog_run (GTK_DIALOG (dialog));
 *  gtk_widget_destroy (dialog);
 * ]|
 * 
 * You might do a non-modal #GtkMessageDialog as follows:
 * 
 * An example for a non-modal dialog:
 * |[<!-- language="C" -->
 *  GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
 *  dialog = gtk_message_dialog_new (parent_window,
 *                                   flags,
 *                                   GTK_MESSAGE_ERROR,
 *                                   GTK_BUTTONS_CLOSE,
 *                                   "Error reading “%s”: %s",
 *                                   filename,
 *                                   g_strerror (errno));
 * 
 *  // Destroy the dialog when the user responds to it
 *  // (e.g. clicks a button)
 * 
 *  g_signal_connect_swapped (dialog, "response",
 *                            G_CALLBACK (gtk_widget_destroy),
 *                            dialog);
 * ]|
 * 
 * # GtkMessageDialog as GtkBuildable
 * 
 * The GtkMessageDialog implementation of the GtkBuildable interface exposes
 * the message area as an internal child with the name “message_area”.
 *
 */
@interface OGTKMessageDialog : OGTKDialog
{

}


/**
 * Methods
 */

- (GtkMessageDialog*)MESSAGEDIALOG;

/**
 * Gets the dialog’s image.
 *
 * @return the dialog’s image
 */
- (OGTKWidget*)image;

/**
 * Returns the message area of the dialog. This is the box where the
 * dialog’s primary and secondary labels are packed. You can add your
 * own extra content to that box and it will appear below those labels.
 * See gtk_dialog_get_content_area() for the corresponding
 * function in the parent #GtkDialog.
 *
 * @return A #GtkBox corresponding to the
 *     “message area” in the @message_dialog.
 */
- (OGTKWidget*)messageArea;

/**
 * Sets the dialog’s image to @image.
 *
 * @param image the image
 */
- (void)setImage:(OGTKWidget*)image;

/**
 * Sets the text of the message dialog to be @str, which is marked
 * up with the [Pango text markup language][PangoMarkupFormat].
 *
 * @param str markup string (see [Pango markup format][PangoMarkupFormat])
 */
- (void)setMarkup:(OFString*)str;

@end