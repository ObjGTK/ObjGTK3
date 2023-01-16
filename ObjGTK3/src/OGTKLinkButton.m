/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKLinkButton.h"

#import "OGTKWidget.h"

@implementation OGTKLinkButton

- (instancetype)init:(OFString*)uri
{
	self = [super initWithGObject:(GObject*)gtk_link_button_new([uri UTF8String])];

	return self;
}

- (instancetype)initWithLabelWithUri:(OFString*)uri label:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_link_button_new_with_label([uri UTF8String], [label UTF8String])];

	return self;
}

- (GtkLinkButton*)LINKBUTTON
{
	return GTK_LINK_BUTTON([self GOBJECT]);
}

- (OFString*)uri
{
	return [OFString stringWithUTF8String:gtk_link_button_get_uri([self LINKBUTTON])];
}

- (bool)visited
{
	return gtk_link_button_get_visited([self LINKBUTTON]);
}

- (void)setUri:(OFString*)uri
{
	gtk_link_button_set_uri([self LINKBUTTON], [uri UTF8String]);
}

- (void)setVisited:(bool)visited
{
	gtk_link_button_set_visited([self LINKBUTTON], visited);
}


@end