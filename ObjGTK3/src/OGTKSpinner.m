/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSpinner.h"

@implementation OGTKSpinner

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_spinner_new()];

	return self;
}

- (GtkSpinner*)SPINNER
{
	return GTK_SPINNER([self GOBJECT]);
}

- (void)start
{
	gtk_spinner_start([self SPINNER]);
}

- (void)stop
{
	gtk_spinner_stop([self SPINNER]);
}


@end