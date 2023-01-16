/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKActionBar.h"

#import "OGTKWidget.h"

@implementation OGTKActionBar

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_action_bar_new()];

	return self;
}

- (GtkActionBar*)ACTIONBAR
{
	return GTK_ACTION_BAR([self GOBJECT]);
}

- (OGTKWidget*)centerWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_action_bar_get_center_widget([self ACTIONBAR])] autorelease];
}

- (void)packEnd:(OGTKWidget*)child
{
	gtk_action_bar_pack_end([self ACTIONBAR], [child WIDGET]);
}

- (void)packStart:(OGTKWidget*)child
{
	gtk_action_bar_pack_start([self ACTIONBAR], [child WIDGET]);
}

- (void)setCenterWidget:(OGTKWidget*)centerWidget
{
	gtk_action_bar_set_center_widget([self ACTIONBAR], [centerWidget WIDGET]);
}


@end