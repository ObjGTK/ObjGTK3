/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRevealer.h"

#import "OGTKWidget.h"

@implementation OGTKRevealer

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_revealer_new()];

	return self;
}

- (GtkRevealer*)REVEALER
{
	return GTK_REVEALER([self GOBJECT]);
}

- (bool)childRevealed
{
	return gtk_revealer_get_child_revealed([self REVEALER]);
}

- (bool)revealChild
{
	return gtk_revealer_get_reveal_child([self REVEALER]);
}

- (guint)transitionDuration
{
	return gtk_revealer_get_transition_duration([self REVEALER]);
}

- (GtkRevealerTransitionType)transitionType
{
	return gtk_revealer_get_transition_type([self REVEALER]);
}

- (void)setRevealChild:(bool)revealChild
{
	gtk_revealer_set_reveal_child([self REVEALER], revealChild);
}

- (void)setTransitionDuration:(guint)duration
{
	gtk_revealer_set_transition_duration([self REVEALER], duration);
}

- (void)setTransitionType:(GtkRevealerTransitionType)transition
{
	gtk_revealer_set_transition_type([self REVEALER], transition);
}


@end