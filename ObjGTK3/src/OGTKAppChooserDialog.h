/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKDialog.h"

@class OGTKWindow;
@class OGTKWidget;

/**
 * #GtkAppChooserDialog shows a #GtkAppChooserWidget inside a #GtkDialog.
 * 
 * Note that #GtkAppChooserDialog does not have any interesting methods
 * of its own. Instead, you should get the embedded #GtkAppChooserWidget
 * using gtk_app_chooser_dialog_get_widget() and call its methods if
 * the generic #GtkAppChooser interface is not sufficient for your needs.
 * 
 * To set the heading that is shown above the #GtkAppChooserWidget,
 * use gtk_app_chooser_dialog_set_heading().
 *
 */
@interface OGTKAppChooserDialog : OGTKDialog
{

}


/**
 * Constructors
 */
- (instancetype)initWithParent:(OGTKWindow*)parent flags:(GtkDialogFlags)flags file:(GFile*)file;
- (instancetype)initForContentTypeWithParent:(OGTKWindow*)parent flags:(GtkDialogFlags)flags contentType:(OFString*)contentType;

/**
 * Methods
 */

- (GtkAppChooserDialog*)APPCHOOSERDIALOG;

/**
 * Returns the text to display at the top of the dialog.
 *
 * @return the text to display at the top of the dialog, or %NULL, in which
 *     case a default text is displayed
 */
- (OFString*)heading;

/**
 * Returns the #GtkAppChooserWidget of this dialog.
 *
 * @return the #GtkAppChooserWidget of @self
 */
- (OGTKWidget*)widget;

/**
 * Sets the text to display at the top of the dialog.
 * If the heading is not set, the dialog displays a default text.
 *
 * @param heading a string containing Pango markup
 */
- (void)setHeading:(OFString*)heading;

@end