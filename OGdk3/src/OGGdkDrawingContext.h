/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkWindow;

/**
 * #GdkDrawingContext is an object that represents the current drawing
 * state of a #GdkWindow.
 * 
 * It's possible to use a #GdkDrawingContext to draw on a #GdkWindow
 * via rendering API like Cairo or OpenGL.
 * 
 * A #GdkDrawingContext can only be created by calling gdk_window_begin_draw_frame()
 * and will be valid until a call to gdk_window_end_draw_frame().
 * 
 * #GdkDrawingContext is available since GDK 3.22
 *
 */
@interface OGGdkDrawingContext : OGObject
{

}


/**
 * Methods
 */

- (GdkDrawingContext*)DRAWINGCONTEXT;

/**
 * Retrieves a Cairo context to be used to draw on the #GdkWindow
 * that created the #GdkDrawingContext.
 * 
 * The returned context is guaranteed to be valid as long as the
 * #GdkDrawingContext is valid, that is between a call to
 * gdk_window_begin_draw_frame() and gdk_window_end_draw_frame().
 *
 * @return a Cairo context to be used to draw
 *   the contents of the #GdkWindow. The context is owned by the
 *   #GdkDrawingContext and should not be destroyed
 */
- (cairo_t*)cairoContext;

/**
 * Retrieves a copy of the clip region used when creating the @context.
 *
 * @return a Cairo region
 */
- (cairo_region_t*)clip;

/**
 * Retrieves the window that created the drawing @context.
 *
 * @return a #GdkWindow
 */
- (OGGdkWindow*)window;

/**
 * Checks whether the given #GdkDrawingContext is valid.
 *
 * @return %TRUE if the context is valid
 */
- (bool)isValid;

@end