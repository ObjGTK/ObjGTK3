/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKWidget;
@class OGGdkWindow;

/**
 * #GtkPaned has two panes, arranged either
 * horizontally or vertically. The division between
 * the two panes is adjustable by the user by dragging
 * a handle.
 * 
 * Child widgets are
 * added to the panes of the widget with gtk_paned_pack1() and
 * gtk_paned_pack2(). The division between the two children is set by default
 * from the size requests of the children, but it can be adjusted by the
 * user.
 * 
 * A paned widget draws a separator between the two child widgets and a
 * small handle that the user can drag to adjust the division. It does not
 * draw any relief around the children or around the separator. (The space
 * in which the separator is called the gutter.) Often, it is useful to put
 * each child inside a #GtkFrame with the shadow type set to %GTK_SHADOW_IN
 * so that the gutter appears as a ridge. No separator is drawn if one of
 * the children is missing.
 * 
 * Each child has two options that can be set, @resize and @shrink. If
 * @resize is true, then when the #GtkPaned is resized, that child will
 * expand or shrink along with the paned widget. If @shrink is true, then
 * that child can be made smaller than its requisition by the user.
 * Setting @shrink to %FALSE allows the application to set a minimum size.
 * If @resize is false for both children, then this is treated as if
 * @resize is true for both children.
 * 
 * The application can set the position of the slider as if it were set
 * by the user, by calling gtk_paned_set_position().
 * 
 * # CSS nodes
 * 
 * |[<!-- language="plain" -->
 * paned
 * ├── <child>
 * ├── separator[.wide]
 * ╰── <child>
 * ]|
 * 
 * GtkPaned has a main CSS node with name paned, and a subnode for
 * the separator with name separator. The subnode gets a .wide style
 * class when the paned is supposed to be wide.
 * 
 * In horizontal orientation, the nodes of the children are always arranged
 * from left to right. So :first-child will always select the leftmost child,
 * regardless of text direction.
 * 
 * ## Creating a paned widget with minimum sizes.
 * 
 * |[<!-- language="C" -->
 * GtkWidget *hpaned = gtk_paned_new (GTK_ORIENTATION_HORIZONTAL);
 * GtkWidget *frame1 = gtk_frame_new (NULL);
 * GtkWidget *frame2 = gtk_frame_new (NULL);
 * gtk_frame_set_shadow_type (GTK_FRAME (frame1), GTK_SHADOW_IN);
 * gtk_frame_set_shadow_type (GTK_FRAME (frame2), GTK_SHADOW_IN);
 * 
 * gtk_widget_set_size_request (hpaned, 200, -1);
 * 
 * gtk_paned_pack1 (GTK_PANED (hpaned), frame1, TRUE, FALSE);
 * gtk_widget_set_size_request (frame1, 50, -1);
 * 
 * gtk_paned_pack2 (GTK_PANED (hpaned), frame2, FALSE, FALSE);
 * gtk_widget_set_size_request (frame2, 50, -1);
 * ]|
 *
 */
@interface OGTKPaned : OGTKContainer
{

}


/**
 * Constructors
 */
- (instancetype)init:(GtkOrientation)orientation;

/**
 * Methods
 */

- (GtkPaned*)PANED;

/**
 * Adds a child to the top or left pane with default parameters. This is
 * equivalent to
 * `gtk_paned_pack1 (paned, child, FALSE, TRUE)`.
 *
 * @param child the child to add
 */
- (void)add1:(OGTKWidget*)child;

/**
 * Adds a child to the bottom or right pane with default parameters. This
 * is equivalent to
 * `gtk_paned_pack2 (paned, child, TRUE, TRUE)`.
 *
 * @param child the child to add
 */
- (void)add2:(OGTKWidget*)child;

/**
 * Obtains the first child of the paned widget.
 *
 * @return first child, or %NULL if it is not set.
 */
- (OGTKWidget*)child1;

/**
 * Obtains the second child of the paned widget.
 *
 * @return second child, or %NULL if it is not set.
 */
- (OGTKWidget*)child2;

/**
 * Returns the #GdkWindow of the handle. This function is
 * useful when handling button or motion events because it
 * enables the callback to distinguish between the window
 * of the paned, a child and the handle.
 *
 * @return the paned’s handle window.
 */
- (OGGdkWindow*)handleWindow;

/**
 * Obtains the position of the divider between the two panes.
 *
 * @return position of the divider
 */
- (gint)position;

/**
 * Gets the #GtkPaned:wide-handle property.
 *
 * @return %TRUE if the paned should have a wide handle
 */
- (bool)wideHandle;

/**
 * Adds a child to the top or left pane.
 *
 * @param child the child to add
 * @param resize should this child expand when the paned widget is resized.
 * @param shrink can this child be made smaller than its requisition.
 */
- (void)pack1WithChild:(OGTKWidget*)child resize:(bool)resize shrink:(bool)shrink;

/**
 * Adds a child to the bottom or right pane.
 *
 * @param child the child to add
 * @param resize should this child expand when the paned widget is resized.
 * @param shrink can this child be made smaller than its requisition.
 */
- (void)pack2WithChild:(OGTKWidget*)child resize:(bool)resize shrink:(bool)shrink;

/**
 * Sets the position of the divider between the two panes.
 *
 * @param position pixel position of divider, a negative value means that the position
 *            is unset.
 */
- (void)setPosition:(gint)position;

/**
 * Sets the #GtkPaned:wide-handle property.
 *
 * @param wide the new value for the #GtkPaned:wide-handle property
 */
- (void)setWideHandle:(bool)wide;

@end