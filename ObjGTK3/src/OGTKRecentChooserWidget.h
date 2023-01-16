/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

@class OGTKRecentManager;
@class OGTKWidget;

/**
 * #GtkRecentChooserWidget is a widget suitable for selecting recently used
 * files.  It is the main building block of a #GtkRecentChooserDialog.  Most
 * applications will only need to use the latter; you can use
 * #GtkRecentChooserWidget as part of a larger window if you have special needs.
 * 
 * Note that #GtkRecentChooserWidget does not have any methods of its own.
 * Instead, you should use the functions that work on a #GtkRecentChooser.
 * 
 * Recently used files are supported since GTK+ 2.10.
 *
 */
@interface OGTKRecentChooserWidget : OGTKBox
{

}


/**
 * Constructors
 */
- (instancetype)init;
- (instancetype)initForManager:(OGTKRecentManager*)manager;

/**
 * Methods
 */

- (GtkRecentChooserWidget*)RECENTCHOOSERWIDGET;

@end