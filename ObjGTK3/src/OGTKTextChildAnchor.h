/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>
#include <gtk/gtkx.h>

#import <OGObject/OGObject.h>

/**
 * A #GtkTextChildAnchor is a spot in the buffer where child widgets can
 * be “anchored” (inserted inline, as if they were characters). The anchor
 * can have multiple widgets anchored, to allow for multiple views.
 *
 */
@interface OGTKTextChildAnchor : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkTextChildAnchor*)TEXTCHILDANCHOR;

/**
 * Determines whether a child anchor has been deleted from
 * the buffer. Keep in mind that the child anchor will be
 * unreferenced when removed from the buffer, so you need to
 * hold your own reference (with g_object_ref()) if you plan
 * to use this function — otherwise all deleted child anchors
 * will also be finalized.
 *
 * @return %TRUE if the child anchor has been deleted from its buffer
 */
- (bool)deleted;

/**
 * Gets a list of all widgets anchored at this child anchor.
 * The returned list should be freed with g_list_free().
 *
 * @return list of widgets anchored at @anchor
 */
- (GList*)widgets;

@end