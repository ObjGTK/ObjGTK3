/*
 * OGTKComboBoxText.h
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

@interface OGTKComboBoxText : OGTKComboBox
{

}


/**
 * Constructors
 */
- (id)init;
- (id)initWithEntry;

/**
 * Methods
 */

- (GtkComboBoxText*)COMBOBOXTEXT;

/**
 * - (void*)appendWithId:(OFString*)id andText:(OFString*)text;
 *
 * @param id
 * @param text
 */
- (void)appendWithId:(OFString*)id andText:(OFString*)text;

/**
 * - (void*)appendText:(OFString*)text;
 *
 * @param text
 */
- (void)appendText:(OFString*)text;

/**
 * - (OFString**)getActiveText;
 *
 * @returns OFString*
 */
- (OFString*)getActiveText;

/**
 * - (void*)insertWithPosition:(gint)position andId:(OFString*)id andText:(OFString*)text;
 *
 * @param position
 * @param id
 * @param text
 */
- (void)insertWithPosition:(gint)position andId:(OFString*)id andText:(OFString*)text;

/**
 * - (void*)insertTextWithPosition:(gint)position andText:(OFString*)text;
 *
 * @param position
 * @param text
 */
- (void)insertTextWithPosition:(gint)position andText:(OFString*)text;

/**
 * - (void*)prependWithId:(OFString*)id andText:(OFString*)text;
 *
 * @param id
 * @param text
 */
- (void)prependWithId:(OFString*)id andText:(OFString*)text;

/**
 * - (void*)prependText:(OFString*)text;
 *
 * @param text
 */
- (void)prependText:(OFString*)text;

/**
 * - (void*)remove:(gint)position;
 *
 * @param position
 */
- (void)remove:(gint)position;

/**
 * - (void*)removeAll;
 *
 */
- (void)removeAll;

@end