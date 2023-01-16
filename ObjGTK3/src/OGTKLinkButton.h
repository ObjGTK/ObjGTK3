/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKButton.h"

@class OGTKWidget;

/**
 * A GtkLinkButton is a #GtkButton with a hyperlink, similar to the one
 * used by web browsers, which triggers an action when clicked. It is useful
 * to show quick links to resources.
 * 
 * A link button is created by calling either gtk_link_button_new() or
 * gtk_link_button_new_with_label(). If using the former, the URI you pass
 * to the constructor is used as a label for the widget.
 * 
 * The URI bound to a GtkLinkButton can be set specifically using
 * gtk_link_button_set_uri(), and retrieved using gtk_link_button_get_uri().
 * 
 * By default, GtkLinkButton calls gtk_show_uri_on_window() when the button is
 * clicked. This behaviour can be overridden by connecting to the
 * #GtkLinkButton::activate-link signal and returning %TRUE from the
 * signal handler.
 * 
 * # CSS nodes
 * 
 * GtkLinkButton has a single CSS node with name button. To differentiate
 * it from a plain #GtkButton, it gets the .link style class.
 *
 */
@interface OGTKLinkButton : OGTKButton
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)uri;
- (instancetype)initWithLabelWithUri:(OFString*)uri label:(OFString*)label;

/**
 * Methods
 */

- (GtkLinkButton*)LINKBUTTON;

/**
 * Retrieves the URI set using gtk_link_button_set_uri().
 *
 * @return a valid URI.  The returned string is owned by the link button
 *   and should not be modified or freed.
 */
- (OFString*)uri;

/**
 * Retrieves the “visited” state of the URI where the #GtkLinkButton
 * points. The button becomes visited when it is clicked. If the URI
 * is changed on the button, the “visited” state is unset again.
 * 
 * The state may also be changed using gtk_link_button_set_visited().
 *
 * @return %TRUE if the link has been visited, %FALSE otherwise
 */
- (bool)visited;

/**
 * Sets @uri as the URI where the #GtkLinkButton points. As a side-effect
 * this unsets the “visited” state of the button.
 *
 * @param uri a valid URI
 */
- (void)setUri:(OFString*)uri;

/**
 * Sets the “visited” state of the URI where the #GtkLinkButton
 * points.  See gtk_link_button_get_visited() for more details.
 *
 * @param visited the new “visited” state
 */
- (void)setVisited:(bool)visited;

@end