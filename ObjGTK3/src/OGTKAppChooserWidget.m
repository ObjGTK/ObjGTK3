/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKAppChooserWidget.h"

#import "OGTKWidget.h"

@implementation OGTKAppChooserWidget

- (instancetype)init:(OFString*)contentType
{
	self = [super initWithGObject:(GObject*)gtk_app_chooser_widget_new([contentType UTF8String])];

	return self;
}

- (GtkAppChooserWidget*)APPCHOOSERWIDGET
{
	return GTK_APP_CHOOSER_WIDGET([self GOBJECT]);
}

- (OFString*)defaultText
{
	return [OFString stringWithUTF8String:gtk_app_chooser_widget_get_default_text([self APPCHOOSERWIDGET])];
}

- (bool)showAll
{
	return gtk_app_chooser_widget_get_show_all([self APPCHOOSERWIDGET]);
}

- (bool)showDefault
{
	return gtk_app_chooser_widget_get_show_default([self APPCHOOSERWIDGET]);
}

- (bool)showFallback
{
	return gtk_app_chooser_widget_get_show_fallback([self APPCHOOSERWIDGET]);
}

- (bool)showOther
{
	return gtk_app_chooser_widget_get_show_other([self APPCHOOSERWIDGET]);
}

- (bool)showRecommended
{
	return gtk_app_chooser_widget_get_show_recommended([self APPCHOOSERWIDGET]);
}

- (void)setDefaultText:(OFString*)text
{
	gtk_app_chooser_widget_set_default_text([self APPCHOOSERWIDGET], [text UTF8String]);
}

- (void)setShowAll:(bool)setting
{
	gtk_app_chooser_widget_set_show_all([self APPCHOOSERWIDGET], setting);
}

- (void)setShowDefault:(bool)setting
{
	gtk_app_chooser_widget_set_show_default([self APPCHOOSERWIDGET], setting);
}

- (void)setShowFallback:(bool)setting
{
	gtk_app_chooser_widget_set_show_fallback([self APPCHOOSERWIDGET], setting);
}

- (void)setShowOther:(bool)setting
{
	gtk_app_chooser_widget_set_show_other([self APPCHOOSERWIDGET], setting);
}

- (void)setShowRecommended:(bool)setting
{
	gtk_app_chooser_widget_set_show_recommended([self APPCHOOSERWIDGET], setting);
}


@end