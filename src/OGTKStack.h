/*
 * OGTKStack.h
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

@interface OGTKStack : OGTKContainer
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkStack*)STACK;

/**
 * - (void*)addNamedWithChild:(OGTKWidget*)child andName:(OFString*)name;
 *
 * @param child
 * @param name
 */
- (void)addNamedWithChild:(OGTKWidget*)child andName:(OFString*)name;

/**
 * - (void*)addTitledWithChild:(OGTKWidget*)child andName:(OFString*)name andTitle:(OFString*)title;
 *
 * @param child
 * @param name
 * @param title
 */
- (void)addTitledWithChild:(OGTKWidget*)child andName:(OFString*)name andTitle:(OFString*)title;

/**
 * - (OGTKWidget**)getChildByName:(OFString*)name;
 *
 * @param name
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getChildByName:(OFString*)name;

/**
 * - (bool*)getHhomogeneous;
 *
 * @returns bool
 */
- (bool)getHhomogeneous;

/**
 * - (bool*)getHomogeneous;
 *
 * @returns bool
 */
- (bool)getHomogeneous;

/**
 * - (bool*)getInterpolateSize;
 *
 * @returns bool
 */
- (bool)getInterpolateSize;

/**
 * - (guint*)getTransitionDuration;
 *
 * @returns guint
 */
- (guint)getTransitionDuration;

/**
 * - (bool*)getTransitionRunning;
 *
 * @returns bool
 */
- (bool)getTransitionRunning;

/**
 * - (GtkStackTransitionType*)getTransitionType;
 *
 * @returns GtkStackTransitionType
 */
- (GtkStackTransitionType)getTransitionType;

/**
 * - (bool*)getVhomogeneous;
 *
 * @returns bool
 */
- (bool)getVhomogeneous;

/**
 * - (OGTKWidget**)getVisibleChild;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getVisibleChild;

/**
 * - (OFString**)getVisibleChildName;
 *
 * @returns OFString*
 */
- (OFString*)getVisibleChildName;

/**
 * - (void*)setHhomogeneous:(bool)hhomogeneous;
 *
 * @param hhomogeneous
 */
- (void)setHhomogeneous:(bool)hhomogeneous;

/**
 * - (void*)setHomogeneous:(bool)homogeneous;
 *
 * @param homogeneous
 */
- (void)setHomogeneous:(bool)homogeneous;

/**
 * - (void*)setInterpolateSize:(bool)interpolateSize;
 *
 * @param interpolateSize
 */
- (void)setInterpolateSize:(bool)interpolateSize;

/**
 * - (void*)setTransitionDuration:(guint)duration;
 *
 * @param duration
 */
- (void)setTransitionDuration:(guint)duration;

/**
 * - (void*)setTransitionType:(GtkStackTransitionType)transition;
 *
 * @param transition
 */
- (void)setTransitionType:(GtkStackTransitionType)transition;

/**
 * - (void*)setVhomogeneous:(bool)vhomogeneous;
 *
 * @param vhomogeneous
 */
- (void)setVhomogeneous:(bool)vhomogeneous;

/**
 * - (void*)setVisibleChild:(OGTKWidget*)child;
 *
 * @param child
 */
- (void)setVisibleChild:(OGTKWidget*)child;

/**
 * - (void*)setVisibleChildFullWithName:(OFString*)name andTransition:(GtkStackTransitionType)transition;
 *
 * @param name
 * @param transition
 */
- (void)setVisibleChildFullWithName:(OFString*)name andTransition:(GtkStackTransitionType)transition;

/**
 * - (void*)setVisibleChildName:(OFString*)name;
 *
 * @param name
 */
- (void)setVisibleChildName:(OFString*)name;

@end