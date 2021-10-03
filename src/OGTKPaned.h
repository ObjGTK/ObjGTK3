/*
 * OGTKPaned.h
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
#import "OGTKContainer.h"

@interface OGTKPaned : OGTKContainer
{

}


/**
 * Constructors
 */
- (id)init:(GtkOrientation)orientation;

/**
 * Methods
 */

- (GtkPaned*)PANED;

/**
 * - (void*)add1:(OGTKWidget*)child;
 *
 * @param child
 */
- (void)add1:(OGTKWidget*)child;

/**
 * - (void*)add2:(OGTKWidget*)child;
 *
 * @param child
 */
- (void)add2:(OGTKWidget*)child;

/**
 * - (OGTKWidget**)getChild1;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getChild1;

/**
 * - (OGTKWidget**)getChild2;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getChild2;

/**
 * - (GdkWindow**)getHandleWindow;
 *
 * @returns GdkWindow*
 */
- (GdkWindow*)getHandleWindow;

/**
 * - (gint*)getPosition;
 *
 * @returns gint
 */
- (gint)getPosition;

/**
 * - (bool*)getWideHandle;
 *
 * @returns bool
 */
- (bool)getWideHandle;

/**
 * - (void*)pack1WithChild:(OGTKWidget*)child andResize:(bool)resize andShrink:(bool)shrink;
 *
 * @param child
 * @param resize
 * @param shrink
 */
- (void)pack1WithChild:(OGTKWidget*)child andResize:(bool)resize andShrink:(bool)shrink;

/**
 * - (void*)pack2WithChild:(OGTKWidget*)child andResize:(bool)resize andShrink:(bool)shrink;
 *
 * @param child
 * @param resize
 * @param shrink
 */
- (void)pack2WithChild:(OGTKWidget*)child andResize:(bool)resize andShrink:(bool)shrink;

/**
 * - (void*)setPosition:(gint)position;
 *
 * @param position
 */
- (void)setPosition:(gint)position;

/**
 * - (void*)setWideHandle:(bool)wide;
 *
 * @param wide
 */
- (void)setWideHandle:(bool)wide;

@end