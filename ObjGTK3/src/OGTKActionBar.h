/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKWidget;

/**
 * GtkActionBar is designed to present contextual actions. It is
 * expected to be displayed below the content and expand horizontally
 * to fill the area.
 * 
 * It allows placing children at the start or the end. In addition, it
 * contains an internal centered box which is centered with respect to
 * the full width of the box, even if the children at either side take
 * up different amounts of space.
 * 
 * # CSS nodes
 * 
 * GtkActionBar has a single CSS node with name actionbar.
 *
 */
@interface OGTKActionBar : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkActionBar*)ACTIONBAR;

/**
 * Retrieves the center bar widget of the bar.
 *
 * @return the center #GtkWidget or %NULL.
 */
- (OGTKWidget*)centerWidget;

/**
 * Adds @child to @action_bar, packed with reference to the
 * end of the @action_bar.
 *
 * @param child the #GtkWidget to be added to @action_bar
 */
- (void)packEnd:(OGTKWidget*)child;

/**
 * Adds @child to @action_bar, packed with reference to the
 * start of the @action_bar.
 *
 * @param child the #GtkWidget to be added to @action_bar
 */
- (void)packStart:(OGTKWidget*)child;

/**
 * Sets the center widget for the #GtkActionBar.
 *
 * @param centerWidget a widget to use for the center
 */
- (void)setCenterWidget:(OGTKWidget*)centerWidget;

@end