/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKNotebookPageAccessible.h"

#import "OGTKWidget.h"
#import "OGTKNotebookAccessible.h"

@implementation OGTKNotebookPageAccessible

- (instancetype)initWithNotebook:(OGTKNotebookAccessible*)notebook child:(OGTKWidget*)child
{
	self = [super initWithGObject:(GObject*)gtk_notebook_page_accessible_new([notebook NOTEBOOKACCESSIBLE], [child WIDGET])];

	return self;
}

- (GtkNotebookPageAccessible*)NOTEBOOKPAGEACCESSIBLE
{
	return GTK_NOTEBOOK_PAGE_ACCESSIBLE([self GOBJECT]);
}

- (void)invalidate
{
	gtk_notebook_page_accessible_invalidate([self NOTEBOOKPAGEACCESSIBLE]);
}


@end