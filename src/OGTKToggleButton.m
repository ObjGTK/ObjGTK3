/*
 * OGTKToggleButton.m
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
#import "OGTKToggleButton.h"

@implementation OGTKToggleButton

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_toggle_button_new()];

	return self;
}

- (id)initWithLabel:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_toggle_button_new_with_label([label UTF8String])];

	return self;
}

- (id)initWithMnemonic:(OFString*)label
{
	self = [super initWithGObject:(GObject*)gtk_toggle_button_new_with_mnemonic([label UTF8String])];

	return self;
}

- (GtkToggleButton*)TOGGLEBUTTON
{
	return GTK_TOGGLE_BUTTON([self GOBJECT]);
}

- (bool)getActive
{
	return gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON([self GOBJECT]));
}

- (bool)getInconsistent
{
	return gtk_toggle_button_get_inconsistent(GTK_TOGGLE_BUTTON([self GOBJECT]));
}

- (bool)getMode
{
	return gtk_toggle_button_get_mode(GTK_TOGGLE_BUTTON([self GOBJECT]));
}

- (void)setActive:(bool)isActive
{
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON([self GOBJECT]), isActive);
}

- (void)setInconsistent:(bool)setting
{
	gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON([self GOBJECT]), setting);
}

- (void)setMode:(bool)drawIndicator
{
	gtk_toggle_button_set_mode(GTK_TOGGLE_BUTTON([self GOBJECT]), drawIndicator);
}

- (void)toggled
{
	gtk_toggle_button_toggled(GTK_TOGGLE_BUTTON([self GOBJECT]));
}


@end