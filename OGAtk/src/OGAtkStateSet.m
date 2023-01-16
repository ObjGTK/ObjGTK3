/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkStateSet.h"

@implementation OGAtkStateSet

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)atk_state_set_new()];

	return self;
}

- (AtkStateSet*)STATESET
{
	return ATK_STATE_SET([self GOBJECT]);
}

- (bool)addState:(AtkStateType)type
{
	return atk_state_set_add_state([self STATESET], type);
}

- (void)addStatesWithTypes:(AtkStateType*)types ntypes:(gint)ntypes
{
	atk_state_set_add_states([self STATESET], types, ntypes);
}

- (OGAtkStateSet*)andSets:(OGAtkStateSet*)compareSet
{
	return [[[OGAtkStateSet alloc] initWithGObject:(GObject*)atk_state_set_and_sets([self STATESET], [compareSet STATESET])] autorelease];
}

- (void)clearStates
{
	atk_state_set_clear_states([self STATESET]);
}

- (bool)containsState:(AtkStateType)type
{
	return atk_state_set_contains_state([self STATESET], type);
}

- (bool)containsStatesWithTypes:(AtkStateType*)types ntypes:(gint)ntypes
{
	return atk_state_set_contains_states([self STATESET], types, ntypes);
}

- (bool)isEmpty
{
	return atk_state_set_is_empty([self STATESET]);
}

- (OGAtkStateSet*)orSets:(OGAtkStateSet*)compareSet
{
	return [[[OGAtkStateSet alloc] initWithGObject:(GObject*)atk_state_set_or_sets([self STATESET], [compareSet STATESET])] autorelease];
}

- (bool)removeState:(AtkStateType)type
{
	return atk_state_set_remove_state([self STATESET], type);
}

- (OGAtkStateSet*)xorSets:(OGAtkStateSet*)compareSet
{
	return [[[OGAtkStateSet alloc] initWithGObject:(GObject*)atk_state_set_xor_sets([self STATESET], [compareSet STATESET])] autorelease];
}


@end