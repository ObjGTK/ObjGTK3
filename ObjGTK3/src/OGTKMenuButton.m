/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenuButton.h"

#import "OGTKMenu.h"
#import "OGTKWidget.h"
#import "OGTKPopover.h"

@implementation OGTKMenuButton

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_menu_button_new()];

	return self;
}

- (GtkMenuButton*)MENUBUTTON
{
	return GTK_MENU_BUTTON([self GOBJECT]);
}

- (OGTKWidget*)alignWidget
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_button_get_align_widget([self MENUBUTTON])] autorelease];
}

- (GtkArrowType)direction
{
	return gtk_menu_button_get_direction([self MENUBUTTON]);
}

- (GMenuModel*)menuModel
{
	return gtk_menu_button_get_menu_model([self MENUBUTTON]);
}

- (OGTKPopover*)popover
{
	return [[[OGTKPopover alloc] initWithGObject:(GObject*)gtk_menu_button_get_popover([self MENUBUTTON])] autorelease];
}

- (OGTKMenu*)popup
{
	return [[[OGTKMenu alloc] initWithGObject:(GObject*)gtk_menu_button_get_popup([self MENUBUTTON])] autorelease];
}

- (bool)usePopover
{
	return gtk_menu_button_get_use_popover([self MENUBUTTON]);
}

- (void)setAlignWidget:(OGTKWidget*)alignWidget
{
	gtk_menu_button_set_align_widget([self MENUBUTTON], [alignWidget WIDGET]);
}

- (void)setDirection:(GtkArrowType)direction
{
	gtk_menu_button_set_direction([self MENUBUTTON], direction);
}

- (void)setMenuModel:(GMenuModel*)menuModel
{
	gtk_menu_button_set_menu_model([self MENUBUTTON], menuModel);
}

- (void)setPopover:(OGTKWidget*)popover
{
	gtk_menu_button_set_popover([self MENUBUTTON], [popover WIDGET]);
}

- (void)setPopup:(OGTKWidget*)menu
{
	gtk_menu_button_set_popup([self MENUBUTTON], [menu WIDGET]);
}

- (void)setUsePopover:(bool)usePopover
{
	gtk_menu_button_set_use_popover([self MENUBUTTON], usePopover);
}


@end