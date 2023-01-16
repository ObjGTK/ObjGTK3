/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEventController.h"

@class OGTKWidget;

/**
 * #GtkEventControllerScroll is an event controller meant to handle
 * scroll events from mice and touchpads. It is capable of handling
 * both discrete and continuous scroll events, abstracting them both
 * on the #GtkEventControllerScroll::scroll signal (deltas in the
 * discrete case are multiples of 1).
 * 
 * In the case of continuous scroll events, #GtkEventControllerScroll
 * encloses all #GtkEventControllerScroll::scroll events between two
 * #GtkEventControllerScroll::scroll-begin and #GtkEventControllerScroll::scroll-end
 * signals.
 * 
 * The behavior of the event controller can be modified by the
 * flags given at creation time, or modified at a later point through
 * gtk_event_controller_scroll_set_flags() (e.g. because the scrolling
 * conditions of the widget changed).
 * 
 * The controller can be set up to emit motion for either/both vertical
 * and horizontal scroll events through #GTK_EVENT_CONTROLLER_SCROLL_VERTICAL,
 * #GTK_EVENT_CONTROLLER_SCROLL_HORIZONTAL and #GTK_EVENT_CONTROLLER_SCROLL_BOTH.
 * If any axis is disabled, the respective #GtkEventControllerScroll::scroll
 * delta will be 0. Vertical scroll events will be translated to horizontal
 * motion for the devices incapable of horizontal scrolling.
 * 
 * The event controller can also be forced to emit discrete events on all devices
 * through #GTK_EVENT_CONTROLLER_SCROLL_DISCRETE. This can be used to implement
 * discrete actions triggered through scroll events (e.g. switching across
 * combobox options).
 * 
 * The #GTK_EVENT_CONTROLLER_SCROLL_KINETIC flag toggles the emission of the
 * #GtkEventControllerScroll::decelerate signal, emitted at the end of scrolling
 * with two X/Y velocity arguments that are consistent with the motion that
 * was received.
 * 
 * This object was added in 3.24.
 *
 */
@interface OGTKEventControllerScroll : OGTKEventController
{

}


/**
 * Constructors
 */
- (instancetype)initWithWidget:(OGTKWidget*)widget flags:(GtkEventControllerScrollFlags)flags;

/**
 * Methods
 */

- (GtkEventControllerScroll*)EVENTCONTROLLERSCROLL;

/**
 * Gets the flags conditioning the scroll controller behavior.
 *
 * @return the controller flags.
 */
- (GtkEventControllerScrollFlags)flags;

/**
 * Sets the flags conditioning scroll controller behavior.
 *
 * @param flags behavior flags
 */
- (void)setFlags:(GtkEventControllerScrollFlags)flags;

@end