/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKDrawingArea.h"

@implementation OGTKDrawingArea

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_drawing_area_new()];

	return self;
}

- (GtkDrawingArea*)DRAWINGAREA
{
	return GTK_DRAWING_AREA([self GOBJECT]);
}


@end