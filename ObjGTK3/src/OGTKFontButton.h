/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKButton.h"

@class OGTKWidget;

/**
 * The #GtkFontButton is a button which displays the currently selected
 * font an allows to open a font chooser dialog to change the font.
 * It is suitable widget for selecting a font in a preference dialog.
 * 
 * # CSS nodes
 * 
 * GtkFontButton has a single CSS node with name button and style class .font.
 *
 */
@interface OGTKFontButton : OGTKButton
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initWithFont:(OFString*)fontname;

/**
 * Methods
 */

- (GtkFontButton*)FONTBUTTON;

/**
 * Retrieves the name of the currently selected font. This name includes
 * style and size information as well. If you want to render something
 * with the font, use this string with pango_font_description_from_string() .
 * If you’re interested in peeking certain values (family name,
 * style, size, weight) just query these properties from the
 * #PangoFontDescription object.
 *
 * @return an internal copy of the font name which must not be freed.
 */
- (OFString*)fontName;

/**
 * Returns whether the font size will be shown in the label.
 *
 * @return whether the font size will be shown in the label.
 */
- (bool)showSize;

/**
 * Returns whether the name of the font style will be shown in the label.
 *
 * @return whether the font style will be shown in the label.
 */
- (bool)showStyle;

/**
 * Retrieves the title of the font chooser dialog.
 *
 * @return an internal copy of the title string which must not be freed.
 */
- (OFString*)title;

/**
 * Returns whether the selected font is used in the label.
 *
 * @return whether the selected font is used in the label.
 */
- (bool)useFont;

/**
 * Returns whether the selected size is used in the label.
 *
 * @return whether the selected size is used in the label.
 */
- (bool)useSize;

/**
 * Sets or updates the currently-displayed font in font picker dialog.
 *
 * @param fontname Name of font to display in font chooser dialog
 * @return %TRUE
 */
- (bool)setFontName:(OFString*)fontname;

/**
 * If @show_size is %TRUE, the font size will be displayed along with the name of the selected font.
 *
 * @param showSize %TRUE if font size should be displayed in dialog.
 */
- (void)setShowSize:(bool)showSize;

/**
 * If @show_style is %TRUE, the font style will be displayed along with name of the selected font.
 *
 * @param showStyle %TRUE if font style should be displayed in label.
 */
- (void)setShowStyle:(bool)showStyle;

/**
 * Sets the title for the font chooser dialog.
 *
 * @param title a string containing the font chooser dialog title
 */
- (void)setTitle:(OFString*)title;

/**
 * If @use_font is %TRUE, the font name will be written using the selected font.
 *
 * @param useFont If %TRUE, font name will be written using font chosen.
 */
- (void)setUseFont:(bool)useFont;

/**
 * If @use_size is %TRUE, the font name will be written using the selected size.
 *
 * @param useSize If %TRUE, font name will be written using the selected size.
 */
- (void)setUseSize:(bool)useSize;

@end