/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEventController.h"

#import "OGTKWidget.h"

@implementation OGTKEventController

- (GtkEventController*)EVENTCONTROLLER
{
	return GTK_EVENT_CONTROLLER([self GOBJECT]);
}

- (GtkPropagationPhase)propagationPhase
{
	return gtk_event_controller_get_propagation_phase([self EVENTCONTROLLER]);
}

- (OGTKWidget*)widget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_event_controller_get_widget([self EVENTCONTROLLER])] autorelease];
}

- (bool)handleEvent:(const GdkEvent*)event
{
	return gtk_event_controller_handle_event([self EVENTCONTROLLER], event);
}

- (void)reset
{
	gtk_event_controller_reset([self EVENTCONTROLLER]);
}

- (void)setPropagationPhase:(GtkPropagationPhase)phase
{
	gtk_event_controller_set_propagation_phase([self EVENTCONTROLLER], phase);
}


@end