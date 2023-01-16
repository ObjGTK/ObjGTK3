/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKInfoBar.h"

#import "OGTKWidget.h"

@implementation OGTKInfoBar

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_info_bar_new()];

	return self;
}

- (GtkInfoBar*)INFOBAR
{
	return GTK_INFO_BAR([self GOBJECT]);
}

- (void)addActionWidgetWithChild:(OGTKWidget*)child responseId:(gint)responseId
{
	gtk_info_bar_add_action_widget([self INFOBAR], [child WIDGET], responseId);
}

- (OGTKWidget*)addButtonWithButtonText:(OFString*)buttonText responseId:(gint)responseId
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_info_bar_add_button([self INFOBAR], [buttonText UTF8String], responseId)] autorelease];
}

- (OGTKWidget*)actionArea
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_info_bar_get_action_area([self INFOBAR])] autorelease];
}

- (OGTKWidget*)contentArea
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_info_bar_get_content_area([self INFOBAR])] autorelease];
}

- (GtkMessageType)messageType
{
	return gtk_info_bar_get_message_type([self INFOBAR]);
}

- (bool)revealed
{
	return gtk_info_bar_get_revealed([self INFOBAR]);
}

- (bool)showCloseButton
{
	return gtk_info_bar_get_show_close_button([self INFOBAR]);
}

- (void)response:(gint)responseId
{
	gtk_info_bar_response([self INFOBAR], responseId);
}

- (void)setDefaultResponse:(gint)responseId
{
	gtk_info_bar_set_default_response([self INFOBAR], responseId);
}

- (void)setMessageType:(GtkMessageType)messageType
{
	gtk_info_bar_set_message_type([self INFOBAR], messageType);
}

- (void)setResponseSensitiveWithResponseId:(gint)responseId setting:(bool)setting
{
	gtk_info_bar_set_response_sensitive([self INFOBAR], responseId, setting);
}

- (void)setRevealed:(bool)revealed
{
	gtk_info_bar_set_revealed([self INFOBAR], revealed);
}

- (void)setShowCloseButton:(bool)setting
{
	gtk_info_bar_set_show_close_button([self INFOBAR], setting);
}


@end