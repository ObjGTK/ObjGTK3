/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <gtk/gtkx.h>
#include <gtk/gtk.h>
#include <gtk/gtk-a11y.h>

#import <OGdk3/OGGdkWindow.h>

@class OGGdkPixbuf;
@class OGTKWidget;

/**
 * GtkOffscreenWindow is strictly intended to be used for obtaining
 * snapshots of widgets that are not part of a normal widget hierarchy.
 * Since #GtkOffscreenWindow is a toplevel widget you cannot obtain
 * snapshots of a full window with it since you cannot pack a toplevel
 * widget in another toplevel.
 * 
 * The idea is to take a widget and manually set the state of it,
 * add it to a GtkOffscreenWindow and then retrieve the snapshot
 * as a #cairo_surface_t or #GdkPixbuf.
 * 
 * GtkOffscreenWindow derives from #GtkWindow only as an implementation
 * detail.  Applications should not use any API specific to #GtkWindow
 * to operate on this object.  It should be treated as a #GtkBin that
 * has no parent widget.
 * 
 * When contained offscreen widgets are redrawn, GtkOffscreenWindow
 * will emit a #GtkWidget::damage-event signal.
 *
 */
@interface OGTKOffscreenWindow : OGGdkWindow
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkOffscreenWindow*)OFFSCREENWINDOW;

/**
 * Retrieves a snapshot of the contained widget in the form of
 * a #GdkPixbuf.  This is a new pixbuf with a reference count of 1,
 * and the application should unreference it once it is no longer
 * needed.
 *
 * @return A #GdkPixbuf pointer, or %NULL.
 */
- (OGGdkPixbuf*)pixbuf;

/**
 * Retrieves a snapshot of the contained widget in the form of
 * a #cairo_surface_t.  If you need to keep this around over window
 * resizes then you should add a reference to it.
 *
 * @return A #cairo_surface_t pointer to the offscreen
 *     surface, or %NULL.
 */
- (cairo_surface_t*)surface;

@end