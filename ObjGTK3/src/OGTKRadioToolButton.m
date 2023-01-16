/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRadioToolButton.h"

#import "OGTKToolItem.h"

@implementation OGTKRadioToolButton

- (instancetype)init:(GSList*)group
{
	self = [super initWithGObject:(GObject*)gtk_radio_tool_button_new(group)];

	return self;
}

- (instancetype)initFromStockWithGroup:(GSList*)group stockId:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_radio_tool_button_new_from_stock(group, [stockId UTF8String])];

	return self;
}

- (instancetype)initFromWidget:(OGTKRadioToolButton*)group
{
	self = [super initWithGObject:(GObject*)gtk_radio_tool_button_new_from_widget([group RADIOTOOLBUTTON])];

	return self;
}

- (instancetype)initWithStockFromWidgetWithGroup:(OGTKRadioToolButton*)group stockId:(OFString*)stockId
{
	self = [super initWithGObject:(GObject*)gtk_radio_tool_button_new_with_stock_from_widget([group RADIOTOOLBUTTON], [stockId UTF8String])];

	return self;
}

- (GtkRadioToolButton*)RADIOTOOLBUTTON
{
	return GTK_RADIO_TOOL_BUTTON([self GOBJECT]);
}

- (GSList*)group
{
	return gtk_radio_tool_button_get_group([self RADIOTOOLBUTTON]);
}

- (void)setGroup:(GSList*)group
{
	gtk_radio_tool_button_set_group([self RADIOTOOLBUTTON], group);
}


@end