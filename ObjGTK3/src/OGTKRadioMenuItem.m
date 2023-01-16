/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKRadioMenuItem.h"

#import "OGTKWidget.h"

@implementation OGTKRadioMenuItem

- (instancetype)init:(GSList*)group
{
	self = [super initWithGObject:(GObject*)gtk_radio_menu_item_new(group)];

	return self;
}

- (instancetype)initFromWidget:(OGTKRadioMenuItem*)group
{
	self = [super initWithGObject:(GObject*)gtk_radio_menu_item_new_from_widget([group RADIOMENUITEM])];

	return self;
}

- (instancetype)initWithLabelWithGroup:(GSList*)group label:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_radio_menu_item_new_with_label(group, [label UTF8String])];

	return self;
}

- (instancetype)initWithLabelFromWidgetWithGroup:(OGTKRadioMenuItem*)group label:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_radio_menu_item_new_with_label_from_widget([group RADIOMENUITEM], [label UTF8String])];

	return self;
}

- (instancetype)initWithMnemonicWithGroup:(GSList*)group label:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_radio_menu_item_new_with_mnemonic(group, [label UTF8String])];

	return self;
}

- (instancetype)initWithMnemonicFromWidgetWithGroup:(OGTKRadioMenuItem*)group label:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_radio_menu_item_new_with_mnemonic_from_widget([group RADIOMENUITEM], [label UTF8String])];

	return self;
}

- (GtkRadioMenuItem*)RADIOMENUITEM
{
	return GTK_RADIO_MENU_ITEM([self GOBJECT]);
}

- (GSList*)group
{
	return gtk_radio_menu_item_get_group([self RADIOMENUITEM]);
}

- (void)joinGroup:(OGTKRadioMenuItem*)groupSource
{
	gtk_radio_menu_item_join_group([self RADIOMENUITEM], [groupSource RADIOMENUITEM]);
}

- (void)setGroup:(GSList*)group
{
	gtk_radio_menu_item_set_group([self RADIOMENUITEM], group);
}


@end