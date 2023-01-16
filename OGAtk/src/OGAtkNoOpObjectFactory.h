/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkObjectFactory.h"

/**
 * The AtkObjectFactory which creates an AtkNoOpObject. An instance of
 * this is created by an AtkRegistry if no factory type has not been
 * specified to create an accessible object of a particular type.
 *
 */
@interface OGAtkNoOpObjectFactory : OGAtkObjectFactory
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (AtkNoOpObjectFactory*)NOOPOBJECTFACTORY;

@end