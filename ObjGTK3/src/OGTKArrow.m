/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKArrow.h"

#import "OGTKWidget.h"

@implementation OGTKArrow

- (instancetype)initWithArrowType:(GtkArrowType)arrowType shadowType:(GtkShadowType)shadowType
{
	self = [super initWithGObject:(GObject*)gtk_arrow_new(arrowType, shadowType)];

	return self;
}

- (GtkArrow*)ARROW
{
	return GTK_ARROW([self GOBJECT]);
}

- (void)setWithArrowType:(GtkArrowType)arrowType shadowType:(GtkShadowType)shadowType
{
	gtk_arrow_set([self ARROW], arrowType, shadowType);
}


@end