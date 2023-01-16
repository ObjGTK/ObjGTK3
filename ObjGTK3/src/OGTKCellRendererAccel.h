/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellRendererText.h"

@class OGTKCellRenderer;

/**
 * #GtkCellRendererAccel displays a keyboard accelerator (i.e. a key
 * combination like `Control + a`). If the cell renderer is editable,
 * the accelerator can be changed by simply typing the new combination.
 * 
 * The #GtkCellRendererAccel cell renderer was added in GTK+ 2.10.
 *
 */
@interface OGTKCellRendererAccel : OGTKCellRendererText
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkCellRendererAccel*)CELLRENDERERACCEL;

@end