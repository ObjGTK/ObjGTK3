/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWidget.h"

#import <OGdk3/OGGdkDisplay.h>
#import <OGdk3/OGGdkDevice.h>
#import <OGdk3/OGGdkFrameClock.h>
#import <OGPango/OGPangoContext.h>
#import <OGdk3/OGGdkScreen.h>
#import <OGAtk/OGAtkObject.h>
#import "OGTKSettings.h"
#import "OGTKRcStyle.h"
#import "OGTKWindow.h"
#import <OGdk3/OGGdkWindow.h>
#import <OGPango/OGPangoFontMap.h>
#import "OGTKStyle.h"
#import <OGdk3/OGGdkDragContext.h>
#import "OGTKAccelGroup.h"
#import <OGPango/OGPangoLayout.h>
#import <OGdk3/OGGdkVisual.h>
#import "OGTKStyleContext.h"
#import "OGTKClipboard.h"
#import <OGGdkPixbuf/OGGdkPixbuf.h>

@implementation OGTKWidget

+ (GtkTextDirection)defaultDirection
{
	return gtk_widget_get_default_direction();
}

+ (OGTKStyle*)defaultStyle
{
	return [[[OGTKStyle alloc] initWithGObject:(GObject*)gtk_widget_get_default_style()] autorelease];
}

+ (void)popCompositeChild
{
	gtk_widget_pop_composite_child();
}

+ (void)pushCompositeChild
{
	gtk_widget_push_composite_child();
}

+ (void)setDefaultDirection:(GtkTextDirection)dir
{
	gtk_widget_set_default_direction(dir);
}

- (GtkWidget*)WIDGET
{
	return GTK_WIDGET([self GOBJECT]);
}

- (bool)activate
{
	return gtk_widget_activate([self WIDGET]);
}

- (void)addAcceleratorWithAccelSignal:(OFString*)accelSignal accelGroup:(OGTKAccelGroup*)accelGroup accelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods accelFlags:(GtkAccelFlags)accelFlags
{
	gtk_widget_add_accelerator([self WIDGET], [accelSignal UTF8String], [accelGroup ACCELGROUP], accelKey, accelMods, accelFlags);
}

- (void)addDeviceEventsWithDevice:(OGGdkDevice*)device events:(GdkEventMask)events
{
	gtk_widget_add_device_events([self WIDGET], [device DEVICE], events);
}

- (void)addEvents:(gint)events
{
	gtk_widget_add_events([self WIDGET], events);
}

- (void)addMnemonicLabel:(OGTKWidget*)label
{
	gtk_widget_add_mnemonic_label([self WIDGET], [label WIDGET]);
}

- (guint)addTickCallbackWithCallback:(GtkTickCallback)callback userData:(gpointer)userData notify:(GDestroyNotify)notify
{
	return gtk_widget_add_tick_callback([self WIDGET], callback, userData, notify);
}

- (bool)canActivateAccel:(guint)signalId
{
	return gtk_widget_can_activate_accel([self WIDGET], signalId);
}

- (bool)childFocus:(GtkDirectionType)direction
{
	return gtk_widget_child_focus([self WIDGET], direction);
}

- (void)childNotify:(OFString*)childProperty
{
	gtk_widget_child_notify([self WIDGET], [childProperty UTF8String]);
}

- (void)classPathWithPathLength:(guint*)pathLength path:(gchar**)path pathReversed:(gchar**)pathReversed
{
	gtk_widget_class_path([self WIDGET], pathLength, path, pathReversed);
}

- (bool)computeExpand:(GtkOrientation)orientation
{
	return gtk_widget_compute_expand([self WIDGET], orientation);
}

- (OGPangoContext*)createPangoContext
{
	return [[[OGPangoContext alloc] initWithGObject:(GObject*)gtk_widget_create_pango_context([self WIDGET])] autorelease];
}

- (OGPangoLayout*)createPangoLayout:(OFString*)text
{
	return [[[OGPangoLayout alloc] initWithGObject:(GObject*)gtk_widget_create_pango_layout([self WIDGET], [text UTF8String])] autorelease];
}

- (void)destroy
{
	gtk_widget_destroy([self WIDGET]);
}

- (void)destroyed:(GtkWidget**)widgetPointer
{
	gtk_widget_destroyed([self WIDGET], widgetPointer);
}

- (bool)deviceIsShadowed:(OGGdkDevice*)device
{
	return gtk_widget_device_is_shadowed([self WIDGET], [device DEVICE]);
}

- (OGGdkDragContext*)dragBeginWithTargets:(GtkTargetList*)targets actions:(GdkDragAction)actions button:(gint)button event:(GdkEvent*)event
{
	return [[[OGGdkDragContext alloc] initWithGObject:(GObject*)gtk_drag_begin([self WIDGET], targets, actions, button, event)] autorelease];
}

- (OGGdkDragContext*)dragBeginWithCoordinatesWithTargets:(GtkTargetList*)targets actions:(GdkDragAction)actions button:(gint)button event:(GdkEvent*)event x:(gint)x y:(gint)y
{
	return [[[OGGdkDragContext alloc] initWithGObject:(GObject*)gtk_drag_begin_with_coordinates([self WIDGET], targets, actions, button, event, x, y)] autorelease];
}

- (bool)dragCheckThresholdWithStartX:(gint)startX startY:(gint)startY currentX:(gint)currentX currentY:(gint)currentY
{
	return gtk_drag_check_threshold([self WIDGET], startX, startY, currentX, currentY);
}

- (void)dragDestAddImageTargets
{
	gtk_drag_dest_add_image_targets([self WIDGET]);
}

- (void)dragDestAddTextTargets
{
	gtk_drag_dest_add_text_targets([self WIDGET]);
}

- (void)dragDestAddUriTargets
{
	gtk_drag_dest_add_uri_targets([self WIDGET]);
}

- (GdkAtom)dragDestFindTargetWithContext:(OGGdkDragContext*)context targetList:(GtkTargetList*)targetList
{
	return gtk_drag_dest_find_target([self WIDGET], [context DRAGCONTEXT], targetList);
}

- (GtkTargetList*)dragDestGetTargetList
{
	return gtk_drag_dest_get_target_list([self WIDGET]);
}

- (bool)dragDestGetTrackMotion
{
	return gtk_drag_dest_get_track_motion([self WIDGET]);
}

- (void)dragDestSetWithFlags:(GtkDestDefaults)flags targets:(const GtkTargetEntry*)targets ntargets:(gint)ntargets actions:(GdkDragAction)actions
{
	gtk_drag_dest_set([self WIDGET], flags, targets, ntargets, actions);
}

- (void)dragDestSetProxyWithProxyWindow:(OGGdkWindow*)proxyWindow protocol:(GdkDragProtocol)protocol useCoordinates:(bool)useCoordinates
{
	gtk_drag_dest_set_proxy([self WIDGET], [proxyWindow WINDOW], protocol, useCoordinates);
}

- (void)dragDestSetTargetList:(GtkTargetList*)targetList
{
	gtk_drag_dest_set_target_list([self WIDGET], targetList);
}

- (void)dragDestSetTrackMotion:(bool)trackMotion
{
	gtk_drag_dest_set_track_motion([self WIDGET], trackMotion);
}

- (void)dragDestUnset
{
	gtk_drag_dest_unset([self WIDGET]);
}

- (void)dragGetDataWithContext:(OGGdkDragContext*)context target:(GdkAtom)target time:(guint32)time
{
	gtk_drag_get_data([self WIDGET], [context DRAGCONTEXT], target, time);
}

- (void)dragHighlight
{
	gtk_drag_highlight([self WIDGET]);
}

- (void)dragSourceAddImageTargets
{
	gtk_drag_source_add_image_targets([self WIDGET]);
}

- (void)dragSourceAddTextTargets
{
	gtk_drag_source_add_text_targets([self WIDGET]);
}

- (void)dragSourceAddUriTargets
{
	gtk_drag_source_add_uri_targets([self WIDGET]);
}

- (GtkTargetList*)dragSourceGetTargetList
{
	return gtk_drag_source_get_target_list([self WIDGET]);
}

- (void)dragSourceSetWithStartButtonMask:(GdkModifierType)startButtonMask targets:(const GtkTargetEntry*)targets ntargets:(gint)ntargets actions:(GdkDragAction)actions
{
	gtk_drag_source_set([self WIDGET], startButtonMask, targets, ntargets, actions);
}

- (void)dragSourceSetIconGicon:(GIcon*)icon
{
	gtk_drag_source_set_icon_gicon([self WIDGET], icon);
}

- (void)dragSourceSetIconName:(OFString*)iconName
{
	gtk_drag_source_set_icon_name([self WIDGET], [iconName UTF8String]);
}

- (void)dragSourceSetIconPixbuf:(OGGdkPixbuf*)pixbuf
{
	gtk_drag_source_set_icon_pixbuf([self WIDGET], [pixbuf PIXBUF]);
}

- (void)dragSourceSetIconStock:(OFString*)stockId
{
	gtk_drag_source_set_icon_stock([self WIDGET], [stockId UTF8String]);
}

- (void)dragSourceSetTargetList:(GtkTargetList*)targetList
{
	gtk_drag_source_set_target_list([self WIDGET], targetList);
}

- (void)dragSourceUnset
{
	gtk_drag_source_unset([self WIDGET]);
}

- (void)dragUnhighlight
{
	gtk_drag_unhighlight([self WIDGET]);
}

- (void)draw:(cairo_t*)cr
{
	gtk_widget_draw([self WIDGET], cr);
}

- (void)ensureStyle
{
	gtk_widget_ensure_style([self WIDGET]);
}

- (void)errorBell
{
	gtk_widget_error_bell([self WIDGET]);
}

- (bool)event:(GdkEvent*)event
{
	return gtk_widget_event([self WIDGET], event);
}

- (void)freezeChildNotify
{
	gtk_widget_freeze_child_notify([self WIDGET]);
}

- (OGAtkObject*)accessible
{
	return [[[OGAtkObject alloc] initWithGObject:(GObject*)gtk_widget_get_accessible([self WIDGET])] autorelease];
}

- (GActionGroup*)actionGroup:(OFString*)prefix
{
	return gtk_widget_get_action_group([self WIDGET], [prefix UTF8String]);
}

- (int)allocatedBaseline
{
	return gtk_widget_get_allocated_baseline([self WIDGET]);
}

- (int)allocatedHeight
{
	return gtk_widget_get_allocated_height([self WIDGET]);
}

- (void)allocatedSizeWithAllocation:(GtkAllocation*)allocation baseline:(int*)baseline
{
	gtk_widget_get_allocated_size([self WIDGET], allocation, baseline);
}

- (int)allocatedWidth
{
	return gtk_widget_get_allocated_width([self WIDGET]);
}

- (void)allocation:(GtkAllocation*)allocation
{
	gtk_widget_get_allocation([self WIDGET], allocation);
}

- (OGTKWidget*)ancestor:(GType)widgetType
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_widget_get_ancestor([self WIDGET], widgetType)] autorelease];
}

- (bool)appPaintable
{
	return gtk_widget_get_app_paintable([self WIDGET]);
}

- (bool)canDefault
{
	return gtk_widget_get_can_default([self WIDGET]);
}

- (bool)canFocus
{
	return gtk_widget_get_can_focus([self WIDGET]);
}

- (void)childRequisition:(GtkRequisition*)requisition
{
	gtk_widget_get_child_requisition([self WIDGET], requisition);
}

- (bool)childVisible
{
	return gtk_widget_get_child_visible([self WIDGET]);
}

- (void)clip:(GtkAllocation*)clip
{
	gtk_widget_get_clip([self WIDGET], clip);
}

- (OGTKClipboard*)clipboard:(GdkAtom)selection
{
	return [[[OGTKClipboard alloc] initWithGObject:(GObject*)gtk_widget_get_clipboard([self WIDGET], selection)] autorelease];
}

- (OFString*)compositeName
{
	return [OFString stringWithUTF8String:gtk_widget_get_composite_name([self WIDGET])];
}

- (bool)deviceEnabled:(OGGdkDevice*)device
{
	return gtk_widget_get_device_enabled([self WIDGET], [device DEVICE]);
}

- (GdkEventMask)deviceEvents:(OGGdkDevice*)device
{
	return gtk_widget_get_device_events([self WIDGET], [device DEVICE]);
}

- (GtkTextDirection)direction
{
	return gtk_widget_get_direction([self WIDGET]);
}

- (OGGdkDisplay*)display
{
	return [[[OGGdkDisplay alloc] initWithGObject:(GObject*)gtk_widget_get_display([self WIDGET])] autorelease];
}

- (bool)doubleBuffered
{
	return gtk_widget_get_double_buffered([self WIDGET]);
}

- (gint)events
{
	return gtk_widget_get_events([self WIDGET]);
}

- (bool)focusOnClick
{
	return gtk_widget_get_focus_on_click([self WIDGET]);
}

- (OGPangoFontMap*)fontMap
{
	return [[[OGPangoFontMap alloc] initWithGObject:(GObject*)gtk_widget_get_font_map([self WIDGET])] autorelease];
}

- (const cairo_font_options_t*)fontOptions
{
	return gtk_widget_get_font_options([self WIDGET]);
}

- (OGGdkFrameClock*)frameClock
{
	return [[[OGGdkFrameClock alloc] initWithGObject:(GObject*)gtk_widget_get_frame_clock([self WIDGET])] autorelease];
}

- (GtkAlign)halign
{
	return gtk_widget_get_halign([self WIDGET]);
}

- (bool)hasTooltip
{
	return gtk_widget_get_has_tooltip([self WIDGET]);
}

- (bool)hasWindow
{
	return gtk_widget_get_has_window([self WIDGET]);
}

- (bool)hexpand
{
	return gtk_widget_get_hexpand([self WIDGET]);
}

- (bool)hexpandSet
{
	return gtk_widget_get_hexpand_set([self WIDGET]);
}

- (bool)mapped
{
	return gtk_widget_get_mapped([self WIDGET]);
}

- (gint)marginBottom
{
	return gtk_widget_get_margin_bottom([self WIDGET]);
}

- (gint)marginEnd
{
	return gtk_widget_get_margin_end([self WIDGET]);
}

- (gint)marginLeft
{
	return gtk_widget_get_margin_left([self WIDGET]);
}

- (gint)marginRight
{
	return gtk_widget_get_margin_right([self WIDGET]);
}

- (gint)marginStart
{
	return gtk_widget_get_margin_start([self WIDGET]);
}

- (gint)marginTop
{
	return gtk_widget_get_margin_top([self WIDGET]);
}

- (GdkModifierType)modifierMask:(GdkModifierIntent)intent
{
	return gtk_widget_get_modifier_mask([self WIDGET], intent);
}

- (OGTKRcStyle*)modifierStyle
{
	return [[[OGTKRcStyle alloc] initWithGObject:(GObject*)gtk_widget_get_modifier_style([self WIDGET])] autorelease];
}

- (OFString*)name
{
	return [OFString stringWithUTF8String:gtk_widget_get_name([self WIDGET])];
}

- (bool)noShowAll
{
	return gtk_widget_get_no_show_all([self WIDGET]);
}

- (double)opacity
{
	return gtk_widget_get_opacity([self WIDGET]);
}

- (OGPangoContext*)pangoContext
{
	return [[[OGPangoContext alloc] initWithGObject:(GObject*)gtk_widget_get_pango_context([self WIDGET])] autorelease];
}

- (OGTKWidget*)parent
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_widget_get_parent([self WIDGET])] autorelease];
}

- (OGGdkWindow*)parentWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_widget_get_parent_window([self WIDGET])] autorelease];
}

- (GtkWidgetPath*)path
{
	return gtk_widget_get_path([self WIDGET]);
}

- (void)pointerWithX:(gint*)x y:(gint*)y
{
	gtk_widget_get_pointer([self WIDGET], x, y);
}

- (void)preferredHeightWithMinimumHeight:(gint*)minimumHeight naturalHeight:(gint*)naturalHeight
{
	gtk_widget_get_preferred_height([self WIDGET], minimumHeight, naturalHeight);
}

- (void)preferredHeightAndBaselineForWidthWithWidth:(gint)width minimumHeight:(gint*)minimumHeight naturalHeight:(gint*)naturalHeight minimumBaseline:(gint*)minimumBaseline naturalBaseline:(gint*)naturalBaseline
{
	gtk_widget_get_preferred_height_and_baseline_for_width([self WIDGET], width, minimumHeight, naturalHeight, minimumBaseline, naturalBaseline);
}

- (void)preferredHeightForWidthWithWidth:(gint)width minimumHeight:(gint*)minimumHeight naturalHeight:(gint*)naturalHeight
{
	gtk_widget_get_preferred_height_for_width([self WIDGET], width, minimumHeight, naturalHeight);
}

- (void)preferredSizeWithMinimumSize:(GtkRequisition*)minimumSize naturalSize:(GtkRequisition*)naturalSize
{
	gtk_widget_get_preferred_size([self WIDGET], minimumSize, naturalSize);
}

- (void)preferredWidthWithMinimumWidth:(gint*)minimumWidth naturalWidth:(gint*)naturalWidth
{
	gtk_widget_get_preferred_width([self WIDGET], minimumWidth, naturalWidth);
}

- (void)preferredWidthForHeightWithHeight:(gint)height minimumWidth:(gint*)minimumWidth naturalWidth:(gint*)naturalWidth
{
	gtk_widget_get_preferred_width_for_height([self WIDGET], height, minimumWidth, naturalWidth);
}

- (bool)realized
{
	return gtk_widget_get_realized([self WIDGET]);
}

- (bool)receivesDefault
{
	return gtk_widget_get_receives_default([self WIDGET]);
}

- (GtkSizeRequestMode)requestMode
{
	return gtk_widget_get_request_mode([self WIDGET]);
}

- (void)requisition:(GtkRequisition*)requisition
{
	gtk_widget_get_requisition([self WIDGET], requisition);
}

- (OGGdkWindow*)rootWindow
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_widget_get_root_window([self WIDGET])] autorelease];
}

- (gint)scaleFactor
{
	return gtk_widget_get_scale_factor([self WIDGET]);
}

- (OGGdkScreen*)screen
{
	return [[[OGGdkScreen alloc] initWithGObject:(GObject*)gtk_widget_get_screen([self WIDGET])] autorelease];
}

- (bool)sensitive
{
	return gtk_widget_get_sensitive([self WIDGET]);
}

- (OGTKSettings*)settings
{
	return [[[OGTKSettings alloc] initWithGObject:(GObject*)gtk_widget_get_settings([self WIDGET])] autorelease];
}

- (void)sizeRequestWithWidth:(gint*)width height:(gint*)height
{
	gtk_widget_get_size_request([self WIDGET], width, height);
}

- (GtkStateType)state
{
	return gtk_widget_get_state([self WIDGET]);
}

- (GtkStateFlags)stateFlags
{
	return gtk_widget_get_state_flags([self WIDGET]);
}

- (OGTKStyle*)style
{
	return [[[OGTKStyle alloc] initWithGObject:(GObject*)gtk_widget_get_style([self WIDGET])] autorelease];
}

- (OGTKStyleContext*)styleContext
{
	return [[[OGTKStyleContext alloc] initWithGObject:(GObject*)gtk_widget_get_style_context([self WIDGET])] autorelease];
}

- (bool)supportMultidevice
{
	return gtk_widget_get_support_multidevice([self WIDGET]);
}

- (GObject*)templateChildWithWidgetType:(GType)widgetType name:(OFString*)name
{
	return gtk_widget_get_template_child([self WIDGET], widgetType, [name UTF8String]);
}

- (OFString*)tooltipMarkup
{
	return [OFString stringWithUTF8String:gtk_widget_get_tooltip_markup([self WIDGET])];
}

- (OFString*)tooltipText
{
	return [OFString stringWithUTF8String:gtk_widget_get_tooltip_text([self WIDGET])];
}

- (OGTKWindow*)tooltipWindow
{
	return [[[OGTKWindow alloc] initWithGObject:(GObject*)gtk_widget_get_tooltip_window([self WIDGET])] autorelease];
}

- (OGTKWidget*)toplevel
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_widget_get_toplevel([self WIDGET])] autorelease];
}

- (GtkAlign)valign
{
	return gtk_widget_get_valign([self WIDGET]);
}

- (GtkAlign)valignWithBaseline
{
	return gtk_widget_get_valign_with_baseline([self WIDGET]);
}

- (bool)vexpand
{
	return gtk_widget_get_vexpand([self WIDGET]);
}

- (bool)vexpandSet
{
	return gtk_widget_get_vexpand_set([self WIDGET]);
}

- (bool)visible
{
	return gtk_widget_get_visible([self WIDGET]);
}

- (OGGdkVisual*)visual
{
	return [[[OGGdkVisual alloc] initWithGObject:(GObject*)gtk_widget_get_visual([self WIDGET])] autorelease];
}

- (OGGdkWindow*)window
{
	return [[[OGGdkWindow alloc] initWithGObject:(GObject*)gtk_widget_get_window([self WIDGET])] autorelease];
}

- (void)grabAdd
{
	gtk_grab_add([self WIDGET]);
}

- (void)grabDefault
{
	gtk_widget_grab_default([self WIDGET]);
}

- (void)grabFocus
{
	gtk_widget_grab_focus([self WIDGET]);
}

- (void)grabRemove
{
	gtk_grab_remove([self WIDGET]);
}

- (bool)hasDefault
{
	return gtk_widget_has_default([self WIDGET]);
}

- (bool)hasFocus
{
	return gtk_widget_has_focus([self WIDGET]);
}

- (bool)hasGrab
{
	return gtk_widget_has_grab([self WIDGET]);
}

- (bool)hasRcStyle
{
	return gtk_widget_has_rc_style([self WIDGET]);
}

- (bool)hasScreen
{
	return gtk_widget_has_screen([self WIDGET]);
}

- (bool)hasVisibleFocus
{
	return gtk_widget_has_visible_focus([self WIDGET]);
}

- (void)hide
{
	gtk_widget_hide([self WIDGET]);
}

- (bool)hideOnDelete
{
	return gtk_widget_hide_on_delete([self WIDGET]);
}

- (bool)inDestruction
{
	return gtk_widget_in_destruction([self WIDGET]);
}

- (void)initTemplate
{
	gtk_widget_init_template([self WIDGET]);
}

- (void)inputShapeCombineRegion:(cairo_region_t*)region
{
	gtk_widget_input_shape_combine_region([self WIDGET], region);
}

- (void)insertActionGroupWithName:(OFString*)name group:(GActionGroup*)group
{
	gtk_widget_insert_action_group([self WIDGET], [name UTF8String], group);
}

- (bool)intersectWithArea:(const GdkRectangle*)area intersection:(GdkRectangle*)intersection
{
	return gtk_widget_intersect([self WIDGET], area, intersection);
}

- (bool)isAncestor:(OGTKWidget*)ancestor
{
	return gtk_widget_is_ancestor([self WIDGET], [ancestor WIDGET]);
}

- (bool)isComposited
{
	return gtk_widget_is_composited([self WIDGET]);
}

- (bool)isDrawable
{
	return gtk_widget_is_drawable([self WIDGET]);
}

- (bool)isFocus
{
	return gtk_widget_is_focus([self WIDGET]);
}

- (bool)isSensitive
{
	return gtk_widget_is_sensitive([self WIDGET]);
}

- (bool)isToplevel
{
	return gtk_widget_is_toplevel([self WIDGET]);
}

- (bool)isVisible
{
	return gtk_widget_is_visible([self WIDGET]);
}

- (bool)keynavFailed:(GtkDirectionType)direction
{
	return gtk_widget_keynav_failed([self WIDGET], direction);
}

- (GList*)listAccelClosures
{
	return gtk_widget_list_accel_closures([self WIDGET]);
}

- (const gchar**)listActionPrefixes
{
	return gtk_widget_list_action_prefixes([self WIDGET]);
}

- (GList*)listMnemonicLabels
{
	return gtk_widget_list_mnemonic_labels([self WIDGET]);
}

- (void)map
{
	gtk_widget_map([self WIDGET]);
}

- (bool)mnemonicActivate:(bool)groupCycling
{
	return gtk_widget_mnemonic_activate([self WIDGET], groupCycling);
}

- (void)modifyBaseWithState:(GtkStateType)state color:(const GdkColor*)color
{
	gtk_widget_modify_base([self WIDGET], state, color);
}

- (void)modifyBgWithState:(GtkStateType)state color:(const GdkColor*)color
{
	gtk_widget_modify_bg([self WIDGET], state, color);
}

- (void)modifyCursorWithPrimary:(const GdkColor*)primary secondary:(const GdkColor*)secondary
{
	gtk_widget_modify_cursor([self WIDGET], primary, secondary);
}

- (void)modifyFgWithState:(GtkStateType)state color:(const GdkColor*)color
{
	gtk_widget_modify_fg([self WIDGET], state, color);
}

- (void)modifyFont:(PangoFontDescription*)fontDesc
{
	gtk_widget_modify_font([self WIDGET], fontDesc);
}

- (void)modifyStyle:(OGTKRcStyle*)style
{
	gtk_widget_modify_style([self WIDGET], [style RCSTYLE]);
}

- (void)modifyTextWithState:(GtkStateType)state color:(const GdkColor*)color
{
	gtk_widget_modify_text([self WIDGET], state, color);
}

- (void)overrideBackgroundColorWithState:(GtkStateFlags)state color:(const GdkRGBA*)color
{
	gtk_widget_override_background_color([self WIDGET], state, color);
}

- (void)overrideColorWithState:(GtkStateFlags)state color:(const GdkRGBA*)color
{
	gtk_widget_override_color([self WIDGET], state, color);
}

- (void)overrideCursorWithCursor:(const GdkRGBA*)cursor secondaryCursor:(const GdkRGBA*)secondaryCursor
{
	gtk_widget_override_cursor([self WIDGET], cursor, secondaryCursor);
}

- (void)overrideFont:(const PangoFontDescription*)fontDesc
{
	gtk_widget_override_font([self WIDGET], fontDesc);
}

- (void)overrideSymbolicColorWithName:(OFString*)name color:(const GdkRGBA*)color
{
	gtk_widget_override_symbolic_color([self WIDGET], [name UTF8String], color);
}

- (void)pathWithPathLength:(guint*)pathLength path:(gchar**)path pathReversed:(gchar**)pathReversed
{
	gtk_widget_path([self WIDGET], pathLength, path, pathReversed);
}

- (void)queueAllocate
{
	gtk_widget_queue_allocate([self WIDGET]);
}

- (void)queueComputeExpand
{
	gtk_widget_queue_compute_expand([self WIDGET]);
}

- (void)queueDraw
{
	gtk_widget_queue_draw([self WIDGET]);
}

- (void)queueDrawAreaWithX:(gint)x y:(gint)y width:(gint)width height:(gint)height
{
	gtk_widget_queue_draw_area([self WIDGET], x, y, width, height);
}

- (void)queueDrawRegion:(const cairo_region_t*)region
{
	gtk_widget_queue_draw_region([self WIDGET], region);
}

- (void)queueResize
{
	gtk_widget_queue_resize([self WIDGET]);
}

- (void)queueResizeNoRedraw
{
	gtk_widget_queue_resize_no_redraw([self WIDGET]);
}

- (void)realize
{
	gtk_widget_realize([self WIDGET]);
}

- (cairo_region_t*)regionIntersect:(const cairo_region_t*)region
{
	return gtk_widget_region_intersect([self WIDGET], region);
}

- (void)registerWindow:(OGGdkWindow*)window
{
	gtk_widget_register_window([self WIDGET], [window WINDOW]);
}

- (bool)removeAcceleratorWithAccelGroup:(OGTKAccelGroup*)accelGroup accelKey:(guint)accelKey accelMods:(GdkModifierType)accelMods
{
	return gtk_widget_remove_accelerator([self WIDGET], [accelGroup ACCELGROUP], accelKey, accelMods);
}

- (void)removeMnemonicLabel:(OGTKWidget*)label
{
	gtk_widget_remove_mnemonic_label([self WIDGET], [label WIDGET]);
}

- (void)removeTickCallback:(guint)id
{
	gtk_widget_remove_tick_callback([self WIDGET], id);
}

- (OGGdkPixbuf*)renderIconWithStockId:(OFString*)stockId size:(GtkIconSize)size detail:(OFString*)detail
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_widget_render_icon([self WIDGET], [stockId UTF8String], size, [detail UTF8String])] autorelease];
}

- (OGGdkPixbuf*)renderIconPixbufWithStockId:(OFString*)stockId size:(GtkIconSize)size
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_widget_render_icon_pixbuf([self WIDGET], [stockId UTF8String], size)] autorelease];
}

- (void)reparent:(OGTKWidget*)newParent
{
	gtk_widget_reparent([self WIDGET], [newParent WIDGET]);
}

- (void)resetRcStyles
{
	gtk_widget_reset_rc_styles([self WIDGET]);
}

- (void)resetStyle
{
	gtk_widget_reset_style([self WIDGET]);
}

- (gint)sendExpose:(GdkEvent*)event
{
	return gtk_widget_send_expose([self WIDGET], event);
}

- (bool)sendFocusChange:(GdkEvent*)event
{
	return gtk_widget_send_focus_change([self WIDGET], event);
}

- (void)setAccelPathWithAccelPath:(OFString*)accelPath accelGroup:(OGTKAccelGroup*)accelGroup
{
	gtk_widget_set_accel_path([self WIDGET], [accelPath UTF8String], [accelGroup ACCELGROUP]);
}

- (void)setAllocation:(const GtkAllocation*)allocation
{
	gtk_widget_set_allocation([self WIDGET], allocation);
}

- (void)setAppPaintable:(bool)appPaintable
{
	gtk_widget_set_app_paintable([self WIDGET], appPaintable);
}

- (void)setCanDefault:(bool)canDefault
{
	gtk_widget_set_can_default([self WIDGET], canDefault);
}

- (void)setCanFocus:(bool)canFocus
{
	gtk_widget_set_can_focus([self WIDGET], canFocus);
}

- (void)setChildVisible:(bool)isVisible
{
	gtk_widget_set_child_visible([self WIDGET], isVisible);
}

- (void)setClip:(const GtkAllocation*)clip
{
	gtk_widget_set_clip([self WIDGET], clip);
}

- (void)setCompositeName:(OFString*)name
{
	gtk_widget_set_composite_name([self WIDGET], [name UTF8String]);
}

- (void)setDeviceEnabledWithDevice:(OGGdkDevice*)device enabled:(bool)enabled
{
	gtk_widget_set_device_enabled([self WIDGET], [device DEVICE], enabled);
}

- (void)setDeviceEventsWithDevice:(OGGdkDevice*)device events:(GdkEventMask)events
{
	gtk_widget_set_device_events([self WIDGET], [device DEVICE], events);
}

- (void)setDirection:(GtkTextDirection)dir
{
	gtk_widget_set_direction([self WIDGET], dir);
}

- (void)setDoubleBuffered:(bool)doubleBuffered
{
	gtk_widget_set_double_buffered([self WIDGET], doubleBuffered);
}

- (void)setEvents:(gint)events
{
	gtk_widget_set_events([self WIDGET], events);
}

- (void)setFocusOnClick:(bool)focusOnClick
{
	gtk_widget_set_focus_on_click([self WIDGET], focusOnClick);
}

- (void)setFontMap:(OGPangoFontMap*)fontMap
{
	gtk_widget_set_font_map([self WIDGET], [fontMap FONTMAP]);
}

- (void)setFontOptions:(const cairo_font_options_t*)options
{
	gtk_widget_set_font_options([self WIDGET], options);
}

- (void)setHalign:(GtkAlign)align
{
	gtk_widget_set_halign([self WIDGET], align);
}

- (void)setHasTooltip:(bool)hasTooltip
{
	gtk_widget_set_has_tooltip([self WIDGET], hasTooltip);
}

- (void)setHasWindow:(bool)hasWindow
{
	gtk_widget_set_has_window([self WIDGET], hasWindow);
}

- (void)setHexpand:(bool)expand
{
	gtk_widget_set_hexpand([self WIDGET], expand);
}

- (void)setHexpandSet:(bool)set
{
	gtk_widget_set_hexpand_set([self WIDGET], set);
}

- (void)setMapped:(bool)mapped
{
	gtk_widget_set_mapped([self WIDGET], mapped);
}

- (void)setMarginBottom:(gint)margin
{
	gtk_widget_set_margin_bottom([self WIDGET], margin);
}

- (void)setMarginEnd:(gint)margin
{
	gtk_widget_set_margin_end([self WIDGET], margin);
}

- (void)setMarginLeft:(gint)margin
{
	gtk_widget_set_margin_left([self WIDGET], margin);
}

- (void)setMarginRight:(gint)margin
{
	gtk_widget_set_margin_right([self WIDGET], margin);
}

- (void)setMarginStart:(gint)margin
{
	gtk_widget_set_margin_start([self WIDGET], margin);
}

- (void)setMarginTop:(gint)margin
{
	gtk_widget_set_margin_top([self WIDGET], margin);
}

- (void)setName:(OFString*)name
{
	gtk_widget_set_name([self WIDGET], [name UTF8String]);
}

- (void)setNoShowAll:(bool)noShowAll
{
	gtk_widget_set_no_show_all([self WIDGET], noShowAll);
}

- (void)setOpacity:(double)opacity
{
	gtk_widget_set_opacity([self WIDGET], opacity);
}

- (void)setParent:(OGTKWidget*)parent
{
	gtk_widget_set_parent([self WIDGET], [parent WIDGET]);
}

- (void)setParentWindow:(OGGdkWindow*)parentWindow
{
	gtk_widget_set_parent_window([self WIDGET], [parentWindow WINDOW]);
}

- (void)setRealized:(bool)realized
{
	gtk_widget_set_realized([self WIDGET], realized);
}

- (void)setReceivesDefault:(bool)receivesDefault
{
	gtk_widget_set_receives_default([self WIDGET], receivesDefault);
}

- (void)setRedrawOnAllocate:(bool)redrawOnAllocate
{
	gtk_widget_set_redraw_on_allocate([self WIDGET], redrawOnAllocate);
}

- (void)setSensitive:(bool)sensitive
{
	gtk_widget_set_sensitive([self WIDGET], sensitive);
}

- (void)setSizeRequestWithWidth:(gint)width height:(gint)height
{
	gtk_widget_set_size_request([self WIDGET], width, height);
}

- (void)setState:(GtkStateType)state
{
	gtk_widget_set_state([self WIDGET], state);
}

- (void)setStateFlagsWithFlags:(GtkStateFlags)flags clear:(bool)clear
{
	gtk_widget_set_state_flags([self WIDGET], flags, clear);
}

- (void)setStyle:(OGTKStyle*)style
{
	gtk_widget_set_style([self WIDGET], [style STYLE]);
}

- (void)setSupportMultidevice:(bool)supportMultidevice
{
	gtk_widget_set_support_multidevice([self WIDGET], supportMultidevice);
}

- (void)setTooltipMarkup:(OFString*)markup
{
	gtk_widget_set_tooltip_markup([self WIDGET], [markup UTF8String]);
}

- (void)setTooltipText:(OFString*)text
{
	gtk_widget_set_tooltip_text([self WIDGET], [text UTF8String]);
}

- (void)setTooltipWindow:(OGTKWindow*)customWindow
{
	gtk_widget_set_tooltip_window([self WIDGET], [customWindow WINDOW]);
}

- (void)setValign:(GtkAlign)align
{
	gtk_widget_set_valign([self WIDGET], align);
}

- (void)setVexpand:(bool)expand
{
	gtk_widget_set_vexpand([self WIDGET], expand);
}

- (void)setVexpandSet:(bool)set
{
	gtk_widget_set_vexpand_set([self WIDGET], set);
}

- (void)setVisible:(bool)visible
{
	gtk_widget_set_visible([self WIDGET], visible);
}

- (void)setVisual:(OGGdkVisual*)visual
{
	gtk_widget_set_visual([self WIDGET], [visual VISUAL]);
}

- (void)setWindow:(OGGdkWindow*)window
{
	gtk_widget_set_window([self WIDGET], [window WINDOW]);
}

- (void)shapeCombineRegion:(cairo_region_t*)region
{
	gtk_widget_shape_combine_region([self WIDGET], region);
}

- (void)show
{
	gtk_widget_show([self WIDGET]);
}

- (void)showAll
{
	gtk_widget_show_all([self WIDGET]);
}

- (void)showNow
{
	gtk_widget_show_now([self WIDGET]);
}

- (void)sizeAllocate:(GtkAllocation*)allocation
{
	gtk_widget_size_allocate([self WIDGET], allocation);
}

- (void)sizeAllocateWithBaselineWithAllocation:(GtkAllocation*)allocation baseline:(gint)baseline
{
	gtk_widget_size_allocate_with_baseline([self WIDGET], allocation, baseline);
}

- (void)sizeRequest:(GtkRequisition*)requisition
{
	gtk_widget_size_request([self WIDGET], requisition);
}

- (void)styleAttach
{
	gtk_widget_style_attach([self WIDGET]);
}

- (void)styleGetPropertyWithPropertyName:(OFString*)propertyName value:(GValue*)value
{
	gtk_widget_style_get_property([self WIDGET], [propertyName UTF8String], value);
}

- (void)styleGetValistWithFirstPropertyName:(OFString*)firstPropertyName varArgs:(va_list)varArgs
{
	gtk_widget_style_get_valist([self WIDGET], [firstPropertyName UTF8String], varArgs);
}

- (void)thawChildNotify
{
	gtk_widget_thaw_child_notify([self WIDGET]);
}

- (bool)translateCoordinatesWithDestWidget:(OGTKWidget*)destWidget srcX:(gint)srcX srcY:(gint)srcY destX:(gint*)destX destY:(gint*)destY
{
	return gtk_widget_translate_coordinates([self WIDGET], [destWidget WIDGET], srcX, srcY, destX, destY);
}

- (void)triggerTooltipQuery
{
	gtk_widget_trigger_tooltip_query([self WIDGET]);
}

- (void)unmap
{
	gtk_widget_unmap([self WIDGET]);
}

- (void)unparent
{
	gtk_widget_unparent([self WIDGET]);
}

- (void)unrealize
{
	gtk_widget_unrealize([self WIDGET]);
}

- (void)unregisterWindow:(OGGdkWindow*)window
{
	gtk_widget_unregister_window([self WIDGET], [window WINDOW]);
}

- (void)unsetStateFlags:(GtkStateFlags)flags
{
	gtk_widget_unset_state_flags([self WIDGET], flags);
}


@end