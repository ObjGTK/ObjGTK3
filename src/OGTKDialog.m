/*
 * OGTKDialog.m
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
#import "OGTKDialog.h"

@implementation OGTKDialog

- (id)initWithTitle:(OFString*)title andParent:(OGTKWindow*)parent andFlags:(GtkDialogFlags)flags andButtonTextResponseDictionary:(OFDictionary*)buttonTextDict
{
	self = [super initWithGObject:(GObject *)gtk_dialog_new_with_buttons([title UTF8String], [parent WINDOW], flags, NULL, NULL)];

	OGTKTypeWrapper *wrapper;
	for(OFString *text in buttonTextDict) {
		wrapper = [buttonTextDict objectForKey:text];
			
		[self addButtonWithButtonText:text andResponseId:wrapper.gintValue];
	}

	return self;
}

- (void)addButtons:(OFDictionary*)buttonTextDict
{
	OGTKTypeWrapper *wrapper;
	for(OFString *text in buttonTextDict) {
		wrapper = [buttonTextDict objectForKey:text];
		
		[self addButtonWithButtonText:text andResponseId:wrapper.gintValue];
	}
}

- (id)init
{
	self = [super initWithGObject:(GObject*)gtk_dialog_new()];

	return self;
}

- (GtkDialog*)DIALOG
{
	return GTK_DIALOG([self GOBJECT]);
}

- (void)addActionWidgetWithChild:(OGTKWidget*)child andResponseId:(gint)responseId
{
	gtk_dialog_add_action_widget(GTK_DIALOG([self GOBJECT]), [child WIDGET], responseId);
}

- (OGTKWidget*)addButtonWithButtonText:(OFString*)buttonText andResponseId:(gint)responseId
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_dialog_add_button(GTK_DIALOG([self GOBJECT]), [buttonText UTF8String], responseId)];
}

- (OGTKWidget*)getActionArea
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_dialog_get_action_area(GTK_DIALOG([self GOBJECT]))];
}

- (OGTKWidget*)getContentArea
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_dialog_get_content_area(GTK_DIALOG([self GOBJECT]))];
}

- (OGTKWidget*)getHeaderBar
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_dialog_get_header_bar(GTK_DIALOG([self GOBJECT]))];
}

- (gint)getResponseForWidget:(OGTKWidget*)widget
{
	return gtk_dialog_get_response_for_widget(GTK_DIALOG([self GOBJECT]), [widget WIDGET]);
}

- (OGTKWidget*)getWidgetForResponse:(gint)responseId
{
	return [[OGTKWidget alloc] initWithGObject:(GObject*)gtk_dialog_get_widget_for_response(GTK_DIALOG([self GOBJECT]), responseId)];
}

- (void)response:(gint)responseId
{
	gtk_dialog_response(GTK_DIALOG([self GOBJECT]), responseId);
}

- (gint)run
{
	return gtk_dialog_run(GTK_DIALOG([self GOBJECT]));
}

- (void)setAlternativeButtonOrderFromArrayWithNparams:(gint)nparams andNewOrder:(gint*)newOrder
{
	gtk_dialog_set_alternative_button_order_from_array(GTK_DIALOG([self GOBJECT]), nparams, newOrder);
}

- (void)setDefaultResponse:(gint)responseId
{
	gtk_dialog_set_default_response(GTK_DIALOG([self GOBJECT]), responseId);
}

- (void)setResponseSensitiveWithResponseId:(gint)responseId andSetting:(bool)setting
{
	gtk_dialog_set_response_sensitive(GTK_DIALOG([self GOBJECT]), responseId, setting);
}


@end