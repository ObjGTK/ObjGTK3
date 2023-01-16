/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

@class OGTKWindow;

/**
 * #GtkApplication is a class that handles many important aspects
 * of a GTK+ application in a convenient fashion, without enforcing
 * a one-size-fits-all application model.
 * 
 * Currently, GtkApplication handles GTK+ initialization, application
 * uniqueness, session management, provides some basic scriptability and
 * desktop shell integration by exporting actions and menus and manages a
 * list of toplevel windows whose life-cycle is automatically tied to the
 * life-cycle of your application.
 * 
 * While GtkApplication works fine with plain #GtkWindows, it is recommended
 * to use it together with #GtkApplicationWindow.
 * 
 * When GDK threads are enabled, GtkApplication will acquire the GDK
 * lock when invoking actions that arrive from other processes.  The GDK
 * lock is not touched for local action invocations.  In order to have
 * actions invoked in a predictable context it is therefore recommended
 * that the GDK lock be held while invoking actions locally with
 * g_action_group_activate_action().  The same applies to actions
 * associated with #GtkApplicationWindow and to the “activate” and
 * “open” #GApplication methods.
 * 
 * ## Automatic resources ## {#automatic-resources}
 * 
 * #GtkApplication will automatically load menus from the #GtkBuilder
 * resource located at "gtk/menus.ui", relative to the application's
 * resource base path (see g_application_set_resource_base_path()).  The
 * menu with the ID "app-menu" is taken as the application's app menu
 * and the menu with the ID "menubar" is taken as the application's
 * menubar.  Additional menus (most interesting submenus) can be named
 * and accessed via gtk_application_get_menu_by_id() which allows for
 * dynamic population of a part of the menu structure.
 * 
 * If the resources "gtk/menus-appmenu.ui" or "gtk/menus-traditional.ui" are
 * present then these files will be used in preference, depending on the value
 * of gtk_application_prefers_app_menu(). If the resource "gtk/menus-common.ui"
 * is present it will be loaded as well. This is useful for storing items that
 * are referenced from both "gtk/menus-appmenu.ui" and
 * "gtk/menus-traditional.ui".
 * 
 * It is also possible to provide the menus manually using
 * gtk_application_set_app_menu() and gtk_application_set_menubar().
 * 
 * #GtkApplication will also automatically setup an icon search path for
 * the default icon theme by appending "icons" to the resource base
 * path.  This allows your application to easily store its icons as
 * resources.  See gtk_icon_theme_add_resource_path() for more
 * information.
 * 
 * If there is a resource located at "gtk/help-overlay.ui" which
 * defines a #GtkShortcutsWindow with ID "help_overlay" then GtkApplication
 * associates an instance of this shortcuts window with each
 * #GtkApplicationWindow and sets up keyboard accelerators (Control-F1
 * and Control-?) to open it. To create a menu item that displays the
 * shortcuts window, associate the item with the action win.show-help-overlay.
 * 
 * ## A simple application ## {#gtkapplication}
 * 
 * [A simple example](https://gitlab.gnome.org/GNOME/gtk/-/blob/gtk-3-24/examples/bp/bloatpad.c)
 * 
 * GtkApplication optionally registers with a session manager
 * of the users session (if you set the #GtkApplication:register-session
 * property) and offers various functionality related to the session
 * life-cycle.
 * 
 * An application can block various ways to end the session with
 * the gtk_application_inhibit() function. Typical use cases for
 * this kind of inhibiting are long-running, uninterruptible operations,
 * such as burning a CD or performing a disk backup. The session
 * manager may not honor the inhibitor, but it can be expected to
 * inform the user about the negative consequences of ending the
 * session while inhibitors are present.
 * 
 * ## See Also ## {#seealso}
 * [HowDoI: Using GtkApplication](https://wiki.gnome.org/HowDoI/GtkApplication),
 * [Getting Started with GTK+: Basics](https://developer.gnome.org/gtk3/stable/gtk-getting-started.html#id-1.2.3.3)
 *
 */
@interface OGTKApplication : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)initWithApplicationId:(OFString*)applicationId flags:(GApplicationFlags)flags;

/**
 * Methods
 */

- (GtkApplication*)APPLICATION;

/**
 * Installs an accelerator that will cause the named action
 * to be activated when the key combination specificed by @accelerator
 * is pressed.
 * 
 * @accelerator must be a string that can be parsed by gtk_accelerator_parse(),
 * e.g. "<Primary>q" or “<Control><Alt>p”.
 * 
 * @action_name must be the name of an action as it would be used
 * in the app menu, i.e. actions that have been added to the application
 * are referred to with an “app.” prefix, and window-specific actions
 * with a “win.” prefix.
 * 
 * GtkApplication also extracts accelerators out of “accel” attributes
 * in the #GMenuModels passed to gtk_application_set_app_menu() and
 * gtk_application_set_menubar(), which is usually more convenient
 * than calling this function for each accelerator.
 *
 * @param accelerator accelerator string
 * @param actionName the name of the action to activate
 * @param parameter parameter to pass when activating the action,
 *   or %NULL if the action does not accept an activation parameter
 */
- (void)addAcceleratorWithAccelerator:(OFString*)accelerator actionName:(OFString*)actionName parameter:(GVariant*)parameter;

/**
 * Adds a window to @application.
 * 
 * This call can only happen after the @application has started;
 * typically, you should add new application windows in response
 * to the emission of the #GApplication::activate signal.
 * 
 * This call is equivalent to setting the #GtkWindow:application
 * property of @window to @application.
 * 
 * Normally, the connection between the application and the window
 * will remain until the window is destroyed, but you can explicitly
 * remove it with gtk_application_remove_window().
 * 
 * GTK+ will keep the @application running as long as it has
 * any windows.
 *
 * @param window a #GtkWindow
 */
- (void)addWindow:(OGTKWindow*)window;

/**
 * Gets the accelerators that are currently associated with
 * the given action.
 *
 * @param detailedActionName a detailed action name, specifying an action
 *     and target to obtain accelerators for
 * @return accelerators for @detailed_action_name, as
 *     a %NULL-terminated array. Free with g_strfreev() when no longer needed
 */
- (gchar**)accelsForAction:(OFString*)detailedActionName;

/**
 * Returns the list of actions (possibly empty) that @accel maps to.
 * Each item in the list is a detailed action name in the usual form.
 * 
 * This might be useful to discover if an accel already exists in
 * order to prevent installation of a conflicting accelerator (from
 * an accelerator editor or a plugin system, for example). Note that
 * having more than one action per accelerator may not be a bad thing
 * and might make sense in cases where the actions never appear in the
 * same context.
 * 
 * In case there are no actions for a given accelerator, an empty array
 * is returned.  %NULL is never returned.
 * 
 * It is a programmer error to pass an invalid accelerator string.
 * If you are unsure, check it with gtk_accelerator_parse() first.
 *
 * @param accel an accelerator that can be parsed by gtk_accelerator_parse()
 * @return a %NULL-terminated array of actions for @accel
 */
- (gchar**)actionsForAccel:(OFString*)accel;

/**
 * Gets the “active” window for the application.
 * 
 * The active window is the one that was most recently focused (within
 * the application).  This window may not have the focus at the moment
 * if another application has it — this is just the most
 * recently-focused window within this application.
 *
 * @return the active window, or %NULL if
 *   there isn't one.
 */
- (OGTKWindow*)activeWindow;

/**
 * Returns the menu model that has been set with
 * gtk_application_set_app_menu().
 *
 * @return the application menu of @application
 *   or %NULL if no application menu has been set.
 */
- (GMenuModel*)appMenu;

/**
 * Gets a menu from automatically loaded resources.
 * See [Automatic resources][automatic-resources]
 * for more information.
 *
 * @param id the id of the menu to look up
 * @return Gets the menu with the
 *     given id from the automatically loaded resources
 */
- (GMenu*)menuById:(OFString*)id;

/**
 * Returns the menu model that has been set with
 * gtk_application_set_menubar().
 *
 * @return the menubar for windows of @application
 */
- (GMenuModel*)menubar;

/**
 * Returns the #GtkApplicationWindow with the given ID.
 * 
 * The ID of a #GtkApplicationWindow can be retrieved with
 * gtk_application_window_get_id().
 *
 * @param id an identifier number
 * @return the window with ID @id, or
 *   %NULL if there is no window with this ID
 */
- (OGTKWindow*)windowById:(guint)id;

/**
 * Gets a list of the #GtkWindows associated with @application.
 * 
 * The list is sorted by most recently focused window, such that the first
 * element is the currently focused window. (Useful for choosing a parent
 * for a transient window.)
 * 
 * The list that is returned should not be modified in any way. It will
 * only remain valid until the next focus change or window creation or
 * deletion.
 *
 * @return a #GList of #GtkWindow
 */
- (GList*)windows;

/**
 * Inform the session manager that certain types of actions should be
 * inhibited. This is not guaranteed to work on all platforms and for
 * all types of actions.
 * 
 * Applications should invoke this method when they begin an operation
 * that should not be interrupted, such as creating a CD or DVD. The
 * types of actions that may be blocked are specified by the @flags
 * parameter. When the application completes the operation it should
 * call gtk_application_uninhibit() to remove the inhibitor. Note that
 * an application can have multiple inhibitors, and all of them must
 * be individually removed. Inhibitors are also cleared when the
 * application exits.
 * 
 * Applications should not expect that they will always be able to block
 * the action. In most cases, users will be given the option to force
 * the action to take place.
 * 
 * Reasons should be short and to the point.
 * 
 * If @window is given, the session manager may point the user to
 * this window to find out more about why the action is inhibited.
 *
 * @param window a #GtkWindow, or %NULL
 * @param flags what types of actions should be inhibited
 * @param reason a short, human-readable string that explains
 *     why these operations are inhibited
 * @return A non-zero cookie that is used to uniquely identify this
 *     request. It should be used as an argument to gtk_application_uninhibit()
 *     in order to remove the request. If the platform does not support
 *     inhibiting or the request failed for some reason, 0 is returned.
 */
- (guint)inhibitWithWindow:(OGTKWindow*)window flags:(GtkApplicationInhibitFlags)flags reason:(OFString*)reason;

/**
 * Determines if any of the actions specified in @flags are
 * currently inhibited (possibly by another application).
 * 
 * Note that this information may not be available (for example
 * when the application is running in a sandbox).
 *
 * @param flags what types of actions should be queried
 * @return %TRUE if any of the actions specified in @flags are inhibited
 */
- (bool)isInhibited:(GtkApplicationInhibitFlags)flags;

/**
 * Lists the detailed action names which have associated accelerators.
 * See gtk_application_set_accels_for_action().
 *
 * @return a %NULL-terminated array of strings,
 *     free with g_strfreev() when done
 */
- (gchar**)listActionDescriptions;

/**
 * Determines if the desktop environment in which the application is
 * running would prefer an application menu be shown.
 * 
 * If this function returns %TRUE then the application should call
 * gtk_application_set_app_menu() with the contents of an application
 * menu, which will be shown by the desktop environment.  If it returns
 * %FALSE then you should consider using an alternate approach, such as
 * a menubar.
 * 
 * The value returned by this function is purely advisory and you are
 * free to ignore it.  If you call gtk_application_set_app_menu() even
 * if the desktop environment doesn't support app menus, then a fallback
 * will be provided.
 * 
 * Applications are similarly free not to set an app menu even if the
 * desktop environment wants to show one.  In that case, a fallback will
 * also be created by the desktop environment (GNOME, for example, uses
 * a menu with only a "Quit" item in it).
 * 
 * The value returned by this function never changes.  Once it returns a
 * particular value, it is guaranteed to always return the same value.
 * 
 * You may only call this function after the application has been
 * registered and after the base startup handler has run.  You're most
 * likely to want to use this from your own startup handler.  It may
 * also make sense to consult this function while constructing UI (in
 * activate, open or an action activation handler) in order to determine
 * if you should show a gear menu or not.
 * 
 * This function will return %FALSE on Mac OS and a default app menu
 * will be created automatically with the "usual" contents of that menu
 * typical to most Mac OS applications.  If you call
 * gtk_application_set_app_menu() anyway, then this menu will be
 * replaced with your own.
 *
 * @return %TRUE if you should set an app menu
 */
- (bool)prefersAppMenu;

/**
 * Removes an accelerator that has been previously added
 * with gtk_application_add_accelerator().
 *
 * @param actionName the name of the action to activate
 * @param parameter parameter to pass when activating the action,
 *   or %NULL if the action does not accept an activation parameter
 */
- (void)removeAcceleratorWithActionName:(OFString*)actionName parameter:(GVariant*)parameter;

/**
 * Remove a window from @application.
 * 
 * If @window belongs to @application then this call is equivalent to
 * setting the #GtkWindow:application property of @window to
 * %NULL.
 * 
 * The application may stop running as a result of a call to this
 * function.
 *
 * @param window a #GtkWindow
 */
- (void)removeWindow:(OGTKWindow*)window;

/**
 * Sets zero or more keyboard accelerators that will trigger the
 * given action. The first item in @accels will be the primary
 * accelerator, which may be displayed in the UI.
 * 
 * To remove all accelerators for an action, use an empty, zero-terminated
 * array for @accels.
 * 
 * For the @detailed_action_name, see g_action_parse_detailed_name() and
 * g_action_print_detailed_name().
 *
 * @param detailedActionName a detailed action name, specifying an action
 *     and target to associate accelerators with
 * @param accels a list of accelerators in the format
 *     understood by gtk_accelerator_parse()
 */
- (void)setAccelsForActionWithDetailedActionName:(OFString*)detailedActionName accels:(const gchar* const*)accels;

/**
 * Sets or unsets the application menu for @application.
 * 
 * This can only be done in the primary instance of the application,
 * after it has been registered.  #GApplication::startup is a good place
 * to call this.
 * 
 * The application menu is a single menu containing items that typically
 * impact the application as a whole, rather than acting on a specific
 * window or document.  For example, you would expect to see
 * “Preferences” or “Quit” in an application menu, but not “Save” or
 * “Print”.
 * 
 * If supported, the application menu will be rendered by the desktop
 * environment.
 * 
 * Use the base #GActionMap interface to add actions, to respond to the user
 * selecting these menu items.
 *
 * @param appMenu a #GMenuModel, or %NULL
 */
- (void)setAppMenu:(GMenuModel*)appMenu;

/**
 * Sets or unsets the menubar for windows of @application.
 * 
 * This is a menubar in the traditional sense.
 * 
 * This can only be done in the primary instance of the application,
 * after it has been registered.  #GApplication::startup is a good place
 * to call this.
 * 
 * Depending on the desktop environment, this may appear at the top of
 * each window, or at the top of the screen.  In some environments, if
 * both the application menu and the menubar are set, the application
 * menu will be presented as if it were the first item of the menubar.
 * Other environments treat the two as completely separate — for example,
 * the application menu may be rendered by the desktop shell while the
 * menubar (if set) remains in each individual window.
 * 
 * Use the base #GActionMap interface to add actions, to respond to the
 * user selecting these menu items.
 *
 * @param menubar a #GMenuModel, or %NULL
 */
- (void)setMenubar:(GMenuModel*)menubar;

/**
 * Removes an inhibitor that has been established with gtk_application_inhibit().
 * Inhibitors are also cleared when the application exits.
 *
 * @param cookie a cookie that was returned by gtk_application_inhibit()
 */
- (void)uninhibit:(guint)cookie;

@end