/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTextChildAnchor.h"

@implementation OGTKTextChildAnchor

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_text_child_anchor_new()];

	return self;
}

- (GtkTextChildAnchor*)TEXTCHILDANCHOR
{
	return GTK_TEXT_CHILD_ANCHOR([self GOBJECT]);
}

- (bool)deleted
{
	return gtk_text_child_anchor_get_deleted([self TEXTCHILDANCHOR]);
}

- (GList*)widgets
{
	return gtk_text_child_anchor_get_widgets([self TEXTCHILDANCHOR]);
}


@end