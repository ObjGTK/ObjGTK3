/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKWidget;

/**
 * The GtkBox widget arranges child widgets into a single row or column,
 * depending upon the value of its #GtkOrientable:orientation property. Within
 * the other dimension, all children are allocated the same size. Of course,
 * the #GtkWidget:halign and #GtkWidget:valign properties can be used on
 * the children to influence their allocation.
 * 
 * GtkBox uses a notion of packing. Packing refers
 * to adding widgets with reference to a particular position in a
 * #GtkContainer. For a GtkBox, there are two reference positions: the
 * start and the end of the box.
 * For a vertical #GtkBox, the start is defined as the top of the box and
 * the end is defined as the bottom. For a horizontal #GtkBox the start
 * is defined as the left side and the end is defined as the right side.
 * 
 * Use repeated calls to gtk_box_pack_start() to pack widgets into a
 * GtkBox from start to end. Use gtk_box_pack_end() to add widgets from
 * end to start. You may intersperse these calls and add widgets from
 * both ends of the same GtkBox.
 * 
 * Because GtkBox is a #GtkContainer, you may also use gtk_container_add()
 * to insert widgets into the box, and they will be packed with the default
 * values for expand and fill child properties. Use gtk_container_remove()
 * to remove widgets from the GtkBox.
 * 
 * Use gtk_box_set_homogeneous() to specify whether or not all children
 * of the GtkBox are forced to get the same amount of space.
 * 
 * Use gtk_box_set_spacing() to determine how much space will be
 * minimally placed between all children in the GtkBox. Note that
 * spacing is added between the children, while
 * padding added by gtk_box_pack_start() or gtk_box_pack_end() is added
 * on either side of the widget it belongs to.
 * 
 * Use gtk_box_reorder_child() to move a GtkBox child to a different
 * place in the box.
 * 
 * Use gtk_box_set_child_packing() to reset the expand,
 * fill and padding child properties.
 * Use gtk_box_query_child_packing() to query these fields.
 * 
 * # CSS nodes
 * 
 * GtkBox uses a single CSS node with name box.
 * 
 * In horizontal orientation, the nodes of the children are always arranged
 * from left to right. So :first-child will always select the leftmost child,
 * regardless of text direction.
 *
 */
@interface OGTKBox : OGTKContainer
{

}


/**
 * Constructors
 */
- (instancetype)initWithOrientation:(GtkOrientation)orientation spacing:(gint)spacing;

/**
 * Methods
 */

- (GtkBox*)BOX;

/**
 * Gets the value set by gtk_box_set_baseline_position().
 *
 * @return the baseline position
 */
- (GtkBaselinePosition)baselinePosition;

/**
 * Retrieves the center widget of the box.
 *
 * @return the center widget
 *   or %NULL in case no center widget is set.
 */
- (OGTKWidget*)centerWidget;

/**
 * Returns whether the box is homogeneous (all children are the
 * same size). See gtk_box_set_homogeneous().
 *
 * @return %TRUE if the box is homogeneous.
 */
- (bool)homogeneous;

/**
 * Gets the value set by gtk_box_set_spacing().
 *
 * @return spacing between children
 */
- (gint)spacing;

/**
 * Adds @child to @box, packed with reference to the end of @box.
 * The @child is packed after (away from end of) any other child
 * packed with reference to the end of @box.
 *
 * @param child the #GtkWidget to be added to @box
 * @param expand %TRUE if the new child is to be given extra space allocated
 *   to @box. The extra space will be divided evenly between all children
 *   of @box that use this option
 * @param fill %TRUE if space given to @child by the @expand option is
 *   actually allocated to @child, rather than just padding it.  This
 *   parameter has no effect if @expand is set to %FALSE.  A child is
 *   always allocated the full height of a horizontal #GtkBox and the full width
 *   of a vertical #GtkBox.  This option affects the other dimension
 * @param padding extra space in pixels to put between this child and its
 *   neighbors, over and above the global amount specified by
 *   #GtkBox:spacing property.  If @child is a widget at one of the
 *   reference ends of @box, then @padding pixels are also put between
 *   @child and the reference edge of @box
 */
- (void)packEndWithChild:(OGTKWidget*)child expand:(bool)expand fill:(bool)fill padding:(guint)padding;

/**
 * Adds @child to @box, packed with reference to the start of @box.
 * The @child is packed after any other child packed with reference
 * to the start of @box.
 *
 * @param child the #GtkWidget to be added to @box
 * @param expand %TRUE if the new child is to be given extra space allocated
 *     to @box. The extra space will be divided evenly between all children
 *     that use this option
 * @param fill %TRUE if space given to @child by the @expand option is
 *     actually allocated to @child, rather than just padding it.  This
 *     parameter has no effect if @expand is set to %FALSE.  A child is
 *     always allocated the full height of a horizontal #GtkBox and the full width
 *     of a vertical #GtkBox. This option affects the other dimension
 * @param padding extra space in pixels to put between this child and its
 *   neighbors, over and above the global amount specified by
 *   #GtkBox:spacing property.  If @child is a widget at one of the
 *   reference ends of @box, then @padding pixels are also put between
 *   @child and the reference edge of @box
 */
- (void)packStartWithChild:(OGTKWidget*)child expand:(bool)expand fill:(bool)fill padding:(guint)padding;

/**
 * Obtains information about how @child is packed into @box.
 *
 * @param child the #GtkWidget of the child to query
 * @param expand pointer to return location for expand child
 *     property
 * @param fill pointer to return location for fill child
 *     property
 * @param padding pointer to return location for padding
 *     child property
 * @param packType pointer to return location for pack-type
 *     child property
 */
- (void)queryChildPackingWithChild:(OGTKWidget*)child expand:(gboolean*)expand fill:(gboolean*)fill padding:(guint*)padding packType:(GtkPackType*)packType;

/**
 * Moves @child to a new @position in the list of @box children.
 * The list contains widgets packed #GTK_PACK_START
 * as well as widgets packed #GTK_PACK_END, in the order that these
 * widgets were added to @box.
 * 
 * A widget’s position in the @box children list determines where
 * the widget is packed into @box.  A child widget at some position
 * in the list will be packed just after all other widgets of the
 * same packing type that appear earlier in the list.
 *
 * @param child the #GtkWidget to move
 * @param position the new position for @child in the list of children
 *   of @box, starting from 0. If negative, indicates the end of
 *   the list
 */
- (void)reorderChildWithChild:(OGTKWidget*)child position:(gint)position;

/**
 * Sets the baseline position of a box. This affects
 * only horizontal boxes with at least one baseline aligned
 * child. If there is more vertical space available than requested,
 * and the baseline is not allocated by the parent then
 * @position is used to allocate the baseline wrt the
 * extra space available.
 *
 * @param position a #GtkBaselinePosition
 */
- (void)setBaselinePosition:(GtkBaselinePosition)position;

/**
 * Sets a center widget; that is a child widget that will be
 * centered with respect to the full width of the box, even
 * if the children at either side take up different amounts
 * of space.
 *
 * @param widget the widget to center
 */
- (void)setCenterWidget:(OGTKWidget*)widget;

/**
 * Sets the way @child is packed into @box.
 *
 * @param child the #GtkWidget of the child to set
 * @param expand the new value of the expand child property
 * @param fill the new value of the fill child property
 * @param padding the new value of the padding child property
 * @param packType the new value of the pack-type child property
 */
- (void)setChildPackingWithChild:(OGTKWidget*)child expand:(bool)expand fill:(bool)fill padding:(guint)padding packType:(GtkPackType)packType;

/**
 * Sets the #GtkBox:homogeneous property of @box, controlling
 * whether or not all children of @box are given equal space
 * in the box.
 *
 * @param homogeneous a boolean value, %TRUE to create equal allotments,
 *   %FALSE for variable allotments
 */
- (void)setHomogeneous:(bool)homogeneous;

/**
 * Sets the #GtkBox:spacing property of @box, which is the
 * number of pixels to place between children of @box.
 *
 * @param spacing the number of pixels to put between children
 */
- (void)setSpacing:(gint)spacing;

@end