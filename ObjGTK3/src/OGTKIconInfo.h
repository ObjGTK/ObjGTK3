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
@class OGTKStyle;
@class OGTKStyleContext;
@class OGGdkPixbuf;
@class OGTKIconTheme;

/**
 * Contains information found when looking up an icon in
 * an icon theme.
 *
 */
@interface OGTKIconInfo : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)initForPixbufWithIconTheme:(OGTKIconTheme*)iconTheme pixbuf:(OGGdkPixbuf*)pixbuf;

/**
 * Methods
 */

- (GtkIconInfo*)ICONINFO;

/**
 * Make a copy of a #GtkIconInfo.
 *
 * @return the new GtkIconInfo
 */
- (OGTKIconInfo*)copy;

/**
 * Free a #GtkIconInfo and associated information
 *
 */
- (void)free;

/**
 * This function is deprecated and always returns %FALSE.
 *
 * @param points location to store pointer
 *     to an array of points, or %NULL free the array of points with g_free().
 * @param npoints location to store the number of points in @points,
 *     or %NULL
 * @return %FALSE
 */
- (bool)attachPointsWithPoints:(GdkPoint**)points npoints:(gint*)npoints;

/**
 * Gets the base scale for the icon. The base scale is a scale
 * for the icon that was specified by the icon theme creator.
 * For instance an icon drawn for a high-dpi screen with window
 * scale 2 for a base size of 32 will be 64 pixels tall and have
 * a base scale of 2.
 *
 * @return the base scale
 */
- (gint)baseScale;

/**
 * Gets the base size for the icon. The base size
 * is a size for the icon that was specified by
 * the icon theme creator. This may be different
 * than the actual size of image; an example of
 * this is small emblem icons that can be attached
 * to a larger icon. These icons will be given
 * the same base size as the larger icons to which
 * they are attached.
 * 
 * Note that for scaled icons the base size does
 * not include the base scale.
 *
 * @return the base size, or 0, if no base
 *     size is known for the icon.
 */
- (gint)baseSize;

/**
 * Gets the built-in image for this icon, if any. To allow GTK+ to use
 * built in icon images, you must pass the %GTK_ICON_LOOKUP_USE_BUILTIN
 * to gtk_icon_theme_lookup_icon().
 *
 * @return the built-in image pixbuf, or %NULL.
 *     No extra reference is added to the returned pixbuf, so if
 *     you want to keep it around, you must use g_object_ref().
 *     The returned image must not be modified.
 */
- (OGGdkPixbuf*)builtinPixbuf;

/**
 * This function is deprecated and always returns %NULL.
 *
 * @return %NULL
 */
- (OFString*)displayName;

/**
 * This function is deprecated and always returns %FALSE.
 *
 * @param rectangle #GdkRectangle in which to store embedded
 *   rectangle coordinates; coordinates are only stored
 *   when this function returns %TRUE.
 * @return %FALSE
 */
- (bool)embeddedRect:(GdkRectangle*)rectangle;

/**
 * Gets the filename for the icon. If the %GTK_ICON_LOOKUP_USE_BUILTIN
 * flag was passed to gtk_icon_theme_lookup_icon(), there may be no
 * filename if a builtin icon is returned; in this case, you should
 * use gtk_icon_info_get_builtin_pixbuf().
 *
 * @return the filename for the icon, or %NULL
 *     if gtk_icon_info_get_builtin_pixbuf() should be used instead.
 *     The return value is owned by GTK+ and should not be modified
 *     or freed.
 */
- (OFString*)filename;

/**
 * Checks if the icon is symbolic or not. This currently uses only
 * the file name and not the file contents for determining this.
 * This behaviour may change in the future.
 *
 * @return %TRUE if the icon is symbolic, %FALSE otherwise
 */
- (bool)isSymbolic;

/**
 * Renders an icon previously looked up in an icon theme using
 * gtk_icon_theme_lookup_icon(); the size will be based on the size
 * passed to gtk_icon_theme_lookup_icon(). Note that the resulting
 * pixbuf may not be exactly this size; an icon theme may have icons
 * that differ slightly from their nominal sizes, and in addition GTK+
 * will avoid scaling icons that it considers sufficiently close to the
 * requested size or for which the source image would have to be scaled
 * up too far. (This maintains sharpness.). This behaviour can be changed
 * by passing the %GTK_ICON_LOOKUP_FORCE_SIZE flag when obtaining
 * the #GtkIconInfo. If this flag has been specified, the pixbuf
 * returned by this function will be scaled to the exact size.
 *
 * @param err
 * @return the rendered icon; this may be a newly
 *     created icon or a new reference to an internal icon, so you must
 *     not modify the icon. Use g_object_unref() to release your reference
 *     to the icon.
 */
- (OGGdkPixbuf*)loadIcon:(GError**)err;

/**
 * Asynchronously load, render and scale an icon previously looked up
 * from the icon theme using gtk_icon_theme_lookup_icon().
 * 
 * For more details, see gtk_icon_info_load_icon() which is the synchronous
 * version of this call.
 *
 * @param cancellable optional #GCancellable object, %NULL to ignore
 * @param callback a #GAsyncReadyCallback to call when the
 *     request is satisfied
 * @param userData the data to pass to callback function
 */
- (void)loadIconAsyncWithCancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData;

/**
 * Finishes an async icon load, see gtk_icon_info_load_icon_async().
 *
 * @param res a #GAsyncResult
 * @param err
 * @return the rendered icon; this may be a newly
 *     created icon or a new reference to an internal icon, so you must
 *     not modify the icon. Use g_object_unref() to release your reference
 *     to the icon.
 */
- (OGGdkPixbuf*)loadIconFinishWithRes:(GAsyncResult*)res err:(GError**)err;

/**
 * Renders an icon previously looked up in an icon theme using
 * gtk_icon_theme_lookup_icon(); the size will be based on the size
 * passed to gtk_icon_theme_lookup_icon(). Note that the resulting
 * surface may not be exactly this size; an icon theme may have icons
 * that differ slightly from their nominal sizes, and in addition GTK+
 * will avoid scaling icons that it considers sufficiently close to the
 * requested size or for which the source image would have to be scaled
 * up too far. (This maintains sharpness.). This behaviour can be changed
 * by passing the %GTK_ICON_LOOKUP_FORCE_SIZE flag when obtaining
 * the #GtkIconInfo. If this flag has been specified, the pixbuf
 * returned by this function will be scaled to the exact size.
 *
 * @param forWindow #GdkWindow to optimize drawing for, or %NULL
 * @param err
 * @return the rendered icon; this may be a newly
 *     created icon or a new reference to an internal icon, so you must
 *     not modify the icon. Use cairo_surface_destroy() to release your
 *     reference to the icon.
 */
- (cairo_surface_t*)loadSurfaceWithForWindow:(OGGdkWindow*)forWindow err:(GError**)err;

/**
 * Loads an icon, modifying it to match the system colours for the foreground,
 * success, warning and error colors provided. If the icon is not a symbolic
 * one, the function will return the result from gtk_icon_info_load_icon().
 * 
 * This allows loading symbolic icons that will match the system theme.
 * 
 * Unless you are implementing a widget, you will want to use
 * g_themed_icon_new_with_default_fallbacks() to load the icon.
 * 
 * As implementation details, the icon loaded needs to be of SVG type,
 * contain the “symbolic” term as the last component of the icon name,
 * and use the “fg”, “success”, “warning” and “error” CSS styles in the
 * SVG file itself.
 * 
 * See the [Symbolic Icons Specification](http://www.freedesktop.org/wiki/SymbolicIcons)
 * for more information about symbolic icons.
 *
 * @param fg a #GdkRGBA representing the foreground color of the icon
 * @param successColor a #GdkRGBA representing the warning color
 *     of the icon or %NULL to use the default color
 * @param warningColor a #GdkRGBA representing the warning color
 *     of the icon or %NULL to use the default color
 * @param errorColor a #GdkRGBA representing the error color
 *     of the icon or %NULL to use the default color (allow-none)
 * @param wasSymbolic a #gboolean, returns whether the
 *     loaded icon was a symbolic one and whether the @fg color was
 *     applied to it.
 * @param err
 * @return a #GdkPixbuf representing the loaded icon
 */
- (OGGdkPixbuf*)loadSymbolicWithFg:(const GdkRGBA*)fg successColor:(const GdkRGBA*)successColor warningColor:(const GdkRGBA*)warningColor errorColor:(const GdkRGBA*)errorColor wasSymbolic:(gboolean*)wasSymbolic err:(GError**)err;

/**
 * Asynchronously load, render and scale a symbolic icon previously looked up
 * from the icon theme using gtk_icon_theme_lookup_icon().
 * 
 * For more details, see gtk_icon_info_load_symbolic() which is the synchronous
 * version of this call.
 *
 * @param fg a #GdkRGBA representing the foreground color of the icon
 * @param successColor a #GdkRGBA representing the warning color
 *     of the icon or %NULL to use the default color
 * @param warningColor a #GdkRGBA representing the warning color
 *     of the icon or %NULL to use the default color
 * @param errorColor a #GdkRGBA representing the error color
 *     of the icon or %NULL to use the default color (allow-none)
 * @param cancellable optional #GCancellable object,
 *     %NULL to ignore
 * @param callback a #GAsyncReadyCallback to call when the
 *     request is satisfied
 * @param userData the data to pass to callback function
 */
- (void)loadSymbolicAsyncWithFg:(const GdkRGBA*)fg successColor:(const GdkRGBA*)successColor warningColor:(const GdkRGBA*)warningColor errorColor:(const GdkRGBA*)errorColor cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData;

/**
 * Finishes an async icon load, see gtk_icon_info_load_symbolic_async().
 *
 * @param res a #GAsyncResult
 * @param wasSymbolic a #gboolean, returns whether the
 *     loaded icon was a symbolic one and whether the @fg color was
 *     applied to it.
 * @param err
 * @return the rendered icon; this may be a newly
 *     created icon or a new reference to an internal icon, so you must
 *     not modify the icon. Use g_object_unref() to release your reference
 *     to the icon.
 */
- (OGGdkPixbuf*)loadSymbolicFinishWithRes:(GAsyncResult*)res wasSymbolic:(gboolean*)wasSymbolic err:(GError**)err;

/**
 * Loads an icon, modifying it to match the system colors for the foreground,
 * success, warning and error colors provided. If the icon is not a symbolic
 * one, the function will return the result from gtk_icon_info_load_icon().
 * This function uses the regular foreground color and the symbolic colors
 * with the names “success_color”, “warning_color” and “error_color” from
 * the context.
 * 
 * This allows loading symbolic icons that will match the system theme.
 * 
 * See gtk_icon_info_load_symbolic() for more details.
 *
 * @param context a #GtkStyleContext
 * @param wasSymbolic a #gboolean, returns whether the
 *     loaded icon was a symbolic one and whether the @fg color was
 *     applied to it.
 * @param err
 * @return a #GdkPixbuf representing the loaded icon
 */
- (OGGdkPixbuf*)loadSymbolicForContextWithContext:(OGTKStyleContext*)context wasSymbolic:(gboolean*)wasSymbolic err:(GError**)err;

/**
 * Asynchronously load, render and scale a symbolic icon previously
 * looked up from the icon theme using gtk_icon_theme_lookup_icon().
 * 
 * For more details, see gtk_icon_info_load_symbolic_for_context()
 * which is the synchronous version of this call.
 *
 * @param context a #GtkStyleContext
 * @param cancellable optional #GCancellable object,
 *     %NULL to ignore
 * @param callback a #GAsyncReadyCallback to call when the
 *     request is satisfied
 * @param userData the data to pass to callback function
 */
- (void)loadSymbolicForContextAsyncWithContext:(OGTKStyleContext*)context cancellable:(GCancellable*)cancellable callback:(GAsyncReadyCallback)callback userData:(gpointer)userData;

/**
 * Finishes an async icon load, see gtk_icon_info_load_symbolic_for_context_async().
 *
 * @param res a #GAsyncResult
 * @param wasSymbolic a #gboolean, returns whether the
 *     loaded icon was a symbolic one and whether the @fg color was
 *     applied to it.
 * @param err
 * @return the rendered icon; this may be a newly
 *     created icon or a new reference to an internal icon, so you must
 *     not modify the icon. Use g_object_unref() to release your reference
 *     to the icon.
 */
- (OGGdkPixbuf*)loadSymbolicForContextFinishWithRes:(GAsyncResult*)res wasSymbolic:(gboolean*)wasSymbolic err:(GError**)err;

/**
 * Loads an icon, modifying it to match the system colours for the foreground,
 * success, warning and error colors provided. If the icon is not a symbolic
 * one, the function will return the result from gtk_icon_info_load_icon().
 * 
 * This allows loading symbolic icons that will match the system theme.
 * 
 * See gtk_icon_info_load_symbolic() for more details.
 *
 * @param style a #GtkStyle to take the colors from
 * @param state the widget state to use for colors
 * @param wasSymbolic a #gboolean, returns whether the
 *     loaded icon was a symbolic one and whether the @fg color was
 *     applied to it.
 * @param err
 * @return a #GdkPixbuf representing the loaded icon
 */
- (OGGdkPixbuf*)loadSymbolicForStyleWithStyle:(OGTKStyle*)style state:(GtkStateType)state wasSymbolic:(gboolean*)wasSymbolic err:(GError**)err;

/**
 * Sets whether the coordinates returned by gtk_icon_info_get_embedded_rect()
 * and gtk_icon_info_get_attach_points() should be returned in their
 * original form as specified in the icon theme, instead of scaled
 * appropriately for the pixbuf returned by gtk_icon_info_load_icon().
 * 
 * Raw coordinates are somewhat strange; they are specified to be with
 * respect to the unscaled pixmap for PNG and XPM icons, but for SVG
 * icons, they are in a 1000x1000 coordinate space that is scaled
 * to the final size of the icon.  You can determine if the icon is an SVG
 * icon by using gtk_icon_info_get_filename(), and seeing if it is non-%NULL
 * and ends in “.svg”.
 * 
 * This function is provided primarily to allow compatibility wrappers
 * for older API's, and is not expected to be useful for applications.
 *
 * @param rawCoordinates whether the coordinates of embedded rectangles
 *     and attached points should be returned in their original
 *     (unscaled) form.
 */
- (void)setRawCoordinates:(bool)rawCoordinates;

@end