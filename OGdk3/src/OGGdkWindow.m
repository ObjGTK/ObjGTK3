/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGGdkWindow.h"

#import "OGGdkVisual.h"
#import "OGGdkDisplay.h"
#import "OGGdkScreen.h"
#import "OGGdkGLContext.h"
#import "OGGdkDrawingContext.h"
#import "OGGdkDevice.h"
#import "OGGdkCursor.h"
#import "OGGdkFrameClock.h"

@implementation OGGdkWindow

+ (OGGdkWindow*)atPointerWithWinX:(gint*)winX winY:(gint*)winY
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_window_at_pointer(winX, winY)] autorelease];
}

+ (void)constrainSizeWithGeometry:(GdkGeometry*)geometry flags:(GdkWindowHints)flags width:(gint)width height:(gint)height newWidth:(gint*)newWidth newHeight:(gint*)newHeight
{
	gdk_window_constrain_size(geometry, flags, width, height, newWidth, newHeight);
}

+ (void)processAllUpdates
{
	gdk_window_process_all_updates();
}

+ (void)setDebugUpdates:(bool)setting
{
	gdk_window_set_debug_updates(setting);
}

- (instancetype)initWithParent:(OGGdkWindow*)parent attributes:(GdkWindowAttr*)attributes attributesMask:(gint)attributesMask
{
	self = [super initWithGObject:(GObject*)gdk_window_new([parent WINDOW], attributes, attributesMask)];

	return self;
}

- (GdkWindow*)WINDOW
{
	return GDK_WINDOW([self GOBJECT]);
}

- (void)addFilterWithFunction:(GdkFilterFunc)function data:(gpointer)data
{
	gdk_window_add_filter([self WINDOW], function, data);
}

- (void)beep
{
	gdk_window_beep([self WINDOW]);
}

- (OGGdkDrawingContext*)beginDrawFrame:(const cairo_region_t*)region
{
	return [[[OGGdkDrawingContext alloc] initWithGObject:(GObject*)gdk_window_begin_draw_frame([self WINDOW], region)] autorelease];
}

- (void)beginMoveDragWithButton:(gint)button rootX:(gint)rootX rootY:(gint)rootY timestamp:(guint32)timestamp
{
	gdk_window_begin_move_drag([self WINDOW], button, rootX, rootY, timestamp);
}

- (void)beginMoveDragForDeviceWithDevice:(OGGdkDevice*)device button:(gint)button rootX:(gint)rootX rootY:(gint)rootY timestamp:(guint32)timestamp
{
	gdk_window_begin_move_drag_for_device([self WINDOW], [device DEVICE], button, rootX, rootY, timestamp);
}

- (void)beginPaintRect:(const GdkRectangle*)rectangle
{
	gdk_window_begin_paint_rect([self WINDOW], rectangle);
}

- (void)beginPaintRegion:(const cairo_region_t*)region
{
	gdk_window_begin_paint_region([self WINDOW], region);
}

- (void)beginResizeDragWithEdge:(GdkWindowEdge)edge button:(gint)button rootX:(gint)rootX rootY:(gint)rootY timestamp:(guint32)timestamp
{
	gdk_window_begin_resize_drag([self WINDOW], edge, button, rootX, rootY, timestamp);
}

- (void)beginResizeDragForDeviceWithEdge:(GdkWindowEdge)edge device:(OGGdkDevice*)device button:(gint)button rootX:(gint)rootX rootY:(gint)rootY timestamp:(guint32)timestamp
{
	gdk_window_begin_resize_drag_for_device([self WINDOW], edge, [device DEVICE], button, rootX, rootY, timestamp);
}

- (void)configureFinished
{
	gdk_window_configure_finished([self WINDOW]);
}

- (void)coordsFromParentWithParentX:(gdouble)parentX parentY:(gdouble)parentY x:(gdouble*)x y:(gdouble*)y
{
	gdk_window_coords_from_parent([self WINDOW], parentX, parentY, x, y);
}

- (void)coordsToParentWithX:(gdouble)x y:(gdouble)y parentX:(gdouble*)parentX parentY:(gdouble*)parentY
{
	gdk_window_coords_to_parent([self WINDOW], x, y, parentX, parentY);
}

- (OGGdkGLContext*)createGlContext:(GError**)err
{
	return [[[OGGdkGLContext alloc] initWithGObject:(GObject*)gdk_window_create_gl_context([self WINDOW], err)] autorelease];
}

- (cairo_surface_t*)createSimilarImageSurfaceWithFormat:(cairo_format_t)format width:(int)width height:(int)height scale:(int)scale
{
	return gdk_window_create_similar_image_surface([self WINDOW], format, width, height, scale);
}

- (cairo_surface_t*)createSimilarSurfaceWithContent:(cairo_content_t)content width:(int)width height:(int)height
{
	return gdk_window_create_similar_surface([self WINDOW], content, width, height);
}

- (void)deiconify
{
	gdk_window_deiconify([self WINDOW]);
}

- (void)destroy
{
	gdk_window_destroy([self WINDOW]);
}

- (void)destroyNotify
{
	gdk_window_destroy_notify([self WINDOW]);
}

- (void)enableSynchronizedConfigure
{
	gdk_window_enable_synchronized_configure([self WINDOW]);
}

- (void)endDrawFrame:(OGGdkDrawingContext*)context
{
	gdk_window_end_draw_frame([self WINDOW], [context DRAWINGCONTEXT]);
}

- (void)endPaint
{
	gdk_window_end_paint([self WINDOW]);
}

- (bool)ensureNative
{
	return gdk_window_ensure_native([self WINDOW]);
}

- (void)flush
{
	gdk_window_flush([self WINDOW]);
}

- (void)focus:(guint32)timestamp
{
	gdk_window_focus([self WINDOW], timestamp);
}

- (void)freezeToplevelUpdatesLibgtkOnly
{
	gdk_window_freeze_toplevel_updates_libgtk_only([self WINDOW]);
}

- (void)freezeUpdates
{
	gdk_window_freeze_updates([self WINDOW]);
}

- (void)fullscreen
{
	gdk_window_fullscreen([self WINDOW]);
}

- (void)fullscreenOnMonitor:(gint)monitor
{
	gdk_window_fullscreen_on_monitor([self WINDOW], monitor);
}

- (void)geometryChanged
{
	gdk_window_geometry_changed([self WINDOW]);
}

- (bool)acceptFocus
{
	return gdk_window_get_accept_focus([self WINDOW]);
}

- (cairo_pattern_t*)backgroundPattern
{
	return gdk_window_get_background_pattern([self WINDOW]);
}

- (GList*)children
{
	return gdk_window_get_children([self WINDOW]);
}

- (GList*)childrenWithUserData:(gpointer)userData
{
	return gdk_window_get_children_with_user_data([self WINDOW], userData);
}

- (cairo_region_t*)clipRegion
{
	return gdk_window_get_clip_region([self WINDOW]);
}

- (bool)composited
{
	return gdk_window_get_composited([self WINDOW]);
}

- (OGGdkCursor*)cursor
{
	return [[[OGGdkCursor alloc] initWithGObject:(GObject*)gdk_window_get_cursor([self WINDOW])] autorelease];
}

- (bool)decorations:(GdkWMDecoration*)decorations
{
	return gdk_window_get_decorations([self WINDOW], decorations);
}

- (OGGdkCursor*)deviceCursor:(OGGdkDevice*)device
{
	return [[[OGGdkCursor alloc] initWithGObject:(GObject*)gdk_window_get_device_cursor([self WINDOW], [device DEVICE])] autorelease];
}

- (GdkEventMask)deviceEvents:(OGGdkDevice*)device
{
	return gdk_window_get_device_events([self WINDOW], [device DEVICE]);
}

- (OGGdkWindow*)devicePositionWithDevice:(OGGdkDevice*)device x:(gint*)x y:(gint*)y mask:(GdkModifierType*)mask
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_window_get_device_position([self WINDOW], [device DEVICE], x, y, mask)] autorelease];
}

- (OGGdkWindow*)devicePositionDoubleWithDevice:(OGGdkDevice*)device x:(gdouble*)x y:(gdouble*)y mask:(GdkModifierType*)mask
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_window_get_device_position_double([self WINDOW], [device DEVICE], x, y, mask)] autorelease];
}

- (OGGdkDisplay*)display
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gdk_window_get_display([self WINDOW])] autorelease];
}

- (GdkDragProtocol)dragProtocol:(GdkWindow**)target
{
	return gdk_window_get_drag_protocol([self WINDOW], target);
}

- (OGGdkWindow*)effectiveParent
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_window_get_effective_parent([self WINDOW])] autorelease];
}

- (OGGdkWindow*)effectiveToplevel
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_window_get_effective_toplevel([self WINDOW])] autorelease];
}

- (bool)eventCompression
{
	return gdk_window_get_event_compression([self WINDOW]);
}

- (GdkEventMask)events
{
	return gdk_window_get_events([self WINDOW]);
}

- (bool)focusOnMap
{
	return gdk_window_get_focus_on_map([self WINDOW]);
}

- (OGGdkFrameClock*)frameClock
{
	return [[[OGGdkFrameClock alloc] initWithGObject:(GObject*)gdk_window_get_frame_clock([self WINDOW])] autorelease];
}

- (void)frameExtents:(GdkRectangle*)rect
{
	gdk_window_get_frame_extents([self WINDOW], rect);
}

- (GdkFullscreenMode)fullscreenMode
{
	return gdk_window_get_fullscreen_mode([self WINDOW]);
}

- (void)geometryWithX:(gint*)x y:(gint*)y width:(gint*)width height:(gint*)height
{
	gdk_window_get_geometry([self WINDOW], x, y, width, height);
}

- (OGGdkWindow*)group
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_window_get_group([self WINDOW])] autorelease];
}

- (int)height
{
	return gdk_window_get_height([self WINDOW]);
}

- (bool)modalHint
{
	return gdk_window_get_modal_hint([self WINDOW]);
}

- (gint)originWithX:(gint*)x y:(gint*)y
{
	return gdk_window_get_origin([self WINDOW], x, y);
}

- (OGGdkWindow*)parent
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_window_get_parent([self WINDOW])] autorelease];
}

- (bool)passThrough
{
	return gdk_window_get_pass_through([self WINDOW]);
}

- (OGGdkWindow*)pointerWithX:(gint*)x y:(gint*)y mask:(GdkModifierType*)mask
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_window_get_pointer([self WINDOW], x, y, mask)] autorelease];
}

- (void)positionWithX:(gint*)x y:(gint*)y
{
	gdk_window_get_position([self WINDOW], x, y);
}

- (void)rootCoordsWithX:(gint)x y:(gint)y rootX:(gint*)rootX rootY:(gint*)rootY
{
	gdk_window_get_root_coords([self WINDOW], x, y, rootX, rootY);
}

- (void)rootOriginWithX:(gint*)x y:(gint*)y
{
	gdk_window_get_root_origin([self WINDOW], x, y);
}

- (gint)scaleFactor
{
	return gdk_window_get_scale_factor([self WINDOW]);
}

- (OGGdkScreen*)screen
{
	return [[[OGGdkScreen alloc] initWithGObject:(GObject*)gdk_window_get_screen([self WINDOW])] autorelease];
}

- (GdkEventMask)sourceEvents:(GdkInputSource)source
{
	return gdk_window_get_source_events([self WINDOW], source);
}

- (GdkWindowState)state
{
	return gdk_window_get_state([self WINDOW]);
}

- (bool)supportMultidevice
{
	return gdk_window_get_support_multidevice([self WINDOW]);
}

- (OGGdkWindow*)toplevel
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gdk_window_get_toplevel([self WINDOW])] autorelease];
}

- (GdkWindowTypeHint)typeHint
{
	return gdk_window_get_type_hint([self WINDOW]);
}

- (cairo_region_t*)updateArea
{
	return gdk_window_get_update_area([self WINDOW]);
}

- (void)userData:(gpointer*)data
{
	gdk_window_get_user_data([self WINDOW], data);
}

- (cairo_region_t*)visibleRegion
{
	return gdk_window_get_visible_region([self WINDOW]);
}

- (OGGdkVisual*)visual
{
	return [[[OGGdkVisual alloc] initWithGObject:(GObject*)gdk_window_get_visual([self WINDOW])] autorelease];
}

- (int)width
{
	return gdk_window_get_width([self WINDOW]);
}

- (GdkWindowType)windowType
{
	return gdk_window_get_window_type([self WINDOW]);
}

- (bool)hasNative
{
	return gdk_window_has_native([self WINDOW]);
}

- (void)hide
{
	gdk_window_hide([self WINDOW]);
}

- (void)iconify
{
	gdk_window_iconify([self WINDOW]);
}

- (void)inputShapeCombineRegionWithShapeRegion:(const cairo_region_t*)shapeRegion offsetX:(gint)offsetX offsetY:(gint)offsetY
{
	gdk_window_input_shape_combine_region([self WINDOW], shapeRegion, offsetX, offsetY);
}

- (void)invalidateMaybeRecurseWithRegion:(const cairo_region_t*)region childFunc:(GdkWindowChildFunc)childFunc userData:(gpointer)userData
{
	gdk_window_invalidate_maybe_recurse([self WINDOW], region, childFunc, userData);
}

- (void)invalidateRectWithRect:(const GdkRectangle*)rect invalidateChildren:(bool)invalidateChildren
{
	gdk_window_invalidate_rect([self WINDOW], rect, invalidateChildren);
}

- (void)invalidateRegionWithRegion:(const cairo_region_t*)region invalidateChildren:(bool)invalidateChildren
{
	gdk_window_invalidate_region([self WINDOW], region, invalidateChildren);
}

- (bool)isDestroyed
{
	return gdk_window_is_destroyed([self WINDOW]);
}

- (bool)isInputOnly
{
	return gdk_window_is_input_only([self WINDOW]);
}

- (bool)isShaped
{
	return gdk_window_is_shaped([self WINDOW]);
}

- (bool)isViewable
{
	return gdk_window_is_viewable([self WINDOW]);
}

- (bool)isVisible
{
	return gdk_window_is_visible([self WINDOW]);
}

- (void)lower
{
	gdk_window_lower([self WINDOW]);
}

- (void)markPaintFromClip:(cairo_t*)cr
{
	gdk_window_mark_paint_from_clip([self WINDOW], cr);
}

- (void)maximize
{
	gdk_window_maximize([self WINDOW]);
}

- (void)mergeChildInputShapes
{
	gdk_window_merge_child_input_shapes([self WINDOW]);
}

- (void)mergeChildShapes
{
	gdk_window_merge_child_shapes([self WINDOW]);
}

- (void)moveWithX:(gint)x y:(gint)y
{
	gdk_window_move([self WINDOW], x, y);
}

- (void)moveRegionWithRegion:(const cairo_region_t*)region dx:(gint)dx dy:(gint)dy
{
	gdk_window_move_region([self WINDOW], region, dx, dy);
}

- (void)moveResizeWithX:(gint)x y:(gint)y width:(gint)width height:(gint)height
{
	gdk_window_move_resize([self WINDOW], x, y, width, height);
}

- (void)moveToRectWithRect:(const GdkRectangle*)rect rectAnchor:(GdkGravity)rectAnchor windowAnchor:(GdkGravity)windowAnchor anchorHints:(GdkAnchorHints)anchorHints rectAnchorDx:(gint)rectAnchorDx rectAnchorDy:(gint)rectAnchorDy
{
	gdk_window_move_to_rect([self WINDOW], rect, rectAnchor, windowAnchor, anchorHints, rectAnchorDx, rectAnchorDy);
}

- (GList*)peekChildren
{
	return gdk_window_peek_children([self WINDOW]);
}

- (void)processUpdates:(bool)updateChildren
{
	gdk_window_process_updates([self WINDOW], updateChildren);
}

- (void)raise
{
	gdk_window_raise([self WINDOW]);
}

- (void)registerDnd
{
	gdk_window_register_dnd([self WINDOW]);
}

- (void)removeFilterWithFunction:(GdkFilterFunc)function data:(gpointer)data
{
	gdk_window_remove_filter([self WINDOW], function, data);
}

- (void)reparentWithNewParent:(OGGdkWindow*)newParent x:(gint)x y:(gint)y
{
	gdk_window_reparent([self WINDOW], [newParent WINDOW], x, y);
}

- (void)resizeWithWidth:(gint)width height:(gint)height
{
	gdk_window_resize([self WINDOW], width, height);
}

- (void)restackWithSibling:(OGGdkWindow*)sibling above:(bool)above
{
	gdk_window_restack([self WINDOW], [sibling WINDOW], above);
}

- (void)scrollWithDx:(gint)dx dy:(gint)dy
{
	gdk_window_scroll([self WINDOW], dx, dy);
}

- (void)setAcceptFocus:(bool)acceptFocus
{
	gdk_window_set_accept_focus([self WINDOW], acceptFocus);
}

- (void)setBackground:(const GdkColor*)color
{
	gdk_window_set_background([self WINDOW], color);
}

- (void)setBackgroundPattern:(cairo_pattern_t*)pattern
{
	gdk_window_set_background_pattern([self WINDOW], pattern);
}

- (void)setBackgroundRgba:(const GdkRGBA*)rgba
{
	gdk_window_set_background_rgba([self WINDOW], rgba);
}

- (void)setChildInputShapes
{
	gdk_window_set_child_input_shapes([self WINDOW]);
}

- (void)setChildShapes
{
	gdk_window_set_child_shapes([self WINDOW]);
}

- (void)setComposited:(bool)composited
{
	gdk_window_set_composited([self WINDOW], composited);
}

- (void)setCursor:(OGGdkCursor*)cursor
{
	gdk_window_set_cursor([self WINDOW], [cursor CURSOR]);
}

- (void)setDecorations:(GdkWMDecoration)decorations
{
	gdk_window_set_decorations([self WINDOW], decorations);
}

- (void)setDeviceCursorWithDevice:(OGGdkDevice*)device cursor:(OGGdkCursor*)cursor
{
	gdk_window_set_device_cursor([self WINDOW], [device DEVICE], [cursor CURSOR]);
}

- (void)setDeviceEventsWithDevice:(OGGdkDevice*)device eventMask:(GdkEventMask)eventMask
{
	gdk_window_set_device_events([self WINDOW], [device DEVICE], eventMask);
}

- (void)setEventCompression:(bool)eventCompression
{
	gdk_window_set_event_compression([self WINDOW], eventCompression);
}

- (void)setEvents:(GdkEventMask)eventMask
{
	gdk_window_set_events([self WINDOW], eventMask);
}

- (void)setFocusOnMap:(bool)focusOnMap
{
	gdk_window_set_focus_on_map([self WINDOW], focusOnMap);
}

- (void)setFullscreenMode:(GdkFullscreenMode)mode
{
	gdk_window_set_fullscreen_mode([self WINDOW], mode);
}

- (void)setFunctions:(GdkWMFunction)functions
{
	gdk_window_set_functions([self WINDOW], functions);
}

- (void)setGeometryHintsWithGeometry:(const GdkGeometry*)geometry geomMask:(GdkWindowHints)geomMask
{
	gdk_window_set_geometry_hints([self WINDOW], geometry, geomMask);
}

- (void)setGroup:(OGGdkWindow*)leader
{
	gdk_window_set_group([self WINDOW], [leader WINDOW]);
}

- (void)setIconList:(GList*)pixbufs
{
	gdk_window_set_icon_list([self WINDOW], pixbufs);
}

- (void)setIconName:(OFString*)name
{
	gdk_window_set_icon_name([self WINDOW], [name UTF8String]);
}

- (void)setInvalidateHandler:(GdkWindowInvalidateHandlerFunc)handler
{
	gdk_window_set_invalidate_handler([self WINDOW], handler);
}

- (void)setKeepAbove:(bool)setting
{
	gdk_window_set_keep_above([self WINDOW], setting);
}

- (void)setKeepBelow:(bool)setting
{
	gdk_window_set_keep_below([self WINDOW], setting);
}

- (void)setModalHint:(bool)modal
{
	gdk_window_set_modal_hint([self WINDOW], modal);
}

- (void)setOpacity:(gdouble)opacity
{
	gdk_window_set_opacity([self WINDOW], opacity);
}

- (void)setOpaqueRegion:(cairo_region_t*)region
{
	gdk_window_set_opaque_region([self WINDOW], region);
}

- (void)setOverrideRedirect:(bool)overrideRedirect
{
	gdk_window_set_override_redirect([self WINDOW], overrideRedirect);
}

- (void)setPassThrough:(bool)passThrough
{
	gdk_window_set_pass_through([self WINDOW], passThrough);
}

- (void)setRole:(OFString*)role
{
	gdk_window_set_role([self WINDOW], [role UTF8String]);
}

- (void)setShadowWidthWithLeft:(gint)left right:(gint)right top:(gint)top bottom:(gint)bottom
{
	gdk_window_set_shadow_width([self WINDOW], left, right, top, bottom);
}

- (void)setSkipPagerHint:(bool)skipsPager
{
	gdk_window_set_skip_pager_hint([self WINDOW], skipsPager);
}

- (void)setSkipTaskbarHint:(bool)skipsTaskbar
{
	gdk_window_set_skip_taskbar_hint([self WINDOW], skipsTaskbar);
}

- (void)setSourceEventsWithSource:(GdkInputSource)source eventMask:(GdkEventMask)eventMask
{
	gdk_window_set_source_events([self WINDOW], source, eventMask);
}

- (void)setStartupId:(OFString*)startupId
{
	gdk_window_set_startup_id([self WINDOW], [startupId UTF8String]);
}

- (bool)setStaticGravities:(bool)useStatic
{
	return gdk_window_set_static_gravities([self WINDOW], useStatic);
}

- (void)setSupportMultidevice:(bool)supportMultidevice
{
	gdk_window_set_support_multidevice([self WINDOW], supportMultidevice);
}

- (void)setTitle:(OFString*)title
{
	gdk_window_set_title([self WINDOW], [title UTF8String]);
}

- (void)setTransientFor:(OGGdkWindow*)parent
{
	gdk_window_set_transient_for([self WINDOW], [parent WINDOW]);
}

- (void)setTypeHint:(GdkWindowTypeHint)hint
{
	gdk_window_set_type_hint([self WINDOW], hint);
}

- (void)setUrgencyHint:(bool)urgent
{
	gdk_window_set_urgency_hint([self WINDOW], urgent);
}

- (void)setUserData:(gpointer)userData
{
	gdk_window_set_user_data([self WINDOW], userData);
}

- (void)shapeCombineRegionWithShapeRegion:(const cairo_region_t*)shapeRegion offsetX:(gint)offsetX offsetY:(gint)offsetY
{
	gdk_window_shape_combine_region([self WINDOW], shapeRegion, offsetX, offsetY);
}

- (void)show
{
	gdk_window_show([self WINDOW]);
}

- (void)showUnraised
{
	gdk_window_show_unraised([self WINDOW]);
}

- (bool)showWindowMenu:(GdkEvent*)event
{
	return gdk_window_show_window_menu([self WINDOW], event);
}

- (void)stick
{
	gdk_window_stick([self WINDOW]);
}

- (void)thawToplevelUpdatesLibgtkOnly
{
	gdk_window_thaw_toplevel_updates_libgtk_only([self WINDOW]);
}

- (void)thawUpdates
{
	gdk_window_thaw_updates([self WINDOW]);
}

- (void)unfullscreen
{
	gdk_window_unfullscreen([self WINDOW]);
}

- (void)unmaximize
{
	gdk_window_unmaximize([self WINDOW]);
}

- (void)unstick
{
	gdk_window_unstick([self WINDOW]);
}

- (void)withdraw
{
	gdk_window_withdraw([self WINDOW]);
}


@end