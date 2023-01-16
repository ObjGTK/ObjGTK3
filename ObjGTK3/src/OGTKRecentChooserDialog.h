/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKDialog.h"

/**
 * #GtkRecentChooserDialog is a dialog box suitable for displaying the recently
 * used documents.  This widgets works by putting a #GtkRecentChooserWidget inside
 * a #GtkDialog.  It exposes the #GtkRecentChooserIface interface, so you can use
 * all the #GtkRecentChooser functions on the recent chooser dialog as well as
 * those for #GtkDialog.
 * 
 * Note that #GtkRecentChooserDialog does not have any methods of its own.
 * Instead, you should use the functions that work on a #GtkRecentChooser.
 * 
 * ## Typical usage ## {#gtkrecentchooser-typical-usage}
 * 
 * In the simplest of cases, you can use the following code to use
 * a #GtkRecentChooserDialog to select a recently used file:
 * 
 * |[<!-- language="C" -->
 * GtkWidget *dialog;
 * gint res;
 * 
 * dialog = gtk_recent_chooser_dialog_new ("Recent Documents",
 *                                         parent_window,
 *                                         _("_Cancel"),
 *                                         GTK_RESPONSE_CANCEL,
 *                                         _("_Open"),
 *                                         GTK_RESPONSE_ACCEPT,
 *                                         NULL);
 * 
 * res = gtk_dialog_run (GTK_DIALOG (dialog));
 * if (res == GTK_RESPONSE_ACCEPT)
 *   {
 *     GtkRecentInfo *info;
 *     GtkRecentChooser *chooser = GTK_RECENT_CHOOSER (dialog);
 * 
 *     info = gtk_recent_chooser_get_current_item (chooser);
 *     open_file (gtk_recent_info_get_uri (info));
 *     gtk_recent_info_unref (info);
 *   }
 * 
 * gtk_widget_destroy (dialog);
 * ]|
 * 
 * Recently used files are supported since GTK+ 2.10.
 *
 */
@interface OGTKRecentChooserDialog : OGTKDialog
{

}


/**
 * Methods
 */

- (GtkRecentChooserDialog*)RECENTCHOOSERDIALOG;

@end