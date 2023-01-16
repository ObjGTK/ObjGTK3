/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>
#include <gtk/gtk.h>

#import <OGObject/OGObject.h>

@class OGTKAccelGroup;
@class OGTKWidget;
@class OGTKAction;
@class OGTKActionGroup;

/**
 * > GtkUIManager is deprecated since GTK+ 3.10. To construct user interfaces
 * > from XML definitions, you should use #GtkBuilder, #GMenuModel, et al. To
 * > work with actions, use #GAction, #GtkActionable et al. These newer classes
 * > support richer functionality and integration with various desktop shells.
 * > It should be possible to migrate most/all functionality from GtkUIManager.
 * 
 * A #GtkUIManager constructs a user interface (menus and toolbars) from
 * one or more UI definitions, which reference actions from one or more
 * action groups.
 * 
 * # UI Definitions # {#XML-UI}
 * 
 * The UI definitions are specified in an XML format which can be
 * roughly described by the following DTD.
 * 
 * > Do not confuse the GtkUIManager UI Definitions described here with
 * > the similarly named [GtkBuilder UI Definitions][BUILDER-UI].
 * 
 * |[
 * <!ELEMENT ui          (menubar|toolbar|popup|accelerator)* >
 * <!ELEMENT menubar     (menuitem|separator|placeholder|menu)* >
 * <!ELEMENT menu        (menuitem|separator|placeholder|menu)* >
 * <!ELEMENT popup       (menuitem|separator|placeholder|menu)* >
 * <!ELEMENT toolbar     (toolitem|separator|placeholder)* >
 * <!ELEMENT placeholder (menuitem|toolitem|separator|placeholder|menu)* >
 * <!ELEMENT menuitem     EMPTY >
 * <!ELEMENT toolitem     (menu?) >
 * <!ELEMENT separator    EMPTY >
 * <!ELEMENT accelerator  EMPTY >
 * <!ATTLIST menubar      name                      #IMPLIED
 *                        action                    #IMPLIED >
 * <!ATTLIST toolbar      name                      #IMPLIED
 *                        action                    #IMPLIED >
 * <!ATTLIST popup        name                      #IMPLIED
 *                        action                    #IMPLIED
 *                        accelerators (true|false) #IMPLIED >
 * <!ATTLIST placeholder  name                      #IMPLIED
 *                        action                    #IMPLIED >
 * <!ATTLIST separator    name                      #IMPLIED
 *                        action                    #IMPLIED
 *                        expand       (true|false) #IMPLIED >
 * <!ATTLIST menu         name                      #IMPLIED
 *                        action                    #REQUIRED
 *                        position     (top|bot)    #IMPLIED >
 * <!ATTLIST menuitem     name                      #IMPLIED
 *                        action                    #REQUIRED
 *                        position     (top|bot)    #IMPLIED
 *                        always-show-image (true|false) #IMPLIED >
 * <!ATTLIST toolitem     name                      #IMPLIED
 *                        action                    #REQUIRED
 *                        position     (top|bot)    #IMPLIED >
 * <!ATTLIST accelerator  name                      #IMPLIED
 *                        action                    #REQUIRED >
 * ]|
 * 
 * There are some additional restrictions beyond those specified in the
 * DTD, e.g. every toolitem must have a toolbar in its anchestry and
 * every menuitem must have a menubar or popup in its anchestry. Since
 * a #GMarkupParser is used to parse the UI description, it must not only
 * be valid XML, but valid markup.
 * 
 * If a name is not specified, it defaults to the action. If an action is
 * not specified either, the element name is used. The name and action
 * attributes must not contain “/” characters after parsing (since that
 * would mess up path lookup) and must be usable as XML attributes when
 * enclosed in doublequotes, thus they must not “"” characters or references
 * to the &quot; entity.
 * 
 * # A UI definition #
 * 
 * |[
 * <ui>
 *   <menubar>
 *     <menu name="FileMenu" action="FileMenuAction">
 *       <menuitem name="New" action="New2Action" />
 *       <placeholder name="FileMenuAdditions" />
 *     </menu>
 *     <menu name="JustifyMenu" action="JustifyMenuAction">
 *       <menuitem name="Left" action="justify-left"/>
 *       <menuitem name="Centre" action="justify-center"/>
 *       <menuitem name="Right" action="justify-right"/>
 *       <menuitem name="Fill" action="justify-fill"/>
 *     </menu>
 *   </menubar>
 *   <toolbar action="toolbar1">
 *     <placeholder name="JustifyToolItems">
 *       <separator/>
 *       <toolitem name="Left" action="justify-left"/>
 *       <toolitem name="Centre" action="justify-center"/>
 *       <toolitem name="Right" action="justify-right"/>
 *       <toolitem name="Fill" action="justify-fill"/>
 *       <separator/>
 *     </placeholder>
 *   </toolbar>
 * </ui>
 * ]|
 * 
 * The constructed widget hierarchy is very similar to the element tree
 * of the XML, with the exception that placeholders are merged into their
 * parents. The correspondence of XML elements to widgets should be
 * almost obvious:
 * 
 * - menubar
 * 
 *    a #GtkMenuBar
 * 
 * - toolbar
 * 
 *    a #GtkToolbar
 * 
 * - popup
 * 
 *    a toplevel #GtkMenu
 * 
 * - menu
 * 
 *    a #GtkMenu attached to a menuitem
 * 
 * - menuitem
 * 
 *    a #GtkMenuItem subclass, the exact type depends on the action
 * 
 * - toolitem
 * 
 *    a #GtkToolItem subclass, the exact type depends on the
 *    action. Note that toolitem elements may contain a menu element,
 *    but only if their associated action specifies a
 *    #GtkMenuToolButton as proxy.
 * 
 * - separator
 * 
 *    a #GtkSeparatorMenuItem or #GtkSeparatorToolItem
 * 
 * - accelerator
 * 
 *    a keyboard accelerator
 * 
 * The “position” attribute determines where a constructed widget is positioned
 * wrt. to its siblings in the partially constructed tree. If it is
 * “top”, the widget is prepended, otherwise it is appended.
 * 
 * # UI Merging # {#UI-Merging}
 * 
 * The most remarkable feature of #GtkUIManager is that it can overlay a set
 * of menuitems and toolitems over another one, and demerge them later.
 * 
 * Merging is done based on the names of the XML elements. Each element is
 * identified by a path which consists of the names of its anchestors, separated
 * by slashes. For example, the menuitem named “Left” in the example above
 * has the path `/ui/menubar/JustifyMenu/Left` and the
 * toolitem with the same name has path
 * `/ui/toolbar1/JustifyToolItems/Left`.
 * 
 * # Accelerators #
 * 
 * Every action has an accelerator path. Accelerators are installed together
 * with menuitem proxies, but they can also be explicitly added with
 * <accelerator> elements in the UI definition. This makes it possible to
 * have accelerators for actions even if they have no visible proxies.
 * 
 * # Smart Separators # {#Smart-Separators}
 * 
 * The separators created by #GtkUIManager are “smart”, i.e. they do not show up
 * in the UI unless they end up between two visible menu or tool items. Separators
 * which are located at the very beginning or end of the menu or toolbar
 * containing them, or multiple separators next to each other, are hidden. This
 * is a useful feature, since the merging of UI elements from multiple sources
 * can make it hard or impossible to determine in advance whether a separator
 * will end up in such an unfortunate position.
 * 
 * For separators in toolbars, you can set `expand="true"` to
 * turn them from a small, visible separator to an expanding, invisible one.
 * Toolitems following an expanding separator are effectively right-aligned.
 * 
 * # Empty Menus
 * 
 * Submenus pose similar problems to separators inconnection with merging. It is
 * impossible to know in advance whether they will end up empty after merging.
 * #GtkUIManager offers two ways to treat empty submenus:
 * 
 * - make them disappear by hiding the menu item they’re attached to
 * 
 * - add an insensitive “Empty” item
 * 
 * The behaviour is chosen based on the “hide_if_empty” property of the action
 * to which the submenu is associated.
 * 
 * # GtkUIManager as GtkBuildable # {#GtkUIManager-BUILDER-UI}
 * 
 * The GtkUIManager implementation of the GtkBuildable interface accepts
 * GtkActionGroup objects as <child> elements in UI definitions.
 * 
 * A GtkUIManager UI definition as described above can be embedded in
 * an GtkUIManager <object> element in a GtkBuilder UI definition.
 * 
 * The widgets that are constructed by a GtkUIManager can be embedded in
 * other parts of the constructed user interface with the help of the
 * “constructor” attribute. See the example below.
 * 
 * ## An embedded GtkUIManager UI definition
 * 
 * |[
 * <object class="GtkUIManager" id="uiman">
 *   <child>
 *     <object class="GtkActionGroup" id="actiongroup">
 *       <child>
 *         <object class="GtkAction" id="file">
 *           <property name="label">_File</property>
 *         </object>
 *       </child>
 *     </object>
 *   </child>
 *   <ui>
 *     <menubar name="menubar1">
 *       <menu action="file">
 *       </menu>
 *     </menubar>
 *   </ui>
 * </object>
 * <object class="GtkWindow" id="main-window">
 *   <child>
 *     <object class="GtkMenuBar" id="menubar1" constructor="uiman"/>
 *   </child>
 * </object>
 * ]|
 *
 */
@interface OGTKUIManager : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkUIManager*)UIMANAGER;

/**
 * Adds a UI element to the current contents of @manager.
 * 
 * If @type is %GTK_UI_MANAGER_AUTO, GTK+ inserts a menuitem, toolitem or
 * separator if such an element can be inserted at the place determined by
 * @path. Otherwise @type must indicate an element that can be inserted at
 * the place determined by @path.
 * 
 * If @path points to a menuitem or toolitem, the new element will be inserted
 * before or after this item, depending on @top.
 *
 * @param mergeId the merge id for the merged UI, see gtk_ui_manager_new_merge_id()
 * @param path a path
 * @param name the name for the added UI element
 * @param action the name of the action to be proxied, or %NULL to add a separator
 * @param type the type of UI element to add.
 * @param top if %TRUE, the UI element is added before its siblings, otherwise it
 *   is added after its siblings.
 */
- (void)addUiWithMergeId:(guint)mergeId path:(OFString*)path name:(OFString*)name action:(OFString*)action type:(GtkUIManagerItemType)type top:(bool)top;

/**
 * Parses a file containing a [UI definition][XML-UI] and
 * merges it with the current contents of @manager.
 *
 * @param filename the name of the file to parse
 * @param err
 * @return The merge id for the merged UI. The merge id can be used
 *   to unmerge the UI with gtk_ui_manager_remove_ui(). If an error occurred,
 *   the return value is 0.
 */
- (guint)addUiFromFileWithFilename:(OFString*)filename err:(GError**)err;

/**
 * Parses a resource file containing a [UI definition][XML-UI] and
 * merges it with the current contents of @manager.
 *
 * @param resourcePath the resource path of the file to parse
 * @param err
 * @return The merge id for the merged UI. The merge id can be used
 *   to unmerge the UI with gtk_ui_manager_remove_ui(). If an error occurred,
 *   the return value is 0.
 */
- (guint)addUiFromResourceWithResourcePath:(OFString*)resourcePath err:(GError**)err;

/**
 * Parses a string containing a [UI definition][XML-UI] and merges it with
 * the current contents of @manager. An enclosing <ui> element is added if
 * it is missing.
 *
 * @param buffer the string to parse
 * @param length the length of @buffer (may be -1 if @buffer is nul-terminated)
 * @param err
 * @return The merge id for the merged UI. The merge id can be used
 *   to unmerge the UI with gtk_ui_manager_remove_ui(). If an error occurred,
 *   the return value is 0.
 */
- (guint)addUiFromStringWithBuffer:(OFString*)buffer length:(gssize)length err:(GError**)err;

/**
 * Makes sure that all pending updates to the UI have been completed.
 * 
 * This may occasionally be necessary, since #GtkUIManager updates the
 * UI in an idle function. A typical example where this function is
 * useful is to enforce that the menubar and toolbar have been added to
 * the main window before showing it:
 * |[<!-- language="C" -->
 * gtk_container_add (GTK_CONTAINER (window), vbox);
 * g_signal_connect (merge, "add-widget",
 *                   G_CALLBACK (add_widget), vbox);
 * gtk_ui_manager_add_ui_from_file (merge, "my-menus");
 * gtk_ui_manager_add_ui_from_file (merge, "my-toolbars");
 * gtk_ui_manager_ensure_update (merge);
 * gtk_widget_show (window);
 * ]|
 *
 */
- (void)ensureUpdate;

/**
 * Returns the #GtkAccelGroup associated with @manager.
 *
 * @return the #GtkAccelGroup.
 */
- (OGTKAccelGroup*)accelGroup;

/**
 * Looks up an action by following a path. See gtk_ui_manager_get_widget()
 * for more information about paths.
 *
 * @param path a path
 * @return the action whose proxy widget is found by following the path,
 *     or %NULL if no widget was found.
 */
- (OGTKAction*)action:(OFString*)path;

/**
 * Returns the list of action groups associated with @manager.
 *
 * @return a #GList of
 *   action groups. The list is owned by GTK+
 *   and should not be modified.
 */
- (GList*)actionGroups;

/**
 * Returns whether menus generated by this #GtkUIManager
 * will have tearoff menu items.
 *
 * @return whether tearoff menu items are added
 */
- (bool)addTearoffs;

/**
 * Obtains a list of all toplevel widgets of the requested types.
 *
 * @param types specifies the types of toplevel widgets to include. Allowed
 *   types are #GTK_UI_MANAGER_MENUBAR, #GTK_UI_MANAGER_TOOLBAR and
 *   #GTK_UI_MANAGER_POPUP.
 * @return a newly-allocated #GSList of
 * all toplevel widgets of the requested types.  Free the returned list with g_slist_free().
 */
- (GSList*)toplevels:(GtkUIManagerItemType)types;

/**
 * Creates a [UI definition][XML-UI] of the merged UI.
 *
 * @return A newly allocated string containing an XML representation of
 * the merged UI.
 */
- (OFString*)ui;

/**
 * Looks up a widget by following a path.
 * The path consists of the names specified in the XML description of the UI.
 * separated by “/”. Elements which don’t have a name or action attribute in
 * the XML (e.g. <popup>) can be addressed by their XML element name
 * (e.g. "popup"). The root element ("/ui") can be omitted in the path.
 * 
 * Note that the widget found by following a path that ends in a <menu>;
 * element is the menuitem to which the menu is attached, not the menu it
 * manages.
 * 
 * Also note that the widgets constructed by a ui manager are not tied to
 * the lifecycle of the ui manager. If you add the widgets returned by this
 * function to some container or explicitly ref them, they will survive the
 * destruction of the ui manager.
 *
 * @param path a path
 * @return the widget found by following the path,
 *     or %NULL if no widget was found
 */
- (OGTKWidget*)widget:(OFString*)path;

/**
 * Inserts an action group into the list of action groups associated
 * with @manager. Actions in earlier groups hide actions with the same
 * name in later groups.
 * 
 * If @pos is larger than the number of action groups in @manager, or
 * negative, @action_group will be inserted at the end of the internal
 * list.
 *
 * @param actionGroup the action group to be inserted
 * @param pos the position at which the group will be inserted.
 */
- (void)insertActionGroupWithActionGroup:(OGTKActionGroup*)actionGroup pos:(gint)pos;

/**
 * Returns an unused merge id, suitable for use with
 * gtk_ui_manager_add_ui().
 *
 * @return an unused merge id.
 */
- (guint)newMergeId;

/**
 * Removes an action group from the list of action groups associated
 * with @manager.
 *
 * @param actionGroup the action group to be removed
 */
- (void)removeActionGroup:(OGTKActionGroup*)actionGroup;

/**
 * Unmerges the part of @manager's content identified by @merge_id.
 *
 * @param mergeId a merge id as returned by gtk_ui_manager_add_ui_from_string()
 */
- (void)removeUi:(guint)mergeId;

/**
 * Sets the “add_tearoffs” property, which controls whether menus
 * generated by this #GtkUIManager will have tearoff menu items.
 * 
 * Note that this only affects regular menus. Generated popup
 * menus never have tearoff menu items.
 *
 * @param addTearoffs whether tearoff menu items are added
 */
- (void)setAddTearoffs:(bool)addTearoffs;

@end