/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkObject.h"

#import "OGAtkRelationSet.h"
#import "OGAtkStateSet.h"

@implementation OGAtkObject

- (AtkObject*)OBJECT
{
	return ATK_OBJECT([self GOBJECT]);
}

- (bool)addRelationshipWithRelationship:(AtkRelationType)relationship target:(OGAtkObject*)target
{
	return atk_object_add_relationship([self OBJECT], relationship, [target OBJECT]);
}

- (guint)connectPropertyChangeHandler:(AtkPropertyChangeHandler*)handler
{
	return atk_object_connect_property_change_handler([self OBJECT], handler);
}

- (OFString*)accessibleId
{
	return [OFString stringWithUTF8String:atk_object_get_accessible_id([self OBJECT])];
}

- (AtkAttributeSet*)attributes
{
	return atk_object_get_attributes([self OBJECT]);
}

- (OFString*)description
{
	return [OFString stringWithUTF8String:atk_object_get_description([self OBJECT])];
}

- (gint)indexInParent
{
	return atk_object_get_index_in_parent([self OBJECT]);
}

- (AtkLayer)layer
{
	return atk_object_get_layer([self OBJECT]);
}

- (gint)mdiZorder
{
	return atk_object_get_mdi_zorder([self OBJECT]);
}

- (gint)naccessibleChildren
{
	return atk_object_get_n_accessible_children([self OBJECT]);
}

- (OFString*)name
{
	return [OFString stringWithUTF8String:atk_object_get_name([self OBJECT])];
}

- (OFString*)objectLocale
{
	return [OFString stringWithUTF8String:atk_object_get_object_locale([self OBJECT])];
}

- (OGAtkObject*)parent
{
	return [[[OGAtkObject alloc] initWithGObject:(GObject*)atk_object_get_parent([self OBJECT])] autorelease];
}

- (AtkRole)role
{
	return atk_object_get_role([self OBJECT]);
}

- (void)initialize:(gpointer)data
{
	atk_object_initialize([self OBJECT], data);
}

- (void)notifyStateChangeWithState:(AtkState)state value:(bool)value
{
	atk_object_notify_state_change([self OBJECT], state, value);
}

- (OGAtkObject*)peekParent
{
	return [[[OGAtkObject alloc] initWithGObject:(GObject*)atk_object_peek_parent([self OBJECT])] autorelease];
}

- (OGAtkObject*)refAccessibleChild:(gint)i
{
	return [[[OGAtkObject alloc] initWithGObject:(GObject*)atk_object_ref_accessible_child([self OBJECT], i)] autorelease];
}

- (OGAtkRelationSet*)refRelationSet
{
	return [[[OGAtkRelationSet alloc] initWithGObject:(GObject*)atk_object_ref_relation_set([self OBJECT])] autorelease];
}

- (OGAtkStateSet*)refStateSet
{
	return [[[OGAtkStateSet alloc] initWithGObject:(GObject*)atk_object_ref_state_set([self OBJECT])] autorelease];
}

- (void)removePropertyChangeHandler:(guint)handlerId
{
	atk_object_remove_property_change_handler([self OBJECT], handlerId);
}

- (bool)removeRelationshipWithRelationship:(AtkRelationType)relationship target:(OGAtkObject*)target
{
	return atk_object_remove_relationship([self OBJECT], relationship, [target OBJECT]);
}

- (void)setAccessibleId:(OFString*)name
{
	atk_object_set_accessible_id([self OBJECT], [name UTF8String]);
}

- (void)setDescription:(OFString*)description
{
	atk_object_set_description([self OBJECT], [description UTF8String]);
}

- (void)setName:(OFString*)name
{
	atk_object_set_name([self OBJECT], [name UTF8String]);
}

- (void)setParent:(OGAtkObject*)parent
{
	atk_object_set_parent([self OBJECT], [parent OBJECT]);
}

- (void)setRole:(AtkRole)role
{
	atk_object_set_role([self OBJECT], role);
}


@end