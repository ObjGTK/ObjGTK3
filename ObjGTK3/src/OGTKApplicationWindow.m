/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKApplicationWindow.h"

#import "OGTKShortcutsWindow.h"
#import "OGTKWidget.h"
#import "OGTKApplication.h"

@implementation OGTKApplicationWindow

- (instancetype)init:(OGTKApplication*)application
{
	self = [super initWithGObject:(GObject*)gtk_application_window_new([application APPLICATION])];

	return self;
}

- (GtkApplicationWindow*)APPLICATIONWINDOW
{
	return GTK_APPLICATION_WINDOW([self GOBJECT]);
}

- (OGTKShortcutsWindow*)helpOverlay
{
	return [[[OGTKShortcutsWindow alloc] initWithGObject:(GObject*)gtk_application_window_get_help_overlay([self APPLICATIONWINDOW])] autorelease];
}

- (guint)id
{
	return gtk_application_window_get_id([self APPLICATIONWINDOW]);
}

- (bool)showMenubar
{
	return gtk_application_window_get_show_menubar([self APPLICATIONWINDOW]);
}

- (void)setHelpOverlay:(OGTKShortcutsWindow*)helpOverlay
{
	gtk_application_window_set_help_overlay([self APPLICATIONWINDOW], [helpOverlay SHORTCUTSWINDOW]);
}

- (void)setShowMenubar:(bool)showMenubar
{
	gtk_application_window_set_show_menubar([self APPLICATIONWINDOW], showMenubar);
}


@end