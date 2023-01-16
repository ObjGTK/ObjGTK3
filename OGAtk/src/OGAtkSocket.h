/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkObject.h"

/**
 * Container for AtkPlug objects from other processes
 * 
 * Together with #AtkPlug, #AtkSocket provides the ability to embed
 * accessibles from one process into another in a fashion that is
 * transparent to assistive technologies. #AtkSocket works as the
 * container of #AtkPlug, embedding it using the method
 * atk_socket_embed(). Any accessible contained in the #AtkPlug will
 * appear to the assistive technologies as being inside the
 * application that created the #AtkSocket.
 * 
 * The communication between a #AtkSocket and a #AtkPlug is done by
 * the IPC layer of the accessibility framework, normally implemented
 * by the D-Bus based implementation of AT-SPI (at-spi2). If that is
 * the case, at-spi-atk2 is the responsible to implement the abstract
 * methods atk_plug_get_id() and atk_socket_embed(), so an ATK
 * implementor shouldn't reimplement them. The process that contains
 * the #AtkPlug is responsible to send the ID returned by
 * atk_plug_id() to the process that contains the #AtkSocket, so it
 * could call the method atk_socket_embed() in order to embed it.
 * 
 * For the same reasons, an implementor doesn't need to implement
 * atk_object_get_n_accessible_children() and
 * atk_object_ref_accessible_child(). All the logic related to those
 * functions will be implemented by the IPC layer.
 * 
 * See [class@AtkPlug]
 *
 */
@interface OGAtkSocket : OGAtkObject
{

}


/**
 * Constructors
 */
- (instancetype)init;

/**
 * Methods
 */

- (AtkSocket*)SOCKET;

/**
 * Embeds the children of an #AtkPlug as the children of the
 * #AtkSocket. The plug may be in the same process or in a different
 * process.
 * 
 * The class item used by this function should be filled in by the IPC
 * layer (usually at-spi2-atk). The implementor of the AtkSocket
 * should call this function and pass the id for the plug as returned
 * by atk_plug_get_id().  It is the responsibility of the application
 * to pass the plug id on to the process implementing the #AtkSocket
 * as needed.
 *
 * @param plugId the ID of an #AtkPlug
 */
- (void)embed:(OFString*)plugId;

/**
 * Determines whether or not the socket has an embedded plug.
 *
 * @return TRUE if a plug is embedded in the socket
 */
- (bool)isOccupied;

@end