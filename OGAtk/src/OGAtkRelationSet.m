/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkRelationSet.h"

#import "OGAtkRelation.h"
#import "OGAtkObject.h"

@implementation OGAtkRelationSet

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)atk_relation_set_new()];

	return self;
}

- (AtkRelationSet*)RELATIONSET
{
	return ATK_RELATION_SET([self GOBJECT]);
}

- (void)add:(OGAtkRelation*)relation
{
	atk_relation_set_add([self RELATIONSET], [relation RELATION]);
}

- (void)addRelationByTypeWithRelationship:(AtkRelationType)relationship target:(OGAtkObject*)target
{
	atk_relation_set_add_relation_by_type([self RELATIONSET], relationship, [target OBJECT]);
}

- (bool)contains:(AtkRelationType)relationship
{
	return atk_relation_set_contains([self RELATIONSET], relationship);
}

- (bool)containsTargetWithRelationship:(AtkRelationType)relationship target:(OGAtkObject*)target
{
	return atk_relation_set_contains_target([self RELATIONSET], relationship, [target OBJECT]);
}

- (gint)nrelations
{
	return atk_relation_set_get_n_relations([self RELATIONSET]);
}

- (OGAtkRelation*)relation:(gint)i
{
	return [[[OGAtkRelation alloc] initWithGObject:(GObject*)atk_relation_set_get_relation([self RELATIONSET], i)] autorelease];
}

- (OGAtkRelation*)relationByType:(AtkRelationType)relationship
{
	return [[[OGAtkRelation alloc] initWithGObject:(GObject*)atk_relation_set_get_relation_by_type([self RELATIONSET], relationship)] autorelease];
}

- (void)remove:(OGAtkRelation*)relation
{
	atk_relation_set_remove([self RELATIONSET], [relation RELATION]);
}


@end