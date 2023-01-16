/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKStatusbar.h"

#import "OGTKWidget.h"

@implementation OGTKStatusbar

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_statusbar_new()];

	return self;
}

- (GtkStatusbar*)STATUSBAR
{
	return GTK_STATUSBAR([self GOBJECT]);
}

- (guint)contextId:(OFString*)contextDescription
{
	return gtk_statusbar_get_context_id([self STATUSBAR], [contextDescription UTF8String]);
}

- (OGTKWidget*)messageArea
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_statusbar_get_message_area([self STATUSBAR])] autorelease];
}

- (void)pop:(guint)contextId
{
	gtk_statusbar_pop([self STATUSBAR], contextId);
}

- (guint)pushWithContextId:(guint)contextId text:(OFString*)text
{
	return gtk_statusbar_push([self STATUSBAR], contextId, [text UTF8String]);
}

- (void)removeWithContextId:(guint)contextId messageId:(guint)messageId
{
	gtk_statusbar_remove([self STATUSBAR], contextId, messageId);
}

- (void)removeAll:(guint)contextId
{
	gtk_statusbar_remove_all([self STATUSBAR], contextId);
}


@end