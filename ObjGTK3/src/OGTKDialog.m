/*
 * SPDX-FileCopyrightText: 2015-2017 Tyler Burton <software@tylerburton.ca>
 * SPDX-FileCopyrightText: 2015-2022 The ObjGTK authors, see AUTHORS file
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#import "OGTKDialog.h"

#import "OGTKWidget.h"

@implementation OGTKDialog

- (instancetype)init
{
	self = [super initWithGObject:(GObject*)gtk_dialog_new()];

	return self;
}

- (GtkDialog*)DIALOG
{
	return GTK_DIALOG([self GOBJECT]);
}

- (void)addActionWidgetWithChild:(OGTKWidget*)child responseId:(gint)responseId
{
	gtk_dialog_add_action_widget([self DIALOG], [child WIDGET], responseId);
}

- (OGTKWidget*)addButtonWithButtonText:(OFString*)buttonText responseId:(gint)responseId
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_dialog_add_button([self DIALOG], [buttonText UTF8String], responseId)] autorelease];
}

- (OGTKWidget*)actionArea
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_dialog_get_action_area([self DIALOG])] autorelease];
}

- (OGTKWidget*)contentArea
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_dialog_get_content_area([self DIALOG])] autorelease];
}

- (OGTKWidget*)headerBar
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_dialog_get_header_bar([self DIALOG])] autorelease];
}

- (gint)responseForWidget:(OGTKWidget*)widget
{
	return gtk_dialog_get_response_for_widget([self DIALOG], [widget WIDGET]);
}

- (OGTKWidget*)widgetForResponse:(gint)responseId
{
	return [[[OGTKWidget alloc] initWithGObject:(GObject*)gtk_dialog_get_widget_for_response([self DIALOG], responseId)] autorelease];
}

- (void)response:(gint)responseId
{
	gtk_dialog_response([self DIALOG], responseId);
}

- (gint)run
{
	return gtk_dialog_run([self DIALOG]);
}

- (void)setAlternativeButtonOrderFromArrayWithNparams:(gint)nparams newOrder:(gint*)newOrder
{
	gtk_dialog_set_alternative_button_order_from_array([self DIALOG], nparams, newOrder);
}

- (void)setDefaultResponse:(gint)responseId
{
	gtk_dialog_set_default_response([self DIALOG], responseId);
}

- (void)setResponseSensitiveWithResponseId:(gint)responseId setting:(bool)setting
{
	gtk_dialog_set_response_sensitive([self DIALOG], responseId, setting);
}


@end