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
 * Accelerator maps are used to define runtime configurable accelerators.
 * Functions for manipulating them are are usually used by higher level
 * convenience mechanisms like #GtkUIManager and are thus considered
 * “low-level”. You’ll want to use them if you’re manually creating menus that
 * should have user-configurable accelerators.
 * 
 * An accelerator is uniquely defined by:
 * - accelerator path
 * - accelerator key
 * - accelerator modifiers
 * 
 * The accelerator path must consist of
 * “<WINDOWTYPE>/Category1/Category2/.../Action”, where WINDOWTYPE
 * should be a unique application-specific identifier that corresponds
 * to the kind of window the accelerator is being used in, e.g.
 * “Gimp-Image”, “Abiword-Document” or “Gnumeric-Settings”.
 * The “Category1/.../Action” portion is most appropriately chosen by
 * the action the accelerator triggers, i.e. for accelerators on menu
 * items, choose the item’s menu path, e.g. “File/Save As”,
 * “Image/View/Zoom” or “Edit/Select All”. So a full valid accelerator
 * path may look like: “<Gimp-Toolbox>/File/Dialogs/Tool Options...”.
 * 
 * All accelerators are stored inside one global #GtkAccelMap that can
 * be obtained using gtk_accel_map_get(). See
 * [Monitoring changes][monitoring-changes] for additional
 * details.
 * 
 * # Manipulating accelerators
 * 
 * New accelerators can be added using gtk_accel_map_add_entry().
 * To search for specific accelerator, use gtk_accel_map_lookup_entry().
 * Modifications of existing accelerators should be done using
 * gtk_accel_map_change_entry().
 * 
 * In order to avoid having some accelerators changed, they can be
 * locked using gtk_accel_map_lock_path(). Unlocking is done using
 * gtk_accel_map_unlock_path().
 * 
 * # Saving and loading accelerator maps
 * 
 * Accelerator maps can be saved to and loaded from some external
 * resource. For simple saving and loading from file,
 * gtk_accel_map_save() and gtk_accel_map_load() are provided.
 * Saving and loading can also be done by providing file descriptor
 * to gtk_accel_map_save_fd() and gtk_accel_map_load_fd().
 * 
 * # Monitoring changes
 * 
 * #GtkAccelMap object is only useful for monitoring changes of
 * accelerators. By connecting to #GtkAccelMap::changed signal, one
 * can monitor changes of all accelerators. It is also possible to
 * monitor only single accelerator path by using it as a detail of
 * the #GtkAccelMap::changed signal.
 *
 */
@interface OGTKAccelMap : OGObject
{

}

/**
 * Functions
 */

/**
 * Registers a new accelerator with the global accelerator map.
 * This function should only be called once per @accel_path
 * with the canonical @accel_key and @accel_mods for this path.
 * To change the accelerator during runtime programatically, use
 * gtk_accel_map_change_entry().
 * 
 * Set @accel_key and @accel_mods to 0 to request a removal of
 * the accelerator.
 * 
 * Note that @accel_path string will be stored in a #GQuark. Therefore, if you
 * pass a static string, you can save some memory by interning it first with
 * g_intern_static_string().
 *
 * @param accelPath valid accelerator path
 * @param accelKey the accelerator key
 * @param accelMods the accelerator modifiers
 */
+ (void)addEntryWithAccelPath:(OFString*)accelPath accelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods;

/**
 * Adds a filter to the global list of accel path filters.
 * 
 * Accel map entries whose accel path matches one of the filters
 * are skipped by gtk_accel_map_foreach().
 * 
 * This function is intended for GTK+ modules that create their own
 * menus, but don’t want them to be saved into the applications accelerator
 * map dump.
 *
 * @param filterPattern a pattern (see #GPatternSpec)
 */
+ (void)addFilter:(OFString*)filterPattern;

/**
 * Changes the @accel_key and @accel_mods currently associated with @accel_path.
 * Due to conflicts with other accelerators, a change may not always be possible,
 * @replace indicates whether other accelerators may be deleted to resolve such
 * conflicts. A change will only occur if all conflicts could be resolved (which
 * might not be the case if conflicting accelerators are locked). Successful
 * changes are indicated by a %TRUE return value.
 * 
 * Note that @accel_path string will be stored in a #GQuark. Therefore, if you
 * pass a static string, you can save some memory by interning it first with
 * g_intern_static_string().
 *
 * @param accelPath a valid accelerator path
 * @param accelKey the new accelerator key
 * @param accelMods the new accelerator modifiers
 * @param replace %TRUE if other accelerators may be deleted upon conflicts
 * @return %TRUE if the accelerator could be changed, %FALSE otherwise
 */
+ (bool)changeEntryWithAccelPath:(OFString*)accelPath accelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods replace:(bool)replace;

/**
 * Loops over the entries in the accelerator map whose accel path
 * doesn’t match any of the filters added with gtk_accel_map_add_filter(),
 * and execute @foreach_func on each. The signature of @foreach_func is
 * that of #GtkAccelMapForeach, the @changed parameter indicates whether
 * this accelerator was changed during runtime (thus, would need
 * saving during an accelerator map dump).
 *
 * @param data data to be passed into @foreach_func
 * @param foreachFunc function to be executed for each accel
 *                map entry which is not filtered out
 */
+ (void)foreachWithData:(gpointer)data foreachFunc:(GtkAccelMapForeach)foreachFunc;

/**
 * Loops over all entries in the accelerator map, and execute
 * @foreach_func on each. The signature of @foreach_func is that of
 * #GtkAccelMapForeach, the @changed parameter indicates whether
 * this accelerator was changed during runtime (thus, would need
 * saving during an accelerator map dump).
 *
 * @param data data to be passed into @foreach_func
 * @param foreachFunc function to be executed for each accel
 *                map entry
 */
+ (void)foreachUnfilteredWithData:(gpointer)data foreachFunc:(GtkAccelMapForeach)foreachFunc;

/**
 * Gets the singleton global #GtkAccelMap object. This object
 * is useful only for notification of changes to the accelerator
 * map via the ::changed signal; it isn’t a parameter to the
 * other accelerator map functions.
 *
 * @return the global #GtkAccelMap object
 */
+ (OGTKAccelMap*)instance;

/**
 * Parses a file previously saved with gtk_accel_map_save() for
 * accelerator specifications, and propagates them accordingly.
 *
 * @param fileName a file containing accelerator specifications,
 *   in the GLib file name encoding
 */
+ (void)load:(OFString*)fileName;

/**
 * Filedescriptor variant of gtk_accel_map_load().
 * 
 * Note that the file descriptor will not be closed by this function.
 *
 * @param fd a valid readable file descriptor
 */
+ (void)loadFd:(gint)fd;

/**
 * #GScanner variant of gtk_accel_map_load().
 *
 * @param scanner a #GScanner which has already been provided with an input file
 */
+ (void)loadScanner:(GScanner*)scanner;

/**
 * Locks the given accelerator path. If the accelerator map doesn’t yet contain
 * an entry for @accel_path, a new one is created.
 * 
 * Locking an accelerator path prevents its accelerator from being changed
 * during runtime. A locked accelerator path can be unlocked by
 * gtk_accel_map_unlock_path(). Refer to gtk_accel_map_change_entry()
 * for information about runtime accelerator changes.
 * 
 * If called more than once, @accel_path remains locked until
 * gtk_accel_map_unlock_path() has been called an equivalent number
 * of times.
 * 
 * Note that locking of individual accelerator paths is independent from
 * locking the #GtkAccelGroup containing them. For runtime accelerator
 * changes to be possible, both the accelerator path and its #GtkAccelGroup
 * have to be unlocked.
 *
 * @param accelPath a valid accelerator path
 */
+ (void)lockPath:(OFString*)accelPath;

/**
 * Looks up the accelerator entry for @accel_path and fills in @key.
 *
 * @param accelPath a valid accelerator path
 * @param key the accelerator key to be filled in (optional)
 * @return %TRUE if @accel_path is known, %FALSE otherwise
 */
+ (bool)lookupEntryWithAccelPath:(OFString*)accelPath key:(GtkAccelKey*)key;

/**
 * Saves current accelerator specifications (accelerator path, key
 * and modifiers) to @file_name.
 * The file is written in a format suitable to be read back in by
 * gtk_accel_map_load().
 *
 * @param fileName the name of the file to contain
 *   accelerator specifications, in the GLib file name encoding
 */
+ (void)save:(OFString*)fileName;

/**
 * Filedescriptor variant of gtk_accel_map_save().
 * 
 * Note that the file descriptor will not be closed by this function.
 *
 * @param fd a valid writable file descriptor
 */
+ (void)saveFd:(gint)fd;

/**
 * Undoes the last call to gtk_accel_map_lock_path() on this @accel_path.
 * Refer to gtk_accel_map_lock_path() for information about accelerator path locking.
 *
 * @param accelPath a valid accelerator path
 */
+ (void)unlockPath:(OFString*)accelPath;

/**
 * Methods
 */

- (GtkAccelMap*)ACCELMAP;

@end