/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGesture.h"

@class OGTKWidget;

/**
 * #GtkGestureZoom is a #GtkGesture implementation able to recognize
 * pinch/zoom gestures, whenever the distance between both tracked
 * sequences changes, the #GtkGestureZoom::scale-changed signal is
 * emitted to report the scale factor.
 *
 */
@interface OGTKGestureZoom : OGTKGesture
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKWidget*)widget;

/**
 * Methods
 */

- (GtkGestureZoom*)GESTUREZOOM;

/**
 * If @gesture is active, this function returns the zooming difference
 * since the gesture was recognized (hence the starting point is
 * considered 1:1). If @gesture is not active, 1 is returned.
 *
 * @return the scale delta
 */
- (gdouble)scaleDelta;

@end