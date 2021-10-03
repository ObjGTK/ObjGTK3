/*
 * OGTKDialog.h
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
#import "OGTKWindow.h"

@interface OGTKDialog : OGTKWindow
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkDialog*)DIALOG;

- (id)initWithTitle:(OFString*)title andParent:(OGTKWindow*)parent andFlags:(GtkDialogFlags)flags andButtonTextResponseDictionary:(OFDictionary*)buttonTextDict;

- (void)addButtons:(OFDictionary*)buttonTextDict;

/**
 * - (void*)addActionWidgetWithChild:(OGTKWidget*)child andResponseId:(gint)responseId;
 *
 * @param child
 * @param responseId
 */
- (void)addActionWidgetWithChild:(OGTKWidget*)child andResponseId:(gint)responseId;

/**
 * - (OGTKWidget**)addButtonWithButtonText:(OFString*)buttonText andResponseId:(gint)responseId;
 *
 * @param buttonText
 * @param responseId
 * @returns OGTKWidget*
 */
- (OGTKWidget*)addButtonWithButtonText:(OFString*)buttonText andResponseId:(gint)responseId;

/**
 * - (OGTKWidget**)getActionArea;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getActionArea;

/**
 * - (OGTKWidget**)getContentArea;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getContentArea;

/**
 * - (OGTKWidget**)getHeaderBar;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getHeaderBar;

/**
 * - (gint*)getResponseForWidget:(OGTKWidget*)widget;
 *
 * @param widget
 * @returns gint
 */
- (gint)getResponseForWidget:(OGTKWidget*)widget;

/**
 * - (OGTKWidget**)getWidgetForResponse:(gint)responseId;
 *
 * @param responseId
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getWidgetForResponse:(gint)responseId;

/**
 * - (void*)response:(gint)responseId;
 *
 * @param responseId
 */
- (void)response:(gint)responseId;

/**
 * - (gint*)run;
 *
 * @returns gint
 */
- (gint)run;

/**
 * - (void*)setAlternativeButtonOrderFromArrayWithNparams:(gint)nparams andNewOrder:(gint*)newOrder;
 *
 * @param nparams
 * @param newOrder
 */
- (void)setAlternativeButtonOrderFromArrayWithNparams:(gint)nparams andNewOrder:(gint*)newOrder;

/**
 * - (void*)setDefaultResponse:(gint)responseId;
 *
 * @param responseId
 */
- (void)setDefaultResponse:(gint)responseId;

/**
 * - (void*)setResponseSensitiveWithResponseId:(gint)responseId andSetting:(bool)setting;
 *
 * @param responseId
 * @param setting
 */
- (void)setResponseSensitiveWithResponseId:(gint)responseId andSetting:(bool)setting;

@end