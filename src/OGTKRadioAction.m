/*
 * OGTKRadioAction.m
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
#import "OGTKRadioAction.h"

@implementation OGTKRadioAction

- (id)initWithName:(OFString*)name andLabel:(OFString*)label andTooltip:(OFString*)tooltip andStockId:(OFString*)stockId andValue:(gint)value
{
	self = [super initWithGObject:(GObject*)gtk_radio_action_new([name UTF8String], [label UTF8String], [tooltip UTF8String], [stockId UTF8String], value)];

	return self;
}

- (GtkRadioAction*)RADIOACTION
{
	return GTK_RADIO_ACTION([self GOBJECT]);
}

- (gint)getCurrentValue
{
	return gtk_radio_action_get_current_value(GTK_RADIO_ACTION([self GOBJECT]));
}

- (GSList*)getGroup
{
	return gtk_radio_action_get_group(GTK_RADIO_ACTION([self GOBJECT]));
}

- (void)joinGroup:(GtkRadioAction*)groupSource
{
	gtk_radio_action_join_group(GTK_RADIO_ACTION([self GOBJECT]), groupSource);
}

- (void)setCurrentValue:(gint)currentValue
{
	gtk_radio_action_set_current_value(GTK_RADIO_ACTION([self GOBJECT]), currentValue);
}

- (void)setGroup:(GSList*)group
{
	gtk_radio_action_set_group(GTK_RADIO_ACTION([self GOBJECT]), group);
}


@end