/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <pango/pango.h>

#import <OGObject/OGObject.h>

/**
 * #PangoEngine is the base class for all types of language and
 * script specific engines. It has no functionality by itself.
 *
 */
@interface OGPangoEngine : OGObject
{

}


/**
 * Methods
 */

- (PangoEngine*)ENGINE;

@end