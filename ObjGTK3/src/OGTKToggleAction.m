/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToggleAction.h"

@implementation OGTKToggleAction

- (instancetype)initWithName:(OFString*)name label:(OFString*)label tooltip:(OFString*)tooltip stockId:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_toggle_action_new([name UTF8String], [label UTF8String], [tooltip UTF8String], [stockId UTF8String])];

	return self;
}

- (GtkToggleAction*)TOGGLEACTION
{
	return GTK_TOGGLE_ACTION([self GOBJECT]);
}

- (bool)active
{
	return gtk_toggle_action_get_active([self TOGGLEACTION]);
}

- (bool)drawAsRadio
{
	return gtk_toggle_action_get_draw_as_radio([self TOGGLEACTION]);
}

- (void)setActive:(bool)isActive
{
	gtk_toggle_action_set_active([self TOGGLEACTION], isActive);
}

- (void)setDrawAsRadio:(bool)drawAsRadio
{
	gtk_toggle_action_set_draw_as_radio([self TOGGLEACTION], drawAsRadio);
}

- (void)toggled
{
	gtk_toggle_action_toggled([self TOGGLEACTION]);
}


@end