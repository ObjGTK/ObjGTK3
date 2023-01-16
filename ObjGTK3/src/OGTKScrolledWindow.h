/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKAdjustment;
@class OGTKWidget;

/**
 * GtkScrolledWindow is a container that accepts a single child widget, makes
 * that child scrollable using either internally added scrollbars or externally
 * associated adjustments, and optionally draws a frame around the child.
 * 
 * Widgets with native scrolling support, i.e. those whose classes implement the
 * #GtkScrollable interface, are added directly. For other types of widget, the
 * class #GtkViewport acts as an adaptor, giving scrollability to other widgets.
 * GtkScrolledWindow’s implementation of gtk_container_add() intelligently
 * accounts for whether or not the added child is a #GtkScrollable. If it isn’t,
 * #GtkScrolledWindow wraps the child in a #GtkViewport and adds that for you.
 * Therefore, you can just add any child widget and not worry about the details.
 * 
 * If gtk_container_add() has added a #GtkViewport for you, you can remove
 * both your added child widget from the #GtkViewport, and the #GtkViewport
 * from the GtkScrolledWindow, like this:
 * 
 * |[<!-- language="C" -->
 * GtkWidget *scrolled_window = gtk_scrolled_window_new (NULL, NULL);
 * GtkWidget *child_widget = gtk_button_new ();
 * 
 * // GtkButton is not a GtkScrollable, so GtkScrolledWindow will automatically
 * // add a GtkViewport.
 * gtk_container_add (GTK_CONTAINER (scrolled_window),
 *                    child_widget);
 * 
 * // Either of these will result in child_widget being unparented:
 * gtk_container_remove (GTK_CONTAINER (scrolled_window),
 *                       child_widget);
 * // or
 * gtk_container_remove (GTK_CONTAINER (scrolled_window),
 *                       gtk_bin_get_child (GTK_BIN (scrolled_window)));
 * ]|
 * 
 * Unless #GtkScrolledWindow:policy is GTK_POLICY_NEVER or GTK_POLICY_EXTERNAL,
 * GtkScrolledWindow adds internal #GtkScrollbar widgets around its child. The
 * scroll position of the child, and if applicable the scrollbars, is controlled
 * by the #GtkScrolledWindow:hadjustment and #GtkScrolledWindow:vadjustment
 * that are associated with the GtkScrolledWindow. See the docs on #GtkScrollbar
 * for the details, but note that the “step_increment” and “page_increment”
 * fields are only effective if the policy causes scrollbars to be present.
 * 
 * If a GtkScrolledWindow doesn’t behave quite as you would like, or
 * doesn’t have exactly the right layout, it’s very possible to set up
 * your own scrolling with #GtkScrollbar and for example a #GtkGrid.
 * 
 * # Touch support
 * 
 * GtkScrolledWindow has built-in support for touch devices. When a
 * touchscreen is used, swiping will move the scrolled window, and will
 * expose 'kinetic' behavior. This can be turned off with the
 * #GtkScrolledWindow:kinetic-scrolling property if it is undesired.
 * 
 * GtkScrolledWindow also displays visual 'overshoot' indication when
 * the content is pulled beyond the end, and this situation can be
 * captured with the #GtkScrolledWindow::edge-overshot signal.
 * 
 * If no mouse device is present, the scrollbars will overlayed as
 * narrow, auto-hiding indicators over the content. If traditional
 * scrollbars are desired although no mouse is present, this behaviour
 * can be turned off with the #GtkScrolledWindow:overlay-scrolling
 * property.
 * 
 * # CSS nodes
 * 
 * GtkScrolledWindow has a main CSS node with name scrolledwindow.
 * 
 * It uses subnodes with names overshoot and undershoot to
 * draw the overflow and underflow indications. These nodes get
 * the .left, .right, .top or .bottom style class added depending
 * on where the indication is drawn.
 * 
 * GtkScrolledWindow also sets the positional style classes (.left,
 * .right, .top, .bottom) and style classes related to overlay
 * scrolling (.overlay-indicator, .dragging, .hovering) on its scrollbars.
 * 
 * If both scrollbars are visible, the area where they meet is drawn
 * with a subnode named junction.
 *
 */
@interface OGTKScrolledWindow : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)initWithHadjustment:(OGTKAdjustment*)hadjustment vadjustment:(OGTKAdjustment*)vadjustment;

/**
 * Methods
 */

- (GtkScrolledWindow*)SCROLLEDWINDOW;

/**
 * Used to add children without native scrolling capabilities. This
 * is simply a convenience function; it is equivalent to adding the
 * unscrollable child to a viewport, then adding the viewport to the
 * scrolled window. If a child has native scrolling, use
 * gtk_container_add() instead of this function.
 * 
 * The viewport scrolls the child by moving its #GdkWindow, and takes
 * the size of the child to be the size of its toplevel #GdkWindow.
 * This will be very wrong for most widgets that support native scrolling;
 * for example, if you add a widget such as #GtkTreeView with a viewport,
 * the whole widget will scroll, including the column headings. Thus,
 * widgets with native scrolling support should not be used with the
 * #GtkViewport proxy.
 * 
 * A widget supports scrolling natively if it implements the
 * #GtkScrollable interface.
 *
 * @param child the widget you want to scroll
 */
- (void)addWithViewport:(OGTKWidget*)child;

/**
 * Return whether button presses are captured during kinetic
 * scrolling. See gtk_scrolled_window_set_capture_button_press().
 *
 * @return %TRUE if button presses are captured during kinetic scrolling
 */
- (bool)captureButtonPress;

/**
 * Returns the horizontal scrollbar’s adjustment, used to connect the
 * horizontal scrollbar to the child widget’s horizontal scroll
 * functionality.
 *
 * @return the horizontal #GtkAdjustment
 */
- (OGTKAdjustment*)hadjustment;

/**
 * Returns the horizontal scrollbar of @scrolled_window.
 *
 * @return the horizontal scrollbar of the scrolled window.
 */
- (OGTKWidget*)hscrollbar;

/**
 * Returns the specified kinetic scrolling behavior.
 *
 * @return the scrolling behavior flags.
 */
- (bool)kineticScrolling;

/**
 * Returns the maximum content height set.
 *
 * @return the maximum content height, or -1
 */
- (gint)maxContentHeight;

/**
 * Returns the maximum content width set.
 *
 * @return the maximum content width, or -1
 */
- (gint)maxContentWidth;

/**
 * Gets the minimal content height of @scrolled_window, or -1 if not set.
 *
 * @return the minimal content height
 */
- (gint)minContentHeight;

/**
 * Gets the minimum content width of @scrolled_window, or -1 if not set.
 *
 * @return the minimum content width
 */
- (gint)minContentWidth;

/**
 * Returns whether overlay scrolling is enabled for this scrolled window.
 *
 * @return %TRUE if overlay scrolling is enabled
 */
- (bool)overlayScrolling;

/**
 * Gets the placement of the contents with respect to the scrollbars
 * for the scrolled window. See gtk_scrolled_window_set_placement().
 *
 * @return the current placement value.
 * 
 * See also gtk_scrolled_window_set_placement() and
 * gtk_scrolled_window_unset_placement().
 */
- (GtkCornerType)placement;

/**
 * Retrieves the current policy values for the horizontal and vertical
 * scrollbars. See gtk_scrolled_window_set_policy().
 *
 * @param hscrollbarPolicy location to store the policy
 *     for the horizontal scrollbar, or %NULL
 * @param vscrollbarPolicy location to store the policy
 *     for the vertical scrollbar, or %NULL
 */
- (void)policyWithHscrollbarPolicy:(GtkPolicyType*)hscrollbarPolicy vscrollbarPolicy:(GtkPolicyType*)vscrollbarPolicy;

/**
 * Reports whether the natural height of the child will be calculated and propagated
 * through the scrolled window’s requested natural height.
 *
 * @return whether natural height propagation is enabled.
 */
- (bool)propagateNaturalHeight;

/**
 * Reports whether the natural width of the child will be calculated and propagated
 * through the scrolled window’s requested natural width.
 *
 * @return whether natural width propagation is enabled.
 */
- (bool)propagateNaturalWidth;

/**
 * Gets the shadow type of the scrolled window. See
 * gtk_scrolled_window_set_shadow_type().
 *
 * @return the current shadow type
 */
- (GtkShadowType)shadowType;

/**
 * Returns the vertical scrollbar’s adjustment, used to connect the
 * vertical scrollbar to the child widget’s vertical scroll functionality.
 *
 * @return the vertical #GtkAdjustment
 */
- (OGTKAdjustment*)vadjustment;

/**
 * Returns the vertical scrollbar of @scrolled_window.
 *
 * @return the vertical scrollbar of the scrolled window.
 */
- (OGTKWidget*)vscrollbar;

/**
 * Changes the behaviour of @scrolled_window with regard to the initial
 * event that possibly starts kinetic scrolling. When @capture_button_press
 * is set to %TRUE, the event is captured by the scrolled window, and
 * then later replayed if it is meant to go to the child widget.
 * 
 * This should be enabled if any child widgets perform non-reversible
 * actions on #GtkWidget::button-press-event. If they don't, and handle
 * additionally handle #GtkWidget::grab-broken-event, it might be better
 * to set @capture_button_press to %FALSE.
 * 
 * This setting only has an effect if kinetic scrolling is enabled.
 *
 * @param captureButtonPress %TRUE to capture button presses
 */
- (void)setCaptureButtonPress:(bool)captureButtonPress;

/**
 * Sets the #GtkAdjustment for the horizontal scrollbar.
 *
 * @param hadjustment the #GtkAdjustment to use, or %NULL to create a new one
 */
- (void)setHadjustment:(OGTKAdjustment*)hadjustment;

/**
 * Turns kinetic scrolling on or off.
 * Kinetic scrolling only applies to devices with source
 * %GDK_SOURCE_TOUCHSCREEN.
 *
 * @param kineticScrolling %TRUE to enable kinetic scrolling
 */
- (void)setKineticScrolling:(bool)kineticScrolling;

/**
 * Sets the maximum height that @scrolled_window should keep visible. The
 * @scrolled_window will grow up to this height before it starts scrolling
 * the content.
 * 
 * It is a programming error to set the maximum content height to a value
 * smaller than #GtkScrolledWindow:min-content-height.
 *
 * @param height the maximum content height
 */
- (void)setMaxContentHeight:(gint)height;

/**
 * Sets the maximum width that @scrolled_window should keep visible. The
 * @scrolled_window will grow up to this width before it starts scrolling
 * the content.
 * 
 * It is a programming error to set the maximum content width to a value
 * smaller than #GtkScrolledWindow:min-content-width.
 *
 * @param width the maximum content width
 */
- (void)setMaxContentWidth:(gint)width;

/**
 * Sets the minimum height that @scrolled_window should keep visible.
 * Note that this can and (usually will) be smaller than the minimum
 * size of the content.
 * 
 * It is a programming error to set the minimum content height to a
 * value greater than #GtkScrolledWindow:max-content-height.
 *
 * @param height the minimal content height
 */
- (void)setMinContentHeight:(gint)height;

/**
 * Sets the minimum width that @scrolled_window should keep visible.
 * Note that this can and (usually will) be smaller than the minimum
 * size of the content.
 * 
 * It is a programming error to set the minimum content width to a
 * value greater than #GtkScrolledWindow:max-content-width.
 *
 * @param width the minimal content width
 */
- (void)setMinContentWidth:(gint)width;

/**
 * Enables or disables overlay scrolling for this scrolled window.
 *
 * @param overlayScrolling whether to enable overlay scrolling
 */
- (void)setOverlayScrolling:(bool)overlayScrolling;

/**
 * Sets the placement of the contents with respect to the scrollbars
 * for the scrolled window.
 * 
 * The default is %GTK_CORNER_TOP_LEFT, meaning the child is
 * in the top left, with the scrollbars underneath and to the right.
 * Other values in #GtkCornerType are %GTK_CORNER_TOP_RIGHT,
 * %GTK_CORNER_BOTTOM_LEFT, and %GTK_CORNER_BOTTOM_RIGHT.
 * 
 * See also gtk_scrolled_window_get_placement() and
 * gtk_scrolled_window_unset_placement().
 *
 * @param windowPlacement position of the child window
 */
- (void)setPlacement:(GtkCornerType)windowPlacement;

/**
 * Sets the scrollbar policy for the horizontal and vertical scrollbars.
 * 
 * The policy determines when the scrollbar should appear; it is a value
 * from the #GtkPolicyType enumeration. If %GTK_POLICY_ALWAYS, the
 * scrollbar is always present; if %GTK_POLICY_NEVER, the scrollbar is
 * never present; if %GTK_POLICY_AUTOMATIC, the scrollbar is present only
 * if needed (that is, if the slider part of the bar would be smaller
 * than the trough — the display is larger than the page size).
 *
 * @param hscrollbarPolicy policy for horizontal bar
 * @param vscrollbarPolicy policy for vertical bar
 */
- (void)setPolicyWithHscrollbarPolicy:(GtkPolicyType)hscrollbarPolicy vscrollbarPolicy:(GtkPolicyType)vscrollbarPolicy;

/**
 * Sets whether the natural height of the child should be calculated and propagated
 * through the scrolled window’s requested natural height.
 *
 * @param propagate whether to propagate natural height
 */
- (void)setPropagateNaturalHeight:(bool)propagate;

/**
 * Sets whether the natural width of the child should be calculated and propagated
 * through the scrolled window’s requested natural width.
 *
 * @param propagate whether to propagate natural width
 */
- (void)setPropagateNaturalWidth:(bool)propagate;

/**
 * Changes the type of shadow drawn around the contents of
 * @scrolled_window.
 *
 * @param type kind of shadow to draw around scrolled window contents
 */
- (void)setShadowType:(GtkShadowType)type;

/**
 * Sets the #GtkAdjustment for the vertical scrollbar.
 *
 * @param vadjustment the #GtkAdjustment to use, or %NULL to create a new one
 */
- (void)setVadjustment:(OGTKAdjustment*)vadjustment;

/**
 * Unsets the placement of the contents with respect to the scrollbars
 * for the scrolled window. If no window placement is set for a scrolled
 * window, it defaults to %GTK_CORNER_TOP_LEFT.
 * 
 * See also gtk_scrolled_window_set_placement() and
 * gtk_scrolled_window_get_placement().
 *
 */
- (void)unsetPlacement;

@end