/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

@class OGTKStack;
@class OGTKWidget;

/**
 * The GtkStackSwitcher widget acts as a controller for a
 * #GtkStack; it shows a row of buttons to switch between
 * the various pages of the associated stack widget.
 * 
 * All the content for the buttons comes from the child properties
 * of the #GtkStack; the button visibility in a #GtkStackSwitcher
 * widget is controlled by the visibility of the child in the
 * #GtkStack.
 * 
 * It is possible to associate multiple #GtkStackSwitcher widgets
 * with the same #GtkStack widget.
 * 
 * The GtkStackSwitcher widget was added in 3.10.
 * 
 * # CSS nodes
 * 
 * GtkStackSwitcher has a single CSS node named stackswitcher and
 * style class .stack-switcher.
 * 
 * When circumstances require it, GtkStackSwitcher adds the
 * .needs-attention style class to the widgets representing the
 * stack pages.
 *
 */
@interface OGTKStackSwitcher : OGTKBox
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkStackSwitcher*)STACKSWITCHER;

/**
 * Retrieves the stack.
 * See gtk_stack_switcher_set_stack().
 *
 * @return the stack, or %NULL if
 *    none has been set explicitly.
 */
- (OGTKStack*)stack;

/**
 * Sets the stack to control.
 *
 * @param stack a #GtkStack
 */
- (void)setStack:(OGTKStack*)stack;

@end