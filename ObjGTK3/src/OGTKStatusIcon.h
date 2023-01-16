/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>
#include <gtk/gtk.h>

#import <OGObject/OGObject.h>

@class OGGdkScreen;
@class OGGdkPixbuf;
@class OGTKMenu;

/**
 * The “system tray” or notification area is normally used for transient icons
 * that indicate some special state. For example, a system tray icon might
 * appear to tell the user that they have new mail, or have an incoming instant
 * message, or something along those lines. The basic idea is that creating an
 * icon in the notification area is less annoying than popping up a dialog.
 * 
 * A #GtkStatusIcon object can be used to display an icon in a “system tray”.
 * The icon can have a tooltip, and the user can interact with it by
 * activating it or popping up a context menu.
 * 
 * It is very important to notice that status icons depend on the existence
 * of a notification area being available to the user; you should not use status
 * icons as the only way to convey critical information regarding your application,
 * as the notification area may not exist on the user's environment, or may have
 * been removed. You should always check that a status icon has been embedded into
 * a notification area by using gtk_status_icon_is_embedded(), and gracefully
 * recover if the function returns %FALSE.
 * 
 * On X11, the implementation follows the
 * [FreeDesktop System Tray Specification](http://www.freedesktop.org/wiki/Specifications/systemtray-spec).
 * Implementations of the “tray” side of this specification can
 * be found e.g. in the GNOME 2 and KDE panel applications.
 * 
 * Note that a GtkStatusIcon is not a widget, but just a #GObject. Making it a
 * widget would be impractical, since the system tray on Windows doesn’t allow
 * to embed arbitrary widgets.
 * 
 * GtkStatusIcon has been deprecated in 3.14. You should consider using
 * notifications or more modern platform-specific APIs instead. GLib provides
 * the #GNotification API which works well with #GtkApplication on multiple
 * platforms and environments, and should be the preferred mechanism to notify
 * the users of transient status updates. See this [HowDoI](https://wiki.gnome.org/HowDoI/GNotification)
 * for code examples.
 *
 */
@interface OGTKStatusIcon : OGObject
{

}

/**
 * Functions
 */

/**
 * Menu positioning function to use with gtk_menu_popup()
 * to position @menu aligned to the status icon @user_data.
 *
 * @param menu the #GtkMenu
 * @param x return location for the x position
 * @param y return location for the y position
 * @param pushIn whether the first menu item should be offset
 *           (pushed in) to be aligned with the menu popup position
 *           (only useful for GtkOptionMenu).
 * @param userData the status icon to position the menu on
 */
+ (void)positionMenuWithMenu:(OGTKMenu*)menu x:(gint*)x y:(gint*)y pushIn:(gboolean*)pushIn userData:(gpointer)userData;

/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initFromFile:(OFString*)filename;
- (instancetype)initFromGicon:(GIcon*)icon;
- (instancetype)initFromIconName:(OFString*)iconName;
- (instancetype)initFromPixbuf:(OGGdkPixbuf*)pixbuf;
- (instancetype)initFromStock:(OFString*)stockId;

/**
 * Methods
 */

- (GtkStatusIcon*)STATUSICON;

/**
 * Obtains information about the location of the status icon
 * on screen. This information can be used to e.g. position
 * popups like notification bubbles.
 * 
 * See gtk_status_icon_position_menu() for a more convenient
 * alternative for positioning menus.
 * 
 * Note that some platforms do not allow GTK+ to provide
 * this information, and even on platforms that do allow it,
 * the information is not reliable unless the status icon
 * is embedded in a notification area, see
 * gtk_status_icon_is_embedded().
 *
 * @param screen return location for
 *          the screen, or %NULL if the information is not needed
 * @param area return location for the area occupied by
 *        the status icon, or %NULL
 * @param orientation return location for the
 *    orientation of the panel in which the status icon is embedded,
 *    or %NULL. A panel at the top or bottom of the screen is
 *    horizontal, a panel at the left or right is vertical.
 * @return %TRUE if the location information has
 *               been filled in
 */
- (bool)geometryWithScreen:(GdkScreen**)screen area:(GdkRectangle*)area orientation:(GtkOrientation*)orientation;

/**
 * Retrieves the #GIcon being displayed by the #GtkStatusIcon.
 * The storage type of the status icon must be %GTK_IMAGE_EMPTY or
 * %GTK_IMAGE_GICON (see gtk_status_icon_get_storage_type()).
 * The caller of this function does not own a reference to the
 * returned #GIcon.
 * 
 * If this function fails, @icon is left unchanged;
 *
 * @return the displayed icon, or %NULL if the image is empty
 */
- (GIcon*)gicon;

/**
 * Returns the current value of the has-tooltip property.
 * See #GtkStatusIcon:has-tooltip for more information.
 *
 * @return current value of has-tooltip on @status_icon.
 */
- (bool)hasTooltip;

/**
 * Gets the name of the icon being displayed by the #GtkStatusIcon.
 * The storage type of the status icon must be %GTK_IMAGE_EMPTY or
 * %GTK_IMAGE_ICON_NAME (see gtk_status_icon_get_storage_type()).
 * The returned string is owned by the #GtkStatusIcon and should not
 * be freed or modified.
 *
 * @return name of the displayed icon, or %NULL if the image is empty.
 */
- (OFString*)iconName;

/**
 * Gets the #GdkPixbuf being displayed by the #GtkStatusIcon.
 * The storage type of the status icon must be %GTK_IMAGE_EMPTY or
 * %GTK_IMAGE_PIXBUF (see gtk_status_icon_get_storage_type()).
 * The caller of this function does not own a reference to the
 * returned pixbuf.
 *
 * @return the displayed pixbuf,
 *     or %NULL if the image is empty.
 */
- (OGGdkPixbuf*)pixbuf;

/**
 * Returns the #GdkScreen associated with @status_icon.
 *
 * @return a #GdkScreen.
 */
- (OGGdkScreen*)screen;

/**
 * Gets the size in pixels that is available for the image.
 * Stock icons and named icons adapt their size automatically
 * if the size of the notification area changes. For other
 * storage types, the size-changed signal can be used to
 * react to size changes.
 * 
 * Note that the returned size is only meaningful while the
 * status icon is embedded (see gtk_status_icon_is_embedded()).
 *
 * @return the size that is available for the image
 */
- (gint)size;

/**
 * Gets the id of the stock icon being displayed by the #GtkStatusIcon.
 * The storage type of the status icon must be %GTK_IMAGE_EMPTY or
 * %GTK_IMAGE_STOCK (see gtk_status_icon_get_storage_type()).
 * The returned string is owned by the #GtkStatusIcon and should not
 * be freed or modified.
 *
 * @return stock id of the displayed stock icon,
 *   or %NULL if the image is empty.
 */
- (OFString*)stock;

/**
 * Gets the type of representation being used by the #GtkStatusIcon
 * to store image data. If the #GtkStatusIcon has no image data,
 * the return value will be %GTK_IMAGE_EMPTY.
 *
 * @return the image representation being used
 */
- (GtkImageType)storageType;

/**
 * Gets the title of this tray icon. See gtk_status_icon_set_title().
 *
 * @return the title of the status icon
 */
- (OFString*)title;

/**
 * Gets the contents of the tooltip for @status_icon.
 *
 * @return the tooltip text, or %NULL. You should free the
 *   returned string with g_free() when done.
 */
- (OFString*)tooltipMarkup;

/**
 * Gets the contents of the tooltip for @status_icon.
 *
 * @return the tooltip text, or %NULL. You should free the
 *   returned string with g_free() when done.
 */
- (OFString*)tooltipText;

/**
 * Returns whether the status icon is visible or not.
 * Note that being visible does not guarantee that
 * the user can actually see the icon, see also
 * gtk_status_icon_is_embedded().
 *
 * @return %TRUE if the status icon is visible
 */
- (bool)visible;

/**
 * This function is only useful on the X11/freedesktop.org platform.
 * 
 * It returns a window ID for the widget in the underlying
 * status icon implementation.  This is useful for the Galago
 * notification service, which can send a window ID in the protocol
 * in order for the server to position notification windows
 * pointing to a status icon reliably.
 * 
 * This function is not intended for other use cases which are
 * more likely to be met by one of the non-X11 specific methods, such
 * as gtk_status_icon_position_menu().
 *
 * @return An 32 bit unsigned integer identifier for the
 * underlying X11 Window
 */
- (guint32)x11WindowId;

/**
 * Returns whether the status icon is embedded in a notification
 * area.
 *
 * @return %TRUE if the status icon is embedded in
 *   a notification area.
 */
- (bool)isEmbedded;

/**
 * Makes @status_icon display the file @filename.
 * See gtk_status_icon_new_from_file() for details.
 *
 * @param filename a filename
 */
- (void)setFromFile:(OFString*)filename;

/**
 * Makes @status_icon display the #GIcon.
 * See gtk_status_icon_new_from_gicon() for details.
 *
 * @param icon a GIcon
 */
- (void)setFromGicon:(GIcon*)icon;

/**
 * Makes @status_icon display the icon named @icon_name from the
 * current icon theme.
 * See gtk_status_icon_new_from_icon_name() for details.
 *
 * @param iconName an icon name
 */
- (void)setFromIconName:(OFString*)iconName;

/**
 * Makes @status_icon display @pixbuf.
 * See gtk_status_icon_new_from_pixbuf() for details.
 *
 * @param pixbuf a #GdkPixbuf or %NULL
 */
- (void)setFromPixbuf:(OGGdkPixbuf*)pixbuf;

/**
 * Makes @status_icon display the stock icon with the id @stock_id.
 * See gtk_status_icon_new_from_stock() for details.
 *
 * @param stockId a stock icon id
 */
- (void)setFromStock:(OFString*)stockId;

/**
 * Sets the has-tooltip property on @status_icon to @has_tooltip.
 * See #GtkStatusIcon:has-tooltip for more information.
 *
 * @param hasTooltip whether or not @status_icon has a tooltip
 */
- (void)setHasTooltip:(bool)hasTooltip;

/**
 * Sets the name of this tray icon.
 * This should be a string identifying this icon. It is may be
 * used for sorting the icons in the tray and will not be shown to
 * the user.
 *
 * @param name the name
 */
- (void)setName:(OFString*)name;

/**
 * Sets the #GdkScreen where @status_icon is displayed; if
 * the icon is already mapped, it will be unmapped, and
 * then remapped on the new screen.
 *
 * @param screen a #GdkScreen
 */
- (void)setScreen:(OGGdkScreen*)screen;

/**
 * Sets the title of this tray icon.
 * This should be a short, human-readable, localized string
 * describing the tray icon. It may be used by tools like screen
 * readers to render the tray icon.
 *
 * @param title the title
 */
- (void)setTitle:(OFString*)title;

/**
 * Sets @markup as the contents of the tooltip, which is marked up with
 *  the [Pango text markup language][PangoMarkupFormat].
 * 
 * This function will take care of setting #GtkStatusIcon:has-tooltip to %TRUE
 * and of the default handler for the #GtkStatusIcon::query-tooltip signal.
 * 
 * See also the #GtkStatusIcon:tooltip-markup property and
 * gtk_tooltip_set_markup().
 *
 * @param markup the contents of the tooltip for @status_icon, or %NULL
 */
- (void)setTooltipMarkup:(OFString*)markup;

/**
 * Sets @text as the contents of the tooltip.
 * 
 * This function will take care of setting #GtkStatusIcon:has-tooltip to
 * %TRUE and of the default handler for the #GtkStatusIcon::query-tooltip
 * signal.
 * 
 * See also the #GtkStatusIcon:tooltip-text property and
 * gtk_tooltip_set_text().
 *
 * @param text the contents of the tooltip for @status_icon
 */
- (void)setTooltipText:(OFString*)text;

/**
 * Shows or hides a status icon.
 *
 * @param visible %TRUE to show the status icon, %FALSE to hide it
 */
- (void)setVisible:(bool)visible;

@end