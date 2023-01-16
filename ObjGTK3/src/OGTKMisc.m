/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMisc.h"

@implementation OGTKMisc

- (GtkMisc*)MISC
{
	return GTK_MISC([self GOBJECT]);
}

- (void)alignmentWithXalign:(gfloat*)xalign yalign:(gfloat*)yalign
{
	gtk_misc_get_alignment([self MISC], xalign, yalign);
}

- (void)paddingWithXpad:(gint*)xpad ypad:(gint*)ypad
{
	gtk_misc_get_padding([self MISC], xpad, ypad);
}

- (void)setAlignmentWithXalign:(gfloat)xalign yalign:(gfloat)yalign
{
	gtk_misc_set_alignment([self MISC], xalign, yalign);
}

- (void)setPaddingWithXpad:(gint)xpad ypad:(gint)ypad
{
	gtk_misc_set_padding([self MISC], xpad, ypad);
}


@end