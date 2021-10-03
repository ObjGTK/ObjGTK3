/*
 * OGTKPopover.h
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

@interface OGTKPopover : OGTKBin
{

}


/**
 * Constructors
 */
- (id)init:(OGTKWidget*)relativeTo;
- (id)initFromModelWithRelativeTo:(OGTKWidget*)relativeTo andModel:(GMenuModel*)model;

/**
 * Methods
 */

- (GtkPopover*)POPOVER;

/**
 * - (void*)bindModelWithModel:(GMenuModel*)model andActionNamespace:(OFString*)actionNamespace;
 *
 * @param model
 * @param actionNamespace
 */
- (void)bindModelWithModel:(GMenuModel*)model andActionNamespace:(OFString*)actionNamespace;

/**
 * - (GtkPopoverConstraint*)getConstrainTo;
 *
 * @returns GtkPopoverConstraint
 */
- (GtkPopoverConstraint)getConstrainTo;

/**
 * - (OGTKWidget**)getDefaultWidget;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getDefaultWidget;

/**
 * - (bool*)getModal;
 *
 * @returns bool
 */
- (bool)getModal;

/**
 * - (bool*)getPointingTo:(GdkRectangle*)rect;
 *
 * @param rect
 * @returns bool
 */
- (bool)getPointingTo:(GdkRectangle*)rect;

/**
 * - (GtkPositionType*)getPosition;
 *
 * @returns GtkPositionType
 */
- (GtkPositionType)getPosition;

/**
 * - (OGTKWidget**)getRelativeTo;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getRelativeTo;

/**
 * - (bool*)getTransitionsEnabled;
 *
 * @returns bool
 */
- (bool)getTransitionsEnabled;

/**
 * - (void*)popdown;
 *
 */
- (void)popdown;

/**
 * - (void*)popup;
 *
 */
- (void)popup;

/**
 * - (void*)setConstrainTo:(GtkPopoverConstraint)constraint;
 *
 * @param constraint
 */
- (void)setConstrainTo:(GtkPopoverConstraint)constraint;

/**
 * - (void*)setDefaultWidget:(OGTKWidget*)widget;
 *
 * @param widget
 */
- (void)setDefaultWidget:(OGTKWidget*)widget;

/**
 * - (void*)setModal:(bool)modal;
 *
 * @param modal
 */
- (void)setModal:(bool)modal;

/**
 * - (void*)setPointingTo:(const GdkRectangle*)rect;
 *
 * @param rect
 */
- (void)setPointingTo:(const GdkRectangle*)rect;

/**
 * - (void*)setPosition:(GtkPositionType)position;
 *
 * @param position
 */
- (void)setPosition:(GtkPositionType)position;

/**
 * - (void*)setRelativeTo:(OGTKWidget*)relativeTo;
 *
 * @param relativeTo
 */
- (void)setRelativeTo:(OGTKWidget*)relativeTo;

/**
 * - (void*)setTransitionsEnabled:(bool)transitionsEnabled;
 *
 * @param transitionsEnabled
 */
- (void)setTransitionsEnabled:(bool)transitionsEnabled;

@end