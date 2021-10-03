/*
 * OGTKThemingEngine.h
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

@interface OGTKThemingEngine : OGTKBase
{

}

/**
 * Functions
 */
+ (GtkThemingEngine*)load:(OFString*)name;
+ (void)registerPropertyWithNameSpace:(OFString*)nameSpace andParseFunc:(GtkStylePropertyParser)parseFunc andPspec:(GParamSpec*)pspec;

/**
 * Methods
 */

- (GtkThemingEngine*)THEMINGENGINE;

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
 * - (GdkScreen**)getScreen;
 *
 * @returns GdkScreen*
 */
- (GdkScreen*)getScreen;

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
 * - (bool*)hasClass:(OFString*)styleClass;
 *
 * @param styleClass
 * @returns bool
 */
- (bool)hasClass:(OFString*)styleClass;

/**
 * - (bool*)hasRegionWithStyleRegion:(OFString*)styleRegion andFlags:(GtkRegionFlags*)flags;
 *
 * @param styleRegion
 * @param flags
 * @returns bool
 */
- (bool)hasRegionWithStyleRegion:(OFString*)styleRegion andFlags:(GtkRegionFlags*)flags;

/**
 * - (bool*)lookupColorWithColorName:(OFString*)colorName andColor:(GdkRGBA*)color;
 *
 * @param colorName
 * @param color
 * @returns bool
 */
- (bool)lookupColorWithColorName:(OFString*)colorName andColor:(GdkRGBA*)color;

/**
 * - (bool*)stateIsRunningWithState:(GtkStateType)state andProgress:(gdouble*)progress;
 *
 * @param state
 * @param progress
 * @returns bool
 */
- (bool)stateIsRunningWithState:(GtkStateType)state andProgress:(gdouble*)progress;

@end