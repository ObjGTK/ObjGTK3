/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <atk/atk.h>

#import <OGObject/OGObject.h>

@class OGAtkObject;
@class OGAtkRelation;

/**
 * The AtkRelationSet held by an object establishes its relationships
 * with objects beyond the normal "parent/child" hierarchical
 * relationships that all user interface objects have.
 * AtkRelationSets establish whether objects are labelled or
 * controlled by other components, share group membership with other
 * components (for instance within a radio-button group), or share
 * content which "flows" between them, among other types of possible
 * relationships.
 *
 */
@interface OGAtkRelationSet : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (AtkRelationSet*)RELATIONSET;

/**
 * Add a new relation to the current relation set if it is not already
 * present.
 * This function ref's the AtkRelation so the caller of this function
 * should unref it to ensure that it will be destroyed when the AtkRelationSet
 * is destroyed.
 *
 * @param relation an #AtkRelation
 */
- (void)add:(OGAtkRelation*)relation;

/**
 * Add a new relation of the specified type with the specified target to
 * the current relation set if the relation set does not contain a relation
 * of that type. If it is does contain a relation of that typea the target
 * is added to the relation.
 *
 * @param relationship an #AtkRelationType
 * @param target an #AtkObject
 */
- (void)addRelationByTypeWithRelationship:(AtkRelationType)relationship target:(OGAtkObject*)target;

/**
 * Determines whether the relation set contains a relation that matches the
 * specified type.
 *
 * @param relationship an #AtkRelationType
 * @return %TRUE if @relationship is the relationship type of a relation
 * in @set, %FALSE otherwise
 */
- (bool)contains:(AtkRelationType)relationship;

/**
 * Determines whether the relation set contains a relation that
 * matches the specified pair formed by type @relationship and object
 * @target.
 *
 * @param relationship an #AtkRelationType
 * @param target an #AtkObject
 * @return %TRUE if @set contains a relation with the relationship
 * type @relationship with an object @target, %FALSE otherwise
 */
- (bool)containsTargetWithRelationship:(AtkRelationType)relationship target:(OGAtkObject*)target;

/**
 * Determines the number of relations in a relation set.
 *
 * @return an integer representing the number of relations in the set.
 */
- (gint)nrelations;

/**
 * Determines the relation at the specified position in the relation set.
 *
 * @param i a gint representing a position in the set, starting from 0.
 * @return a #AtkRelation, which is the relation at
 * position i in the set.
 */
- (OGAtkRelation*)relation:(gint)i;

/**
 * Finds a relation that matches the specified type.
 *
 * @param relationship an #AtkRelationType
 * @return an #AtkRelation, which is a relation matching the
 * specified type.
 */
- (OGAtkRelation*)relationByType:(AtkRelationType)relationship;

/**
 * Removes a relation from the relation set.
 * This function unref's the #AtkRelation so it will be deleted unless there
 * is another reference to it.
 *
 * @param relation an #AtkRelation
 */
- (void)remove:(OGAtkRelation*)relation;

@end