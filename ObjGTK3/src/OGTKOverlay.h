/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKWidget;

/**
 * GtkOverlay is a container which contains a single main child, on top
 * of which it can place “overlay” widgets. The position of each overlay
 * widget is determined by its #GtkWidget:halign and #GtkWidget:valign
 * properties. E.g. a widget with both alignments set to %GTK_ALIGN_START
 * will be placed at the top left corner of the GtkOverlay container,
 * whereas an overlay with halign set to %GTK_ALIGN_CENTER and valign set
 * to %GTK_ALIGN_END will be placed a the bottom edge of the GtkOverlay,
 * horizontally centered. The position can be adjusted by setting the margin
 * properties of the child to non-zero values.
 * 
 * More complicated placement of overlays is possible by connecting
 * to the #GtkOverlay::get-child-position signal.
 * 
 * An overlay’s minimum and natural sizes are those of its main child. The sizes
 * of overlay children are not considered when measuring these preferred sizes.
 * 
 * # GtkOverlay as GtkBuildable
 * 
 * The GtkOverlay implementation of the GtkBuildable interface
 * supports placing a child as an overlay by specifying “overlay” as
 * the “type” attribute of a `<child>` element.
 * 
 * # CSS nodes
 * 
 * GtkOverlay has a single CSS node with the name “overlay”. Overlay children
 * whose alignments cause them to be positioned at an edge get the style classes
 * “.left”, “.right”, “.top”, and/or “.bottom” according to their position.
 *
 */
@interface OGTKOverlay : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkOverlay*)OVERLAY;

/**
 * Adds @widget to @overlay.
 * 
 * The widget will be stacked on top of the main widget
 * added with gtk_container_add().
 * 
 * The position at which @widget is placed is determined
 * from its #GtkWidget:halign and #GtkWidget:valign properties.
 *
 * @param widget a #GtkWidget to be added to the container
 */
- (void)addOverlay:(OGTKWidget*)widget;

/**
 * Convenience function to get the value of the #GtkOverlay:pass-through
 * child property for @widget.
 *
 * @param widget an overlay child of #GtkOverlay
 * @return whether the widget is a pass through child.
 */
- (bool)overlayPassThrough:(OGTKWidget*)widget;

/**
 * Moves @child to a new @index in the list of @overlay children.
 * The list contains overlays in the order that these were
 * added to @overlay by default. See also #GtkOverlay:index.
 * 
 * A widget’s index in the @overlay children list determines which order
 * the children are drawn if they overlap. The first child is drawn at
 * the bottom. It also affects the default focus chain order.
 *
 * @param child the overlaid #GtkWidget to move
 * @param index the new index for @child in the list of overlay children
 *   of @overlay, starting from 0. If negative, indicates the end of
 *   the list
 */
- (void)reorderOverlayWithChild:(OGTKWidget*)child index:(int)index;

/**
 * Convenience function to set the value of the #GtkOverlay:pass-through
 * child property for @widget.
 *
 * @param widget an overlay child of #GtkOverlay
 * @param passThrough whether the child should pass the input through
 */
- (void)setOverlayPassThroughWithWidget:(OGTKWidget*)widget passThrough:(bool)passThrough;

@end