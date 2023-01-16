/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkNoOpObjectFactory.h"

@implementation OGAtkNoOpObjectFactory

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)atk_no_op_object_factory_new()];

	return self;
}

- (AtkNoOpObjectFactory*)NOOPOBJECTFACTORY
{
	return ATK_NO_OP_OBJECT_FACTORY([self GOBJECT]);
}


@end