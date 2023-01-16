/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

@class OGTKWidget;

/**
 * A #GtkVBox is a container that organizes child widgets into a single column.
 * 
 * Use the #GtkBox packing interface to determine the arrangement,
 * spacing, height, and alignment of #GtkVBox children.
 * 
 * All children are allocated the same width.
 * 
 * GtkVBox has been deprecated. You can use #GtkBox with a #GtkOrientable:orientation
 * set to %GTK_ORIENTATION_VERTICAL instead when calling gtk_box_new(),
 * which is a very quick and easy change.
 * 
 * If you have derived your own classes from GtkVBox, you can change the
 * inheritance to derive directly from #GtkBox, and set the #GtkOrientable:orientation
 * property to %GTK_ORIENTATION_VERTICAL in your instance init function,
 * with a call like:
 * 
 * |[<!-- language="C" -->
 *   gtk_orientable_set_orientation (GTK_ORIENTABLE (object),
 *                                   GTK_ORIENTATION_VERTICAL);
 * ]|
 * 
 * If you have a grid-like layout composed of nested boxes, and you don’t
 * need first-child or last-child styling, the recommendation is to switch
 * to #GtkGrid. For more information about migrating to #GtkGrid, see
 * [Migrating from other containers to GtkGrid][gtk-migrating-GtkGrid].
 *
 */
@interface OGTKVBox : OGTKBox
{

}


/**
 * Constructors
 */
- (instancetype)initWithHomogeneous:(bool)homogeneous spacing:(gint)spacing;

/**
 * Methods
 */

- (GtkVBox*)VBOX;

@end