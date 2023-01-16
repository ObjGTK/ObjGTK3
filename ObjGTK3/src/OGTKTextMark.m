/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKTextMark.h"

#import "OGTKTextBuffer.h"

@implementation OGTKTextMark

- (instancetype)initWithName:(OFString*)name leftGravity:(bool)leftGravity
{
	self = [super initWithGObject:(GObject*)gtk_text_mark_new([name UTF8String], leftGravity)];

	return self;
}

- (GtkTextMark*)TEXTMARK
{
	return GTK_TEXT_MARK([self GOBJECT]);
}

- (OGTKTextBuffer*)buffer
{
	return [[[OGTKTextBuffer alloc] initWithGObject:(GObject*)gtk_text_mark_get_buffer([self TEXTMARK])] autorelease];
}

- (bool)deleted
{
	return gtk_text_mark_get_deleted([self TEXTMARK]);
}

- (bool)leftGravity
{
	return gtk_text_mark_get_left_gravity([self TEXTMARK]);
}

- (OFString*)name
{
	return [OFString stringWithUTF8String:gtk_text_mark_get_name([self TEXTMARK])];
}

- (bool)visible
{
	return gtk_text_mark_get_visible([self TEXTMARK]);
}

- (void)setVisible:(bool)setting
{
	gtk_text_mark_set_visible([self TEXTMARK], setting);
}


@end