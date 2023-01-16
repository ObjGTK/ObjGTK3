/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKNotebook.h"

#import "OGTKWidget.h"

@implementation OGTKNotebook

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_notebook_new()];

	return self;
}

- (GtkNotebook*)NOTEBOOK
{
	return GTK_NOTEBOOK([self GOBJECT]);
}

- (gint)appendPageWithChild:(OGTKWidget*)child tabLabel:(OGTKWidget*)tabLabel
{
	return gtk_notebook_append_page([self NOTEBOOK], [child WIDGET], [tabLabel WIDGET]);
}

- (gint)appendPageMenuWithChild:(OGTKWidget*)child tabLabel:(OGTKWidget*)tabLabel menuLabel:(OGTKWidget*)menuLabel
{
	return gtk_notebook_append_page_menu([self NOTEBOOK], [child WIDGET], [tabLabel WIDGET], [menuLabel WIDGET]);
}

- (void)detachTab:(OGTKWidget*)child
{
	gtk_notebook_detach_tab([self NOTEBOOK], [child WIDGET]);
}

- (OGTKWidget*)actionWidget:(GtkPackType)packType
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_notebook_get_action_widget([self NOTEBOOK], packType)] autorelease];
}

- (gint)currentPage
{
	return gtk_notebook_get_current_page([self NOTEBOOK]);
}

- (OFString*)groupName
{
	return [OFString stringWithUTF8String:gtk_notebook_get_group_name([self NOTEBOOK])];
}

- (OGTKWidget*)menuLabel:(OGTKWidget*)child
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_notebook_get_menu_label([self NOTEBOOK], [child WIDGET])] autorelease];
}

- (OFString*)menuLabelText:(OGTKWidget*)child
{
	return [OFString stringWithUTF8String:gtk_notebook_get_menu_label_text([self NOTEBOOK], [child WIDGET])];
}

- (gint)npages
{
	return gtk_notebook_get_n_pages([self NOTEBOOK]);
}

- (OGTKWidget*)nthPage:(gint)pageNum
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_notebook_get_nth_page([self NOTEBOOK], pageNum)] autorelease];
}

- (bool)scrollable
{
	return gtk_notebook_get_scrollable([self NOTEBOOK]);
}

- (bool)showBorder
{
	return gtk_notebook_get_show_border([self NOTEBOOK]);
}

- (bool)showTabs
{
	return gtk_notebook_get_show_tabs([self NOTEBOOK]);
}

- (bool)tabDetachable:(OGTKWidget*)child
{
	return gtk_notebook_get_tab_detachable([self NOTEBOOK], [child WIDGET]);
}

- (guint16)tabHborder
{
	return gtk_notebook_get_tab_hborder([self NOTEBOOK]);
}

- (OGTKWidget*)tabLabel:(OGTKWidget*)child
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_notebook_get_tab_label([self NOTEBOOK], [child WIDGET])] autorelease];
}

- (OFString*)tabLabelText:(OGTKWidget*)child
{
	return [OFString stringWithUTF8String:gtk_notebook_get_tab_label_text([self NOTEBOOK], [child WIDGET])];
}

- (GtkPositionType)tabPos
{
	return gtk_notebook_get_tab_pos([self NOTEBOOK]);
}

- (bool)tabReorderable:(OGTKWidget*)child
{
	return gtk_notebook_get_tab_reorderable([self NOTEBOOK], [child WIDGET]);
}

- (guint16)tabVborder
{
	return gtk_notebook_get_tab_vborder([self NOTEBOOK]);
}

- (gint)insertPageWithChild:(OGTKWidget*)child tabLabel:(OGTKWidget*)tabLabel position:(gint)position
{
	return gtk_notebook_insert_page([self NOTEBOOK], [child WIDGET], [tabLabel WIDGET], position);
}

- (gint)insertPageMenuWithChild:(OGTKWidget*)child tabLabel:(OGTKWidget*)tabLabel menuLabel:(OGTKWidget*)menuLabel position:(gint)position
{
	return gtk_notebook_insert_page_menu([self NOTEBOOK], [child WIDGET], [tabLabel WIDGET], [menuLabel WIDGET], position);
}

- (void)nextPage
{
	gtk_notebook_next_page([self NOTEBOOK]);
}

- (gint)pageNum:(OGTKWidget*)child
{
	return gtk_notebook_page_num([self NOTEBOOK], [child WIDGET]);
}

- (void)popupDisable
{
	gtk_notebook_popup_disable([self NOTEBOOK]);
}

- (void)popupEnable
{
	gtk_notebook_popup_enable([self NOTEBOOK]);
}

- (gint)prependPageWithChild:(OGTKWidget*)child tabLabel:(OGTKWidget*)tabLabel
{
	return gtk_notebook_prepend_page([self NOTEBOOK], [child WIDGET], [tabLabel WIDGET]);
}

- (gint)prependPageMenuWithChild:(OGTKWidget*)child tabLabel:(OGTKWidget*)tabLabel menuLabel:(OGTKWidget*)menuLabel
{
	return gtk_notebook_prepend_page_menu([self NOTEBOOK], [child WIDGET], [tabLabel WIDGET], [menuLabel WIDGET]);
}

- (void)prevPage
{
	gtk_notebook_prev_page([self NOTEBOOK]);
}

- (void)removePage:(gint)pageNum
{
	gtk_notebook_remove_page([self NOTEBOOK], pageNum);
}

- (void)reorderChildWithChild:(OGTKWidget*)child position:(gint)position
{
	gtk_notebook_reorder_child([self NOTEBOOK], [child WIDGET], position);
}

- (void)setActionWidgetWithWidget:(OGTKWidget*)widget packType:(GtkPackType)packType
{
	gtk_notebook_set_action_widget([self NOTEBOOK], [widget WIDGET], packType);
}

- (void)setCurrentPage:(gint)pageNum
{
	gtk_notebook_set_current_page([self NOTEBOOK], pageNum);
}

- (void)setGroupName:(OFString*)groupName
{
	gtk_notebook_set_group_name([self NOTEBOOK], [groupName UTF8String]);
}

- (void)setMenuLabelWithChild:(OGTKWidget*)child menuLabel:(OGTKWidget*)menuLabel
{
	gtk_notebook_set_menu_label([self NOTEBOOK], [child WIDGET], [menuLabel WIDGET]);
}

- (void)setMenuLabelTextWithChild:(OGTKWidget*)child menuText:(OFString*)menuText
{
	gtk_notebook_set_menu_label_text([self NOTEBOOK], [child WIDGET], [menuText UTF8String]);
}

- (void)setScrollable:(bool)scrollable
{
	gtk_notebook_set_scrollable([self NOTEBOOK], scrollable);
}

- (void)setShowBorder:(bool)showBorder
{
	gtk_notebook_set_show_border([self NOTEBOOK], showBorder);
}

- (void)setShowTabs:(bool)showTabs
{
	gtk_notebook_set_show_tabs([self NOTEBOOK], showTabs);
}

- (void)setTabDetachableWithChild:(OGTKWidget*)child detachable:(bool)detachable
{
	gtk_notebook_set_tab_detachable([self NOTEBOOK], [child WIDGET], detachable);
}

- (void)setTabLabelWithChild:(OGTKWidget*)child tabLabel:(OGTKWidget*)tabLabel
{
	gtk_notebook_set_tab_label([self NOTEBOOK], [child WIDGET], [tabLabel WIDGET]);
}

- (void)setTabLabelTextWithChild:(OGTKWidget*)child tabText:(OFString*)tabText
{
	gtk_notebook_set_tab_label_text([self NOTEBOOK], [child WIDGET], [tabText UTF8String]);
}

- (void)setTabPos:(GtkPositionType)pos
{
	gtk_notebook_set_tab_pos([self NOTEBOOK], pos);
}

- (void)setTabReorderableWithChild:(OGTKWidget*)child reorderable:(bool)reorderable
{
	gtk_notebook_set_tab_reorderable([self NOTEBOOK], [child WIDGET], reorderable);
}


@end