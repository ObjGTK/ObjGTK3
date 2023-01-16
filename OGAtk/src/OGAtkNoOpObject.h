/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkObject.h"

/**
 * An AtkObject which purports to implement all ATK interfaces.
 * 
 * An AtkNoOpObject is an AtkObject which purports to implement all
 * ATK interfaces. It is the type of AtkObject which is created if an
 * accessible object is requested for an object type for which no
 * factory type is specified.
 *
 */
@interface OGAtkNoOpObject : OGAtkObject
{

}


/**
 * Constructors
 */
- (instancetype)init:(GObject*)obj;

/**
 * Methods
 */

- (AtkNoOpObject*)NOOPOBJECT;

@end