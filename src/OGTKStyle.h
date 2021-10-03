/*
 * OGTKStyle.h
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

@interface OGTKStyle : OGTKBase
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkStyle*)STYLE;

/**
 * - (void*)applyDefaultBackgroundWithCr:(cairo_t*)cr andWindow:(GdkWindow*)window andStateType:(GtkStateType)stateType andX:(gint)x andY:(gint)y andWidth:(gint)width andHeight:(gint)height;
 *
 * @param cr
 * @param window
 * @param stateType
 * @param x
 * @param y
 * @param width
 * @param height
 */
- (void)applyDefaultBackgroundWithCr:(cairo_t*)cr andWindow:(GdkWindow*)window andStateType:(GtkStateType)stateType andX:(gint)x andY:(gint)y andWidth:(gint)width andHeight:(gint)height;

/**
 * - (GtkStyle**)attach:(GdkWindow*)window;
 *
 * @param window
 * @returns GtkStyle*
 */
- (GtkStyle*)attach:(GdkWindow*)window;

/**
 * - (GtkStyle**)copy;
 *
 * @returns GtkStyle*
 */
- (GtkStyle*)copy;

/**
 * - (void*)detach;
 *
 */
- (void)detach;

/**
 * - (void*)getStylePropertyWithWidgetType:(GType)widgetType andPropertyName:(OFString*)propertyName andValue:(GValue*)value;
 *
 * @param widgetType
 * @param propertyName
 * @param value
 */
- (void)getStylePropertyWithWidgetType:(GType)widgetType andPropertyName:(OFString*)propertyName andValue:(GValue*)value;

/**
 * - (void*)getValistWithWidgetType:(GType)widgetType andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs;
 *
 * @param widgetType
 * @param firstPropertyName
 * @param varArgs
 */
- (void)getValistWithWidgetType:(GType)widgetType andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs;

/**
 * - (bool*)hasContext;
 *
 * @returns bool
 */
- (bool)hasContext;

/**
 * - (bool*)lookupColorWithColorName:(OFString*)colorName andColor:(GdkColor*)color;
 *
 * @param colorName
 * @param color
 * @returns bool
 */
- (bool)lookupColorWithColorName:(OFString*)colorName andColor:(GdkColor*)color;

/**
 * - (GtkIconSet**)lookupIconSet:(OFString*)stockId;
 *
 * @param stockId
 * @returns GtkIconSet*
 */
- (GtkIconSet*)lookupIconSet:(OFString*)stockId;

/**
 * - (GdkPixbuf**)renderIconWithSource:(const GtkIconSource*)source andDirection:(GtkTextDirection)direction andState:(GtkStateType)state andSize:(GtkIconSize)size andWidget:(OGTKWidget*)widget andDetail:(OFString*)detail;
 *
 * @param source
 * @param direction
 * @param state
 * @param size
 * @param widget
 * @param detail
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)renderIconWithSource:(const GtkIconSource*)source andDirection:(GtkTextDirection)direction andState:(GtkStateType)state andSize:(GtkIconSize)size andWidget:(OGTKWidget*)widget andDetail:(OFString*)detail;

/**
 * - (void*)setBackgroundWithWindow:(GdkWindow*)window andStateType:(GtkStateType)stateType;
 *
 * @param window
 * @param stateType
 */
- (void)setBackgroundWithWindow:(GdkWindow*)window andStateType:(GtkStateType)stateType;

@end