/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKVolumeButton.h"

#import "OGTKWidget.h"

@implementation OGTKVolumeButton

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_volume_button_new()];

	return self;
}

- (GtkVolumeButton*)VOLUMEBUTTON
{
	return GTK_VOLUME_BUTTON([self GOBJECT]);
}


@end