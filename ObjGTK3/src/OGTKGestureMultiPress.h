/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureSingle.h"

@class OGTKWidget;
@class OGTKGesture;

/**
 * #GtkGestureMultiPress is a #GtkGesture implementation able to recognize
 * multiple clicks on a nearby zone, which can be listened for through the
 * #GtkGestureMultiPress::pressed signal. Whenever time or distance between
 * clicks exceed the GTK+ defaults, #GtkGestureMultiPress::stopped is emitted,
 * and the click counter is reset.
 * 
 * Callers may also restrict the area that is considered valid for a >1
 * touch/button press through gtk_gesture_multi_press_set_area(), so any
 * click happening outside that area is considered to be a first click of
 * its own.
 *
 */
@interface OGTKGestureMultiPress : OGTKGestureSingle
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKWidget*)widget;

/**
 * Methods
 */

- (GtkGestureMultiPress*)GESTUREMULTIPRESS;

/**
 * If an area was set through gtk_gesture_multi_press_set_area(),
 * this function will return %TRUE and fill in @rect with the
 * press area. See gtk_gesture_multi_press_set_area() for more
 * details on what the press area represents.
 *
 * @param rect return location for the press area
 * @return %TRUE if @rect was filled with the press area
 */
- (bool)area:(GdkRectangle*)rect;

/**
 * If @rect is non-%NULL, the press area will be checked to be
 * confined within the rectangle, otherwise the button count
 * will be reset so the press is seen as being the first one.
 * If @rect is %NULL, the area will be reset to an unrestricted
 * state.
 * 
 * Note: The rectangle is only used to determine whether any
 * non-first click falls within the expected area. This is not
 * akin to an input shape.
 *
 * @param rect rectangle to receive coordinates on
 */
- (void)setArea:(const GdkRectangle*)rect;

@end