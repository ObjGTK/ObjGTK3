/*
 * OGTKContainer.h
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
#import "OGTKWidget.h"

@interface OGTKContainer : OGTKWidget
{

}


/**
 * Methods
 */

- (GtkContainer*)CONTAINER;

- (void)addWidget:(OGTKWidget*)widget withProperties:(OFDictionary*)properties;

/**
 * - (void*)add:(OGTKWidget*)widget;
 *
 * @param widget
 */
- (void)add:(OGTKWidget*)widget;

/**
 * - (void*)checkResize;
 *
 */
- (void)checkResize;

/**
 * - (void*)childGetPropertyWithChild:(OGTKWidget*)child andPropertyName:(OFString*)propertyName andValue:(GValue*)value;
 *
 * @param child
 * @param propertyName
 * @param value
 */
- (void)childGetPropertyWithChild:(OGTKWidget*)child andPropertyName:(OFString*)propertyName andValue:(GValue*)value;

/**
 * - (void*)childGetValistWithChild:(OGTKWidget*)child andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs;
 *
 * @param child
 * @param firstPropertyName
 * @param varArgs
 */
- (void)childGetValistWithChild:(OGTKWidget*)child andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs;

/**
 * - (void*)childNotifyWithChild:(OGTKWidget*)child andChildProperty:(OFString*)childProperty;
 *
 * @param child
 * @param childProperty
 */
- (void)childNotifyWithChild:(OGTKWidget*)child andChildProperty:(OFString*)childProperty;

/**
 * - (void*)childNotifyByPspecWithChild:(OGTKWidget*)child andPspec:(GParamSpec*)pspec;
 *
 * @param child
 * @param pspec
 */
- (void)childNotifyByPspecWithChild:(OGTKWidget*)child andPspec:(GParamSpec*)pspec;

/**
 * - (void*)childSetPropertyWithChild:(OGTKWidget*)child andPropertyName:(OFString*)propertyName andValue:(const GValue*)value;
 *
 * @param child
 * @param propertyName
 * @param value
 */
- (void)childSetPropertyWithChild:(OGTKWidget*)child andPropertyName:(OFString*)propertyName andValue:(const GValue*)value;

/**
 * - (void*)childSetValistWithChild:(OGTKWidget*)child andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs;
 *
 * @param child
 * @param firstPropertyName
 * @param varArgs
 */
- (void)childSetValistWithChild:(OGTKWidget*)child andFirstPropertyName:(OFString*)firstPropertyName andVarArgs:(va_list)varArgs;

/**
 * - (GType*)childType;
 *
 * @returns GType
 */
- (GType)childType;

/**
 * - (void*)forallWithCallback:(GtkCallback)callback andCallbackData:(gpointer)callbackData;
 *
 * @param callback
 * @param callbackData
 */
- (void)forallWithCallback:(GtkCallback)callback andCallbackData:(gpointer)callbackData;

/**
 * - (void*)foreachWithCallback:(GtkCallback)callback andCallbackData:(gpointer)callbackData;
 *
 * @param callback
 * @param callbackData
 */
- (void)foreachWithCallback:(GtkCallback)callback andCallbackData:(gpointer)callbackData;

/**
 * - (guint*)getBorderWidth;
 *
 * @returns guint
 */
- (guint)getBorderWidth;

/**
 * - (GList**)getChildren;
 *
 * @returns GList*
 */
- (GList*)getChildren;

/**
 * - (bool*)getFocusChain:(GList**)focusableWidgets;
 *
 * @param focusableWidgets
 * @returns bool
 */
- (bool)getFocusChain:(GList**)focusableWidgets;

/**
 * - (OGTKWidget**)getFocusChild;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getFocusChild;

/**
 * - (GtkAdjustment**)getFocusHadjustment;
 *
 * @returns GtkAdjustment*
 */
- (GtkAdjustment*)getFocusHadjustment;

/**
 * - (GtkAdjustment**)getFocusVadjustment;
 *
 * @returns GtkAdjustment*
 */
- (GtkAdjustment*)getFocusVadjustment;

/**
 * - (GtkWidgetPath**)getPathForChild:(OGTKWidget*)child;
 *
 * @param child
 * @returns GtkWidgetPath*
 */
- (GtkWidgetPath*)getPathForChild:(OGTKWidget*)child;

/**
 * - (GtkResizeMode*)getResizeMode;
 *
 * @returns GtkResizeMode
 */
- (GtkResizeMode)getResizeMode;

/**
 * - (void*)propagateDrawWithChild:(OGTKWidget*)child andCr:(cairo_t*)cr;
 *
 * @param child
 * @param cr
 */
- (void)propagateDrawWithChild:(OGTKWidget*)child andCr:(cairo_t*)cr;

/**
 * - (void*)remove:(OGTKWidget*)widget;
 *
 * @param widget
 */
- (void)remove:(OGTKWidget*)widget;

/**
 * - (void*)resizeChildren;
 *
 */
- (void)resizeChildren;

/**
 * - (void*)setBorderWidth:(guint)borderWidth;
 *
 * @param borderWidth
 */
- (void)setBorderWidth:(guint)borderWidth;

/**
 * - (void*)setFocusChain:(GList*)focusableWidgets;
 *
 * @param focusableWidgets
 */
- (void)setFocusChain:(GList*)focusableWidgets;

/**
 * - (void*)setFocusChild:(OGTKWidget*)child;
 *
 * @param child
 */
- (void)setFocusChild:(OGTKWidget*)child;

/**
 * - (void*)setFocusHadjustment:(GtkAdjustment*)adjustment;
 *
 * @param adjustment
 */
- (void)setFocusHadjustment:(GtkAdjustment*)adjustment;

/**
 * - (void*)setFocusVadjustment:(GtkAdjustment*)adjustment;
 *
 * @param adjustment
 */
- (void)setFocusVadjustment:(GtkAdjustment*)adjustment;

/**
 * - (void*)setReallocateRedraws:(bool)needsRedraws;
 *
 * @param needsRedraws
 */
- (void)setReallocateRedraws:(bool)needsRedraws;

/**
 * - (void*)setResizeMode:(GtkResizeMode)resizeMode;
 *
 * @param resizeMode
 */
- (void)setResizeMode:(GtkResizeMode)resizeMode;

/**
 * - (void*)unsetFocusChain;
 *
 */
- (void)unsetFocusChain;

@end