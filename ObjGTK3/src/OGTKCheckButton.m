/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKCheckButton.h"

#import "OGTKWidget.h"

@implementation OGTKCheckButton

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_check_button_new()];

	return self;
}

- (instancetype)initWithLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_check_button_new_with_label([label UTF8String])];

	return self;
}

- (instancetype)initWithMnemonic:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_check_button_new_with_mnemonic([label UTF8String])];

	return self;
}

- (GtkCheckButton*)CHECKBUTTON
{
	return GTK_CHECK_BUTTON([self GOBJECT]);
}


@end