/*
 * OGTKInfoBar.h
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
#import "OGTKBox.h"

@interface OGTKInfoBar : OGTKBox
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkInfoBar*)INFOBAR;

- (id)initWithButtonTextResponseDictionary:(OFDictionary*)buttonTextDict;

- (void)addButtonTextResponseDictionary:(OFDictionary*)buttonTextDict;

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
 * - (GtkMessageType*)getMessageType;
 *
 * @returns GtkMessageType
 */
- (GtkMessageType)getMessageType;

/**
 * - (bool*)getRevealed;
 *
 * @returns bool
 */
- (bool)getRevealed;

/**
 * - (bool*)getShowCloseButton;
 *
 * @returns bool
 */
- (bool)getShowCloseButton;

/**
 * - (void*)response:(gint)responseId;
 *
 * @param responseId
 */
- (void)response:(gint)responseId;

/**
 * - (void*)setDefaultResponse:(gint)responseId;
 *
 * @param responseId
 */
- (void)setDefaultResponse:(gint)responseId;

/**
 * - (void*)setMessageType:(GtkMessageType)messageType;
 *
 * @param messageType
 */
- (void)setMessageType:(GtkMessageType)messageType;

/**
 * - (void*)setResponseSensitiveWithResponseId:(gint)responseId andSetting:(bool)setting;
 *
 * @param responseId
 * @param setting
 */
- (void)setResponseSensitiveWithResponseId:(gint)responseId andSetting:(bool)setting;

/**
 * - (void*)setRevealed:(bool)revealed;
 *
 * @param revealed
 */
- (void)setRevealed:(bool)revealed;

/**
 * - (void*)setShowCloseButton:(bool)setting;
 *
 * @param setting
 */
- (void)setShowCloseButton:(bool)setting;

@end