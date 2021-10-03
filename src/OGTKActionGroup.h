/*
 * OGTKActionGroup.h
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

@interface OGTKActionGroup : OGTKBase
{

}


/**
 * Constructors
 */
- (id)init:(OFString*)name;

/**
 * Methods
 */

- (GtkActionGroup*)ACTIONGROUP;

/**
 * - (void*)addAction:(GtkAction*)action;
 *
 * @param action
 */
- (void)addAction:(GtkAction*)action;

/**
 * - (void*)addActionWithAccelWithAction:(GtkAction*)action andAccelerator:(OFString*)accelerator;
 *
 * @param action
 * @param accelerator
 */
- (void)addActionWithAccelWithAction:(GtkAction*)action andAccelerator:(OFString*)accelerator;

/**
 * - (void*)addActionsWithEntries:(const GtkActionEntry*)entries andNentries:(guint)nentries andUserData:(gpointer)userData;
 *
 * @param entries
 * @param nentries
 * @param userData
 */
- (void)addActionsWithEntries:(const GtkActionEntry*)entries andNentries:(guint)nentries andUserData:(gpointer)userData;

/**
 * - (void*)addActionsFullWithEntries:(const GtkActionEntry*)entries andNentries:(guint)nentries andUserData:(gpointer)userData andDestroy:(GDestroyNotify)destroy;
 *
 * @param entries
 * @param nentries
 * @param userData
 * @param destroy
 */
- (void)addActionsFullWithEntries:(const GtkActionEntry*)entries andNentries:(guint)nentries andUserData:(gpointer)userData andDestroy:(GDestroyNotify)destroy;

/**
 * - (void*)addRadioActionsWithEntries:(const GtkRadioActionEntry*)entries andNentries:(guint)nentries andValue:(gint)value andOnChange:(GCallback)onChange andUserData:(gpointer)userData;
 *
 * @param entries
 * @param nentries
 * @param value
 * @param onChange
 * @param userData
 */
- (void)addRadioActionsWithEntries:(const GtkRadioActionEntry*)entries andNentries:(guint)nentries andValue:(gint)value andOnChange:(GCallback)onChange andUserData:(gpointer)userData;

/**
 * - (void*)addRadioActionsFullWithEntries:(const GtkRadioActionEntry*)entries andNentries:(guint)nentries andValue:(gint)value andOnChange:(GCallback)onChange andUserData:(gpointer)userData andDestroy:(GDestroyNotify)destroy;
 *
 * @param entries
 * @param nentries
 * @param value
 * @param onChange
 * @param userData
 * @param destroy
 */
- (void)addRadioActionsFullWithEntries:(const GtkRadioActionEntry*)entries andNentries:(guint)nentries andValue:(gint)value andOnChange:(GCallback)onChange andUserData:(gpointer)userData andDestroy:(GDestroyNotify)destroy;

/**
 * - (void*)addToggleActionsWithEntries:(const GtkToggleActionEntry*)entries andNentries:(guint)nentries andUserData:(gpointer)userData;
 *
 * @param entries
 * @param nentries
 * @param userData
 */
- (void)addToggleActionsWithEntries:(const GtkToggleActionEntry*)entries andNentries:(guint)nentries andUserData:(gpointer)userData;

/**
 * - (void*)addToggleActionsFullWithEntries:(const GtkToggleActionEntry*)entries andNentries:(guint)nentries andUserData:(gpointer)userData andDestroy:(GDestroyNotify)destroy;
 *
 * @param entries
 * @param nentries
 * @param userData
 * @param destroy
 */
- (void)addToggleActionsFullWithEntries:(const GtkToggleActionEntry*)entries andNentries:(guint)nentries andUserData:(gpointer)userData andDestroy:(GDestroyNotify)destroy;

/**
 * - (GtkAccelGroup**)getAccelGroup;
 *
 * @returns GtkAccelGroup*
 */
- (GtkAccelGroup*)getAccelGroup;

/**
 * - (GtkAction**)getAction:(OFString*)actionName;
 *
 * @param actionName
 * @returns GtkAction*
 */
- (GtkAction*)getAction:(OFString*)actionName;

/**
 * - (OFString**)getName;
 *
 * @returns OFString*
 */
- (OFString*)getName;

/**
 * - (bool*)getSensitive;
 *
 * @returns bool
 */
- (bool)getSensitive;

/**
 * - (bool*)getVisible;
 *
 * @returns bool
 */
- (bool)getVisible;

/**
 * - (GList**)listActions;
 *
 * @returns GList*
 */
- (GList*)listActions;

/**
 * - (void*)removeAction:(GtkAction*)action;
 *
 * @param action
 */
- (void)removeAction:(GtkAction*)action;

/**
 * - (void*)setAccelGroup:(GtkAccelGroup*)accelGroup;
 *
 * @param accelGroup
 */
- (void)setAccelGroup:(GtkAccelGroup*)accelGroup;

/**
 * - (void*)setSensitive:(bool)sensitive;
 *
 * @param sensitive
 */
- (void)setSensitive:(bool)sensitive;

/**
 * - (void*)setTranslateFuncWithFunc:(GtkTranslateFunc)func andData:(gpointer)data andNotify:(GDestroyNotify)notify;
 *
 * @param func
 * @param data
 * @param notify
 */
- (void)setTranslateFuncWithFunc:(GtkTranslateFunc)func andData:(gpointer)data andNotify:(GDestroyNotify)notify;

/**
 * - (void*)setTranslationDomain:(OFString*)domain;
 *
 * @param domain
 */
- (void)setTranslationDomain:(OFString*)domain;

/**
 * - (void*)setVisible:(bool)visible;
 *
 * @param visible
 */
- (void)setVisible:(bool)visible;

/**
 * - (OFString**)translateString:(OFString*)string;
 *
 * @param string
 * @returns OFString*
 */
- (OFString*)translateString:(OFString*)string;

@end