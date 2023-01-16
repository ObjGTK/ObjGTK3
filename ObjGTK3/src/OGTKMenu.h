/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenuShell.h"

@class OGTKAccelGroup;
@class OGGdkDevice;
@class OGTKWidget;
@class OGGdkMonitor;
@class OGGdkWindow;
@class OGGdkScreen;

/**
 * A #GtkMenu is a #GtkMenuShell that implements a drop down menu
 * consisting of a list of #GtkMenuItem objects which can be navigated
 * and activated by the user to perform application functions.
 * 
 * A #GtkMenu is most commonly dropped down by activating a
 * #GtkMenuItem in a #GtkMenuBar or popped up by activating a
 * #GtkMenuItem in another #GtkMenu.
 * 
 * A #GtkMenu can also be popped up by activating a #GtkComboBox.
 * Other composite widgets such as the #GtkNotebook can pop up a
 * #GtkMenu as well.
 * 
 * Applications can display a #GtkMenu as a popup menu by calling the
 * gtk_menu_popup() function.  The example below shows how an application
 * can pop up a menu when the 3rd mouse button is pressed.
 * 
 * ## Connecting the popup signal handler.
 * 
 * |[<!-- language="C" -->
 *   // connect our handler which will popup the menu
 *   g_signal_connect_swapped (window, "button_press_event",
 * G_CALLBACK (my_popup_handler), menu);
 * ]|
 * 
 * ## Signal handler which displays a popup menu.
 * 
 * |[<!-- language="C" -->
 * static gint
 * my_popup_handler (GtkWidget *widget, GdkEvent *event)
 * {
 *   GtkMenu *menu;
 *   GdkEventButton *event_button;
 * 
 *   g_return_val_if_fail (widget != NULL, FALSE);
 *   g_return_val_if_fail (GTK_IS_MENU (widget), FALSE);
 *   g_return_val_if_fail (event != NULL, FALSE);
 * 
 *   // The "widget" is the menu that was supplied when
 *   // g_signal_connect_swapped() was called.
 *   menu = GTK_MENU (widget);
 * 
 *   if (event->type == GDK_BUTTON_PRESS)
 *     {
 *       event_button = (GdkEventButton *) event;
 *       if (event_button->button == GDK_BUTTON_SECONDARY)
 *         {
 *           gtk_menu_popup (menu, NULL, NULL, NULL, NULL,
 *                           event_button->button, event_button->time);
 *           return TRUE;
 *         }
 *     }
 * 
 *   return FALSE;
 * }
 * ]|
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * menu
 * ├── arrow.top
 * ├── <child>
 * ┊
 * ├── <child>
 * ╰── arrow.bottom
 * ]|
 * 
 * The main CSS node of GtkMenu has name menu, and there are two subnodes
 * with name arrow, for scrolling menu arrows. These subnodes get the
 * .top and .bottom style classes.
 *
 */
@interface OGTKMenu : OGTKMenuShell
{

}

/**
 * Functions
 */

/**
 * Returns a list of the menus which are attached to this widget.
 * This list is owned by GTK+ and must not be modified.
 *
 * @param widget a #GtkWidget
 * @return the list
 *     of menus attached to his widget.
 */
+ (GList*)forAttachWidget:(OGTKWidget*)widget;

/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initFromModel:(GMenuModel*)model;

/**
 * Methods
 */

- (GtkMenu*)MENU;

/**
 * Adds a new #GtkMenuItem to a (table) menu. The number of “cells” that
 * an item will occupy is specified by @left_attach, @right_attach,
 * @top_attach and @bottom_attach. These each represent the leftmost,
 * rightmost, uppermost and lower column and row numbers of the table.
 * (Columns and rows are indexed from zero).
 * 
 * Note that this function is not related to gtk_menu_detach().
 *
 * @param child a #GtkMenuItem
 * @param leftAttach The column number to attach the left side of the item to
 * @param rightAttach The column number to attach the right side of the item to
 * @param topAttach The row number to attach the top of the item to
 * @param bottomAttach The row number to attach the bottom of the item to
 */
- (void)attachWithChild:(OGTKWidget*)child leftAttach:(guint)leftAttach rightAttach:(guint)rightAttach topAttach:(guint)topAttach bottomAttach:(guint)bottomAttach;

/**
 * Attaches the menu to the widget and provides a callback function
 * that will be invoked when the menu calls gtk_menu_detach() during
 * its destruction.
 * 
 * If the menu is attached to the widget then it will be destroyed
 * when the widget is destroyed, as if it was a child widget.
 * An attached menu will also move between screens correctly if the
 * widgets moves between screens.
 *
 * @param attachWidget the #GtkWidget that the menu will be attached to
 * @param detacher the user supplied callback function
 *             that will be called when the menu calls gtk_menu_detach()
 */
- (void)attachToWidgetWithAttachWidget:(OGTKWidget*)attachWidget detacher:(GtkMenuDetachFunc)detacher;

/**
 * Detaches the menu from the widget to which it had been attached.
 * This function will call the callback function, @detacher, provided
 * when the gtk_menu_attach_to_widget() function was called.
 *
 */
- (void)detach;

/**
 * Gets the #GtkAccelGroup which holds global accelerators for the
 * menu. See gtk_menu_set_accel_group().
 *
 * @return the #GtkAccelGroup associated with the menu
 */
- (OGTKAccelGroup*)accelGroup;

/**
 * Retrieves the accelerator path set on the menu.
 *
 * @return the accelerator path set on the menu.
 */
- (OFString*)accelPath;

/**
 * Returns the selected menu item from the menu.  This is used by the
 * #GtkComboBox.
 *
 * @return the #GtkMenuItem that was last selected
 *          in the menu.  If a selection has not yet been made, the
 *          first menu item is selected.
 */
- (OGTKWidget*)active;

/**
 * Returns the #GtkWidget that the menu is attached to.
 *
 * @return the #GtkWidget that the menu is attached to
 */
- (OGTKWidget*)attachWidget;

/**
 * Retrieves the number of the monitor on which to show the menu.
 *
 * @return the number of the monitor on which the menu should
 *    be popped up or -1, if no monitor has been set
 */
- (gint)monitor;

/**
 * Returns whether the menu reserves space for toggles and
 * icons, regardless of their actual presence.
 *
 * @return Whether the menu reserves toggle space
 */
- (bool)reserveToggleSize;

/**
 * Returns whether the menu is torn off.
 * See gtk_menu_set_tearoff_state().
 *
 * @return %TRUE if the menu is currently torn off.
 */
- (bool)tearoffState;

/**
 * Returns the title of the menu. See gtk_menu_set_title().
 *
 * @return the title of the menu, or %NULL if the menu
 *     has no title set on it. This string is owned by GTK+
 *     and should not be modified or freed.
 */
- (OFString*)title;

/**
 * Places @menu on the given monitor.
 *
 * @param monitor the monitor to place the menu on
 */
- (void)placeOnMonitor:(OGGdkMonitor*)monitor;

/**
 * Removes the menu from the screen.
 *
 */
- (void)popdown;

/**
 * Displays a menu and makes it available for selection.
 * 
 * Applications can use this function to display context-sensitive
 * menus, and will typically supply %NULL for the @parent_menu_shell,
 * @parent_menu_item, @func and @data parameters. The default menu
 * positioning function will position the menu at the current mouse
 * cursor position.
 * 
 * The @button parameter should be the mouse button pressed to initiate
 * the menu popup. If the menu popup was initiated by something other
 * than a mouse button press, such as a mouse button release or a keypress,
 * @button should be 0.
 * 
 * The @activate_time parameter is used to conflict-resolve initiation
 * of concurrent requests for mouse/keyboard grab requests. To function
 * properly, this needs to be the timestamp of the user event (such as
 * a mouse click or key press) that caused the initiation of the popup.
 * Only if no such event is available, gtk_get_current_event_time() can
 * be used instead.
 * 
 * Note that this function does not work very well on GDK backends that
 * do not have global coordinates, such as Wayland or Mir. You should
 * probably use one of the gtk_menu_popup_at_ variants, which do not
 * have this problem.
 *
 * @param parentMenuShell the menu shell containing the
 *     triggering menu item, or %NULL
 * @param parentMenuItem the menu item whose activation
 *     triggered the popup, or %NULL
 * @param func a user supplied function used to position
 *     the menu, or %NULL
 * @param data user supplied data to be passed to @func.
 * @param button the mouse button which was pressed to initiate the event.
 * @param activateTime the time at which the activation event occurred.
 */
- (void)popupWithParentMenuShell:(OGTKWidget*)parentMenuShell parentMenuItem:(OGTKWidget*)parentMenuItem func:(GtkMenuPositionFunc)func data:(gpointer)data button:(guint)button activateTime:(guint32)activateTime;

/**
 * Displays @menu and makes it available for selection.
 * 
 * See gtk_menu_popup_at_widget () to pop up a menu at a widget.
 * gtk_menu_popup_at_rect () also allows you to position a menu at an arbitrary
 * rectangle.
 * 
 * @menu will be positioned at the pointer associated with @trigger_event.
 * 
 * Properties that influence the behaviour of this function are
 * #GtkMenu:anchor-hints, #GtkMenu:rect-anchor-dx, #GtkMenu:rect-anchor-dy, and
 * #GtkMenu:menu-type-hint. Connect to the #GtkMenu::popped-up signal to find
 * out how it was actually positioned.
 *
 * @param triggerEvent the #GdkEvent that initiated this request or
 *                 %NULL if it's the current event
 */
- (void)popupAtPointer:(const GdkEvent*)triggerEvent;

/**
 * Displays @menu and makes it available for selection.
 * 
 * See gtk_menu_popup_at_widget () and gtk_menu_popup_at_pointer (), which
 * handle more common cases for popping up menus.
 * 
 * @menu will be positioned at @rect, aligning their anchor points. @rect is
 * relative to the top-left corner of @rect_window. @rect_anchor and
 * @menu_anchor determine anchor points on @rect and @menu to pin together.
 * @menu can optionally be offset by #GtkMenu:rect-anchor-dx and
 * #GtkMenu:rect-anchor-dy.
 * 
 * Anchors should be specified under the assumption that the text direction is
 * left-to-right; they will be flipped horizontally automatically if the text
 * direction is right-to-left.
 * 
 * Other properties that influence the behaviour of this function are
 * #GtkMenu:anchor-hints and #GtkMenu:menu-type-hint. Connect to the
 * #GtkMenu::popped-up signal to find out how it was actually positioned.
 *
 * @param rectWindow the #GdkWindow @rect is relative to
 * @param rect the #GdkRectangle to align @menu with
 * @param rectAnchor the point on @rect to align with @menu's anchor point
 * @param menuAnchor the point on @menu to align with @rect's anchor point
 * @param triggerEvent the #GdkEvent that initiated this request or
 *                 %NULL if it's the current event
 */
- (void)popupAtRectWithRectWindow:(OGGdkWindow*)rectWindow rect:(const GdkRectangle*)rect rectAnchor:(GdkGravity)rectAnchor menuAnchor:(GdkGravity)menuAnchor triggerEvent:(const GdkEvent*)triggerEvent;

/**
 * Displays @menu and makes it available for selection.
 * 
 * See gtk_menu_popup_at_pointer () to pop up a menu at the master pointer.
 * gtk_menu_popup_at_rect () also allows you to position a menu at an arbitrary
 * rectangle.
 * 
 * ![](popup-anchors.png)
 * 
 * @menu will be positioned at @widget, aligning their anchor points.
 * @widget_anchor and @menu_anchor determine anchor points on @widget and @menu
 * to pin together. @menu can optionally be offset by #GtkMenu:rect-anchor-dx
 * and #GtkMenu:rect-anchor-dy.
 * 
 * Anchors should be specified under the assumption that the text direction is
 * left-to-right; they will be flipped horizontally automatically if the text
 * direction is right-to-left.
 * 
 * Other properties that influence the behaviour of this function are
 * #GtkMenu:anchor-hints and #GtkMenu:menu-type-hint. Connect to the
 * #GtkMenu::popped-up signal to find out how it was actually positioned.
 *
 * @param widget the #GtkWidget to align @menu with
 * @param widgetAnchor the point on @widget to align with @menu's anchor point
 * @param menuAnchor the point on @menu to align with @widget's anchor point
 * @param triggerEvent the #GdkEvent that initiated this request or
 *                 %NULL if it's the current event
 */
- (void)popupAtWidgetWithWidget:(OGTKWidget*)widget widgetAnchor:(GdkGravity)widgetAnchor menuAnchor:(GdkGravity)menuAnchor triggerEvent:(const GdkEvent*)triggerEvent;

/**
 * Displays a menu and makes it available for selection.
 * 
 * Applications can use this function to display context-sensitive menus,
 * and will typically supply %NULL for the @parent_menu_shell,
 * @parent_menu_item, @func, @data and @destroy parameters. The default
 * menu positioning function will position the menu at the current position
 * of @device (or its corresponding pointer).
 * 
 * The @button parameter should be the mouse button pressed to initiate
 * the menu popup. If the menu popup was initiated by something other than
 * a mouse button press, such as a mouse button release or a keypress,
 * @button should be 0.
 * 
 * The @activate_time parameter is used to conflict-resolve initiation of
 * concurrent requests for mouse/keyboard grab requests. To function
 * properly, this needs to be the time stamp of the user event (such as
 * a mouse click or key press) that caused the initiation of the popup.
 * Only if no such event is available, gtk_get_current_event_time() can
 * be used instead.
 * 
 * Note that this function does not work very well on GDK backends that
 * do not have global coordinates, such as Wayland or Mir. You should
 * probably use one of the gtk_menu_popup_at_ variants, which do not
 * have this problem.
 *
 * @param device a #GdkDevice
 * @param parentMenuShell the menu shell containing the triggering
 *     menu item, or %NULL
 * @param parentMenuItem the menu item whose activation triggered
 *     the popup, or %NULL
 * @param func a user supplied function used to position the menu,
 *     or %NULL
 * @param data user supplied data to be passed to @func
 * @param destroy destroy notify for @data
 * @param button the mouse button which was pressed to initiate the event
 * @param activateTime the time at which the activation event occurred
 */
- (void)popupForDeviceWithDevice:(OGGdkDevice*)device parentMenuShell:(OGTKWidget*)parentMenuShell parentMenuItem:(OGTKWidget*)parentMenuItem func:(GtkMenuPositionFunc)func data:(gpointer)data destroy:(GDestroyNotify)destroy button:(guint)button activateTime:(guint32)activateTime;

/**
 * Moves @child to a new @position in the list of @menu
 * children.
 *
 * @param child the #GtkMenuItem to move
 * @param position the new position to place @child.
 *     Positions are numbered from 0 to n - 1
 */
- (void)reorderChildWithChild:(OGTKWidget*)child position:(gint)position;

/**
 * Repositions the menu according to its position function.
 *
 */
- (void)reposition;

/**
 * Set the #GtkAccelGroup which holds global accelerators for the
 * menu.  This accelerator group needs to also be added to all windows
 * that this menu is being used in with gtk_window_add_accel_group(),
 * in order for those windows to support all the accelerators
 * contained in this group.
 *
 * @param accelGroup the #GtkAccelGroup to be associated
 *               with the menu.
 */
- (void)setAccelGroup:(OGTKAccelGroup*)accelGroup;

/**
 * Sets an accelerator path for this menu from which accelerator paths
 * for its immediate children, its menu items, can be constructed.
 * The main purpose of this function is to spare the programmer the
 * inconvenience of having to call gtk_menu_item_set_accel_path() on
 * each menu item that should support runtime user changable accelerators.
 * Instead, by just calling gtk_menu_set_accel_path() on their parent,
 * each menu item of this menu, that contains a label describing its
 * purpose, automatically gets an accel path assigned.
 * 
 * For example, a menu containing menu items “New” and “Exit”, will, after
 * `gtk_menu_set_accel_path (menu, "<Gnumeric-Sheet>/File");` has been
 * called, assign its items the accel paths: `"<Gnumeric-Sheet>/File/New"`
 * and `"<Gnumeric-Sheet>/File/Exit"`.
 * 
 * Assigning accel paths to menu items then enables the user to change
 * their accelerators at runtime. More details about accelerator paths
 * and their default setups can be found at gtk_accel_map_add_entry().
 * 
 * Note that @accel_path string will be stored in a #GQuark. Therefore,
 * if you pass a static string, you can save some memory by interning
 * it first with g_intern_static_string().
 *
 * @param accelPath a valid accelerator path, or %NULL to unset the path
 */
- (void)setAccelPath:(OFString*)accelPath;

/**
 * Selects the specified menu item within the menu.  This is used by
 * the #GtkComboBox and should not be used by anyone else.
 *
 * @param index the index of the menu item to select.  Index values are
 *         from 0 to n-1
 */
- (void)setActive:(guint)index;

/**
 * Informs GTK+ on which monitor a menu should be popped up.
 * See gdk_monitor_get_geometry().
 * 
 * This function should be called from a #GtkMenuPositionFunc
 * if the menu should not appear on the same monitor as the pointer.
 * This information can’t be reliably inferred from the coordinates
 * returned by a #GtkMenuPositionFunc, since, for very long menus,
 * these coordinates may extend beyond the monitor boundaries or even
 * the screen boundaries.
 *
 * @param monitorNum the number of the monitor on which the menu should
 *    be popped up
 */
- (void)setMonitor:(gint)monitorNum;

/**
 * Sets whether the menu should reserve space for drawing toggles
 * or icons, regardless of their actual presence.
 *
 * @param reserveToggleSize whether to reserve size for toggles
 */
- (void)setReserveToggleSize:(bool)reserveToggleSize;

/**
 * Sets the #GdkScreen on which the menu will be displayed.
 *
 * @param screen a #GdkScreen, or %NULL if the screen should be
 *          determined by the widget the menu is attached to
 */
- (void)setScreen:(OGGdkScreen*)screen;

/**
 * Changes the tearoff state of the menu.  A menu is normally
 * displayed as drop down menu which persists as long as the menu is
 * active.  It can also be displayed as a tearoff menu which persists
 * until it is closed or reattached.
 *
 * @param tornOff If %TRUE, menu is displayed as a tearoff menu.
 */
- (void)setTearoffState:(bool)tornOff;

/**
 * Sets the title string for the menu.
 * 
 * The title is displayed when the menu is shown as a tearoff
 * menu. If @title is %NULL, the menu will see if it is attached
 * to a parent menu item, and if so it will try to use the same
 * text as that menu item’s label.
 *
 * @param title a string containing the title for the menu, or %NULL to
 *   inherit the title of the parent menu item, if any
 */
- (void)setTitle:(OFString*)title;

@end