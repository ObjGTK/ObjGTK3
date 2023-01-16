/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkObject.h"

/**
 * See #AtkSocket
 *
 */
@interface OGAtkPlug : OGAtkObject
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (AtkPlug*)PLUG;

/**
 * Gets the unique ID of an #AtkPlug object, which can be used to
 * embed inside of an #AtkSocket using atk_socket_embed().
 * 
 * Internally, this calls a class function that should be registered
 * by the IPC layer (usually at-spi2-atk). The implementor of an
 * #AtkPlug object should call this function (after atk-bridge is
 * loaded) and pass the value to the process implementing the
 * #AtkSocket, so it could embed the plug.
 *
 * @return the unique ID for the plug
 */
- (OFString*)id;

/**
 * Sets @child as accessible child of @plug and @plug as accessible parent of
 * @child. @child can be NULL.
 * 
 * In some cases, one can not use the AtkPlug type directly as accessible
 * object for the toplevel widget of the application. For instance in the gtk
 * case, GtkPlugAccessible can not inherit both from GtkWindowAccessible and
 * from AtkPlug. In such a case, one can create, in addition to the standard
 * accessible object for the toplevel widget, an AtkPlug object, and make the
 * former the child of the latter by calling atk_plug_set_child().
 *
 * @param child an #AtkObject to be set as accessible child of @plug.
 */
- (void)setChild:(OGAtkObject*)child;

@end