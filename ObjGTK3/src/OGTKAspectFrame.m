/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAspectFrame.h"

#import "OGTKWidget.h"

@implementation OGTKAspectFrame

- (instancetype)initWithLabel:(OFString*)label xalign:(gfloat)xalign yalign:(gfloat)yalign ratio:(gfloat)ratio obeyChild:(bool)obeyChild
{
	self = [super initWithGObject:(GObject*)gtk_aspect_frame_new([label UTF8String], xalign, yalign, ratio, obeyChild)];

	return self;
}

- (GtkAspectFrame*)ASPECTFRAME
{
	return GTK_ASPECT_FRAME([self GOBJECT]);
}

- (void)setWithXalign:(gfloat)xalign yalign:(gfloat)yalign ratio:(gfloat)ratio obeyChild:(bool)obeyChild
{
	gtk_aspect_frame_set([self ASPECTFRAME], xalign, yalign, ratio, obeyChild);
}


@end