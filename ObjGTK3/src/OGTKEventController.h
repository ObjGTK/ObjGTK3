/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>
#include <gtk/gtk.h>

#import <OGObject/OGObject.h>

@class OGTKWidget;

/**
 * #GtkEventController is a base, low-level implementation for event
 * controllers. Those react to a series of #GdkEvents, and possibly trigger
 * actions as a consequence of those.
 *
 */
@interface OGTKEventController : OGObject
{

}


/**
 * Methods
 */

- (GtkEventController*)EVENTCONTROLLER;

/**
 * Gets the propagation phase at which @controller handles events.
 *
 * @return the propagation phase
 */
- (GtkPropagationPhase)propagationPhase;

/**
 * Returns the #GtkWidget this controller relates to.
 *
 * @return a #GtkWidget
 */
- (OGTKWidget*)widget;

/**
 * Feeds an events into @controller, so it can be interpreted
 * and the controller actions triggered.
 *
 * @param event a #GdkEvent
 * @return %TRUE if the event was potentially useful to trigger the
 *          controller action
 */
- (bool)handleEvent:(const GdkEvent*)event;

/**
 * Resets the @controller to a clean state. Every interaction
 * the controller did through #GtkEventController::handle-event
 * will be dropped at this point.
 *
 */
- (void)reset;

/**
 * Sets the propagation phase at which a controller handles events.
 * 
 * If @phase is %GTK_PHASE_NONE, no automatic event handling will be
 * performed, but other additional gesture maintenance will. In that phase,
 * the events can be managed by calling gtk_event_controller_handle_event().
 *
 * @param phase a propagation phase
 */
- (void)setPropagationPhase:(GtkPropagationPhase)phase;

@end