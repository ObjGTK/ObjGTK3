/*
 * OGTKStyleContext.h
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

@interface OGTKStyleContext : OGTKBase
{

}

/**
 * Functions
 */
+ (void)addProviderForScreenWithScreen:(GdkScreen*)screen andProvider:(GtkStyleProvider*)provider andPriority:(guint)priority;
+ (void)removeProviderForScreenWithScreen:(GdkScreen*)screen andProvider:(GtkStyleProvider*)provider;
+ (void)resetWidgets:(GdkScreen*)screen;

/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkStyleContext*)STYLECONTEXT;

/**
 * - (void*)addClass:(OFString*)className;
 *
 * @param className
 */
- (void)addClass:(OFString*)className;

/**
 * - (void*)addProviderWithProvider:(GtkStyleProvider*)provider andPriority:(guint)priority;
 *
 * @param provider
 * @param priority
 */
- (void)addProviderWithProvider:(GtkStyleProvider*)provider andPriority:(guint)priority;

/**
 * - (void*)addRegionWithRegionName:(OFString*)regionName andFlags:(GtkRegionFlags)flags;
 *
 * @param regionName
 * @param flags
 */
- (void)addRegionWithRegionName:(OFString*)regionName andFlags:(GtkRegionFlags)flags;

/**
 * - (void*)cancelAnimations:(gpointer)regionId;
 *
 * @param regionId
 */
- (void)cancelAnimations:(gpointer)regionId;

/**
 * - (void*)getBackgroundColorWithState:(GtkStateFlags)state andColor:(GdkRGBA*)color;
 *
 * @param state
 * @param color
 */
- (void)getBackgroundColorWithState:(GtkStateFlags)state andColor:(GdkRGBA*)color;

/**
 * - (void*)getBorderWithState:(GtkStateFlags)state andBorder:(GtkBorder*)border;
 *
 * @param state
 * @param border
 */
- (void)getBorderWithState:(GtkStateFlags)state andBorder:(GtkBorder*)border;

/**
 * - (void*)getBorderColorWithState:(GtkStateFlags)state andColor:(GdkRGBA*)color;
 *
 * @param state
 * @param color
 */
- (void)getBorderColorWithState:(GtkStateFlags)state andColor:(GdkRGBA*)color;

/**
 * - (void*)getColorWithState:(GtkStateFlags)state andColor:(GdkRGBA*)color;
 *
 * @param state
 * @param color
 */
- (void)getColorWithState:(GtkStateFlags)state andColor:(GdkRGBA*)color;

/**
 * - (GtkTextDirection*)getDirection;
 *
 * @returns GtkTextDirection
 */
- (GtkTextDirection)getDirection;

/**
 * - (const PangoFontDescription**)getFont:(GtkStateFlags)state;
 *
 * @param state
 * @returns const PangoFontDescription*
 */
- (const PangoFontDescription*)getFont:(GtkStateFlags)state;

/**
 * - (GdkFrameClock**)getFrameClock;
 *
 * @returns GdkFrameClock*
 */
- (GdkFrameClock*)getFrameClock;

/**
 * - (GtkJunctionSides*)getJunctionSides;
 *
 * @returns GtkJunctionSides
 */
- (GtkJunctionSides)getJunctionSides;

/**
 * - (void*)getMarginWithState:(GtkStateFlags)state andMargin:(GtkBorder*)margin;
 *
 * @param state
 * @param margin
 */
- (void)getMarginWithState:(GtkStateFlags)state andMargin:(GtkBorder*)margin;

/**
 * - (void*)getPaddingWithState:(GtkStateFlags)state andPadding:(GtkBorder*)padding;
 *
 * @param state
 * @param padding
 */
- (void)getPaddingWithState:(GtkStateFlags)state andPadding:(GtkBorder*)padding;

/**
 * - (GtkStyleContext**)getParent;
 *
 * @returns GtkStyleContext*
 */
- (GtkStyleContext*)getParent;

/**
 * - (const GtkWidgetPath**)getPath;
 *
 * @returns const GtkWidgetPath*
 */
- (const GtkWidgetPath*)getPath;

/**
 * - (void*)getPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state andValue:(GValue*)value;
 *
 * @param property
 * @param state
 * @param value
 */
- (void)getPropertyWithProperty:(OFString*)property andState:(GtkStateFlags)state andValue:(GValue*)value;

/**
 * - (gint*)getScale;
 *
 * @returns gint
 */
- (gint)getScale;

/**
 * - (GdkScreen**)getScreen;
 *
 * @returns GdkScreen*
 */
- (GdkScreen*)getScreen;

/**
 * - (GtkCssSection**)getSection:(OFString*)property;
 *
 * @param property
 * @returns GtkCssSection*
 */
- (GtkCssSection*)getSection:(OFString*)property;

/**
 * - (GtkStateFlags*)getState;
 *
 * @returns GtkStateFlags
 */
- (GtkStateFlags)getState;

/**
 * - (void*)getStylePropertyWithPropertyName:(OFString*)propertyName andValue:(GValue*)value;
 *
 * @param propertyName
 * @param value
 */
- (void)getStylePropertyWithPropertyName:(OFString*)propertyName andValue:(GValue*)value;

/**
 * - (void*)getStyleValist:(va_list)args;
 *
 * @param args
 */
- (void)getStyleValist:(va_list)args;

/**
 * - (void*)getValistWithState:(GtkStateFlags)state andArgs:(va_list)args;
 *
 * @param state
 * @param args
 */
- (void)getValistWithState:(GtkStateFlags)state andArgs:(va_list)args;

/**
 * - (bool*)hasClass:(OFString*)className;
 *
 * @param className
 * @returns bool
 */
- (bool)hasClass:(OFString*)className;

/**
 * - (bool*)hasRegionWithRegionName:(OFString*)regionName andFlagsReturn:(GtkRegionFlags*)flagsReturn;
 *
 * @param regionName
 * @param flagsReturn
 * @returns bool
 */
- (bool)hasRegionWithRegionName:(OFString*)regionName andFlagsReturn:(GtkRegionFlags*)flagsReturn;

/**
 * - (void*)invalidate;
 *
 */
- (void)invalidate;

/**
 * - (GList**)listClasses;
 *
 * @returns GList*
 */
- (GList*)listClasses;

/**
 * - (GList**)listRegions;
 *
 * @returns GList*
 */
- (GList*)listRegions;

/**
 * - (bool*)lookupColorWithColorName:(OFString*)colorName andColor:(GdkRGBA*)color;
 *
 * @param colorName
 * @param color
 * @returns bool
 */
- (bool)lookupColorWithColorName:(OFString*)colorName andColor:(GdkRGBA*)color;

/**
 * - (GtkIconSet**)lookupIconSet:(OFString*)stockId;
 *
 * @param stockId
 * @returns GtkIconSet*
 */
- (GtkIconSet*)lookupIconSet:(OFString*)stockId;

/**
 * - (void*)notifyStateChangeWithWindow:(GdkWindow*)window andRegionId:(gpointer)regionId andState:(GtkStateType)state andStateValue:(bool)stateValue;
 *
 * @param window
 * @param regionId
 * @param state
 * @param stateValue
 */
- (void)notifyStateChangeWithWindow:(GdkWindow*)window andRegionId:(gpointer)regionId andState:(GtkStateType)state andStateValue:(bool)stateValue;

/**
 * - (void*)popAnimatableRegion;
 *
 */
- (void)popAnimatableRegion;

/**
 * - (void*)pushAnimatableRegion:(gpointer)regionId;
 *
 * @param regionId
 */
- (void)pushAnimatableRegion:(gpointer)regionId;

/**
 * - (void*)removeClass:(OFString*)className;
 *
 * @param className
 */
- (void)removeClass:(OFString*)className;

/**
 * - (void*)removeProvider:(GtkStyleProvider*)provider;
 *
 * @param provider
 */
- (void)removeProvider:(GtkStyleProvider*)provider;

/**
 * - (void*)removeRegion:(OFString*)regionName;
 *
 * @param regionName
 */
- (void)removeRegion:(OFString*)regionName;

/**
 * - (void*)restore;
 *
 */
- (void)restore;

/**
 * - (void*)save;
 *
 */
- (void)save;

/**
 * - (void*)scrollAnimationsWithWindow:(GdkWindow*)window andDx:(gint)dx andDy:(gint)dy;
 *
 * @param window
 * @param dx
 * @param dy
 */
- (void)scrollAnimationsWithWindow:(GdkWindow*)window andDx:(gint)dx andDy:(gint)dy;

/**
 * - (void*)setBackground:(GdkWindow*)window;
 *
 * @param window
 */
- (void)setBackground:(GdkWindow*)window;

/**
 * - (void*)setDirection:(GtkTextDirection)direction;
 *
 * @param direction
 */
- (void)setDirection:(GtkTextDirection)direction;

/**
 * - (void*)setFrameClock:(GdkFrameClock*)frameClock;
 *
 * @param frameClock
 */
- (void)setFrameClock:(GdkFrameClock*)frameClock;

/**
 * - (void*)setJunctionSides:(GtkJunctionSides)sides;
 *
 * @param sides
 */
- (void)setJunctionSides:(GtkJunctionSides)sides;

/**
 * - (void*)setParent:(GtkStyleContext*)parent;
 *
 * @param parent
 */
- (void)setParent:(GtkStyleContext*)parent;

/**
 * - (void*)setPath:(GtkWidgetPath*)path;
 *
 * @param path
 */
- (void)setPath:(GtkWidgetPath*)path;

/**
 * - (void*)setScale:(gint)scale;
 *
 * @param scale
 */
- (void)setScale:(gint)scale;

/**
 * - (void*)setScreen:(GdkScreen*)screen;
 *
 * @param screen
 */
- (void)setScreen:(GdkScreen*)screen;

/**
 * - (void*)setState:(GtkStateFlags)flags;
 *
 * @param flags
 */
- (void)setState:(GtkStateFlags)flags;

/**
 * - (bool*)stateIsRunningWithState:(GtkStateType)state andProgress:(gdouble*)progress;
 *
 * @param state
 * @param progress
 * @returns bool
 */
- (bool)stateIsRunningWithState:(GtkStateType)state andProgress:(gdouble*)progress;

/**
 * - (char**)toString:(GtkStyleContextPrintFlags)flags;
 *
 * @param flags
 * @returns char*
 */
- (char*)toString:(GtkStyleContextPrintFlags)flags;

@end