/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <atk/atk.h>

#import <OGObject/OGObject.h>

/**
 * An AtkStateSet is a read-only representation of the full set of #AtkStates
 * that apply to an object at a given time. This set is not meant to be
 * modified, but rather created when #atk_object_ref_state_set() is called.
 *
 */
@interface OGAtkStateSet : OGObject
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (AtkStateSet*)STATESET;

/**
 * Adds the state of the specified type to the state set if it is not already
 * present.
 * 
 * Note that because an #AtkStateSet is a read-only object, this method should
 * be used to add a state to a newly-created set which will then be returned by
 * #atk_object_ref_state_set. It should not be used to modify the existing state
 * of an object. See also #atk_object_notify_state_change.
 *
 * @param type an #AtkStateType
 * @return %TRUE if  the state for @type is not already in @set.
 */
- (bool)addState:(AtkStateType)type;

/**
 * Adds the states of the specified types to the state set.
 * 
 * Note that because an #AtkStateSet is a read-only object, this method should
 * be used to add states to a newly-created set which will then be returned by
 * #atk_object_ref_state_set. It should not be used to modify the existing state
 * of an object. See also #atk_object_notify_state_change.
 *
 * @param types an array of #AtkStateType
 * @param ntypes The number of elements in the array
 */
- (void)addStatesWithTypes:(AtkStateType*)types ntypes:(gint)ntypes;

/**
 * Constructs the intersection of the two sets, returning %NULL if the
 * intersection is empty.
 *
 * @param compareSet another #AtkStateSet
 * @return a new #AtkStateSet which is the intersection of
 * the two sets.
 */
- (OGAtkStateSet*)andSets:(OGAtkStateSet*)compareSet;

/**
 * Removes all states from the state set.
 *
 */
- (void)clearStates;

/**
 * Checks whether the state for the specified type is in the specified set.
 *
 * @param type an #AtkStateType
 * @return %TRUE if @type is the state type is in @set.
 */
- (bool)containsState:(AtkStateType)type;

/**
 * Checks whether the states for all the specified types are in the
 * specified set.
 *
 * @param types an array of #AtkStateType
 * @param ntypes The number of elements in the array
 * @return %TRUE if all the states for @type are in @set.
 */
- (bool)containsStatesWithTypes:(AtkStateType*)types ntypes:(gint)ntypes;

/**
 * Checks whether the state set is empty, i.e. has no states set.
 *
 * @return %TRUE if @set has no states set, otherwise %FALSE
 */
- (bool)isEmpty;

/**
 * Constructs the union of the two sets.
 *
 * @param compareSet another #AtkStateSet
 * @return a new #AtkStateSet which is
 * the union of the two sets, returning %NULL is empty.
 */
- (OGAtkStateSet*)orSets:(OGAtkStateSet*)compareSet;

/**
 * Removes the state for the specified type from the state set.
 * 
 * Note that because an #AtkStateSet is a read-only object, this method should
 * be used to remove a state to a newly-created set which will then be returned
 * by #atk_object_ref_state_set. It should not be used to modify the existing
 * state of an object. See also #atk_object_notify_state_change.
 *
 * @param type an #AtkType
 * @return %TRUE if @type was the state type is in @set.
 */
- (bool)removeState:(AtkStateType)type;

/**
 * Constructs the exclusive-or of the two sets, returning %NULL is empty.
 * The set returned by this operation contains the states in exactly
 * one of the two sets.
 *
 * @param compareSet another #AtkStateSet
 * @return a new #AtkStateSet which contains the states
 * which are in exactly one of the two sets.
 */
- (OGAtkStateSet*)xorSets:(OGAtkStateSet*)compareSet;

@end