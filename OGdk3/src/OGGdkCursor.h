/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gdk/gdk.h>

#import <OGObject/OGObject.h>

@class OGGdkPixbuf;
@class OGGdkDisplay;

/**
 * A #GdkCursor represents a cursor. Its contents are private.
 *
 */
@interface OGGdkCursor : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init:(GdkCursorType)cursorType;
- (instancetype)initForDisplayWithDisplay:(OGGdkDisplay*)display cursorType:(GdkCursorType)cursorType;
- (instancetype)initFromNameWithDisplay:(OGGdkDisplay*)display name:(OFString*)name;
- (instancetype)initFromPixbufWithDisplay:(OGGdkDisplay*)display pixbuf:(OGGdkPixbuf*)pixbuf x:(gint)x y:(gint)y;
- (instancetype)initFromSurfaceWithDisplay:(OGGdkDisplay*)display surface:(cairo_surface_t*)surface x:(gdouble)x y:(gdouble)y;

/**
 * Methods
 */

- (GdkCursor*)CURSOR;

/**
 * Returns the cursor type for this cursor.
 *
 * @return a #GdkCursorType
 */
- (GdkCursorType)cursorType;

/**
 * Returns the display on which the #GdkCursor is defined.
 *
 * @return the #GdkDisplay associated to @cursor
 */
- (OGGdkDisplay*)display;

/**
 * Returns a #GdkPixbuf with the image used to display the cursor.
 * 
 * Note that depending on the capabilities of the windowing system and
 * on the cursor, GDK may not be able to obtain the image data. In this
 * case, %NULL is returned.
 *
 * @return a #GdkPixbuf representing
 *   @cursor, or %NULL
 */
- (OGGdkPixbuf*)image;

/**
 * Returns a cairo image surface with the image used to display the cursor.
 * 
 * Note that depending on the capabilities of the windowing system and
 * on the cursor, GDK may not be able to obtain the image data. In this
 * case, %NULL is returned.
 *
 * @param xhot Location to store the hotspot x position,
 *   or %NULL
 * @param yhot Location to store the hotspot y position,
 *   or %NULL
 * @return a #cairo_surface_t
 *   representing @cursor, or %NULL
 */
- (cairo_surface_t*)surfaceWithXhot:(gdouble*)xhot yhot:(gdouble*)yhot;

@end