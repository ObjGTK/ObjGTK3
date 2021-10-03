/*
 * OGTKGestureSingle.h
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
#import "Gesture.h"

@interface OGTKGestureSingle : Gesture
{

}


/**
 * Methods
 */

- (GtkGestureSingle*)GESTURESINGLE;

/**
 * - (guint*)getButton;
 *
 * @returns guint
 */
- (guint)getButton;

/**
 * - (guint*)getCurrentButton;
 *
 * @returns guint
 */
- (guint)getCurrentButton;

/**
 * - (GdkEventSequence**)getCurrentSequence;
 *
 * @returns GdkEventSequence*
 */
- (GdkEventSequence*)getCurrentSequence;

/**
 * - (bool*)getExclusive;
 *
 * @returns bool
 */
- (bool)getExclusive;

/**
 * - (bool*)getTouchOnly;
 *
 * @returns bool
 */
- (bool)getTouchOnly;

/**
 * - (void*)setButton:(guint)button;
 *
 * @param button
 */
- (void)setButton:(guint)button;

/**
 * - (void*)setExclusive:(bool)exclusive;
 *
 * @param exclusive
 */
- (void)setExclusive:(bool)exclusive;

/**
 * - (void*)setTouchOnly:(bool)touchOnly;
 *
 * @param touchOnly
 */
- (void)setTouchOnly:(bool)touchOnly;

@end