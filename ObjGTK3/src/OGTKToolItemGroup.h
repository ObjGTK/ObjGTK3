/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKToolItem;
@class OGTKWidget;

/**
 * A #GtkToolItemGroup is used together with #GtkToolPalette to add
 * #GtkToolItems to a palette like container with different
 * categories and drag and drop support.
 * 
 * # CSS nodes
 * 
 * GtkToolItemGroup has a single CSS node named toolitemgroup.
 *
 */
@interface OGTKToolItemGroup : OGTKContainer
{

}


/**
 * Constructors
 */
- (instancetype)init:(OFString*)label;

/**
 * Methods
 */

- (GtkToolItemGroup*)TOOLITEMGROUP;

/**
 * Gets whether @group is collapsed or expanded.
 *
 * @return %TRUE if @group is collapsed, %FALSE if it is expanded
 */
- (bool)collapsed;

/**
 * Gets the tool item at position (x, y).
 *
 * @param x the x position
 * @param y the y position
 * @return the #GtkToolItem at position (x, y)
 */
- (OGTKToolItem*)dropItemWithX:(gint)x y:(gint)y;

/**
 * Gets the ellipsization mode of @group.
 *
 * @return the #PangoEllipsizeMode of @group
 */
- (PangoEllipsizeMode)ellipsize;

/**
 * Gets the relief mode of the header button of @group.
 *
 * @return the #GtkReliefStyle
 */
- (GtkReliefStyle)headerRelief;

/**
 * Gets the position of @item in @group as index.
 *
 * @param item a #GtkToolItem
 * @return the index of @item in @group or -1 if @item is no child of @group
 */
- (gint)itemPosition:(OGTKToolItem*)item;

/**
 * Gets the label of @group.
 *
 * @return the label of @group. The label is an internal string of @group
 *     and must not be modified. Note that %NULL is returned if a custom
 *     label has been set with gtk_tool_item_group_set_label_widget()
 */
- (OFString*)label;

/**
 * Gets the label widget of @group.
 * See gtk_tool_item_group_set_label_widget().
 *
 * @return the label widget of @group
 */
- (OGTKWidget*)labelWidget;

/**
 * Gets the number of tool items in @group.
 *
 * @return the number of tool items in @group
 */
- (guint)nitems;

/**
 * Gets the tool item at @index in group.
 *
 * @param index the index
 * @return the #GtkToolItem at index
 */
- (OGTKToolItem*)nthItem:(guint)index;

/**
 * Inserts @item at @position in the list of children of @group.
 *
 * @param item the #GtkToolItem to insert into @group
 * @param position the position of @item in @group, starting with 0.
 *     The position -1 means end of list.
 */
- (void)insertWithItem:(OGTKToolItem*)item position:(gint)position;

/**
 * Sets whether the @group should be collapsed or expanded.
 *
 * @param collapsed whether the @group should be collapsed or expanded
 */
- (void)setCollapsed:(bool)collapsed;

/**
 * Sets the ellipsization mode which should be used by labels in @group.
 *
 * @param ellipsize the #PangoEllipsizeMode labels in @group should use
 */
- (void)setEllipsize:(PangoEllipsizeMode)ellipsize;

/**
 * Set the button relief of the group header.
 * See gtk_button_set_relief() for details.
 *
 * @param style the #GtkReliefStyle
 */
- (void)setHeaderRelief:(GtkReliefStyle)style;

/**
 * Sets the position of @item in the list of children of @group.
 *
 * @param item the #GtkToolItem to move to a new position, should
 *     be a child of @group.
 * @param position the new position of @item in @group, starting with 0.
 *     The position -1 means end of list.
 */
- (void)setItemPositionWithItem:(OGTKToolItem*)item position:(gint)position;

/**
 * Sets the label of the tool item group. The label is displayed in the header
 * of the group.
 *
 * @param label the new human-readable label of of the group
 */
- (void)setLabel:(OFString*)label;

/**
 * Sets the label of the tool item group.
 * The label widget is displayed in the header of the group, in place
 * of the usual label.
 *
 * @param labelWidget the widget to be displayed in place of the usual label
 */
- (void)setLabelWidget:(OGTKWidget*)labelWidget;

@end