/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenu.h"

#import "OGTKAccelGroup.h"
#import "OGTKWidget.h"
#import <OGdk3/OGGdkScreen.h>
#import <OGdk3/OGGdkMonitor.h>
#import <OGdk3/OGGdkDevice.h>
#import <OGdk3/OGGdkWindow.h>

@implementation OGTKMenu

+ (GList*)forAttachWidget:(OGTKWidget*)widget
{
	return gtk_menu_get_for_attach_widget([widget WIDGET]);
}

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_menu_new()];

	return self;
}

- (instancetype)initFromModel:(GMenuModel*)model
{
	self = [super initWithGObject:(GObject*)gtk_menu_new_from_model(model)];

	return self;
}

- (GtkMenu*)MENU
{
	return GTK_MENU([self GOBJECT]);
}

- (void)attachWithChild:(OGTKWidget*)child leftAttach:(guint)leftAttach rightAttach:(guint)rightAttach topAttach:(guint)topAttach bottomAttach:(guint)bottomAttach
{
	gtk_menu_attach([self MENU], [child WIDGET], leftAttach, rightAttach, topAttach, bottomAttach);
}

- (void)attachToWidgetWithAttachWidget:(OGTKWidget*)attachWidget detacher:(GtkMenuDetachFunc)detacher
{
	gtk_menu_attach_to_widget([self MENU], [attachWidget WIDGET], detacher);
}

- (void)detach
{
	gtk_menu_detach([self MENU]);
}

- (OGTKAccelGroup*)accelGroup
{
	return [[[OGTKAccelGroup alloc] initWithGObject:(GObject*)gtk_menu_get_accel_group([self MENU])] autorelease];
}

- (OFString*)accelPath
{
	return [OFString stringWithUTF8String:gtk_menu_get_accel_path([self MENU])];
}

- (OGTKWidget*)active
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_get_active([self MENU])] autorelease];
}

- (OGTKWidget*)attachWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_get_attach_widget([self MENU])] autorelease];
}

- (gint)monitor
{
	return gtk_menu_get_monitor([self MENU]);
}

- (bool)reserveToggleSize
{
	return gtk_menu_get_reserve_toggle_size([self MENU]);
}

- (bool)tearoffState
{
	return gtk_menu_get_tearoff_state([self MENU]);
}

- (OFString*)title
{
	return [OFString stringWithUTF8String:gtk_menu_get_title([self MENU])];
}

- (void)placeOnMonitor:(OGGdkMonitor*)monitor
{
	gtk_menu_place_on_monitor([self MENU], [monitor MONITOR]);
}

- (void)popdown
{
	gtk_menu_popdown([self MENU]);
}

- (void)popupWithParentMenuShell:(OGTKWidget*)parentMenuShell parentMenuItem:(OGTKWidget*)parentMenuItem func:(GtkMenuPositionFunc)func data:(gpointer)data button:(guint)button activateTime:(guint32)activateTime
{
	gtk_menu_popup([self MENU], [parentMenuShell WIDGET], [parentMenuItem WIDGET], func, data, button, activateTime);
}

- (void)popupAtPointer:(const GdkEvent*)triggerEvent
{
	gtk_menu_popup_at_pointer([self MENU], triggerEvent);
}

- (void)popupAtRectWithRectWindow:(OGGdkWindow*)rectWindow rect:(const GdkRectangle*)rect rectAnchor:(GdkGravity)rectAnchor menuAnchor:(GdkGravity)menuAnchor triggerEvent:(const GdkEvent*)triggerEvent
{
	gtk_menu_popup_at_rect([self MENU], [rectWindow WINDOW], rect, rectAnchor, menuAnchor, triggerEvent);
}

- (void)popupAtWidgetWithWidget:(OGTKWidget*)widget widgetAnchor:(GdkGravity)widgetAnchor menuAnchor:(GdkGravity)menuAnchor triggerEvent:(const GdkEvent*)triggerEvent
{
	gtk_menu_popup_at_widget([self MENU], [widget WIDGET], widgetAnchor, menuAnchor, triggerEvent);
}

- (void)popupForDeviceWithDevice:(OGGdkDevice*)device parentMenuShell:(OGTKWidget*)parentMenuShell parentMenuItem:(OGTKWidget*)parentMenuItem func:(GtkMenuPositionFunc)func data:(gpointer)data destroy:(GDestroyNotify)destroy button:(guint)button activateTime:(guint32)activateTime
{
	gtk_menu_popup_for_device([self MENU], [device DEVICE], [parentMenuShell WIDGET], [parentMenuItem WIDGET], func, data, destroy, button, activateTime);
}

- (void)reorderChildWithChild:(OGTKWidget*)child position:(gint)position
{
	gtk_menu_reorder_child([self MENU], [child WIDGET], position);
}

- (void)reposition
{
	gtk_menu_reposition([self MENU]);
}

- (void)setAccelGroup:(OGTKAccelGroup*)accelGroup
{
	gtk_menu_set_accel_group([self MENU], [accelGroup ACCELGROUP]);
}

- (void)setAccelPath:(OFString*)accelPath
{
	gtk_menu_set_accel_path([self MENU], [accelPath UTF8String]);
}

- (void)setActive:(guint)index
{
	gtk_menu_set_active([self MENU], index);
}

- (void)setMonitor:(gint)monitorNum
{
	gtk_menu_set_monitor([self MENU], monitorNum);
}

- (void)setReserveToggleSize:(bool)reserveToggleSize
{
	gtk_menu_set_reserve_toggle_size([self MENU], reserveToggleSize);
}

- (void)setScreen:(OGGdkScreen*)screen
{
	gtk_menu_set_screen([self MENU], [screen SCREEN]);
}

- (void)setTearoffState:(bool)tornOff
{
	gtk_menu_set_tearoff_state([self MENU], tornOff);
}

- (void)setTitle:(OFString*)title
{
	gtk_menu_set_title([self MENU], [title UTF8String]);
}


@end