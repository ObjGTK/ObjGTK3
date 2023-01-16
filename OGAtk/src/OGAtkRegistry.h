/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <atk/atk.h>

#import <OGObject/OGObject.h>

@class OGAtkObjectFactory;

/**
 * The AtkRegistry is normally used to create appropriate ATK "peers"
 * for user interface components.  Application developers usually need
 * only interact with the AtkRegistry by associating appropriate ATK
 * implementation classes with GObject classes via the
 * atk_registry_set_factory_type call, passing the appropriate GType
 * for application custom widget classes.
 *
 */
@interface OGAtkRegistry : OGObject
{

}


/**
 * Methods
 */

- (AtkRegistry*)REGISTRY;

/**
 * Gets an #AtkObjectFactory appropriate for creating #AtkObjects
 * appropriate for @type.
 *
 * @param type a #GType with which to look up the associated #AtkObjectFactory
 * @return an #AtkObjectFactory appropriate for creating
 * #AtkObjects appropriate for @type.
 */
- (OGAtkObjectFactory*)factory:(GType)type;

/**
 * Provides a #GType indicating the #AtkObjectFactory subclass
 * associated with @type.
 *
 * @param type a #GType with which to look up the associated #AtkObjectFactory
 * subclass
 * @return a #GType associated with type @type
 */
- (GType)factoryType:(GType)type;

/**
 * Associate an #AtkObjectFactory subclass with a #GType. Note:
 * The associated @factory_type will thereafter be responsible for
 * the creation of new #AtkObject implementations for instances
 * appropriate for @type.
 *
 * @param type an #AtkObject type
 * @param factoryType an #AtkObjectFactory type to associate with @type.  Must
 * implement AtkObject appropriate for @type.
 */
- (void)setFactoryTypeWithType:(GType)type factoryType:(GType)factoryType;

@end