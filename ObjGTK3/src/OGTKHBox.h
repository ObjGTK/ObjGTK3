/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKBox.h"

@class OGTKWidget;

/**
 * #GtkHBox is a container that organizes child widgets into a single row.
 * 
 * Use the #GtkBox packing interface to determine the arrangement,
 * spacing, width, and alignment of #GtkHBox children.
 * 
 * All children are allocated the same height.
 * 
 * GtkHBox has been deprecated. You can use #GtkBox instead, which is a
 * very quick and easy change. If you have derived your own classes from
 * GtkHBox, you can simply change the inheritance to derive directly
 * from #GtkBox. No further changes are needed, since the default
 * value of the #GtkOrientable:orientation property is
 * %GTK_ORIENTATION_HORIZONTAL.
 * 
 * If you have a grid-like layout composed of nested boxes, and you don’t
 * need first-child or last-child styling, the recommendation is to switch
 * to #GtkGrid. For more information about migrating to #GtkGrid, see
 * [Migrating from other containers to GtkGrid][gtk-migrating-GtkGrid].
 *
 */
@interface OGTKHBox : OGTKBox
{

}


/**
 * Constructors
 */
- (instancetype)initWithHomogeneous:(bool)homogeneous spacing:(gint)spacing;

/**
 * Methods
 */

- (GtkHBox*)HBOX;

@end