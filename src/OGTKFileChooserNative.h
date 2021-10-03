/*
 * OGTKFileChooserNative.h
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
#import "OGTKNativeDialog.h"

@interface OGTKFileChooserNative : OGTKNativeDialog
{

}


/**
 * Constructors
 */
- (id)initWithTitle:(OFString*)title andParent:(GtkWindow*)parent andAction:(GtkFileChooserAction)action andAcceptLabel:(OFString*)acceptLabel andCancelLabel:(OFString*)cancelLabel;

/**
 * Methods
 */

- (GtkFileChooserNative*)FILECHOOSERNATIVE;

/**
 * - (const char**)getAcceptLabel;
 *
 * @returns const char*
 */
- (const char*)getAcceptLabel;

/**
 * - (const char**)getCancelLabel;
 *
 * @returns const char*
 */
- (const char*)getCancelLabel;

/**
 * - (void*)setAcceptLabel:(const char*)acceptLabel;
 *
 * @param acceptLabel
 */
- (void)setAcceptLabel:(const char*)acceptLabel;

/**
 * - (void*)setCancelLabel:(const char*)cancelLabel;
 *
 * @param cancelLabel
 */
- (void)setCancelLabel:(const char*)cancelLabel;

@end