/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKPlugAccessible.h"

@implementation OGTKPlugAccessible

- (GtkPlugAccessible*)PLUGACCESSIBLE
{
	return GTK_PLUG_ACCESSIBLE([self GOBJECT]);
}

- (OFString*)id
{
	return [OFString stringWithUTF8String:gtk_plug_accessible_get_id([self PLUGACCESSIBLE])];
}


@end