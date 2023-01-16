/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToolItem.h"

/**
 * A #GtkSeparatorToolItem is a #GtkToolItem that separates groups of other
 * #GtkToolItems. Depending on the theme, a #GtkSeparatorToolItem will
 * often look like a vertical line on horizontally docked toolbars.
 * 
 * If the #GtkToolbar child property “expand” is %TRUE and the property
 * #GtkSeparatorToolItem:draw is %FALSE, a #GtkSeparatorToolItem will act as
 * a “spring” that forces other items to the ends of the toolbar.
 * 
 * Use gtk_separator_tool_item_new() to create a new #GtkSeparatorToolItem.
 * 
 * # CSS nodes
 * 
 * GtkSeparatorToolItem has a single CSS node with name separator.
 *
 */
@interface OGTKSeparatorToolItem : OGTKToolItem
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkSeparatorToolItem*)SEPARATORTOOLITEM;

/**
 * Returns whether @item is drawn as a line, or just blank.
 * See gtk_separator_tool_item_set_draw().
 *
 * @return %TRUE if @item is drawn as a line, or just blank.
 */
- (bool)draw;

/**
 * Whether @item is drawn as a vertical line, or just blank.
 * Setting this to %FALSE along with gtk_tool_item_set_expand() is useful
 * to create an item that forces following items to the end of the toolbar.
 *
 * @param draw whether @item is drawn as a vertical line
 */
- (void)setDraw:(bool)draw;

@end