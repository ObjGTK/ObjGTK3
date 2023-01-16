/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellRenderer.h"

/**
 * #GtkCellRendererProgress renders a numeric value as a progress par in a cell.
 * Additionally, it can display a text on top of the progress bar.
 * 
 * The #GtkCellRendererProgress cell renderer was added in GTK+ 2.6.
 *
 */
@interface OGTKCellRendererProgress : OGTKCellRenderer
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkCellRendererProgress*)CELLRENDERERPROGRESS;

@end