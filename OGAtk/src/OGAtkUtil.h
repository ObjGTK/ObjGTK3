/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <atk/atk.h>

#import <OGObject/OGObject.h>

/**
 * A set of ATK utility functions which are used to support event
 * registration of various types, and obtaining the 'root' accessible
 * of a process and information about the current ATK implementation
 * and toolkit version.
 *
 */
@interface OGAtkUtil : OGObject
{

}


/**
 * Methods
 */

- (AtkUtil*)UTIL;

@end