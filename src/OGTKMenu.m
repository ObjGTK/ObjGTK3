/*
 * OGTKMenu.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKMenu.h"

@implementation OGTKMenu

+ (GList*)getForAttachWidget:(OGTKWidget*)widget
{
	return gtk_menu_get_for_attach_widget([widget WIDGET]);
}

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_menu_new()];

	return self;
}

- (id)initFromModel:(GMenuModel*)model
{
	self = [super initWithGObject:(GObject*)gtk_menu_new_from_model(model)];

	return self;
}

- (GtkMenu*)MENU
{
	return GTK_MENU([self GOBJECT]);
}

- (void)attachWithChild:(OGTKWidget*)child andLeftAttach:(guint)leftAttach andRightAttach:(guint)rightAttach andTopAttach:(guint)topAttach andBottomAttach:(guint)bottomAttach
{
	gtk_menu_attach(GTK_MENU([self GOBJECT]), [child WIDGET], leftAttach, rightAttach, topAttach, bottomAttach);
}

- (void)attachToWidgetWithAttachWidget:(OGTKWidget*)attachWidget andDetacher:(GtkMenuDetachFunc)detacher
{
	gtk_menu_attach_to_widget(GTK_MENU([self GOBJECT]), [attachWidget WIDGET], detacher);
}

- (void)detach
{
	gtk_menu_detach(GTK_MENU([self GOBJECT]));
}

- (GtkAccelGroup*)getAccelGroup
{
	return gtk_menu_get_accel_group(GTK_MENU([self GOBJECT]));
}

- (OFString*)getAccelPath
{
	return [OFString stringWithUTF8String:gtk_menu_get_accel_path(GTK_MENU([self GOBJECT]))];
}

- (OGTKWidget*)getActive
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_get_active(GTK_MENU([self GOBJECT]))];
}

- (OGTKWidget*)getAttachWidget
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_get_attach_widget(GTK_MENU([self GOBJECT]))];
}

- (gint)getMonitor
{
	return gtk_menu_get_monitor(GTK_MENU([self GOBJECT]));
}

- (bool)getReserveToggleSize
{
	return gtk_menu_get_reserve_toggle_size(GTK_MENU([self GOBJECT]));
}

- (bool)getTearoffState
{
	return gtk_menu_get_tearoff_state(GTK_MENU([self GOBJECT]));
}

- (OFString*)getTitle
{
	return [OFString stringWithUTF8String:gtk_menu_get_title(GTK_MENU([self GOBJECT]))];
}

- (void)placeOnMonitor:(GdkMonitor*)monitor
{
	gtk_menu_place_on_monitor(GTK_MENU([self GOBJECT]), monitor);
}

- (void)popdown
{
	gtk_menu_popdown(GTK_MENU([self GOBJECT]));
}

- (void)popupWithParentMenuShell:(OGTKWidget*)parentMenuShell andParentMenuItem:(OGTKWidget*)parentMenuItem andFunc:(GtkMenuPositionFunc)func andData:(gpointer)data andButton:(guint)button andActivateTime:(guint32)activateTime
{
	gtk_menu_popup(GTK_MENU([self GOBJECT]), [parentMenuShell WIDGET], [parentMenuItem WIDGET], func, data, button, activateTime);
}

- (void)popupAtPointer:(const GdkEvent*)triggerEvent
{
	gtk_menu_popup_at_pointer(GTK_MENU([self GOBJECT]), triggerEvent);
}

- (void)popupAtRectWithRectWindow:(GdkWindow*)rectWindow andRect:(const GdkRectangle*)rect andRectAnchor:(GdkGravity)rectAnchor andMenuAnchor:(GdkGravity)menuAnchor andTriggerEvent:(const GdkEvent*)triggerEvent
{
	gtk_menu_popup_at_rect(GTK_MENU([self GOBJECT]), rectWindow, rect, rectAnchor, menuAnchor, triggerEvent);
}

- (void)popupAtWidgetWithWidget:(OGTKWidget*)widget andWidgetAnchor:(GdkGravity)widgetAnchor andMenuAnchor:(GdkGravity)menuAnchor andTriggerEvent:(const GdkEvent*)triggerEvent
{
	gtk_menu_popup_at_widget(GTK_MENU([self GOBJECT]), [widget WIDGET], widgetAnchor, menuAnchor, triggerEvent);
}

- (void)popupForDeviceWithDevice:(GdkDevice*)device andParentMenuShell:(OGTKWidget*)parentMenuShell andParentMenuItem:(OGTKWidget*)parentMenuItem andFunc:(GtkMenuPositionFunc)func andData:(gpointer)data andDestroy:(GDestroyNotify)destroy andButton:(guint)button andActivateTime:(guint32)activateTime
{
	gtk_menu_popup_for_device(GTK_MENU([self GOBJECT]), device, [parentMenuShell WIDGET], [parentMenuItem WIDGET], func, data, destroy, button, activateTime);
}

- (void)reorderChildWithChild:(OGTKWidget*)child andPosition:(gint)position
{
	gtk_menu_reorder_child(GTK_MENU([self GOBJECT]), [child WIDGET], position);
}

- (void)reposition
{
	gtk_menu_reposition(GTK_MENU([self GOBJECT]));
}

- (void)setAccelGroup:(GtkAccelGroup*)accelGroup
{
	gtk_menu_set_accel_group(GTK_MENU([self GOBJECT]), accelGroup);
}

- (void)setAccelPath:(OFString*)accelPath
{
	gtk_menu_set_accel_path(GTK_MENU([self GOBJECT]), [accelPath UTF8String]);
}

- (void)setActive:(guint)index
{
	gtk_menu_set_active(GTK_MENU([self GOBJECT]), index);
}

- (void)setMonitor:(gint)monitorNum
{
	gtk_menu_set_monitor(GTK_MENU([self GOBJECT]), monitorNum);
}

- (void)setReserveToggleSize:(bool)reserveToggleSize
{
	gtk_menu_set_reserve_toggle_size(GTK_MENU([self GOBJECT]), reserveToggleSize);
}

- (void)setScreen:(GdkScreen*)screen
{
	gtk_menu_set_screen(GTK_MENU([self GOBJECT]), screen);
}

- (void)setTearoffState:(bool)tornOff
{
	gtk_menu_set_tearoff_state(GTK_MENU([self GOBJECT]), tornOff);
}

- (void)setTitle:(OFString*)title
{
	gtk_menu_set_title(GTK_MENU([self GOBJECT]), [title UTF8String]);
}


@end