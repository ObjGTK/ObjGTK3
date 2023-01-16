/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKModelButton.h"

#import "OGTKWidget.h"

@implementation OGTKModelButton

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_model_button_new()];

	return self;
}

- (GtkModelButton*)MODELBUTTON
{
	return GTK_MODEL_BUTTON([self GOBJECT]);
}


@end