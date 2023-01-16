/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkRelation.h"

#import "OGAtkObject.h"

@implementation OGAtkRelation

- (instancetype)initWithTargets:(AtkObject**)targets ntargets:(gint)ntargets relationship:(AtkRelationType)relationship
{
	self = [super initWithGObject:(GObject*)atk_relation_new(targets, ntargets, relationship)];

	return self;
}

- (AtkRelation*)RELATION
{
	return ATK_RELATION([self GOBJECT]);
}

- (void)addTarget:(OGAtkObject*)target
{
	atk_relation_add_target([self RELATION], [target OBJECT]);
}

- (AtkRelationType)relationType
{
	return atk_relation_get_relation_type([self RELATION]);
}

- (GPtrArray*)target
{
	return atk_relation_get_target([self RELATION]);
}

- (bool)removeTarget:(OGAtkObject*)target
{
	return atk_relation_remove_target([self RELATION], [target OBJECT]);
}


@end