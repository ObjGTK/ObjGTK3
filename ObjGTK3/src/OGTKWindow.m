/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWindow.h"

#import "OGTKApplication.h"
#import <OGdk3/OGGdkScreen.h>
#import "OGTKAccelGroup.h"
#import "OGTKWidget.h"
#import "OGTKWindowGroup.h"
#import <OGGdkPixbuf/OGGdkPixbuf.h>

@implementation OGTKWindow

+ (GList*)defaultIconList
{
	return gtk_window_get_default_icon_list();
}

+ (OFString*)defaultIconName
{
	return [OFString stringWithUTF8String:gtk_window_get_default_icon_name()];
}

+ (GList*)listToplevels
{
	return gtk_window_list_toplevels();
}

+ (void)setAutoStartupNotification:(bool)setting
{
	gtk_window_set_auto_startup_notification(setting);
}

+ (void)setDefaultIcon:(OGGdkPixbuf*)icon
{
	gtk_window_set_default_icon([icon PIXBUF]);
}

+ (bool)setDefaultIconFromFileWithFilename:(OFString*)filename err:(GError**)err
{
	return gtk_window_set_default_icon_from_file([filename UTF8String], err);
}

+ (void)setDefaultIconList:(GList*)list
{
	gtk_window_set_default_icon_list(list);
}

+ (void)setDefaultIconName:(OFString*)name
{
	gtk_window_set_default_icon_name([name UTF8String]);
}

+ (void)setInteractiveDebugging:(bool)enable
{
	gtk_window_set_interactive_debugging(enable);
}

- (instancetype)init:(GtkWindowType)type
{
	self = [super initWithGObject:(GObject*)gtk_window_new(type)];

	return self;
}

- (GtkWindow*)WINDOW
{
	return GTK_WINDOW([self GOBJECT]);
}

- (bool)activateDefault
{
	return gtk_window_activate_default([self WINDOW]);
}

- (bool)activateFocus
{
	return gtk_window_activate_focus([self WINDOW]);
}

- (bool)activateKey:(GdkEventKey*)event
{
	return gtk_window_activate_key([self WINDOW], event);
}

- (void)addAccelGroup:(OGTKAccelGroup*)accelGroup
{
	gtk_window_add_accel_group([self WINDOW], [accelGroup ACCELGROUP]);
}

- (void)addMnemonicWithKeyval:(guint)keyval target:(OGTKWidget*)target
{
	gtk_window_add_mnemonic([self WINDOW], keyval, [target WIDGET]);
}

- (void)beginMoveDragWithButton:(gint)button rootX:(gint)rootX rootY:(gint)rootY timestamp:(guint32)timestamp
{
	gtk_window_begin_move_drag([self WINDOW], button, rootX, rootY, timestamp);
}

- (void)beginResizeDragWithEdge:(GdkWindowEdge)edge button:(gint)button rootX:(gint)rootX rootY:(gint)rootY timestamp:(guint32)timestamp
{
	gtk_window_begin_resize_drag([self WINDOW], edge, button, rootX, rootY, timestamp);
}

- (void)close
{
	gtk_window_close([self WINDOW]);
}

- (void)deiconify
{
	gtk_window_deiconify([self WINDOW]);
}

- (void)fullscreen
{
	gtk_window_fullscreen([self WINDOW]);
}

- (void)fullscreenOnMonitorWithScreen:(OGGdkScreen*)screen monitor:(gint)monitor
{
	gtk_window_fullscreen_on_monitor([self WINDOW], [screen SCREEN], monitor);
}

- (bool)acceptFocus
{
	return gtk_window_get_accept_focus([self WINDOW]);
}

- (OGTKApplication*)application
{
	return [[[OGTKApplication alloc] initWithGObject:(GObject*)gtk_window_get_application([self WINDOW])] autorelease];
}

- (OGTKWidget*)attachedTo
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_window_get_attached_to([self WINDOW])] autorelease];
}

- (bool)decorated
{
	return gtk_window_get_decorated([self WINDOW]);
}

- (void)defaultSizeWithWidth:(gint*)width height:(gint*)height
{
	gtk_window_get_default_size([self WINDOW], width, height);
}

- (OGTKWidget*)defaultWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_window_get_default_widget([self WINDOW])] autorelease];
}

- (bool)deletable
{
	return gtk_window_get_deletable([self WINDOW]);
}

- (bool)destroyWithParent
{
	return gtk_window_get_destroy_with_parent([self WINDOW]);
}

- (OGTKWidget*)focus
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_window_get_focus([self WINDOW])] autorelease];
}

- (bool)focusOnMap
{
	return gtk_window_get_focus_on_map([self WINDOW]);
}

- (bool)focusVisible
{
	return gtk_window_get_focus_visible([self WINDOW]);
}

- (GdkGravity)gravity
{
	return gtk_window_get_gravity([self WINDOW]);
}

- (OGTKWindowGroup*)group
{
	return [[[OGTKWindowGroup alloc] initWithGObject:(GObject*)gtk_window_get_group([self WINDOW])] autorelease];
}

- (bool)hasResizeGrip
{
	return gtk_window_get_has_resize_grip([self WINDOW]);
}

- (bool)hideTitlebarWhenMaximized
{
	return gtk_window_get_hide_titlebar_when_maximized([self WINDOW]);
}

- (OGGdkPixbuf*)icon
{
	return [[[OGGdkPixbuf alloc] initWithGObject:(GObject*)gtk_window_get_icon([self WINDOW])] autorelease];
}

- (GList*)iconList
{
	return gtk_window_get_icon_list([self WINDOW]);
}

- (OFString*)iconName
{
	return [OFString stringWithUTF8String:gtk_window_get_icon_name([self WINDOW])];
}

- (GdkModifierType)mnemonicModifier
{
	return gtk_window_get_mnemonic_modifier([self WINDOW]);
}

- (bool)mnemonicsVisible
{
	return gtk_window_get_mnemonics_visible([self WINDOW]);
}

- (bool)modal
{
	return gtk_window_get_modal([self WINDOW]);
}

- (gdouble)opacity
{
	return gtk_window_get_opacity([self WINDOW]);
}

- (void)positionWithRootX:(gint*)rootX rootY:(gint*)rootY
{
	gtk_window_get_position([self WINDOW], rootX, rootY);
}

- (bool)resizable
{
	return gtk_window_get_resizable([self WINDOW]);
}

- (bool)resizeGripArea:(GdkRectangle*)rect
{
	return gtk_window_get_resize_grip_area([self WINDOW], rect);
}

- (OFString*)role
{
	return [OFString stringWithUTF8String:gtk_window_get_role([self WINDOW])];
}

- (OGGdkScreen*)screen
{
	return [[[OGGdkScreen alloc] initWithGObject:(GObject*)gtk_window_get_screen([self WINDOW])] autorelease];
}

- (void)sizeWithWidth:(gint*)width height:(gint*)height
{
	gtk_window_get_size([self WINDOW], width, height);
}

- (bool)skipPagerHint
{
	return gtk_window_get_skip_pager_hint([self WINDOW]);
}

- (bool)skipTaskbarHint
{
	return gtk_window_get_skip_taskbar_hint([self WINDOW]);
}

- (OFString*)title
{
	return [OFString stringWithUTF8String:gtk_window_get_title([self WINDOW])];
}

- (OGTKWidget*)titlebar
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_window_get_titlebar([self WINDOW])] autorelease];
}

- (OGTKWindow*)transientFor
{
	return [[[OGTKWindow alloc] initWithGObject:(GObject*)gtk_window_get_transient_for([self WINDOW])] autorelease];
}

- (GdkWindowTypeHint)typeHint
{
	return gtk_window_get_type_hint([self WINDOW]);
}

- (bool)urgencyHint
{
	return gtk_window_get_urgency_hint([self WINDOW]);
}

- (GtkWindowType)windowType
{
	return gtk_window_get_window_type([self WINDOW]);
}

- (bool)hasGroup
{
	return gtk_window_has_group([self WINDOW]);
}

- (bool)hasToplevelFocus
{
	return gtk_window_has_toplevel_focus([self WINDOW]);
}

- (void)iconify
{
	gtk_window_iconify([self WINDOW]);
}

- (bool)isActive
{
	return gtk_window_is_active([self WINDOW]);
}

- (bool)isMaximized
{
	return gtk_window_is_maximized([self WINDOW]);
}

- (void)maximize
{
	gtk_window_maximize([self WINDOW]);
}

- (bool)mnemonicActivateWithKeyval:(guint)keyval modifier:(GdkModifierType)modifier
{
	return gtk_window_mnemonic_activate([self WINDOW], keyval, modifier);
}

- (void)moveWithX:(gint)x y:(gint)y
{
	gtk_window_move([self WINDOW], x, y);
}

- (bool)parseGeometry:(OFString*)geometry
{
	return gtk_window_parse_geometry([self WINDOW], [geometry UTF8String]);
}

- (void)present
{
	gtk_window_present([self WINDOW]);
}

- (void)presentWithTime:(guint32)timestamp
{
	gtk_window_present_with_time([self WINDOW], timestamp);
}

- (bool)propagateKeyEvent:(GdkEventKey*)event
{
	return gtk_window_propagate_key_event([self WINDOW], event);
}

- (void)removeAccelGroup:(OGTKAccelGroup*)accelGroup
{
	gtk_window_remove_accel_group([self WINDOW], [accelGroup ACCELGROUP]);
}

- (void)removeMnemonicWithKeyval:(guint)keyval target:(OGTKWidget*)target
{
	gtk_window_remove_mnemonic([self WINDOW], keyval, [target WIDGET]);
}

- (void)reshowWithInitialSize
{
	gtk_window_reshow_with_initial_size([self WINDOW]);
}

- (void)resizeWithWidth:(gint)width height:(gint)height
{
	gtk_window_resize([self WINDOW], width, height);
}

- (bool)resizeGripIsVisible
{
	return gtk_window_resize_grip_is_visible([self WINDOW]);
}

- (void)resizeToGeometryWithWidth:(gint)width height:(gint)height
{
	gtk_window_resize_to_geometry([self WINDOW], width, height);
}

- (void)setAcceptFocus:(bool)setting
{
	gtk_window_set_accept_focus([self WINDOW], setting);
}

- (void)setApplication:(OGTKApplication*)application
{
	gtk_window_set_application([self WINDOW], [application APPLICATION]);
}

- (void)setAttachedTo:(OGTKWidget*)attachWidget
{
	gtk_window_set_attached_to([self WINDOW], [attachWidget WIDGET]);
}

- (void)setDecorated:(bool)setting
{
	gtk_window_set_decorated([self WINDOW], setting);
}

- (void)setDefault:(OGTKWidget*)defaultWidget
{
	gtk_window_set_default([self WINDOW], [defaultWidget WIDGET]);
}

- (void)setDefaultGeometryWithWidth:(gint)width height:(gint)height
{
	gtk_window_set_default_geometry([self WINDOW], width, height);
}

- (void)setDefaultSizeWithWidth:(gint)width height:(gint)height
{
	gtk_window_set_default_size([self WINDOW], width, height);
}

- (void)setDeletable:(bool)setting
{
	gtk_window_set_deletable([self WINDOW], setting);
}

- (void)setDestroyWithParent:(bool)setting
{
	gtk_window_set_destroy_with_parent([self WINDOW], setting);
}

- (void)setFocus:(OGTKWidget*)focus
{
	gtk_window_set_focus([self WINDOW], [focus WIDGET]);
}

- (void)setFocusOnMap:(bool)setting
{
	gtk_window_set_focus_on_map([self WINDOW], setting);
}

- (void)setFocusVisible:(bool)setting
{
	gtk_window_set_focus_visible([self WINDOW], setting);
}

- (void)setGeometryHintsWithGeometryWidget:(OGTKWidget*)geometryWidget geometry:(GdkGeometry*)geometry geomMask:(GdkWindowHints)geomMask
{
	gtk_window_set_geometry_hints([self WINDOW], [geometryWidget WIDGET], geometry, geomMask);
}

- (void)setGravity:(GdkGravity)gravity
{
	gtk_window_set_gravity([self WINDOW], gravity);
}

- (void)setHasResizeGrip:(bool)value
{
	gtk_window_set_has_resize_grip([self WINDOW], value);
}

- (void)setHasUserRefCount:(bool)setting
{
	gtk_window_set_has_user_ref_count([self WINDOW], setting);
}

- (void)setHideTitlebarWhenMaximized:(bool)setting
{
	gtk_window_set_hide_titlebar_when_maximized([self WINDOW], setting);
}

- (void)setIcon:(OGGdkPixbuf*)icon
{
	gtk_window_set_icon([self WINDOW], [icon PIXBUF]);
}

- (bool)setIconFromFileWithFilename:(OFString*)filename err:(GError**)err
{
	return gtk_window_set_icon_from_file([self WINDOW], [filename UTF8String], err);
}

- (void)setIconList:(GList*)list
{
	gtk_window_set_icon_list([self WINDOW], list);
}

- (void)setIconName:(OFString*)name
{
	gtk_window_set_icon_name([self WINDOW], [name UTF8String]);
}

- (void)setKeepAbove:(bool)setting
{
	gtk_window_set_keep_above([self WINDOW], setting);
}

- (void)setKeepBelow:(bool)setting
{
	gtk_window_set_keep_below([self WINDOW], setting);
}

- (void)setMnemonicModifier:(GdkModifierType)modifier
{
	gtk_window_set_mnemonic_modifier([self WINDOW], modifier);
}

- (void)setMnemonicsVisible:(bool)setting
{
	gtk_window_set_mnemonics_visible([self WINDOW], setting);
}

- (void)setModal:(bool)modal
{
	gtk_window_set_modal([self WINDOW], modal);
}

- (void)setOpacity:(gdouble)opacity
{
	gtk_window_set_opacity([self WINDOW], opacity);
}

- (void)setPosition:(GtkWindowPosition)position
{
	gtk_window_set_position([self WINDOW], position);
}

- (void)setResizable:(bool)resizable
{
	gtk_window_set_resizable([self WINDOW], resizable);
}

- (void)setRole:(OFString*)role
{
	gtk_window_set_role([self WINDOW], [role UTF8String]);
}

- (void)setScreen:(OGGdkScreen*)screen
{
	gtk_window_set_screen([self WINDOW], [screen SCREEN]);
}

- (void)setSkipPagerHint:(bool)setting
{
	gtk_window_set_skip_pager_hint([self WINDOW], setting);
}

- (void)setSkipTaskbarHint:(bool)setting
{
	gtk_window_set_skip_taskbar_hint([self WINDOW], setting);
}

- (void)setStartupId:(OFString*)startupId
{
	gtk_window_set_startup_id([self WINDOW], [startupId UTF8String]);
}

- (void)setTitle:(OFString*)title
{
	gtk_window_set_title([self WINDOW], [title UTF8String]);
}

- (void)setTitlebar:(OGTKWidget*)titlebar
{
	gtk_window_set_titlebar([self WINDOW], [titlebar WIDGET]);
}

- (void)setTransientFor:(OGTKWindow*)parent
{
	gtk_window_set_transient_for([self WINDOW], [parent WINDOW]);
}

- (void)setTypeHint:(GdkWindowTypeHint)hint
{
	gtk_window_set_type_hint([self WINDOW], hint);
}

- (void)setUrgencyHint:(bool)setting
{
	gtk_window_set_urgency_hint([self WINDOW], setting);
}

- (void)setWmclassWithWmclassName:(OFString*)wmclassName wmclassClass:(OFString*)wmclassClass
{
	gtk_window_set_wmclass([self WINDOW], [wmclassName UTF8String], [wmclassClass UTF8String]);
}

- (void)stick
{
	gtk_window_stick([self WINDOW]);
}

- (void)unfullscreen
{
	gtk_window_unfullscreen([self WINDOW]);
}

- (void)unmaximize
{
	gtk_window_unmaximize([self WINDOW]);
}

- (void)unstick
{
	gtk_window_unstick([self WINDOW]);
}


@end