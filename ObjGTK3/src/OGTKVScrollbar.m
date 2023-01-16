/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKVScrollbar.h"

#import "OGTKAdjustment.h"
#import "OGTKWidget.h"

@implementation OGTKVScrollbar

- (instancetype)init:(OGTKAdjustment*)adjustment
{
	self = [super initWithGObject:(GObject*)gtk_vscrollbar_new([adjustment ADJUSTMENT])];

	return self;
}

- (GtkVScrollbar*)VSCROLLBAR
{
	return GTK_VSCROLLBAR([self GOBJECT]);
}


@end