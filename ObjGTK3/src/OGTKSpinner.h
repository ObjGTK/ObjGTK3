/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKWidget.h"

/**
 * A GtkSpinner widget displays an icon-size spinning animation.
 * It is often used as an alternative to a #GtkProgressBar for
 * displaying indefinite activity, instead of actual progress.
 * 
 * To start the animation, use gtk_spinner_start(), to stop it
 * use gtk_spinner_stop().
 * 
 * # CSS nodes
 * 
 * GtkSpinner has a single CSS node with the name spinner. When the animation is
 * active, the :checked pseudoclass is added to this node.
 *
 */
@interface OGTKSpinner : OGTKWidget
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkSpinner*)SPINNER;

/**
 * Starts the animation of the spinner.
 *
 */
- (void)start;

/**
 * Stops the animation of the spinner.
 *
 */
- (void)stop;

@end