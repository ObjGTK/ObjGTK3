/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <atk/atk.h>

#import <OGObject/OGObject.h>

@class OGAtkObject;

/**
 * An object used to describe a relation between a
 *  object and one or more other objects.
 * 
 * An AtkRelation describes a relation between an object and one or
 * more other objects. The actual relations that an object has with
 * other objects are defined as an AtkRelationSet, which is a set of
 * AtkRelations.
 *
 */
@interface OGAtkRelation : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)initWithTargets:(AtkObject**)targets ntargets:(gint)ntargets relationship:(AtkRelationType)relationship;

/**
 * Methods
 */

- (AtkRelation*)RELATION;

/**
 * Adds the specified AtkObject to the target for the relation, if it is
 * not already present.  See also atk_object_add_relationship().
 *
 * @param target an #AtkObject
 */
- (void)addTarget:(OGAtkObject*)target;

/**
 * Gets the type of @relation
 *
 * @return the type of @relation
 */
- (AtkRelationType)relationType;

/**
 * Gets the target list of @relation
 *
 * @return the target list of @relation
 */
- (GPtrArray*)target;

/**
 * Remove the specified AtkObject from the target for the relation.
 *
 * @param target an #AtkObject
 * @return TRUE if the removal is successful.
 */
- (bool)removeTarget:(OGAtkObject*)target;

@end