/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRecentChooserWidget.h"

#import "OGTKRecentManager.h"
#import "OGTKWidget.h"

@implementation OGTKRecentChooserWidget

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_recent_chooser_widget_new()];

	return self;
}

- (instancetype)initForManager:(OGTKRecentManager*)manager
{
	self = [super initWithGObject:(GObject*)gtk_recent_chooser_widget_new_for_manager([manager RECENTMANAGER])];

	return self;
}

- (GtkRecentChooserWidget*)RECENTCHOOSERWIDGET
{
	return GTK_RECENT_CHOOSER_WIDGET([self GOBJECT]);
}


@end