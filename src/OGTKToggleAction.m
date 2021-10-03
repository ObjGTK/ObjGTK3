/*
 * OGTKToggleAction.m
 * This file is part of ObjGTK which is a fork of CoreGTK for ObjFW
 *
 * Copyright (C) 2017 - Tyler Burton
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 * Modified by the ObjGTK Team, 2021. See the AUTHORS file for a
 * list of people on the ObjGTK Team.
 * See the ChangeLog files for a list of changes.
 */

/*
 * Objective-C imports
 */
#import "OGTKToggleAction.h"

@implementation OGTKToggleAction

- (id)initWithName:(OFString*)name andLabel:(OFString*)label andTooltip:(OFString*)tooltip andStockId:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_toggle_action_new([name UTF8String], [label UTF8String], [tooltip UTF8String], [stockId UTF8String])];

	return self;
}

- (GtkToggleAction*)TOGGLEACTION
{
	return GTK_TOGGLE_ACTION([self GOBJECT]);
}

- (bool)getActive
{
	return gtk_toggle_action_get_active(GTK_TOGGLE_ACTION([self GOBJECT]));
}

- (bool)getDrawAsRadio
{
	return gtk_toggle_action_get_draw_as_radio(GTK_TOGGLE_ACTION([self GOBJECT]));
}

- (void)setActive:(bool)isActive
{
	gtk_toggle_action_set_active(GTK_TOGGLE_ACTION([self GOBJECT]), isActive);
}

- (void)setDrawAsRadio:(bool)drawAsRadio
{
	gtk_toggle_action_set_draw_as_radio(GTK_TOGGLE_ACTION([self GOBJECT]), drawAsRadio);
}

- (void)toggled
{
	gtk_toggle_action_toggled(GTK_TOGGLE_ACTION([self GOBJECT]));
}


@end