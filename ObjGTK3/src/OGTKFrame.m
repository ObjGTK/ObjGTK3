/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKFrame.h"

#import "OGTKWidget.h"

@implementation OGTKFrame

- (instancetype)init:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_frame_new([label UTF8String])];

	return self;
}

- (GtkFrame*)FRAME
{
	return GTK_FRAME([self GOBJECT]);
}

- (OFString*)label
{
	return [OFString stringWithUTF8String:gtk_frame_get_label([self FRAME])];
}

- (void)labelAlignWithXalign:(gfloat*)xalign yalign:(gfloat*)yalign
{
	gtk_frame_get_label_align([self FRAME], xalign, yalign);
}

- (OGTKWidget*)labelWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_frame_get_label_widget([self FRAME])] autorelease];
}

- (GtkShadowType)shadowType
{
	return gtk_frame_get_shadow_type([self FRAME]);
}

- (void)setLabel:(OFString*)label
{
	gtk_frame_set_label([self FRAME], [label UTF8String]);
}

- (void)setLabelAlignWithXalign:(gfloat)xalign yalign:(gfloat)yalign
{
	gtk_frame_set_label_align([self FRAME], xalign, yalign);
}

- (void)setLabelWidget:(OGTKWidget*)labelWidget
{
	gtk_frame_set_label_widget([self FRAME], [labelWidget WIDGET]);
}

- (void)setShadowType:(GtkShadowType)type
{
	gtk_frame_set_shadow_type([self FRAME], type);
}


@end