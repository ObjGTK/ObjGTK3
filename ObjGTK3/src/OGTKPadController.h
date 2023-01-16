/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEventController.h"

@class OGTKWindow;
@class OGGdkDevice;

/**
 * #GtkPadController is an event controller for the pads found in drawing
 * tablets (The collection of buttons and tactile sensors often found around
 * the stylus-sensitive area).
 * 
 * These buttons and sensors have no implicit meaning, and by default they
 * perform no action, this event controller is provided to map those to
 * #GAction objects, thus letting the application give those a more semantic
 * meaning.
 * 
 * Buttons and sensors are not constrained to triggering a single action, some
 * %GDK_SOURCE_TABLET_PAD devices feature multiple "modes", all these input
 * elements have one current mode, which may determine the final action
 * being triggered. Pad devices often divide buttons and sensors into groups,
 * all elements in a group share the same current mode, but different groups
 * may have different modes. See gdk_device_pad_get_n_groups() and
 * gdk_device_pad_get_group_n_modes().
 * 
 * Each of the actions that a given button/strip/ring performs for a given
 * mode is defined by #GtkPadActionEntry, it contains an action name that
 * will be looked up in the given #GActionGroup and activated whenever the
 * specified input element and mode are triggered.
 * 
 * A simple example of #GtkPadController usage, assigning button 1 in all
 * modes and pad devices to an "invert-selection" action:
 * |[
 *   GtkPadActionEntry *pad_actions[] = {
 *     { GTK_PAD_ACTION_BUTTON, 1, -1, "Invert selection", "pad-actions.invert-selection" },
 *     …
 *   };
 * 
 *   …
 *   action_group = g_simple_action_group_new ();
 *   action = g_simple_action_new ("pad-actions.invert-selection", NULL);
 *   g_signal_connect (action, "activate", on_invert_selection_activated, NULL);
 *   g_action_map_add_action (G_ACTION_MAP (action_group), action);
 *   …
 *   pad_controller = gtk_pad_controller_new (window, action_group, NULL);
 * ]|
 * 
 * The actions belonging to rings/strips will be activated with a parameter
 * of type %G_VARIANT_TYPE_DOUBLE bearing the value of the given axis, it
 * is required that those are made stateful and accepting this #GVariantType.
 *
 */
@interface OGTKPadController : OGTKEventController
{

}


/**
 * Constructors
 */
- (instancetype)initWithWindow:(OGTKWindow*)window group:(GActionGroup*)group pad:(OGGdkDevice*)pad;

/**
 * Methods
 */

- (GtkPadController*)PADCONTROLLER;

/**
 * Adds an individual action to @controller. This action will only be activated
 * if the given button/ring/strip number in @index is interacted while
 * the current mode is @mode. -1 may be used for simple cases, so the action
 * is triggered on all modes.
 * 
 * The given @label should be considered user-visible, so internationalization
 * rules apply. Some windowing systems may be able to use those for user
 * feedback.
 *
 * @param type the type of pad feature that will trigger this action
 * @param index the 0-indexed button/ring/strip number that will trigger this action
 * @param mode the mode that will trigger this action, or -1 for all modes.
 * @param label Human readable description of this action, this string should
 *   be deemed user-visible.
 * @param actionName action name that will be activated in the #GActionGroup
 */
- (void)setActionWithType:(GtkPadActionType)type index:(gint)index mode:(gint)mode label:(OFString*)label actionName:(OFString*)actionName;

/**
 * This is a convenience function to add a group of action entries on
 * @controller. See #GtkPadActionEntry and gtk_pad_controller_set_action().
 *
 * @param entries the action entries to set on @controller
 * @param nentries the number of elements in @entries
 */
- (void)setActionEntriesWithEntries:(const GtkPadActionEntry*)entries nentries:(gint)nentries;

@end