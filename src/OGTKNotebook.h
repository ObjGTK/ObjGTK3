/*
 * OGTKNotebook.h
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
#import "OGTKContainer.h"

@interface OGTKNotebook : OGTKContainer
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkNotebook*)NOTEBOOK;

/**
 * - (gint*)appendPageWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel;
 *
 * @param child
 * @param tabLabel
 * @returns gint
 */
- (gint)appendPageWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel;

/**
 * - (gint*)appendPageMenuWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel andMenuLabel:(OGTKWidget*)menuLabel;
 *
 * @param child
 * @param tabLabel
 * @param menuLabel
 * @returns gint
 */
- (gint)appendPageMenuWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel andMenuLabel:(OGTKWidget*)menuLabel;

/**
 * - (void*)detachTab:(OGTKWidget*)child;
 *
 * @param child
 */
- (void)detachTab:(OGTKWidget*)child;

/**
 * - (OGTKWidget**)getActionWidget:(GtkPackType)packType;
 *
 * @param packType
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getActionWidget:(GtkPackType)packType;

/**
 * - (gint*)getCurrentPage;
 *
 * @returns gint
 */
- (gint)getCurrentPage;

/**
 * - (OFString**)getGroupName;
 *
 * @returns OFString*
 */
- (OFString*)getGroupName;

/**
 * - (OGTKWidget**)getMenuLabel:(OGTKWidget*)child;
 *
 * @param child
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getMenuLabel:(OGTKWidget*)child;

/**
 * - (OFString**)getMenuLabelText:(OGTKWidget*)child;
 *
 * @param child
 * @returns OFString*
 */
- (OFString*)getMenuLabelText:(OGTKWidget*)child;

/**
 * - (gint*)getNpages;
 *
 * @returns gint
 */
- (gint)getNpages;

/**
 * - (OGTKWidget**)getNthPage:(gint)pageNum;
 *
 * @param pageNum
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getNthPage:(gint)pageNum;

/**
 * - (bool*)getScrollable;
 *
 * @returns bool
 */
- (bool)getScrollable;

/**
 * - (bool*)getShowBorder;
 *
 * @returns bool
 */
- (bool)getShowBorder;

/**
 * - (bool*)getShowTabs;
 *
 * @returns bool
 */
- (bool)getShowTabs;

/**
 * - (bool*)getTabDetachable:(OGTKWidget*)child;
 *
 * @param child
 * @returns bool
 */
- (bool)getTabDetachable:(OGTKWidget*)child;

/**
 * - (guint16*)getTabHborder;
 *
 * @returns guint16
 */
- (guint16)getTabHborder;

/**
 * - (OGTKWidget**)getTabLabel:(OGTKWidget*)child;
 *
 * @param child
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getTabLabel:(OGTKWidget*)child;

/**
 * - (OFString**)getTabLabelText:(OGTKWidget*)child;
 *
 * @param child
 * @returns OFString*
 */
- (OFString*)getTabLabelText:(OGTKWidget*)child;

/**
 * - (GtkPositionType*)getTabPos;
 *
 * @returns GtkPositionType
 */
- (GtkPositionType)getTabPos;

/**
 * - (bool*)getTabReorderable:(OGTKWidget*)child;
 *
 * @param child
 * @returns bool
 */
- (bool)getTabReorderable:(OGTKWidget*)child;

/**
 * - (guint16*)getTabVborder;
 *
 * @returns guint16
 */
- (guint16)getTabVborder;

/**
 * - (gint*)insertPageWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel andPosition:(gint)position;
 *
 * @param child
 * @param tabLabel
 * @param position
 * @returns gint
 */
- (gint)insertPageWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel andPosition:(gint)position;

/**
 * - (gint*)insertPageMenuWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel andMenuLabel:(OGTKWidget*)menuLabel andPosition:(gint)position;
 *
 * @param child
 * @param tabLabel
 * @param menuLabel
 * @param position
 * @returns gint
 */
- (gint)insertPageMenuWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel andMenuLabel:(OGTKWidget*)menuLabel andPosition:(gint)position;

/**
 * - (void*)nextPage;
 *
 */
- (void)nextPage;

/**
 * - (gint*)pageNum:(OGTKWidget*)child;
 *
 * @param child
 * @returns gint
 */
- (gint)pageNum:(OGTKWidget*)child;

/**
 * - (void*)popupDisable;
 *
 */
- (void)popupDisable;

/**
 * - (void*)popupEnable;
 *
 */
- (void)popupEnable;

/**
 * - (gint*)prependPageWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel;
 *
 * @param child
 * @param tabLabel
 * @returns gint
 */
- (gint)prependPageWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel;

/**
 * - (gint*)prependPageMenuWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel andMenuLabel:(OGTKWidget*)menuLabel;
 *
 * @param child
 * @param tabLabel
 * @param menuLabel
 * @returns gint
 */
- (gint)prependPageMenuWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel andMenuLabel:(OGTKWidget*)menuLabel;

/**
 * - (void*)prevPage;
 *
 */
- (void)prevPage;

/**
 * - (void*)removePage:(gint)pageNum;
 *
 * @param pageNum
 */
- (void)removePage:(gint)pageNum;

/**
 * - (void*)reorderChildWithChild:(OGTKWidget*)child andPosition:(gint)position;
 *
 * @param child
 * @param position
 */
- (void)reorderChildWithChild:(OGTKWidget*)child andPosition:(gint)position;

/**
 * - (void*)setActionWidgetWithWidget:(OGTKWidget*)widget andPackType:(GtkPackType)packType;
 *
 * @param widget
 * @param packType
 */
- (void)setActionWidgetWithWidget:(OGTKWidget*)widget andPackType:(GtkPackType)packType;

/**
 * - (void*)setCurrentPage:(gint)pageNum;
 *
 * @param pageNum
 */
- (void)setCurrentPage:(gint)pageNum;

/**
 * - (void*)setGroupName:(OFString*)groupName;
 *
 * @param groupName
 */
- (void)setGroupName:(OFString*)groupName;

/**
 * - (void*)setMenuLabelWithChild:(OGTKWidget*)child andMenuLabel:(OGTKWidget*)menuLabel;
 *
 * @param child
 * @param menuLabel
 */
- (void)setMenuLabelWithChild:(OGTKWidget*)child andMenuLabel:(OGTKWidget*)menuLabel;

/**
 * - (void*)setMenuLabelTextWithChild:(OGTKWidget*)child andMenuText:(OFString*)menuText;
 *
 * @param child
 * @param menuText
 */
- (void)setMenuLabelTextWithChild:(OGTKWidget*)child andMenuText:(OFString*)menuText;

/**
 * - (void*)setScrollable:(bool)scrollable;
 *
 * @param scrollable
 */
- (void)setScrollable:(bool)scrollable;

/**
 * - (void*)setShowBorder:(bool)showBorder;
 *
 * @param showBorder
 */
- (void)setShowBorder:(bool)showBorder;

/**
 * - (void*)setShowTabs:(bool)showTabs;
 *
 * @param showTabs
 */
- (void)setShowTabs:(bool)showTabs;

/**
 * - (void*)setTabDetachableWithChild:(OGTKWidget*)child andDetachable:(bool)detachable;
 *
 * @param child
 * @param detachable
 */
- (void)setTabDetachableWithChild:(OGTKWidget*)child andDetachable:(bool)detachable;

/**
 * - (void*)setTabLabelWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel;
 *
 * @param child
 * @param tabLabel
 */
- (void)setTabLabelWithChild:(OGTKWidget*)child andTabLabel:(OGTKWidget*)tabLabel;

/**
 * - (void*)setTabLabelTextWithChild:(OGTKWidget*)child andTabText:(OFString*)tabText;
 *
 * @param child
 * @param tabText
 */
- (void)setTabLabelTextWithChild:(OGTKWidget*)child andTabText:(OFString*)tabText;

/**
 * - (void*)setTabPos:(GtkPositionType)pos;
 *
 * @param pos
 */
- (void)setTabPos:(GtkPositionType)pos;

/**
 * - (void*)setTabReorderableWithChild:(OGTKWidget*)child andReorderable:(bool)reorderable;
 *
 * @param child
 * @param reorderable
 */
- (void)setTabReorderableWithChild:(OGTKWidget*)child andReorderable:(bool)reorderable;

@end