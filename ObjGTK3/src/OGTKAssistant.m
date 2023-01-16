/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAssistant.h"

#import <OGGdkPixbuf/OGGdkPixbuf.h>
#import "OGTKWidget.h"

@implementation OGTKAssistant

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_assistant_new()];

	return self;
}

- (GtkAssistant*)ASSISTANT
{
	return GTK_ASSISTANT([self GOBJECT]);
}

- (void)addActionWidget:(OGTKWidget*)child
{
	gtk_assistant_add_action_widget([self ASSISTANT], [child WIDGET]);
}

- (gint)appendPage:(OGTKWidget*)page
{
	return gtk_assistant_append_page([self ASSISTANT], [page WIDGET]);
}

- (void)commit
{
	gtk_assistant_commit([self ASSISTANT]);
}

- (gint)currentPage
{
	return gtk_assistant_get_current_page([self ASSISTANT]);
}

- (gint)npages
{
	return gtk_assistant_get_n_pages([self ASSISTANT]);
}

- (OGTKWidget*)nthPage:(gint)pageNum
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_assistant_get_nth_page([self ASSISTANT], pageNum)] autorelease];
}

- (bool)pageComplete:(OGTKWidget*)page
{
	return gtk_assistant_get_page_complete([self ASSISTANT], [page WIDGET]);
}

- (bool)pageHasPadding:(OGTKWidget*)page
{
	return gtk_assistant_get_page_has_padding([self ASSISTANT], [page WIDGET]);
}

- (OGGdkPixbuf*)pageHeaderImage:(OGTKWidget*)page
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_assistant_get_page_header_image([self ASSISTANT], [page WIDGET])] autorelease];
}

- (OGGdkPixbuf*)pageSideImage:(OGTKWidget*)page
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_assistant_get_page_side_image([self ASSISTANT], [page WIDGET])] autorelease];
}

- (OFString*)pageTitle:(OGTKWidget*)page
{
	return [OFString stringWithUTF8String:gtk_assistant_get_page_title([self ASSISTANT], [page WIDGET])];
}

- (GtkAssistantPageType)pageType:(OGTKWidget*)page
{
	return gtk_assistant_get_page_type([self ASSISTANT], [page WIDGET]);
}

- (gint)insertPageWithPage:(OGTKWidget*)page position:(gint)position
{
	return gtk_assistant_insert_page([self ASSISTANT], [page WIDGET], position);
}

- (void)nextPage
{
	gtk_assistant_next_page([self ASSISTANT]);
}

- (gint)prependPage:(OGTKWidget*)page
{
	return gtk_assistant_prepend_page([self ASSISTANT], [page WIDGET]);
}

- (void)previousPage
{
	gtk_assistant_previous_page([self ASSISTANT]);
}

- (void)removeActionWidget:(OGTKWidget*)child
{
	gtk_assistant_remove_action_widget([self ASSISTANT], [child WIDGET]);
}

- (void)removePage:(gint)pageNum
{
	gtk_assistant_remove_page([self ASSISTANT], pageNum);
}

- (void)setCurrentPage:(gint)pageNum
{
	gtk_assistant_set_current_page([self ASSISTANT], pageNum);
}

- (void)setForwardPageFuncWithPageFunc:(GtkAssistantPageFunc)pageFunc data:(gpointer)data destroy:(GDestroyNotify)destroy
{
	gtk_assistant_set_forward_page_func([self ASSISTANT], pageFunc, data, destroy);
}

- (void)setPageCompleteWithPage:(OGTKWidget*)page complete:(bool)complete
{
	gtk_assistant_set_page_complete([self ASSISTANT], [page WIDGET], complete);
}

- (void)setPageHasPaddingWithPage:(OGTKWidget*)page hasPadding:(bool)hasPadding
{
	gtk_assistant_set_page_has_padding([self ASSISTANT], [page WIDGET], hasPadding);
}

- (void)setPageHeaderImageWithPage:(OGTKWidget*)page pixbuf:(OGGdkPixbuf*)pixbuf
{
	gtk_assistant_set_page_header_image([self ASSISTANT], [page WIDGET], [pixbuf PIXBUF]);
}

- (void)setPageSideImageWithPage:(OGTKWidget*)page pixbuf:(OGGdkPixbuf*)pixbuf
{
	gtk_assistant_set_page_side_image([self ASSISTANT], [page WIDGET], [pixbuf PIXBUF]);
}

- (void)setPageTitleWithPage:(OGTKWidget*)page title:(OFString*)title
{
	gtk_assistant_set_page_title([self ASSISTANT], [page WIDGET], [title UTF8String]);
}

- (void)setPageTypeWithPage:(OGTKWidget*)page type:(GtkAssistantPageType)type
{
	gtk_assistant_set_page_type([self ASSISTANT], [page WIDGET], type);
}

- (void)updateButtonsState
{
	gtk_assistant_update_buttons_state([self ASSISTANT]);
}


@end