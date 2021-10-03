/*
 * OGTKApplication.h
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

@interface OGTKApplication : OGTKBase
{

}


/**
 * Constructors
 */
- (id)initWithApplicationId:(OFString*)applicationId andFlags:(GApplicationFlags)flags;

/**
 * Methods
 */

- (GtkApplication*)APPLICATION;

/**
 * - (void*)addAcceleratorWithAccelerator:(OFString*)accelerator andActionName:(OFString*)actionName andParameter:(GVariant*)parameter;
 *
 * @param accelerator
 * @param actionName
 * @param parameter
 */
- (void)addAcceleratorWithAccelerator:(OFString*)accelerator andActionName:(OFString*)actionName andParameter:(GVariant*)parameter;

/**
 * - (void*)addWindow:(GtkWindow*)window;
 *
 * @param window
 */
- (void)addWindow:(GtkWindow*)window;

/**
 * - (gchar***)getAccelsForAction:(OFString*)detailedActionName;
 *
 * @param detailedActionName
 * @returns gchar**
 */
- (gchar**)getAccelsForAction:(OFString*)detailedActionName;

/**
 * - (gchar***)getActionsForAccel:(OFString*)accel;
 *
 * @param accel
 * @returns gchar**
 */
- (gchar**)getActionsForAccel:(OFString*)accel;

/**
 * - (GtkWindow**)getActiveWindow;
 *
 * @returns GtkWindow*
 */
- (GtkWindow*)getActiveWindow;

/**
 * - (GMenuModel**)getAppMenu;
 *
 * @returns GMenuModel*
 */
- (GMenuModel*)getAppMenu;

/**
 * - (GMenu**)getMenuById:(OFString*)id;
 *
 * @param id
 * @returns GMenu*
 */
- (GMenu*)getMenuById:(OFString*)id;

/**
 * - (GMenuModel**)getMenubar;
 *
 * @returns GMenuModel*
 */
- (GMenuModel*)getMenubar;

/**
 * - (GtkWindow**)getWindowById:(guint)id;
 *
 * @param id
 * @returns GtkWindow*
 */
- (GtkWindow*)getWindowById:(guint)id;

/**
 * - (GList**)getWindows;
 *
 * @returns GList*
 */
- (GList*)getWindows;

/**
 * - (guint*)inhibitWithWindow:(GtkWindow*)window andFlags:(GtkApplicationInhibitFlags)flags andReason:(OFString*)reason;
 *
 * @param window
 * @param flags
 * @param reason
 * @returns guint
 */
- (guint)inhibitWithWindow:(GtkWindow*)window andFlags:(GtkApplicationInhibitFlags)flags andReason:(OFString*)reason;

/**
 * - (bool*)isInhibited:(GtkApplicationInhibitFlags)flags;
 *
 * @param flags
 * @returns bool
 */
- (bool)isInhibited:(GtkApplicationInhibitFlags)flags;

/**
 * - (gchar***)listActionDescriptions;
 *
 * @returns gchar**
 */
- (gchar**)listActionDescriptions;

/**
 * - (bool*)prefersAppMenu;
 *
 * @returns bool
 */
- (bool)prefersAppMenu;

/**
 * - (void*)removeAcceleratorWithActionName:(OFString*)actionName andParameter:(GVariant*)parameter;
 *
 * @param actionName
 * @param parameter
 */
- (void)removeAcceleratorWithActionName:(OFString*)actionName andParameter:(GVariant*)parameter;

/**
 * - (void*)removeWindow:(GtkWindow*)window;
 *
 * @param window
 */
- (void)removeWindow:(GtkWindow*)window;

/**
 * - (void*)setAccelsForActionWithDetailedActionName:(OFString*)detailedActionName andAccels:(const gchar* const*)accels;
 *
 * @param detailedActionName
 * @param accels
 */
- (void)setAccelsForActionWithDetailedActionName:(OFString*)detailedActionName andAccels:(const gchar* const*)accels;

/**
 * - (void*)setAppMenu:(GMenuModel*)appMenu;
 *
 * @param appMenu
 */
- (void)setAppMenu:(GMenuModel*)appMenu;

/**
 * - (void*)setMenubar:(GMenuModel*)menubar;
 *
 * @param menubar
 */
- (void)setMenubar:(GMenuModel*)menubar;

/**
 * - (void*)uninhibit:(guint)cookie;
 *
 * @param cookie
 */
- (void)uninhibit:(guint)cookie;

@end