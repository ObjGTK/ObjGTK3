/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAlignment.h"

#import "OGTKWidget.h"

@implementation OGTKAlignment

- (instancetype)initWithXalign:(gfloat)xalign yalign:(gfloat)yalign xscale:(gfloat)xscale yscale:(gfloat)yscale
{
	self = [super initWithGObject:(GObject*)gtk_alignment_new(xalign, yalign, xscale, yscale)];

	return self;
}

- (GtkAlignment*)ALIGNMENT
{
	return GTK_ALIGNMENT([self GOBJECT]);
}

- (void)paddingWithPaddingTop:(guint*)paddingTop paddingBottom:(guint*)paddingBottom paddingLeft:(guint*)paddingLeft paddingRight:(guint*)paddingRight
{
	gtk_alignment_get_padding([self ALIGNMENT], paddingTop, paddingBottom, paddingLeft, paddingRight);
}

- (void)setWithXalign:(gfloat)xalign yalign:(gfloat)yalign xscale:(gfloat)xscale yscale:(gfloat)yscale
{
	gtk_alignment_set([self ALIGNMENT], xalign, yalign, xscale, yscale);
}

- (void)setPaddingWithPaddingTop:(guint)paddingTop paddingBottom:(guint)paddingBottom paddingLeft:(guint)paddingLeft paddingRight:(guint)paddingRight
{
	gtk_alignment_set_padding([self ALIGNMENT], paddingTop, paddingBottom, paddingLeft, paddingRight);
}


@end