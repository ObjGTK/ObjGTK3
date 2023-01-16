/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKGestureSingle.h"

@class OGTKWidget;
@class OGTKGesture;

/**
 * #GtkGestureLongPress is a #GtkGesture implementation able to recognize
 * long presses, triggering the #GtkGestureLongPress::pressed after the
 * timeout is exceeded.
 * 
 * If the touchpoint is lifted before the timeout passes, or if it drifts
 * too far of the initial press point, the #GtkGestureLongPress::cancelled
 * signal will be emitted.
 *
 */
@interface OGTKGestureLongPress : OGTKGestureSingle
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKWidget*)widget;

/**
 * Methods
 */

- (GtkGestureLongPress*)GESTURELONGPRESS;

@end