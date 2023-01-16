/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKIMContextSimple.h"

@implementation OGTKIMContextSimple

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_im_context_simple_new()];

	return self;
}

- (GtkIMContextSimple*)IMCONTEXTSIMPLE
{
	return GTK_IM_CONTEXT_SIMPLE([self GOBJECT]);
}

- (void)addComposeFile:(OFString*)composeFile
{
	gtk_im_context_simple_add_compose_file([self IMCONTEXTSIMPLE], [composeFile UTF8String]);
}

- (void)addTableWithData:(guint16*)data maxSeqLen:(gint)maxSeqLen nseqs:(gint)nseqs
{
	gtk_im_context_simple_add_table([self IMCONTEXTSIMPLE], data, maxSeqLen, nseqs);
}


@end