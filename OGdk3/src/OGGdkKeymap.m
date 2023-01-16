/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkKeymap.h"

#import "OGGdkDisplay.h"

@implementation OGGdkKeymap

+ (OGGdkKeymap*)default
{
	return [[[OGGdkKeymap alloc] initWithGObject:(GObject*)gdk_keymap_get_default()] autorelease];
}

+ (OGGdkKeymap*)forDisplay:(OGGdkDisplay*)display
{
	return [[[OGGdkKeymap alloc] initWithGObject:(GObject*)gdk_keymap_get_for_display([display DISPLAY])] autorelease];
}

- (GdkKeymap*)KEYMAP
{
	return GDK_KEYMAP([self GOBJECT]);
}

- (void)addVirtualModifiers:(GdkModifierType*)state
{
	gdk_keymap_add_virtual_modifiers([self KEYMAP], state);
}

- (bool)capsLockState
{
	return gdk_keymap_get_caps_lock_state([self KEYMAP]);
}

- (PangoDirection)direction
{
	return gdk_keymap_get_direction([self KEYMAP]);
}

- (bool)entriesForKeycodeWithHardwareKeycode:(guint)hardwareKeycode keys:(GdkKeymapKey**)keys keyvals:(guint**)keyvals nentries:(gint*)nentries
{
	return gdk_keymap_get_entries_for_keycode([self KEYMAP], hardwareKeycode, keys, keyvals, nentries);
}

- (bool)entriesForKeyvalWithKeyval:(guint)keyval keys:(GdkKeymapKey**)keys nkeys:(gint*)nkeys
{
	return gdk_keymap_get_entries_for_keyval([self KEYMAP], keyval, keys, nkeys);
}

- (GdkModifierType)modifierMask:(GdkModifierIntent)intent
{
	return gdk_keymap_get_modifier_mask([self KEYMAP], intent);
}

- (guint)modifierState
{
	return gdk_keymap_get_modifier_state([self KEYMAP]);
}

- (bool)numLockState
{
	return gdk_keymap_get_num_lock_state([self KEYMAP]);
}

- (bool)scrollLockState
{
	return gdk_keymap_get_scroll_lock_state([self KEYMAP]);
}

- (bool)haveBidiLayouts
{
	return gdk_keymap_have_bidi_layouts([self KEYMAP]);
}

- (guint)lookupKey:(const GdkKeymapKey*)key
{
	return gdk_keymap_lookup_key([self KEYMAP], key);
}

- (bool)mapVirtualModifiers:(GdkModifierType*)state
{
	return gdk_keymap_map_virtual_modifiers([self KEYMAP], state);
}

- (bool)translateKeyboardStateWithHardwareKeycode:(guint)hardwareKeycode state:(GdkModifierType)state group:(gint)group keyval:(guint*)keyval effectiveGroup:(gint*)effectiveGroup level:(gint*)level consumedModifiers:(GdkModifierType*)consumedModifiers
{
	return gdk_keymap_translate_keyboard_state([self KEYMAP], hardwareKeycode, state, group, keyval, effectiveGroup, level, consumedModifiers);
}


@end