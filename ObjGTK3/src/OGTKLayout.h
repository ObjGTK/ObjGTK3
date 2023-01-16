/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKAdjustment;
@class OGTKWidget;
@class OGGdkWindow;

/**
 * #GtkLayout is similar to #GtkDrawingArea in that it’s a “blank slate” and
 * doesn’t do anything except paint a blank background by default. It’s
 * different in that it supports scrolling natively due to implementing
 * #GtkScrollable, and can contain child widgets since it’s a #GtkContainer.
 * 
 * If you just want to draw, a #GtkDrawingArea is a better choice since it has
 * lower overhead. If you just need to position child widgets at specific
 * points, then #GtkFixed provides that functionality on its own.
 * 
 * When handling expose events on a #GtkLayout, you must draw to the #GdkWindow
 * returned by gtk_layout_get_bin_window(), rather than to the one returned by
 * gtk_widget_get_window() as you would for a #GtkDrawingArea.
 *
 */
@interface OGTKLayout : OGTKContainer
{

}


/**
 * Constructors
 */
- (instancetype)initWithHadjustment:(OGTKAdjustment*)hadjustment vadjustment:(OGTKAdjustment*)vadjustment;

/**
 * Methods
 */

- (GtkLayout*)LAYOUT;

/**
 * Retrieve the bin window of the layout used for drawing operations.
 *
 * @return a #GdkWindow
 */
- (OGGdkWindow*)binWindow;

/**
 * This function should only be called after the layout has been
 * placed in a #GtkScrolledWindow or otherwise configured for
 * scrolling. It returns the #GtkAdjustment used for communication
 * between the horizontal scrollbar and @layout.
 * 
 * See #GtkScrolledWindow, #GtkScrollbar, #GtkAdjustment for details.
 *
 * @return horizontal scroll adjustment
 */
- (OGTKAdjustment*)hadjustment;

/**
 * Gets the size that has been set on the layout, and that determines
 * the total extents of the layout’s scrollbar area. See
 * gtk_layout_set_size ().
 *
 * @param width location to store the width set on
 *     @layout, or %NULL
 * @param height location to store the height set on
 *     @layout, or %NULL
 */
- (void)sizeWithWidth:(guint*)width height:(guint*)height;

/**
 * This function should only be called after the layout has been
 * placed in a #GtkScrolledWindow or otherwise configured for
 * scrolling. It returns the #GtkAdjustment used for communication
 * between the vertical scrollbar and @layout.
 * 
 * See #GtkScrolledWindow, #GtkScrollbar, #GtkAdjustment for details.
 *
 * @return vertical scroll adjustment
 */
- (OGTKAdjustment*)vadjustment;

/**
 * Moves a current child of @layout to a new position.
 *
 * @param childWidget a current child of @layout
 * @param x X position to move to
 * @param y Y position to move to
 */
- (void)moveWithChildWidget:(OGTKWidget*)childWidget x:(gint)x y:(gint)y;

/**
 * Adds @child_widget to @layout, at position (@x,@y).
 * @layout becomes the new parent container of @child_widget.
 *
 * @param childWidget child widget
 * @param x X position of child widget
 * @param y Y position of child widget
 */
- (void)putWithChildWidget:(OGTKWidget*)childWidget x:(gint)x y:(gint)y;

/**
 * Sets the horizontal scroll adjustment for the layout.
 * 
 * See #GtkScrolledWindow, #GtkScrollbar, #GtkAdjustment for details.
 *
 * @param adjustment new scroll adjustment
 */
- (void)setHadjustment:(OGTKAdjustment*)adjustment;

/**
 * Sets the size of the scrollable area of the layout.
 *
 * @param width width of entire scrollable area
 * @param height height of entire scrollable area
 */
- (void)setSizeWithWidth:(guint)width height:(guint)height;

/**
 * Sets the vertical scroll adjustment for the layout.
 * 
 * See #GtkScrolledWindow, #GtkScrollbar, #GtkAdjustment for details.
 *
 * @param adjustment new scroll adjustment
 */
- (void)setVadjustment:(OGTKAdjustment*)adjustment;

@end