/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKLabel.h"

@class OGTKWidget;

/**
 * The #GtkAccelLabel widget is a subclass of #GtkLabel that also displays an
 * accelerator key on the right of the label text, e.g. “Ctrl+S”.
 * It is commonly used in menus to show the keyboard short-cuts for commands.
 * 
 * The accelerator key to display is typically not set explicitly (although it
 * can be, with gtk_accel_label_set_accel()). Instead, the #GtkAccelLabel displays
 * the accelerators which have been added to a particular widget. This widget is
 * set by calling gtk_accel_label_set_accel_widget().
 * 
 * For example, a #GtkMenuItem widget may have an accelerator added to emit
 * the “activate” signal when the “Ctrl+S” key combination is pressed.
 * A #GtkAccelLabel is created and added to the #GtkMenuItem, and
 * gtk_accel_label_set_accel_widget() is called with the #GtkMenuItem as the
 * second argument. The #GtkAccelLabel will now display “Ctrl+S” after its label.
 * 
 * Note that creating a #GtkMenuItem with gtk_menu_item_new_with_label() (or
 * one of the similar functions for #GtkCheckMenuItem and #GtkRadioMenuItem)
 * automatically adds a #GtkAccelLabel to the #GtkMenuItem and calls
 * gtk_accel_label_set_accel_widget() to set it up for you.
 * 
 * A #GtkAccelLabel will only display accelerators which have %GTK_ACCEL_VISIBLE
 * set (see #GtkAccelFlags).
 * A #GtkAccelLabel can display multiple accelerators and even signal names,
 * though it is almost always used to display just one accelerator key.
 * 
 * ## Creating a simple menu item with an accelerator key.
 * 
 * |[<!-- language="C" -->
 *   GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 *   GtkWidget *menu = gtk_menu_new ();
 *   GtkWidget *save_item;
 *   GtkAccelGroup *accel_group;
 * 
 *   // Create a GtkAccelGroup and add it to the window.
 *   accel_group = gtk_accel_group_new ();
 *   gtk_window_add_accel_group (GTK_WINDOW (window), accel_group);
 * 
 *   // Create the menu item using the convenience function.
 *   save_item = gtk_menu_item_new_with_label ("Save");
 *   gtk_widget_show (save_item);
 *   gtk_container_add (GTK_CONTAINER (menu), save_item);
 * 
 *   // Now add the accelerator to the GtkMenuItem. Note that since we
 *   // called gtk_menu_item_new_with_label() to create the GtkMenuItem
 *   // the GtkAccelLabel is automatically set up to display the
 *   // GtkMenuItem accelerators. We just need to make sure we use
 *   // GTK_ACCEL_VISIBLE here.
 *   gtk_widget_add_accelerator (save_item, "activate", accel_group,
 *                               GDK_KEY_s, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
 * ]|
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * label
 * ╰── accelerator
 * ]|
 * 
 * Like #GtkLabel, GtkAccelLabel has a main CSS node with the name label.
 * It adds a subnode with name accelerator.
 *
 */
@interface OGTKAccelLabel : OGTKLabel
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)string;

/**
 * Methods
 */

- (GtkAccelLabel*)ACCELLABEL;

/**
 * Gets the keyval and modifier mask set with
 * gtk_accel_label_set_accel().
 *
 * @param acceleratorKey return location for the keyval
 * @param acceleratorMods return location for the modifier mask
 */
- (void)accelWithAcceleratorKey:(guint*)acceleratorKey acceleratorMods:(GdkModifierType*)acceleratorMods;

/**
 * Fetches the widget monitored by this accelerator label. See
 * gtk_accel_label_set_accel_widget().
 *
 * @return the object monitored by the accelerator label, or %NULL.
 */
- (OGTKWidget*)accelWidget;

/**
 * Returns the width needed to display the accelerator key(s).
 * This is used by menus to align all of the #GtkMenuItem widgets, and shouldn't
 * be needed by applications.
 *
 * @return the width needed to display the accelerator key(s).
 */
- (guint)accelWidth;

/**
 * Recreates the string representing the accelerator keys.
 * This should not be needed since the string is automatically updated whenever
 * accelerators are added or removed from the associated widget.
 *
 * @return always returns %FALSE.
 */
- (bool)refetch;

/**
 * Manually sets a keyval and modifier mask as the accelerator rendered
 * by @accel_label.
 * 
 * If a keyval and modifier are explicitly set then these values are
 * used regardless of any associated accel closure or widget.
 * 
 * Providing an @accelerator_key of 0 removes the manual setting.
 *
 * @param acceleratorKey a keyval, or 0
 * @param acceleratorMods the modifier mask for the accel
 */
- (void)setAccelWithAcceleratorKey:(guint)acceleratorKey acceleratorMods:(GdkModifierType)acceleratorMods;

/**
 * Sets the closure to be monitored by this accelerator label. The closure
 * must be connected to an accelerator group; see gtk_accel_group_connect().
 * Passing %NULL for @accel_closure will dissociate @accel_label from its
 * current closure, if any.
 *
 * @param accelClosure the closure to monitor for accelerator changes,
 * or %NULL
 */
- (void)setAccelClosure:(GClosure*)accelClosure;

/**
 * Sets the widget to be monitored by this accelerator label. Passing %NULL for
 * @accel_widget will dissociate @accel_label from its current widget, if any.
 *
 * @param accelWidget the widget to be monitored, or %NULL
 */
- (void)setAccelWidget:(OGTKWidget*)accelWidget;

@end