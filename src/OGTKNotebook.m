/*
 * OGTKNotebook.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKNotebook.h"

@implementation OGTKNotebook

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_notebook_new()];

	return self;
}

- (GtkNotebook*)NOTEBOOK
{
	return GTK_NOTEBOOK([self GOBJECT]);
}

- (gint)appendPageWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel
{
	return gtk_notebook_append_page(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], [tabLabel WIDGET]);
}

- (gint)appendPageMenuWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel andMenuLabel:(OGTKWidget*)menuLabel
{
	return gtk_notebook_append_page_menu(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], [tabLabel WIDGET], [menuLabel WIDGET]);
}

- (void)detachTab:(OGTKWidget*)child
{
	gtk_notebook_detach_tab(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET]);
}

- (OGTKWidget*)getActionWidget:(GtkPackType)packType
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_notebook_get_action_widget(GTK_NOTEBOOK([self GOBJECT]), packType)];
}

- (gint)getCurrentPage
{
	return gtk_notebook_get_current_page(GTK_NOTEBOOK([self GOBJECT]));
}

- (OFString*)getGroupName
{
	return [OFString stringWithUTF8String:gtk_notebook_get_group_name(GTK_NOTEBOOK([self GOBJECT]))];
}

- (OGTKWidget*)getMenuLabel:(OGTKWidget*)child
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_notebook_get_menu_label(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET])];
}

- (OFString*)getMenuLabelText:(OGTKWidget*)child
{
	return [OFString stringWithUTF8String:gtk_notebook_get_menu_label_text(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET])];
}

- (gint)getNpages
{
	return gtk_notebook_get_n_pages(GTK_NOTEBOOK([self GOBJECT]));
}

- (OGTKWidget*)getNthPage:(gint)pageNum
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_notebook_get_nth_page(GTK_NOTEBOOK([self GOBJECT]), pageNum)];
}

- (bool)getScrollable
{
	return gtk_notebook_get_scrollable(GTK_NOTEBOOK([self GOBJECT]));
}

- (bool)getShowBorder
{
	return gtk_notebook_get_show_border(GTK_NOTEBOOK([self GOBJECT]));
}

- (bool)getShowTabs
{
	return gtk_notebook_get_show_tabs(GTK_NOTEBOOK([self GOBJECT]));
}

- (bool)getTabDetachable:(OGTKWidget*)child
{
	return gtk_notebook_get_tab_detachable(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET]);
}

- (guint16)getTabHborder
{
	return gtk_notebook_get_tab_hborder(GTK_NOTEBOOK([self GOBJECT]));
}

- (OGTKWidget*)getTabLabel:(OGTKWidget*)child
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_notebook_get_tab_label(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET])];
}

- (OFString*)getTabLabelText:(OGTKWidget*)child
{
	return [OFString stringWithUTF8String:gtk_notebook_get_tab_label_text(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET])];
}

- (GtkPositionType)getTabPos
{
	return gtk_notebook_get_tab_pos(GTK_NOTEBOOK([self GOBJECT]));
}

- (bool)getTabReorderable:(OGTKWidget*)child
{
	return gtk_notebook_get_tab_reorderable(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET]);
}

- (guint16)getTabVborder
{
	return gtk_notebook_get_tab_vborder(GTK_NOTEBOOK([self GOBJECT]));
}

- (gint)insertPageWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel andPosition:(gint)position
{
	return gtk_notebook_insert_page(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], [tabLabel WIDGET], position);
}

- (gint)insertPageMenuWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel andMenuLabel:(OGTKWidget*)menuLabel andPosition:(gint)position
{
	return gtk_notebook_insert_page_menu(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], [tabLabel WIDGET], [menuLabel WIDGET], position);
}

- (void)nextPage
{
	gtk_notebook_next_page(GTK_NOTEBOOK([self GOBJECT]));
}

- (gint)pageNum:(OGTKWidget*)child
{
	return gtk_notebook_page_num(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET]);
}

- (void)popupDisable
{
	gtk_notebook_popup_disable(GTK_NOTEBOOK([self GOBJECT]));
}

- (void)popupEnable
{
	gtk_notebook_popup_enable(GTK_NOTEBOOK([self GOBJECT]));
}

- (gint)prependPageWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel
{
	return gtk_notebook_prepend_page(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], [tabLabel WIDGET]);
}

- (gint)prependPageMenuWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel andMenuLabel:(OGTKWidget*)menuLabel
{
	return gtk_notebook_prepend_page_menu(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], [tabLabel WIDGET], [menuLabel WIDGET]);
}

- (void)prevPage
{
	gtk_notebook_prev_page(GTK_NOTEBOOK([self GOBJECT]));
}

- (void)removePage:(gint)pageNum
{
	gtk_notebook_remove_page(GTK_NOTEBOOK([self GOBJECT]), pageNum);
}

- (void)reorderChildWithChild:(OGTKWidget*)child andPosition:(gint)position
{
	gtk_notebook_reorder_child(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], position);
}

- (void)setActionWidgetWithWidget:(OGTKWidget*)widget andPackType:(GtkPackType)packType
{
	gtk_notebook_set_action_widget(GTK_NOTEBOOK([self GOBJECT]), [widget WIDGET], packType);
}

- (void)setCurrentPage:(gint)pageNum
{
	gtk_notebook_set_current_page(GTK_NOTEBOOK([self GOBJECT]), pageNum);
}

- (void)setGroupName:(OFString*)groupName
{
	gtk_notebook_set_group_name(GTK_NOTEBOOK([self GOBJECT]), [groupName UTF8String]);
}

- (void)setMenuLabelWithChild:(OGTKWidget*)child andMenuLabel:(OGTKWidget*)menuLabel
{
	gtk_notebook_set_menu_label(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], [menuLabel WIDGET]);
}

- (void)setMenuLabelTextWithChild:(OGTKWidget*)child andMenuText:(OFString*)menuText
{
	gtk_notebook_set_menu_label_text(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], [menuText UTF8String]);
}

- (void)setScrollable:(bool)scrollable
{
	gtk_notebook_set_scrollable(GTK_NOTEBOOK([self GOBJECT]), scrollable);
}

- (void)setShowBorder:(bool)showBorder
{
	gtk_notebook_set_show_border(GTK_NOTEBOOK([self GOBJECT]), showBorder);
}

- (void)setShowTabs:(bool)showTabs
{
	gtk_notebook_set_show_tabs(GTK_NOTEBOOK([self GOBJECT]), showTabs);
}

- (void)setTabDetachableWithChild:(OGTKWidget*)child andDetachable:(bool)detachable
{
	gtk_notebook_set_tab_detachable(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], detachable);
}

- (void)setTabLabelWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel
{
	gtk_notebook_set_tab_label(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], [tabLabel WIDGET]);
}

- (void)setTabLabelTextWithChild:(OGTKWidget*)child andTabText:(OFString*)tabText
{
	gtk_notebook_set_tab_label_text(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], [tabText UTF8String]);
}

- (void)setTabPos:(GtkPositionType)pos
{
	gtk_notebook_set_tab_pos(GTK_NOTEBOOK([self GOBJECT]), pos);
}

- (void)setTabReorderableWithChild:(OGTKWidget*)child andReorderable:(bool)reorderable
{
	gtk_notebook_set_tab_reorderable(GTK_NOTEBOOK([self GOBJECT]), [child WIDGET], reorderable);
}


@end