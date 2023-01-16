/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCellAccessible.h"

@interface OGTKContainerCellAccessible : OGTKCellAccessible
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (GtkContainerCellAccessible*)CONTAINERCELLACCESSIBLE;

/**
 *
 * @param child
 */
- (void)addChild:(OGTKCellAccessible*)child;

/**
 * Get a list of children.
 *
 * @return
 */
- (GList*)children;

/**
 *
 * @param child
 */
- (void)removeChild:(OGTKCellAccessible*)child;

@end