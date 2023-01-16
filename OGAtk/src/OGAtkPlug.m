/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkPlug.h"

@implementation OGAtkPlug

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)atk_plug_new()];

	return self;
}

- (AtkPlug*)PLUG
{
	return ATK_PLUG([self GOBJECT]);
}

- (OFString*)id
{
	return [OFString stringWithUTF8String:atk_plug_get_id([self PLUG])];
}

- (void)setChild:(OGAtkObject*)child
{
	atk_plug_set_child([self PLUG], [child OBJECT]);
}


@end