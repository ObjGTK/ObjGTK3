/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKScrollbar.h"

@class OGTKAdjustment;
@class OGTKWidget;

/**
 * The #GtkHScrollbar widget is a widget arranged horizontally creating a
 * scrollbar. See #GtkScrollbar for details on
 * scrollbars. #GtkAdjustment pointers may be added to handle the
 * adjustment of the scrollbar or it may be left %NULL in which case one
 * will be created for you. See #GtkScrollbar for a description of what the
 * fields in an adjustment represent for a scrollbar.
 * 
 * GtkHScrollbar has been deprecated, use #GtkScrollbar instead.
 *
 */
@interface OGTKHScrollbar : OGTKScrollbar
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKAdjustment*)adjustment;

/**
 * Methods
 */

- (GtkHScrollbar*)HSCROLLBAR;

@end