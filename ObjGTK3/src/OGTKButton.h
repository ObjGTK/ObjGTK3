/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGGdkWindow;
@class OGTKWidget;

/**
 * The #GtkButton widget is generally used to trigger a callback function that is
 * called when the button is pressed.  The various signals and how to use them
 * are outlined below.
 * 
 * The #GtkButton widget can hold any valid child widget.  That is, it can hold
 * almost any other standard #GtkWidget.  The most commonly used child is the
 * #GtkLabel.
 * 
 * # CSS nodes
 * 
 * GtkButton has a single CSS node with name button. The node will get the
 * style classes .image-button or .text-button, if the content is just an
 * image or label, respectively. It may also receive the .flat style class.
 * 
 * Other style classes that are commonly used with GtkButton include
 * .suggested-action and .destructive-action. In special cases, buttons
 * can be made round by adding the .circular style class.
 * 
 * Button-like widgets like #GtkToggleButton, #GtkMenuButton, #GtkVolumeButton,
 * #GtkLockButton, #GtkColorButton, #GtkFontButton or #GtkFileChooserButton use
 * style classes such as .toggle, .popup, .scale, .lock, .color, .font, .file
 * to differentiate themselves from a plain GtkButton.
 *
 */
@interface OGTKButton : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initFromIconNameWithIconName:(OFString*)iconName size:(GtkIconSize)size;
- (instancetype)initFromStock:(OFString*)stockId;
- (instancetype)initWithLabel:(OFString*)label;
- (instancetype)initWithMnemonic:(OFString*)label;

/**
 * Methods
 */

- (GtkButton*)BUTTON;

/**
 * Emits a #GtkButton::clicked signal to the given #GtkButton.
 *
 */
- (void)clicked;

/**
 * Emits a #GtkButton::enter signal to the given #GtkButton.
 *
 */
- (void)enter;

/**
 * Gets the alignment of the child in the button.
 *
 * @param xalign return location for horizontal alignment
 * @param yalign return location for vertical alignment
 */
- (void)alignmentWithXalign:(gfloat*)xalign yalign:(gfloat*)yalign;

/**
 * Returns whether the button will ignore the #GtkSettings:gtk-button-images
 * setting and always show the image, if available.
 *
 * @return %TRUE if the button will always show the image
 */
- (bool)alwaysShowImage;

/**
 * Returns the button’s event window if it is realized, %NULL otherwise.
 * This function should be rarely needed.
 *
 * @return @button’s event window.
 */
- (OGGdkWindow*)eventWindow;

/**
 * Returns whether the button grabs focus when it is clicked with the mouse.
 * See gtk_button_set_focus_on_click().
 *
 * @return %TRUE if the button grabs focus when it is clicked with
 *               the mouse.
 */
- (bool)focusOnClick;

/**
 * Gets the widget that is currenty set as the image of @button.
 * This may have been explicitly set by gtk_button_set_image()
 * or constructed by gtk_button_new_from_stock().
 *
 * @return a #GtkWidget or %NULL in case
 *     there is no image
 */
- (OGTKWidget*)image;

/**
 * Gets the position of the image relative to the text
 * inside the button.
 *
 * @return the position
 */
- (GtkPositionType)imagePosition;

/**
 * Fetches the text from the label of the button, as set by
 * gtk_button_set_label(). If the label text has not
 * been set the return value will be %NULL. This will be the
 * case if you create an empty button with gtk_button_new() to
 * use as a container.
 *
 * @return The text of the label widget. This string is owned
 * by the widget and must not be modified or freed.
 */
- (OFString*)label;

/**
 * Returns the current relief style of the given #GtkButton.
 *
 * @return The current #GtkReliefStyle
 */
- (GtkReliefStyle)relief;

/**
 * Returns whether the button label is a stock item.
 *
 * @return %TRUE if the button label is used to
 *               select a stock item instead of being
 *               used directly as the label text.
 */
- (bool)useStock;

/**
 * Returns whether an embedded underline in the button label indicates a
 * mnemonic. See gtk_button_set_use_underline ().
 *
 * @return %TRUE if an embedded underline in the button label
 *               indicates the mnemonic accelerator keys.
 */
- (bool)useUnderline;

/**
 * Emits a #GtkButton::leave signal to the given #GtkButton.
 *
 */
- (void)leave;

/**
 * Emits a #GtkButton::pressed signal to the given #GtkButton.
 *
 */
- (void)pressed;

/**
 * Emits a #GtkButton::released signal to the given #GtkButton.
 *
 */
- (void)released;

/**
 * Sets the alignment of the child. This property has no effect unless
 * the child is a #GtkMisc or a #GtkAlignment.
 *
 * @param xalign the horizontal position of the child, 0.0 is left aligned,
 *   1.0 is right aligned
 * @param yalign the vertical position of the child, 0.0 is top aligned,
 *   1.0 is bottom aligned
 */
- (void)setAlignmentWithXalign:(gfloat)xalign yalign:(gfloat)yalign;

/**
 * If %TRUE, the button will ignore the #GtkSettings:gtk-button-images
 * setting and always show the image, if available.
 * 
 * Use this property if the button  would be useless or hard to use
 * without the image.
 *
 * @param alwaysShow %TRUE if the menuitem should always show the image
 */
- (void)setAlwaysShowImage:(bool)alwaysShow;

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
 * Set the image of @button to the given widget. The image will be
 * displayed if the label text is %NULL or if
 * #GtkButton:always-show-image is %TRUE. You don’t have to call
 * gtk_widget_show() on @image yourself.
 *
 * @param image a widget to set as the image for the button, or %NULL to unset
 */
- (void)setImage:(OGTKWidget*)image;

/**
 * Sets the position of the image relative to the text
 * inside the button.
 *
 * @param position the position
 */
- (void)setImagePosition:(GtkPositionType)position;

/**
 * Sets the text of the label of the button to @str. This text is
 * also used to select the stock item if gtk_button_set_use_stock()
 * is used.
 * 
 * This will also clear any previously set labels.
 *
 * @param label a string
 */
- (void)setLabel:(OFString*)label;

/**
 * Sets the relief style of the edges of the given #GtkButton widget.
 * Two styles exist, %GTK_RELIEF_NORMAL and %GTK_RELIEF_NONE.
 * The default style is, as one can guess, %GTK_RELIEF_NORMAL.
 * The deprecated value %GTK_RELIEF_HALF behaves the same as
 * %GTK_RELIEF_NORMAL.
 *
 * @param relief The GtkReliefStyle as described above
 */
- (void)setRelief:(GtkReliefStyle)relief;

/**
 * If %TRUE, the label set on the button is used as a
 * stock id to select the stock item for the button.
 *
 * @param useStock %TRUE if the button should use a stock item
 */
- (void)setUseStock:(bool)useStock;

/**
 * If true, an underline in the text of the button label indicates
 * the next character should be used for the mnemonic accelerator key.
 *
 * @param useUnderline %TRUE if underlines in the text indicate mnemonics
 */
- (void)setUseUnderline:(bool)useUnderline;

@end