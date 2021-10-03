/*
 * OGTKGesture.h
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
#import "EventController.h"

@interface OGTKGesture : EventController
{

}


/**
 * Methods
 */

- (GtkGesture*)GESTURE;

/**
 * - (bool*)getBoundingBox:(GdkRectangle*)rect;
 *
 * @param rect
 * @returns bool
 */
- (bool)getBoundingBox:(GdkRectangle*)rect;

/**
 * - (bool*)getBoundingBoxCenterWithX:(gdouble*)x andY:(gdouble*)y;
 *
 * @param x
 * @param y
 * @returns bool
 */
- (bool)getBoundingBoxCenterWithX:(gdouble*)x andY:(gdouble*)y;

/**
 * - (GdkDevice**)getDevice;
 *
 * @returns GdkDevice*
 */
- (GdkDevice*)getDevice;

/**
 * - (GList**)getGroup;
 *
 * @returns GList*
 */
- (GList*)getGroup;

/**
 * - (const GdkEvent**)getLastEvent:(GdkEventSequence*)sequence;
 *
 * @param sequence
 * @returns const GdkEvent*
 */
- (const GdkEvent*)getLastEvent:(GdkEventSequence*)sequence;

/**
 * - (GdkEventSequence**)getLastUpdatedSequence;
 *
 * @returns GdkEventSequence*
 */
- (GdkEventSequence*)getLastUpdatedSequence;

/**
 * - (bool*)getPointWithSequence:(GdkEventSequence*)sequence andX:(gdouble*)x andY:(gdouble*)y;
 *
 * @param sequence
 * @param x
 * @param y
 * @returns bool
 */
- (bool)getPointWithSequence:(GdkEventSequence*)sequence andX:(gdouble*)x andY:(gdouble*)y;

/**
 * - (GtkEventSequenceState*)getSequenceState:(GdkEventSequence*)sequence;
 *
 * @param sequence
 * @returns GtkEventSequenceState
 */
- (GtkEventSequenceState)getSequenceState:(GdkEventSequence*)sequence;

/**
 * - (GList**)getSequences;
 *
 * @returns GList*
 */
- (GList*)getSequences;

/**
 * - (GdkWindow**)getWindow;
 *
 * @returns GdkWindow*
 */
- (GdkWindow*)getWindow;

/**
 * - (void*)group:(GtkGesture*)gesture;
 *
 * @param gesture
 */
- (void)group:(GtkGesture*)gesture;

/**
 * - (bool*)handlesSequence:(GdkEventSequence*)sequence;
 *
 * @param sequence
 * @returns bool
 */
- (bool)handlesSequence:(GdkEventSequence*)sequence;

/**
 * - (bool*)isActive;
 *
 * @returns bool
 */
- (bool)isActive;

/**
 * - (bool*)isGroupedWith:(GtkGesture*)other;
 *
 * @param other
 * @returns bool
 */
- (bool)isGroupedWith:(GtkGesture*)other;

/**
 * - (bool*)isRecognized;
 *
 * @returns bool
 */
- (bool)isRecognized;

/**
 * - (bool*)setSequenceStateWithSequence:(GdkEventSequence*)sequence andState:(GtkEventSequenceState)state;
 *
 * @param sequence
 * @param state
 * @returns bool
 */
- (bool)setSequenceStateWithSequence:(GdkEventSequence*)sequence andState:(GtkEventSequenceState)state;

/**
 * - (bool*)setState:(GtkEventSequenceState)state;
 *
 * @param state
 * @returns bool
 */
- (bool)setState:(GtkEventSequenceState)state;

/**
 * - (void*)setWindow:(GdkWindow*)window;
 *
 * @param window
 */
- (void)setWindow:(GdkWindow*)window;

/**
 * - (void*)ungroup;
 *
 */
- (void)ungroup;

@end