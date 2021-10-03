/*
 * OGTKCellRendererToggle.h
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
#import "CellRenderer.h"

@interface OGTKCellRendererToggle : CellRenderer
{

}


/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkCellRendererToggle*)CELLRENDERERTOGGLE;

/**
 * - (bool*)getActivatable;
 *
 * @returns bool
 */
- (bool)getActivatable;

/**
 * - (bool*)getActive;
 *
 * @returns bool
 */
- (bool)getActive;

/**
 * - (bool*)getRadio;
 *
 * @returns bool
 */
- (bool)getRadio;

/**
 * - (void*)setActivatable:(bool)setting;
 *
 * @param setting
 */
- (void)setActivatable:(bool)setting;

/**
 * - (void*)setActive:(bool)setting;
 *
 * @param setting
 */
- (void)setActive:(bool)setting;

/**
 * - (void*)setRadio:(bool)radio;
 *
 * @param radio
 */
- (void)setRadio:(bool)radio;

@end