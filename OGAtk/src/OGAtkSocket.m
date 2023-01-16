/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkSocket.h"

@implementation OGAtkSocket

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)atk_socket_new()];

	return self;
}

- (AtkSocket*)SOCKET
{
	return ATK_SOCKET([self GOBJECT]);
}

- (void)embed:(OFString*)plugId
{
	atk_socket_embed([self SOCKET], [plugId UTF8String]);
}

- (bool)isOccupied
{
	return atk_socket_is_occupied([self SOCKET]);
}


@end