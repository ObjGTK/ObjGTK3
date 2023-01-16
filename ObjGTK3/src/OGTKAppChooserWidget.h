/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

@class OGTKWidget;

/**
 * #GtkAppChooserWidget is a widget for selecting applications.
 * It is the main building block for #GtkAppChooserDialog. Most
 * applications only need to use the latter; but you can use
 * this widget as part of a larger widget if you have special needs.
 * 
 * #GtkAppChooserWidget offers detailed control over what applications
 * are shown, using the
 * #GtkAppChooserWidget:show-default,
 * #GtkAppChooserWidget:show-recommended,
 * #GtkAppChooserWidget:show-fallback,
 * #GtkAppChooserWidget:show-other and
 * #GtkAppChooserWidget:show-all
 * properties. See the #GtkAppChooser documentation for more information
 * about these groups of applications.
 * 
 * To keep track of the selected application, use the
 * #GtkAppChooserWidget::application-selected and #GtkAppChooserWidget::application-activated signals.
 * 
 * # CSS nodes
 * 
 * GtkAppChooserWidget has a single CSS node with name appchooser.
 *
 */
@interface OGTKAppChooserWidget : OGTKBox
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)contentType;

/**
 * Methods
 */

- (GtkAppChooserWidget*)APPCHOOSERWIDGET;

/**
 * Returns the text that is shown if there are not applications
 * that can handle the content type.
 *
 * @return the value of #GtkAppChooserWidget:default-text
 */
- (OFString*)defaultText;

/**
 * Returns the current value of the #GtkAppChooserWidget:show-all
 * property.
 *
 * @return the value of #GtkAppChooserWidget:show-all
 */
- (bool)showAll;

/**
 * Returns the current value of the #GtkAppChooserWidget:show-default
 * property.
 *
 * @return the value of #GtkAppChooserWidget:show-default
 */
- (bool)showDefault;

/**
 * Returns the current value of the #GtkAppChooserWidget:show-fallback
 * property.
 *
 * @return the value of #GtkAppChooserWidget:show-fallback
 */
- (bool)showFallback;

/**
 * Returns the current value of the #GtkAppChooserWidget:show-other
 * property.
 *
 * @return the value of #GtkAppChooserWidget:show-other
 */
- (bool)showOther;

/**
 * Returns the current value of the #GtkAppChooserWidget:show-recommended
 * property.
 *
 * @return the value of #GtkAppChooserWidget:show-recommended
 */
- (bool)showRecommended;

/**
 * Sets the text that is shown if there are not applications
 * that can handle the content type.
 *
 * @param text the new value for #GtkAppChooserWidget:default-text
 */
- (void)setDefaultText:(OFString*)text;

/**
 * Sets whether the app chooser should show all applications
 * in a flat list.
 *
 * @param setting the new value for #GtkAppChooserWidget:show-all
 */
- (void)setShowAll:(bool)setting;

/**
 * Sets whether the app chooser should show the default handler
 * for the content type in a separate section.
 *
 * @param setting the new value for #GtkAppChooserWidget:show-default
 */
- (void)setShowDefault:(bool)setting;

/**
 * Sets whether the app chooser should show related applications
 * for the content type in a separate section.
 *
 * @param setting the new value for #GtkAppChooserWidget:show-fallback
 */
- (void)setShowFallback:(bool)setting;

/**
 * Sets whether the app chooser should show applications
 * which are unrelated to the content type.
 *
 * @param setting the new value for #GtkAppChooserWidget:show-other
 */
- (void)setShowOther:(bool)setting;

/**
 * Sets whether the app chooser should show recommended applications
 * for the content type in a separate section.
 *
 * @param setting the new value for #GtkAppChooserWidget:show-recommended
 */
- (void)setShowRecommended:(bool)setting;

@end