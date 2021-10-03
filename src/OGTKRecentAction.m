/*
 * OGTKRecentAction.m
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
#import "OGTKRecentAction.h"

@implementation OGTKRecentAction

- (id)initWithName:(OFString*)name andLabel:(OFString*)label andTooltip:(OFString*)tooltip andStockId:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_recent_action_new([name UTF8String], [label UTF8String], [tooltip UTF8String], [stockId UTF8String])];

	return self;
}

- (id)initForManagerWithName:(OFString*)name andLabel:(OFString*)label andTooltip:(OFString*)tooltip andStockId:(OFString*)stockId andManager:(GtkRecentManager*)manager
{
	self = [super initWithGObject:(GObject*)gtk_recent_action_new_for_manager([name UTF8String], [label UTF8String], [tooltip UTF8String], [stockId UTF8String], manager)];

	return self;
}

- (GtkRecentAction*)RECENTACTION
{
	return GTK_RECENT_ACTION([self GOBJECT]);
}

- (bool)getShowNumbers
{
	return gtk_recent_action_get_show_numbers(GTK_RECENT_ACTION([self GOBJECT]));
}

- (void)setShowNumbers:(bool)showNumbers
{
	gtk_recent_action_set_show_numbers(GTK_RECENT_ACTION([self GOBJECT]), showNumbers);
}


@end