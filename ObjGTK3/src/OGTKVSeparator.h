/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSeparator.h"

@class OGTKWidget;

/**
 * The #GtkVSeparator widget is a vertical separator, used to group the
 * widgets within a window. It displays a vertical line with a shadow to
 * make it appear sunken into the interface.
 * 
 * GtkVSeparator has been deprecated, use #GtkSeparator instead.
 *
 */
@interface OGTKVSeparator : OGTKSeparator
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkVSeparator*)VSEPARATOR;

@end