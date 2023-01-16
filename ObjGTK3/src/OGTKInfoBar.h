/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

@class OGTKWidget;

/**
 * #GtkInfoBar is a widget that can be used to show messages to
 * the user without showing a dialog. It is often temporarily shown
 * at the top or bottom of a document. In contrast to #GtkDialog, which
 * has a action area at the bottom, #GtkInfoBar has an action area
 * at the side.
 * 
 * The API of #GtkInfoBar is very similar to #GtkDialog, allowing you
 * to add buttons to the action area with gtk_info_bar_add_button() or
 * gtk_info_bar_new_with_buttons(). The sensitivity of action widgets
 * can be controlled with gtk_info_bar_set_response_sensitive().
 * To add widgets to the main content area of a #GtkInfoBar, use
 * gtk_info_bar_get_content_area() and add your widgets to the container.
 * 
 * Similar to #GtkMessageDialog, the contents of a #GtkInfoBar can by
 * classified as error message, warning, informational message, etc,
 * by using gtk_info_bar_set_message_type(). GTK+ may use the message type
 * to determine how the message is displayed.
 * 
 * A simple example for using a #GtkInfoBar:
 * |[<!-- language="C" -->
 * GtkWidget *widget, *message_label, *content_area;
 * GtkWidget *grid;
 * GtkInfoBar *bar;
 * 
 * // set up info bar
 * widget = gtk_info_bar_new ();
 * bar = GTK_INFO_BAR (widget);
 * grid = gtk_grid_new ();
 * 
 * gtk_widget_set_no_show_all (widget, TRUE);
 * message_label = gtk_label_new ("");
 * content_area = gtk_info_bar_get_content_area (bar);
 * gtk_container_add (GTK_CONTAINER (content_area),
 *                    message_label);
 * gtk_info_bar_add_button (bar,
 *                          _("_OK"),
 *                          GTK_RESPONSE_OK);
 * g_signal_connect (bar,
 *                   "response",
 *                   G_CALLBACK (gtk_widget_hide),
 *                   NULL);
 * gtk_grid_attach (GTK_GRID (grid),
 *                  widget,
 *                  0, 2, 1, 1);
 * 
 * // ...
 * 
 * // show an error message
 * gtk_label_set_text (GTK_LABEL (message_label), "An error occurred!");
 * gtk_info_bar_set_message_type (bar,
 *                                GTK_MESSAGE_ERROR);
 * gtk_widget_show (bar);
 * ]|
 * 
 * # GtkInfoBar as GtkBuildable
 * 
 * The GtkInfoBar implementation of the GtkBuildable interface exposes
 * the content area and action area as internal children with the names
 * “content_area” and “action_area”.
 * 
 * GtkInfoBar supports a custom `<action-widgets>` element, which can contain
 * multiple `<action-widget>` elements. The “response” attribute specifies a
 * numeric response, and the content of the element is the id of widget
 * (which should be a child of the dialogs @action_area).
 * 
 * # CSS nodes
 * 
 * GtkInfoBar has a single CSS node with name infobar. The node may get
 * one of the style classes .info, .warning, .error or .question, depending
 * on the message type.
 *
 */
@interface OGTKInfoBar : OGTKBox
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkInfoBar*)INFOBAR;

/**
 * Add an activatable widget to the action area of a #GtkInfoBar,
 * connecting a signal handler that will emit the #GtkInfoBar::response
 * signal on the message area when the widget is activated. The widget
 * is appended to the end of the message areas action area.
 *
 * @param child an activatable widget
 * @param responseId response ID for @child
 */
- (void)addActionWidgetWithChild:(OGTKWidget*)child responseId:(gint)responseId;

/**
 * Adds a button with the given text and sets things up so that
 * clicking the button will emit the “response” signal with the given
 * response_id. The button is appended to the end of the info bars's
 * action area. The button widget is returned, but usually you don't
 * need it.
 *
 * @param buttonText text of button
 * @param responseId response ID for the button
 * @return the #GtkButton widget
 * that was added
 */
- (OGTKWidget*)addButtonWithButtonText:(OFString*)buttonText responseId:(gint)responseId;

/**
 * Returns the action area of @info_bar.
 *
 * @return the action area
 */
- (OGTKWidget*)actionArea;

/**
 * Returns the content area of @info_bar.
 *
 * @return the content area
 */
- (OGTKWidget*)contentArea;

/**
 * Returns the message type of the message area.
 *
 * @return the message type of the message area.
 */
- (GtkMessageType)messageType;

/**
 *
 * @return the current value of the GtkInfoBar:revealed property.
 */
- (bool)revealed;

/**
 * Returns whether the widget will display a standard close button.
 *
 * @return %TRUE if the widget displays standard close button
 */
- (bool)showCloseButton;

/**
 * Emits the “response” signal with the given @response_id.
 *
 * @param responseId a response ID
 */
- (void)response:(gint)responseId;

/**
 * Sets the last widget in the info bar’s action area with
 * the given response_id as the default widget for the dialog.
 * Pressing “Enter” normally activates the default widget.
 * 
 * Note that this function currently requires @info_bar to
 * be added to a widget hierarchy.
 *
 * @param responseId a response ID
 */
- (void)setDefaultResponse:(gint)responseId;

/**
 * Sets the message type of the message area.
 * 
 * GTK+ uses this type to determine how the message is displayed.
 *
 * @param messageType a #GtkMessageType
 */
- (void)setMessageType:(GtkMessageType)messageType;

/**
 * Calls gtk_widget_set_sensitive (widget, setting) for each
 * widget in the info bars’s action area with the given response_id.
 * A convenient way to sensitize/desensitize dialog buttons.
 *
 * @param responseId a response ID
 * @param setting TRUE for sensitive
 */
- (void)setResponseSensitiveWithResponseId:(gint)responseId setting:(bool)setting;

/**
 * Sets the GtkInfoBar:revealed property to @revealed. This will cause
 * @info_bar to show up with a slide-in transition.
 * 
 * Note that this property does not automatically show @info_bar and thus won’t
 * have any effect if it is invisible.
 *
 * @param revealed The new value of the property
 */
- (void)setRevealed:(bool)revealed;

/**
 * If true, a standard close button is shown. When clicked it emits
 * the response %GTK_RESPONSE_CLOSE.
 *
 * @param setting %TRUE to include a close button
 */
- (void)setShowCloseButton:(bool)setting;

@end