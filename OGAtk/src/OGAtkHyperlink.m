/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGAtkHyperlink.h"

#import "OGAtkObject.h"

@implementation OGAtkHyperlink

- (AtkHyperlink*)HYPERLINK
{
	return ATK_HYPERLINK([self GOBJECT]);
}

- (gint)endIndex
{
	return atk_hyperlink_get_end_index([self HYPERLINK]);
}

- (gint)nanchors
{
	return atk_hyperlink_get_n_anchors([self HYPERLINK]);
}

- (OGAtkObject*)object:(gint)i
{
	return [[[OGAtkObject alloc] initWithGObject:(GObject*)atk_hyperlink_get_object([self HYPERLINK], i)] autorelease];
}

- (gint)startIndex
{
	return atk_hyperlink_get_start_index([self HYPERLINK]);
}

- (OFString*)uri:(gint)i
{
	return [OFString stringWithUTF8String:atk_hyperlink_get_uri([self HYPERLINK], i)];
}

- (bool)isInline
{
	return atk_hyperlink_is_inline([self HYPERLINK]);
}

- (bool)isSelectedLink
{
	return atk_hyperlink_is_selected_link([self HYPERLINK]);
}

- (bool)isValid
{
	return atk_hyperlink_is_valid([self HYPERLINK]);
}


@end