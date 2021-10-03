/*
 * OGTKNativeDialog.h
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
#import "OGTKBase.h"

@interface OGTKNativeDialog : OGTKBase
{

}


/**
 * Methods
 */

- (GtkNativeDialog*)NATIVEDIALOG;

/**
 * - (void*)destroy;
 *
 */
- (void)destroy;

/**
 * - (bool*)getModal;
 *
 * @returns bool
 */
- (bool)getModal;

/**
 * - (const char**)getTitle;
 *
 * @returns const char*
 */
- (const char*)getTitle;

/**
 * - (GtkWindow**)getTransientFor;
 *
 * @returns GtkWindow*
 */
- (GtkWindow*)getTransientFor;

/**
 * - (bool*)getVisible;
 *
 * @returns bool
 */
- (bool)getVisible;

/**
 * - (void*)hide;
 *
 */
- (void)hide;

/**
 * - (gint*)run;
 *
 * @returns gint
 */
- (gint)run;

/**
 * - (void*)setModal:(bool)modal;
 *
 * @param modal
 */
- (void)setModal:(bool)modal;

/**
 * - (void*)setTitle:(const char*)title;
 *
 * @param title
 */
- (void)setTitle:(const char*)title;

/**
 * - (void*)setTransientFor:(GtkWindow*)parent;
 *
 * @param parent
 */
- (void)setTransientFor:(GtkWindow*)parent;

/**
 * - (void*)show;
 *
 */
- (void)show;

@end