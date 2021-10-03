/*
 * OGTKMenu.h
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
#import "OGTKMenuShell.h"

@interface OGTKMenu : OGTKMenuShell
{

}

/**
 * Functions
 */
+ (GList*)getForAttachWidget:(OGTKWidget*)widget;

/**
 * Constructors
 */
- (id)init;
- (id)initFromModel:(GMenuModel*)model;

/**
 * Methods
 */

- (GtkMenu*)MENU;

/**
 * - (void*)attachWithChild:(OGTKWidget*)child andLeftAttach:(guint)leftAttach andRightAttach:(guint)rightAttach andTopAttach:(guint)topAttach andBottomAttach:(guint)bottomAttach;
 *
 * @param child
 * @param leftAttach
 * @param rightAttach
 * @param topAttach
 * @param bottomAttach
 */
- (void)attachWithChild:(OGTKWidget*)child andLeftAttach:(guint)leftAttach andRightAttach:(guint)rightAttach andTopAttach:(guint)topAttach andBottomAttach:(guint)bottomAttach;

/**
 * - (void*)attachToWidgetWithAttachWidget:(OGTKWidget*)attachWidget andDetacher:(GtkMenuDetachFunc)detacher;
 *
 * @param attachWidget
 * @param detacher
 */
- (void)attachToWidgetWithAttachWidget:(OGTKWidget*)attachWidget andDetacher:(GtkMenuDetachFunc)detacher;

/**
 * - (void*)detach;
 *
 */
- (void)detach;

/**
 * - (GtkAccelGroup**)getAccelGroup;
 *
 * @returns GtkAccelGroup*
 */
- (GtkAccelGroup*)getAccelGroup;

/**
 * - (OFString**)getAccelPath;
 *
 * @returns OFString*
 */
- (OFString*)getAccelPath;

/**
 * - (OGTKWidget**)getActive;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getActive;

/**
 * - (OGTKWidget**)getAttachWidget;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getAttachWidget;

/**
 * - (gint*)getMonitor;
 *
 * @returns gint
 */
- (gint)getMonitor;

/**
 * - (bool*)getReserveToggleSize;
 *
 * @returns bool
 */
- (bool)getReserveToggleSize;

/**
 * - (bool*)getTearoffState;
 *
 * @returns bool
 */
- (bool)getTearoffState;

/**
 * - (OFString**)getTitle;
 *
 * @returns OFString*
 */
- (OFString*)getTitle;

/**
 * - (void*)placeOnMonitor:(GdkMonitor*)monitor;
 *
 * @param monitor
 */
- (void)placeOnMonitor:(GdkMonitor*)monitor;

/**
 * - (void*)popdown;
 *
 */
- (void)popdown;

/**
 * - (void*)popupWithParentMenuShell:(OGTKWidget*)parentMenuShell andParentMenuItem:(OGTKWidget*)parentMenuItem andFunc:(GtkMenuPositionFunc)func andData:(gpointer)data andButton:(guint)button andActivateTime:(guint32)activateTime;
 *
 * @param parentMenuShell
 * @param parentMenuItem
 * @param func
 * @param data
 * @param button
 * @param activateTime
 */
- (void)popupWithParentMenuShell:(OGTKWidget*)parentMenuShell andParentMenuItem:(OGTKWidget*)parentMenuItem andFunc:(GtkMenuPositionFunc)func andData:(gpointer)data andButton:(guint)button andActivateTime:(guint32)activateTime;

/**
 * - (void*)popupAtPointer:(const GdkEvent*)triggerEvent;
 *
 * @param triggerEvent
 */
- (void)popupAtPointer:(const GdkEvent*)triggerEvent;

/**
 * - (void*)popupAtRectWithRectWindow:(GdkWindow*)rectWindow andRect:(const GdkRectangle*)rect andRectAnchor:(GdkGravity)rectAnchor andMenuAnchor:(GdkGravity)menuAnchor andTriggerEvent:(const GdkEvent*)triggerEvent;
 *
 * @param rectWindow
 * @param rect
 * @param rectAnchor
 * @param menuAnchor
 * @param triggerEvent
 */
- (void)popupAtRectWithRectWindow:(GdkWindow*)rectWindow andRect:(const GdkRectangle*)rect andRectAnchor:(GdkGravity)rectAnchor andMenuAnchor:(GdkGravity)menuAnchor andTriggerEvent:(const GdkEvent*)triggerEvent;

/**
 * - (void*)popupAtWidgetWithWidget:(OGTKWidget*)widget andWidgetAnchor:(GdkGravity)widgetAnchor andMenuAnchor:(GdkGravity)menuAnchor andTriggerEvent:(const GdkEvent*)triggerEvent;
 *
 * @param widget
 * @param widgetAnchor
 * @param menuAnchor
 * @param triggerEvent
 */
- (void)popupAtWidgetWithWidget:(OGTKWidget*)widget andWidgetAnchor:(GdkGravity)widgetAnchor andMenuAnchor:(GdkGravity)menuAnchor andTriggerEvent:(const GdkEvent*)triggerEvent;

/**
 * - (void*)popupForDeviceWithDevice:(GdkDevice*)device andParentMenuShell:(OGTKWidget*)parentMenuShell andParentMenuItem:(OGTKWidget*)parentMenuItem andFunc:(GtkMenuPositionFunc)func andData:(gpointer)data andDestroy:(GDestroyNotify)destroy andButton:(guint)button andActivateTime:(guint32)activateTime;
 *
 * @param device
 * @param parentMenuShell
 * @param parentMenuItem
 * @param func
 * @param data
 * @param destroy
 * @param button
 * @param activateTime
 */
- (void)popupForDeviceWithDevice:(GdkDevice*)device andParentMenuShell:(OGTKWidget*)parentMenuShell andParentMenuItem:(OGTKWidget*)parentMenuItem andFunc:(GtkMenuPositionFunc)func andData:(gpointer)data andDestroy:(GDestroyNotify)destroy andButton:(guint)button andActivateTime:(guint32)activateTime;

/**
 * - (void*)reorderChildWithChild:(OGTKWidget*)child andPosition:(gint)position;
 *
 * @param child
 * @param position
 */
- (void)reorderChildWithChild:(OGTKWidget*)child andPosition:(gint)position;

/**
 * - (void*)reposition;
 *
 */
- (void)reposition;

/**
 * - (void*)setAccelGroup:(GtkAccelGroup*)accelGroup;
 *
 * @param accelGroup
 */
- (void)setAccelGroup:(GtkAccelGroup*)accelGroup;

/**
 * - (void*)setAccelPath:(OFString*)accelPath;
 *
 * @param accelPath
 */
- (void)setAccelPath:(OFString*)accelPath;

/**
 * - (void*)setActive:(guint)index;
 *
 * @param index
 */
- (void)setActive:(guint)index;

/**
 * - (void*)setMonitor:(gint)monitorNum;
 *
 * @param monitorNum
 */
- (void)setMonitor:(gint)monitorNum;

/**
 * - (void*)setReserveToggleSize:(bool)reserveToggleSize;
 *
 * @param reserveToggleSize
 */
- (void)setReserveToggleSize:(bool)reserveToggleSize;

/**
 * - (void*)setScreen:(GdkScreen*)screen;
 *
 * @param screen
 */
- (void)setScreen:(GdkScreen*)screen;

/**
 * - (void*)setTearoffState:(bool)tornOff;
 *
 * @param tornOff
 */
- (void)setTearoffState:(bool)tornOff;

/**
 * - (void*)setTitle:(OFString*)title;
 *
 * @param title
 */
- (void)setTitle:(OFString*)title;

@end