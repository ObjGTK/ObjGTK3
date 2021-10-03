/*
 * OGTKHeaderBar.h
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
#import "OGTKContainer.h"

@interface OGTKHeaderBar : OGTKContainer
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkHeaderBar*)HEADERBAR;

/**
 * - (OGTKWidget**)getCustomTitle;
 *
 * @returns OGTKWidget*
 */
- (OGTKWidget*)getCustomTitle;

/**
 * - (OFString**)getDecorationLayout;
 *
 * @returns OFString*
 */
- (OFString*)getDecorationLayout;

/**
 * - (bool*)getHasSubtitle;
 *
 * @returns bool
 */
- (bool)getHasSubtitle;

/**
 * - (bool*)getShowCloseButton;
 *
 * @returns bool
 */
- (bool)getShowCloseButton;

/**
 * - (OFString**)getSubtitle;
 *
 * @returns OFString*
 */
- (OFString*)getSubtitle;

/**
 * - (OFString**)getTitle;
 *
 * @returns OFString*
 */
- (OFString*)getTitle;

/**
 * - (void*)packEnd:(OGTKWidget*)child;
 *
 * @param child
 */
- (void)packEnd:(OGTKWidget*)child;

/**
 * - (void*)packStart:(OGTKWidget*)child;
 *
 * @param child
 */
- (void)packStart:(OGTKWidget*)child;

/**
 * - (void*)setCustomTitle:(OGTKWidget*)titleWidget;
 *
 * @param titleWidget
 */
- (void)setCustomTitle:(OGTKWidget*)titleWidget;

/**
 * - (void*)setDecorationLayout:(OFString*)layout;
 *
 * @param layout
 */
- (void)setDecorationLayout:(OFString*)layout;

/**
 * - (void*)setHasSubtitle:(bool)setting;
 *
 * @param setting
 */
- (void)setHasSubtitle:(bool)setting;

/**
 * - (void*)setShowCloseButton:(bool)setting;
 *
 * @param setting
 */
- (void)setShowCloseButton:(bool)setting;

/**
 * - (void*)setSubtitle:(OFString*)subtitle;
 *
 * @param subtitle
 */
- (void)setSubtitle:(OFString*)subtitle;

/**
 * - (void*)setTitle:(OFString*)title;
 *
 * @param title
 */
- (void)setTitle:(OFString*)title;

@end