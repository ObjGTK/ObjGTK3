/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKContainer.h"

@class OGTKWidget;

/**
 * The GtkStack widget is a container which only shows
 * one of its children at a time. In contrast to GtkNotebook,
 * GtkStack does not provide a means for users to change the
 * visible child. Instead, the #GtkStackSwitcher widget can be
 * used with GtkStack to provide this functionality.
 * 
 * Transitions between pages can be animated as slides or
 * fades. This can be controlled with gtk_stack_set_transition_type().
 * These animations respect the #GtkSettings:gtk-enable-animations
 * setting.
 * 
 * The GtkStack widget was added in GTK+ 3.10.
 * 
 * # CSS nodes
 * 
 * GtkStack has a single CSS node named stack.
 *
 */
@interface OGTKStack : OGTKContainer
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkStack*)STACK;

/**
 * Adds a child to @stack.
 * The child is identified by the @name.
 *
 * @param child the widget to add
 * @param name the name for @child
 */
- (void)addNamedWithChild:(OGTKWidget*)child name:(OFString*)name;

/**
 * Adds a child to @stack.
 * The child is identified by the @name. The @title
 * will be used by #GtkStackSwitcher to represent
 * @child in a tab bar, so it should be short.
 *
 * @param child the widget to add
 * @param name the name for @child
 * @param title a human-readable title for @child
 */
- (void)addTitledWithChild:(OGTKWidget*)child name:(OFString*)name title:(OFString*)title;

/**
 * Finds the child of the #GtkStack with the name given as
 * the argument. Returns %NULL if there is no child with this
 * name.
 *
 * @param name the name of the child to find
 * @return the requested child of the #GtkStack
 */
- (OGTKWidget*)childByName:(OFString*)name;

/**
 * Gets whether @stack is horizontally homogeneous.
 * See gtk_stack_set_hhomogeneous().
 *
 * @return whether @stack is horizontally homogeneous.
 */
- (bool)hhomogeneous;

/**
 * Gets whether @stack is homogeneous.
 * See gtk_stack_set_homogeneous().
 *
 * @return whether @stack is homogeneous.
 */
- (bool)homogeneous;

/**
 * Returns wether the #GtkStack is set up to interpolate between
 * the sizes of children on page switch.
 *
 * @return %TRUE if child sizes are interpolated
 */
- (bool)interpolateSize;

/**
 * Returns the amount of time (in milliseconds) that
 * transitions between pages in @stack will take.
 *
 * @return the transition duration
 */
- (guint)transitionDuration;

/**
 * Returns whether the @stack is currently in a transition from one page to
 * another.
 *
 * @return %TRUE if the transition is currently running, %FALSE otherwise.
 */
- (bool)transitionRunning;

/**
 * Gets the type of animation that will be used
 * for transitions between pages in @stack.
 *
 * @return the current transition type of @stack
 */
- (GtkStackTransitionType)transitionType;

/**
 * Gets whether @stack is vertically homogeneous.
 * See gtk_stack_set_vhomogeneous().
 *
 * @return whether @stack is vertically homogeneous.
 */
- (bool)vhomogeneous;

/**
 * Gets the currently visible child of @stack, or %NULL if
 * there are no visible children.
 *
 * @return the visible child of the #GtkStack
 */
- (OGTKWidget*)visibleChild;

/**
 * Returns the name of the currently visible child of @stack, or
 * %NULL if there is no visible child.
 *
 * @return the name of the visible child of the #GtkStack
 */
- (OFString*)visibleChildName;

/**
 * Sets the #GtkStack to be horizontally homogeneous or not.
 * If it is homogeneous, the #GtkStack will request the same
 * width for all its children. If it isn't, the stack
 * may change width when a different child becomes visible.
 *
 * @param hhomogeneous %TRUE to make @stack horizontally homogeneous
 */
- (void)setHhomogeneous:(bool)hhomogeneous;

/**
 * Sets the #GtkStack to be homogeneous or not. If it
 * is homogeneous, the #GtkStack will request the same
 * size for all its children. If it isn't, the stack
 * may change size when a different child becomes visible.
 * 
 * Since 3.16, homogeneity can be controlled separately
 * for horizontal and vertical size, with the
 * #GtkStack:hhomogeneous and #GtkStack:vhomogeneous.
 *
 * @param homogeneous %TRUE to make @stack homogeneous
 */
- (void)setHomogeneous:(bool)homogeneous;

/**
 * Sets whether or not @stack will interpolate its size when
 * changing the visible child. If the #GtkStack:interpolate-size
 * property is set to %TRUE, @stack will interpolate its size between
 * the current one and the one it'll take after changing the
 * visible child, according to the set transition duration.
 *
 * @param interpolateSize the new value
 */
- (void)setInterpolateSize:(bool)interpolateSize;

/**
 * Sets the duration that transitions between pages in @stack
 * will take.
 *
 * @param duration the new duration, in milliseconds
 */
- (void)setTransitionDuration:(guint)duration;

/**
 * Sets the type of animation that will be used for
 * transitions between pages in @stack. Available
 * types include various kinds of fades and slides.
 * 
 * The transition type can be changed without problems
 * at runtime, so it is possible to change the animation
 * based on the page that is about to become current.
 *
 * @param transition the new transition type
 */
- (void)setTransitionType:(GtkStackTransitionType)transition;

/**
 * Sets the #GtkStack to be vertically homogeneous or not.
 * If it is homogeneous, the #GtkStack will request the same
 * height for all its children. If it isn't, the stack
 * may change height when a different child becomes visible.
 *
 * @param vhomogeneous %TRUE to make @stack vertically homogeneous
 */
- (void)setVhomogeneous:(bool)vhomogeneous;

/**
 * Makes @child the visible child of @stack.
 * 
 * If @child is different from the currently
 * visible child, the transition between the
 * two will be animated with the current
 * transition type of @stack.
 * 
 * Note that the @child widget has to be visible itself
 * (see gtk_widget_show()) in order to become the visible
 * child of @stack.
 *
 * @param child a child of @stack
 */
- (void)setVisibleChild:(OGTKWidget*)child;

/**
 * Makes the child with the given name visible.
 * 
 * Note that the child widget has to be visible itself
 * (see gtk_widget_show()) in order to become the visible
 * child of @stack.
 *
 * @param name the name of the child to make visible
 * @param transition the transition type to use
 */
- (void)setVisibleChildFullWithName:(OFString*)name transition:(GtkStackTransitionType)transition;

/**
 * Makes the child with the given name visible.
 * 
 * If @child is different from the currently
 * visible child, the transition between the
 * two will be animated with the current
 * transition type of @stack.
 * 
 * Note that the child widget has to be visible itself
 * (see gtk_widget_show()) in order to become the visible
 * child of @stack.
 *
 * @param name the name of the child to make visible
 */
- (void)setVisibleChildName:(OFString*)name;

@end