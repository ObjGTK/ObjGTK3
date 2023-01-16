/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

@class OGTKWidget;

@interface OGTKButtonBox : OGTKBox
{

}


/**
 * Constructors
 */
- (instancetype)init:(GtkOrientation)orientation;

/**
 * Methods
 */

- (GtkButtonBox*)BUTTONBOX;

/**
 * Returns whether the child is exempted from homogenous
 * sizing.
 *
 * @param child a child of @widget
 * @return %TRUE if the child is not subject to homogenous sizing
 */
- (bool)childNonHomogeneous:(OGTKWidget*)child;

/**
 * Returns whether @child should appear in a secondary group of children.
 *
 * @param child a child of @widget
 * @return whether @child should appear in a secondary group of children.
 */
- (bool)childSecondary:(OGTKWidget*)child;

/**
 * Retrieves the method being used to arrange the buttons in a button box.
 *
 * @return the method used to lay out buttons in @widget.
 */
- (GtkButtonBoxStyle)layout;

/**
 * Sets whether the child is exempted from homogeous sizing.
 *
 * @param child a child of @widget
 * @param nonHomogeneous the new value
 */
- (void)setChildNonHomogeneousWithChild:(OGTKWidget*)child nonHomogeneous:(bool)nonHomogeneous;

/**
 * Sets whether @child should appear in a secondary group of children.
 * A typical use of a secondary child is the help button in a dialog.
 * 
 * This group appears after the other children if the style
 * is %GTK_BUTTONBOX_START, %GTK_BUTTONBOX_SPREAD or
 * %GTK_BUTTONBOX_EDGE, and before the other children if the style
 * is %GTK_BUTTONBOX_END. For horizontal button boxes, the definition
 * of before/after depends on direction of the widget (see
 * gtk_widget_set_direction()). If the style is %GTK_BUTTONBOX_START
 * or %GTK_BUTTONBOX_END, then the secondary children are aligned at
 * the other end of the button box from the main children. For the
 * other styles, they appear immediately next to the main children.
 *
 * @param child a child of @widget
 * @param isSecondary if %TRUE, the @child appears in a secondary group of the
 *                button box.
 */
- (void)setChildSecondaryWithChild:(OGTKWidget*)child isSecondary:(bool)isSecondary;

/**
 * Changes the way buttons are arranged in their container.
 *
 * @param layoutStyle the new layout style
 */
- (void)setLayout:(GtkButtonBoxStyle)layoutStyle;

@end