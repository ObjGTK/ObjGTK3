/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRadioAction.h"

@implementation OGTKRadioAction

- (instancetype)initWithName:(OFString*)name label:(OFString*)label tooltip:(OFString*)tooltip stockId:(OFString*)stockId value:(gint)value
{
	self = [super initWithGObject:(GObject*)gtk_radio_action_new([name UTF8String], [label UTF8String], [tooltip UTF8String], [stockId UTF8String], value)];

	return self;
}

- (GtkRadioAction*)RADIOACTION
{
	return GTK_RADIO_ACTION([self GOBJECT]);
}

- (gint)currentValue
{
	return gtk_radio_action_get_current_value([self RADIOACTION]);
}

- (GSList*)group
{
	return gtk_radio_action_get_group([self RADIOACTION]);
}

- (void)joinGroup:(OGTKRadioAction*)groupSource
{
	gtk_radio_action_join_group([self RADIOACTION], [groupSource RADIOACTION]);
}

- (void)setCurrentValue:(gint)currentValue
{
	gtk_radio_action_set_current_value([self RADIOACTION], currentValue);
}

- (void)setGroup:(GSList*)group
{
	gtk_radio_action_set_group([self RADIOACTION], group);
}


@end