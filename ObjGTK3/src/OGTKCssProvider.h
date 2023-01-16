/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>
#include <gtk/gtk.h>

#import <OGObject/OGObject.h>

/**
 * GtkCssProvider is an object implementing the #GtkStyleProvider interface.
 * It is able to parse [CSS-like][css-overview] input in order to style widgets.
 * 
 * An application can make GTK+ parse a specific CSS style sheet by calling
 * gtk_css_provider_load_from_file() or gtk_css_provider_load_from_resource()
 * and adding the provider with gtk_style_context_add_provider() or
 * gtk_style_context_add_provider_for_screen().
 * 
 * In addition, certain files will be read when GTK+ is initialized. First, the
 * file `$XDG_CONFIG_HOME/gtk-3.0/gtk.css` is loaded if it exists. Then, GTK+
 * loads the first existing file among
 * `XDG_DATA_HOME/themes/THEME/gtk-VERSION/gtk.css`,
 * `$HOME/.themes/THEME/gtk-VERSION/gtk.css`,
 * `$XDG_DATA_DIRS/themes/THEME/gtk-VERSION/gtk.css` and
 * `DATADIR/share/themes/THEME/gtk-VERSION/gtk.css`, where `THEME` is the name of
 * the current theme (see the #GtkSettings:gtk-theme-name setting), `DATADIR`
 * is the prefix configured when GTK+ was compiled (unless overridden by the
 * `GTK_DATA_PREFIX` environment variable), and `VERSION` is the GTK+ version number.
 * If no file is found for the current version, GTK+ tries older versions all the
 * way back to 3.0.
 * 
 * In the same way, GTK+ tries to load a gtk-keys.css file for the current
 * key theme, as defined by #GtkSettings:gtk-key-theme-name.
 *
 */
@interface OGTKCssProvider : OGObject
{

}

/**
 * Functions
 */

/**
 * Use gtk_css_provider_new() instead.
 *
 * @return The provider used for fallback styling.
 *          This memory is owned by GTK+, and you must not free it.
 */
+ (OGTKCssProvider*)default;

/**
 * Loads a theme from the usual theme paths
 *
 * @param name A theme name
 * @param variant variant to load, for example, "dark", or
 *     %NULL for the default
 * @return a #GtkCssProvider with the theme loaded.
 *     This memory is owned by GTK+, and you must not free it.
 */
+ (OGTKCssProvider*)namedWithName:(OFString*)name variant:(OFString*)variant;

/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkCssProvider*)CSSPROVIDER;

/**
 * Loads @data into @css_provider, and by doing so clears any previously loaded
 * information.
 *
 * @param data CSS data loaded in memory
 * @param length the length of @data in bytes, or -1 for NUL terminated strings. If
 *   @length is not -1, the code will assume it is not NUL terminated and will
 *   potentially do a copy.
 * @param err
 * @return %TRUE. The return value is deprecated and %FALSE will only be
 *     returned for backwards compatibility reasons if an @error is not
 *     %NULL and a loading error occurred. To track errors while loading
 *     CSS, connect to the #GtkCssProvider::parsing-error signal.
 */
- (bool)loadFromDataWithData:(OFString*)data length:(gssize)length err:(GError**)err;

/**
 * Loads the data contained in @file into @css_provider, making it
 * clear any previously loaded information.
 *
 * @param file #GFile pointing to a file to load
 * @param err
 * @return %TRUE. The return value is deprecated and %FALSE will only be
 *     returned for backwards compatibility reasons if an @error is not
 *     %NULL and a loading error occurred. To track errors while loading
 *     CSS, connect to the #GtkCssProvider::parsing-error signal.
 */
- (bool)loadFromFileWithFile:(GFile*)file err:(GError**)err;

/**
 * Loads the data contained in @path into @css_provider, making it clear
 * any previously loaded information.
 *
 * @param path the path of a filename to load, in the GLib filename encoding
 * @param err
 * @return %TRUE. The return value is deprecated and %FALSE will only be
 *     returned for backwards compatibility reasons if an @error is not
 *     %NULL and a loading error occurred. To track errors while loading
 *     CSS, connect to the #GtkCssProvider::parsing-error signal.
 */
- (bool)loadFromPathWithPath:(OFString*)path err:(GError**)err;

/**
 * Loads the data contained in the resource at @resource_path into
 * the #GtkCssProvider, clearing any previously loaded information.
 * 
 * To track errors while loading CSS, connect to the
 * #GtkCssProvider::parsing-error signal.
 *
 * @param resourcePath a #GResource resource path
 */
- (void)loadFromResource:(OFString*)resourcePath;

/**
 * Converts the @provider into a string representation in CSS
 * format.
 * 
 * Using gtk_css_provider_load_from_data() with the return value
 * from this function on a new provider created with
 * gtk_css_provider_new() will basically create a duplicate of
 * this @provider.
 *
 * @return a new string representing the @provider.
 */
- (char*)toString;

@end