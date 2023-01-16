/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKEventBox.h"

#import "OGTKWidget.h"

@implementation OGTKEventBox

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_event_box_new()];

	return self;
}

- (GtkEventBox*)EVENTBOX
{
	return GTK_EVENT_BOX([self GOBJECT]);
}

- (bool)aboveChild
{
	return gtk_event_box_get_above_child([self EVENTBOX]);
}

- (bool)visibleWindow
{
	return gtk_event_box_get_visible_window([self EVENTBOX]);
}

- (void)setAboveChild:(bool)aboveChild
{
	gtk_event_box_set_above_child([self EVENTBOX], aboveChild);
}

- (void)setVisibleWindow:(bool)visibleWindow
{
	gtk_event_box_set_visible_window([self EVENTBOX], visibleWindow);
}


@end