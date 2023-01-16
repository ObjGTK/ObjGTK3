/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkObjectFactory.h"

#import "OGAtkObject.h"

@implementation OGAtkObjectFactory

- (AtkObjectFactory*)OBJECTFACTORY
{
	return ATK_OBJECT_FACTORY([self GOBJECT]);
}

- (OGAtkObject*)createAccessible:(GObject*)obj
{
	return [[[OGAtkObject alloc] initWithGObject:(GObject*)atk_object_factory_create_accessible([self OBJECTFACTORY], obj)] autorelease];
}

- (GType)accessibleType
{
	return atk_object_factory_get_accessible_type([self OBJECTFACTORY]);
}

- (void)invalidate
{
	atk_object_factory_invalidate([self OBJECTFACTORY]);
}


@end