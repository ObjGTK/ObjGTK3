/*
 * OGTKAppChooserWidget.m
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
#import "OGTKAppChooserWidget.h"

@implementation OGTKAppChooserWidget

- (id)init:(OFString*)contentType
{
	self = [super initWithGObject:(GObject*)gtk_app_chooser_widget_new([contentType UTF8String])];

	return self;
}

- (GtkAppChooserWidget*)APPCHOOSERWIDGET
{
	return GTK_APP_CHOOSER_WIDGET([self GOBJECT]);
}

- (OFString*)getDefaultText
{
	return [OFString stringWithUTF8String:gtk_app_chooser_widget_get_default_text(GTK_APP_CHOOSER_WIDGET([self GOBJECT]))];
}

- (bool)getShowAll
{
	return gtk_app_chooser_widget_get_show_all(GTK_APP_CHOOSER_WIDGET([self GOBJECT]));
}

- (bool)getShowDefault
{
	return gtk_app_chooser_widget_get_show_default(GTK_APP_CHOOSER_WIDGET([self GOBJECT]));
}

- (bool)getShowFallback
{
	return gtk_app_chooser_widget_get_show_fallback(GTK_APP_CHOOSER_WIDGET([self GOBJECT]));
}

- (bool)getShowOther
{
	return gtk_app_chooser_widget_get_show_other(GTK_APP_CHOOSER_WIDGET([self GOBJECT]));
}

- (bool)getShowRecommended
{
	return gtk_app_chooser_widget_get_show_recommended(GTK_APP_CHOOSER_WIDGET([self GOBJECT]));
}

- (void)setDefaultText:(OFString*)text
{
	gtk_app_chooser_widget_set_default_text(GTK_APP_CHOOSER_WIDGET([self GOBJECT]), [text UTF8String]);
}

- (void)setShowAll:(bool)setting
{
	gtk_app_chooser_widget_set_show_all(GTK_APP_CHOOSER_WIDGET([self GOBJECT]), setting);
}

- (void)setShowDefault:(bool)setting
{
	gtk_app_chooser_widget_set_show_default(GTK_APP_CHOOSER_WIDGET([self GOBJECT]), setting);
}

- (void)setShowFallback:(bool)setting
{
	gtk_app_chooser_widget_set_show_fallback(GTK_APP_CHOOSER_WIDGET([self GOBJECT]), setting);
}

- (void)setShowOther:(bool)setting
{
	gtk_app_chooser_widget_set_show_other(GTK_APP_CHOOSER_WIDGET([self GOBJECT]), setting);
}

- (void)setShowRecommended:(bool)setting
{
	gtk_app_chooser_widget_set_show_recommended(GTK_APP_CHOOSER_WIDGET([self GOBJECT]), setting);
}


@end