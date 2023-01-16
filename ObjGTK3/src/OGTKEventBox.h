/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBin.h"

@class OGTKWidget;

/**
 * The #GtkEventBox widget is a subclass of #GtkBin which also has its
 * own window. It is useful since it allows you to catch events for widgets
 * which do not have their own window.
 *
 */
@interface OGTKEventBox : OGTKBin
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkEventBox*)EVENTBOX;

/**
 * Returns whether the event box window is above or below the
 * windows of its child. See gtk_event_box_set_above_child()
 * for details.
 *
 * @return %TRUE if the event box window is above the
 *     window of its child
 */
- (bool)aboveChild;

/**
 * Returns whether the event box has a visible window.
 * See gtk_event_box_set_visible_window() for details.
 *
 * @return %TRUE if the event box window is visible
 */
- (bool)visibleWindow;

/**
 * Set whether the event box window is positioned above the windows
 * of its child, as opposed to below it. If the window is above, all
 * events inside the event box will go to the event box. If the window
 * is below, events in windows of child widgets will first got to that
 * widget, and then to its parents.
 * 
 * The default is to keep the window below the child.
 *
 * @param aboveChild %TRUE if the event box window is above its child
 */
- (void)setAboveChild:(bool)aboveChild;

/**
 * Set whether the event box uses a visible or invisible child
 * window. The default is to use visible windows.
 * 
 * In an invisible window event box, the window that the
 * event box creates is a %GDK_INPUT_ONLY window, which
 * means that it is invisible and only serves to receive
 * events.
 * 
 * A visible window event box creates a visible (%GDK_INPUT_OUTPUT)
 * window that acts as the parent window for all the widgets
 * contained in the event box.
 * 
 * You should generally make your event box invisible if
 * you just want to trap events. Creating a visible window
 * may cause artifacts that are visible to the user, especially
 * if the user is using a theme with gradients or pixmaps.
 * 
 * The main reason to create a non input-only event box is if
 * you want to set the background to a different color or
 * draw on it.
 * 
 * There is one unexpected issue for an invisible event box that has its
 * window below the child. (See gtk_event_box_set_above_child().)
 * Since the input-only window is not an ancestor window of any windows
 * that descendent widgets of the event box create, events on these
 * windows aren’t propagated up by the windowing system, but only by GTK+.
 * The practical effect of this is if an event isn’t in the event
 * mask for the descendant window (see gtk_widget_add_events()),
 * it won’t be received by the event box.
 * 
 * This problem doesn’t occur for visible event boxes, because in
 * that case, the event box window is actually the ancestor of the
 * descendant windows, not just at the same place on the screen.
 *
 * @param visibleWindow %TRUE to make the event box have a visible window
 */
- (void)setVisibleWindow:(bool)visibleWindow;

@end