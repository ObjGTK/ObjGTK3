/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCheckMenuItemAccessible.h"

@implementation OGTKCheckMenuItemAccessible

- (GtkCheckMenuItemAccessible*)CHECKMENUITEMACCESSIBLE
{
	return GTK_CHECK_MENU_ITEM_ACCESSIBLE([self GOBJECT]);
}


@end