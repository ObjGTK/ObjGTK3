/*
 * OGTKWindow.h
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
#import "OGTKBin.h"

@interface OGTKWindow : OGTKBin
{

}

/**
 * Functions
 */
+ (GList*)getDefaultIconList;
+ (OFString*)getDefaultIconName;
+ (GList*)listToplevels;
+ (void)setAutoStartupNotification:(bool)setting;
+ (void)setDefaultIcon:(GdkPixbuf*)icon;
+ (bool)setDefaultIconFromFileWithFilename:(OFString*)filename andErr:(GError**)err;
+ (void)setDefaultIconList:(GList*)list;
+ (void)setDefaultIconName:(OFString*)name;
+ (void)setInteractiveDebugging:(bool)enable;

/**
 * Constructors
 */
- (id)init:(GtkWindowType)type;

/**
 * Methods
 */

- (GtkWindow*)WINDOW;

/**
 * - (bool*)activateDefault;
 *
 * @returns bool
 */
- (bool)activateDefault;

/**
 * - (bool*)activateFocus;
 *
 * @returns bool
 */
- (bool)activateFocus;

/**
 * - (bool*)activateKey:(GdkEventKey*)event;
 *
 * @param event
 * @returns bool
 */
- (bool)activateKey:(GdkEventKey*)event;

/**
 * - (void*)addAccelGroup:(GtkAccelGroup*)accelGroup;
 *
 * @param accelGroup
 */
- (void)addAccelGroup:(GtkAccelGroup*)accelGroup;

/**
 * - (void*)addMnemonicWithKeyval:(guint)keyval andTarget:(OGTKWidget*)target;
 *
 * @param keyval
 * @param target
 */
- (void)addMnemonicWithKeyval:(guint)keyval andTarget:(OGTKWidget*)target;

/**
 * - (void*)beginMoveDragWithButton:(gint)button andRootX:(gint)rootX andRootY:(gint)rootY andTimestamp:(guint32)timestamp;
 *
 * @param button
 * @param rootX
 * @param rootY
 * @param timestamp
 */
- (void)beginMoveDragWithButton:(gint)button andRootX:(gint)rootX andRootY:(gint)rootY andTimestamp:(guint32)timestamp;

/**
 * - (void*)beginResizeDragWithEdge:(GdkWindowEdge)edge andButton:(gint)button andRootX:(gint)rootX andRootY:(gint)rootY andTimestamp:(guint32)timestamp;
 *
 * @param edge
 * @param button
 * @param rootX
 * @param rootY
 * @param timestamp
 */
- (void)beginResizeDragWithEdge:(GdkWindowEdge)edge andButton:(gint)button andRootX:(gint)rootX andRootY:(gint)rootY andTimestamp:(guint32)timestamp;

/**
 * - (void*)close;
 *
 */
- (void)close;

/**
 * - (void*)deiconify;
 *
 */
- (void)deiconify;

/**
 * - (void*)fullscreen;
 *
 */
- (void)fullscreen;

/**
 * - (void*)fullscreenOnMonitorWithScreen:(GdkScreen*)screen andMonitor:(gint)monitor;
 *
 * @param screen
 * @param monitor
 */
- (void)fullscreenOnMonitorWithScreen:(GdkScreen*)screen andMonitor:(gint)monitor;

/**
 * - (bool*)getAcceptFocus;
 *
 * @returns bool
 */
- (bool)getAcceptFocus;

/**
 * - (GtkApplication**)getApplication;
 *
 * @returns GtkApplication*
 */
- (GtkApplication*)getApplication;

/**
 * - (OGTKWidget**)getAttachedTo;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getAttachedTo;

/**
 * - (bool*)getDecorated;
 *
 * @returns bool
 */
- (bool)getDecorated;

/**
 * - (void*)getDefaultSizeWithWidth:(gint*)width andHeight:(gint*)height;
 *
 * @param width
 * @param height
 */
- (void)getDefaultSizeWithWidth:(gint*)width andHeight:(gint*)height;

/**
 * - (OGTKWidget**)getDefaultWidget;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getDefaultWidget;

/**
 * - (bool*)getDeletable;
 *
 * @returns bool
 */
- (bool)getDeletable;

/**
 * - (bool*)getDestroyWithParent;
 *
 * @returns bool
 */
- (bool)getDestroyWithParent;

/**
 * - (OGTKWidget**)getFocus;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getFocus;

/**
 * - (bool*)getFocusOnMap;
 *
 * @returns bool
 */
- (bool)getFocusOnMap;

/**
 * - (bool*)getFocusVisible;
 *
 * @returns bool
 */
- (bool)getFocusVisible;

/**
 * - (GdkGravity*)getGravity;
 *
 * @returns GdkGravity
 */
- (GdkGravity)getGravity;

/**
 * - (GtkWindowGroup**)getGroup;
 *
 * @returns GtkWindowGroup*
 */
- (GtkWindowGroup*)getGroup;

/**
 * - (bool*)getHasResizeGrip;
 *
 * @returns bool
 */
- (bool)getHasResizeGrip;

/**
 * - (bool*)getHideTitlebarWhenMaximized;
 *
 * @returns bool
 */
- (bool)getHideTitlebarWhenMaximized;

/**
 * - (GdkPixbuf**)getIcon;
 *
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)getIcon;

/**
 * - (GList**)getIconList;
 *
 * @returns GList*
 */
- (GList*)getIconList;

/**
 * - (OFString**)getIconName;
 *
 * @returns OFString*
 */
- (OFString*)getIconName;

/**
 * - (GdkModifierType*)getMnemonicModifier;
 *
 * @returns GdkModifierType
 */
- (GdkModifierType)getMnemonicModifier;

/**
 * - (bool*)getMnemonicsVisible;
 *
 * @returns bool
 */
- (bool)getMnemonicsVisible;

/**
 * - (bool*)getModal;
 *
 * @returns bool
 */
- (bool)getModal;

/**
 * - (gdouble*)getOpacity;
 *
 * @returns gdouble
 */
- (gdouble)getOpacity;

/**
 * - (void*)getPositionWithRootX:(gint*)rootX andRootY:(gint*)rootY;
 *
 * @param rootX
 * @param rootY
 */
- (void)getPositionWithRootX:(gint*)rootX andRootY:(gint*)rootY;

/**
 * - (bool*)getResizable;
 *
 * @returns bool
 */
- (bool)getResizable;

/**
 * - (bool*)getResizeGripArea:(GdkRectangle*)rect;
 *
 * @param rect
 * @returns bool
 */
- (bool)getResizeGripArea:(GdkRectangle*)rect;

/**
 * - (OFString**)getRole;
 *
 * @returns OFString*
 */
- (OFString*)getRole;

/**
 * - (GdkScreen**)getScreen;
 *
 * @returns GdkScreen*
 */
- (GdkScreen*)getScreen;

/**
 * - (void*)getSizeWithWidth:(gint*)width andHeight:(gint*)height;
 *
 * @param width
 * @param height
 */
- (void)getSizeWithWidth:(gint*)width andHeight:(gint*)height;

/**
 * - (bool*)getSkipPagerHint;
 *
 * @returns bool
 */
- (bool)getSkipPagerHint;

/**
 * - (bool*)getSkipTaskbarHint;
 *
 * @returns bool
 */
- (bool)getSkipTaskbarHint;

/**
 * - (OFString**)getTitle;
 *
 * @returns OFString*
 */
- (OFString*)getTitle;

/**
 * - (OGTKWidget**)getTitlebar;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getTitlebar;

/**
 * - (GtkWindow**)getTransientFor;
 *
 * @returns GtkWindow*
 */
- (GtkWindow*)getTransientFor;

/**
 * - (GdkWindowTypeHint*)getTypeHint;
 *
 * @returns GdkWindowTypeHint
 */
- (GdkWindowTypeHint)getTypeHint;

/**
 * - (bool*)getUrgencyHint;
 *
 * @returns bool
 */
- (bool)getUrgencyHint;

/**
 * - (GtkWindowType*)getWindowType;
 *
 * @returns GtkWindowType
 */
- (GtkWindowType)getWindowType;

/**
 * - (bool*)hasGroup;
 *
 * @returns bool
 */
- (bool)hasGroup;

/**
 * - (bool*)hasToplevelFocus;
 *
 * @returns bool
 */
- (bool)hasToplevelFocus;

/**
 * - (void*)iconify;
 *
 */
- (void)iconify;

/**
 * - (bool*)isActive;
 *
 * @returns bool
 */
- (bool)isActive;

/**
 * - (bool*)isMaximized;
 *
 * @returns bool
 */
- (bool)isMaximized;

/**
 * - (void*)maximize;
 *
 */
- (void)maximize;

/**
 * - (bool*)mnemonicActivateWithKeyval:(guint)keyval andModifier:(GdkModifierType)modifier;
 *
 * @param keyval
 * @param modifier
 * @returns bool
 */
- (bool)mnemonicActivateWithKeyval:(guint)keyval andModifier:(GdkModifierType)modifier;

/**
 * - (void*)moveWithX:(gint)x andY:(gint)y;
 *
 * @param x
 * @param y
 */
- (void)moveWithX:(gint)x andY:(gint)y;

/**
 * - (bool*)parseGeometry:(OFString*)geometry;
 *
 * @param geometry
 * @returns bool
 */
- (bool)parseGeometry:(OFString*)geometry;

/**
 * - (void*)present;
 *
 */
- (void)present;

/**
 * - (void*)presentWithTime:(guint32)timestamp;
 *
 * @param timestamp
 */
- (void)presentWithTime:(guint32)timestamp;

/**
 * - (bool*)propagateKeyEvent:(GdkEventKey*)event;
 *
 * @param event
 * @returns bool
 */
- (bool)propagateKeyEvent:(GdkEventKey*)event;

/**
 * - (void*)removeAccelGroup:(GtkAccelGroup*)accelGroup;
 *
 * @param accelGroup
 */
- (void)removeAccelGroup:(GtkAccelGroup*)accelGroup;

/**
 * - (void*)removeMnemonicWithKeyval:(guint)keyval andTarget:(OGTKWidget*)target;
 *
 * @param keyval
 * @param target
 */
- (void)removeMnemonicWithKeyval:(guint)keyval andTarget:(OGTKWidget*)target;

/**
 * - (void*)reshowWithInitialSize;
 *
 */
- (void)reshowWithInitialSize;

/**
 * - (void*)resizeWithWidth:(gint)width andHeight:(gint)height;
 *
 * @param width
 * @param height
 */
- (void)resizeWithWidth:(gint)width andHeight:(gint)height;

/**
 * - (bool*)resizeGripIsVisible;
 *
 * @returns bool
 */
- (bool)resizeGripIsVisible;

/**
 * - (void*)resizeToGeometryWithWidth:(gint)width andHeight:(gint)height;
 *
 * @param width
 * @param height
 */
- (void)resizeToGeometryWithWidth:(gint)width andHeight:(gint)height;

/**
 * - (void*)setAcceptFocus:(bool)setting;
 *
 * @param setting
 */
- (void)setAcceptFocus:(bool)setting;

/**
 * - (void*)setApplication:(GtkApplication*)application;
 *
 * @param application
 */
- (void)setApplication:(GtkApplication*)application;

/**
 * - (void*)setAttachedTo:(OGTKWidget*)attachWidget;
 *
 * @param attachWidget
 */
- (void)setAttachedTo:(OGTKWidget*)attachWidget;

/**
 * - (void*)setDecorated:(bool)setting;
 *
 * @param setting
 */
- (void)setDecorated:(bool)setting;

/**
 * - (void*)setDefault:(OGTKWidget*)defaultWidget;
 *
 * @param defaultWidget
 */
- (void)setDefault:(OGTKWidget*)defaultWidget;

/**
 * - (void*)setDefaultGeometryWithWidth:(gint)width andHeight:(gint)height;
 *
 * @param width
 * @param height
 */
- (void)setDefaultGeometryWithWidth:(gint)width andHeight:(gint)height;

/**
 * - (void*)setDefaultSizeWithWidth:(gint)width andHeight:(gint)height;
 *
 * @param width
 * @param height
 */
- (void)setDefaultSizeWithWidth:(gint)width andHeight:(gint)height;

/**
 * - (void*)setDeletable:(bool)setting;
 *
 * @param setting
 */
- (void)setDeletable:(bool)setting;

/**
 * - (void*)setDestroyWithParent:(bool)setting;
 *
 * @param setting
 */
- (void)setDestroyWithParent:(bool)setting;

/**
 * - (void*)setFocus:(OGTKWidget*)focus;
 *
 * @param focus
 */
- (void)setFocus:(OGTKWidget*)focus;

/**
 * - (void*)setFocusOnMap:(bool)setting;
 *
 * @param setting
 */
- (void)setFocusOnMap:(bool)setting;

/**
 * - (void*)setFocusVisible:(bool)setting;
 *
 * @param setting
 */
- (void)setFocusVisible:(bool)setting;

/**
 * - (void*)setGeometryHintsWithGeometryWidget:(OGTKWidget*)geometryWidget andGeometry:(GdkGeometry*)geometry andGeomMask:(GdkWindowHints)geomMask;
 *
 * @param geometryWidget
 * @param geometry
 * @param geomMask
 */
- (void)setGeometryHintsWithGeometryWidget:(OGTKWidget*)geometryWidget andGeometry:(GdkGeometry*)geometry andGeomMask:(GdkWindowHints)geomMask;

/**
 * - (void*)setGravity:(GdkGravity)gravity;
 *
 * @param gravity
 */
- (void)setGravity:(GdkGravity)gravity;

/**
 * - (void*)setHasResizeGrip:(bool)value;
 *
 * @param value
 */
- (void)setHasResizeGrip:(bool)value;

/**
 * - (void*)setHasUserRefCount:(bool)setting;
 *
 * @param setting
 */
- (void)setHasUserRefCount:(bool)setting;

/**
 * - (void*)setHideTitlebarWhenMaximized:(bool)setting;
 *
 * @param setting
 */
- (void)setHideTitlebarWhenMaximized:(bool)setting;

/**
 * - (void*)setIcon:(GdkPixbuf*)icon;
 *
 * @param icon
 */
- (void)setIcon:(GdkPixbuf*)icon;

/**
 * - (bool*)setIconFromFileWithFilename:(OFString*)filename andErr:(GError**)err;
 *
 * @param filename
 * @param err
 * @returns bool
 */
- (bool)setIconFromFileWithFilename:(OFString*)filename andErr:(GError**)err;

/**
 * - (void*)setIconList:(GList*)list;
 *
 * @param list
 */
- (void)setIconList:(GList*)list;

/**
 * - (void*)setIconName:(OFString*)name;
 *
 * @param name
 */
- (void)setIconName:(OFString*)name;

/**
 * - (void*)setKeepAbove:(bool)setting;
 *
 * @param setting
 */
- (void)setKeepAbove:(bool)setting;

/**
 * - (void*)setKeepBelow:(bool)setting;
 *
 * @param setting
 */
- (void)setKeepBelow:(bool)setting;

/**
 * - (void*)setMnemonicModifier:(GdkModifierType)modifier;
 *
 * @param modifier
 */
- (void)setMnemonicModifier:(GdkModifierType)modifier;

/**
 * - (void*)setMnemonicsVisible:(bool)setting;
 *
 * @param setting
 */
- (void)setMnemonicsVisible:(bool)setting;

/**
 * - (void*)setModal:(bool)modal;
 *
 * @param modal
 */
- (void)setModal:(bool)modal;

/**
 * - (void*)setOpacity:(gdouble)opacity;
 *
 * @param opacity
 */
- (void)setOpacity:(gdouble)opacity;

/**
 * - (void*)setPosition:(GtkWindowPosition)position;
 *
 * @param position
 */
- (void)setPosition:(GtkWindowPosition)position;

/**
 * - (void*)setResizable:(bool)resizable;
 *
 * @param resizable
 */
- (void)setResizable:(bool)resizable;

/**
 * - (void*)setRole:(OFString*)role;
 *
 * @param role
 */
- (void)setRole:(OFString*)role;

/**
 * - (void*)setScreen:(GdkScreen*)screen;
 *
 * @param screen
 */
- (void)setScreen:(GdkScreen*)screen;

/**
 * - (void*)setSkipPagerHint:(bool)setting;
 *
 * @param setting
 */
- (void)setSkipPagerHint:(bool)setting;

/**
 * - (void*)setSkipTaskbarHint:(bool)setting;
 *
 * @param setting
 */
- (void)setSkipTaskbarHint:(bool)setting;

/**
 * - (void*)setStartupId:(OFString*)startupId;
 *
 * @param startupId
 */
- (void)setStartupId:(OFString*)startupId;

/**
 * - (void*)setTitle:(OFString*)title;
 *
 * @param title
 */
- (void)setTitle:(OFString*)title;

/**
 * - (void*)setTitlebar:(OGTKWidget*)titlebar;
 *
 * @param titlebar
 */
- (void)setTitlebar:(OGTKWidget*)titlebar;

/**
 * - (void*)setTransientFor:(GtkWindow*)parent;
 *
 * @param parent
 */
- (void)setTransientFor:(GtkWindow*)parent;

/**
 * - (void*)setTypeHint:(GdkWindowTypeHint)hint;
 *
 * @param hint
 */
- (void)setTypeHint:(GdkWindowTypeHint)hint;

/**
 * - (void*)setUrgencyHint:(bool)setting;
 *
 * @param setting
 */
- (void)setUrgencyHint:(bool)setting;

/**
 * - (void*)setWmclassWithWmclassName:(OFString*)wmclassName andWmclassClass:(OFString*)wmclassClass;
 *
 * @param wmclassName
 * @param wmclassClass
 */
- (void)setWmclassWithWmclassName:(OFString*)wmclassName andWmclassClass:(OFString*)wmclassClass;

/**
 * - (void*)stick;
 *
 */
- (void)stick;

/**
 * - (void*)unfullscreen;
 *
 */
- (void)unfullscreen;

/**
 * - (void*)unmaximize;
 *
 */
- (void)unmaximize;

/**
 * - (void*)unstick;
 *
 */
- (void)unstick;

@end