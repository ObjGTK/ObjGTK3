/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKToggleButton.h"

#import "OGTKWidget.h"

@implementation OGTKToggleButton

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_toggle_button_new()];

	return self;
}

- (instancetype)initWithLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_toggle_button_new_with_label([label UTF8String])];

	return self;
}

- (instancetype)initWithMnemonic:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_toggle_button_new_with_mnemonic([label UTF8String])];

	return self;
}

- (GtkToggleButton*)TOGGLEBUTTON
{
	return GTK_TOGGLE_BUTTON([self GOBJECT]);
}

- (bool)active
{
	return gtk_toggle_button_get_active([self TOGGLEBUTTON]);
}

- (bool)inconsistent
{
	return gtk_toggle_button_get_inconsistent([self TOGGLEBUTTON]);
}

- (bool)mode
{
	return gtk_toggle_button_get_mode([self TOGGLEBUTTON]);
}

- (void)setActive:(bool)isActive
{
	gtk_toggle_button_set_active([self TOGGLEBUTTON], isActive);
}

- (void)setInconsistent:(bool)setting
{
	gtk_toggle_button_set_inconsistent([self TOGGLEBUTTON], setting);
}

- (void)setMode:(bool)drawIndicator
{
	gtk_toggle_button_set_mode([self TOGGLEBUTTON], drawIndicator);
}

- (void)toggled
{
	gtk_toggle_button_toggled([self TOGGLEBUTTON]);
}


@end