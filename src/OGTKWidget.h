/*
 * OGTKWidget.h
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
#import "OGTKBase.h"

@interface OGTKWidget : OGTKBase
{

}

/**
 * Functions
 */
+ (GtkTextDirection)getDefaultDirection;
+ (GtkStyle*)getDefaultStyle;
+ (void)popCompositeChild;
+ (void)pushCompositeChild;
+ (void)setDefaultDirection:(GtkTextDirection)dir;

/**
 * Methods
 */

- (GtkWidget*)WIDGET;

/**
 * - (bool*)activate;
 *
 * @returns bool
 */
- (bool)activate;

/**
 * - (void*)addAcceleratorWithAccelSignal:(OFString*)accelSignal andAccelGroup:(GtkAccelGroup*)accelGroup andAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods andAccelFlags:(GtkAccelFlags)accelFlags;
 *
 * @param accelSignal
 * @param accelGroup
 * @param accelKey
 * @param accelMods
 * @param accelFlags
 */
- (void)addAcceleratorWithAccelSignal:(OFString*)accelSignal andAccelGroup:(GtkAccelGroup*)accelGroup andAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods andAccelFlags:(GtkAccelFlags)accelFlags;

/**
 * - (void*)addDeviceEventsWithDevice:(GdkDevice*)device andEvents:(GdkEventMask)events;
 *
 * @param device
 * @param events
 */
- (void)addDeviceEventsWithDevice:(GdkDevice*)device andEvents:(GdkEventMask)events;

/**
 * - (void*)addEvents:(gint)events;
 *
 * @param events
 */
- (void)addEvents:(gint)events;

/**
 * - (void*)addMnemonicLabel:(OGTKWidget*)label;
 *
 * @param label
 */
- (void)addMnemonicLabel:(OGTKWidget*)label;

/**
 * - (guint*)addTickCallbackWithCallback:(GtkTickCallback)callback andUserData:(gpointer)userData andNotify:(GDestroyNotify)notify;
 *
 * @param callback
 * @param userData
 * @param notify
 * @returns guint
 */
- (guint)addTickCallbackWithCallback:(GtkTickCallback)callback andUserData:(gpointer)userData andNotify:(GDestroyNotify)notify;

/**
 * - (bool*)canActivateAccel:(guint)signalId;
 *
 * @param signalId
 * @returns bool
 */
- (bool)canActivateAccel:(guint)signalId;

/**
 * - (bool*)childFocus:(GtkDirectionType)direction;
 *
 * @param direction
 * @returns bool
 */
- (bool)childFocus:(GtkDirectionType)direction;

/**
 * - (void*)childNotify:(OFString*)childProperty;
 *
 * @param childProperty
 */
- (void)childNotify:(OFString*)childProperty;

/**
 * - (void*)classPathWithPathLength:(guint*)pathLength andPath:(gchar**)path andPathReversed:(gchar**)pathReversed;
 *
 * @param pathLength
 * @param path
 * @param pathReversed
 */
- (void)classPathWithPathLength:(guint*)pathLength andPath:(gchar**)path andPathReversed:(gchar**)pathReversed;

/**
 * - (bool*)computeExpand:(GtkOrientation)orientation;
 *
 * @param orientation
 * @returns bool
 */
- (bool)computeExpand:(GtkOrientation)orientation;

/**
 * - (PangoContext**)createPangoContext;
 *
 * @returns PangoContext*
 */
- (PangoContext*)createPangoContext;

/**
 * - (PangoLayout**)createPangoLayout:(OFString*)text;
 *
 * @param text
 * @returns PangoLayout*
 */
- (PangoLayout*)createPangoLayout:(OFString*)text;

/**
 * - (void*)destroy;
 *
 */
- (void)destroy;

/**
 * - (void*)destroyed:(GtkWidget**)widgetPointer;
 *
 * @param widgetPointer
 */
- (void)destroyed:(GtkWidget**)widgetPointer;

/**
 * - (bool*)deviceIsShadowed:(GdkDevice*)device;
 *
 * @param device
 * @returns bool
 */
- (bool)deviceIsShadowed:(GdkDevice*)device;

/**
 * - (GdkDragContext**)gtkDragBeginWithTargets:(GtkTargetList*)targets andActions:(GdkDragAction)actions andButton:(gint)button andEvent:(GdkEvent*)event;
 *
 * @param targets
 * @param actions
 * @param button
 * @param event
 * @returns GdkDragContext*
 */
- (GdkDragContext*)gtkDragBeginWithTargets:(GtkTargetList*)targets andActions:(GdkDragAction)actions andButton:(gint)button andEvent:(GdkEvent*)event;

/**
 * - (GdkDragContext**)gtkDragBeginWithCoordinatesWithTargets:(GtkTargetList*)targets andActions:(GdkDragAction)actions andButton:(gint)button andEvent:(GdkEvent*)event andX:(gint)x andY:(gint)y;
 *
 * @param targets
 * @param actions
 * @param button
 * @param event
 * @param x
 * @param y
 * @returns GdkDragContext*
 */
- (GdkDragContext*)gtkDragBeginWithCoordinatesWithTargets:(GtkTargetList*)targets andActions:(GdkDragAction)actions andButton:(gint)button andEvent:(GdkEvent*)event andX:(gint)x andY:(gint)y;

/**
 * - (bool*)gtkDragCheckThresholdWithStartX:(gint)startX andStartY:(gint)startY andCurrentX:(gint)currentX andCurrentY:(gint)currentY;
 *
 * @param startX
 * @param startY
 * @param currentX
 * @param currentY
 * @returns bool
 */
- (bool)gtkDragCheckThresholdWithStartX:(gint)startX andStartY:(gint)startY andCurrentX:(gint)currentX andCurrentY:(gint)currentY;

/**
 * - (void*)gtkDragDestAddImageTargets;
 *
 */
- (void)gtkDragDestAddImageTargets;

/**
 * - (void*)gtkDragDestAddTextTargets;
 *
 */
- (void)gtkDragDestAddTextTargets;

/**
 * - (void*)gtkDragDestAddUriTargets;
 *
 */
- (void)gtkDragDestAddUriTargets;

/**
 * - (GdkAtom*)gtkDragDestFindTargetWithContext:(GdkDragContext*)context andTargetList:(GtkTargetList*)targetList;
 *
 * @param context
 * @param targetList
 * @returns GdkAtom
 */
- (GdkAtom)gtkDragDestFindTargetWithContext:(GdkDragContext*)context andTargetList:(GtkTargetList*)targetList;

/**
 * - (GtkTargetList**)gtkDragDestGetTargetList;
 *
 * @returns GtkTargetList*
 */
- (GtkTargetList*)gtkDragDestGetTargetList;

/**
 * - (bool*)gtkDragDestGetTrackMotion;
 *
 * @returns bool
 */
- (bool)gtkDragDestGetTrackMotion;

/**
 * - (void*)gtkDragDestSetWithFlags:(GtkDestDefaults)flags andTargets:(const GtkTargetEntry*)targets andNtargets:(gint)ntargets andActions:(GdkDragAction)actions;
 *
 * @param flags
 * @param targets
 * @param ntargets
 * @param actions
 */
- (void)gtkDragDestSetWithFlags:(GtkDestDefaults)flags andTargets:(const GtkTargetEntry*)targets andNtargets:(gint)ntargets andActions:(GdkDragAction)actions;

/**
 * - (void*)gtkDragDestSetProxyWithProxyWindow:(GdkWindow*)proxyWindow andProtocol:(GdkDragProtocol)protocol andUseCoordinates:(bool)useCoordinates;
 *
 * @param proxyWindow
 * @param protocol
 * @param useCoordinates
 */
- (void)gtkDragDestSetProxyWithProxyWindow:(GdkWindow*)proxyWindow andProtocol:(GdkDragProtocol)protocol andUseCoordinates:(bool)useCoordinates;

/**
 * - (void*)gtkDragDestSetTargetList:(GtkTargetList*)targetList;
 *
 * @param targetList
 */
- (void)gtkDragDestSetTargetList:(GtkTargetList*)targetList;

/**
 * - (void*)gtkDragDestSetTrackMotion:(bool)trackMotion;
 *
 * @param trackMotion
 */
- (void)gtkDragDestSetTrackMotion:(bool)trackMotion;

/**
 * - (void*)gtkDragDestUnset;
 *
 */
- (void)gtkDragDestUnset;

/**
 * - (void*)gtkDragGetDataWithContext:(GdkDragContext*)context andTarget:(GdkAtom)target andTime:(guint32)time;
 *
 * @param context
 * @param target
 * @param time
 */
- (void)gtkDragGetDataWithContext:(GdkDragContext*)context andTarget:(GdkAtom)target andTime:(guint32)time;

/**
 * - (void*)gtkDragHighlight;
 *
 */
- (void)gtkDragHighlight;

/**
 * - (void*)gtkDragSourceAddImageTargets;
 *
 */
- (void)gtkDragSourceAddImageTargets;

/**
 * - (void*)gtkDragSourceAddTextTargets;
 *
 */
- (void)gtkDragSourceAddTextTargets;

/**
 * - (void*)gtkDragSourceAddUriTargets;
 *
 */
- (void)gtkDragSourceAddUriTargets;

/**
 * - (GtkTargetList**)gtkDragSourceGetTargetList;
 *
 * @returns GtkTargetList*
 */
- (GtkTargetList*)gtkDragSourceGetTargetList;

/**
 * - (void*)gtkDragSourceSetWithStartButtonMask:(GdkModifierType)startButtonMask andTargets:(const GtkTargetEntry*)targets andNtargets:(gint)ntargets andActions:(GdkDragAction)actions;
 *
 * @param startButtonMask
 * @param targets
 * @param ntargets
 * @param actions
 */
- (void)gtkDragSourceSetWithStartButtonMask:(GdkModifierType)startButtonMask andTargets:(const GtkTargetEntry*)targets andNtargets:(gint)ntargets andActions:(GdkDragAction)actions;

/**
 * - (void*)gtkDragSourceSetIconGicon:(GIcon*)icon;
 *
 * @param icon
 */
- (void)gtkDragSourceSetIconGicon:(GIcon*)icon;

/**
 * - (void*)gtkDragSourceSetIconName:(OFString*)iconName;
 *
 * @param iconName
 */
- (void)gtkDragSourceSetIconName:(OFString*)iconName;

/**
 * - (void*)gtkDragSourceSetIconPixbuf:(GdkPixbuf*)pixbuf;
 *
 * @param pixbuf
 */
- (void)gtkDragSourceSetIconPixbuf:(GdkPixbuf*)pixbuf;

/**
 * - (void*)gtkDragSourceSetIconStock:(OFString*)stockId;
 *
 * @param stockId
 */
- (void)gtkDragSourceSetIconStock:(OFString*)stockId;

/**
 * - (void*)gtkDragSourceSetTargetList:(GtkTargetList*)targetList;
 *
 * @param targetList
 */
- (void)gtkDragSourceSetTargetList:(GtkTargetList*)targetList;

/**
 * - (void*)gtkDragSourceUnset;
 *
 */
- (void)gtkDragSourceUnset;

/**
 * - (void*)gtkDragUnhighlight;
 *
 */
- (void)gtkDragUnhighlight;

/**
 * - (void*)draw:(cairo_t*)cr;
 *
 * @param cr
 */
- (void)draw:(cairo_t*)cr;

/**
 * - (void*)ensureStyle;
 *
 */
- (void)ensureStyle;

/**
 * - (void*)errorBell;
 *
 */
- (void)errorBell;

/**
 * - (bool*)event:(GdkEvent*)event;
 *
 * @param event
 * @returns bool
 */
- (bool)event:(GdkEvent*)event;

/**
 * - (void*)freezeChildNotify;
 *
 */
- (void)freezeChildNotify;

/**
 * - (AtkObject**)getAccessible;
 *
 * @returns AtkObject*
 */
- (AtkObject*)getAccessible;

/**
 * - (GActionGroup**)getActionGroup:(OFString*)prefix;
 *
 * @param prefix
 * @returns GActionGroup*
 */
- (GActionGroup*)getActionGroup:(OFString*)prefix;

/**
 * - (int*)getAllocatedBaseline;
 *
 * @returns int
 */
- (int)getAllocatedBaseline;

/**
 * - (int*)getAllocatedHeight;
 *
 * @returns int
 */
- (int)getAllocatedHeight;

/**
 * - (void*)getAllocatedSizeWithAllocation:(GtkAllocation*)allocation andBaseline:(int*)baseline;
 *
 * @param allocation
 * @param baseline
 */
- (void)getAllocatedSizeWithAllocation:(GtkAllocation*)allocation andBaseline:(int*)baseline;

/**
 * - (int*)getAllocatedWidth;
 *
 * @returns int
 */
- (int)getAllocatedWidth;

/**
 * - (void*)getAllocation:(GtkAllocation*)allocation;
 *
 * @param allocation
 */
- (void)getAllocation:(GtkAllocation*)allocation;

/**
 * - (OGTKWidget**)getAncestor:(GType)widgetType;
 *
 * @param widgetType
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getAncestor:(GType)widgetType;

/**
 * - (bool*)getAppPaintable;
 *
 * @returns bool
 */
- (bool)getAppPaintable;

/**
 * - (bool*)getCanDefault;
 *
 * @returns bool
 */
- (bool)getCanDefault;

/**
 * - (bool*)getCanFocus;
 *
 * @returns bool
 */
- (bool)getCanFocus;

/**
 * - (void*)getChildRequisition:(GtkRequisition*)requisition;
 *
 * @param requisition
 */
- (void)getChildRequisition:(GtkRequisition*)requisition;

/**
 * - (bool*)getChildVisible;
 *
 * @returns bool
 */
- (bool)getChildVisible;

/**
 * - (void*)getClip:(GtkAllocation*)clip;
 *
 * @param clip
 */
- (void)getClip:(GtkAllocation*)clip;

/**
 * - (GtkClipboard**)getClipboard:(GdkAtom)selection;
 *
 * @param selection
 * @returns GtkClipboard*
 */
- (GtkClipboard*)getClipboard:(GdkAtom)selection;

/**
 * - (OFString**)getCompositeName;
 *
 * @returns OFString*
 */
- (OFString*)getCompositeName;

/**
 * - (bool*)getDeviceEnabled:(GdkDevice*)device;
 *
 * @param device
 * @returns bool
 */
- (bool)getDeviceEnabled:(GdkDevice*)device;

/**
 * - (GdkEventMask*)getDeviceEvents:(GdkDevice*)device;
 *
 * @param device
 * @returns GdkEventMask
 */
- (GdkEventMask)getDeviceEvents:(GdkDevice*)device;

/**
 * - (GtkTextDirection*)getDirection;
 *
 * @returns GtkTextDirection
 */
- (GtkTextDirection)getDirection;

/**
 * - (GdkDisplay**)getDisplay;
 *
 * @returns GdkDisplay*
 */
- (GdkDisplay*)getDisplay;

/**
 * - (bool*)getDoubleBuffered;
 *
 * @returns bool
 */
- (bool)getDoubleBuffered;

/**
 * - (gint*)getEvents;
 *
 * @returns gint
 */
- (gint)getEvents;

/**
 * - (bool*)getFocusOnClick;
 *
 * @returns bool
 */
- (bool)getFocusOnClick;

/**
 * - (PangoFontMap**)getFontMap;
 *
 * @returns PangoFontMap*
 */
- (PangoFontMap*)getFontMap;

/**
 * - (const cairo_font_options_t**)getFontOptions;
 *
 * @returns const cairo_font_options_t*
 */
- (const cairo_font_options_t*)getFontOptions;

/**
 * - (GdkFrameClock**)getFrameClock;
 *
 * @returns GdkFrameClock*
 */
- (GdkFrameClock*)getFrameClock;

/**
 * - (GtkAlign*)getHalign;
 *
 * @returns GtkAlign
 */
- (GtkAlign)getHalign;

/**
 * - (bool*)getHasTooltip;
 *
 * @returns bool
 */
- (bool)getHasTooltip;

/**
 * - (bool*)getHasWindow;
 *
 * @returns bool
 */
- (bool)getHasWindow;

/**
 * - (bool*)getHexpand;
 *
 * @returns bool
 */
- (bool)getHexpand;

/**
 * - (bool*)getHexpandSet;
 *
 * @returns bool
 */
- (bool)getHexpandSet;

/**
 * - (bool*)getMapped;
 *
 * @returns bool
 */
- (bool)getMapped;

/**
 * - (gint*)getMarginBottom;
 *
 * @returns gint
 */
- (gint)getMarginBottom;

/**
 * - (gint*)getMarginEnd;
 *
 * @returns gint
 */
- (gint)getMarginEnd;

/**
 * - (gint*)getMarginLeft;
 *
 * @returns gint
 */
- (gint)getMarginLeft;

/**
 * - (gint*)getMarginRight;
 *
 * @returns gint
 */
- (gint)getMarginRight;

/**
 * - (gint*)getMarginStart;
 *
 * @returns gint
 */
- (gint)getMarginStart;

/**
 * - (gint*)getMarginTop;
 *
 * @returns gint
 */
- (gint)getMarginTop;

/**
 * - (GdkModifierType*)getModifierMask:(GdkModifierIntent)intent;
 *
 * @param intent
 * @returns GdkModifierType
 */
- (GdkModifierType)getModifierMask:(GdkModifierIntent)intent;

/**
 * - (GtkRcStyle**)getModifierStyle;
 *
 * @returns GtkRcStyle*
 */
- (GtkRcStyle*)getModifierStyle;

/**
 * - (OFString**)getName;
 *
 * @returns OFString*
 */
- (OFString*)getName;

/**
 * - (bool*)getNoShowAll;
 *
 * @returns bool
 */
- (bool)getNoShowAll;

/**
 * - (double*)getOpacity;
 *
 * @returns double
 */
- (double)getOpacity;

/**
 * - (PangoContext**)getPangoContext;
 *
 * @returns PangoContext*
 */
- (PangoContext*)getPangoContext;

/**
 * - (OGTKWidget**)getParent;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getParent;

/**
 * - (GdkWindow**)getParentWindow;
 *
 * @returns GdkWindow*
 */
- (GdkWindow*)getParentWindow;

/**
 * - (GtkWidgetPath**)getPath;
 *
 * @returns GtkWidgetPath*
 */
- (GtkWidgetPath*)getPath;

/**
 * - (void*)getPointerWithX:(gint*)x andY:(gint*)y;
 *
 * @param x
 * @param y
 */
- (void)getPointerWithX:(gint*)x andY:(gint*)y;

/**
 * - (void*)getPreferredHeightWithMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight;
 *
 * @param minimumHeight
 * @param naturalHeight
 */
- (void)getPreferredHeightWithMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight;

/**
 * - (void*)getPreferredHeightAndBaselineForWidthWithWidth:(gint)width andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight andMinimumBaseline:(gint*)minimumBaseline andNaturalBaseline:(gint*)naturalBaseline;
 *
 * @param width
 * @param minimumHeight
 * @param naturalHeight
 * @param minimumBaseline
 * @param naturalBaseline
 */
- (void)getPreferredHeightAndBaselineForWidthWithWidth:(gint)width andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight andMinimumBaseline:(gint*)minimumBaseline andNaturalBaseline:(gint*)naturalBaseline;

/**
 * - (void*)getPreferredHeightForWidthWithWidth:(gint)width andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight;
 *
 * @param width
 * @param minimumHeight
 * @param naturalHeight
 */
- (void)getPreferredHeightForWidthWithWidth:(gint)width andMinimumHeight:(gint*)minimumHeight andNaturalHeight:(gint*)naturalHeight;

/**
 * - (void*)getPreferredSizeWithMinimumSize:(GtkRequisition*)minimumSize andNaturalSize:(GtkRequisition*)naturalSize;
 *
 * @param minimumSize
 * @param naturalSize
 */
- (void)getPreferredSizeWithMinimumSize:(GtkRequisition*)minimumSize andNaturalSize:(GtkRequisition*)naturalSize;

/**
 * - (void*)getPreferredWidthWithMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth;
 *
 * @param minimumWidth
 * @param naturalWidth
 */
- (void)getPreferredWidthWithMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth;

/**
 * - (void*)getPreferredWidthForHeightWithHeight:(gint)height andMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth;
 *
 * @param height
 * @param minimumWidth
 * @param naturalWidth
 */
- (void)getPreferredWidthForHeightWithHeight:(gint)height andMinimumWidth:(gint*)minimumWidth andNaturalWidth:(gint*)naturalWidth;

/**
 * - (bool*)getRealized;
 *
 * @returns bool
 */
- (bool)getRealized;

/**
 * - (bool*)getReceivesDefault;
 *
 * @returns bool
 */
- (bool)getReceivesDefault;

/**
 * - (GtkSizeRequestMode*)getRequestMode;
 *
 * @returns GtkSizeRequestMode
 */
- (GtkSizeRequestMode)getRequestMode;

/**
 * - (void*)getRequisition:(GtkRequisition*)requisition;
 *
 * @param requisition
 */
- (void)getRequisition:(GtkRequisition*)requisition;

/**
 * - (GdkWindow**)getRootWindow;
 *
 * @returns GdkWindow*
 */
- (GdkWindow*)getRootWindow;

/**
 * - (gint*)getScaleFactor;
 *
 * @returns gint
 */
- (gint)getScaleFactor;

/**
 * - (GdkScreen**)getScreen;
 *
 * @returns GdkScreen*
 */
- (GdkScreen*)getScreen;

/**
 * - (bool*)getSensitive;
 *
 * @returns bool
 */
- (bool)getSensitive;

/**
 * - (GtkSettings**)getSettings;
 *
 * @returns GtkSettings*
 */
- (GtkSettings*)getSettings;

/**
 * - (void*)getSizeRequestWithWidth:(gint*)width andHeight:(gint*)height;
 *
 * @param width
 * @param height
 */
- (void)getSizeRequestWithWidth:(gint*)width andHeight:(gint*)height;

/**
 * - (GtkStateType*)getState;
 *
 * @returns GtkStateType
 */
- (GtkStateType)getState;

/**
 * - (GtkStateFlags*)getStateFlags;
 *
 * @returns GtkStateFlags
 */
- (GtkStateFlags)getStateFlags;

/**
 * - (GtkStyle**)getStyle;
 *
 * @returns GtkStyle*
 */
- (GtkStyle*)getStyle;

/**
 * - (GtkStyleContext**)getStyleContext;
 *
 * @returns GtkStyleContext*
 */
- (GtkStyleContext*)getStyleContext;

/**
 * - (bool*)getSupportMultidevice;
 *
 * @returns bool
 */
- (bool)getSupportMultidevice;

/**
 * - (GObject**)getTemplateChildWithWidgetType:(GType)widgetType andName:(OFString*)name;
 *
 * @param widgetType
 * @param name
 * @returns GObject*
 */
- (GObject*)getTemplateChildWithWidgetType:(GType)widgetType andName:(OFString*)name;

/**
 * - (OFString**)getTooltipMarkup;
 *
 * @returns OFString*
 */
- (OFString*)getTooltipMarkup;

/**
 * - (OFString**)getTooltipText;
 *
 * @returns OFString*
 */
- (OFString*)getTooltipText;

/**
 * - (GtkWindow**)getTooltipWindow;
 *
 * @returns GtkWindow*
 */
- (GtkWindow*)getTooltipWindow;

/**
 * - (OGTKWidget**)getToplevel;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getToplevel;

/**
 * - (GtkAlign*)getValign;
 *
 * @returns GtkAlign
 */
- (GtkAlign)getValign;

/**
 * - (GtkAlign*)getValignWithBaseline;
 *
 * @returns GtkAlign
 */
- (GtkAlign)getValignWithBaseline;

/**
 * - (bool*)getVexpand;
 *
 * @returns bool
 */
- (bool)getVexpand;

/**
 * - (bool*)getVexpandSet;
 *
 * @returns bool
 */
- (bool)getVexpandSet;

/**
 * - (bool*)getVisible;
 *
 * @returns bool
 */
- (bool)getVisible;

/**
 * - (GdkVisual**)getVisual;
 *
 * @returns GdkVisual*
 */
- (GdkVisual*)getVisual;

/**
 * - (GdkWindow**)getWindow;
 *
 * @returns GdkWindow*
 */
- (GdkWindow*)getWindow;

/**
 * - (void*)gtkGrabAdd;
 *
 */
- (void)gtkGrabAdd;

/**
 * - (void*)grabDefault;
 *
 */
- (void)grabDefault;

/**
 * - (void*)grabFocus;
 *
 */
- (void)grabFocus;

/**
 * - (void*)gtkGrabRemove;
 *
 */
- (void)gtkGrabRemove;

/**
 * - (bool*)hasDefault;
 *
 * @returns bool
 */
- (bool)hasDefault;

/**
 * - (bool*)hasFocus;
 *
 * @returns bool
 */
- (bool)hasFocus;

/**
 * - (bool*)hasGrab;
 *
 * @returns bool
 */
- (bool)hasGrab;

/**
 * - (bool*)hasRcStyle;
 *
 * @returns bool
 */
- (bool)hasRcStyle;

/**
 * - (bool*)hasScreen;
 *
 * @returns bool
 */
- (bool)hasScreen;

/**
 * - (bool*)hasVisibleFocus;
 *
 * @returns bool
 */
- (bool)hasVisibleFocus;

/**
 * - (void*)hide;
 *
 */
- (void)hide;

/**
 * - (bool*)hideOnDelete;
 *
 * @returns bool
 */
- (bool)hideOnDelete;

/**
 * - (bool*)inDestruction;
 *
 * @returns bool
 */
- (bool)inDestruction;

/**
 * - (void*)initTemplate;
 *
 */
- (void)initTemplate;

/**
 * - (void*)inputShapeCombineRegion:(cairo_region_t*)region;
 *
 * @param region
 */
- (void)inputShapeCombineRegion:(cairo_region_t*)region;

/**
 * - (void*)insertActionGroupWithName:(OFString*)name andGroup:(GActionGroup*)group;
 *
 * @param name
 * @param group
 */
- (void)insertActionGroupWithName:(OFString*)name andGroup:(GActionGroup*)group;

/**
 * - (bool*)intersectWithArea:(const GdkRectangle*)area andIntersection:(GdkRectangle*)intersection;
 *
 * @param area
 * @param intersection
 * @returns bool
 */
- (bool)intersectWithArea:(const GdkRectangle*)area andIntersection:(GdkRectangle*)intersection;

/**
 * - (bool*)isAncestor:(OGTKWidget*)ancestor;
 *
 * @param ancestor
 * @returns bool
 */
- (bool)isAncestor:(OGTKWidget*)ancestor;

/**
 * - (bool*)isComposited;
 *
 * @returns bool
 */
- (bool)isComposited;

/**
 * - (bool*)isDrawable;
 *
 * @returns bool
 */
- (bool)isDrawable;

/**
 * - (bool*)isFocus;
 *
 * @returns bool
 */
- (bool)isFocus;

/**
 * - (bool*)isSensitive;
 *
 * @returns bool
 */
- (bool)isSensitive;

/**
 * - (bool*)isToplevel;
 *
 * @returns bool
 */
- (bool)isToplevel;

/**
 * - (bool*)isVisible;
 *
 * @returns bool
 */
- (bool)isVisible;

/**
 * - (bool*)keynavFailed:(GtkDirectionType)direction;
 *
 * @param direction
 * @returns bool
 */
- (bool)keynavFailed:(GtkDirectionType)direction;

/**
 * - (GList**)listAccelClosures;
 *
 * @returns GList*
 */
- (GList*)listAccelClosures;

/**
 * - (const gchar***)listActionPrefixes;
 *
 * @returns const gchar**
 */
- (const gchar**)listActionPrefixes;

/**
 * - (GList**)listMnemonicLabels;
 *
 * @returns GList*
 */
- (GList*)listMnemonicLabels;

/**
 * - (void*)map;
 *
 */
- (void)map;

/**
 * - (bool*)mnemonicActivate:(bool)groupCycling;
 *
 * @param groupCycling
 * @returns bool
 */
- (bool)mnemonicActivate:(bool)groupCycling;

/**
 * - (void*)modifyBaseWithState:(GtkStateType)state andColor:(const GdkColor*)color;
 *
 * @param state
 * @param color
 */
- (void)modifyBaseWithState:(GtkStateType)state andColor:(const GdkColor*)color;

/**
 * - (void*)modifyBgWithState:(GtkStateType)state andColor:(const GdkColor*)color;
 *
 * @param state
 * @param color
 */
- (void)modifyBgWithState:(GtkStateType)state andColor:(const GdkColor*)color;

/**
 * - (void*)modifyCursorWithPrimary:(const GdkColor*)primary andSecondary:(const GdkColor*)secondary;
 *
 * @param primary
 * @param secondary
 */
- (void)modifyCursorWithPrimary:(const GdkColor*)primary andSecondary:(const GdkColor*)secondary;

/**
 * - (void*)modifyFgWithState:(GtkStateType)state andColor:(const GdkColor*)color;
 *
 * @param state
 * @param color
 */
- (void)modifyFgWithState:(GtkStateType)state andColor:(const GdkColor*)color;

/**
 * - (void*)modifyFont:(PangoFontDescription*)fontDesc;
 *
 * @param fontDesc
 */
- (void)modifyFont:(PangoFontDescription*)fontDesc;

/**
 * - (void*)modifyStyle:(GtkRcStyle*)style;
 *
 * @param style
 */
- (void)modifyStyle:(GtkRcStyle*)style;

/**
 * - (void*)modifyTextWithState:(GtkStateType)state andColor:(const GdkColor*)color;
 *
 * @param state
 * @param color
 */
- (void)modifyTextWithState:(GtkStateType)state andColor:(const GdkColor*)color;

/**
 * - (void*)overrideBackgroundColorWithState:(GtkStateFlags)state andColor:(const GdkRGBA*)color;
 *
 * @param state
 * @param color
 */
- (void)overrideBackgroundColorWithState:(GtkStateFlags)state andColor:(const GdkRGBA*)color;

/**
 * - (void*)overrideColorWithState:(GtkStateFlags)state andColor:(const GdkRGBA*)color;
 *
 * @param state
 * @param color
 */
- (void)overrideColorWithState:(GtkStateFlags)state andColor:(const GdkRGBA*)color;

/**
 * - (void*)overrideCursorWithCursor:(const GdkRGBA*)cursor andSecondaryCursor:(const GdkRGBA*)secondaryCursor;
 *
 * @param cursor
 * @param secondaryCursor
 */
- (void)overrideCursorWithCursor:(const GdkRGBA*)cursor andSecondaryCursor:(const GdkRGBA*)secondaryCursor;

/**
 * - (void*)overrideFont:(const PangoFontDescription*)fontDesc;
 *
 * @param fontDesc
 */
- (void)overrideFont:(const PangoFontDescription*)fontDesc;

/**
 * - (void*)overrideSymbolicColorWithName:(OFString*)name andColor:(const GdkRGBA*)color;
 *
 * @param name
 * @param color
 */
- (void)overrideSymbolicColorWithName:(OFString*)name andColor:(const GdkRGBA*)color;

/**
 * - (void*)pathWithPathLength:(guint*)pathLength andPath:(gchar**)path andPathReversed:(gchar**)pathReversed;
 *
 * @param pathLength
 * @param path
 * @param pathReversed
 */
- (void)pathWithPathLength:(guint*)pathLength andPath:(gchar**)path andPathReversed:(gchar**)pathReversed;

/**
 * - (void*)queueAllocate;
 *
 */
- (void)queueAllocate;

/**
 * - (void*)queueComputeExpand;
 *
 */
- (void)queueComputeExpand;

/**
 * - (void*)queueDraw;
 *
 */
- (void)queueDraw;

/**
 * - (void*)queueDrawAreaWithX:(gint)x andY:(gint)y andWidth:(gint)width andHeight:(gint)height;
 *
 * @param x
 * @param y
 * @param width
 * @param height
 */
- (void)queueDrawAreaWithX:(gint)x andY:(gint)y andWidth:(gint)width andHeight:(gint)height;

/**
 * - (void*)queueDrawRegion:(const cairo_region_t*)region;
 *
 * @param region
 */
- (void)queueDrawRegion:(const cairo_region_t*)region;

/**
 * - (void*)queueResize;
 *
 */
- (void)queueResize;

/**
 * - (void*)queueResizeNoRedraw;
 *
 */
- (void)queueResizeNoRedraw;

/**
 * - (void*)realize;
 *
 */
- (void)realize;

/**
 * - (cairo_region_t**)regionIntersect:(const cairo_region_t*)region;
 *
 * @param region
 * @returns cairo_region_t*
 */
- (cairo_region_t*)regionIntersect:(const cairo_region_t*)region;

/**
 * - (void*)registerWindow:(GdkWindow*)window;
 *
 * @param window
 */
- (void)registerWindow:(GdkWindow*)window;

/**
 * - (bool*)removeAcceleratorWithAccelGroup:(GtkAccelGroup*)accelGroup andAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods;
 *
 * @param accelGroup
 * @param accelKey
 * @param accelMods
 * @returns bool
 */
- (bool)removeAcceleratorWithAccelGroup:(GtkAccelGroup*)accelGroup andAccelKey:(guint)accelKey andAccelMods:(GdkModifierType)accelMods;

/**
 * - (void*)removeMnemonicLabel:(OGTKWidget*)label;
 *
 * @param label
 */
- (void)removeMnemonicLabel:(OGTKWidget*)label;

/**
 * - (void*)removeTickCallback:(guint)id;
 *
 * @param id
 */
- (void)removeTickCallback:(guint)id;

/**
 * - (GdkPixbuf**)renderIconWithStockId:(OFString*)stockId andSize:(GtkIconSize)size andDetail:(OFString*)detail;
 *
 * @param stockId
 * @param size
 * @param detail
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)renderIconWithStockId:(OFString*)stockId andSize:(GtkIconSize)size andDetail:(OFString*)detail;

/**
 * - (GdkPixbuf**)renderIconPixbufWithStockId:(OFString*)stockId andSize:(GtkIconSize)size;
 *
 * @param stockId
 * @param size
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)renderIconPixbufWithStockId:(OFString*)stockId andSize:(GtkIconSize)size;

/**
 * - (void*)reparent:(OGTKWidget*)newParent;
 *
 * @param newParent
 */
- (void)reparent:(OGTKWidget*)newParent;

/**
 * - (void*)resetRcStyles;
 *
 */
- (void)resetRcStyles;

/**
 * - (void*)resetStyle;
 *
 */
- (void)resetStyle;

/**
 * - (gint*)sendExpose:(GdkEvent*)event;
 *
 * @param event
 * @returns gint
 */
- (gint)sendExpose:(GdkEvent*)event;

/**
 * - (bool*)sendFocusChange:(GdkEvent*)event;
 *
 * @param event
 * @returns bool
 */
- (bool)sendFocusChange:(GdkEvent*)event;

/**
 * - (void*)setAccelPathWithAccelPath:(OFString*)accelPath andAccelGroup:(GtkAccelGroup*)accelGroup;
 *
 * @param accelPath
 * @param accelGroup
 */
- (void)setAccelPathWithAccelPath:(OFString*)accelPath andAccelGroup:(GtkAccelGroup*)accelGroup;

/**
 * - (void*)setAllocation:(const GtkAllocation*)allocation;
 *
 * @param allocation
 */
- (void)setAllocation:(const GtkAllocation*)allocation;

/**
 * - (void*)setAppPaintable:(bool)appPaintable;
 *
 * @param appPaintable
 */
- (void)setAppPaintable:(bool)appPaintable;

/**
 * - (void*)setCanDefault:(bool)canDefault;
 *
 * @param canDefault
 */
- (void)setCanDefault:(bool)canDefault;

/**
 * - (void*)setCanFocus:(bool)canFocus;
 *
 * @param canFocus
 */
- (void)setCanFocus:(bool)canFocus;

/**
 * - (void*)setChildVisible:(bool)isVisible;
 *
 * @param isVisible
 */
- (void)setChildVisible:(bool)isVisible;

/**
 * - (void*)setClip:(const GtkAllocation*)clip;
 *
 * @param clip
 */
- (void)setClip:(const GtkAllocation*)clip;

/**
 * - (void*)setCompositeName:(OFString*)name;
 *
 * @param name
 */
- (void)setCompositeName:(OFString*)name;

/**
 * - (void*)setDeviceEnabledWithDevice:(GdkDevice*)device andEnabled:(bool)enabled;
 *
 * @param device
 * @param enabled
 */
- (void)setDeviceEnabledWithDevice:(GdkDevice*)device andEnabled:(bool)enabled;

/**
 * - (void*)setDeviceEventsWithDevice:(GdkDevice*)device andEvents:(GdkEventMask)events;
 *
 * @param device
 * @param events
 */
- (void)setDeviceEventsWithDevice:(GdkDevice*)device andEvents:(GdkEventMask)events;

/**
 * - (void*)setDirection:(GtkTextDirection)dir;
 *
 * @param dir
 */
- (void)setDirection:(GtkTextDirection)dir;

/**
 * - (void*)setDoubleBuffered:(bool)doubleBuffered;
 *
 * @param doubleBuffered
 */
- (void)setDoubleBuffered:(bool)doubleBuffered;

/**
 * - (void*)setEvents:(gint)events;
 *
 * @param events
 */
- (void)setEvents:(gint)events;

/**
 * - (void*)setFocusOnClick:(bool)focusOnClick;
 *
 * @param focusOnClick
 */
- (void)setFocusOnClick:(bool)focusOnClick;

/**
 * - (void*)setFontMap:(PangoFontMap*)fontMap;
 *
 * @param fontMap
 */
- (void)setFontMap:(PangoFontMap*)fontMap;

/**
 * - (void*)setFontOptions:(const cairo_font_options_t*)options;
 *
 * @param options
 */
- (void)setFontOptions:(const cairo_font_options_t*)options;

/**
 * - (void*)setHalign:(GtkAlign)align;
 *
 * @param align
 */
- (void)setHalign:(GtkAlign)align;

/**
 * - (void*)setHasTooltip:(bool)hasTooltip;
 *
 * @param hasTooltip
 */
- (void)setHasTooltip:(bool)hasTooltip;

/**
 * - (void*)setHasWindow:(bool)hasWindow;
 *
 * @param hasWindow
 */
- (void)setHasWindow:(bool)hasWindow;

/**
 * - (void*)setHexpand:(bool)expand;
 *
 * @param expand
 */
- (void)setHexpand:(bool)expand;

/**
 * - (void*)setHexpandSet:(bool)set;
 *
 * @param set
 */
- (void)setHexpandSet:(bool)set;

/**
 * - (void*)setMapped:(bool)mapped;
 *
 * @param mapped
 */
- (void)setMapped:(bool)mapped;

/**
 * - (void*)setMarginBottom:(gint)margin;
 *
 * @param margin
 */
- (void)setMarginBottom:(gint)margin;

/**
 * - (void*)setMarginEnd:(gint)margin;
 *
 * @param margin
 */
- (void)setMarginEnd:(gint)margin;

/**
 * - (void*)setMarginLeft:(gint)margin;
 *
 * @param margin
 */
- (void)setMarginLeft:(gint)margin;

/**
 * - (void*)setMarginRight:(gint)margin;
 *
 * @param margin
 */
- (void)setMarginRight:(gint)margin;

/**
 * - (void*)setMarginStart:(gint)margin;
 *
 * @param margin
 */
- (void)setMarginStart:(gint)margin;

/**
 * - (void*)setMarginTop:(gint)margin;
 *
 * @param margin
 */
- (void)setMarginTop:(gint)margin;

/**
 * - (void*)setName:(OFString*)name;
 *
 * @param name
 */
- (void)setName:(OFString*)name;

/**
 * - (void*)setNoShowAll:(bool)noShowAll;
 *
 * @param noShowAll
 */
- (void)setNoShowAll:(bool)noShowAll;

/**
 * - (void*)setOpacity:(double)opacity;
 *
 * @param opacity
 */
- (void)setOpacity:(double)opacity;

/**
 * - (void*)setParent:(OGTKWidget*)parent;
 *
 * @param parent
 */
- (void)setParent:(OGTKWidget*)parent;

/**
 * - (void*)setParentWindow:(GdkWindow*)parentWindow;
 *
 * @param parentWindow
 */
- (void)setParentWindow:(GdkWindow*)parentWindow;

/**
 * - (void*)setRealized:(bool)realized;
 *
 * @param realized
 */
- (void)setRealized:(bool)realized;

/**
 * - (void*)setReceivesDefault:(bool)receivesDefault;
 *
 * @param receivesDefault
 */
- (void)setReceivesDefault:(bool)receivesDefault;

/**
 * - (void*)setRedrawOnAllocate:(bool)redrawOnAllocate;
 *
 * @param redrawOnAllocate
 */
- (void)setRedrawOnAllocate:(bool)redrawOnAllocate;

/**
 * - (void*)setSensitive:(bool)sensitive;
 *
 * @param sensitive
 */
- (void)setSensitive:(bool)sensitive;

/**
 * - (void*)setSizeRequestWithWidth:(gint)width andHeight:(gint)height;
 *
 * @param width
 * @param height
 */
- (void)setSizeRequestWithWidth:(gint)width andHeight:(gint)height;

/**
 * - (void*)setState:(GtkStateType)state;
 *
 * @param state
 */
- (void)setState:(GtkStateType)state;

/**
 * - (void*)setStateFlagsWithFlags:(GtkStateFlags)flags andClear:(bool)clear;
 *
 * @param flags
 * @param clear
 */
- (void)setStateFlagsWithFlags:(GtkStateFlags)flags andClear:(bool)clear;

/**
 * - (void*)setStyle:(GtkStyle*)style;
 *
 * @param style
 */
- (void)setStyle:(GtkStyle*)style;

/**
 * - (void*)setSupportMultidevice:(bool)supportMultidevice;
 *
 * @param supportMultidevice
 */
- (void)setSupportMultidevice:(bool)supportMultidevice;

/**
 * - (void*)setTooltipMarkup:(OFString*)markup;
 *
 * @param markup
 */
- (void)setTooltipMarkup:(OFString*)markup;

/**
 * - (void*)setTooltipText:(OFString*)text;
 *
 * @param text
 */
- (void)setTooltipText:(OFString*)text;

/**
 * - (void*)setTooltipWindow:(GtkWindow*)customWindow;
 *
 * @param customWindow
 */
- (void)setTooltipWindow:(GtkWindow*)customWindow;

/**
 * - (void*)setValign:(GtkAlign)align;
 *
 * @param align
 */
- (void)setValign:(GtkAlign)align;

/**
 * - (void*)setVexpand:(bool)expand;
 *
 * @param expand
 */
- (void)setVexpand:(bool)expand;

/**
 * - (void*)setVexpandSet:(bool)set;
 *
 * @param set
 */
- (void)setVexpandSet:(bool)set;

/**
 * - (void*)setVisible:(bool)visible;
 *
 * @param visible
 */
- (void)setVisible:(bool)visible;

/**
 * - (void*)setVisual:(GdkVisual*)visual;
 *
 * @param visual
 */
- (void)setVisual:(GdkVisual*)visual;

/**
 * - (void*)setWindow:(GdkWindow*)window;
 *
 * @param window
 */
- (void)setWindow:(GdkWindow*)window;

/**
 * - (void*)shapeCombineRegion:(cairo_region_t*)region;
 *
 * @param region
 */
- (void)shapeCombineRegion:(cairo_region_t*)region;

/**
 * - (void*)show;
 *
 */
- (void)show;

/**
 * - (void*)showAll;
 *
 */
- (void)showAll;

/**
 * - (void*)showNow;
 *
 */
- (void)showNow;

/**
 * - (void*)sizeAllocate:(GtkAllocation*)allocation;
 *
 * @param allocation
 */
- (void)sizeAllocate:(GtkAllocation*)allocation;

/**
 * - (void*)sizeAllocateWithBaselineWithAllocation:(GtkAllocation*)allocation andBaseline:(gint)baseline;
 *
 * @param allocation
 * @param baseline
 */
- (void)sizeAllocateWithBaselineWithAllocation:(GtkAllocation*)allocation andBaseline:(gint)baseline;

/**
 * - (void*)sizeRequest:(GtkRequisition*)requisition;
 *
 * @param requisition
 */
- (void)sizeRequest:(GtkRequisition*)requisition;

/**
 * - (void*)styleAttach;
 *
 */
- (void)styleAttach;

/**
 * - (void*)styleGetPropertyWithPropertyName:(OFString*)propertyName andValue:(GValue*)value;
 *
 * @param propertyName
 * @param value
 */
- (void)styleGetPropertyWithPropertyName:(OFString*)propertyName andValue:(GValue*)value;

/**
 * - (void*)styleGetValistWithFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs;
 *
 * @param firstPropertyName
 * @param varArgs
 */
- (void)styleGetValistWithFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs;

/**
 * - (void*)thawChildNotify;
 *
 */
- (void)thawChildNotify;

/**
 * - (bool*)translateCoordinatesWithDestWidget:(OGTKWidget*)destWidget andSrcX:(gint)srcX andSrcY:(gint)srcY andDestX:(gint*)destX andDestY:(gint*)destY;
 *
 * @param destWidget
 * @param srcX
 * @param srcY
 * @param destX
 * @param destY
 * @returns bool
 */
- (bool)translateCoordinatesWithDestWidget:(OGTKWidget*)destWidget andSrcX:(gint)srcX andSrcY:(gint)srcY andDestX:(gint*)destX andDestY:(gint*)destY;

/**
 * - (void*)triggerTooltipQuery;
 *
 */
- (void)triggerTooltipQuery;

/**
 * - (void*)unmap;
 *
 */
- (void)unmap;

/**
 * - (void*)unparent;
 *
 */
- (void)unparent;

/**
 * - (void*)unrealize;
 *
 */
- (void)unrealize;

/**
 * - (void*)unregisterWindow:(GdkWindow*)window;
 *
 * @param window
 */
- (void)unregisterWindow:(GdkWindow*)window;

/**
 * - (void*)unsetStateFlags:(GtkStateFlags)flags;
 *
 * @param flags
 */
- (void)unsetStateFlags:(GtkStateFlags)flags;

@end