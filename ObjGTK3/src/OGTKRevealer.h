/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKWidget;

/**
 * The GtkRevealer widget is a container which animates
 * the transition of its child from invisible to visible.
 * 
 * The style of transition can be controlled with
 * gtk_revealer_set_transition_type().
 * 
 * These animations respect the #GtkSettings:gtk-enable-animations
 * setting.
 * 
 * # CSS nodes
 * 
 * GtkRevealer has a single CSS node with name revealer.
 * 
 * The GtkRevealer widget was added in GTK+ 3.10.
 *
 */
@interface OGTKRevealer : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkRevealer*)REVEALER;

/**
 * Returns whether the child is fully revealed, in other words whether
 * the transition to the revealed state is completed.
 *
 * @return %TRUE if the child is fully revealed
 */
- (bool)childRevealed;

/**
 * Returns whether the child is currently
 * revealed. See gtk_revealer_set_reveal_child().
 * 
 * This function returns %TRUE as soon as the transition
 * is to the revealed state is started. To learn whether
 * the child is fully revealed (ie the transition is completed),
 * use gtk_revealer_get_child_revealed().
 *
 * @return %TRUE if the child is revealed.
 */
- (bool)revealChild;

/**
 * Returns the amount of time (in milliseconds) that
 * transitions will take.
 *
 * @return the transition duration
 */
- (guint)transitionDuration;

/**
 * Gets the type of animation that will be used
 * for transitions in @revealer.
 *
 * @return the current transition type of @revealer
 */
- (GtkRevealerTransitionType)transitionType;

/**
 * Tells the #GtkRevealer to reveal or conceal its child.
 * 
 * The transition will be animated with the current
 * transition type of @revealer.
 *
 * @param revealChild %TRUE to reveal the child
 */
- (void)setRevealChild:(bool)revealChild;

/**
 * Sets the duration that transitions will take.
 *
 * @param duration the new duration, in milliseconds
 */
- (void)setTransitionDuration:(guint)duration;

/**
 * Sets the type of animation that will be used for
 * transitions in @revealer. Available types include
 * various kinds of fades and slides.
 *
 * @param transition the new transition type
 */
- (void)setTransitionType:(GtkRevealerTransitionType)transition;

@end