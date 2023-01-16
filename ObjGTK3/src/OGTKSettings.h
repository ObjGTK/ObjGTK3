/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtkx.h>
#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>

#import <OGObject/OGObject.h>

@class OGGdkScreen;

/**
 * GtkSettings provide a mechanism to share global settings between
 * applications.
 * 
 * On the X window system, this sharing is realized by an
 * [XSettings](http://www.freedesktop.org/wiki/Specifications/xsettings-spec)
 * manager that is usually part of the desktop environment, along with
 * utilities that let the user change these settings. In the absence of
 * an Xsettings manager, GTK+ reads default values for settings from
 * `settings.ini` files in
 * `/etc/gtk-3.0`, `$XDG_CONFIG_DIRS/gtk-3.0`
 * and `$XDG_CONFIG_HOME/gtk-3.0`.
 * These files must be valid key files (see #GKeyFile), and have
 * a section called Settings. Themes can also provide default values
 * for settings by installing a `settings.ini` file
 * next to their `gtk.css` file.
 * 
 * Applications can override system-wide settings by setting the property
 * of the GtkSettings object with g_object_set(). This should be restricted
 * to special cases though; GtkSettings are not meant as an application
 * configuration facility. When doing so, you need to be aware that settings
 * that are specific to individual widgets may not be available before the
 * widget type has been realized at least once. The following example
 * demonstrates a way to do this:
 * |[<!-- language="C" -->
 *   gtk_init (&argc, &argv);
 * 
 *   // make sure the type is realized
 *   g_type_class_unref (g_type_class_ref (GTK_TYPE_IMAGE_MENU_ITEM));
 * 
 *   g_object_set (gtk_settings_get_default (), "gtk-enable-animations", FALSE, NULL);
 * ]|
 * 
 * There is one GtkSettings instance per screen. It can be obtained with
 * gtk_settings_get_for_screen(), but in many cases, it is more convenient
 * to use gtk_widget_get_settings(). gtk_settings_get_default() returns the
 * GtkSettings instance for the default screen.
 *
 */
@interface OGTKSettings : OGObject
{

}

/**
 * Functions
 */

/**
 * Gets the #GtkSettings object for the default GDK screen, creating
 * it if necessary. See gtk_settings_get_for_screen().
 *
 * @return a #GtkSettings object. If there is
 * no default screen, then returns %NULL.
 */
+ (OGTKSettings*)default;

/**
 * Gets the #GtkSettings object for @screen, creating it if necessary.
 *
 * @param screen a #GdkScreen.
 * @return a #GtkSettings object.
 */
+ (OGTKSettings*)forScreen:(OGGdkScreen*)screen;

/**
 * This function is not useful outside GTK+.
 *
 * @param pspec
 */
+ (void)installProperty:(GParamSpec*)pspec;

/**
 * This function is not useful outside GTK+.
 *
 * @param pspec
 * @param parser
 */
+ (void)installPropertyParserWithPspec:(GParamSpec*)pspec parser:(GtkRcPropertyParser)parser;

/**
 * Methods
 */

- (GtkSettings*)SETTINGS;

/**
 * Undoes the effect of calling g_object_set() to install an
 * application-specific value for a setting. After this call,
 * the setting will again follow the session-wide value for
 * this setting.
 *
 * @param name the name of the setting to reset
 */
- (void)resetProperty:(OFString*)name;

/**
 *
 * @param name
 * @param vdouble
 * @param origin
 */
- (void)setDoublePropertyWithName:(OFString*)name vdouble:(gdouble)vdouble origin:(OFString*)origin;

/**
 *
 * @param name
 * @param vlong
 * @param origin
 */
- (void)setLongPropertyWithName:(OFString*)name vlong:(glong)vlong origin:(OFString*)origin;

/**
 *
 * @param name
 * @param svalue
 */
- (void)setPropertyValueWithName:(OFString*)name svalue:(const GtkSettingsValue*)svalue;

/**
 *
 * @param name
 * @param vstring
 * @param origin
 */
- (void)setStringPropertyWithName:(OFString*)name vstring:(OFString*)vstring origin:(OFString*)origin;

@end