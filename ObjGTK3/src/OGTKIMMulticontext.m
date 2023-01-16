/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKIMMulticontext.h"

#import "OGTKMenuShell.h"

@implementation OGTKIMMulticontext

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_im_multicontext_new()];

	return self;
}

- (GtkIMMulticontext*)IMMULTICONTEXT
{
	return GTK_IM_MULTICONTEXT([self GOBJECT]);
}

- (void)appendMenuitems:(OGTKMenuShell*)menushell
{
	gtk_im_multicontext_append_menuitems([self IMMULTICONTEXT], [menushell MENUSHELL]);
}

- (OFString*)contextId
{
	return [OFString stringWithUTF8String:gtk_im_multicontext_get_context_id([self IMMULTICONTEXT])];
}

- (void)setContextId:(OFString*)contextId
{
	gtk_im_multicontext_set_context_id([self IMMULTICONTEXT], [contextId UTF8String]);
}


@end