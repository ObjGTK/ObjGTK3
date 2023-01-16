/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkDisplay;

/**
 * A #GdkKeymap defines the translation from keyboard state
 * (including a hardware key, a modifier mask, and active keyboard group)
 * to a keyval. This translation has two phases. The first phase is
 * to determine the effective keyboard group and level for the keyboard
 * state; the second phase is to look up the keycode/group/level triplet
 * in the keymap and see what keyval it corresponds to.
 *
 */
@interface OGGdkKeymap : OGObject
{

}

/**
 * Functions
 */

/**
 * Use gdk_keymap_get_for_display() instead
 *
 * @return the #GdkKeymap attached to the default display.
 */
+ (OGGdkKeymap*)default;

/**
 * Returns the #GdkKeymap attached to @display.
 *
 * @param display the #GdkDisplay.
 * @return the #GdkKeymap attached to @display.
 */
+ (OGGdkKeymap*)forDisplay:(OGGdkDisplay*)display;

/**
 * Methods
 */

- (GdkKeymap*)KEYMAP;

/**
 * Maps the non-virtual modifiers (i.e Mod2, Mod3, ...) which are set
 * in @state to the virtual modifiers (i.e. Super, Hyper and Meta) and
 * set the corresponding bits in @state.
 * 
 * GDK already does this before delivering key events, but for
 * compatibility reasons, it only sets the first virtual modifier
 * it finds, whereas this function sets all matching virtual modifiers.
 * 
 * This function is useful when matching key events against
 * accelerators.
 *
 * @param state pointer to the modifier mask to change
 */
- (void)addVirtualModifiers:(GdkModifierType*)state;

/**
 * Returns whether the Caps Lock modifer is locked.
 *
 * @return %TRUE if Caps Lock is on
 */
- (bool)capsLockState;

/**
 * Returns the direction of effective layout of the keymap.
 *
 * @return %PANGO_DIRECTION_LTR or %PANGO_DIRECTION_RTL
 *   if it can determine the direction. %PANGO_DIRECTION_NEUTRAL
 *   otherwise.
 */
- (PangoDirection)direction;

/**
 * Returns the keyvals bound to @hardware_keycode.
 * The Nth #GdkKeymapKey in @keys is bound to the Nth
 * keyval in @keyvals. Free the returned arrays with g_free().
 * When a keycode is pressed by the user, the keyval from
 * this list of entries is selected by considering the effective
 * keyboard group and level. See gdk_keymap_translate_keyboard_state().
 *
 * @param hardwareKeycode a keycode
 * @param keys return
 *     location for array of #GdkKeymapKey, or %NULL
 * @param keyvals return
 *     location for array of keyvals, or %NULL
 * @param nentries length of @keys and @keyvals
 * @return %TRUE if there were any entries
 */
- (bool)entriesForKeycodeWithHardwareKeycode:(guint)hardwareKeycode keys:(GdkKeymapKey**)keys keyvals:(guint**)keyvals nentries:(gint*)nentries;

/**
 * Obtains a list of keycode/group/level combinations that will
 * generate @keyval. Groups and levels are two kinds of keyboard mode;
 * in general, the level determines whether the top or bottom symbol
 * on a key is used, and the group determines whether the left or
 * right symbol is used. On US keyboards, the shift key changes the
 * keyboard level, and there are no groups. A group switch key might
 * convert a keyboard between Hebrew to English modes, for example.
 * #GdkEventKey contains a %group field that indicates the active
 * keyboard group. The level is computed from the modifier mask.
 * The returned array should be freed
 * with g_free().
 *
 * @param keyval a keyval, such as %GDK_KEY_a, %GDK_KEY_Up, %GDK_KEY_Return, etc.
 * @param keys return location
 *     for an array of #GdkKeymapKey
 * @param nkeys return location for number of elements in returned array
 * @return %TRUE if keys were found and returned
 */
- (bool)entriesForKeyvalWithKeyval:(guint)keyval keys:(GdkKeymapKey**)keys nkeys:(gint*)nkeys;

/**
 * Returns the modifier mask the @keymap’s windowing system backend
 * uses for a particular purpose.
 * 
 * Note that this function always returns real hardware modifiers, not
 * virtual ones (e.g. it will return #GDK_MOD1_MASK rather than
 * #GDK_META_MASK if the backend maps MOD1 to META), so there are use
 * cases where the return value of this function has to be transformed
 * by gdk_keymap_add_virtual_modifiers() in order to contain the
 * expected result.
 *
 * @param intent the use case for the modifier mask
 * @return the modifier mask used for @intent.
 */
- (GdkModifierType)modifierMask:(GdkModifierIntent)intent;

/**
 * Returns the current modifier state.
 *
 * @return the current modifier state.
 */
- (guint)modifierState;

/**
 * Returns whether the Num Lock modifer is locked.
 *
 * @return %TRUE if Num Lock is on
 */
- (bool)numLockState;

/**
 * Returns whether the Scroll Lock modifer is locked.
 *
 * @return %TRUE if Scroll Lock is on
 */
- (bool)scrollLockState;

/**
 * Determines if keyboard layouts for both right-to-left and left-to-right
 * languages are in use.
 *
 * @return %TRUE if there are layouts in both directions, %FALSE otherwise
 */
- (bool)haveBidiLayouts;

/**
 * Looks up the keyval mapped to a keycode/group/level triplet.
 * If no keyval is bound to @key, returns 0. For normal user input,
 * you want to use gdk_keymap_translate_keyboard_state() instead of
 * this function, since the effective group/level may not be
 * the same as the current keyboard state.
 *
 * @param key a #GdkKeymapKey with keycode, group, and level initialized
 * @return a keyval, or 0 if none was mapped to the given @key
 */
- (guint)lookupKey:(const GdkKeymapKey*)key;

/**
 * Maps the virtual modifiers (i.e. Super, Hyper and Meta) which
 * are set in @state to their non-virtual counterparts (i.e. Mod2,
 * Mod3,...) and set the corresponding bits in @state.
 * 
 * This function is useful when matching key events against
 * accelerators.
 *
 * @param state pointer to the modifier state to map
 * @return %FALSE if two virtual modifiers were mapped to the
 *     same non-virtual modifier. Note that %FALSE is also returned
 *     if a virtual modifier is mapped to a non-virtual modifier that
 *     was already set in @state.
 */
- (bool)mapVirtualModifiers:(GdkModifierType*)state;

/**
 * Translates the contents of a #GdkEventKey into a keyval, effective
 * group, and level. Modifiers that affected the translation and
 * are thus unavailable for application use are returned in
 * @consumed_modifiers.
 * See [Groups][key-group-explanation] for an explanation of
 * groups and levels. The @effective_group is the group that was
 * actually used for the translation; some keys such as Enter are not
 * affected by the active keyboard group. The @level is derived from
 * @state. For convenience, #GdkEventKey already contains the translated
 * keyval, so this function isn’t as useful as you might think.
 * 
 * @consumed_modifiers gives modifiers that should be masked outfrom @state
 * when comparing this key press to a hot key. For instance, on a US keyboard,
 * the `plus` symbol is shifted, so when comparing a key press to a
 * `<Control>plus` accelerator `<Shift>` should be masked out.
 * 
 * |[<!-- language="C" -->
 * // We want to ignore irrelevant modifiers like ScrollLock
 * #define ALL_ACCELS_MASK (GDK_CONTROL_MASK | GDK_SHIFT_MASK | GDK_MOD1_MASK)
 * gdk_keymap_translate_keyboard_state (keymap, event->hardware_keycode,
 *                                      event->state, event->group,
 *                                      &keyval, NULL, NULL, &consumed);
 * if (keyval == GDK_PLUS &&
 *     (event->state & ~consumed & ALL_ACCELS_MASK) == GDK_CONTROL_MASK)
 *   // Control was pressed
 * ]|
 * 
 * An older interpretation @consumed_modifiers was that it contained
 * all modifiers that might affect the translation of the key;
 * this allowed accelerators to be stored with irrelevant consumed
 * modifiers, by doing:
 * |[<!-- language="C" -->
 * // XXX Don’t do this XXX
 * if (keyval == accel_keyval &&
 *     (event->state & ~consumed & ALL_ACCELS_MASK) == (accel_mods & ~consumed))
 *   // Accelerator was pressed
 * ]|
 * 
 * However, this did not work if multi-modifier combinations were
 * used in the keymap, since, for instance, `<Control>` would be
 * masked out even if only `<Control><Alt>` was used in the keymap.
 * To support this usage as well as well as possible, all single
 * modifier combinations that could affect the key for any combination
 * of modifiers will be returned in @consumed_modifiers; multi-modifier
 * combinations are returned only when actually found in @state. When
 * you store accelerators, you should always store them with consumed
 * modifiers removed. Store `<Control>plus`, not `<Control><Shift>plus`,
 *
 * @param hardwareKeycode a keycode
 * @param state a modifier state
 * @param group active keyboard group
 * @param keyval return location for keyval, or %NULL
 * @param effectiveGroup return location for effective
 *     group, or %NULL
 * @param level return location for level, or %NULL
 * @param consumedModifiers return location for modifiers
 *     that were used to determine the group or level, or %NULL
 * @return %TRUE if there was a keyval bound to the keycode/state/group
 */
- (bool)translateKeyboardStateWithHardwareKeycode:(guint)hardwareKeycode state:(GdkModifierType)state group:(gint)group keyval:(guint*)keyval effectiveGroup:(gint*)effectiveGroup level:(gint*)level consumedModifiers:(GdkModifierType*)consumedModifiers;

@end