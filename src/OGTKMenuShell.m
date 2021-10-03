/*
 * OGTKMenuShell.m
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
#import "OGTKMenuShell.h"

@implementation OGTKMenuShell

- (GtkMenuShell*)MENUSHELL
{
	return GTK_MENU_SHELL([self GOBJECT]);
}

- (void)activateItemWithMenuItem:(OGTKWidget*)menuItem andForceDeactivate:(bool)forceDeactivate
{
	gtk_menu_shell_activate_item(GTK_MENU_SHELL([self GOBJECT]), [menuItem WIDGET], forceDeactivate);
}

- (void)append:(OGTKWidget*)child
{
	gtk_menu_shell_append(GTK_MENU_SHELL([self GOBJECT]), [child WIDGET]);
}

- (void)bindModelWithModel:(GMenuModel*)model andActionNamespace:(OFString*)actionNamespace andWithSeparators:(bool)withSeparators
{
	gtk_menu_shell_bind_model(GTK_MENU_SHELL([self GOBJECT]), model, [actionNamespace UTF8String], withSeparators);
}

- (void)cancel
{
	gtk_menu_shell_cancel(GTK_MENU_SHELL([self GOBJECT]));
}

- (void)deactivate
{
	gtk_menu_shell_deactivate(GTK_MENU_SHELL([self GOBJECT]));
}

- (void)deselect
{
	gtk_menu_shell_deselect(GTK_MENU_SHELL([self GOBJECT]));
}

- (OGTKWidget*)getParentShell
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_shell_get_parent_shell(GTK_MENU_SHELL([self GOBJECT]))];
}

- (OGTKWidget*)getSelectedItem
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_menu_shell_get_selected_item(GTK_MENU_SHELL([self GOBJECT]))];
}

- (bool)getTakeFocus
{
	return gtk_menu_shell_get_take_focus(GTK_MENU_SHELL([self GOBJECT]));
}

- (void)insertWithChild:(OGTKWidget*)child andPosition:(gint)position
{
	gtk_menu_shell_insert(GTK_MENU_SHELL([self GOBJECT]), [child WIDGET], position);
}

- (void)prepend:(OGTKWidget*)child
{
	gtk_menu_shell_prepend(GTK_MENU_SHELL([self GOBJECT]), [child WIDGET]);
}

- (void)selectFirst:(bool)searchSensitive
{
	gtk_menu_shell_select_first(GTK_MENU_SHELL([self GOBJECT]), searchSensitive);
}

- (void)selectItem:(OGTKWidget*)menuItem
{
	gtk_menu_shell_select_item(GTK_MENU_SHELL([self GOBJECT]), [menuItem WIDGET]);
}

- (void)setTakeFocus:(bool)takeFocus
{
	gtk_menu_shell_set_take_focus(GTK_MENU_SHELL([self GOBJECT]), takeFocus);
}


@end