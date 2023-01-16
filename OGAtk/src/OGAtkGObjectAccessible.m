/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkGObjectAccessible.h"

@implementation OGAtkGObjectAccessible

+ (OGAtkObject*)forObject:(GObject*)obj
{
	return [[[OGAtkObject alloc] initWithGObject:(GObject*)atk_gobject_accessible_for_object(obj)] autorelease];
}

- (AtkGObjectAccessible*)GOBJECTACCESSIBLE
{
	return ATK_GOBJECT_ACCESSIBLE([self GOBJECT]);
}

- (GObject*)object
{
	return atk_gobject_accessible_get_object([self GOBJECTACCESSIBLE]);
}


@end