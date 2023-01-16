/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKSpinnerAccessible.h"

@implementation OGTKSpinnerAccessible

- (GtkSpinnerAccessible*)SPINNERACCESSIBLE
{
	return GTK_SPINNER_ACCESSIBLE([self GOBJECT]);
}


@end