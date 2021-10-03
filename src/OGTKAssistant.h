/*
 * OGTKAssistant.h
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
#import "OGTKWindow.h"

@interface OGTKAssistant : OGTKWindow
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkAssistant*)ASSISTANT;

/**
 * - (void*)addActionWidget:(OGTKWidget*)child;
 *
 * @param child
 */
- (void)addActionWidget:(OGTKWidget*)child;

/**
 * - (gint*)appendPage:(OGTKWidget*)page;
 *
 * @param page
 * @returns gint
 */
- (gint)appendPage:(OGTKWidget*)page;

/**
 * - (void*)commit;
 *
 */
- (void)commit;

/**
 * - (gint*)getCurrentPage;
 *
 * @returns gint
 */
- (gint)getCurrentPage;

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
 * - (bool*)getPageComplete:(OGTKWidget*)page;
 *
 * @param page
 * @returns bool
 */
- (bool)getPageComplete:(OGTKWidget*)page;

/**
 * - (bool*)getPageHasPadding:(OGTKWidget*)page;
 *
 * @param page
 * @returns bool
 */
- (bool)getPageHasPadding:(OGTKWidget*)page;

/**
 * - (GdkPixbuf**)getPageHeaderImage:(OGTKWidget*)page;
 *
 * @param page
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)getPageHeaderImage:(OGTKWidget*)page;

/**
 * - (GdkPixbuf**)getPageSideImage:(OGTKWidget*)page;
 *
 * @param page
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)getPageSideImage:(OGTKWidget*)page;

/**
 * - (OFString**)getPageTitle:(OGTKWidget*)page;
 *
 * @param page
 * @returns OFString*
 */
- (OFString*)getPageTitle:(OGTKWidget*)page;

/**
 * - (GtkAssistantPageType*)getPageType:(OGTKWidget*)page;
 *
 * @param page
 * @returns GtkAssistantPageType
 */
- (GtkAssistantPageType)getPageType:(OGTKWidget*)page;

/**
 * - (gint*)insertPageWithPage:(OGTKWidget*)page andPosition:(gint)position;
 *
 * @param page
 * @param position
 * @returns gint
 */
- (gint)insertPageWithPage:(OGTKWidget*)page andPosition:(gint)position;

/**
 * - (void*)nextPage;
 *
 */
- (void)nextPage;

/**
 * - (gint*)prependPage:(OGTKWidget*)page;
 *
 * @param page
 * @returns gint
 */
- (gint)prependPage:(OGTKWidget*)page;

/**
 * - (void*)previousPage;
 *
 */
- (void)previousPage;

/**
 * - (void*)removeActionWidget:(OGTKWidget*)child;
 *
 * @param child
 */
- (void)removeActionWidget:(OGTKWidget*)child;

/**
 * - (void*)removePage:(gint)pageNum;
 *
 * @param pageNum
 */
- (void)removePage:(gint)pageNum;

/**
 * - (void*)setCurrentPage:(gint)pageNum;
 *
 * @param pageNum
 */
- (void)setCurrentPage:(gint)pageNum;

/**
 * - (void*)setForwardPageFuncWithPageFunc:(GtkAssistantPageFunc)pageFunc andData:(gpointer)data andDestroy:(GDestroyNotify)destroy;
 *
 * @param pageFunc
 * @param data
 * @param destroy
 */
- (void)setForwardPageFuncWithPageFunc:(GtkAssistantPageFunc)pageFunc andData:(gpointer)data andDestroy:(GDestroyNotify)destroy;

/**
 * - (void*)setPageCompleteWithPage:(OGTKWidget*)page andComplete:(bool)complete;
 *
 * @param page
 * @param complete
 */
- (void)setPageCompleteWithPage:(OGTKWidget*)page andComplete:(bool)complete;

/**
 * - (void*)setPageHasPaddingWithPage:(OGTKWidget*)page andHasPadding:(bool)hasPadding;
 *
 * @param page
 * @param hasPadding
 */
- (void)setPageHasPaddingWithPage:(OGTKWidget*)page andHasPadding:(bool)hasPadding;

/**
 * - (void*)setPageHeaderImageWithPage:(OGTKWidget*)page andPixbuf:(GdkPixbuf*)pixbuf;
 *
 * @param page
 * @param pixbuf
 */
- (void)setPageHeaderImageWithPage:(OGTKWidget*)page andPixbuf:(GdkPixbuf*)pixbuf;

/**
 * - (void*)setPageSideImageWithPage:(OGTKWidget*)page andPixbuf:(GdkPixbuf*)pixbuf;
 *
 * @param page
 * @param pixbuf
 */
- (void)setPageSideImageWithPage:(OGTKWidget*)page andPixbuf:(GdkPixbuf*)pixbuf;

/**
 * - (void*)setPageTitleWithPage:(OGTKWidget*)page andTitle:(OFString*)title;
 *
 * @param page
 * @param title
 */
- (void)setPageTitleWithPage:(OGTKWidget*)page andTitle:(OFString*)title;

/**
 * - (void*)setPageTypeWithPage:(OGTKWidget*)page andType:(GtkAssistantPageType)type;
 *
 * @param page
 * @param type
 */
- (void)setPageTypeWithPage:(OGTKWidget*)page andType:(GtkAssistantPageType)type;

/**
 * - (void*)updateButtonsState;
 *
 */
- (void)updateButtonsState;

@end