/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>
#include <gtk/gtk.h>

#import <OGObject/OGObject.h>

@class OGTKAction;
@class OGTKAccelGroup;

/**
 * Actions are organised into groups. An action group is essentially a
 * map from names to #GtkAction objects.
 * 
 * All actions that would make sense to use in a particular context
 * should be in a single group. Multiple action groups may be used for a
 * particular user interface. In fact, it is expected that most nontrivial
 * applications will make use of multiple groups. For example, in an
 * application that can edit multiple documents, one group holding global
 * actions (e.g. quit, about, new), and one group per document holding
 * actions that act on that document (eg. save, cut/copy/paste, etc). Each
 * window’s menus would be constructed from a combination of two action
 * groups.
 * 
 * ## Accelerators ## {#Action-Accel}
 * 
 * Accelerators are handled by the GTK+ accelerator map. All actions are
 * assigned an accelerator path (which normally has the form
 * `<Actions>/group-name/action-name`) and a shortcut is associated with
 * this accelerator path. All menuitems and toolitems take on this accelerator
 * path. The GTK+ accelerator map code makes sure that the correct shortcut
 * is displayed next to the menu item.
 * 
 * # GtkActionGroup as GtkBuildable # {#GtkActionGroup-BUILDER-UI}
 * 
 * The #GtkActionGroup implementation of the #GtkBuildable interface accepts
 * #GtkAction objects as <child> elements in UI definitions.
 * 
 * Note that it is probably more common to define actions and action groups
 * in the code, since they are directly related to what the code can do.
 * 
 * The GtkActionGroup implementation of the GtkBuildable interface supports
 * a custom <accelerator> element, which has attributes named “key“ and
 * “modifiers“ and allows to specify accelerators. This is similar to the
 * <accelerator> element of #GtkWidget, the main difference is that
 * it doesn’t allow you to specify a signal.
 * 
 * ## A #GtkDialog UI definition fragment. ##
 * |[
 * <object class="GtkActionGroup" id="actiongroup">
 *   <child>
 *       <object class="GtkAction" id="About">
 *           <property name="name">About</property>
 *           <property name="stock_id">gtk-about</property>
 *           <signal handler="about_activate" name="activate"/>
 *       </object>
 *       <accelerator key="F1" modifiers="GDK_CONTROL_MASK | GDK_SHIFT_MASK"/>
 *   </child>
 * </object>
 * ]|
 *
 */
@interface OGTKActionGroup : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)name;

/**
 * Methods
 */

- (GtkActionGroup*)ACTIONGROUP;

/**
 * Adds an action object to the action group. Note that this function
 * does not set up the accel path of the action, which can lead to problems
 * if a user tries to modify the accelerator of a menuitem associated with
 * the action. Therefore you must either set the accel path yourself with
 * gtk_action_set_accel_path(), or use
 * `gtk_action_group_add_action_with_accel (..., NULL)`.
 *
 * @param action an action
 */
- (void)addAction:(OGTKAction*)action;

/**
 * Adds an action object to the action group and sets up the accelerator.
 * 
 * If @accelerator is %NULL, attempts to use the accelerator associated
 * with the stock_id of the action.
 * 
 * Accel paths are set to `<Actions>/group-name/action-name`.
 *
 * @param action the action to add
 * @param accelerator the accelerator for the action, in
 *   the format understood by gtk_accelerator_parse(), or "" for no accelerator, or
 *   %NULL to use the stock accelerator
 */
- (void)addActionWithAccelWithAction:(OGTKAction*)action accelerator:(OFString*)accelerator;

/**
 * This is a convenience function to create a number of actions and add them
 * to the action group.
 * 
 * The “activate” signals of the actions are connected to the callbacks
 * and their accel paths are set to `<Actions>/group-name/action-name`.
 *
 * @param entries an array of action descriptions
 * @param nentries the number of entries
 * @param userData data to pass to the action callbacks
 */
- (void)addActionsWithEntries:(const GtkActionEntry*)entries nentries:(guint)nentries userData:(gpointer)userData;

/**
 * This variant of gtk_action_group_add_actions() adds a #GDestroyNotify
 * callback for @user_data.
 *
 * @param entries an array of action descriptions
 * @param nentries the number of entries
 * @param userData data to pass to the action callbacks
 * @param destroy destroy notification callback for @user_data
 */
- (void)addActionsFullWithEntries:(const GtkActionEntry*)entries nentries:(guint)nentries userData:(gpointer)userData destroy:(GDestroyNotify)destroy;

/**
 * This is a convenience routine to create a group of radio actions and
 * add them to the action group.
 * 
 * The “changed” signal of the first radio action is connected to the
 * @on_change callback and the accel paths of the actions are set to
 * `<Actions>/group-name/action-name`.
 *
 * @param entries an array of radio action descriptions
 * @param nentries the number of entries
 * @param value the value of the action to activate initially, or -1 if
 *   no action should be activated
 * @param onChange the callback to connect to the changed signal
 * @param userData data to pass to the action callbacks
 */
- (void)addRadioActionsWithEntries:(const GtkRadioActionEntry*)entries nentries:(guint)nentries value:(gint)value onChange:(GCallback)onChange userData:(gpointer)userData;

/**
 * This variant of gtk_action_group_add_radio_actions() adds a
 * #GDestroyNotify callback for @user_data.
 *
 * @param entries an array of radio action descriptions
 * @param nentries the number of entries
 * @param value the value of the action to activate initially, or -1 if
 *   no action should be activated
 * @param onChange the callback to connect to the changed signal
 * @param userData data to pass to the action callbacks
 * @param destroy destroy notification callback for @user_data
 */
- (void)addRadioActionsFullWithEntries:(const GtkRadioActionEntry*)entries nentries:(guint)nentries value:(gint)value onChange:(GCallback)onChange userData:(gpointer)userData destroy:(GDestroyNotify)destroy;

/**
 * This is a convenience function to create a number of toggle actions and add them
 * to the action group.
 * 
 * The “activate” signals of the actions are connected to the callbacks
 * and their accel paths are set to `<Actions>/group-name/action-name`.
 *
 * @param entries an array of toggle action descriptions
 * @param nentries the number of entries
 * @param userData data to pass to the action callbacks
 */
- (void)addToggleActionsWithEntries:(const GtkToggleActionEntry*)entries nentries:(guint)nentries userData:(gpointer)userData;

/**
 * This variant of gtk_action_group_add_toggle_actions() adds a
 * #GDestroyNotify callback for @user_data.
 *
 * @param entries an array of toggle action descriptions
 * @param nentries the number of entries
 * @param userData data to pass to the action callbacks
 * @param destroy destroy notification callback for @user_data
 */
- (void)addToggleActionsFullWithEntries:(const GtkToggleActionEntry*)entries nentries:(guint)nentries userData:(gpointer)userData destroy:(GDestroyNotify)destroy;

/**
 * Gets the accelerator group.
 *
 * @return the accelerator group associated with this action
 * group or %NULL if there is none.
 */
- (OGTKAccelGroup*)accelGroup;

/**
 * Looks up an action in the action group by name.
 *
 * @param actionName the name of the action
 * @return the action, or %NULL if no action by that name exists
 */
- (OGTKAction*)action:(OFString*)actionName;

/**
 * Gets the name of the action group.
 *
 * @return the name of the action group.
 */
- (OFString*)name;

/**
 * Returns %TRUE if the group is sensitive.  The constituent actions
 * can only be logically sensitive (see gtk_action_is_sensitive()) if
 * they are sensitive (see gtk_action_get_sensitive()) and their group
 * is sensitive.
 *
 * @return %TRUE if the group is sensitive.
 */
- (bool)sensitive;

/**
 * Returns %TRUE if the group is visible.  The constituent actions
 * can only be logically visible (see gtk_action_is_visible()) if
 * they are visible (see gtk_action_get_visible()) and their group
 * is visible.
 *
 * @return %TRUE if the group is visible.
 */
- (bool)visible;

/**
 * Lists the actions in the action group.
 *
 * @return an allocated list of the action objects in the action group
 */
- (GList*)listActions;

/**
 * Removes an action object from the action group.
 *
 * @param action an action
 */
- (void)removeAction:(OGTKAction*)action;

/**
 * Sets the accelerator group to be used by every action in this group.
 *
 * @param accelGroup a #GtkAccelGroup to set or %NULL
 */
- (void)setAccelGroup:(OGTKAccelGroup*)accelGroup;

/**
 * Changes the sensitivity of @action_group
 *
 * @param sensitive new sensitivity
 */
- (void)setSensitive:(bool)sensitive;

/**
 * Sets a function to be used for translating the @label and @tooltip of
 * #GtkActionEntrys added by gtk_action_group_add_actions().
 * 
 * If you’re using gettext(), it is enough to set the translation domain
 * with gtk_action_group_set_translation_domain().
 *
 * @param func a #GtkTranslateFunc
 * @param data data to be passed to @func and @notify
 * @param notify a #GDestroyNotify function to be called when @action_group is
 *   destroyed and when the translation function is changed again
 */
- (void)setTranslateFuncWithFunc:(GtkTranslateFunc)func data:(gpointer)data notify:(GDestroyNotify)notify;

/**
 * Sets the translation domain and uses g_dgettext() for translating the
 * @label and @tooltip of #GtkActionEntrys added by
 * gtk_action_group_add_actions().
 * 
 * If you’re not using gettext() for localization, see
 * gtk_action_group_set_translate_func().
 *
 * @param domain the translation domain to use for g_dgettext()
 * calls, or %NULL to use the domain set with textdomain()
 */
- (void)setTranslationDomain:(OFString*)domain;

/**
 * Changes the visible of @action_group.
 *
 * @param visible new visiblity
 */
- (void)setVisible:(bool)visible;

/**
 * Translates a string using the function set with
 * gtk_action_group_set_translate_func(). This
 * is mainly intended for language bindings.
 *
 * @param string a string
 * @return the translation of @string
 */
- (OFString*)translateString:(OFString*)string;

@end