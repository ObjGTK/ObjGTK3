/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <atk/atk.h>

#import <OGObject/OGObject.h>

/**
 * A set of utility functions for thread locking. This interface and
 * all his related methods are deprecated since 2.12.
 *
 */
@interface OGAtkMisc : OGObject
{

}

/**
 * Functions
 */
+ (const AtkMisc*)instance;

/**
 * Methods
 */

- (AtkMisc*)MISC;

/**
 * Take the thread mutex for the GUI toolkit,
 * if one exists.
 * (This method is implemented by the toolkit ATK implementation layer;
 *  for instance, for GTK+, GAIL implements this via GDK_THREADS_ENTER).
 *
 */
- (void)threadsEnter;

/**
 * Release the thread mutex for the GUI toolkit,
 * if one exists. This method, and atk_misc_threads_enter,
 * are needed in some situations by threaded application code which
 * services ATK requests, since fulfilling ATK requests often
 * requires calling into the GUI toolkit.  If a long-running or
 * potentially blocking call takes place inside such a block, it should
 * be bracketed by atk_misc_threads_leave/atk_misc_threads_enter calls.
 * (This method is implemented by the toolkit ATK implementation layer;
 *  for instance, for GTK+, GAIL implements this via GDK_THREADS_LEAVE).
 *
 */
- (void)threadsLeave;

@end