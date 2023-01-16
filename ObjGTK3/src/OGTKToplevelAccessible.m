/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToplevelAccessible.h"

@implementation OGTKToplevelAccessible

- (GtkToplevelAccessible*)TOPLEVELACCESSIBLE
{
	return GTK_TOPLEVEL_ACCESSIBLE([self GOBJECT]);
}

- (GList*)children
{
	return gtk_toplevel_accessible_get_children([self TOPLEVELACCESSIBLE]);
}


@end