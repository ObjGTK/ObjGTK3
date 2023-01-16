/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKDialog.h"

@class OGTKWidget;

@interface OGTKFontSelectionDialog : OGTKDialog
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)title;

/**
 * Methods
 */

- (GtkFontSelectionDialog*)FONTSELECTIONDIALOG;

/**
 * Gets the “Cancel” button.
 *
 * @return the #GtkWidget used in the dialog
 *     for the “Cancel” button.
 */
- (OGTKWidget*)cancelButton;

/**
 * Gets the currently-selected font name.
 * 
 * Note that this can be a different string than what you set with
 * gtk_font_selection_dialog_set_font_name(), as the font selection widget
 * may normalize font names and thus return a string with a different
 * structure. For example, “Helvetica Italic Bold 12” could be normalized
 * to “Helvetica Bold Italic 12”.  Use pango_font_description_equal()
 * if you want to compare two font descriptions.
 *
 * @return A string with the name of the current font, or %NULL if no
 *     font is selected. You must free this string with g_free().
 */
- (OFString*)fontName;

/**
 * Retrieves the #GtkFontSelection widget embedded in the dialog.
 *
 * @return the embedded #GtkFontSelection
 */
- (OGTKWidget*)fontSelection;

/**
 * Gets the “OK” button.
 *
 * @return the #GtkWidget used in the dialog
 *     for the “OK” button.
 */
- (OGTKWidget*)okButton;

/**
 * Gets the text displayed in the preview area.
 *
 * @return the text displayed in the preview area.
 *     This string is owned by the widget and should not be
 *     modified or freed
 */
- (OFString*)previewText;

/**
 * Sets the currently selected font.
 *
 * @param fontname a font name like “Helvetica 12” or “Times Bold 18”
 * @return %TRUE if the font selected in @fsd is now the
 *     @fontname specified, %FALSE otherwise.
 */
- (bool)setFontName:(OFString*)fontname;

/**
 * Sets the text displayed in the preview area.
 *
 * @param text the text to display in the preview area
 */
- (void)setPreviewText:(OFString*)text;

@end