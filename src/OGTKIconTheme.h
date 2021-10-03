/*
 * OGTKIconTheme.h
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

@interface OGTKIconTheme : OGTKBase
{

}

/**
 * Functions
 */
+ (void)addBuiltinIconWithIconName:(OFString*)iconName andSize:(gint)size andPixbuf:(GdkPixbuf*)pixbuf;
+ (GtkIconTheme*)getDefault;
+ (GtkIconTheme*)getForScreen:(GdkScreen*)screen;

/**
 * Constructors
 */
- (id)init;

/**
 * Methods
 */

- (GtkIconTheme*)ICONTHEME;

/**
 * - (void*)addResourcePath:(OFString*)path;
 *
 * @param path
 */
- (void)addResourcePath:(OFString*)path;

/**
 * - (void*)appendSearchPath:(OFString*)path;
 *
 * @param path
 */
- (void)appendSearchPath:(OFString*)path;

/**
 * - (GtkIconInfo**)chooseIconWithIconNames:(const gchar**)iconNames andSize:(gint)size andFlags:(GtkIconLookupFlags)flags;
 *
 * @param iconNames
 * @param size
 * @param flags
 * @returns GtkIconInfo*
 */
- (GtkIconInfo*)chooseIconWithIconNames:(const gchar**)iconNames andSize:(gint)size andFlags:(GtkIconLookupFlags)flags;

/**
 * - (GtkIconInfo**)chooseIconForScaleWithIconNames:(const gchar**)iconNames andSize:(gint)size andScale:(gint)scale andFlags:(GtkIconLookupFlags)flags;
 *
 * @param iconNames
 * @param size
 * @param scale
 * @param flags
 * @returns GtkIconInfo*
 */
- (GtkIconInfo*)chooseIconForScaleWithIconNames:(const gchar**)iconNames andSize:(gint)size andScale:(gint)scale andFlags:(GtkIconLookupFlags)flags;

/**
 * - (char**)getExampleIconName;
 *
 * @returns char*
 */
- (char*)getExampleIconName;

/**
 * - (gint**)getIconSizes:(OFString*)iconName;
 *
 * @param iconName
 * @returns gint*
 */
- (gint*)getIconSizes:(OFString*)iconName;

/**
 * - (void*)getSearchPathWithPath:(gchar***)path andNelements:(gint*)nelements;
 *
 * @param path
 * @param nelements
 */
- (void)getSearchPathWithPath:(gchar***)path andNelements:(gint*)nelements;

/**
 * - (bool*)hasIcon:(OFString*)iconName;
 *
 * @param iconName
 * @returns bool
 */
- (bool)hasIcon:(OFString*)iconName;

/**
 * - (GList**)listContexts;
 *
 * @returns GList*
 */
- (GList*)listContexts;

/**
 * - (GList**)listIcons:(OFString*)context;
 *
 * @param context
 * @returns GList*
 */
- (GList*)listIcons:(OFString*)context;

/**
 * - (GdkPixbuf**)loadIconWithIconName:(OFString*)iconName andSize:(gint)size andFlags:(GtkIconLookupFlags)flags;
 *
 * @param iconName
 * @param size
 * @param flags
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)loadIconWithIconName:(OFString*)iconName andSize:(gint)size andFlags:(GtkIconLookupFlags)flags;

/**
 * - (GdkPixbuf**)loadIconForScaleWithIconName:(OFString*)iconName andSize:(gint)size andScale:(gint)scale andFlags:(GtkIconLookupFlags)flags;
 *
 * @param iconName
 * @param size
 * @param scale
 * @param flags
 * @returns GdkPixbuf*
 */
- (GdkPixbuf*)loadIconForScaleWithIconName:(OFString*)iconName andSize:(gint)size andScale:(gint)scale andFlags:(GtkIconLookupFlags)flags;

/**
 * - (cairo_surface_t**)loadSurfaceWithIconName:(OFString*)iconName andSize:(gint)size andScale:(gint)scale andForWindow:(GdkWindow*)forWindow andFlags:(GtkIconLookupFlags)flags;
 *
 * @param iconName
 * @param size
 * @param scale
 * @param forWindow
 * @param flags
 * @returns cairo_surface_t*
 */
- (cairo_surface_t*)loadSurfaceWithIconName:(OFString*)iconName andSize:(gint)size andScale:(gint)scale andForWindow:(GdkWindow*)forWindow andFlags:(GtkIconLookupFlags)flags;

/**
 * - (GtkIconInfo**)lookupByGiconWithIcon:(GIcon*)icon andSize:(gint)size andFlags:(GtkIconLookupFlags)flags;
 *
 * @param icon
 * @param size
 * @param flags
 * @returns GtkIconInfo*
 */
- (GtkIconInfo*)lookupByGiconWithIcon:(GIcon*)icon andSize:(gint)size andFlags:(GtkIconLookupFlags)flags;

/**
 * - (GtkIconInfo**)lookupByGiconForScaleWithIcon:(GIcon*)icon andSize:(gint)size andScale:(gint)scale andFlags:(GtkIconLookupFlags)flags;
 *
 * @param icon
 * @param size
 * @param scale
 * @param flags
 * @returns GtkIconInfo*
 */
- (GtkIconInfo*)lookupByGiconForScaleWithIcon:(GIcon*)icon andSize:(gint)size andScale:(gint)scale andFlags:(GtkIconLookupFlags)flags;

/**
 * - (GtkIconInfo**)lookupIconWithIconName:(OFString*)iconName andSize:(gint)size andFlags:(GtkIconLookupFlags)flags;
 *
 * @param iconName
 * @param size
 * @param flags
 * @returns GtkIconInfo*
 */
- (GtkIconInfo*)lookupIconWithIconName:(OFString*)iconName andSize:(gint)size andFlags:(GtkIconLookupFlags)flags;

/**
 * - (GtkIconInfo**)lookupIconForScaleWithIconName:(OFString*)iconName andSize:(gint)size andScale:(gint)scale andFlags:(GtkIconLookupFlags)flags;
 *
 * @param iconName
 * @param size
 * @param scale
 * @param flags
 * @returns GtkIconInfo*
 */
- (GtkIconInfo*)lookupIconForScaleWithIconName:(OFString*)iconName andSize:(gint)size andScale:(gint)scale andFlags:(GtkIconLookupFlags)flags;

/**
 * - (void*)prependSearchPath:(OFString*)path;
 *
 * @param path
 */
- (void)prependSearchPath:(OFString*)path;

/**
 * - (bool*)rescanIfNeeded;
 *
 * @returns bool
 */
- (bool)rescanIfNeeded;

/**
 * - (void*)setCustomTheme:(OFString*)themeName;
 *
 * @param themeName
 */
- (void)setCustomTheme:(OFString*)themeName;

/**
 * - (void*)setScreen:(GdkScreen*)screen;
 *
 * @param screen
 */
- (void)setScreen:(GdkScreen*)screen;

/**
 * - (void*)setSearchPathWithPath:(const gchar**)path andNelements:(gint)nelements;
 *
 * @param path
 * @param nelements
 */
- (void)setSearchPathWithPath:(const gchar**)path andNelements:(gint)nelements;

@end