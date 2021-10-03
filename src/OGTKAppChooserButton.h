/*
 * OGTKAppChooserButton.h
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
#import "OGTKComboBox.h"

@interface OGTKAppChooserButton : OGTKComboBox
{

}


/**
 * Constructors
 */
- (id)init:(OFString*)contentType;

/**
 * Methods
 */

- (GtkAppChooserButton*)APPCHOOSERBUTTON;

/**
 * - (void*)appendCustomItemWithName:(OFString*)name andLabel:(OFString*)label andIcon:(GIcon*)icon;
 *
 * @param name
 * @param label
 * @param icon
 */
- (void)appendCustomItemWithName:(OFString*)name andLabel:(OFString*)label andIcon:(GIcon*)icon;

/**
 * - (void*)appendSeparator;
 *
 */
- (void)appendSeparator;

/**
 * - (OFString**)getHeading;
 *
 * @returns OFString*
 */
- (OFString*)getHeading;

/**
 * - (bool*)getShowDefaultItem;
 *
 * @returns bool
 */
- (bool)getShowDefaultItem;

/**
 * - (bool*)getShowDialogItem;
 *
 * @returns bool
 */
- (bool)getShowDialogItem;

/**
 * - (void*)setActiveCustomItem:(OFString*)name;
 *
 * @param name
 */
- (void)setActiveCustomItem:(OFString*)name;

/**
 * - (void*)setHeading:(OFString*)heading;
 *
 * @param heading
 */
- (void)setHeading:(OFString*)heading;

/**
 * - (void*)setShowDefaultItem:(bool)setting;
 *
 * @param setting
 */
- (void)setShowDefaultItem:(bool)setting;

/**
 * - (void*)setShowDialogItem:(bool)setting;
 *
 * @param setting
 */
- (void)setShowDialogItem:(bool)setting;

@end