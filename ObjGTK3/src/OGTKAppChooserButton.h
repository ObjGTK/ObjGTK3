/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKComboBox.h"

@class OGTKWidget;

/**
 * The #GtkAppChooserButton is a widget that lets the user select
 * an application. It implements the #GtkAppChooser interface.
 * 
 * Initially, a #GtkAppChooserButton selects the first application
 * in its list, which will either be the most-recently used application
 * or, if #GtkAppChooserButton:show-default-item is %TRUE, the
 * default application.
 * 
 * The list of applications shown in a #GtkAppChooserButton includes
 * the recommended applications for the given content type. When
 * #GtkAppChooserButton:show-default-item is set, the default application
 * is also included. To let the user chooser other applications,
 * you can set the #GtkAppChooserButton:show-dialog-item property,
 * which allows to open a full #GtkAppChooserDialog.
 * 
 * It is possible to add custom items to the list, using
 * gtk_app_chooser_button_append_custom_item(). These items cause
 * the #GtkAppChooserButton::custom-item-activated signal to be
 * emitted when they are selected.
 * 
 * To track changes in the selected application, use the
 * #GtkComboBox::changed signal.
 *
 */
@interface OGTKAppChooserButton : OGTKComboBox
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)contentType;

/**
 * Methods
 */

- (GtkAppChooserButton*)APPCHOOSERBUTTON;

/**
 * Appends a custom item to the list of applications that is shown
 * in the popup; the item name must be unique per-widget.
 * Clients can use the provided name as a detail for the
 * #GtkAppChooserButton::custom-item-activated signal, to add a
 * callback for the activation of a particular custom item in the list.
 * See also gtk_app_chooser_button_append_separator().
 *
 * @param name the name of the custom item
 * @param label the label for the custom item
 * @param icon the icon for the custom item
 */
- (void)appendCustomItemWithName:(OFString*)name label:(OFString*)label icon:(GIcon*)icon;

/**
 * Appends a separator to the list of applications that is shown
 * in the popup.
 *
 */
- (void)appendSeparator;

/**
 * Returns the text to display at the top of the dialog.
 *
 * @return the text to display at the top of the dialog,
 *     or %NULL, in which case a default text is displayed
 */
- (OFString*)heading;

/**
 * Returns the current value of the #GtkAppChooserButton:show-default-item
 * property.
 *
 * @return the value of #GtkAppChooserButton:show-default-item
 */
- (bool)showDefaultItem;

/**
 * Returns the current value of the #GtkAppChooserButton:show-dialog-item
 * property.
 *
 * @return the value of #GtkAppChooserButton:show-dialog-item
 */
- (bool)showDialogItem;

/**
 * Selects a custom item previously added with
 * gtk_app_chooser_button_append_custom_item().
 * 
 * Use gtk_app_chooser_refresh() to bring the selection
 * to its initial state.
 *
 * @param name the name of the custom item
 */
- (void)setActiveCustomItem:(OFString*)name;

/**
 * Sets the text to display at the top of the dialog.
 * If the heading is not set, the dialog displays a default text.
 *
 * @param heading a string containing Pango markup
 */
- (void)setHeading:(OFString*)heading;

/**
 * Sets whether the dropdown menu of this button should show the
 * default application for the given content type at top.
 *
 * @param setting the new value for #GtkAppChooserButton:show-default-item
 */
- (void)setShowDefaultItem:(bool)setting;

/**
 * Sets whether the dropdown menu of this button should show an
 * entry to trigger a #GtkAppChooserDialog.
 *
 * @param setting the new value for #GtkAppChooserButton:show-dialog-item
 */
- (void)setShowDialogItem:(bool)setting;

@end