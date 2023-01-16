/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkDragContext.h"

#import "OGGdkWindow.h"
#import "OGGdkDevice.h"

@implementation OGGdkDragContext

- (GdkDragContext*)DRAGCONTEXT
{
	return GDK_DRAG_CONTEXT([self GOBJECT]);
}

- (GdkDragAction)actions
{
	return gdk_drag_context_get_actions([self DRAGCONTEXT]);
}

- (OGGdkWindow*)destWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_drag_context_get_dest_window([self DRAGCONTEXT])] autorelease];
}

- (OGGdkDevice*)device
{
	return [[[OGGdkDevice alloc] initWithGObject:(GObject*)gdk_drag_context_get_device([self DRAGCONTEXT])] autorelease];
}

- (OGGdkWindow*)dragWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_drag_context_get_drag_window([self DRAGCONTEXT])] autorelease];
}

- (GdkDragProtocol)protocol
{
	return gdk_drag_context_get_protocol([self DRAGCONTEXT]);
}

- (GdkDragAction)selectedAction
{
	return gdk_drag_context_get_selected_action([self DRAGCONTEXT]);
}

- (OGGdkWindow*)sourceWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_drag_context_get_source_window([self DRAGCONTEXT])] autorelease];
}

- (GdkDragAction)suggestedAction
{
	return gdk_drag_context_get_suggested_action([self DRAGCONTEXT]);
}

- (GList*)listTargets
{
	return gdk_drag_context_list_targets([self DRAGCONTEXT]);
}

- (bool)manageDndWithIpcWindow:(OGGdkWindow*)ipcWindow actions:(GdkDragAction)actions
{
	return gdk_drag_context_manage_dnd([self DRAGCONTEXT], [ipcWindow WINDOW], actions);
}

- (void)setDevice:(OGGdkDevice*)device
{
	gdk_drag_context_set_device([self DRAGCONTEXT], [device DEVICE]);
}

- (void)setHotspotWithHotX:(gint)hotX hotY:(gint)hotY
{
	gdk_drag_context_set_hotspot([self DRAGCONTEXT], hotX, hotY);
}


@end