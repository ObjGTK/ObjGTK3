/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKMenuShell.h"

#import "OGTKWidget.h"

@implementation OGTKMenuShell

- (GtkMenuShell*)MENUSHELL
{
	return GTK_MENU_SHELL([self GOBJECT]);
}

- (void)activateItemWithMenuItem:(OGTKWidget*)menuItem forceDeactivate:(bool)forceDeactivate
{
	gtk_menu_shell_activate_item([self MENUSHELL], [menuItem WIDGET], forceDeactivate);
}

- (void)append:(OGTKWidget*)child
{
	gtk_menu_shell_append([self MENUSHELL], [child WIDGET]);
}

- (void)bindModelWithModel:(GMenuModel*)model actionNamespace:(OFString*)actionNamespace withSeparators:(bool)withSeparators
{
	gtk_menu_shell_bind_model([self MENUSHELL], model, [actionNamespace UTF8String], withSeparators);
}

- (void)cancel
{
	gtk_menu_shell_cancel([self MENUSHELL]);
}

- (void)deactivate
{
	gtk_menu_shell_deactivate([self MENUSHELL]);
}

- (void)deselect
{
	gtk_menu_shell_deselect([self MENUSHELL]);
}

- (OGTKWidget*)parentShell
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_shell_get_parent_shell([self MENUSHELL])] autorelease];
}

- (OGTKWidget*)selectedItem
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_shell_get_selected_item([self MENUSHELL])] autorelease];
}

- (bool)takeFocus
{
	return gtk_menu_shell_get_take_focus([self MENUSHELL]);
}

- (void)insertWithChild:(OGTKWidget*)child position:(gint)position
{
	gtk_menu_shell_insert([self MENUSHELL], [child WIDGET], position);
}

- (void)prepend:(OGTKWidget*)child
{
	gtk_menu_shell_prepend([self MENUSHELL], [child WIDGET]);
}

- (void)selectFirst:(bool)searchSensitive
{
	gtk_menu_shell_select_first([self MENUSHELL], searchSensitive);
}

- (void)selectItem:(OGTKWidget*)menuItem
{
	gtk_menu_shell_select_item([self MENUSHELL], [menuItem WIDGET]);
}

- (void)setTakeFocus:(bool)takeFocus
{
	gtk_menu_shell_set_take_focus([self MENUSHELL], takeFocus);
}


@end