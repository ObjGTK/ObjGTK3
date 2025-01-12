/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtkx.h>
#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>

#import <OGAtk/OGAtkObject.h>

@class OGTKWidget;
@class OGTKNotebookAccessible;

@interface OGTKNotebookPageAccessible : OGAtkObject
{

}


/**
 * Constructors
 */
- (instancetype)initWithNotebook:(OGTKNotebookAccessible*)notebook child:(OGTKWidget*)child;

/**
 * Methods
 */

- (GtkNotebookPageAccessible*)NOTEBOOKPAGEACCESSIBLE;

/**
 *
 */
- (void)invalidate;

@end