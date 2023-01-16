/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKWidget;
@class OGTKAdjustment;
@class OGGdkWindow;

/**
 * The #GtkViewport widget acts as an adaptor class, implementing
 * scrollability for child widgets that lack their own scrolling
 * capabilities. Use GtkViewport to scroll child widgets such as
 * #GtkGrid, #GtkBox, and so on.
 * 
 * If a widget has native scrolling abilities, such as #GtkTextView,
 * #GtkTreeView or #GtkIconView, it can be added to a #GtkScrolledWindow
 * with gtk_container_add(). If a widget does not, you must first add the
 * widget to a #GtkViewport, then add the viewport to the scrolled window.
 * gtk_container_add() does this automatically if a child that does not
 * implement #GtkScrollable is added to a #GtkScrolledWindow, so you can
 * ignore the presence of the viewport.
 * 
 * The GtkViewport will start scrolling content only if allocated less
 * than the child widget’s minimum size in a given orientation.
 * 
 * # CSS nodes
 * 
 * GtkViewport has a single CSS node with name viewport.
 *
 */
@interface OGTKViewport : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)initWithHadjustment:(OGTKAdjustment*)hadjustment vadjustment:(OGTKAdjustment*)vadjustment;

/**
 * Methods
 */

- (GtkViewport*)VIEWPORT;

/**
 * Gets the bin window of the #GtkViewport.
 *
 * @return a #GdkWindow
 */
- (OGGdkWindow*)binWindow;

/**
 * Returns the horizontal adjustment of the viewport.
 *
 * @return the horizontal adjustment of @viewport.
 */
- (OGTKAdjustment*)hadjustment;

/**
 * Gets the shadow type of the #GtkViewport. See
 * gtk_viewport_set_shadow_type().
 *
 * @return the shadow type
 */
- (GtkShadowType)shadowType;

/**
 * Returns the vertical adjustment of the viewport.
 *
 * @return the vertical adjustment of @viewport.
 */
- (OGTKAdjustment*)vadjustment;

/**
 * Gets the view window of the #GtkViewport.
 *
 * @return a #GdkWindow
 */
- (OGGdkWindow*)viewWindow;

/**
 * Sets the horizontal adjustment of the viewport.
 *
 * @param adjustment a #GtkAdjustment.
 */
- (void)setHadjustment:(OGTKAdjustment*)adjustment;

/**
 * Sets the shadow type of the viewport.
 *
 * @param type the new shadow type.
 */
- (void)setShadowType:(GtkShadowType)type;

/**
 * Sets the vertical adjustment of the viewport.
 *
 * @param adjustment a #GtkAdjustment.
 */
- (void)setVadjustment:(OGTKAdjustment*)adjustment;

@end