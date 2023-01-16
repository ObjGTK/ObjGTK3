/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkRegistry.h"

#import "OGAtkObjectFactory.h"

@implementation OGAtkRegistry

- (AtkRegistry*)REGISTRY
{
	return ATK_REGISTRY([self GOBJECT]);
}

- (OGAtkObjectFactory*)factory:(GType)type
{
	return [[[OGAtkObjectFactory alloc] initWithGObject:(GObject*)atk_registry_get_factory([self REGISTRY], type)] autorelease];
}

- (GType)factoryType:(GType)type
{
	return atk_registry_get_factory_type([self REGISTRY], type);
}

- (void)setFactoryTypeWithType:(GType)type factoryType:(GType)factoryType
{
	atk_registry_set_factory_type([self REGISTRY], type, factoryType);
}


@end