/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkNoOpObject.h"

@implementation OGAtkNoOpObject

- (instancetype)init:(GObject*)obj
{
	self = [super initWithGObject:(GObject*)atk_no_op_object_new(obj)];

	return self;
}

- (AtkNoOpObject*)NOOPOBJECT
{
	return ATK_NO_OP_OBJECT([self GOBJECT]);
}


@end