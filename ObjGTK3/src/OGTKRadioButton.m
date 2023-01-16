/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRadioButton.h"

#import "OGTKWidget.h"

@implementation OGTKRadioButton

- (instancetype)init:(GSList*)group
{
	self = [super initWithGObject:(GObject*)gtk_radio_button_new(group)];

	return self;
}

- (instancetype)initFromWidget:(OGTKRadioButton*)radioGroupMember
{
	self = [super initWithGObject:(GObject*)gtk_radio_button_new_from_widget([radioGroupMember RADIOBUTTON])];

	return self;
}

- (instancetype)initWithLabelWithGroup:(GSList*)group label:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_radio_button_new_with_label(group, [label UTF8String])];

	return self;
}

- (instancetype)initWithLabelFromWidgetWithRadioGroupMember:(OGTKRadioButton*)radioGroupMember label:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_radio_button_new_with_label_from_widget([radioGroupMember RADIOBUTTON], [label UTF8String])];

	return self;
}

- (instancetype)initWithMnemonicWithGroup:(GSList*)group label:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_radio_button_new_with_mnemonic(group, [label UTF8String])];

	return self;
}

- (instancetype)initWithMnemonicFromWidgetWithRadioGroupMember:(OGTKRadioButton*)radioGroupMember label:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_radio_button_new_with_mnemonic_from_widget([radioGroupMember RADIOBUTTON], [label UTF8String])];

	return self;
}

- (GtkRadioButton*)RADIOBUTTON
{
	return GTK_RADIO_BUTTON([self GOBJECT]);
}

- (GSList*)group
{
	return gtk_radio_button_get_group([self RADIOBUTTON]);
}

- (void)joinGroup:(OGTKRadioButton*)groupSource
{
	gtk_radio_button_join_group([self RADIOBUTTON], [groupSource RADIOBUTTON]);
}

- (void)setGroup:(GSList*)group
{
	gtk_radio_button_set_group([self RADIOBUTTON], group);
}


@end