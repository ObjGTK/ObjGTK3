/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAccessible.h"

#import "OGTKWidget.h"

@implementation OGTKAccessible

- (GtkAccessible*)ACCESSIBLE
{
	return GTK_ACCESSIBLE([self GOBJECT]);
}

- (void)connectWidgetDestroyed
{
	gtk_accessible_connect_widget_destroyed([self ACCESSIBLE]);
}

- (OGTKWidget*)widget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_accessible_get_widget([self ACCESSIBLE])] autorelease];
}

- (void)setWidget:(OGTKWidget*)widget
{
	gtk_accessible_set_widget([self ACCESSIBLE], [widget WIDGET]);
}


@end