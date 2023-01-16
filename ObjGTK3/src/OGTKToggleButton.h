/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKButton.h"

@class OGTKWidget;

/**
 * A #GtkToggleButton is a #GtkButton which will remain “pressed-in” when
 * clicked. Clicking again will cause the toggle button to return to its
 * normal state.
 * 
 * A toggle button is created by calling either gtk_toggle_button_new() or
 * gtk_toggle_button_new_with_label(). If using the former, it is advisable to
 * pack a widget, (such as a #GtkLabel and/or a #GtkImage), into the toggle
 * button’s container. (See #GtkButton for more information).
 * 
 * The state of a #GtkToggleButton can be set specifically using
 * gtk_toggle_button_set_active(), and retrieved using
 * gtk_toggle_button_get_active().
 * 
 * To simply switch the state of a toggle button, use gtk_toggle_button_toggled().
 * 
 * # CSS nodes
 * 
 * GtkToggleButton has a single CSS node with name button. To differentiate
 * it from a plain #GtkButton, it gets the .toggle style class.
 * 
 * ## Creating two #GtkToggleButton widgets.
 * 
 * |[<!-- language="C" -->
 * static void output_state (GtkToggleButton *source, gpointer user_data) {
 *   printf ("Active: %d\n", gtk_toggle_button_get_active (source));
 * }
 * 
 * void make_toggles (void) {
 *   GtkWidget *window, *toggle1, *toggle2;
 *   GtkWidget *box;
 *   const char *text;
 * 
 *   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 *   box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 12);
 * 
 *   text = "Hi, I’m a toggle button.";
 *   toggle1 = gtk_toggle_button_new_with_label (text);
 * 
 *   // Makes this toggle button invisible
 *   gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (toggle1),
 *                               TRUE);
 * 
 *   g_signal_connect (toggle1, "toggled",
 *                     G_CALLBACK (output_state),
 *                     NULL);
 *   gtk_container_add (GTK_CONTAINER (box), toggle1);
 * 
 *   text = "Hi, I’m a toggle button.";
 *   toggle2 = gtk_toggle_button_new_with_label (text);
 *   gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (toggle2),
 *                               FALSE);
 *   g_signal_connect (toggle2, "toggled",
 *                     G_CALLBACK (output_state),
 *                     NULL);
 *   gtk_container_add (GTK_CONTAINER (box), toggle2);
 * 
 *   gtk_container_add (GTK_CONTAINER (window), box);
 *   gtk_widget_show_all (window);
 * }
 * ]|
 *
 */
@interface OGTKToggleButton : OGTKButton
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initWithLabel:(OFString*)label;
- (instancetype)initWithMnemonic:(OFString*)label;

/**
 * Methods
 */

- (GtkToggleButton*)TOGGLEBUTTON;

/**
 * Queries a #GtkToggleButton and returns its current state. Returns %TRUE if
 * the toggle button is pressed in and %FALSE if it is raised.
 *
 * @return a #gboolean value.
 */
- (bool)active;

/**
 * Gets the value set by gtk_toggle_button_set_inconsistent().
 *
 * @return %TRUE if the button is displayed as inconsistent, %FALSE otherwise
 */
- (bool)inconsistent;

/**
 * Retrieves whether the button is displayed as a separate indicator
 * and label. See gtk_toggle_button_set_mode().
 *
 * @return %TRUE if the togglebutton is drawn as a separate indicator
 *   and label.
 */
- (bool)mode;

/**
 * Sets the status of the toggle button. Set to %TRUE if you want the
 * GtkToggleButton to be “pressed in”, and %FALSE to raise it.
 * This action causes the #GtkToggleButton::toggled signal and the
 * #GtkButton::clicked signal to be emitted.
 *
 * @param isActive %TRUE or %FALSE.
 */
- (void)setActive:(bool)isActive;

/**
 * If the user has selected a range of elements (such as some text or
 * spreadsheet cells) that are affected by a toggle button, and the
 * current values in that range are inconsistent, you may want to
 * display the toggle in an “in between” state. This function turns on
 * “in between” display.  Normally you would turn off the inconsistent
 * state again if the user toggles the toggle button. This has to be
 * done manually, gtk_toggle_button_set_inconsistent() only affects
 * visual appearance, it doesn’t affect the semantics of the button.
 *
 * @param setting %TRUE if state is inconsistent
 */
- (void)setInconsistent:(bool)setting;

/**
 * Sets whether the button is displayed as a separate indicator and label.
 * You can call this function on a checkbutton or a radiobutton with
 * @draw_indicator = %FALSE to make the button look like a normal button.
 * 
 * This can be used to create linked strip of buttons that work like
 * a #GtkStackSwitcher.
 * 
 * This function only affects instances of classes like #GtkCheckButton
 * and #GtkRadioButton that derive from #GtkToggleButton,
 * not instances of #GtkToggleButton itself.
 *
 * @param drawIndicator if %TRUE, draw the button as a separate indicator
 * and label; if %FALSE, draw the button like a normal button
 */
- (void)setMode:(bool)drawIndicator;

/**
 * Emits the #GtkToggleButton::toggled signal on the
 * #GtkToggleButton. There is no good reason for an
 * application ever to call this function.
 *
 */
- (void)toggled;

@end