/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkWindow;
@class OGGdkDevice;

@interface OGGdkDragContext : OGObject
{

}


/**
 * Methods
 */

- (GdkDragContext*)DRAGCONTEXT;

/**
 * Determines the bitmask of actions proposed by the source if
 * gdk_drag_context_get_suggested_action() returns %GDK_ACTION_ASK.
 *
 * @return the #GdkDragAction flags
 */
- (GdkDragAction)actions;

/**
 * Returns the destination window for the DND operation.
 *
 * @return a #GdkWindow
 */
- (OGGdkWindow*)destWindow;

/**
 * Returns the #GdkDevice associated to the drag context.
 *
 * @return The #GdkDevice associated to @context.
 */
- (OGGdkDevice*)device;

/**
 * Returns the window on which the drag icon should be rendered
 * during the drag operation. Note that the window may not be
 * available until the drag operation has begun. GDK will move
 * the window in accordance with the ongoing drag operation.
 * The window is owned by @context and will be destroyed when
 * the drag operation is over.
 *
 * @return the drag window, or %NULL
 */
- (OGGdkWindow*)dragWindow;

/**
 * Returns the drag protocol that is used by this context.
 *
 * @return the drag protocol
 */
- (GdkDragProtocol)protocol;

/**
 * Determines the action chosen by the drag destination.
 *
 * @return a #GdkDragAction value
 */
- (GdkDragAction)selectedAction;

/**
 * Returns the #GdkWindow where the DND operation started.
 *
 * @return a #GdkWindow
 */
- (OGGdkWindow*)sourceWindow;

/**
 * Determines the suggested drag action of the context.
 *
 * @return a #GdkDragAction value
 */
- (GdkDragAction)suggestedAction;

/**
 * Retrieves the list of targets of the context.
 *
 * @return a #GList of targets
 */
- (GList*)listTargets;

/**
 * Requests the drag and drop operation to be managed by @context.
 * When a drag and drop operation becomes managed, the #GdkDragContext
 * will internally handle all input and source-side #GdkEventDND events
 * as required by the windowing system.
 * 
 * Once the drag and drop operation is managed, the drag context will
 * emit the following signals:
 * - The #GdkDragContext::action-changed signal whenever the final action
 *   to be performed by the drag and drop operation changes.
 * - The #GdkDragContext::drop-performed signal after the user performs
 *   the drag and drop gesture (typically by releasing the mouse button).
 * - The #GdkDragContext::dnd-finished signal after the drag and drop
 *   operation concludes (after all #GdkSelection transfers happen).
 * - The #GdkDragContext::cancel signal if the drag and drop operation is
 *   finished but doesn't happen over an accepting destination, or is
 *   cancelled through other means.
 *
 * @param ipcWindow Window to use for IPC messaging/events
 * @param actions the actions supported by the drag source
 * @return #TRUE if the drag and drop operation is managed.
 */
- (bool)manageDndWithIpcWindow:(OGGdkWindow*)ipcWindow actions:(GdkDragAction)actions;

/**
 * Associates a #GdkDevice to @context, so all Drag and Drop events
 * for @context are emitted as if they came from this device.
 *
 * @param device a #GdkDevice
 */
- (void)setDevice:(OGGdkDevice*)device;

/**
 * Sets the position of the drag window that will be kept
 * under the cursor hotspot. Initially, the hotspot is at the
 * top left corner of the drag window.
 *
 * @param hotX x coordinate of the drag window hotspot
 * @param hotY y coordinate of the drag window hotspot
 */
- (void)setHotspotWithHotX:(gint)hotX hotY:(gint)hotY;

@end