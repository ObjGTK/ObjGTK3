/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKProgressBarAccessible.h"

@implementation OGTKProgressBarAccessible

- (GtkProgressBarAccessible*)PROGRESSBARACCESSIBLE
{
	return GTK_PROGRESS_BAR_ACCESSIBLE([self GOBJECT]);
}


@end