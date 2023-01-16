/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

@class OGGdkWindow;
@class OGGdkScreen;
@class OGGdkPixbuf;
@class OGTKIconInfo;

/**
 * #GtkIconTheme provides a facility for looking up icons by name
 * and size. The main reason for using a name rather than simply
 * providing a filename is to allow different icons to be used
 * depending on what “icon theme” is selected
 * by the user. The operation of icon themes on Linux and Unix
 * follows the [Icon Theme Specification](http://www.freedesktop.org/Standards/icon-theme-spec)
 * There is a fallback icon theme, named `hicolor`, where applications
 * should install their icons, but additional icon themes can be installed
 * as operating system vendors and users choose.
 * 
 * Named icons are similar to the deprecated [Stock Items][gtkstock],
 * and the distinction between the two may be a bit confusing.
 * A few things to keep in mind:
 * 
 * - Stock images usually are used in conjunction with
 *   [Stock Items][gtkstock], such as %GTK_STOCK_OK or
 *   %GTK_STOCK_OPEN. Named icons are easier to set up and therefore
 *   are more useful for new icons that an application wants to
 *   add, such as application icons or window icons.
 * 
 * - Stock images can only be loaded at the symbolic sizes defined
 *   by the #GtkIconSize enumeration, or by custom sizes defined
 *   by gtk_icon_size_register(), while named icons are more flexible
 *   and any pixel size can be specified.
 * 
 * - Because stock images are closely tied to stock items, and thus
 *   to actions in the user interface, stock images may come in
 *   multiple variants for different widget states or writing
 *   directions.
 * 
 * A good rule of thumb is that if there is a stock image for what
 * you want to use, use it, otherwise use a named icon. It turns
 * out that internally stock images are generally defined in
 * terms of one or more named icons. (An example of the
 * more than one case is icons that depend on writing direction;
 * %GTK_STOCK_GO_FORWARD uses the two themed icons
 * “gtk-stock-go-forward-ltr” and “gtk-stock-go-forward-rtl”.)
 * 
 * In many cases, named themes are used indirectly, via #GtkImage
 * or stock items, rather than directly, but looking up icons
 * directly is also simple. The #GtkIconTheme object acts
 * as a database of all the icons in the current theme. You
 * can create new #GtkIconTheme objects, but it’s much more
 * efficient to use the standard icon theme for the #GdkScreen
 * so that the icon information is shared with other people
 * looking up icons.
 * |[<!-- language="C" -->
 * GError *error = NULL;
 * GtkIconTheme *icon_theme;
 * GdkPixbuf *pixbuf;
 * 
 * icon_theme = gtk_icon_theme_get_default ();
 * pixbuf = gtk_icon_theme_load_icon (icon_theme,
 *                                    "my-icon-name", // icon name
 *                                    48, // icon size
 *                                    0,  // flags
 *                                    &error);
 * if (!pixbuf)
 *   {
 *     g_warning ("Couldn’t load icon: %s", error->message);
 *     g_error_free (error);
 *   }
 * else
 *   {
 *     // Use the pixbuf
 *     g_object_unref (pixbuf);
 *   }
 * ]|
 *
 */
@interface OGTKIconTheme : OGObject
{

}

/**
 * Functions
 */
+ (void)addBuiltinIconWithIconName:(OFString*)iconName size:(gint)size pixbuf:(OGGdkPixbuf*)pixbuf;
+ (OGTKIconTheme*)default;
+ (OGTKIconTheme*)forScreen:(OGGdkScreen*)screen;

/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkIconTheme*)ICONTHEME;

/**
 * Adds a resource path that will be looked at when looking
 * for icons, similar to search paths.
 * 
 * This function should be used to make application-specific icons
 * available as part of the icon theme.
 * 
 * The resources are considered as part of the hicolor icon theme
 * and must be located in subdirectories that are defined in the
 * hicolor icon theme, such as `@path/16x16/actions/run.png`.
 * Icons that are directly placed in the resource path instead
 * of a subdirectory are also considered as ultimate fallback.
 *
 * @param path a resource path
 */
- (void)addResourcePath:(OFString*)path;

/**
 * Appends a directory to the search path.
 * See gtk_icon_theme_set_search_path().
 *
 * @param path directory name to append to the icon path
 */
- (void)appendSearchPath:(OFString*)path;

/**
 * Looks up a named icon and returns a #GtkIconInfo containing
 * information such as the filename of the icon. The icon
 * can then be rendered into a pixbuf using
 * gtk_icon_info_load_icon(). (gtk_icon_theme_load_icon()
 * combines these two steps if all you need is the pixbuf.)
 * 
 * If @icon_names contains more than one name, this function
 * tries them all in the given order before falling back to
 * inherited icon themes.
 *
 * @param iconNames %NULL-terminated array of
 *     icon names to lookup
 * @param size desired icon size
 * @param flags flags modifying the behavior of the icon lookup
 * @return a #GtkIconInfo object
 * containing information about the icon, or %NULL if the icon wasn’t
 * found.
 */
- (OGTKIconInfo*)chooseIconWithIconNames:(const gchar**)iconNames size:(gint)size flags:(GtkIconLookupFlags)flags;

/**
 * Looks up a named icon for a particular window scale and returns
 * a #GtkIconInfo containing information such as the filename of the
 * icon. The icon can then be rendered into a pixbuf using
 * gtk_icon_info_load_icon(). (gtk_icon_theme_load_icon()
 * combines these two steps if all you need is the pixbuf.)
 * 
 * If @icon_names contains more than one name, this function
 * tries them all in the given order before falling back to
 * inherited icon themes.
 *
 * @param iconNames %NULL-terminated
 *     array of icon names to lookup
 * @param size desired icon size
 * @param scale desired scale
 * @param flags flags modifying the behavior of the icon lookup
 * @return a #GtkIconInfo object
 *     containing information about the icon, or %NULL if the
 *     icon wasn’t found.
 */
- (OGTKIconInfo*)chooseIconForScaleWithIconNames:(const gchar**)iconNames size:(gint)size scale:(gint)scale flags:(GtkIconLookupFlags)flags;

/**
 * Gets the name of an icon that is representative of the
 * current theme (for instance, to use when presenting
 * a list of themes to the user.)
 *
 * @return the name of an example icon or %NULL.
 *     Free with g_free().
 */
- (char*)exampleIconName;

/**
 * Returns an array of integers describing the sizes at which
 * the icon is available without scaling. A size of -1 means
 * that the icon is available in a scalable format. The array
 * is zero-terminated.
 *
 * @param iconName the name of an icon
 * @return An newly
 * allocated array describing the sizes at which the icon is
 * available. The array should be freed with g_free() when it is no
 * longer needed.
 */
- (gint*)iconSizes:(OFString*)iconName;

/**
 * Gets the current search path. See gtk_icon_theme_set_search_path().
 *
 * @param path location to store a list of icon theme path directories or %NULL.
 *     The stored value should be freed with g_strfreev().
 * @param nelements location to store number of elements in @path, or %NULL
 */
- (void)searchPathWithPath:(gchar***)path nelements:(gint*)nelements;

/**
 * Checks whether an icon theme includes an icon
 * for a particular name.
 *
 * @param iconName the name of an icon
 * @return %TRUE if @icon_theme includes an
 *  icon for @icon_name.
 */
- (bool)hasIcon:(OFString*)iconName;

/**
 * Gets the list of contexts available within the current
 * hierarchy of icon themes.
 * See gtk_icon_theme_list_icons() for details about contexts.
 *
 * @return a #GList list
 *     holding the names of all the contexts in the theme. You must first
 *     free each element in the list with g_free(), then free the list
 *     itself with g_list_free().
 */
- (GList*)listContexts;

/**
 * Lists the icons in the current icon theme. Only a subset
 * of the icons can be listed by providing a context string.
 * The set of values for the context string is system dependent,
 * but will typically include such values as “Applications” and
 * “MimeTypes”. Contexts are explained in the
 * [Icon Theme Specification](http://www.freedesktop.org/wiki/Specifications/icon-theme-spec).
 * The standard contexts are listed in the
 * [Icon Naming Specification](http://www.freedesktop.org/wiki/Specifications/icon-naming-spec).
 * Also see gtk_icon_theme_list_contexts().
 *
 * @param context a string identifying a particular type of
 *           icon, or %NULL to list all icons.
 * @return a #GList list
 *     holding the names of all the icons in the theme. You must
 *     first free each element in the list with g_free(), then
 *     free the list itself with g_list_free().
 */
- (GList*)listIcons:(OFString*)context;

/**
 * Looks up an icon in an icon theme, scales it to the given size
 * and renders it into a pixbuf. This is a convenience function;
 * if more details about the icon are needed, use
 * gtk_icon_theme_lookup_icon() followed by gtk_icon_info_load_icon().
 * 
 * Note that you probably want to listen for icon theme changes and
 * update the icon. This is usually done by connecting to the
 * GtkWidget::style-set signal. If for some reason you do not want to
 * update the icon when the icon theme changes, you should consider
 * using gdk_pixbuf_copy() to make a private copy of the pixbuf
 * returned by this function. Otherwise GTK+ may need to keep the old
 * icon theme loaded, which would be a waste of memory.
 *
 * @param iconName the name of the icon to lookup
 * @param size the desired icon size. The resulting icon may not be
 *     exactly this size; see gtk_icon_info_load_icon().
 * @param flags flags modifying the behavior of the icon lookup
 * @param err
 * @return the rendered icon; this may be
 *     a newly created icon or a new reference to an internal icon, so
 *     you must not modify the icon. Use g_object_unref() to release
 *     your reference to the icon. %NULL if the icon isn’t found.
 */
- (OGGdkPixbuf*)loadIconWithIconName:(OFString*)iconName size:(gint)size flags:(GtkIconLookupFlags)flags err:(GError**)err;

/**
 * Looks up an icon in an icon theme for a particular window scale,
 * scales it to the given size and renders it into a pixbuf. This is a
 * convenience function; if more details about the icon are needed,
 * use gtk_icon_theme_lookup_icon() followed by
 * gtk_icon_info_load_icon().
 * 
 * Note that you probably want to listen for icon theme changes and
 * update the icon. This is usually done by connecting to the
 * GtkWidget::style-set signal. If for some reason you do not want to
 * update the icon when the icon theme changes, you should consider
 * using gdk_pixbuf_copy() to make a private copy of the pixbuf
 * returned by this function. Otherwise GTK+ may need to keep the old
 * icon theme loaded, which would be a waste of memory.
 *
 * @param iconName the name of the icon to lookup
 * @param size the desired icon size. The resulting icon may not be
 *     exactly this size; see gtk_icon_info_load_icon().
 * @param scale desired scale
 * @param flags flags modifying the behavior of the icon lookup
 * @param err
 * @return the rendered icon; this may be
 *     a newly created icon or a new reference to an internal icon, so
 *     you must not modify the icon. Use g_object_unref() to release
 *     your reference to the icon. %NULL if the icon isn’t found.
 */
- (OGGdkPixbuf*)loadIconForScaleWithIconName:(OFString*)iconName size:(gint)size scale:(gint)scale flags:(GtkIconLookupFlags)flags err:(GError**)err;

/**
 * Looks up an icon in an icon theme for a particular window scale,
 * scales it to the given size and renders it into a cairo surface. This is a
 * convenience function; if more details about the icon are needed,
 * use gtk_icon_theme_lookup_icon() followed by
 * gtk_icon_info_load_surface().
 * 
 * Note that you probably want to listen for icon theme changes and
 * update the icon. This is usually done by connecting to the
 * GtkWidget::style-set signal.
 *
 * @param iconName the name of the icon to lookup
 * @param size the desired icon size. The resulting icon may not be
 *     exactly this size; see gtk_icon_info_load_icon().
 * @param scale desired scale
 * @param forWindow #GdkWindow to optimize drawing for, or %NULL
 * @param flags flags modifying the behavior of the icon lookup
 * @param err
 * @return the rendered icon; this may be
 *     a newly created icon or a new reference to an internal icon, so
 *     you must not modify the icon. Use cairo_surface_destroy() to
 *     release your reference to the icon. %NULL if the icon isn’t
 *     found.
 */
- (cairo_surface_t*)loadSurfaceWithIconName:(OFString*)iconName size:(gint)size scale:(gint)scale forWindow:(OGGdkWindow*)forWindow flags:(GtkIconLookupFlags)flags err:(GError**)err;

/**
 * Looks up an icon and returns a #GtkIconInfo containing information
 * such as the filename of the icon. The icon can then be rendered
 * into a pixbuf using gtk_icon_info_load_icon().
 * 
 * When rendering on displays with high pixel densities you should not
 * use a @size multiplied by the scaling factor returned by functions
 * like gdk_window_get_scale_factor(). Instead, you should use
 * gtk_icon_theme_lookup_by_gicon_for_scale(), as the assets loaded
 * for a given scaling factor may be different.
 *
 * @param icon the #GIcon to look up
 * @param size desired icon size
 * @param flags flags modifying the behavior of the icon lookup
 * @return a #GtkIconInfo containing
 *     information about the icon, or %NULL if the icon wasn’t
 *     found. Unref with g_object_unref()
 */
- (OGTKIconInfo*)lookupByGiconWithIcon:(GIcon*)icon size:(gint)size flags:(GtkIconLookupFlags)flags;

/**
 * Looks up an icon and returns a #GtkIconInfo containing information
 * such as the filename of the icon. The icon can then be rendered into
 * a pixbuf using gtk_icon_info_load_icon().
 *
 * @param icon the #GIcon to look up
 * @param size desired icon size
 * @param scale the desired scale
 * @param flags flags modifying the behavior of the icon lookup
 * @return a #GtkIconInfo containing
 *     information about the icon, or %NULL if the icon wasn’t
 *     found. Unref with g_object_unref()
 */
- (OGTKIconInfo*)lookupByGiconForScaleWithIcon:(GIcon*)icon size:(gint)size scale:(gint)scale flags:(GtkIconLookupFlags)flags;

/**
 * Looks up a named icon and returns a #GtkIconInfo containing
 * information such as the filename of the icon. The icon
 * can then be rendered into a pixbuf using
 * gtk_icon_info_load_icon(). (gtk_icon_theme_load_icon()
 * combines these two steps if all you need is the pixbuf.)
 * 
 * When rendering on displays with high pixel densities you should not
 * use a @size multiplied by the scaling factor returned by functions
 * like gdk_window_get_scale_factor(). Instead, you should use
 * gtk_icon_theme_lookup_icon_for_scale(), as the assets loaded
 * for a given scaling factor may be different.
 *
 * @param iconName the name of the icon to lookup
 * @param size desired icon size
 * @param flags flags modifying the behavior of the icon lookup
 * @return a #GtkIconInfo object
 *     containing information about the icon, or %NULL if the
 *     icon wasn’t found.
 */
- (OGTKIconInfo*)lookupIconWithIconName:(OFString*)iconName size:(gint)size flags:(GtkIconLookupFlags)flags;

/**
 * Looks up a named icon for a particular window scale and returns a
 * #GtkIconInfo containing information such as the filename of the
 * icon. The icon can then be rendered into a pixbuf using
 * gtk_icon_info_load_icon(). (gtk_icon_theme_load_icon() combines
 * these two steps if all you need is the pixbuf.)
 *
 * @param iconName the name of the icon to lookup
 * @param size desired icon size
 * @param scale the desired scale
 * @param flags flags modifying the behavior of the icon lookup
 * @return a #GtkIconInfo object
 *     containing information about the icon, or %NULL if the
 *     icon wasn’t found.
 */
- (OGTKIconInfo*)lookupIconForScaleWithIconName:(OFString*)iconName size:(gint)size scale:(gint)scale flags:(GtkIconLookupFlags)flags;

/**
 * Prepends a directory to the search path.
 * See gtk_icon_theme_set_search_path().
 *
 * @param path directory name to prepend to the icon path
 */
- (void)prependSearchPath:(OFString*)path;

/**
 * Checks to see if the icon theme has changed; if it has, any
 * currently cached information is discarded and will be reloaded
 * next time @icon_theme is accessed.
 *
 * @return %TRUE if the icon theme has changed and needed
 *     to be reloaded.
 */
- (bool)rescanIfNeeded;

/**
 * Sets the name of the icon theme that the #GtkIconTheme object uses
 * overriding system configuration. This function cannot be called
 * on the icon theme objects returned from gtk_icon_theme_get_default()
 * and gtk_icon_theme_get_for_screen().
 *
 * @param themeName name of icon theme to use instead of
 *   configured theme, or %NULL to unset a previously set custom theme
 */
- (void)setCustomTheme:(OFString*)themeName;

/**
 * Sets the screen for an icon theme; the screen is used
 * to track the user’s currently configured icon theme,
 * which might be different for different screens.
 *
 * @param screen a #GdkScreen
 */
- (void)setScreen:(OGGdkScreen*)screen;

/**
 * Sets the search path for the icon theme object. When looking
 * for an icon theme, GTK+ will search for a subdirectory of
 * one or more of the directories in @path with the same name
 * as the icon theme containing an index.theme file. (Themes from
 * multiple of the path elements are combined to allow themes to be
 * extended by adding icons in the user’s home directory.)
 * 
 * In addition if an icon found isn’t found either in the current
 * icon theme or the default icon theme, and an image file with
 * the right name is found directly in one of the elements of
 * @path, then that image will be used for the icon name.
 * (This is legacy feature, and new icons should be put
 * into the fallback icon theme, which is called hicolor,
 * rather than directly on the icon path.)
 *
 * @param path array of
 *     directories that are searched for icon themes
 * @param nelements number of elements in @path.
 */
- (void)setSearchPathWithPath:(const gchar**)path nelements:(gint)nelements;

@end