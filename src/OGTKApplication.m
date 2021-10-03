/*
 * OGTKApplication.m
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
#import "OGTKApplication.h"

@implementation OGTKApplication

- (id)initWithApplicationId:(OFString*)applicationId andFlags:(GApplicationFlags)flags
{
	self = [super initWithGObject:(GObject*)gtk_application_new([applicationId UTF8String], flags)];

	return self;
}

- (GtkApplication*)APPLICATION
{
	return GTK_APPLICATION([self GOBJECT]);
}

- (void)addAcceleratorWithAccelerator:(OFString*)accelerator andActionName:(OFString*)actionName andParameter:(GVariant*)parameter
{
	gtk_application_add_accelerator(GTK_APPLICATION([self GOBJECT]), [accelerator UTF8String], [actionName UTF8String], parameter);
}

- (void)addWindow:(GtkWindow*)window
{
	gtk_application_add_window(GTK_APPLICATION([self GOBJECT]), window);
}

- (gchar**)getAccelsForAction:(OFString*)detailedActionName
{
	return gtk_application_get_accels_for_action(GTK_APPLICATION([self GOBJECT]), [detailedActionName UTF8String]);
}

- (gchar**)getActionsForAccel:(OFString*)accel
{
	return gtk_application_get_actions_for_accel(GTK_APPLICATION([self GOBJECT]), [accel UTF8String]);
}

- (GtkWindow*)getActiveWindow
{
	return gtk_application_get_active_window(GTK_APPLICATION([self GOBJECT]));
}

- (GMenuModel*)getAppMenu
{
	return gtk_application_get_app_menu(GTK_APPLICATION([self GOBJECT]));
}

- (GMenu*)getMenuById:(OFString*)id
{
	return gtk_application_get_menu_by_id(GTK_APPLICATION([self GOBJECT]), [id UTF8String]);
}

- (GMenuModel*)getMenubar
{
	return gtk_application_get_menubar(GTK_APPLICATION([self GOBJECT]));
}

- (GtkWindow*)getWindowById:(guint)id
{
	return gtk_application_get_window_by_id(GTK_APPLICATION([self GOBJECT]), id);
}

- (GList*)getWindows
{
	return gtk_application_get_windows(GTK_APPLICATION([self GOBJECT]));
}

- (guint)inhibitWithWindow:(GtkWindow*)window andFlags:(GtkApplicationInhibitFlags)flags andReason:(OFString*)reason
{
	return gtk_application_inhibit(GTK_APPLICATION([self GOBJECT]), window, flags, [reason UTF8String]);
}

- (bool)isInhibited:(GtkApplicationInhibitFlags)flags
{
	return gtk_application_is_inhibited(GTK_APPLICATION([self GOBJECT]), flags);
}

- (gchar**)listActionDescriptions
{
	return gtk_application_list_action_descriptions(GTK_APPLICATION([self GOBJECT]));
}

- (bool)prefersAppMenu
{
	return gtk_application_prefers_app_menu(GTK_APPLICATION([self GOBJECT]));
}

- (void)removeAcceleratorWithActionName:(OFString*)actionName andParameter:(GVariant*)parameter
{
	gtk_application_remove_accelerator(GTK_APPLICATION([self GOBJECT]), [actionName UTF8String], parameter);
}

- (void)removeWindow:(GtkWindow*)window
{
	gtk_application_remove_window(GTK_APPLICATION([self GOBJECT]), window);
}

- (void)setAccelsForActionWithDetailedActionName:(OFString*)detailedActionName andAccels:(const gchar* const*)accels
{
	gtk_application_set_accels_for_action(GTK_APPLICATION([self GOBJECT]), [detailedActionName UTF8String], accels);
}

- (void)setAppMenu:(GMenuModel*)appMenu
{
	gtk_application_set_app_menu(GTK_APPLICATION([self GOBJECT]), appMenu);
}

- (void)setMenubar:(GMenuModel*)menubar
{
	gtk_application_set_menubar(GTK_APPLICATION([self GOBJECT]), menubar);
}

- (void)uninhibit:(guint)cookie
{
	gtk_application_uninhibit(GTK_APPLICATION([self GOBJECT]), cookie);
}


@end