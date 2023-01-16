/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>
#include <gtk/gtk.h>

#import <OGdk3/OGGdkWindow.h>

@class OGTKWidget;
@class OGGdkPixbuf;

/**
 * A #GtkAssistant is a widget used to represent a generally complex
 * operation splitted in several steps, guiding the user through its
 * pages and controlling the page flow to collect the necessary data.
 * 
 * The design of GtkAssistant is that it controls what buttons to show
 * and to make sensitive, based on what it knows about the page sequence
 * and the [type][GtkAssistantPageType] of each page,
 * in addition to state information like the page
 * [completion][gtk-assistant-set-page-complete]
 * and [committed][gtk-assistant-commit] status.
 * 
 * If you have a case that doesn’t quite fit in #GtkAssistants way of
 * handling buttons, you can use the #GTK_ASSISTANT_PAGE_CUSTOM page
 * type and handle buttons yourself.
 * 
 * # GtkAssistant as GtkBuildable
 * 
 * The GtkAssistant implementation of the #GtkBuildable interface
 * exposes the @action_area as internal children with the name
 * “action_area”.
 * 
 * To add pages to an assistant in #GtkBuilder, simply add it as a
 * child to the GtkAssistant object, and set its child properties
 * as necessary.
 * 
 * # CSS nodes
 * 
 * GtkAssistant has a single CSS node with the name assistant.
 *
 */
@interface OGTKAssistant : OGGdkWindow
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkAssistant*)ASSISTANT;

/**
 * Adds a widget to the action area of a #GtkAssistant.
 *
 * @param child a #GtkWidget
 */
- (void)addActionWidget:(OGTKWidget*)child;

/**
 * Appends a page to the @assistant.
 *
 * @param page a #GtkWidget
 * @return the index (starting at 0) of the inserted page
 */
- (gint)appendPage:(OGTKWidget*)page;

/**
 * Erases the visited page history so the back button is not
 * shown on the current page, and removes the cancel button
 * from subsequent pages.
 * 
 * Use this when the information provided up to the current
 * page is hereafter deemed permanent and cannot be modified
 * or undone. For example, showing a progress page to track
 * a long-running, unreversible operation after the user has
 * clicked apply on a confirmation page.
 *
 */
- (void)commit;

/**
 * Returns the page number of the current page.
 *
 * @return The index (starting from 0) of the current
 *     page in the @assistant, or -1 if the @assistant has no pages,
 *     or no current page.
 */
- (gint)currentPage;

/**
 * Returns the number of pages in the @assistant
 *
 * @return the number of pages in the @assistant
 */
- (gint)npages;

/**
 * Returns the child widget contained in page number @page_num.
 *
 * @param pageNum the index of a page in the @assistant,
 *     or -1 to get the last page
 * @return the child widget, or %NULL
 *     if @page_num is out of bounds
 */
- (OGTKWidget*)nthPage:(gint)pageNum;

/**
 * Gets whether @page is complete.
 *
 * @param page a page of @assistant
 * @return %TRUE if @page is complete.
 */
- (bool)pageComplete:(OGTKWidget*)page;

/**
 * Gets whether page has padding.
 *
 * @param page a page of @assistant
 * @return %TRUE if @page has padding
 */
- (bool)pageHasPadding:(OGTKWidget*)page;

/**
 * Gets the header image for @page.
 *
 * @param page a page of @assistant
 * @return the header image for @page,
 *     or %NULL if there’s no header image for the page
 */
- (OGGdkPixbuf*)pageHeaderImage:(OGTKWidget*)page;

/**
 * Gets the side image for @page.
 *
 * @param page a page of @assistant
 * @return the side image for @page,
 *     or %NULL if there’s no side image for the page
 */
- (OGGdkPixbuf*)pageSideImage:(OGTKWidget*)page;

/**
 * Gets the title for @page.
 *
 * @param page a page of @assistant
 * @return the title for @page
 */
- (OFString*)pageTitle:(OGTKWidget*)page;

/**
 * Gets the page type of @page.
 *
 * @param page a page of @assistant
 * @return the page type of @page
 */
- (GtkAssistantPageType)pageType:(OGTKWidget*)page;

/**
 * Inserts a page in the @assistant at a given position.
 *
 * @param page a #GtkWidget
 * @param position the index (starting at 0) at which to insert the page,
 *     or -1 to append the page to the @assistant
 * @return the index (starting from 0) of the inserted page
 */
- (gint)insertPageWithPage:(OGTKWidget*)page position:(gint)position;

/**
 * Navigate to the next page.
 * 
 * It is a programming error to call this function when
 * there is no next page.
 * 
 * This function is for use when creating pages of the
 * #GTK_ASSISTANT_PAGE_CUSTOM type.
 *
 */
- (void)nextPage;

/**
 * Prepends a page to the @assistant.
 *
 * @param page a #GtkWidget
 * @return the index (starting at 0) of the inserted page
 */
- (gint)prependPage:(OGTKWidget*)page;

/**
 * Navigate to the previous visited page.
 * 
 * It is a programming error to call this function when
 * no previous page is available.
 * 
 * This function is for use when creating pages of the
 * #GTK_ASSISTANT_PAGE_CUSTOM type.
 *
 */
- (void)previousPage;

/**
 * Removes a widget from the action area of a #GtkAssistant.
 *
 * @param child a #GtkWidget
 */
- (void)removeActionWidget:(OGTKWidget*)child;

/**
 * Removes the @page_num’s page from @assistant.
 *
 * @param pageNum the index of a page in the @assistant,
 *     or -1 to remove the last page
 */
- (void)removePage:(gint)pageNum;

/**
 * Switches the page to @page_num.
 * 
 * Note that this will only be necessary in custom buttons,
 * as the @assistant flow can be set with
 * gtk_assistant_set_forward_page_func().
 *
 * @param pageNum index of the page to switch to, starting from 0.
 *     If negative, the last page will be used. If greater
 *     than the number of pages in the @assistant, nothing
 *     will be done.
 */
- (void)setCurrentPage:(gint)pageNum;

/**
 * Sets the page forwarding function to be @page_func.
 * 
 * This function will be used to determine what will be
 * the next page when the user presses the forward button.
 * Setting @page_func to %NULL will make the assistant to
 * use the default forward function, which just goes to the
 * next visible page.
 *
 * @param pageFunc the #GtkAssistantPageFunc, or %NULL
 *     to use the default one
 * @param data user data for @page_func
 * @param destroy destroy notifier for @data
 */
- (void)setForwardPageFuncWithPageFunc:(GtkAssistantPageFunc)pageFunc data:(gpointer)data destroy:(GDestroyNotify)destroy;

/**
 * Sets whether @page contents are complete.
 * 
 * This will make @assistant update the buttons state
 * to be able to continue the task.
 *
 * @param page a page of @assistant
 * @param complete the completeness status of the page
 */
- (void)setPageCompleteWithPage:(OGTKWidget*)page complete:(bool)complete;

/**
 * Sets whether the assistant is adding padding around
 * the page.
 *
 * @param page a page of @assistant
 * @param hasPadding whether this page has padding
 */
- (void)setPageHasPaddingWithPage:(OGTKWidget*)page hasPadding:(bool)hasPadding;

/**
 * Sets a header image for @page.
 *
 * @param page a page of @assistant
 * @param pixbuf the new header image @page
 */
- (void)setPageHeaderImageWithPage:(OGTKWidget*)page pixbuf:(OGGdkPixbuf*)pixbuf;

/**
 * Sets a side image for @page.
 * 
 * This image used to be displayed in the side area of the assistant
 * when @page is the current page.
 *
 * @param page a page of @assistant
 * @param pixbuf the new side image @page
 */
- (void)setPageSideImageWithPage:(OGTKWidget*)page pixbuf:(OGGdkPixbuf*)pixbuf;

/**
 * Sets a title for @page.
 * 
 * The title is displayed in the header area of the assistant
 * when @page is the current page.
 *
 * @param page a page of @assistant
 * @param title the new title for @page
 */
- (void)setPageTitleWithPage:(OGTKWidget*)page title:(OFString*)title;

/**
 * Sets the page type for @page.
 * 
 * The page type determines the page behavior in the @assistant.
 *
 * @param page a page of @assistant
 * @param type the new type for @page
 */
- (void)setPageTypeWithPage:(OGTKWidget*)page type:(GtkAssistantPageType)type;

/**
 * Forces @assistant to recompute the buttons state.
 * 
 * GTK+ automatically takes care of this in most situations,
 * e.g. when the user goes to a different page, or when the
 * visibility or completeness of a page changes.
 * 
 * One situation where it can be necessary to call this
 * function is when changing a value on the current page
 * affects the future page flow of the assistant.
 *
 */
- (void)updateButtonsState;

@end