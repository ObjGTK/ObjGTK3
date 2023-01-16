/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

@class OGGdkScreen;
@class OGTKWindow;

/**
 * This should not be accessed directly. Use the accessor functions below.
 *
 */
@interface OGTKMountOperation : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init:(OGTKWindow*)parent;

/**
 * Methods
 */

- (GtkMountOperation*)MOUNTOPERATION;

/**
 * Gets the transient parent used by the #GtkMountOperation
 *
 * @return the transient parent for windows shown by @op
 */
- (OGTKWindow*)parent;

/**
 * Gets the screen on which windows of the #GtkMountOperation
 * will be shown.
 *
 * @return the screen on which windows of @op are shown
 */
- (OGGdkScreen*)screen;

/**
 * Returns whether the #GtkMountOperation is currently displaying
 * a window.
 *
 * @return %TRUE if @op is currently displaying a window
 */
- (bool)isShowing;

/**
 * Sets the transient parent for windows shown by the
 * #GtkMountOperation.
 *
 * @param parent transient parent of the window, or %NULL
 */
- (void)setParent:(OGTKWindow*)parent;

/**
 * Sets the screen to show windows of the #GtkMountOperation on.
 *
 * @param screen a #GdkScreen
 */
- (void)setScreen:(OGGdkScreen*)screen;

@end