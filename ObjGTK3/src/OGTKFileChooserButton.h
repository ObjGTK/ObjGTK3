/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

@class OGTKWidget;

/**
 * The #GtkFileChooserButton is a widget that lets the user select a
 * file.  It implements the #GtkFileChooser interface.  Visually, it is a
 * file name with a button to bring up a #GtkFileChooserDialog.
 * The user can then use that dialog to change the file associated with
 * that button.  This widget does not support setting the
 * #GtkFileChooser:select-multiple property to %TRUE.
 * 
 * ## Create a button to let the user select a file in /etc
 * 
 * |[<!-- language="C" -->
 * {
 *   GtkWidget *button;
 * 
 *   button = gtk_file_chooser_button_new (_("Select a file"),
 *                                         GTK_FILE_CHOOSER_ACTION_OPEN);
 *   gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER (button),
 *                                        "/etc");
 * }
 * ]|
 * 
 * The #GtkFileChooserButton supports the #GtkFileChooserActions
 * %GTK_FILE_CHOOSER_ACTION_OPEN and %GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER.
 * 
 * > The #GtkFileChooserButton will ellipsize the label, and will thus
 * > request little horizontal space.  To give the button more space,
 * > you should call gtk_widget_get_preferred_size(),
 * > gtk_file_chooser_button_set_width_chars(), or pack the button in
 * > such a way that other interface elements give space to the
 * > widget.
 * 
 * # CSS nodes
 * 
 * GtkFileChooserButton has a CSS node with name “filechooserbutton”, containing
 * a subnode for the internal button with name “button” and style class “.file”.
 *
 */
@interface OGTKFileChooserButton : OGTKBox
{

}


/**
 * Constructors
 */
- (instancetype)initWithTitle:(OFString*)title action:(GtkFileChooserAction)action;
- (instancetype)initWithDialog:(OGTKWidget*)dialog;

/**
 * Methods
 */

- (GtkFileChooserButton*)FILECHOOSERBUTTON;

/**
 * Returns whether the button grabs focus when it is clicked with the mouse.
 * See gtk_file_chooser_button_set_focus_on_click().
 *
 * @return %TRUE if the button grabs focus when it is clicked with
 *               the mouse.
 */
- (bool)focusOnClick;

/**
 * Retrieves the title of the browse dialog used by @button. The returned value
 * should not be modified or freed.
 *
 * @return a pointer to the browse dialog’s title.
 */
- (OFString*)title;

/**
 * Retrieves the width in characters of the @button widget’s entry and/or label.
 *
 * @return an integer width (in characters) that the button will use to size itself.
 */
- (gint)widthChars;

/**
 * Sets whether the button will grab focus when it is clicked with the mouse.
 * Making mouse clicks not grab focus is useful in places like toolbars where
 * you don’t want the keyboard focus removed from the main area of the
 * application.
 *
 * @param focusOnClick whether the button grabs focus when clicked with the mouse
 */
- (void)setFocusOnClick:(bool)focusOnClick;

/**
 * Modifies the @title of the browse dialog used by @button.
 *
 * @param title the new browse dialog title.
 */
- (void)setTitle:(OFString*)title;

/**
 * Sets the width (in characters) that @button will use to @n_chars.
 *
 * @param nchars the new width, in characters.
 */
- (void)setWidthChars:(gint)nchars;

@end