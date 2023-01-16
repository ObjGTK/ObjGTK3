/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

@class OGPangoFontFamily;
@class OGTKWidget;
@class OGPangoFontFace;

@interface OGTKFontSelection : OGTKBox
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkFontSelection*)FONTSELECTION;

/**
 * Gets the #PangoFontFace representing the selected font group
 * details (i.e. family, slant, weight, width, etc).
 *
 * @return A #PangoFontFace representing the
 *     selected font group details. The returned object is owned by
 *     @fontsel and must not be modified or freed.
 */
- (OGPangoFontFace*)face;

/**
 * This returns the #GtkTreeView which lists all styles available for
 * the selected font. For example, “Regular”, “Bold”, etc.
 *
 * @return A #GtkWidget that is part of @fontsel
 */
- (OGTKWidget*)faceList;

/**
 * Gets the #PangoFontFamily representing the selected font family.
 *
 * @return A #PangoFontFamily representing the
 *     selected font family. Font families are a collection of font
 *     faces. The returned object is owned by @fontsel and must not
 *     be modified or freed.
 */
- (OGPangoFontFamily*)family;

/**
 * This returns the #GtkTreeView that lists font families, for
 * example, “Sans”, “Serif”, etc.
 *
 * @return A #GtkWidget that is part of @fontsel
 */
- (OGTKWidget*)familyList;

/**
 * Gets the currently-selected font name.
 * 
 * Note that this can be a different string than what you set with
 * gtk_font_selection_set_font_name(), as the font selection widget may
 * normalize font names and thus return a string with a different structure.
 * For example, “Helvetica Italic Bold 12” could be normalized to
 * “Helvetica Bold Italic 12”. Use pango_font_description_equal()
 * if you want to compare two font descriptions.
 *
 * @return A string with the name of the current font, or %NULL if
 *     no font is selected. You must free this string with g_free().
 */
- (OFString*)fontName;

/**
 * This returns the #GtkEntry used to display the font as a preview.
 *
 * @return A #GtkWidget that is part of @fontsel
 */
- (OGTKWidget*)previewEntry;

/**
 * Gets the text displayed in the preview area.
 *
 * @return the text displayed in the preview area.
 *     This string is owned by the widget and should not be
 *     modified or freed
 */
- (OFString*)previewText;

/**
 * The selected font size.
 *
 * @return A n integer representing the selected font size,
 *     or -1 if no font size is selected.
 */
- (gint)size;

/**
 * This returns the #GtkEntry used to allow the user to edit the font
 * number manually instead of selecting it from the list of font sizes.
 *
 * @return A #GtkWidget that is part of @fontsel
 */
- (OGTKWidget*)sizeEntry;

/**
 * This returns the #GtkTreeView used to list font sizes.
 *
 * @return A #GtkWidget that is part of @fontsel
 */
- (OGTKWidget*)sizeList;

/**
 * Sets the currently-selected font.
 * 
 * Note that the @fontsel needs to know the screen in which it will appear
 * for this to work; this can be guaranteed by simply making sure that the
 * @fontsel is inserted in a toplevel window before you call this function.
 *
 * @param fontname a font name like “Helvetica 12” or “Times Bold 18”
 * @return %TRUE if the font could be set successfully; %FALSE if no
 *     such font exists or if the @fontsel doesn’t belong to a particular
 *     screen yet.
 */
- (bool)setFontName:(OFString*)fontname;

/**
 * Sets the text displayed in the preview area.
 * The @text is used to show how the selected font looks.
 *
 * @param text the text to display in the preview area
 */
- (void)setPreviewText:(OFString*)text;

@end