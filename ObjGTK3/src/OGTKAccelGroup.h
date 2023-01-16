/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtkx.h>
#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>

#import <OGObject/OGObject.h>

/**
 * A #GtkAccelGroup represents a group of keyboard accelerators,
 * typically attached to a toplevel #GtkWindow (with
 * gtk_window_add_accel_group()). Usually you won’t need to create a
 * #GtkAccelGroup directly; instead, when using #GtkUIManager, GTK+
 * automatically sets up the accelerators for your menus in the ui
 * manager’s #GtkAccelGroup.
 * 
 * Note that “accelerators” are different from
 * “mnemonics”. Accelerators are shortcuts for
 * activating a menu item; they appear alongside the menu item they’re a
 * shortcut for. For example “Ctrl+Q” might appear alongside the “Quit”
 * menu item. Mnemonics are shortcuts for GUI elements such as text
 * entries or buttons; they appear as underlined characters. See
 * gtk_label_new_with_mnemonic(). Menu items can have both accelerators
 * and mnemonics, of course.
 *
 */
@interface OGTKAccelGroup : OGObject
{

}

/**
 * Functions
 */

/**
 * Finds the #GtkAccelGroup to which @closure is connected;
 * see gtk_accel_group_connect().
 *
 * @param closure a #GClosure
 * @return the #GtkAccelGroup to which @closure
 *     is connected, or %NULL
 */
+ (OGTKAccelGroup*)fromAccelClosure:(GClosure*)closure;

/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkAccelGroup*)ACCELGROUP;

/**
 * Finds the first accelerator in @accel_group that matches
 * @accel_key and @accel_mods, and activates it.
 *
 * @param accelQuark the quark for the accelerator name
 * @param acceleratable the #GObject, usually a #GtkWindow, on which
 *    to activate the accelerator
 * @param accelKey accelerator keyval from a key event
 * @param accelMods keyboard state mask from a key event
 * @return %TRUE if an accelerator was activated and handled
 *     this keypress
 */
- (bool)activateWithAccelQuark:(GQuark)accelQuark acceleratable:(GObject*)acceleratable accelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods;

/**
 * Installs an accelerator in this group. When @accel_group is being
 * activated in response to a call to gtk_accel_groups_activate(),
 * @closure will be invoked if the @accel_key and @accel_mods from
 * gtk_accel_groups_activate() match those of this connection.
 * 
 * The signature used for the @closure is that of #GtkAccelGroupActivate.
 * 
 * Note that, due to implementation details, a single closure can
 * only be connected to one accelerator group.
 *
 * @param accelKey key value of the accelerator
 * @param accelMods modifier combination of the accelerator
 * @param accelFlags a flag mask to configure this accelerator
 * @param closure closure to be executed upon accelerator activation
 */
- (void)connectWithAccelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods accelFlags:(GtkAccelFlags)accelFlags closure:(GClosure*)closure;

/**
 * Installs an accelerator in this group, using an accelerator path
 * to look up the appropriate key and modifiers (see
 * gtk_accel_map_add_entry()). When @accel_group is being activated
 * in response to a call to gtk_accel_groups_activate(), @closure will
 * be invoked if the @accel_key and @accel_mods from
 * gtk_accel_groups_activate() match the key and modifiers for the path.
 * 
 * The signature used for the @closure is that of #GtkAccelGroupActivate.
 * 
 * Note that @accel_path string will be stored in a #GQuark. Therefore,
 * if you pass a static string, you can save some memory by interning it
 * first with g_intern_static_string().
 *
 * @param accelPath path used for determining key and modifiers
 * @param closure closure to be executed upon accelerator activation
 */
- (void)connectByPathWithAccelPath:(OFString*)accelPath closure:(GClosure*)closure;

/**
 * Removes an accelerator previously installed through
 * gtk_accel_group_connect().
 * 
 * Since 2.20 @closure can be %NULL.
 *
 * @param closure the closure to remove from this accelerator
 *     group, or %NULL to remove all closures
 * @return %TRUE if the closure was found and got disconnected
 */
- (bool)disconnect:(GClosure*)closure;

/**
 * Removes an accelerator previously installed through
 * gtk_accel_group_connect().
 *
 * @param accelKey key value of the accelerator
 * @param accelMods modifier combination of the accelerator
 * @return %TRUE if there was an accelerator which could be
 *     removed, %FALSE otherwise
 */
- (bool)disconnectKeyWithAccelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods;

/**
 * Finds the first entry in an accelerator group for which
 * @find_func returns %TRUE and returns its #GtkAccelKey.
 *
 * @param findFunc a function to filter the entries
 *    of @accel_group with
 * @param data data to pass to @find_func
 * @return the key of the first entry passing
 *    @find_func. The key is owned by GTK+ and must not be freed.
 */
- (GtkAccelKey*)findWithFindFunc:(GtkAccelGroupFindFunc)findFunc data:(gpointer)data;

/**
 * Locks are added and removed using gtk_accel_group_lock() and
 * gtk_accel_group_unlock().
 *
 * @return %TRUE if there are 1 or more locks on the @accel_group,
 *     %FALSE otherwise.
 */
- (bool)isLocked;

/**
 * Gets a #GdkModifierType representing the mask for this
 * @accel_group. For example, #GDK_CONTROL_MASK, #GDK_SHIFT_MASK, etc.
 *
 * @return the modifier mask for this accel group.
 */
- (GdkModifierType)modifierMask;

/**
 * Locks the given accelerator group.
 * 
 * Locking an acelerator group prevents the accelerators contained
 * within it to be changed during runtime. Refer to
 * gtk_accel_map_change_entry() about runtime accelerator changes.
 * 
 * If called more than once, @accel_group remains locked until
 * gtk_accel_group_unlock() has been called an equivalent number
 * of times.
 *
 */
- (void)lock;

/**
 * Queries an accelerator group for all entries matching @accel_key
 * and @accel_mods.
 *
 * @param accelKey key value of the accelerator
 * @param accelMods modifier combination of the accelerator
 * @param nentries location to return the number
 *     of entries found, or %NULL
 * @return an array of
 *     @n_entries #GtkAccelGroupEntry elements, or %NULL. The array
 *     is owned by GTK+ and must not be freed.
 */
- (GtkAccelGroupEntry*)queryWithAccelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods nentries:(guint*)nentries;

/**
 * Undoes the last call to gtk_accel_group_lock() on this @accel_group.
 *
 */
- (void)unlock;

@end