/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKLinkButtonAccessible.h"

@implementation OGTKLinkButtonAccessible

- (GtkLinkButtonAccessible*)LINKBUTTONACCESSIBLE
{
	return GTK_LINK_BUTTON_ACCESSIBLE([self GOBJECT]);
}


@end