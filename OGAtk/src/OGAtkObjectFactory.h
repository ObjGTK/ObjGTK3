/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <atk/atk.h>

#import <OGObject/OGObject.h>

@class OGAtkObject;

/**
 * The base object class for a factory used to
 *  create accessible objects for objects of a specific GType.
 * 
 * This class is the base object class for a factory used to create an
 * accessible object for a specific GType. The function
 * atk_registry_set_factory_type() is normally called to store in the
 * registry the factory type to be used to create an accessible of a
 * particular GType.
 *
 */
@interface OGAtkObjectFactory : OGObject
{

}


/**
 * Methods
 */

- (AtkObjectFactory*)OBJECTFACTORY;

/**
 * Provides an #AtkObject that implements an accessibility interface
 * on behalf of @obj
 *
 * @param obj a #GObject
 * @return an #AtkObject that implements an accessibility
 * interface on behalf of @obj
 */
- (OGAtkObject*)createAccessible:(GObject*)obj;

/**
 * Gets the GType of the accessible which is created by the factory.
 *
 * @return the type of the accessible which is created by the @factory.
 * The value G_TYPE_INVALID is returned if no type if found.
 */
- (GType)accessibleType;

/**
 * Inform @factory that it is no longer being used to create
 * accessibles. When called, @factory may need to inform
 * #AtkObjects which it has created that they need to be re-instantiated.
 * Note: primarily used for runtime replacement of #AtkObjectFactorys
 * in object registries.
 *
 */
- (void)invalidate;

@end