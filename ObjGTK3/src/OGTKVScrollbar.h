/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKScrollbar.h"

@class OGTKWidget;
@class OGTKAdjustment;

/**
 * The #GtkVScrollbar widget is a widget arranged vertically creating a
 * scrollbar. See #GtkScrollbar for details on
 * scrollbars. #GtkAdjustment pointers may be added to handle the
 * adjustment of the scrollbar or it may be left %NULL in which case one
 * will be created for you. See #GtkScrollbar for a description of what the
 * fields in an adjustment represent for a scrollbar.
 * 
 * GtkVScrollbar has been deprecated, use #GtkScrollbar instead.
 *
 */
@interface OGTKVScrollbar : OGTKScrollbar
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKAdjustment*)adjustment;

/**
 * Methods
 */

- (GtkVScrollbar*)VSCROLLBAR;

@end