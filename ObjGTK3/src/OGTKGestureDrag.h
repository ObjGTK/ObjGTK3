/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureSingle.h"

@class OGTKWidget;
@class OGTKGesture;

/**
 * #GtkGestureDrag is a #GtkGesture implementation that recognizes drag
 * operations. The drag operation itself can be tracked throught the
 * #GtkGestureDrag::drag-begin, #GtkGestureDrag::drag-update and
 * #GtkGestureDrag::drag-end signals, or the relevant coordinates be
 * extracted through gtk_gesture_drag_get_offset() and
 * gtk_gesture_drag_get_start_point().
 *
 */
@interface OGTKGestureDrag : OGTKGestureSingle
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKWidget*)widget;

/**
 * Methods
 */

- (GtkGestureDrag*)GESTUREDRAG;

/**
 * If the @gesture is active, this function returns %TRUE and
 * fills in @x and @y with the coordinates of the current point,
 * as an offset to the starting drag point.
 *
 * @param x X offset for the current point
 * @param y Y offset for the current point
 * @return %TRUE if the gesture is active
 */
- (bool)offsetWithX:(gdouble*)x y:(gdouble*)y;

/**
 * If the @gesture is active, this function returns %TRUE
 * and fills in @x and @y with the drag start coordinates,
 * in window-relative coordinates.
 *
 * @param x X coordinate for the drag start point
 * @param y Y coordinate for the drag start point
 * @return %TRUE if the gesture is active
 */
- (bool)startPointWithX:(gdouble*)x y:(gdouble*)y;

@end