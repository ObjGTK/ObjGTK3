/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKApplication.h"

#import "OGTKWindow.h"

@implementation OGTKApplication

- (instancetype)initWithApplicationId:(OFString*)applicationId flags:(GApplicationFlags)flags
{
	self = [super initWithGObject:(GObject*)gtk_application_new([applicationId UTF8String], flags)];

	return self;
}

- (GtkApplication*)APPLICATION
{
	return GTK_APPLICATION([self GOBJECT]);
}

- (void)addAcceleratorWithAccelerator:(OFString*)accelerator actionName:(OFString*)actionName parameter:(GVariant*)parameter
{
	gtk_application_add_accelerator([self APPLICATION], [accelerator UTF8String], [actionName UTF8String], parameter);
}

- (void)addWindow:(OGTKWindow*)window
{
	gtk_application_add_window([self APPLICATION], [window WINDOW]);
}

- (gchar**)accelsForAction:(OFString*)detailedActionName
{
	return gtk_application_get_accels_for_action([self APPLICATION], [detailedActionName UTF8String]);
}

- (gchar**)actionsForAccel:(OFString*)accel
{
	return gtk_application_get_actions_for_accel([self APPLICATION], [accel UTF8String]);
}

- (OGTKWindow*)activeWindow
{
	return [[[OGTKWindow alloc] initWithGObject:(GObject*)gtk_application_get_active_window([self APPLICATION])] autorelease];
}

- (GMenuModel*)appMenu
{
	return gtk_application_get_app_menu([self APPLICATION]);
}

- (GMenu*)menuById:(OFString*)id
{
	return gtk_application_get_menu_by_id([self APPLICATION], [id UTF8String]);
}

- (GMenuModel*)menubar
{
	return gtk_application_get_menubar([self APPLICATION]);
}

- (OGTKWindow*)windowById:(guint)id
{
	return [[[OGTKWindow alloc] initWithGObject:(GObject*)gtk_application_get_window_by_id([self APPLICATION], id)] autorelease];
}

- (GList*)windows
{
	return gtk_application_get_windows([self APPLICATION]);
}

- (guint)inhibitWithWindow:(OGTKWindow*)window flags:(GtkApplicationInhibitFlags)flags reason:(OFString*)reason
{
	return gtk_application_inhibit([self APPLICATION], [window WINDOW], flags, [reason UTF8String]);
}

- (bool)isInhibited:(GtkApplicationInhibitFlags)flags
{
	return gtk_application_is_inhibited([self APPLICATION], flags);
}

- (gchar**)listActionDescriptions
{
	return gtk_application_list_action_descriptions([self APPLICATION]);
}

- (bool)prefersAppMenu
{
	return gtk_application_prefers_app_menu([self APPLICATION]);
}

- (void)removeAcceleratorWithActionName:(OFString*)actionName parameter:(GVariant*)parameter
{
	gtk_application_remove_accelerator([self APPLICATION], [actionName UTF8String], parameter);
}

- (void)removeWindow:(OGTKWindow*)window
{
	gtk_application_remove_window([self APPLICATION], [window WINDOW]);
}

- (void)setAccelsForActionWithDetailedActionName:(OFString*)detailedActionName accels:(const gchar* const*)accels
{
	gtk_application_set_accels_for_action([self APPLICATION], [detailedActionName UTF8String], accels);
}

- (void)setAppMenu:(GMenuModel*)appMenu
{
	gtk_application_set_app_menu([self APPLICATION], appMenu);
}

- (void)setMenubar:(GMenuModel*)menubar
{
	gtk_application_set_menubar([self APPLICATION], menubar);
}

- (void)uninhibit:(guint)cookie
{
	gtk_application_uninhibit([self APPLICATION], cookie);
}


@end