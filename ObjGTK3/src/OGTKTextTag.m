/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTextTag.h"

@implementation OGTKTextTag

- (instancetype)init:(OFString*)name
{
	self = [super initWithGObject:(GObject*)gtk_text_tag_new([name UTF8String])];

	return self;
}

- (GtkTextTag*)TEXTTAG
{
	return GTK_TEXT_TAG([self GOBJECT]);
}

- (void)changed:(bool)sizeChanged
{
	gtk_text_tag_changed([self TEXTTAG], sizeChanged);
}

- (bool)eventWithEventObject:(GObject*)eventObject event:(GdkEvent*)event iter:(const GtkTextIter*)iter
{
	return gtk_text_tag_event([self TEXTTAG], eventObject, event, iter);
}

- (gint)priority
{
	return gtk_text_tag_get_priority([self TEXTTAG]);
}

- (void)setPriority:(gint)priority
{
	gtk_text_tag_set_priority([self TEXTTAG], priority);
}


@end